#ifndef __MessageCenter_h_
#define __MessageCenter_h_
/************************************************************************/
/* ��Ϣ����   ϵͳ��Ϣ��ʾ����                                          */
/************************************************************************/

#include "GameDef.h"
#include "Singleton.h"

enum SystemMessageType
{
	SystemMessage_Msg,			// ϵͳ��Ϣ ���������ʾ����ʾ
	SystemMessage_Notice1,		// ���� �Ϸ���������ʾ
	SystemMessage_Notice2,		// ���� ����һ�ֱ���
	SystemMessage_Prompt,		// ϵͳ��ʾ����Ļ�м���ʾ
	SystemMessage_Normal,		// ���½���ʾ����þ��飬��ý�ң�һ�����ʧ
	SystemMessage_CompMN,		// �����ʾ��SystemMessage_Msg + SystemMessage_Notice1��
	SystemMessage_CompMP,		// �����ʾ��SystemMessage_Msg + SystemMessage_Prompt��
	SystemMessage_Alert,		// ������ʾ����ʾ
	SystemMessage_Mail,			// �ʼ���ʾ
	SystemMessage_Team,			// �����ʾ
	SystemMessage_Trade,		// ������ʾ
	SystemMessage_Chat,			// ����������ʾ
	SystemMessage_Max,
};

#define Max_Message_Len		500

class SystemMessageCache
{
public:
	SystemMessageCache(int len = 100) : m_nLength(len) {}
	~SystemMessageCache(){}

	inline void push(const string& val){
		m_Msgs.push_back(val);
		while ( (int)m_Msgs.size() > m_nLength )
		{
			pop();
		}
	}

	inline string pop(){
		string ret = m_Msgs.front();
		m_Msgs.erase(m_Msgs.begin());
		return ret;
	}

	inline void clear(){
		m_Msgs.clear();
	}

	inline void remove(const string& str)
	{
		list<string>::iterator it = find(m_Msgs.begin(), m_Msgs.end(), str);
		if (it != m_Msgs.end())
		{
			m_Msgs.erase(it);
		}
	}

	inline bool has(const string& str){
		return (find(m_Msgs.begin(), m_Msgs.end(), str) != m_Msgs.end());
	}

	inline int length(){
		return (int)m_Msgs.size();
	}

	inline void length(int len){
		m_nLength = len;
	}

private:
	list<string>	m_Msgs;
	int				m_nLength;
};

class MessageCenter : public Singleton_Auto<MessageCenter>
{
public:
	MessageCenter();
	~MessageCenter();

	inline SystemMessageCache& GetMessageCache(SystemMessageType type){ return m_Cache[type]; }

public:
	void SystemMessage(SystemMessageType type,const char* format, ... );
	void SystemMessage(SystemMessageType type,const string& msg);
	void SystemMessage(int nCode, ...);
	void SystemMessage(int nCode, vector<string>& vtrArgs);

	bool HasMessage(SystemMessageType type, const string& msg);
	void RemoveMessage(SystemMessageType type, const string& msg);
protected:
	SystemMessageCache m_Cache[SystemMessage_Max];
};

SystemMessageType FormatMsgByArgFromVector(int nCode, vector<string>& vtrArgs, string &strMsg);

#define gMessageCenter				MessageCenter::Instance()
#define MessagePrompt(Msg, ...)		gMessageCenter->SystemMessage(SystemMessage_Prompt,Msg,##__VA_ARGS__)
#define MessageNormal(Msg, ...)		gMessageCenter->SystemMessage(SystemMessage_Normal,Msg,##__VA_ARGS__)
#define MessageSystem(Msg, ...)		gMessageCenter->SystemMessage(SystemMessage_Msg,Msg,##__VA_ARGS__)
#define MessageNotice1(Msg, ...)	gMessageCenter->SystemMessage(SystemMessage_Notice1,Msg,##__VA_ARGS__)
#define MessageNotice2(Msg, ...)	gMessageCenter->SystemMessage(SystemMessage_Notice2,Msg,##__VA_ARGS__)
#define MessageAlert(Msg, ...)		gMessageCenter->SystemMessage(SystemMessage_Alert,Msg,##__VA_ARGS__)
#define MessageMail(Msg, ...)		gMessageCenter->SystemMessage(SystemMessage_Mail,Msg,##__VA_ARGS__)
#define MessageTeam(Msg, ...)		gMessageCenter->SystemMessage(SystemMessage_Team,Msg,##__VA_ARGS__)
#define MessageChat(Msg, ...)		gMessageCenter->SystemMessage(SystemMessage_Chat,Msg,##__VA_ARGS__)
#define MessageTrade(Msg, ...)		gMessageCenter->SystemMessage(SystemMessage_Trade,Msg,##__VA_ARGS__)

#endif		// __MessageCenter_h_