// GS����ע���Լ�
struct GS2LS_Register_Request <->
{
	int32	serverID;
	string  sign;
};

// GSע�᷵��
struct LS2GS_Register_Ret <->
{
	int32	retCode;
};

// LS�����˺��ڸ÷����û���Ϣ
struct LS2GS_GetPlayerInfo_Request <->
{
	int64		userID;
};

// LS�����˺��ڸ÷����û���Ϣ
struct GS2LS_GetPlayerInfo_Ret <->
{
	int64	accountID; // �˺�ID
	int64	userID; // ��ɫID
	int8	isExist;
	int8	career,//  1 սʿ Career_Soldier; 2 ��ʿ Career_DaoShi  ; 3 ��ʦ Career_FaShi  
	int8	sex;//1:�� 0:Ů
	int32	level; //��ɫ�ȼ�
	string	name; //��ɫ������
};

// LS֪ͨGS���׼����¼
struct LS2GS_UserReadyToLogin <->
{
	int32	platId;
	int64	accountID;
	string	account;
	string	sign;
};

// ��ҵ�¼GS��LS֪ͨ
struct GS2LS_UserLogin <->
{
	int32	platId;
	int64	accountID;
	string	account;
	string	sign;
};

// ����˳�GS��LS֪ͨ
struct GS2LS_UserLogout <->
{
	int64		userID;
};

// LS֪ͨGS�߳����
struct LS2GS_UserKick <->
{
	int64		userID;
};

// ��ֵ��Ϣ
struct LS2GS_PayInfo_Request <->
{
	string		webPid;
	string		op;
};

// ��ֵ��Ϣ����
struct GS2LS_PayInfo_Ret <->
{
	string		webPid;
	string		orderId;
	int8		retCode;
};

// ��̨GM����
struct LS2GS_GM_CMD_Request <->
{
	string		webPid;
	string		op;
};

struct GS2LS_GM_CMD_Ret <->
{
	string		webPid;
	string		name;
	int8		retCode;
};

// ���������
struct LS2GS_Kick_Player_Off_Request <->
{
	string		webPid;
	string		name;
};

struct GS2LS_Kick_Player_Off_Ret <->
{
	string		webPid;
	string		name;
	int8		retCode;
};

// ϵͳ����
struct LS2GS_Announcement_Request <->
{
	string		webPid;
	string		msg;
};

struct GS2LS_Announcement_Ret <->
{
	string		webPid;
	int8		retCode;
};

// ��̨���ƻ�Ŀ�����ر�
struct LS2GS_control_activity_Request <->
{
	string		webPid;
	string		op;
};

struct GS2LS_control_activity_Ret <->
{
	string		webPid;
	int8		retCode;
};

struct GS2LS_kickOutUser <->
{
	int64 userId;
};

struct GS2LS_upadateOnlinePlayerCnt <->
{
	int32 onlinePlayerCnt;
};

struct LS2GS_Forbid_Chat_Request <->
{
	string webPid;
	string name;
	int32 time;
	int8 flag;
};

struct GS2LS_Forbid_Chat_Request_Ret <->
{
	string		webPid;
	int8		retCode;	
};

struct LS2GS_SET_GM_Request <->
{
	string		webPid;
	string		name;
	int8        flag;
};

struct GS2LS_SET_GM_Request_Ret <->
{
	string		webPid;
	int8		retCode;	
};