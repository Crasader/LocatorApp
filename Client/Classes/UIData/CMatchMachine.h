/****************************************************************************
 ����ƥ��״̬��
 ������
 2015-09-08
 ****************************************************************************/
#pragma once
#include "GameDef.h"
#include "GameScene/Hero.h"

typedef enum _matchMode
{
	MatchMode_None,
	MatchMode_Single,
	MatchMode_Invite,
	MatchMode_Match,
	MachMode_End,
	MatchMode_Count,
}MatchMode;

//MatchMode<<2 | TeamStatus
typedef enum _matchStatus
{
	MatchStatus_None = -1,
	MatchStatus_NoTeam_Single = 4,					//δ���,����ģʽ
	MatchStatus_NoTeam_Invite = 8,					//δ���,����ģʽ
	MatchStatus_NoTeam_Match = 12,					//δ���,ƥ��ģʽ
	MatchStatus_TeamNoFull_Single = 5,				//���δ��,����ģʽ
	MatchStatus_TeamNoFull_Invite = 9,				//���δ��,����ģʽ
	MatchStatus_TeamNoFull_Match = 13,				//���δ��,ƥ��ģʽ
	MatchStatus_TeamFull_Single = 6,				//�����,����ģʽ
	MatchStatus_TeamFull_Invite = 10,				//�����,����ģʽ
	MatchStatus_TeamFull_Match = 14,				//�����,ƥ��ģʽ
	MatchStatus_Count,									//������
}MatchStatus;

class CMatchMachine
{
public:
	CMatchMachine();
	~CMatchMachine();

	void					Init();
	void					Clear();

	void					Update(float dt);

	//ƥ���Ƿ�����
	inline bool				IsMatchStarted() { return m_bMatchStarted; }
	inline void				SetMatchStarted(bool bStarted) { m_bMatchStarted=bStarted; }
	inline void				MatchStart() { SetMatchStarted(true); }
	void					MatchEnd();
	//ƥ�䷢����ID
	inline int64			GetMatchInvitedPlayerId() { return m_nMatchInvitedPlayerId; }
	inline void				SetMatchInvitedPlayerId(int64 nPlayerId) { m_nMatchInvitedPlayerId = nPlayerId; }
	inline bool				AmIInviter() { return m_nMatchInvitedPlayerId == gHero->GetId(); }
	//ƥ�䵹��ʱ
	inline float			GetMatchCountSeconds()	{ return m_fMatchCountSeconds; }
	inline void				SetMatchCountSeconds(float nSeconds) { m_fMatchCountSeconds = nSeconds; m_fMatchCountSecondSum = nSeconds; time(&m_nMatchStartTimeStamp); }
	//ƥ��׼������ĵ�ͼID
	inline int				GetMatchCopyMapIdToEnter()	{ return m_nMatchCopyMapIdToEnter; }
	inline void				SetMatchCopyMapIdToEnter(int nMapId) { m_nMatchCopyMapIdToEnter = nMapId; }
	//ƥ��ģʽ
	inline MatchMode		GetMatchMode() { return m_nMatchMode; }
	inline void				SetMatchMode(MatchMode matchMode) { m_nMatchMode = matchMode; }
	//ƥ���Ƿ�׼����
	inline bool				GetMatchPrepared() { return m_bMatchPrepared; }
	inline void				SetMatchPrepared(bool bMatchPrepared) { m_bMatchPrepared = bMatchPrepared; }
	//ƥ��״̬
	inline MatchStatus		GetMatchStatus() { return m_matchStatus; }
	inline void				SetMatchStatus(MatchStatus matchStatus) { m_matchStatus = matchStatus; }
	void					UpdateMatchStatus();
	//ƥ��ȴ�ʱ��
	inline float			GetMatchWaitTime() { return m_fMatchWaitTime; }
	void					SetMatchWaitTime(float fWaitTime) { m_fMatchWaitTime = fWaitTime; }


private:
	bool					m_bMatchStarted;					  //ƥ���Ƿ�������
	int64					m_nMatchInvitedPlayerId;			  //ƥ�䷢����ID
	float					m_fMatchCountSeconds;				  //ƥ�䵹��ʱ��
	int						m_nMatchCopyMapIdToEnter;			  //ƥ��׼������ĵ�ͼID
	MatchMode				m_nMatchMode;						  //ƥ��ģʽ,ƥ��ģʽ�ֶ�����������ģʽ�Զ�����
	bool					m_bMatchPrepared;					  //ƥ���Ƿ�׼����
	MatchStatus				m_matchStatus;						  //ƥ��״̬
	float					m_fMatchWaitTime;					  //ƥ��ȴ�ʱ��
	time_t					m_nMatchStartTimeStamp;				  //ƥ������ʱ���
	float					m_fMatchCountSecondSum;				  //����ʱ��ʱ��
};
