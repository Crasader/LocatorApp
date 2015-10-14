/*
 ģ��:�������
 ����:TangBo
 ʱ��:2015/8/31
 **/
#pragma  once
#include "GameUI.h"

class SkyBookUI_cl;
 
class SkyBookCalcUI_cl:public GameUI
{
public: 
	friend class SkyBookUI_cl;
	SkyBookCalcUI_cl();
	~SkyBookCalcUI_cl();
	bool onInit();

	void onOpen();

	void callback(Ref* pSender, TouchEventType touchtype);

	CC_SYNTHESIZE(int, m_count, CurCount);

private:
	SkyBookUI_cl * pUI;
	Text*       m_pText;
};


class SkyBookUI_cl:public GameUI
{
public:
	friend class SkyBookCalcUI_cl;
	SkyBookUI_cl();
	~SkyBookUI_cl();

	bool onInit();
	void onOpen();

	//��Ƕ����
	void initInlayLayer();

	//��������
	void initRefinedLayer();

	//�ϳɽ���
	void initSyntheticLayer();

	//��������
	void initBagLayer();



	//��Ƕ�������ð�ť,״̬�л�
	void inlayConfigBtnChange();

	//���ݵ�ǰ��Ƕ����ˢ�����ݽ���
	void freshInlaydData();

	//ˢ������
	void freshCapacity();

	//����Ƿ�������������ײ
	void checkInsertRectOther();

	//��ʾ��Ӧ������ϵͳ����
	void showLayerByIndex();

	//��ť״̬��ʾ
	void showBtnStatus();

	//����ť�ص�
	void callBack(Ref * pSender, TouchEventType touchtype);

	//��Ƕ���Ӵ����ص�
	void inlayGridCallback(Ref* pSender, TouchEventType touchtype);

	//��Ƕ���������ť�ص�
	void inlayOptionCallback(Ref* pSender, TouchEventType touchtype);

	//��Ƕ�������ð�ť�ص�
	void inlayConfigCallback(Ref* pSender, TouchEventType touchtype);

	//�������������ť�ص�
	void refinedOptionsCallback(Ref* pSender, TouchEventType touchtype);

	//����������ӻص�
	void refinedGridCallback(Ref* pSender, TouchEventType touchtype);

	//�ϳɽ��������ť�ص�
	void syntheicOptionCallback(Ref* pSender, TouchEventType touchtype);

	//������ǩ��ť�ص�
	void bagSignBtnCallback(Ref* pSender, TouchEventType touchtype);

	//����������ť�ص�
	void bagOptionCallback(Ref* pSender, TouchEventType touchtype);

	//��ת����������, ���������ư�ť 
	//val true��ʾ��ǩҳ false û�б�ǩ
	void setMianBtn(bool val);

	//���ر�ǩ��������
	//param 0 �Ǳ�ʾ������Ƕ��ȫ��������������������
	//      1 �Ǳ�ʾ��ȫ�����������������������
	int  getSignBagType(int param);

	//���ı�����ǩ��ʾ
	void showBagLayerBySign();

public:        //������Ϣ

	/**********����������Ϣ**********/
	//������Ƕ��Ϣ
	void          sendInlayMsg();

	//���ͼ�����Ϣ
	void          sendRefinedMsg();

	/********����ص��¼�********/

	//�����������÷���
	void updateChangeConfigRet(pk::C2GS_TianShuChangeIndex_Ret* value);

	//���¿�λ�л�����
	void updateChangeHoleRet(pk::C2GS_TianShuChangeSolt_Ret* value);

	//������������
	void upgradeSkyBook(int8 lv, int16 exp);

	//��ʾ�ϳ�����
	void showNewSkyBook(int16 dataid);

	//����װ����������ǿ�� _type ǿ��������
	void updateCapacity(int8 _type);

	//����װ�������λǿ��
	void updateHole(int8 _type, int8 solt);

	//������Ƕ
	void updateInlay(pk::GS2C_TianShuSet_Ret* value);

	//����ʱ�䶨ʱ��
	void updateLongTimer(float fd);

public:           //�����Զ����¼�

	//���������¼�
	void       signBagOneTouch(CItem* item);

	//����˫���¼�
	void       signBagDoubleTouch(CItem* item);

private:

	//�Ƿ��б�ǩ��ʾ
	bool                m_isShowSign;

	//��ǰ�����Ƿ��  setMianBtn��ʹ��
	bool               m_isOpened;

	//��ǰѡ��ı�ǩҳ
	int                 m_curIndex;

	//��¼�ϴ���ʾ����idx
	int                 m_lastIndex;

	//��ǰ����״̬
	int                 m_CurOptionStutas;

	//��ǰ�Ƿ����㳤���¼� ������Ƕ������Ӱ�ť
	bool                m_islongTouched;

	//��ǰ�ƶ�����
	ImageView*          m_pMoveBook;

	//�����¼���¼
	float               m_fLongTime;

	//��ǰײ���ĸ���id
	int                 m_curInsertId;

	//��������������
	//0   Ϊ��Ƕ���� ���� ���� ����
	//1-2 Ϊ�������� �ϳɽ���
	//3   Ϊ��������  
	//4-5 Ϊ����������ӽ���  4�б�ǩҳ 5û�б�ǩҳ
	Layout*             m_pPanle[6];

	//����ť
	//0���� 1���� 2���� 3���� 4�ϳ� 5����
	Button*             m_pButton[6];


	//��Ƕ�ĸ���ָ��
	//����˳��:0-8  0��λ����λ�� ������Ϊ��ͨλ��
	ImageView*          m_pInlayGrids[9];

	//��Ƕ�����ð�ť
	Button*             m_pConfigBtn[3];

	//��Ƕ�Ĳ�����ť    0ж�� 1����ǿ�� 2��λǿ��
	Button*             m_pInlayOpBtns[3];

	//��Ƕ�������ı�
	Text*               m_pCapacityText;

	//��Ƕ����list�б�
	ListView*           m_pInlayList;

	//��Ƕʹ������id
	int8                m_curConfigIdx;

	//��ǰѡ��Ŀ�λ Ĭ��ֵ��-1����ʾû��ѡ��  ÿ�β�����Ҫ���¸���ֵ
	int                 m_curSlot;

	//������
	int                 m_totalCapacity;

	//��ǰ����
	int                 m_curCapacity;

	//�Ƿ�������ǿ��
	bool                m_isCapacity;

	//�Ƿ�����λǿ��
	bool                m_isHole;

	//�Ƿ�ж�²���
	bool                m_isGiveUp;


	//����
	//Ҫ�����ĸ���ָ��
	ImageView*          m_pRefinedGrid;

	//�����Ľ�����
	LoadingBar*         m_pRefinedBar;

	//�������Ǽ���ǩ   
	//����ı�0-1 0Ϊ��ʼ�Ǽ� 1Ϊ�����Ǽ�
	//�ұ��ı�2-3 2Ϊ��ʼ�Ǽ� 3Ϊ�����Ǽ�
	Text*               m_pStarText[4];

	//������������
	Text*               m_pRefinedTSName;

	//�����Ĳ�����ť    
	//0 Ϊ������ť 1Ϊ���� 2Ϊȡ��
	Button*             m_pRefinedOpBtn[3];

	//���������б�
	//0 Ϊ�Ա������б�
	//1 Ϊ�����б�
	ListView*           m_pRefinedLists[2];

	//�ϳ�
	//�ϳɸ���ָ��
	//0-3 Ϊ���ϸ��� 5ΪĿ�����
	ImageView*          m_pSyntheicGrids[5];

	//�ϳɵĲ�����ť    
	//0 Ϊ�ϳɰ�ť 1Ϊ���� 2Ϊȡ��
	Button*             m_pSyntheicOpBtn[3];

	//�ϳɺ����������
	Text*               m_pSyntheicName;

	//�ϳɺ����������б�
	ListView*           m_pSyntheicList;

	//����
	//������ǩ����
	//0����Ƕ 1ȫ�� 2���� 3���� 4 ����  
	Button*             m_pBagSignBtn[5];
	//��ǩ��������
	//0����Ƕ 1ȫ�� 2���� 3���� 4 ����  
	ScrollView*         m_pBagSignScroll[5];
	//��ǩ��������
	Slider*             m_pBagSignSlider[5];

	//�����ޱ�ǩ����
	ScrollView*         m_pBagScroll;

	//�����ޱ�ǩ����
	Slider*             m_pBagSlider;

	//����ѡ����������
	Text*               m_pBagSelectName;

	//����ѡ�����������б�
	ListView*           m_pBagSelectList;
	
	//����������ť
	//[0] �����  [1] �ұ�
	Button*             m_pBagOptionBtn[2];

	//������ǰѡ��ı�ǩ
	int                 m_curBagSignIdx;

	//��¼��ǰѡ�����������
	int                 m_curTotalBook;

	//��ǰ����ѡ������
	CItem*              m_pBagSelectBook;

	//��ǰѡ�е���������
	vector<CItem*>      m_vSelectBook;

	//������������
	vector<pk::tian_shu_material> m_vSelectMaterial;
};