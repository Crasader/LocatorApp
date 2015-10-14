// define msg between client and loginserver

// ��¼��֤������ƽ̨��
struct C2LS_Login_Test ->
{
	string	account;
	int16	platformID;
	string	sign;
	string	deviceIMEI;
	string	screenSize;
	int32     channelId;
};

// ��¼��֤����
struct LS2C_Login_Ret <-
{
	int8	result;
	int64	userID;
};

// ����������б���Ϣ
struct C2LS_RequestGameServerList ->
{

};

// �������б���Ϣ�ṹ
struct GameServerInfo
{
	int32	id;
	string	name;
	int32	status;
	string  desc;
	int8	isExist; //1:���ڽ�ɫ��0�������ڽ�ɫ
	int8	career,//  1 սʿ Career_Soldier; 2 ��ʿ Career_DaoShi  ; 3 ��ʦ Career_FaShi  
	int8	sex;//1:�� 0:Ů
	int32	level; //��ɫ�ȼ�
	string	playerName; //��ɫ������
	int8    isNew;      // �Ƿ����·�
	string  regionName;  // ����
};

// ���ط������б�
struct LS2C_GameServerList_Ret <-
{
	int8    regionCnt;   // ��༸����
	vector<GameServerInfo>	gameServers;
};

// ѡ����Ϸ�������������������Ϣ
struct C2LS_RequestSelGameServer ->
{
	int32	serverID;
};

// ���ط�������Ϣ
struct LS2C_SelGameServer_Ret <-
{
	int32		retCode;
	string		ip;
	int16		port;
	string		sign;
};

//������һ��
struct C2LS_BackPreStatus ->
{
};