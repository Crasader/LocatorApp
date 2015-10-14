#include "UpdateScene.h"
#include "UI/GameUI.h"
#include "GameUpdate/GameUpdateManager.h"
#include "GameUpdate/GameUpdate.h"
#include "GameUpdate/GameUpdateUI.h"

CUpdateScene::CUpdateScene() : m_pLayer(NULL)
{

}

CUpdateScene::~CUpdateScene()
{
	
}

bool CUpdateScene::init()
{
	// ��Ļ����
	Size vSize = gDirector->getVisibleSize();
	Point pos = Point(vSize.width/2,vSize.height/2)+gDirector->getVisibleOrigin();
	
	// Logo ����
	Sprite* pLogo = Sprite::create("update/logo.jpg");
	if ( pLogo )
	{
		ActionInterval* pAction1 = FadeIn::create(1.0f);
		ActionInterval* pAction2 = DelayTime::create(1.0f);
		ActionInterval* pAction3 = FadeOut::create(0.5f);

		pLogo->setPosition(pos);
		pLogo->setOpacity(0);
		pLogo->runAction(Sequence::create(
			FadeIn::create(1.0f),
			DelayTime::create(1.0f),
			FadeOut::create(0.5f),
			CallFunc::create( CC_CALLBACK_0(CUpdateScene::onLogoEnded,this,pLogo)),NULL));

		addChild(pLogo);
	}

	scheduleUpdate();

	return true;
}

void CUpdateScene::update(float delta)
{
	gUpdateManager->Update(delta);
}

void CUpdateScene::onLogoEnded(Node* pLogo)
{
	pLogo->removeFromParent();
	// LOGO������ϣ���ʼ����
	gUpdateManager->Initialize();
	// �򿪸��½���
	gUpdateManager->OpenUpdateUI();
	// ��ʼ����
	gUpdateManager->EnterState(UpdateStateType_Start);
}