#include "HelloWorldScene.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
	auto UI = cocostudio::GUIReader::getInstance()->widgetFromJsonFile("MoreUI_1.ExportJson");

	UI->setPosition(Point(100, 100));

	this->addChild(UI);
	log("start");

	m_hpBar = (LoadingBar*)Helper::seekWidgetByName(UI, "hpBar");
	m_hpBar->addTouchEventListener(this, toucheventselector(HelloWorld::onClick));
    
    return true;
}

void HelloWorld::onClick(Ref*, TouchEventType type)
{
	switch (type)
	{
	case TouchEventType::TOUCH_EVENT_MOVED:
		m_hpBar->setPercent(m_hpBar->getPercent() - 5);
		log("clicked");
		break;
	default:
		break;
	}
}

void HelloWorld::menuCloseCallback(Ref* pSender)
{
	Director::getInstance()->pushScene(
		TransitionSlideInT::create(3.0f,SecondScene::createScene())
		);
//#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
//	MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
//    return;
//#endif
//
//    Director::getInstance()->end();
//
//#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
//    exit(0);
//#endif
}
