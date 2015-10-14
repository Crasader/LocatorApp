/****************************************************************************
 ����UI
 ����
 2015-9-17
 ****************************************************************************/
#pragma once
#include "GameDef.h"
#include "GameUI.h"
#include "../GameScene/GameUILayer.h"

#define MAX_FREE_REVIVE_COUNT 3
class CReviveUI : public GameUI
{
public:
	CReviveUI();
	~CReviveUI();

	bool			onInit();
	void			onOpen();
	void			onClose();

	void			update(float dt);
	void			updateUI();		//	ˢ�½���

	CREATE_FUNC(CReviveUI);
public:				
	void			updateTimer();								//  ����ʱ���º���
	void			updateProgress();							//  ���������º���
	void			clickGiveupButton(Ref*, TouchEventType);	//  �������������ť
	void			clickReviveButton(Ref*, TouchEventType);	//  ����������ť

	void			deadTimeOut();								//  ����״̬����

private:
	Text*						m_title_text;		// �����ı�
	Text*						m_timer_text;		// ����ʱ�ı�

	ProgressTimer*				m_progressBar;		// ���ν�����

	int m_deadRestTime;			//	����ʱ���� ��λ����
	int	m_restPoint;			//	���ν�����ʣ��ĵ��� ��ֵΪ10000
	int m_need_gold;			//  ������Ҫ�Ľ�� 

public:
};

