#ifndef _SECONDSCENE_H_
#define _SECONDSCENE_H_
#include "cocos2d.h"
using namespace cocos2d;
class SecondScene :
	public Layer
{
public:
	SecondScene();
	~SecondScene();
	static Scene* createScene();
	void popScene(Ref* pSender);
	virtual bool init();
	CREATE_FUNC(SecondScene);
};

#endif

