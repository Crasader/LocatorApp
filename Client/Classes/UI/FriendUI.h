#pragma once

#include "GameUI.h"
#include "Net/pk_friend.h"

class FriendUI_cl: public GameUI
{
public:
	FriendUI_cl();
	~FriendUI_cl();

	bool onInit();

	void onOpen();

	void onClose();

	//��ʼ����ť
	//param : _idx ѡ��ť���±�
	void setSelectBtnByIdx(int _idx);

	//���ýڵ�����
	void setChildShowDate(Widget * child, pk::Friend_Info* _info);

	//��ʾ�Ǹ��б�
	void setShowByIndex(int _index);

	//��ʼ�������б�
	void initFriendList();

	//ˢ�º����б�
	void freshFriendList();

	//��ʼ���������б�
	void initBlackList();

	//ˢ�º������б�
	void freshBlackList();

	//��ʼ������б�
	void initRelativeList();

	//ˢ������б�
	void freshRelativeList();

	//�������ͻص�����
	void callBack(Ref * pSender, TouchEventType _type);

	//���Ѳ�������ص�
	void callBackFriendB(Ref * pSender, TouchEventType _type);

	//���Ѳ�������ص�
	void callBackBlackB(Ref * pSender, TouchEventType _type);

	//���Ѳ�������ص�
	void callBackRelativeB(Ref * pSender, TouchEventType _type);

	//list�ص�
	void callBackList(Ref * pSender, TouchEventType _type);

private:

	Button*                  m_selectbtn[3];                 //�б�ѡ��ť

	ListView*                m_pViewList[3];                 //listview:0����, 1������, 2������
	Layout*                  m_pBtnPanel[3];                 //option:0����, 1������, 2������ 
	Slider*                  m_pSlider[3];                   //����
	Widget*                  m_selectChild[3];               //ѡ��Ľڵ�
	float                    m_fpercent[3];                  //�����б�bar��λ��
	int                      m_index;                        //��ǰѡ��
	int64                    m_selectPid[3];         
	string                   m_selectPname[3];
	int64                    m_curplayerid;                  //��ǰ��ѡ���playerid
	string                   m_curpname;                     //��ǰ�������
};