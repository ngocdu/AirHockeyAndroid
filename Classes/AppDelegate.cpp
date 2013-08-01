//
//  AirHockeyAppDelegate.cpp
//  AirHockey
//
//  Created by Trung Kien Do on 13/07/09.
//  Copyright __FRAMGIA__ 2013年. All rights reserved.
//

#include "AppDelegate.h"

#include "cocos2d.h"
#include "SimpleAudioEngine.h"
#include "RankingScene.h"
//#include "GetPresent.h"
USING_NS_CC;
using namespace CocosDenshion;
typedef struct tagResource
 {
     cocos2d::CCSize size;
     char directory[100];
 }Resource;

 static Resource smallResource  =  { cocos2d::CCSizeMake(480, 320),   "iphone" };
 static Resource mediumResource =  { cocos2d::CCSizeMake(1024, 768),  "ipad"   };
 static Resource largeResource  =  { cocos2d::CCSizeMake(2048, 1536), "ipadhd" };
static cocos2d::CCSize designResolutionSize = cocos2d::CCSizeMake(800, 480);
AppDelegate::AppDelegate()
{

}

AppDelegate::~AppDelegate()
{
}

bool AppDelegate::applicationDidFinishLaunching()
{
//	 CCDirector* pDirector = CCDirector::sharedDirector();
//	     CCEGLView* pEGLView = CCEGLView::sharedOpenGLView();
//	     pDirector->setOpenGLView(pEGLView);
//
//	     // Set the design resolution
//	    pEGLView->setDesignResolutionSize(designResolutionSize.width, designResolutionSize.height, kResolutionNoBorder);
//
//	    CCSize frameSize = pEGLView->getFrameSize();
//
//	    // In this demo, we select resource according to the frame's height.
//	    // If the resource size is different from design resolution size, you need to set contentScaleFactor.
//	    // We use the ratio of resource's height to the height of design resolution,
//	    // this can make sure that the resource's height could fit for the height of design resolution.
//
//	    // if the frame's height is larger than the height of medium resource size, select large resource.
//	    if (frameSize.height > mediumResource.size.height)
//	    {
//	        searchPath.push_back(largeResource.directory);
//	        pDirector->setContentScaleFactor(largeResource.size.height/designResolutionSize.height);
//	    }
//	    // if the frame's height is larger than the height of small resource size, select medium resource.
//	    else if (frameSize.height > smallResource.size.height)
//	    {
//	        searchPath.push_back(mediumResource.directory);
//	        pDirector->setContentScaleFactor(mediumResource.size.height/designResolutionSize.height);
//	    }
//	    // if the frame's height is smaller than the height of medium resource size, select small resource.
//	    else
//	    {
//	        searchPath.push_back(smallResource.directory);
//	        pDirector->setContentScaleFactor(smallResource.size.height/designResolutionSize.height);
//	    }
	//-----------------------------

    // initialize director
    CCDirector *pDirector = CCDirector::sharedDirector();
    pDirector->setOpenGLView(CCEGLView::sharedOpenGLView());

    // turn on display FPS
    pDirector->setDisplayStats(false);
    
    // set FPS. the default value is 1.0/60 if you don't call this
    pDirector->setAnimationInterval(1.0 / 60);
    
    // create a scene. it's an autorelease object
    CCScene *pScene = RankingScene::scene();

    // run
    pDirector->runWithScene(pScene);

    return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground()
{
    CCDirector::sharedDirector()->stopAnimation();
    SimpleAudioEngine::sharedEngine()->pauseBackgroundMusic();
    SimpleAudioEngine::sharedEngine()->pauseAllEffects();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground()
{
    CCDirector::sharedDirector()->startAnimation();
    SimpleAudioEngine::sharedEngine()->resumeBackgroundMusic();
    SimpleAudioEngine::sharedEngine()->resumeAllEffects();
}
