/****************************************************************************
 5������UI
 ������
 2015-08-06
 ****************************************************************************/
#pragma once
#include "GameDef.h"
#include "GameUI.h"
#include "Net/pk_map.h"
#include "GameScene/Hero.h"

class CWaveEnd : public GameUI
{
public:
	CWaveEnd();
	~CWaveEnd();

	bool			onInit();
	void			onOpen();
	void			clickRetreat(Ref*, TouchEventType);
	void			clickContinue(Ref*, TouchEventType);
	void			CountSeconds(float dt);
	void			UpdateSelection();
	void			UpdateRewards();

private:
	class CScrollTable*		m_pRetreatList;	//�����б�
	class CScrollTable*		m_pContinueList;	//�����б�
	class CScrollTable*		m_pUnSelList;	//δѡ���б�

	Widget*					m_pMainUI;

	class CScrollMenu*		m_pReWardMenu;
	RadioButtonSet*			m_pBtn;
	class Label*			m_pMagicNum;

	int						m_CountSeconds;;

public:
	static std::map<int,pk::GS2C_GiveSelectionToContinueCopy> s_waveRewards;
};

