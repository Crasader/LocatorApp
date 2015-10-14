#pragma once

#include "GameDef.h"
#include "GameUI.h"
#include "../GameScene/GameUILayer.h"
#include "UIPageView.h"
#include "UI/ResMgr/CtrlAllocator.h"
#include "Net/pk_friend.h"
#include "Net/pk_item.h"
#include "ui/UIRichText.h"

struct ItemLinkData
{
	emGridsType ePackType;
	int64		nItemID;
	string		strName;
	int			nStrOffset;

	ItemLinkData(emGridsType type, int64 id, string str, int offset): ePackType(type), nItemID(id), strName(str), nStrOffset(offset){};
	bool operator == (const ItemLinkData& other)
	{
		return nItemID == other.nItemID && nStrOffset == other.nStrOffset;
	}
};

struct MsgRecord
{
	string					strMsg;		//�ͻ����������Ϣ
	string					strMsgServer;	//���͸���������Ϣ
	vector<ItemLinkData>	vtrLinks;		//��Ʒ����

	MsgRecord(string str, string msgServer, vector<ItemLinkData> vtr): strMsg(str), strMsgServer(msgServer), vtrLinks(vtr){}
	bool operator == (const MsgRecord &other)
	{
		if (vtrLinks.size() != other.vtrLinks.size())
			return false;

		for (size_t i = 0; i < vtrLinks.size(); i++)
		{
			if(!(vtrLinks[i] == other.vtrLinks[i]))
			{
				return false;
			}
		}

		return (strMsg == other.strMsg && strMsgServer == other.strMsgServer);
	}
};

class ChatMainUI : public GameUI
{
public:
	ChatMainUI();
	~ChatMainUI();

	bool			onInit();
	virtual void	onOpen();
	void			onClose();
	void			clickTab(int index);
	//void			clickMenu(int index);
	void			clickExit(Ref*, TouchEventType);
	void			clickSendMsg(Ref*, TouchEventType);
	void			clickLatestMsg(Ref*, TouchEventType);
	void			clickVoice(Ref*, TouchEventType);
	void			clickLatestMenu(int, long long data);
	void			clickChanelMenu(int);
	void			clickNameLink(Ref*, int64);
	void			clickItemLink(Ref*, int64);
	void			clickNameLink4MainUI(Ref*, int64);
	void			clickItemLink4MainUI(Ref*, int64);
	void			clickNameLinkOfChanel(int nChanel, Ref*, int64);
	void			clickItemLinkOfChanel(int nChanel, Ref*, int64);
	void			InputItemLink(emGridsType type, class CItem *pItem);
	//ˢ�µ�ǰƵ����Ϣ
	void			UpdateCurChanel();
	//�Ƿ�Ϊ��ǰƵ����Ϣ
	bool			IsCurChannelMsg(pk::GS2C_Chat *value);
	//����̶�Ƶ������Ϣ
	void			MsgArrive(MsgItem* pMsgItem);
	//����һ���̶�Ƶ��
	void			AddFixChannel(ChannelType type);
	//�ر�һ���̶�Ƶ��
	void			CloseFixChanel(ChannelType type);
	//��ʾ�̶�Ƶ��
	void			ShowFixedChannel(ChannelType type);
	//˽��Ƶ������Ϣ
	void			PrivateMsgArrive(MsgItem* pMsgItem);
	//����һ��˽��Ƶ��
	void			AddPrivateChannel(int64 channelId,string playerName);
	//�ر�һ��˽��Ƶ��
	void			closePrivateChannel(Ref*, TouchEventType);
	//�Ƿ��������ʾƵ��
	bool			IsShowingChExist(int64 channelId);
	//����Ƶ��id��ȡ�˵�����
	int				GetIndexByChannelId(int64 channelId);
	//��ʾ˽��Ƶ��
	void			ShowPrivateChannel(int64 channelId,string playerName);
	//��δ����ϢƵ��������˸��ʾ
	void			TipsChannelUnread(Channel* pChannel);
	//����Ƶ���رհ�ť״̬
	void			updateChannelClose(int menuIndex);
	//����δ������Ϣ�ı�־״̬
	void			showNewMsgSign();
	//����
	void			showExpression(Ref*, TouchEventType);
	void			clickExpressionItem(Ref*,TouchEventType);
	void			closeExpression(Ref*,TouchEventType);
	//�����
	void			UpdateDisplayedText(bool bHasCursor);
	void			InputText(Ref*, TextFiledEventType);
	void			UpdateInputState();

private:
	Text*					m_pCursor;
	Text*					m_pTxtMaterialNewCnt;
	Widget*					m_pGridMoved;
	TextField*				m_pInput;
	RichText *				m_pDisplayedInput;		// ��ʾʵ����������֣�Ϊ����ʾ����ɫ�ĵ������ӣ����ô�׾��
	class ScrollEditBox*	m_pScrollEditBox;
	Button *				m_pLatest;
	class CScrollMsgWindow*	m_pMsgWind;				//Ƶ����Ϣ
	class CScrollTable*		m_pLastMsgs;			//���¼�¼��Ϣ
	Widget *				m_pListBG;
	CScrollMenu*			m_pChanelMenu;
	Button *				m_pVoice;
	Widget*					m_pExpressionUI;		//�������
	Widget*					m_pChannelClose;		//Ƶ���رհ�ť
	Widget*					m_pNewMsgSign;			//����Ϣ��־

	vector<pk::GS2C_Chat>	m_Msgs[8];
	vector<MsgRecord>		m_Latest;
	vector<ItemLinkData>	m_vtrItemsToSent;		// ������е�������ӳ��ĵ��ߣ�int����������������е���ʼƫ��
	int						m_nCurGroup;
	int64					m_nCurClickPlayerID;
	ChannelType				m_nCurSeverChId;		//��ǰ�����ĵķ�����Ƶ��ID
	int64					m_nCurClientChId;		//��ǰ�����ĵĿͻ���Ƶ��ID
	int						m_nChannelMenuIndex;	//��ǰ����˵�����
	vector<int64>			m_showingChannels;		//����ʾ��Ƶ�� ,<Ƶ��ID>
	string					m_sChatingPlayerName;	
};

//��ʾ��������,�ı�,��Ʒ����,����
void		MakeChatContent(RichText *pTextIn, MsgRecord* pMyRecord);


class ScrollEditBox : public Layout
{
public:
	ScrollEditBox(){}
	~ScrollEditBox(){}

	CREATE_FUNC(ScrollEditBox);

	static ScrollEditBox* create(Widget* pEdit)
	{
		ScrollEditBox *pSEB = ScrollEditBox::create();
		if ( pSEB )
		{
			pSEB->pEditBox = pEdit;
			pSEB->addChild(pEdit);
			pSEB->setClippingEnabled(true);
			pSEB->scheduleUpdate();
			return pSEB;
		}
		
		return NULL;
	}
	void update(float dt)
	{
		Size szEdit = pEditBox->getSize();
		pEditBox->setPosition(Point(MIN(szEdit.width / 2, _size.width - szEdit.width / 2),  _size.height / 2));
		pEditBox->getSize().width;
	}

private:
	Widget*		pEditBox;
};

