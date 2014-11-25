#ifndef ThreeDirectionController_h__
#define ThreeDirectionController_h__

#include "Controller.h"
#include "cocos2d.h"

using namespace cocos2d;

class ThreeDirectionController:public Controller
{
public:
	ThreeDirectionController();
	~ThreeDirectionController();
	CREATE_FUNC(ThreeDirectionController);
	virtual bool init();
	virtual void update(float dt);
	void setiXSpeed(int iSpeed);
	void SetiYSpeed(int iSpeed);
private:
	int m_iXSpeed;
	int m_iYSpeed;
	void registeTouchEvent();
};


#endif // ThreeDirectionController_h__
