#include "GameScene.h"
#include "GameLayer.h"
#include "Hero.h"
#include "GameUILayer.h"
#include "GameTipsLayer.h"
#include "RoleTitleLayer.h"
#include "RoleModel.h"
#include "UI/GameUI.h"
#include "Net/NetDispatcher.h"
#include "GameManager.h"
#include "UI/ResMgr/CtrlAllocator.h"
#include "Net/pk_nonInGame.h"
#include "GameVariable.h"
#include "TaskMgr.h"
#include "BeyondMap.h"
#include "UI/LoadingUI.h"
#include "UI/GamePrompt.h"
#include "Log.h"
#include "MemoryMonitor.h"
#include "DataPool.h"

using namespace cocostudio;

// ���������ֱ������Ϸ��ʾ�������½Ǻ����Ͻ�����Ӧ��UIlayer�е����꣬�������������ж�UIԭ���Ƿ�����ʾ���ڲ�
Point ptWindowLB2UILayer(0.f, 0.f);
Point ptWindowRT2UILayer(GAME_UI_ORIG_SIZE.width, GAME_UI_ORIG_SIZE.height);

float fNow;

CGameScene::CGameScene() : m_fMemoryInterval(0.0f)
{

}

CGameScene::~CGameScene()
{

}

// on "init" you need to initialize your instance
bool CGameScene::init()
{
	return true;
}

void CGameScene::onEnter()
{
	Scene::onEnter();

	pk::C2GS_EnterGame cmd;
	cmd.playerID = gHero->GetId();
	cmd.Send(gNetSocket);

	LOGI("request enter game ...");

	gLoadingUI->Show(LOADRES_TYPE);

	addChild(gGameLayer);
	addChild(gGameUILayer);
	addChild(gGameTipsLayer);
	if (gPromptCenter->GetWidgetPrompt()->getParent())
	{
		gPromptCenter->GetWidgetPrompt()->removeFromParentAndCleanup(true);
	}
	gGameTipsLayer->addChild(gPromptCenter->GetWidgetPrompt());

	// ��Ļ����
	Size vSize = gDirector->getVisibleSize();
	Size wSize = UI_ORIG_SIZE;
	float fScale = MIN(vSize.width / wSize.width, vSize.height / wSize.height);
	gGameUILayer->setScale(fScale);
	gGameTipsLayer->setScale(fScale);

	Point pos(0,0);
	pos += gDirector->getVisibleOrigin();
	gGameUILayer->setPosition(pos);
	gGameTipsLayer->setPosition(pos);

	if (vSize.width / vSize.height > wSize.width / wSize.height)
	{
		ptWindowRT2UILayer.x = vSize.width / vSize.height * wSize.height;
	}
	else
	{
		ptWindowRT2UILayer.y = vSize.height / vSize.width * wSize.width;
	}

	gGameVariable->Reset();
	gGameLayer->scheduleUpdate();
	gGameUILayer->scheduleUpdate();
	scheduleUpdate();
}

void CGameScene::onExit()
{
	unscheduleUpdate();

	Scene::onExit();
	gGameUILayer->removeAllChildren();
}

void CGameScene::update(float delta)
{
	if ( !gGameManager->IsGaming() )
	{
		LOGE("none game state CGameScene::update");
		return ;
	}

	fNow += delta;
	m_fMemoryInterval += delta;

	// ����ģ�����
	if ( !gNetDispatcher->IsConnect() )
	{
		int recode = gNetDispatcher->GetIOSocket()->getErrorCode();
		LOGE("Socket connect break.errcode[%d]",recode);
		gGameManager->EnterState(GS_Login);
	}
	else
	{
		gNetDispatcher->update(delta);
	}

	// �ڴ���
	if ( gMemoryMonitor->isMemoryWarnning() && m_fMemoryInterval > 5.0f )
	{
		if ( gMemoryMonitor->isMemoryEmergence() )
		{
			LOGE("memory Emergence. total: %.1f free: %.1f used: %.1f", gMemoryMonitor->totlMemory(), gMemoryMonitor->freeMemory(),gMemoryMonitor->usedMemory());
		}
		else
		{
			LOGW("memory Warnning. total: %.1f free: %.1f used: %.1f", gMemoryMonitor->totlMemory(), gMemoryMonitor->freeMemory(),gMemoryMonitor->usedMemory());
		}

		m_fMemoryInterval = 0.0f;
	}

	//gTaskManager->Update(delta);
	gGridsManager->update(delta);
	CSuperMove::Instance()->Update();
	gPromptCenter->update(delta);
	gDataPool->Update(delta);
}