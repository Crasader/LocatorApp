/****************************************************************************
 ����ϵͳUI
 ����
 2015-8-24
 ****************************************************************************/
#pragma once
#include "GameDef.h"
#include "GameUI.h"

class CMissionUI : public GameUI
{
public:
	CMissionUI();
	~CMissionUI();

	bool			onInit();
	void			onOpen();

	CREATE_FUNC(CMissionUI);
public:
	Widget*			createMissionItem();						
	void			updateMissionList1();					 // �����Ҳ������б�1
	void			updateMissionList2();					 // �����Ҳ������б�2
	void			updateMissionList3();					 // �����Ҳ������б�3
	void			updateCheckBox();						 // ��������������ѡ�
	void			updateMission(int mission_id);			//  ��������id���µ��������״̬


	void			clickCheckBox(Ref*, TouchEventType);	 // �������ķ���checkbox

	void			clickCloseButton(Ref*, TouchEventType);
	void			clickGoButton(Ref*, TouchEventType);     // �����ǰ����ť
	void			clickGetButton(Ref*, TouchEventType);     // �������ȡ��ť
private:
	ListView*					m_task_1_list;	// ����1�������б�
	ListView*					m_task_2_list;	// ����2�������б�
	ListView*					m_task_3_list;	// ����3�������б�
	Slider*					    m_pSlider[3];   //����

	CheckBox*					m_mission_type_1_item; // ��������1
	CheckBox*					m_mission_type_2_item; // ��������2
	CheckBox*					m_mission_type_3_item; // ��������3

	CheckBox*					m_select_type_item;    // ѡ�����������

	Text*						juqing_label;
	Text*						shangjin_label;
	Text*						chongtu_label;

	vector<Widget*>				m_mission_vec;	// �����ѽӵ�����

public:
};

