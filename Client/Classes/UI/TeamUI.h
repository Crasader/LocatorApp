/****************************************************************************
 �罻UI
 ������
 2015-07-29
 ****************************************************************************/
#pragma once
#include "GameDef.h"
#include "GameUI.h"
#include "Net/pk_team.h"
#include "CustomCtrl/MenuForPlayer.h"
#include "GameScene/Hero.h"
#include "MainUI.h"

typedef enum _teamStatus
{
	TeamStatus_None = -1,
	TeamStatus_NoTeam = 0,
	TeamStatus_TeamNoFull,
	TeamStatus_TeamFull,
	TeamStatus_Count,
}TeamStatus;

typedef struct _teamMember
{
	int64 id;
	string name;
	int16 level;
	int8 career;
	int8 sex;
	int32 hp;
	int32 maxhp;
	int8 online;
	int8 isContinue;	//1����������,0:��������,-1��δѡ��
}TeamMember;

typedef struct _teamInfo
{
	int64 teamId;
	int64 leadId;
	int8 isPermitNum;	//�Ƿ������Ա����
	vector<TeamMember> member_list;
}TeamInfo;

class CTeamUI : public GameUI
{
public:
	CTeamUI();
	~CTeamUI();

	bool			onInit();
	void			onOpen();

public:
	void			clickExit(Ref*, TouchEventType);
	void			clickAllow(Ref*, CheckBoxEventType);
	void			clickAllowAdd(Ref*, TouchEventType);
	void			clickItem(int nIndex, long long);
	void			clickTab(int index);
	void			updateList(int index);
	void			updateTeamList();
	void			updateFriendList();
	void			updateRegionList();
	void			updateRecentList();
	//ˢ�¶�Ա�����������Ϣ
	void			updateTeamAllowInfo();
	//ˢ�¶������������״̬
	void			updateTeamOnlineState();
	//ˢ��ѡ��״̬
	void			updateSelState(int nIndex);
	//����Ű�
	void			TeamLayout();
	//�����Ű�
	void			OtherLayout();

private:
	class RadioButtonSet *	m_pTabs;
	class CScrollTable*		m_pList;	//�����б�,�����б�,�����б�,�������б�
	Widget*					m_teampanel;
	CheckBox*				m_allowMemMsg;
	Widget*					m_Operate;
	CMenuForPerson*			m_menuForPerson;
	Widget*					m_pSelSign;
	Widget*					m_pMainBg;

	int						m_nCurGroup;
	int64					m_playerId;

public:
	//��ȡ��Ա��Ϣ
	static TeamMember* GetTeamMember(int64 id)
	{
		for (size_t i = 0; i < s_teamInfo.member_list.size(); i++)
		{
			if (s_teamInfo.member_list[i].id == id)
			{
				return &s_teamInfo.member_list[i];
			}
		}
		return NULL;
	}
	//��ȡ��Ա��Ϣ
	static TeamMember* GetTeamMember(string name)
	{
		for (size_t i = 0; i < s_teamInfo.member_list.size(); i++)
		{
			if (s_teamInfo.member_list[i].name == name)
			{
				return &s_teamInfo.member_list[i];
			}
		}
		return NULL;
	}
	//�Ƿ��Ƕӳ�
	static bool				IsLeader()
	{
		return (s_teamInfo.leadId == gHero->GetId());
	}
	//��Ա�Ƿ�����
	static bool				IsOnline(int64 id)
	{
		for (unsigned int i=0; i<s_teamInfo.member_list.size(); ++i)
		{
			if (id == s_teamInfo.member_list[i].id)
			{
				return s_teamInfo.member_list[i].online == 0;
			}
		}
		return true;
	}
	//��ö�����������
	static int				CountTeamOnline()
	{
		int nCount = 0;
		for (unsigned int i=0; i<s_teamInfo.member_list.size(); ++i)
		{
			if(!s_teamInfo.member_list[i].online)
			{
				nCount++;
			}
		}
		return nCount;
	}
	//��ȡ���״̬
	static TeamStatus		GetTeamStatus()
	{
		switch (CountTeamOnline())
		{
		case 1:
		case 0:
			return TeamStatus_NoTeam;
		case Team_Max_Num:
			return TeamStatus_TeamFull;
		default:
			return TeamStatus_TeamNoFull;
		}
	}

	static TeamInfo s_teamInfo;	//������Ϣ
	static pk::GS2C_GetOldTeamer_Ret s_TeamRecent;	//������
};

