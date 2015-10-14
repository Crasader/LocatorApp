#pragma once
#include "GameUI.h"
#include "../GameScene/GameUILayer.h"
#include "CustomCtrl/ScrollTable.h"
#include "GameScene/NPC.h"

enum FuncEventType
{
	FuncEvent_Transfer = 1,	//����
	FuncEvent_NpcStore = 2,	//�̵�
	FuncEvent_Strength = 3,	//ǿ��
	FuncEvent_CopyMap  = 4,	//����
	FuncEvent_SaleBank = 9,	//����
	FuncEvent_Battle  = 10,	//ս��
	FuncEvent_BuffStore= 11,//�����̵�
};

class CNpcDialog : public NpcUI
{
public:

	CNpcDialog();
	~CNpcDialog();

	bool			onInit();
	void			onOpen();
	void			onClose();

	void			InitFuncsPanel();
	void			AdaptSizeAndPos(size_t nFunsSize);
	void			InitTaskPanel();
	void			InitFuncPanel();
	bool			InitLeavePanel();

	void			FillTaskIds(vector<int>& completeVec, vector<int>& acceptVec);

	void			EventByFuncName(size_t nIndex);

	void			clickBtnClose(Ref* pSender, TouchEventType type);
	void			clickFuncName(Ref* pSender, TouchEventType type);
	void			clickTaskItem(int nIndex, long long noused);
	void			clickFuncItem(int nIndex, long long noused);
	void			EnterBattleConfirm(bool yesOrNo);

private:
	Widget*			m_pDialogPanel;
	Text*			m_pNpcName;
	Text*			m_pTalkContent;
	Widget*			m_pDivImg;
	Widget*			m_pFuncsPanel;
	NpcCfg*			m_pNpcCfg;

	CScrollTable*	m_pTaskList;
	CScrollTable*	m_pFuncList;
	Button*			m_pLeaveBtn;

	vector<Npc_functionCfg*>		m_pNpcFuncCfg;
	vector<int>				m_taskids;
};
