//-define(EnterBattleMap_Err_Of_Cfg, -1).  %%���Ʊ����
//-define(EnterBattleMap_Err_Of_Cnt, -2).  %%�����������
//-define(EnterBattleMap_Err_Of_Item, -3). %%��Ʒ����
//-define(EnterBattleMap_Err_Of_Level, -4). %%����ȼ�����
//-define(EnterBattleMap_Err_Of_PlayerCnt, -5). %%�����Ѿ��ﵽ����
//-define(EnterBattleMap_Err_Of_IsNotLeader, -6). %%���Ƕӳ�
//-define(EnterBattleMap_Err_Of_Time, -7). %%�δ��ʼ�����Ѿ�����
//-define(EnterBattleMap_Err_Of_Refuse, -8). %%�ܾ�����
//-define(EnterBattleMap_Err_Of_IsNotHaveTeam, -9). %%û�ж���
//-define(EnterBattleMap_Err_Of_InTeamList, -10). %%���Ѿ�ͬ�����ս��
//-define(EnterBattleMap_Err_Of_IsNotEnterSignalMap, -11). %%���ģʽ�²��ܽ��뵥��ս��
//-define(EnterBattleMap_Err_Of_PlayerIsMax, -12). %%�����ﵽ����
//-define(EnterBattleMap_Err_Of_EnterBattlMap, -13). %%���Ѿ������ս��
//-define(EnterBattleMap_Err_Of_NpcDis, -14). %%npc����̫Զ
//-define(EnterBattleMap_Err_Of_InBattlMap, -15). %%���Ѿ���ս����
//-define(EnterBattleMap_Err_Of_MemberLevel, -16). %%��Ա�ȼ�����
//-define(EnterBattleMap_Succ, 1). %%�ɹ�����ս��
//-define(RequestBattleMap_Succ, 2). %%�ӳ��������ս��
//-define(AgreeEnterBattle, 3). %%ͬ�����ս��

//���˽�ս��
struct C2GS_SignalEnterBattleMap ->
{
	int64 npcId;
	int32 npcDataId;
};

struct GS2C_SignalEnterBattleMap <-
{
	int8 retCode;
};

//��ӽ�ս��(�ӳ�����)
struct C2GS_TeamRequestEnterMap ->
{
	int64 npcId;
	int32 npcDataId;
};

struct GS2C_TeamRequestEnterMap <-
{
	int8 retCode;
};

//�����Ա���յ�����Ϣ
struct GS2C_InviteEnterBattleMap <-
{
	int64 npcId;
	int32 npcDataId;
	int64 inviteId;
	string inviteName;
};

struct C2GS_InviteEnterBattleMap ->
{
	int8 isAgree; //0:�ܾ�, 1:ͬ��
	int64 inviterId;
	int64 npcId;
	int32 npcDataId;	
};

struct GS2C_InviteerEnterBattleMap <-
{
	int8 retCode;
};

struct GS2C_InviteEnterBattleMap_Result <-
{
	int8 retCode; //0:�ܾ�, 1:ͬ��
	string playerName;
};

struct GS2C_UpdateBattlePlayerCnt <-
{
	int32 redPlayerCnt;
	int32 bluePlayerCnt;
	int32 remainTime;
};

struct battleBaseInfo
{
	int32 myScore;          //���ѵĻ���
	int32 redScore;          //
	int32 redKillPlayerCnt;  //��ɱ���
	int32 redKillBaseCnt;    //�ݻٽ���
	int32 redGatherCnt;      //��ȡʥ��
	int32 redKillMonster;    //��ɱ����
	int32 blueScore;          
	int32 blueKillPlayerCnt;  
	int32 blueKillBaseCnt;    
	int32 blueGatherCnt;      
	int32 blueKillMonster; 
};

struct GS2C_EndBattle <-
{
	int32 exp;
	int32 money;
	int32 honor;
	battleBaseInfo st;
};

struct GS2C_UpdateBattleInfo <-
{
	int32 myScore;          //���ѵĻ���
	int32 redScore;         //�췽����
	int32 blueScore;        //��������
	int32 killPlayerCnt;    //��ɱ���
	int32 deadCnt;          //��������	
};

struct C2GS_BuyBuff ->
{
	int32 buffId;
};

struct GS2C_BuyBuff <-
{
	int8 retCode; //-1,buff������,-2,��Ǯ����,-3,����ս����,1,�ɹ�
};

struct GS2C_TeamTimeOut <-
{
};

struct GS2C_Open_Battle_Door <-
{
	int64 id;
};





//offline pvp protocol
//�������߾�����ͻ���
struct GS2C_OfflineExp <-
{
	int32 normalProtOfflineExp;//��ͨ����ܱ����ľ���
	int32 vipExtraProtOfflineExp;//vip��Ҷ����ܱ����ľ���
	int32 notProtOfflineExp;//��һ�ȡ�Ĳ��ܱ��������߾���
	int32 robbedOfflineExp;//�����ߵľ���
};

//��ȡ���߾���
struct C2GS_PickupOfflineExp ->
{
};

struct RobbedRecord
{
	int32   robExp;
	int32   robTime;  //��������ʱ��
	int64   id;
	string	name;
	int8	career,
	int32	level;
	int32	fight;			//ս����
	int32   guildId;
};

//�������߾������ϸ��Ϣ
struct GS2C_RobbedOfflineExpDetailInfo <-
{ 
	vector<RobbedRecord> robbedRecordList;
}


	