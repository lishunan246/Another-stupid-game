#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "cocos2d.h"
#include "Entity.h"
using namespace cocos2d;

#define JUMP_ACTION_TAG 1

class Player:public Entity
{
public:
	Player();
	~Player();
	CREATE_FUNC(Player);
	virtual bool init();
	void run();
	void setViewPointByPlayer();
	void setTiledMap(TMXTiledMap* map);
	void setTagPosition(int x, int y);
	
private:
	TMXTiledMap* m_map;
	bool isJumping;
	TMXLayer* meta;

	Point tileCoordForPosition(Point pos);
};



#endif