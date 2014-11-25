#ifndef ControllerListener_h__
#define ControllerListener_h__

#include "cocos2d.h"

using namespace cocos2d;

class ControllerListener
{
public:
	ControllerListener();
	~ControllerListener();
	virtual void setTagPosition(int x, int y) = 0;
	virtual Point getTagPosition() = 0;
private:

};


#endif // ControllerListener_h__
