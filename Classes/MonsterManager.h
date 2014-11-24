#ifndef __MONSTERMANAGER_H__
#define __MONSTERMANAGER_H__

#include "cocos2d.h"
#include "Monster.h"

USING_NS_CC;

#define MAX_MONSTER_NUM 10

class MonsterManager:public Node
{
public:
	MonsterManager();
	~MonsterManager();
	CREATE_FUNC(MonsterManager);
	virtual bool init();
	virtual void update(float dt);
	void bindPlayer(Player* player);
private:
	void createMonsters();

	Vector<Monster*> m_MonsterArr;
	Player* m_player;
};


#endif