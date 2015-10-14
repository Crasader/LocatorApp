#include "ChatData.h"

CChatDataMgr::CChatDataMgr()
{

}

CChatDataMgr::~CChatDataMgr()
{
	channels.clear();
}

//����������Ϣ ˽��ʹ�����ID����Ϊchannel id
MsgItem* CChatDataMgr::AddMsg(int64 nChannelId, pk::GS2C_Chat chatContent,bool bIsMyWords)
{
	MsgItem* pMsgItem = nullptr;
	map<int64, Channel>::iterator it = channels.find(nChannelId);
	MsgItem mobj = {chatContent,bIsMyWords};
	if (it != channels.end())
	{
		it->second.msg.push_back(mobj);
		pMsgItem = &it->second.msg.back();
		it->second.bUnread = true;
		if (MAX_MSG_CACHE_SIZE < it->second.msg.size())
		{
			it->second.msg.erase(it->second.msg.begin());
		}
	}
	else
	{
		Channel obj;
		obj.msg.push_back(mobj);
		obj.playerName = chatContent.senderName;
		obj.channelId = (chatContent.channelId == ChannelType_Personal ? chatContent.senderId : chatContent.channelId);
		obj.bUnread = true;
		channels.insert(make_pair(nChannelId, obj));
		pMsgItem = &channels.rbegin()->second.msg.back();
	}
	//��������ʾ�����˽��
	if ( nChannelId>=ChannelType_Count || nChannelId==ChannelType_Team )
	{
		m_msgOfMainUI.push(mobj);
	}
	return pMsgItem;
}

//����˽��Ƶ��
void CChatDataMgr::AddChannel(int64 nChannelId, string playerName)
{
	map<int64, Channel>::iterator it = channels.find(nChannelId);
	if (it == channels.end())
	{
		Channel obj;
		obj.playerName = playerName;
		obj.channelId = nChannelId;
		channels.insert(make_pair(nChannelId, obj));
	}
}

//��ȡƵ��
Channel* CChatDataMgr::GetChannel(int64 nChannelId)
{
	map<int64, Channel>::iterator it = channels.find(nChannelId);
	if (it != channels.end())
	{
		return &it->second;
	}

	return NULL;
}

//ɾ��Ƶ��
void CChatDataMgr::RemoveChannel(int64 nChannelId)
{
	map<int64, Channel>::iterator it = channels.find(nChannelId);
	if (it != channels.end())
	{
		channels.erase(it);
	}
}

//����Ƶ��δ����־
void CChatDataMgr::SetChannelReaded(int64 nChannelId, bool bReaded)
{
	Channel *pChanel = GetChannel(nChannelId);
	if (pChanel)
		pChanel->bUnread = !bReaded;
}

int CChatDataMgr::GetUnreadChannelNum()
{
	int nNum = 0;
	map<int64, Channel>::iterator it = channels.begin();
	for (; it != channels.end(); it++)
	{
		//ͳ��˽�ĵ�
		if (it->second.bUnread && it->second.channelId > ChannelType_Count)
			nNum++;
	}
	return nNum;
}