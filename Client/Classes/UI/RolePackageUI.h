/*
 * ģ��:��ɫ��������ģ��
 * ���ߣ�Tangbo
 */
#pragma once
#include "GameUI.h"
#include "Net/pk_trade.h"


typedef   vector<pk::C2GS_NpcShopSell>  SaleItem_v;

class RolePackageUI_cl:public GameUI
{
public:
	RolePackageUI_cl();
	~RolePackageUI_cl();

	bool            onInit();
	void            onOpen();


	//��ʼ������������
	void           initScrollView();


	//����������ʾ
	void            setShowByType(int _type);

	//��ť�ص�
	void            callBack(Ref* _ref, TouchEventType _type);

	//ˢ����ʾ
	void            freshShow();

	//����
	void            update(float dt);

private:
	
	//����㻬����ָ��
	ScrollView *              m_pScorllView[4];    

	//����ָ��
	Slider     *              m_pSlider[4];

	//��ǰ��ʾ����
	int                       m_curTypeIdx;

	//ѡ�е���Ʒ
	SaleItem_v                m_vSaleItem[4];

	//��ʾ�ڵ����
	Text*                     m_numText[4];

	//���
	Text*                     m_jbText;

	//��¼ÿ���������ڵ����
	int                       m_childCount[4];

	//��¼�����
	__int64                       m_jb;
};