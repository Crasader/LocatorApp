/****************************************************************************
 ս����UI
 ������
 2015-07-29
 ****************************************************************************/

#pragma once

#include "MainUI.h"

class CMainUIFight : public MainUI
{
public:
	CMainUIFight();
	~CMainUIFight();

	bool					onInit();
	void					onOpen();
	void					onClose();

	void				    InitHeadIcon();
	bool					InitSkillBtns();

	void					update(float dt);
    void				    updateLv();
    void				    updateHp();
    void				    updateMp();
	void					updateSkillBtns();
	void					updateSkillCd();
	void					updateNormalAttack(float dt);	// ������ͨ������ť������������
	void					updateTeamHead();
	void					updateMapName(const std::string& name);
	void					updateChatMsg(pk::GS2C_Chat *value);
	void				    updateBuff();
	void					ContinueFight(bool yesOrNo);

	ImageView*				getHeadIcon(){ return m_HeadIcon; }
private:
	//����¼�����
	void					ClickQuit(Ref *pSender, TouchEventType type);
	void					ClickSkill(Ref *pSender, TouchEventType type);
	void					ClickJoyStick(Ref *pSender, TouchEventType type);
	void					clickHead(Ref *pSender, TouchEventType type);
	void					clickChat(Ref *pSender, TouchEventType type);
	void					clickChatWind(Ref *pSender, TouchEventType type);

	//����
	void					SelTask(int, long long);
	void					UpdateTask();	//
	void					updateTaskTrace();
	void					TraceTask(class Task* pTask);
	void					clickTask(Ref *pSender, TouchEventType type);
	void					clickTaskBtn(Ref *pSender, CheckBoxEventType type);

public:
	int						m_defCountSeconds;
	int						m_DestoryCountSeconds;

private:
	Layout*					m_panelLT;	//�������
	Layout*					m_panelLB;	//�������
	Layout*					m_panelRT;	//�������
	Layout*					m_panelRB;	//�������

	//���ͷ��
	ImageView*				m_HeadIcon;
	Text*					m_HeroLv;
	Text*					m_HeroHp;
	Text*					m_HeroMp;
	Layout*					m_HeroHpBar;
	Layout*					m_HeroMpBar;
	ImageView*				m_HeroHpSlot;
	ImageView*				m_HeroMpSlot;
	Text*					m_HeroName;
	bool					m_bIconInit;
	//buff�б�
	ListView*				m_buffListView;

	//ҡ��
	ImageView*				m_JoyStick;

	//���ܲ�
	SkillBtn				m_SkillBtns[Skill_Max_Num];		// ���ܿ������ť
	SkillBtn				m_NormalAtk;					// ��ͨ������ť
	bool					m_bNormalAtkPushed;				// ��ͨ������ť�Ƿ񱻰��£���������ס��ť��������
	float					m_fNormalAtkTimer;				// ��ͨ����������ʱ���������ļ��ʱ��

	//����
	TeamHead				m_TeamHead[Team_Max_Num];

	//����
	Layout*					m_pChatUI;

	class HornContorller*	m_pHornWind;
	class CScrollMsgForMainUI*	m_pMsgWind;
	Button*					m_pButtonChat;
	float					m_fChatBtnShowTime;
	bool					m_bMsgWindScrolled;

	//pvpС��ͼ
	Widget*					m_pPvPSmallMap;
};