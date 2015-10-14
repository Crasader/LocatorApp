// -> client to server
// <- server to client
// <-> client & server

// �����¼gameserver
struct C2GS_Login ->
{
	int64		accountID;
	string		sign;
	int32		version;
};

struct UserPlayerData
{
	int64	playerID;
	string	name;
	int32	level;
	int8	career;
	int8	sex;
};

// ��¼���أ��ɹ����ؽ�ɫ�б�
struct GS2C_Login_Ret <-
{
	int32		retCode;
	vector<UserPlayerData>	player_list;
};

// ���󴴽���ɫ
struct C2GS_CreatePlayer ->
{
	string	name;
	int8	career;//  1 սʿ Career_Soldier; 2 ��ʿ Career_DaoShi  ; 3 ��ʦ Career_FaShi  
	int8	sex;//1:�� 0:Ů
};

// ���󴴽���ɫ���أ��ɹ����ؽ�ɫ��Ϣ
struct GS2C_CreatePlayer_Ret <-
{
	int32	retCode;
	vector<UserPlayerData>	player_list;
};

// ɾ����ɫ
struct C2GS_DeletePlayer ->
{
	int64	playerID;
};

// ���󴴽���ɫ���أ��ɹ����ؽ�ɫ��Ϣ
struct GS2C_DeletePlayer_Ret <-
{
	int32	retCode;
	vector<UserPlayerData>	player_list;
};

// ���������Ϸ
struct C2GS_EnterGame ->
{
	int64	playerID;
};

// С�ˣ�����ѡ���ɫ����
struct GS2C_ReturnToSelectRoleDlg_Ret <-
{
	int32		retCode; //0: �ɹ�  ��0�������ʱ,��ر�client
	vector<UserPlayerData>	player_list;
};

// ������������Ϸ�󣬷��������Ȼᷢ�����������ݵ��ͻ��ˣ�����Ϣָ�����ݷ������
struct GS2C_SendPlayerDataComplete <-
{
	int32 mapDataId;//��ͼ������id�� ���mapDataId����0���벻Ҫ����
	int16	x;   // in logical, player current position
	int16	y;   // in logical, player current position
};

// �ͻ��˼��������ݺ�ᷢ�ͽ����ͼ����
struct C2GS_EnterMap ->
{
};





