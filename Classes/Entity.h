#pragma once
#include "cocos2d.h"

using namespace cocos2d;
class Entity :
	public Node
{
public:
	Entity();
	~Entity();
	Sprite* getSprite();
	void bindSprite(Sprite* sprite);
private:
	Sprite* m_sprite;
};

