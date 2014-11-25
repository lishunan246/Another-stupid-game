#ifndef SimpleMoveController_h__
#define SimpleMoveController_h__

#include "cocos2d.h"
#include "Controller.h"

using namespace cocos2d;

class SimpleMoveController:public Controller
{
public:
	SimpleMoveController();
	~SimpleMoveController();
	CREATE_FUNC(SimpleMoveController);
	virtual bool init();
	virtual void update(float dt);
	void setiSpeed(int iSpeed);
private:
	int m_iSpeed;
};



#endif // SimpleMoveController_h__
