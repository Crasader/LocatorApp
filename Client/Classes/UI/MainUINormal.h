/****************************************************************************
 ��ս����UI
 ������
 2015-07-29
 ****************************************************************************/

#ifndef __MainUINormal_h_
#define __MainUINormal_h_

#include "MainUI.h"

class CMainUINormal : public MainUI
{
public:
	CMainUINormal();
	~CMainUINormal();

	bool					onInit();
	void					onOpen();
	void					onClose();
	void					update(float dt);

    void				    updateLv();
    void				    updateHp();
    void				    updateMp();
	void					updateMapName(const std::string& name);
	ImageView*				getHeadIcon(){ return m_HeadIcon; }
    void				    InitHeadIcon();
	void					updateChatMsg(pk::GS2C_Chat *value);
	void					updateHornMsg(pk::GS2C_Chat *value);
	//����ƥ�䵹��ʱUI
	void					ShowMatchStatus();
	void					CloseMatchStatusUI();
	void					OpenMatchStatusUI();

private:
	//����¼�����
	void					ClickJoyStick(Ref *pSender, TouchEventType type);
	void					ClickQuit(Ref *pSender, TouchEventType type);
	void					ClickQuit0(Ref *pSender, TouchEventType type);
	void					ClickCopyMap(Ref *pSender, TouchEventType type);
	void					ClickTeamCopyMap(Ref *pSender, TouchEventType type);
	void					ClickSwitchB(Ref *pSender, TouchEventType type);
	void					ClickSwitchT(Ref *pSender, TouchEventType type);
	void					clickChat(Ref *pSender, TouchEventType type);
	void					clickChatWind(Ref *pSender, TouchEventType type);
	void					clickHead(Ref *pSender, TouchEventType type);
	void					ClickTeam(Ref *pSender, TouchEventType type);
	void					ClickMap(Ref *pSender, TouchEventType type);
	void					ClickTask(Ref *pSender, TouchEventType type);
	void					ClickMenuRB(Ref *pSender, TouchEventType type);
	void					ClickMail(Ref *pSender, TouchEventType type);
	void					ClickManufacture(Ref *pSender, TouchEventType type);
	void					ClickGoToMatch(Ref *pSender, TouchEventType type);
	void					ClickOpenMatch(Ref *pSender, TouchEventType type);
private:
	Layout*					m_panelLT;	//�������
	Layout*					m_panelLB;	//�������
	Layout*					m_panelRT;	//�������
	Layout*					m_panelRB;	//�������

	//���ͷ��
	ImageView*				m_HeadIcon;
	Text*					m_HeroLv;
	Text*					m_HeroName;
	bool					m_bIconInit;

	//ҡ��
	ImageView*				m_JoyStick;

	Layout*					m_panelMenuB;	//�ײ��˵�Panel
	Button*					m_BtnSwitchB;	//�ײ��˵�����

	Layout*					m_panelMenuT;	//�����˵�Panel
	Button*					m_BtnSwitchT;	//�����˵�����

	//����
	Layout*					m_pChatUI;

	class HornContorller*	m_pHornWind;
	class CScrollMsgForMainUI*	m_pMsgWind;
	Button*					m_pButtonChat;
	float					m_fChatBtnShowTime;
	bool					m_bMsgWindScrolled;

	//����ƥ��
	Widget*					m_pMatchStatusUI;
	class Label*			m_pMatchSeconds;
	Widget*					m_pMatchSign;
	RichTextEx*				m_pMatchCopyName;
	Button*					m_pBtnOpenMatchStatus;
	float					m_fMatchUIShowSeconds;

	//��ͼ
	Text*					m_mapName;
};
//�������������������
void	openTeamUI(UiOpenType openType);
#endif