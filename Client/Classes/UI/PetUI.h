/****************************************************************************
 ����UI
 ����
 2015-10-13
 ****************************************************************************/
#pragma once
#include "GameDef.h"
#include "GameUI.h"
#include "../GameScene/GameUILayer.h"

class CPetUI : public GameUI
{
public:
	CPetUI();
	~CPetUI();

	bool			onInit();
	void			onOpen();
	void			onClose();

	CREATE_FUNC(CPetUI);
public:				
	void			clickBackButton(Ref*, TouchEventType);		//  ������ذ�ť
	void			clickTianshuButton(Ref*, TouchEventType);	//	��������鰴ť
	void			clickQianghuaButton(Ref*, TouchEventType);	//  �����ǿ����ť

	void			clickCheckBox(Ref*, TouchEventType);		// ����������checkbox 

	void			clickSwitch(Ref*, TouchEventType);		//  �л���尴ť

	void			updatePetList();						//  ���³����б�

	void			updateAttributePanel();					//  �����������

	void			updateQianghuaPanel();					//  ����ǿ�����
private:

	Button*		m_BackButton_btn_2;		// ǿ�����ķ��ذ�ť
	Button*		m_Qianghua_btn_2;		// ǿ������ǿ����ť
	Button*		m_Qianghua_btn;			// ǿ����ť
	Button*		m_Tianshu_btn;			// ���鰴ť

	ImageView*	m_attribute_panel;		// �������
	ImageView*	m_qianghua_panel;		// ǿ�����

	ListView*	m_listView_pet;			// �����б�

	ListView*	m_listView_attribute;	// ���������б�
	ListView*	m_attr_list;			// ǿ�������б�

	CheckBox*	m_select_pet_item;		// ѡ��ĳ���
public:
};

