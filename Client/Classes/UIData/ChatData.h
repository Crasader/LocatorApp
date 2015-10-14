/****************************************************************************
 �������ݹ�����
 ������
 2015-10-08
 ****************************************************************************/
#pragma once
#include "GameDef.h"
#include "Net/pk_item.h"


#define MAX_MSG_CACHE_SIZE 100

//����Ƶ��,�ͷ�����Ƶ��ID����һ��
typedef enum _channelType
{
	ChannelType_World = 1,	//����
	ChannelType_Guild,		//����
	ChannelType_Team,		//����
	ChannelType_Map,		//ͬһ�ŵ�ͼ
	ChannelType_System,		//ϵͳ
	ChannelType_Horn,		//����
	ChannelType_Personal,	//˽��
	ChannelType_Team_Msg,	//���
	ChannelType_Count,
}ChannelType;

//������Ϣ
typedef struct _msgItem
{
	pk::GS2C_Chat content;	//������Ϣ
	bool bIsMine;			//������Լ����͵ģ�
}MsgItem;

//����Ƶ��
typedef struct _channel
{
	_channel()	{bUnread = false;}

	vector<MsgItem> msg;		//Ƶ��������Ϣ
	bool bUnread;
	string playerName;
	int64	channelId;			//�ͻ���Ƶ��ID
}Channel;

class CChatDataMgr
{

public:
	CChatDataMgr();
	~CChatDataMgr();

	//����������Ϣ ˽��ʹ�����ID����Ϊchannel id
	MsgItem* AddMsg(int64 nChannelId, pk::GS2C_Chat chatContent,bool bIsMyWords = false);

	//����˽��Ƶ��
	void AddChannel(int64 nChannelId, string playerName);

	//��ȡƵ��
	Channel* GetChannel(int64 nChannelId);

	//ɾ��Ƶ��
	void RemoveChannel(int64 nChannelId);

	//����Ƶ��δ����־
	void SetChannelReaded(int64 nChannelId, bool bReaded);

	int GetUnreadChannelNum();

	queue<MsgItem>*	GetMsgOfMainUI() { return &m_msgOfMainUI; }

private:
	//����Ƶ�� <�ͻ���Ƶ��ID��Ƶ��>
	map<int64, Channel> channels;
	//��ʾ���������ϵ���Ϣ
	queue<MsgItem> m_msgOfMainUI;
};