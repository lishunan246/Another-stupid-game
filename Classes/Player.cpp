#include "Player.h"
Player::Player()
{
	isJumping = false;
}

Player::~Player()
{
}

bool Player::init()
{
	return true;
}

void Player::run()
{
	SpriteFrameCache* frameCache = SpriteFrameCache::getInstance();
	frameCache->addSpriteFramesWithFile("boys.plist", "boys.png");

	SpriteFrame* frame = NULL;
	Vector<SpriteFrame*> frameList;

	for (int i = 1; i < 15; i++)
	{
		frame = frameCache->getSpriteFrameByName(StringUtils::format("run%d.png", i));
		frameList.pushBack(frame);
	}

	Animation* animation = Animation::createWithSpriteFrames(frameList);
	animation->setLoops(-1);
	animation->setDelayPerUnit(0.08f);

	Animate* animate = Animate::create(animation);
	m_sprite->runAction(animate);
}

void Player::setViewPointByPlayer()
{
	if (m_sprite == NULL)
		return;
	Layer* parent = (Layer*)getParent();

	Size mapTileNum = m_map->getMapSize();
	Size tiledSize = m_map->getTileSize();

	Size mapSize = Size(mapTileNum.width*tiledSize.width, mapTileNum.height*tiledSize.height);

	Size visibleSize = Director::getInstance()->getVisibleSize();

	Point spritePos = getPosition();

	float x = std::max(spritePos.x, visibleSize.width / 2);
	float y = std::max(spritePos.y, visibleSize.height / 2);

	x = std::min(x, mapSize.width - visibleSize.width / 2);
	y = std::min(y, mapSize.height - visibleSize.height / 2);

	Point destPos = Point(x, y);

	Point centerPos = Point(visibleSize.width / 2, visibleSize.height / 2);

	Point viewPos = centerPos - destPos;

	parent->setPosition(viewPos);
}

void Player::setTiledMap(TMXTiledMap* map)
{
	this->m_map = map;
	this->meta = m_map->getLayer("meta");
	this->meta->setVisible(false);
}

void Player::setTagPosition(int x, int y)
{
	Size spriteSize = m_sprite->getContentSize();
	Point dstPos = Point(x + spriteSize.width / 2, y);
	Point tiledPos = tileCoordForPosition(dstPos);
	int tiledGid = meta->getTileGIDAt(tiledPos);
	if (tiledGid != 0)
	{
		Value properties = m_map->getPropertiesForGID(tiledGid);

		ValueMap propertiesMap = properties.asValueMap();
		if (propertiesMap.find("Collidable") != propertiesMap.end())
		{
			Value prop = properties.asValueMap().at("Collidable");

			if (prop.asString().compare("true") == 0 && isJumping == false)
			{
				isJumping = true;
				auto jumpBy = JumpBy::create(0.5f, Point(-100, 0), 80, 1);
				CallFunc* callFunc = CallFunc::create([&](){
					isJumping = false;
					log("Hhh");
				});

				auto actions = Sequence::create(jumpBy, callFunc, NULL);
				this->runAction(actions);
				TMXLayer* barrier = m_map->getLayer("ground");
				barrier->removeTileAt(tiledPos);
			}
		}
		if (propertiesMap.find("food") != propertiesMap.end())
		{
			Value prop = propertiesMap.at("food");
			if (prop.asString().compare("true") == 0)
			{
				TMXLayer* barrier = m_map->getLayer("ground");
				barrier->removeTileAt(tiledPos);
			}
		}
	}

	Entity::setTagPosition(x, y);
	setViewPointByPlayer();
}

Point Player::tileCoordForPosition(Point pos)
{
	Size mapTiledNum = m_map->getMapSize();
	Size tiledSize = m_map->getTileSize();

	int x = pos.x/tiledSize.width;
	int y = (700 - pos.y) / tiledSize.height;

	if (x > 0)
	{
		x -= 1;
	}

	if (y > 0)
	{
		y -= 1;
	}

	return Point(x, y);
}

