
//��ݼ�
struct ShortcutInfo   
{
	int8 index;
	int8 type;
	int64 id;
};

struct GSWithC_Shortcuts <->
{
	vector<ShortcutInfo> shortcutInfos;
};

//����һ����Ҹ��Ի�������Ϣ��client
struct GS2C_Preference_Set_Info <-
{
	int8 teamSet;//�������
};

struct VariantData
{
	int8 index;
	int32 value;
};
struct GS2C_VariantDataSet <-
{
	int8 variant_type;//�������ͣ�  0:δ��ʼ��;    1:��ұ����� 2���������
	vector<VariantData> info_list;
};




//�����������Ϣ

// �����������Ϣ
struct ArenaPlayerEquipinfo
{
	int32 equipDataId;    //װ��������id
	int8 part;            //װ�����Ĳ�λ or ���µĲ�λ	
	int8 stars;           //װ�����Ǽ�,ǿ�����Ǽ�������
	int8 luck;            //װ��������ֵ
};

struct ArenaPlayerInfo   
{
	int64 	playerId;
	string	name;
	int8	sex;
	int8 	career;
	int32	level;
	int32	fight;	//ս����
	int32	rank;   // �������
	vector<ArenaPlayerEquipinfo>  equipList;
};

struct ArenaMsgInfo   
{
	string 	name;
	int8	flag;
	int32 	rank;
	int32	time;
};

// ���뾺����
struct C2GS_EnterArena_Req  ->
{
};

struct GS2C_EnterArena_Ret <-
{
	int32 	ret;	
};
// ��������Ϣ
struct GS2C_ArenaInfo <-
{
	int32	curRank;  // ��ҵ�ǰ����
	int32	fight;  // ս����
	int32	awardId;  // ���ս���	
	vector<ArenaPlayerInfo>  arenaPlayerList;
	vector<ArenaMsgInfo> arenaMsgList;
};

// ��ʼ��ս
struct C2GS_StartChallenge_Req  ->
{
	int64 	playerId;   // ����ս���Id	
};

struct GS2C_StartChallenge_Ret  <-
{
	int32 	ret;
};

// ��ʼ5�뵹��ʱ
struct C2GS_Start_Count_down_Req  ->
{	
};

// ��ȡ���������ս���
struct C2GS_Arena_Award_Req  ->
{
};

struct GS2C_Arena_Award_Ret  <-
{
	int32 	ret;
};


//��������
struct DefenseMonsterInfo   
{
	int64 id;
	int32 dataId;
	int8 isDead;
};

// defense monster info update
struct GS2C_Update_TowerDefenseMonster  <-
{
	vector<DefenseMonsterInfo> defenseMonsterInfos;
};

// refresh monster
struct GS2C_MonsterRefresh_Time  <-
{
	int8 waveIndex; //�ڼ�����
	int32 delayMs; //�ӳٶ��ٺ������
};


// ������������������ػ�����
struct C2GS_Upgrade_TowerDefenseMonster  ->
{
	int64 id;
	int32 dataId;
};

struct C2GS_RecoverLife_TowerDefenseMonster  ->
{
	int64 id;
	int32 dataId;
};

//������ҵ�award info
struct GS2C_TowerDefense_Update_AwardInfo <-
{
	int32 spiritNum;
	int32 awardExp;
	int32 awardCoin;
};


struct GS2C_TowerDefenseCopy_Result <-
{
	int8 isSuccess; //1:�ɹ� 0��ʧ��
};


struct GS2C_ArenaCopy_Result <-
{
	int8 isSuccess; //1:�ɹ� 0��ʧ��
};

//����
struct Login_Notice 
{
	string	title;
	string	content;
	string	date;
	string	signature;
};

struct GS2C_Login_Notice <-
{
	vector<Login_Notice>	login_Notice_lists;
};


struct C2GS_HeartBeat  ->
{
};

struct Pay_Info 
{
	int8	id;
	int32	gameMoney;
	int32	ucMoney;
	int8	state;
};

struct GS2C_Pay_Info <-
{
	vector<Pay_Info>	pay_Info_lists;
};

struct C2GS_Player_Get_Sign_In_Info ->
{
};

struct GS2C_Player_Sign_In_Info <-
{
	int8  isAlready;   //�Ƿ���ǩ��
};

struct C2GS_Player_Sign_In ->
{
};

struct GS2C_Player_Sign_In_Result <-
{
	int32 days;
	int8 retCode;
};

//��ǩ
struct C2GS_Player_Again_Sign_In ->
{
	int32 days;
};

struct GS2C_Player_Again_Sign_In_Result <-
{
	int32 days;
	int8 retCode;
};

struct C2GS_Player_Get_Award ->
{
	int8 id;
};

struct GS2C_Player_Get_Award_Result <-
{
	int8 retCode;
};

struct C2GS_Sign_In_One_Key_Get_Award ->
{
};

struct C2GS_System_Set_Request ->
{
	int32 type; //����(�����ý���,��ӵȵ�)
	int32 flag;
};

struct GS2C_System_Set_Request_Result <-
{
	int8 retCode;
};

struct C2GS_MakeQuestion ->
{
	int64 playerId;
};

struct GS2C_MakeQuestion <-
{
	vector<int32> questionVec;
};

struct C2GS_Question ->
{
	int32 id;
	int8 type;
	int8 answer;
};

struct GS2C_Question <-
{
	int8 errCnt;
	int8 rightCnt;
	int32 useTime;
	int32 remainTime;
	int8 retCode; //-1,id������, -2,�Ѵ��, -3,�������̫��, -4,���ڻ����, 0:�𰸴���, 1:����ȷ
};

//�������
struct C2GS_ResetQuestErr ->
{
	int32 cnt;
};

struct GS2C_ResetQuestErr <-
{
	int16 newErrCnt;
	int8 retCode; //1:�ɹ���0:ʧ��,Ԫ������
};

struct GS2C_Question_OnLine <-
{
	int8 errCnt;
	int8 rightCnt;
	int32 useTime;
	int32 remainTime;
	int32 lastScore;
	int32 weekScore;
	vector<int32> questionVec;
	vector<int32> finishQuestionVec;
};

struct C2GS_FinishQuestion ->
{
	int64 playerId;
};

struct GS2C_FinishQuestion <-
{
	int32 exp;
	int32 coin;
	int32 bindCoin;
	int32 score;
	int32 weekScore;
};


//	�������а�
struct C2GS_RankList_Req ->
{
	int8				rankType;   //1:�ǻ۴��˰�
};
// ������Ϣ
struct RankInfo
{
	int8                rank;      //����
	string				name;      //ţ�ư�͵ȼ���ʱΪ���name������ʱΪ���name
	int8                sex;       //�Ա�
	int8                career;    // ְҵ
	int32               count;     // �ǻ۴��˰�Ϊ���ܵ÷�
};
//	���а񷵻�
struct GS2C_RankList_Ret <-
{
	int32				retCode;    //0�ɹ�
	int8				rankType;   //1:�ǻ۴��˰�
	vector<RankInfo>    rank_list;  //���е������Ϣ
};


//	boss��ս���ȡbossˢ����Ϣ
struct C2GS_BossRefreshList_Req ->
{
};
struct BossRefreshInfo
{
	int8                isDead;      //1������  0:���
	int32               monsterDataId;//���������id
	int32               nextRefreshDownCountSec; //�����´�ˢ�»�Ҫ������
};
//	boss��ս��  ����bossˢ����Ϣ
struct GS2C_BossRefreshList_Ret <-
{
	vector<BossRefreshInfo>    refresh_list;  //bossˢ����Ϣ
};


//���������������ȵ�server,server���������浽��ұ������������ʱ��Ӧ�Ѵ���ұ�������client
struct C2GS_SaveNewHandGuildProgress ->
{
	int32 index;
};
