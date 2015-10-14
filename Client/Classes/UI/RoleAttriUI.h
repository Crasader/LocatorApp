/*
 * ģ�飺��ɫ���Ժ�װ������
 * ���ߣ�Tangbo
 */
#pragma once
#include "GameUI.h"
#include "Net/pk_item.h"


class RoleAttriUI_cl:public GameUI
{
public:

	RoleAttriUI_cl();
	~RoleAttriUI_cl();

	bool            onInit();
	void            onOpen();

	//���ı�ǩ��ť��ʾ
	void            setBtnShowByIdx(int idx);

	//������ʾװ��������ֵ����
	void            setPanelShowByIdx(int idx);

	//��ʼ����ϸ���Խ���
	void            initDetailData();

	//��ʼ��Role Equip
	void            initRoleEquip();
	//ˢ������װ����
	void            RefreshRoleEquip(pk::GS2C_EquipGetItem_Ret *value);

	//��Ӵ����¼�
	void            addEquipTouchEvent(CGridIcon* grid);

	//�õ���ǰ��װ��Ϊװ��
	int             getEquipNum();

	//����ť�����¼�
	void            callBack(Ref * _ref, TouchEventType _type);

	//װ����ť�����¼�
	void            equipCallBack(Ref* _ref, TouchEventType _type);

	//����װ���ص�
	void            goddeviceCallBack(Ref* pSender, TouchEventType type);

	//����������ť�ص��¼�
	void            operatCallBack(Ref* _ref, TouchEventType _type);

	//ˢ����ʾ
	void            freshShow();

	//��⾫���Ƿ��ϵ���������
	//param��_spr ��ʱ����װ������ָ��
	bool            checkBagIsOverlap();

	void            updateTime(float fd);

	//��ȡ��������װ��������ڵ�
	inline ScrollView* getRoleEquipRoll(){return m_pScroll;} 

private:

	//��ǩ��ť
	Button *           m_pSignBtn[3]; 

	//������װ��  0:���� 1:����  2-4:����    
	Button *           m_pEquipItem[6];

	//��ڵ�      0:���� 1:���� 2:��ϸ����
	Layout *           m_pPanel[3];

	//���Խڵ�    0:hp 1:magic 2:attack 3: defence 4:strength_at 5:strengt_sk
	Text *             m_pLabel[6];

	//ս���ڵ�
	Label *             m_pAttackText;

	//װ������������
	ScrollView*        m_pScroll;

	//����ڵ�
	Slider*            m_pSlider;

	//��ǰѡ��װ��id
	int                m_curEidx;

	//��ǰ�Ľ���id
	int                m_curUIidx;

	//�Ƿ񳤰�
	bool               m_isLongTouch;

	//����ʱ��(��)
	float              m_longTime;

	//˫��ʱ��
	float              m_delayTime;

	//װ���ƶ�
	ImageView*         m_pMoveSprite;

	//�����Ļ���������
	Rect               m_scrollRect;   

	//Ҫж�µ�װ��id
	vector<int>        m_takeoff;

	//�Ƿ�֧��˫��
	bool               m_doubleTouched;

	//�Ƿ�֧�ֳ���
	bool               m_longTouched;
 };

