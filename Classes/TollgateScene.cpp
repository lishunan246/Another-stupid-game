#include "TollgateScene.h" 

TollgateScene::TollgateScene()
{
	m_iScore = 0;
}

TollgateScene::~TollgateScene()
{
}

bool TollgateScene::init()
{
	if (!Layer::init())
		return false;

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Sprite* titleSprite = Sprite::create("title.png");
	titleSprite->setPosition(visibleSize.width / 2, visibleSize.height - 50);
	this->addChild(titleSprite,2);

	m_player = Player::create();
	m_player->bindSprite(Sprite::create("sprite.png"));
	m_player->setPosition(200, visibleSize.height / 4);
	this->addChild(m_player, 3);

	initBG();
	loadUI();

	this->scheduleUpdate();

	MonsterManager* monsterMgr = MonsterManager::create();
	this->addChild(monsterMgr);
	monsterMgr->bindPlayer(m_player);

	return true;
}

void TollgateScene::initBG()
{
	Size visibleSize = Director::getInstance()->getVisibleSize();

	m_bgSprite1 = Sprite::create("tollgateBG.jpg");
	m_bgSprite1 -> setPosition(visibleSize.width / 2, visibleSize.height / 2);
	this->addChild(m_bgSprite1, 0);

	m_bgSprite2 = Sprite::create("tollgateBG.jpg");
	m_bgSprite2->setPosition(visibleSize.width / 2+visibleSize.width, visibleSize.height / 2);
	m_bgSprite2->setFlippedX(true);
	this->addChild(m_bgSprite2, 0);
}

Scene* TollgateScene::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = TollgateScene::create();

	// add layer as a child to scene
	scene->addChild(layer);

	
	// return the scene
	return scene;
}

void TollgateScene::update(float delta)
{
	int posX1 = m_bgSprite1->getPositionX();
	int posX2 = m_bgSprite2->getPositionX();

	int iSpeed = 1;

	posX1 -= iSpeed;
	posX2 -= iSpeed;

	m_bgSprite1->setPositionX(posX1);
	m_bgSprite2->setPositionX(posX2);

	m_iScore++;

	m_scoreLab->setStringValue(Value(m_iScore).asString());
	m_hpBar->setPercent(m_player->getiHP() / 10.f);

	if (m_player->getiHP() == 0)
	{
		Director::getInstance()->pushScene(
			TransitionSlideInT::create(3.0f, SecondScene::createScene())
			);
	}
}

void TollgateScene::loadUI()
{
	auto UI = cocostudio::GUIReader::getInstance()->widgetFromJsonFile("LittleRunnerUI_1.ExportJson");
	this->addChild(UI);

	auto jumpBtn = (Button*)Helper::seekWidgetByName(UI, "JumpBtn");
	m_scoreLab = (TextAtlas*)Helper::seekWidgetByName(UI, "scoreLab");
	m_hpBar = (LoadingBar*)Helper::seekWidgetByName(UI, "hpProgress");

	jumpBtn->addTouchEventListener(this, toucheventselector(TollgateScene::jumpEvent));
}

void TollgateScene::jumpEvent(Ref*, TouchEventType type)
{
	switch (type)
	{
	case TouchEventType::TOUCH_EVENT_ENDED:
		m_player->jump();
		break;
	default:
		break;
	}
}