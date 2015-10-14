/*
 * ģ��: item������ʾ����
 * ����: Tangbo
 * ʱ��: 2015/9/23
 */

#pragma once
#include "GameUIWithOutSideTouchEvent.h"
class ItemTipsUI :public GameUIWithOutSideTouchEvent
{
public:
	ItemTipsUI(void);
	~ItemTipsUI(void);

	bool   onInit();

	//����ϴ���ʾ������
	void   resetData();

	void   initByItem(CItem* item,Point locationpos, GameUI * ui);

	void   initByGoddevice(GodDevice* goddevice, Point locationpos, GameUI * ui);

	//��ʾ�������ʾ
	static void   show(GodDevice* goditem,Point locationpos, GameUI * ui = nullptr);
	
	//��ʾ��ͨ��Ʒ����ʾ
	static void   show(CItem* item, Point locationpos, GameUI * ui = nullptr);

	//�¼��ص�
	void   eventCallBack(Ref* pSender, TouchEventType touchevent);

	//�ⲿ�¼�
	void   outsideCallback();

private:

	//���߸��ڵ�
	ImageView* m_pRoot;

	//����icon
	ImageView * m_pIcon;

	//��������
	Text*       m_pName;

	//���߾����ȼ�
	Text*       m_pRefineVal;

	//�Ǽ��б�
	ListView*   m_pStarList;

	//�����б�
	ListView*   m_pAttriList;

	//���ư�ť
	Button*     m_pOptionBtn;

	//��������
	Text*       m_pSkillText;

	//��������
	Text*       m_pRuleText;

	//���ǽڵ�
	Widget*     m_pStar;

	//���Խڵ�
	Widget*     m_pAttri;

	//��������
	CItem*      m_pItem;

	//��������
	GodDevice*  m_pGodDevice;

	//Ҫ�رյ�ui
	GameUI*     m_pGameUI;
};

