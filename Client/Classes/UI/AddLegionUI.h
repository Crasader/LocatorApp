/*ģ��: ������Ž���
 *����: Tangbo
 *ʱ��: 2015/9/29
 */
#pragma once
#include "GameUI.h"


class AddLegionUI_cl:public GameUI
{
public:
	AddLegionUI_cl();
	~AddLegionUI_cl();

	bool onInit();

	//���Ľ�����ʾ
	void    changeShow();

	//���¾����б�
	void    updateLegionList(Legion_V * vec = nullptr);

	//������Ա
	Legion_V searchMember();

	//��ǩ��ť�ص�
	void    callbackSign(Ref* pSender, TouchEventType event);

	//���ư�ť�ص�
	void    callbackOption(Ref* pSender, TouchEventType event);

	//������ť�ص�
	void    callbackSearch(Ref* pSender, TouchEventType event);

	//�������������ص�
	void    callbackCreateInput(Ref* textfield, TextFiledEventType event);

	//�����������������ص�
	void    callbackSearchInput(Ref* textfield, TextFiledEventType event);

private:

	//��ǰ������ʾ��index
	int        m_nIndex;

	//������ָ��  0��Ϣ 1�����б� 2��������
	Widget*    m_pPanel[3];

	//��ǩ��ť  0��Ϣ 1���� 2�ر�
	Button*    m_pSignBtn[3];

	//�����б�
	ListView*  m_pLegionList;

	//�������ŵ�����ؼ�
	TextField* m_pLegionName;

	//�������ŵ�����ؼ�
	TextField* m_pSearchName;
};