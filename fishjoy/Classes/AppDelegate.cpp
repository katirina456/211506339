#include "AppDelegate.h"
#include "GameMenuLayer.h"

USING_NS_CC;

AppDelegate::AppDelegate() {

}

AppDelegate::~AppDelegate() 
{
}

bool AppDelegate::applicationDidFinishLaunching() {
    CCDirector* pDirector = CCDirector::sharedDirector();
    CCEGLView* pEGLView = CCEGLView::sharedOpenGLView();

    pDirector->setOpenGLView(pEGLView);

    CCScene *pScene = GameMenuLayer::scene();

    pDirector->runWithScene(pScene);

    return true;
}

void AppDelegate::applicationDidEnterBackground() {
    CCDirector::sharedDirector()->stopAnimation();
	
}

void AppDelegate::applicationWillEnterForeground() {
    CCDirector::sharedDirector()->startAnimation();

}
