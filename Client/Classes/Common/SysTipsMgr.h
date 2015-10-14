/*
	��Ϸ������ʾ������
	2015-8-6
	������
*/
#pragma once
#include "GameDef.h"
#include "UI/GameUI.h"

typedef enum _sysType
{
	systype_team,	//���
	systype_chat,	//����
	systype_max,
}SysType;

//��ʾ����
typedef enum _actionType
{
	action_none,
	action_visible,
	action_blink,
	action_max,
}ActionType;

typedef union _tipsAction
{
	bool visible;		//�Ƿ�ɼ�
	bool blink;			//�Ƿ���˸
}TipsAction;

class CSysTipsMgr : public Singleton<CSysTipsMgr>
{
public:
	typedef struct _sysTips
	{
		Widget*	widget;	//��ʾUI
		ActionType actionType;
		TipsAction	tipsAction;
	}SysTips;

	CSysTipsMgr();
	~CSysTipsMgr();

	//����tips�ؼ� tips����
	void			SetWidget(SysType type, ActionType actionType, Widget* widget);
	//����tips
	void			RunTipsAction(SysType type);
	void			RunTipsAction(SysTips& sysTips);
	//ֹͣtips
	void			StopTipsAction(SysType type);

private:
	std::map<SysType,SysTips>			mTipsMap;
};

#define gSysTipsMgr		CSysTipsMgr::Instance()
