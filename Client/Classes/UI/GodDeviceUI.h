/****************************************************************************
 ����ϵͳUI
 ����
 2015-9-2
 ****************************************************************************/
#pragma once
#include "GameDef.h"
#include "GameUI.h"

class ShaderSprite;

class CGodDeviceUI : public GameUI
{
public:
	CGodDeviceUI();
	~CGodDeviceUI();

	bool			onInit();
	void			onOpen();

	CREATE_FUNC(CGodDeviceUI);
public:
	Widget*			createTabItem();						

	void			clickCheckBox(Ref*, TouchEventType);		// ��������ķ���checkbox
	void			clickCloseButton(Ref*, TouchEventType);
	void			clickDressButton(Ref*, TouchEventType);     // ����˴�����ť
	void			updateGodDeviceList();						// ˢ�������б�
	void			updateGodDeviceData(int index);			// ˢ��ѡ������������
private:
	ListView*					m_type_list;	// �������͵��б�

	CheckBox*					m_select_type_item;    // ѡ�����������
	Button*						m_dress_btn;		   // װ����ť

	Text*						m_name_label;		// ��������
	Text*						m_des_label;		// ��������
	Text*						m_attr_label_1;		// ��������1
	Text*						m_attr_label_2;		// ��������2
	Text*						m_attr_label_3;		// ��������3
	Text*						m_attr_label_4;		// ��������4

	ShaderSprite*				m_skill_icon_1;		// ����ͼ��1
	ShaderSprite*				m_skill_icon_2;		// ����ͼ��2
	ShaderSprite*				m_skill_icon_3;		// ����ͼ��3
	ShaderSprite*				m_skill_icon_4;		// ����ͼ��4

	vector<ShaderSprite*>		m_skill_icon_vec;		// ����ͼ��vec

	ImageView* m_skill_icon_bg_1;
	ImageView* m_skill_icon_bg_2;
	ImageView* m_skill_icon_bg_3;
	ImageView* m_skill_icon_bg_4;
	vector<ImageView*>		    m_skill_icon_bg_vec;	// ����ͼ�걳��vec

	Text*						m_skill_name_1;		// ��������1
	Text*						m_skill_name_2;		// ��������2
	Text*						m_skill_name_3;		// ��������3
	Text*						m_skill_name_4;		// ��������4

	vector<Text*>				m_skill_name_vec;	// ��������vec

	Text*						m_skill_des_1;		// ��������1
	Text*						m_skill_des_2;		// ��������2
	Text*						m_skill_des_3;		// ��������3
	Text*						m_skill_des_4;		// ��������4

	vector<Text*>				m_skill_des_vec;	// ��������vec

	vector<int>					m_indexToGodCfgId_vec; // �±��Ӧ��cfgId
public:
};

