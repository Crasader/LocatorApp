/****************************************************************************
 ս���Ƽ���UI
 ����
 2015-9-29
 ****************************************************************************/
#pragma once
#include "GameDef.h"
#include "GameUI.h"
#include "../GameScene/GameUILayer.h"

class CHallTechTreeUI : public GameUI
{
public:
	CHallTechTreeUI();
	~CHallTechTreeUI();

	bool			onInit();
	void			onOpen();
	void			onClose();
	
	void			UpdateAll();

	void			update(float dt);

	CREATE_FUNC(CHallTechTreeUI);
public:				
	void			clickBackButton(Ref*, TouchEventType);			//  ������������水ť
	void			clickUpgradeButton(Ref*, TouchEventType);		//  �����ڰ�ť
	
	void			clickCheckBox(Ref*, TouchEventType);			// ����Ƽ�������checkbox 

	void			updateRightPanel(int index);					// �����Ҳ����
private:
	Text*						m_name_text;		// �Ƽ��������ı�
	Text*						m_des_text;			// �Ƽ��������ı�
	Text*						m_need_text;		// �Ƽ������������ı�

	Button *					upgrade_btn_;
	Text*						m_time_text;		// �Ƽ���������ʱ��

	ImageView*					m_bar_bg;			// ���������� 
		
	LoadingBar*					m_bar;				// ������

	Layout*						m_tree_panel;		// �Ƽ����������

	ListView*					m_listView;			// �Ƽ������������б�
	ui::ScrollView*				m_scrollView;		// �Ƽ�����������б�

	Button*						m_upgrade_btn;		// ������ť

	vector<ui::Widget*>			m_treeIcon;			// �Զ���ICONͼ��vec

	CheckBox*					m_select_node_item;    // ѡ��ĿƼ����ڵ�

	int	m_index;	// ѡ��ĿƼ����±�
public:
};

