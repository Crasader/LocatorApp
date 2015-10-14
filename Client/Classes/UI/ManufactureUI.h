/*
 *ģ��:�������
 *����:Tangbo
 *ʱ��:2015/9/15
 */
#pragma once

#include "GameUI.h"

//������ʾ����
class FastTipsUI_cl:public Layer
{
public:
	
	FastTipsUI_cl():m_id(-1),m_pLoadingbar(nullptr),m_pGold(nullptr)
	{

	}

	bool initdata(int id);

	static FastTipsUI_cl* create(int id);

	void   callback(Ref * pSneder, TouchEventType touchevent);

	void   fastCallback(Ref* pSender, TouchEventType touchevent);

	//������ʾ���
	void   setFastGold();

private:

	int      m_id;               //��ǰ�����±�

	LoadingBar*  m_pLoadingbar;

	Widget*      m_pGold;            //������ʾ

	Rect         m_rect;

	Point        m_point;
};

class ManufactureUI_cl:public GameUI
{
public:
	ManufactureUI_cl();
	~ManufactureUI_cl();
	friend class FastTipsUI_cl;
	bool onInit();
	void onOpen();

	/*��ʼ��ģ��*/

	//��ʼ���������
	void initManufacture();

	//��ʼ�������߽���
	void initLine();

	//��ʼ��ͼֽ����
	void initBluePrint();

	//��ʼ�����Ͻ���
	void initMaterial();

	/*��������*/
	void changePanel();

	void changeBluePrintPanel();

	//����ͼֽ����ʼ������
	void pushBlueprintByID(int id);
	void pushBlueprintByItem(CItem* item);

	/*�ص�ģ��*/

	//����ť�ص��¼�
	void  callback(Ref* _ref, TouchEventType touchevent);

	//������������ť�ص�
	void  manufactureOptionCallback(Ref* _ref, TouchEventType touchevent);

	//���������ϻص�
	void  manufactureMaterialCallback(Ref* _ref, TouchEventType touchevent);

	//��ȡ�����߻ص�
	void  getLineCallback(Ref* _ref, TouchEventType touchevent);

	//ͼֽ���淵��
	void  blueCallback(Ref* _ref, TouchEventType touchevent);

	//���Ͻ��淵��
	void  materialCallback(Ref* _ref, TouchEventType touchevent);

	//��ʾ�����߽�����ʾ
	void callbackShowBarTips(Ref* _ref, TouchEventType touchevent);

	//ͼֽ�������ӵ���ص��¼�
	void  oneTouchCallback(CItem* item);

	/*����ģ��*/
	//��ʼ����ص�
	void  startManufactureRet(int right);

	//�����µ������߻ص�
	void  openNewLineRet();

	//��ȡ�����߻ص�
	void  getLineRet(int dataid);

protected:

	//���ò�����ʾ
	//idx:�����±�  str:���ϵ�id��num
	void  setMaterialShow(int idx, string& str);

	//���������߽ڵ�
	Widget*  createLineChildById(int id);

	//���½ڵ�
	void freshLineById(int id);

	//����ÿ���ڵ����ʾ
	void  update(float fd);

	//ͼֽ����
	CItemGridArray* getCurTypeBluePrint(int type);

private:

	/*��¼ģ��*/
	//��ǰ�����±�
	int            m_pageIndex; 

	//��ǰ�Ƿ�ѡͼֽ
	bool           m_bSelectBlueprint;

	//����id
	int            m_blueprintID;

	//�Ƿ�ȴ����춯���ص�
	bool           m_bActionRet;

	/*�ڵ�ָ��*/
	//�ĸ��������ڵ�
	//0���� 1������ 2ͼֽ 3����
	Layout*        m_pPanel[4];

	//����ť
	//0���� 1������ 2ͼֽ 3���� 4�ر�
	Button*        m_pButton[5];

	//�����������  ˳ʱ�뻷������ �����ϱߵ�����Ϊ���
	ImageView*     m_pMaterialIcon[6];

	//���������   ˳ʱ�뻷������ �����ϱߵ�����Ϊ���
	Text*          m_pMaterialCount[6];

	//���������ť  0����ͼֽ 1��ʼ����
	Button*        m_pOptionBtn[2];

	//�����������Ʒ  0��ɫ��� 1��ɫԪ�� 2Ŀ����� 3����ʱ�� 4������
	Widget*          m_pNeed[5];

	//��ǰ����ͼֽ
	ImageView*     m_pCurBlueprint;

	//��ǰ����ѡ���ͼֽ
	CItem*         m_pBlueItem;


	//�����ߵ�����
	ScrollView*    m_pLineScroll;

	//�����ߵĻ���
	Slider*        m_pLineSlider;

	//���������� ��Ϊ����ڵ�
	ImageView*     m_pLineChild;

	//Ĭ����ʼλ��
	Point          m_lineStartPos;

	//�����߽ڵ�ĺ�����
	int            m_lineDisX;

	//�����߽ڵ��������
	int            m_lineDisY;

	//��������߽ڵ�
	vector<Widget*> m_vLineWidget;

	//ͼֽ����  0ȫ�� 1���� 2���� 3���� 4���� 5����
	ScrollView*    m_pBlueScroll[6];

	//ͼֽ����  0ȫ�� 1���� 2���� 3���� 4���� 5����
	Slider*        m_pBlueSlider[6];

	//ͼֽ������ť 0ȫ�� 1���� 2���� 3���� 4���� 5���� 6���� 7�ع�
	Button*        m_pBlueBtn[8];

	//ͼֽ������ť 0���� 1���� 2���� 3���� 4����
	CItemGridArray* m_pBlueTypeArrary[5];

	//ͼֽ��ǩ
	int           m_blueSign;

	//����
	ScrollView*    m_pMaterialScroll;

	//���ϻ���
	Slider*        m_pMaterialSlider;

	//���ϲ�����ť 0���� 1�ع�
	Button*        m_pMaterialBtn[2];

	FastTipsUI_cl*  m_pFastTips;
};