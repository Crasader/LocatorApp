struct playTime
{
	int32 startTime;
	int32 endTime;
};

struct buttonBase
{
	int32 type;
	int32 id;
};

struct activeCenterBaseInfo
{
	int32 id;	
	int32 remainTime;
};

struct GS2C_ActiveCenterBaseInfo <-
{
	vector<activeCenterBaseInfo> vec;
};

struct activeBaseInfo
{
	int32 id;
	int32 cnt; //ʱ�����ɵĴ���
	int32 completeCnt; //����ܴ���
};

//���ڽ���
struct GS2C_InActive <-
{
	vector<activeBaseInfo> vec;
};

//������ʼ
struct GS2C_Guture <-
{
	vector<activeBaseInfo> vec;
};

//�����
struct GS2C_Completed <-
{
	vector<activeBaseInfo> vec;
};

struct GS2C_UpdateActive <-
{
	int32 id;
	int32 cnt;
	int32 totalCnt;
};

struct C2GS_RequestEnterActive ->
{
	int32 id;
};

struct GS2C_RequestEnterActive <-
{
	int8 retCode; //1:�ɹ�
};

struct C2GS_OpenActiveUI ->
{
	int64 playerId;
};


//�ɳ����
struct C2GS_LevelAward_Req ->
{
	int32 level;
};

//��¼���
struct C2GS_LoginAward_Req ->
{
	int32 cfgId;//��¼���������id
};
