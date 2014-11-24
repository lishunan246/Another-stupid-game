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
	void jump();
	void hit();
	int getiHP();

private:
	bool m_isJumping;
	int m_iHP;

	void resetData();
};


#endif