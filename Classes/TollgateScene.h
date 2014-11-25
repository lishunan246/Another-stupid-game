#ifndef __TOLLGATESCENE_H__
#define __TOLLGATESCENE_H__

#include "cocos2d.h"

#include "extensions\cocos-ext.h"
#include "ui\CocosGUI.h"
#include "editor-support\cocostudio\CocoStudio.h"
#include "editor-support\cocostudio\CCSGUIReader.h"

#include "MonsterManager.h"
#include "Player.h"
#include "SecondScene.h"
#include "SimpleMoveController.h"
#include "ThreeDirectionController.h"
using namespace cocos2d::extension;
using namespace cocostudio;
using namespace cocos2d::ui;

class Player;
class TollgateScene:public Layer
{
public:
	TollgateScene();
	~TollgateScene();

	static Scene* createScene();
	virtual bool init();
	CREATE_FUNC(TollgateScene);
	//virtual void update(float delta);
	//void jumpEvent(Ref*, TouchEventType type);

private:	
	Sprite* m_bgSprite1;
	Sprite* m_bgSprite2;
	Player* m_player;
	int m_iScore;
	TextAtlas* m_scoreLab;
	LoadingBar* m_hpBar;

	void addPlayer(TMXTiledMap* map);

	//void initBG();
	//void loadUI();
};


#endif