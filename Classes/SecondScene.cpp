#include "SecondScene.h"


SecondScene::SecondScene()
{
}


SecondScene::~SecondScene()
{
}

Scene* SecondScene::createScene()
{
	auto scene = Scene::create();
	auto layer = SecondScene::create();
	scene->addChild(layer);
	return scene;
}

bool SecondScene::init()
{
	Label* label = Label::create("Hello", "Microsoft YaHei", 40);
	label->setPosition(ccp(300, 200));
	this->addChild(label);

	MenuItemImage *pCloseItem = MenuItemImage::create(
		"CloseNormal.png", 
		"CloseSelected.png", 
		this, 
		menu_selector(SecondScene::popScene)
		);

	pCloseItem->setPosition(ccp(Director::getInstance()->getWinSize().width - 20, 20));
	Menu* pMenu = Menu::create(pCloseItem, NULL);
	pMenu->setPosition(Point(0, 0));
	this->addChild(pMenu, 1);

	return true;
}

void SecondScene::popScene(Ref* pSender)
{
	//Director::getInstance()->popScene();
}