/* ������ʾģ��
   Data: 2015/7/20
   Author��Tangbo
*/

#pragma once
#include "cocos2d.h"
#include "GameUI.h"
#include "GameScene/GameUILayer.h"
#include "LoadingUI.h"

#define  UPDATETIME    0.1f
#define  DELAYTIME     5.f
#define  MAX_STRING		30
#define  MAX_WORDS_0	200
#define  MAX_WORDS_1	100

class DramaUI:public GameUI
{
public:

	static void		PlayDrama(int nDramaId)
	{
		if(!nDramaId) return;
		DramaUI* pDramaUI = (DramaUI*)gGameUILayer->getUI(IDU_Drama);
		if(!pDramaUI) return;
		pDramaUI->SetStartId(nDramaId);
		if (gLoadingUI->IsActive())
		{
			gLoadingUI->addLoadEndEvent(pDramaUI,LoadingUI::LoadEnd_Event(&DramaUI::showDrama));
		}
		else
		{
			pDramaUI->showDrama();
		}
	}

public:
	bool onInit();
	void onOpen();
	void onShow();
	void onClose();
	void onDestroy();

	//��ʼ�����ɴ�͸ģʽ
	void  initModel();

	//��ʼ���ɴ�͸ģʽ
	void  initUnmodel();

	inline int				GetStartId() { return m_dataID; }
	inline void				SetStartId(int startId) { m_dataID = startId; }

	/* Name  : showDramaByParam
	   Des   : ͨ��ָ��������ʾ����Ի�
	   Parma : _startid ����������ʼid, _npcid Ҫ�Ի���npcid
	   ret   : none
	*/
	void   showDramaByParam(int _startid, int _npcid);
	void   showDrama();

	/* Name  : touchevent
	   Des   : ���õ�ǰ��Ĵ�����Ӧ�¼�
	   Parma : 
	   ret   : 
	*/
	void    touchevent(Ref *pSender, TouchEventType _type);

	/* Name  : touchevent
	   Des   : ���õ�ǰ��Ĵ�����Ӧ�¼�
	   Parma : 
	   ret   : 
	*/
	void    passevent(Ref *pSender, TouchEventType _type);

	/* Name  : getCurShowContext()
	   Des   : ��ȡ��ǰ����ʾ����,����ͷ����ʾ,�ı���ʾ
	   Param : none
	   ret   : ���ص�ǰ�Ի�������
	*/
	string  getCurShowContext();

	/* Name  : getSubShowString()
	   Des   : ��ȡ��ǰ֡����ʾ������
	   Param : _index ��ǰ����ʾ��λ��
	   ret   : ������������
	*/
	string  getSubShowString(int _index);

	/* Name  : showByInstant
	   Des   : ˲����ʾ�Ի�
	   Param : 
	   ret   :
	*/
	void    showByInstant();

	/* Name  : showByInterval
	   Des   : ����ʾ�Ի�
	   Param : 
	   ret   :
	*/
	void    showByInterval();



	/* Name  : showCenterTips()
	   Des   : ��ʾ������ʾ�ַ�
	   Param : 
	   ret   :
	*/
	void    showCenterTips();


	/* Name  : subDataByMainType
	 * Des   : ��Drama�������з����,��ǰmain������
	 * Param : main  
	 * ret   : ���ؾ���Ի�����
	 */
	vector<DramaCfg*> subDataByMainType(int main);

	/* Name  : subStringToVector(string _str)
	   Des   : ��Ҫ��ʾ���ַ����ֽ�ȡ����ʾ����
	   Param : _str ��ǰ�Ի�Ҫ��ʾ���ַ�
	   ret   :
	*/
	void    subStringToVector();

	/* Name  : nextTalk
	   Des   : ��ʾ��һ��
	   Parma : none
	   Ret   : none
	 */
	void    nextTalk(int _delay = DELAYTIME);


	/* Name  : update(float fd)
	   Des   : ��������ʾ������
	   Param : fd ��ʾ�ļ��ʱ��
	   ret   :
	*/
	void    updateShow(float fd);

	DramaUI();
	~DramaUI();

     //��ǰ��ʾģʽ falseȫ����ʾ(Ĭ����ʾ)  true С����ʾ�ɴ�͸
	CC_SYNTHESIZE_READONLY(bool, m_curShowMode, curShowMode);

private:
	struct TalkLine_st
	{
		TalkLine_st(){
			direct = 0;
			roleid = 0;
			person = 0;
			talkstr.clear();
		}

		int  direct;        //��ʾ����
		int  roleid;        //����Ի��Ľ�ɫid 0��ǰ���(Ĭ��) 
		int  person;        //��ɫ����  0 npc 1���
		vector<std::string> talkstr;//��ǰ˵��������
	};
	typedef vector<TalkLine_st*>  VecStr;

	Text*                    m_pNpcName;          //npc����

	Text*                    m_pHeroName;         //hero����

	cocos2d::ui::Text      * m_pShowTextNpc;         //npc�Ի���ǩ

	cocos2d::ui::Text      * m_pShowTextHero;         //hero�Ի���ǩ

	cocos2d::ui::ImageView * m_npcIcon;           //npcͼ��

	cocos2d::ui::ImageView * m_heroIcon;          //Ӣ��ͼ��

	string                   m_showStr;           //˵������


	int                      m_stcLen;            //������

	int                      m_dataID;            //��ʾ����id

	int                      m_touchCnt;          //��������

	int                      m_curIndex;          //����ʾ�±�

	int                      m_subIndex;          //�����±�
	
	VecStr                   m_dump[MAX_STRING];          //���30��

	bool                     m_isSkip;            //�Ƿ�����
};



