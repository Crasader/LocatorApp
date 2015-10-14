/*
�����ͼ
������
2015-8-19
*/

#pragma once
#include "GameDef.h"
#include "GameUI.h"
#include "MainUIFight.h"

class CUIWorldMap :public GameUI
{
public:
	typedef enum _worldMapMode
	{
		WorldMapMode_None = 0,
		WorldMapMode_PlaceList,
		WorldMapMode_CopyList,
		WorldMapMode_Prepare,
		WorldMapMode_Count,
	}WorldMapMode;

	typedef enum _matchBtnStatus
	{
		MatchBtnStatus_None = 0,
		MatchBtnStatus_Cancel,
		MatchBtnStatus_CancelAndStart,
		MatchBtnStatus_Started,
		MatchBtnStatus_Prepare,
		MatchBtnStatus_PrepareOver,
		MatchBtnStatus_Count,
	}MatchBtnStatus;

public:
	CUIWorldMap(void);
	~CUIWorldMap(void);

	//��ʾ�������븱����UI
	static	void			ShowGameCopyToEnter(int nMapId)
	{
		GameCopy* pGameCopy = gCopyDataMgr->GetGameCopy(nMapId);
		if(!pGameCopy) return;

		CUIWorldMap* pUI = (CUIWorldMap*)gGameUILayer->open(IDU_WORLDMAPUI);
		if(!pUI) return;
		{
			pUI->ShowLocaleList(pGameCopy->worldMapId);
			pUI->ShowPrepare(pGameCopy);
		}
	}

	virtual bool			onInit();
	virtual void			onOpen();
	virtual void			update(float dt);

	//��ͼ��ʾģʽ,�ص��б�,�����б�,׼��UI��ƥ��UI
	inline WorldMapMode		GetMode() { return m_curMode; } 
	void					SetMode(WorldMapMode mode);
	//ƥ�䰴ťģʽ
	inline MatchBtnStatus	GetMatchBtnStatus() { return m_matchBtnStatus; }
	void					SetMatchBtnStatus(MatchBtnStatus btnStatus);
	//���½���״̬
	void					UpdateBigPlaceLockUI();
	void					UpdateSmallPlaceLockUI();
	//��ʾ��ԱICON
	void					ShowTeamIcon();
	//��ʾС�ص��б�(���������б�)
	void					ShowLocaleList(int nWorldMapId);
	//չ�������б�
	void					SpreadGameCopyList(unsigned int nIdx,vector<GameCopy*>& gameCopys);
	//�տs��ǰչ���ĸ����б�
	void					ShrinkGameCopyList();
	//��ʾ����׼��UI
	void					ShowPrepare(GameCopy* gameCopy);
	//��ʾ����������Ϣ
	void					ShowGameCopyInfo(Widget* pUI,GameCopy* gameCopy,bool bNeedCopyIcon);
	//����ƥ��ģʽ����
	void					SetMatchModeTxt();
	//��ʾƥ��UI
	void					ShowMatch();
	//��ʾƥ�䰴ť
	void					UpdateMatchBtn();
	void					ShowBtnCancel();
	void					ShowBtnCancelAndStart();
	void					ShowBtnStarted();
	void					ShowBtnPrepare();
	void					ShowBtnPrepareOver();
	//����������ƥ������
	void					SetInviterMatchData();
	//�������������ƥ������
	void					SetInviterRandomMatchData();

	//����¼�

	//�������
	void clickCloseBtn(Ref* pSender,TouchEventType type);
	//�������
	void clickChatBtn(Ref* pSender,TouchEventType type);
	//����������
	void clickRandomBtn(Ref* pSender,TouchEventType type);
	//���������
	void clickTeamBtn(Ref* pSender,TouchEventType type);
	//�����ص�
	void clickWorldPlace( Ref* pSender,TouchEventType type );
	//���С�ص�
	void clickLocale(Ref* pSender,TouchEventType type);
	//����ӽڵ�
	void clickChildCopyItem(Ref* pSender,TouchEventType type);
	//�����ʼ����
	void clickStartCopy(Ref* pSender,TouchEventType type);
	//�������
	void clickBackFromPrepare(Ref* pSender,TouchEventType type);
	//���ƥ��ģʽ
	void clickMatch(Ref* pSender,TouchEventType type);
	//���ѡ��ƥ��ģʽ
	void clickMatchItem(int nIdx);
	//���ȡ��ƥ��
	void clickCancelMatch(Ref* pSender,TouchEventType type);
	//���������ʼ
	void clickStartImmediately(Ref* pSender,TouchEventType type);
	//���׼��
	void clickPrepare(Ref* pSender,TouchEventType type);
private:
	Widget*					m_pPlaceList;						//��ص�UI
	Widget*					m_pCopyList;						//����UI
	Widget*					m_pPrepare;							//׼��UI
	Widget*					m_pMatch;							//ƥ��UI
	ImageView*				m_pTeamIcon[Team_Max_Num];			//��ԱICON
	ListView*				m_pCopyListView;					//�����б�
	Slider*					m_pSlider;							//������
	Text*					m_pCopyMode;						//����ģʽ�ı�
	Text*					m_pCamp;							//���������ı�
	Text*					m_pMatchMode;						//ƥ��ģʽ�ı�
	Widget*					m_pMenuMatchBg;
	Widget*					m_pParentCopyItem;					//���ڵ㸱��UIģ��
	Widget*					m_pChildCopyItem;					//�ӽڵ㸱��UIģ��
	vector<Widget*>			m_pWorldPlaceLock;
	RichTextEx*				m_pCountTitle;						//����ʱ����
	class Label*			m_pCountNum;						//����ʱ����
	Button*					m_pBtnCountLeft;					//����ʱ��ť
	Button*					m_pBtnCountRight;					//����ʱ�Ұ�ť
	Button*					m_pBtnCountCenter;					//����ʱ�а�ť
	Widget*					m_pMatchingSign;					//����ƥ����
	Text*					m_pMatchWaitTime;					//ƥ��ȴ�ʱ��

	WorldMapMode			m_curMode;							//�����ͼUIģʽ
	MatchMode				m_matchMode;						//ƥ��ģʽ
	MatchStatus				m_matchStatus;						//ƥ��״̬
	MatchBtnStatus			m_matchBtnStatus;					//ƥ�䰴ť״̬
	int						m_nChildIdxInListView;				//չ���ӽڵ���ListView��ʾ��λ��
	int						m_nCurLocaleId;						//��ǰѡ���С�ص�
	GameCopy*				m_curGameCopy;						//��ǰҪ����ĸ���
	int						m_nMatchModeIdx;					//ƥ��ģʽ����
	int						m_nBigPlaceIdx;						//��ǰ��ʾ��ص�
};