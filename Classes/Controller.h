#ifndef __CONTROLLER_H__
#define __CONTROLLER_H__

#include "cocos2d.h"
#include "ControllerListener.h"

using namespace cocos2d;

class Controller:public Node
{
public:
	Controller();
	~Controller();
	void setControllerListener(ControllerListener* controllerListener);
protected:
	ControllerListener* m_controllerListener;
};



#endif