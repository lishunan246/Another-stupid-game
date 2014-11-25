#include "ThreeDirectionController.h"

ThreeDirectionController::ThreeDirectionController()
{
}

ThreeDirectionController::~ThreeDirectionController()
{
}

bool ThreeDirectionController::init()
{
	this->m_iXSpeed = 0;
	this->m_iYSpeed = 0;

	registeTouchEvent();

	this->scheduleUpdate();
	return true;
}

void ThreeDirectionController::update(float dt)
{
	if (m_controllerListener == NULL)
		return;

	Point curPos = m_controllerListener->getTagPosition();

	curPos.x += m_iXSpeed;
	curPos.y += m_iYSpeed;

	m_controllerListener->setTagPosition(curPos.x,curPos.y);
}

void ThreeDirectionController::SetiYSpeed(int iSpeed)
{
	this->m_iYSpeed = iSpeed;
}

void ThreeDirectionController::setiXSpeed(int iSpeed)
{
	this->m_iXSpeed = iSpeed;
}

void ThreeDirectionController::registeTouchEvent()
{
	auto listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = [](Touch* touch, Event* event)
	{
		return true;
	};

	listener->onTouchMoved = [&](Touch* touch, Event* event)
	{
		Point touchPos = Director::getInstance()->convertToGL(touch->getLocationInView());
		Point pos = m_controllerListener->getTagPosition();

		int iSpeed = 0;

		if (touchPos.y > pos.y)
		{
			iSpeed = 1;
		}
		else
		{
			iSpeed = -1;
		}

		SetiYSpeed(iSpeed);
	};

	listener->onTouchEnded = [&](Touch* touch, Event* event)
	{
		SetiYSpeed(0);
	};

	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);

}

