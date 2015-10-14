
struct Friend_Info
{
	int64 playerId;  //���id
	string name;     //�������
	int32 level;     //��ҵȼ�
	int32 career;    //���ְҵ
	int32 sex;       //����Ա�
	int8  online;    //�Ƿ�����, 1:����, 0:������
	int8  type;      //1:����,2:����,3:������,4:��ʱ����
	int8  isInTeam;  //�Ƿ��ڶ�����
	int8  isVip;     //�Ƿ���vip
};

struct GS2C_All_Friend_Info <-
{
	vector<Friend_Info> vec;
};

// GS֪ͨ�ͻ���ϵͳ��Ϣ
struct GS2C_Friend_Info <-
{
	Friend_Info st;
};

// �ͻ���������������Ϣ
struct C2GS_Add_Friend ->
{
	int64 playerId;  //���id
	int8  type; //1:����,2:����,3:������
};

// -1:�����б�����
// -2:�Ѿ����б���
// -3:�Է�������
// 1: �Ӻ��ѳɹ�
struct GS2C_Add_Friend_Result <-
{
	int32 retCode; //����ֵ
};

struct C2GS_Remove_Friend ->
{
	int64 playerId; //���id
	int8  type; //1:����,2:����,3:������
};

struct GS2C_Remove_Friend_Result <-
{
	int32 retCode;  //-1:ʧ��, 1:�ɹ�
	int64 playerId; //���id
	int8  type; //1:����,2:����,3:������
};

struct C2GS_Request_Friend_State ->
{
};

struct friend_State
{
	int64 playerId;
	int32 level;
	int8 isInTeam;
};

struct GS2C_Request_Friend_State_Result <-
{
	vector<friend_State> vec;
};

//������ʱ������Ϣ
struct C2GS_Palyer_Touch_List_Req ->
{
	vector<int64> playerList
};

struct GS2C_Palyer_Touch_List_Ret <-
{
	vector<Friend_Info> player_list;
};