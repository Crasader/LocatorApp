//%%������
//-define(Create_Guild_Err_Of_Name_Is_Too_Long, -1). %%����̫��
//-define(Create_Guild_Err_Of_Announcement_Is_Too_Long, -2). %%����̫��
//-define(Create_Guild_Err_Of_Name_Is_Exit, -3). %%��������Ѿ�����
//-define(Create_Guild_Err_Of_Guild_Is_Exit, -4). %%�����Ѿ�����
//-define(Create_Guild_Err_Of_Money_Is_Not_Enough, -5). %%��Ǯ����
//-define(Create_Guild_Err_Of_Player_Level, -6). %%��ҵȼ�����
//-define(Create_Guild_Err_Of_Name_Or_Announcement_Is_Null, -7). %%���ֻ�������Ϊ��
//-define(Create_Guild_Err_Of_Item_Is_Not_Enough, -8). %%���߲���
//-define(Create_Guild_Err_Of_Max_Guild_Cnt, -9). %%��������Ѿ��ﵽ���ֵ
//-define(Create_Guild_Succ, 1). %%�����ɹ�

//-define(KillOut_Member_Err_Of_Kill_Identity, -1). %%���ǻ᳤���߲��Ǹ��᳤
//-define(KillOut_Member_Err_Of_Member_Is_DeputyLeaer_Or_Leader, -2). %%���᳤�����߳��᳤���߸��᳤
//-define(KillOut_Member_Err_Of_Member_Is_Leaer, -3). %%�᳤�����߳��᳤
//-define(KillOut_Member_Err_Of_Guild, -4). %%����ͬһ������
//-define(KillOut_Member_Succ, 1).
struct guildList 
{
	int64 guildId;
	string guildName; //��������
	int16 guildLevel;  //����ȼ�
	string guildLeaderName; //�᳤
	int32 curMementCnt; //��ǰ��������
	int32 maxMementCnt; //��󹫻�����
	int32 guildProsperity; //���ᷱ�ٶ�
	string guildDeclaration; //��������
};

//�鿴�����б���Ϣ
struct C2GS_LookOverGuildInfo ->
{
	int64 playerId;
};

//�����б�
struct GS2C_GuildList <-
{
	vector<guildList> vec;
};

struct memberList
{
	int64 playerId;
	string memberName; //��Ա����
	int8 position; //ְλ
	int32 level; //�ȼ�
	int32 contribution; //���׶�
	int8 isVip;
	int8 career;
	int8 isOnline;
};

struct guildSkill
{
	int32 skillType;
	int32 skillLevel;
};

//����Ա�б�
struct GS2C_MemberList <-
{
	int64 guildId;
	string guildAnnouncement; //����
	vector<guildSkill> skillVec;
	vector<memberList> vec;
};

struct applyList
{
	int64 playerId;
	string name;
	int32 level;
	int8 career;
	int8 isVip;
};

struct GS2C_ApplyList <-
{
	vector<applyList> vec;
};

//���󴴽����
struct C2GS_CreateGuild ->
{
	string guildName; //�������
	string guildDeclaration; //�������
};

struct GS2C_CreateGuild_Result <-
{
	int8 retCode; //-1:����̫��, -2:����̫��, -3:��������Ѿ�����, -4:�����Ѿ�����, -5:��Ǯ����, -6:��ҵȼ�����, -7:���ֻ�������Ϊ��, -8:���߲���, -9:��������Ѿ��ﵽ���ֵ, -10:������ 1:�ɹ�
	guildList st;
}

struct GS2C_CreateGuild <-
{
	guildList st;
};

//���������
struct C2GS_RequestJoinGuild ->
{
	int64 guildId;
};

struct GS2C_RequestJoinGuild <-
{
	applyList st;
};

//ͬ����߾ܾ�
struct C2GS_ApproveRequestJoinGuild ->
{
	int8 respon; //0:�ܾ�, 1:����
	int64 requestPlayerId; //0����ȫ��
	int64 guildId;
};

struct GS2C_JoinGuild_Result <-
{
	memberList st;
};

//�������
struct C2GS_UpgradeGuild ->
{
	int64 guildId; //���id
};

struct GS2C_UpgradeGuild_Result <-
{
	//-1: ���ǻ᳤�������� -2: ����Ѿ�����ߵȼ� -3:��ᷱ�ٶȲ��� 1:�ɹ�֮·
	int8 retCode;
	int16 newLevel;
};

//�㲥��Ϣ
struct GS2C_UpgradeGuild <-
{
	int16 level;
	int32 maxMementCnt;
	int32 guildProsperity;
};

//�˳����
struct C2GS_ExitGuild ->
{
	int64 guildId;
};

struct GS2C_ExitGuild_Result <-
{
	int64 memberId;
};

//�߳���Ա
struct C2GS_KillOutPlayer ->
{
	int64 memberId;
};

struct GS2C_KillOutPlayer_Result <-
{
	int64 memberId;
};

//ת�û᳤
struct C2GS_TransferLeader ->
{
	int64 memberId;
};

struct GS2C_TransferLeader_Result <-
{
	int64 newLeader;
};

//���ø��᳤
struct C2GS_SetDeputyLeader ->
{
	int64 memberId;
};

struct GS2C_SetDeputyLeader_Result <-
{
	int64 memberId;
};

//�Ƴ����᳤
struct C2GS_RemoveDeputyLeader ->
{
	int64 memberId;
};

struct GS2C_RemoveDeputyLeader_Result <-
{
	int64 memberId;
};

//���¹���
struct C2GS_UpdateAnnouncement ->
{
	string announcemnet;
};

struct GS2C_UpdateAnnouncement_Result <-
{
	string announcemnet;
};

//����
struct C2GS_GuildDonation ->
{
	int32 money;
};

struct GS2C_GuildDonation_Result <-
{
	int32 contribution; //���׶�
	int32 guildProsperity; //���ᷱ�ٶ�
	int64 memberId; //������
};

struct GS2C_UpdateGuildProsperity <-
{
	int32 contribution; //���׶�
	int64 memberId;
};

struct GS2C_UpgradeSkill <-
{
	int32 guildProsperity; //���ᷱ�ٶ�
	int32 skillType;
	int32 skillLevel;
};

struct C2GS_DissolveGuild ->
{
	int64 guildId;
};

struct GS2C_DissolveGuild_Result <-
{
	int8 retCode; //1:�ɹ�, 0:ʧ��
};

struct C2GS_StudyGuildSkill ->
{
	int32 skillId;
};

struct C2GS_UpgradeGuildSkill ->
{
	int32 skillId;
};

struct C2GS_RequestGuildWar ->
{
	int64 guildId;
};

struct GS2C_GuildWar <-
{
	int8 retCode; //1:��ʼ, 0:����
	int8 isAttack; //1:������, 0:��������
	int64 guildId;
};