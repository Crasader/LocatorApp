/****************************************************************************
 �ʼ�ϵͳUI
 ����
 2015-8-12
 ****************************************************************************/
#pragma once
#include "GameDef.h"
#include "GameUI.h"

class CMailUI : public GameUI
{
public:
	CMailUI();
	~CMailUI();

	bool			onInit();
	void			onOpen();

	CREATE_FUNC(CMailUI);
public:
	Widget*			createMailItem();						
	void			updateMailContent(int64 mail_id);			 // �����Ҳ��ʼ���ʾ��������
	void			updateMailList();						 // ��������ʼ��б�

	void			clickCheckBoxMail(Ref*, TouchEventType); // ����ʼ����鿴�ʼ�

	void			clickCloseButton(Ref*, TouchEventType);
	void			clickGetAwardButton(Ref*, TouchEventType);
	void			clickGetAllButton(Ref*, TouchEventType);
	void			clickDeleteReadButton(Ref*, TouchEventType);
private:
	ListView*					m_mail_list;		// �ʼ��б�
	Button*						m_get_award_btn;	// ��ȡ������ť
	Slider*						mail_list_slider;

	Text*						m_mail_content_txt; // �ʼ�����
	Text*						m_mail_title_txt;	// �ʼ�����
	ScrollView*					m_mail_award_srcoll;	// �ʼ������б�

	CheckBox*					m_select_mail_item; // ѡ����ʼ�

	vector<int64>				m_mail_id_vec;
public:
};

