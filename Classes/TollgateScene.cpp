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

	TMXTiledMap* map = TMXTiledMap::create("level01.tmx");

	this->addChild(map);

	addPlayer(map);

	return true;
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


void TollgateScene::addPlayer(TMXTiledMap* map)
{
	Size visibleSize = Director::getInstance()->getVisibleSize();

	Sprite* playerSprite = Sprite::create("player.png");
	Player* mPlayer = Player::create();
	mPlayer->bindSprite(playerSprite);
	mPlayer->run();
	mPlayer->setTiledMap(map);

	TMXObjectGroup* objGroup = map->getObjectGroup("objects");

	ValueMap playerPointMap = objGroup->getObject("PlayerPoint");
	float playerX = playerPointMap.at("x").asFloat();
	float playerY = playerPointMap.at("y").asFloat();

	mPlayer->setPosition(playerX,playerY);
	map->addChild(mPlayer);
	ThreeDirectionController* threeDirectionController = ThreeDirectionController::create();

	SimpleMoveController* simpleMoveController = SimpleMoveController::create();

	threeDirectionController->setiXSpeed(1);
	threeDirectionController->SetiYSpeed(0);

	this->addChild(threeDirectionController);

	mPlayer->setController(threeDirectionController);
}