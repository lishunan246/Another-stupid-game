#pragma once
#include "cocos2d.h"
#include "ControllerListener.h"
#include "Controller.h"
using namespace cocos2d;
class Entity :
	public Node,
	public ControllerListener
{
public:
	Entity();
	~Entity();
	Sprite* getSprite();
	void bindSprite(Sprite* sprite);
	void setController(Controller* controller);
	virtual void setTagPosition(int x, int y);
	virtual Point getTagPosition();
protected:
	Sprite* m_sprite;
	Controller* m_controller;
};

