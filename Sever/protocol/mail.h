

//-define(Send_Mail_Failed_Title_Long, -1).  ����̫��
//-define(Send_Mail_Failed_Content_Long, -2).  ����̫��
//-define(Send_Mail_Failed_Name_Is_Not_Exit, -3).  ��Ҳ�����
//-define(Send_Mail_Failed_Item, -4).  ��Ʒ����
//-define(Send_Mail_Failed_Mail_Is_Full, -5).  ��������
//-define(Send_Mail_Failed_Item_Cnt, -6).  ����̫��
//-define(Send_Mail_Money_Too_Much, -7).  ��Ǯ��������
//-define(Send_Mail_Money_Is_Not_Enough, -8).  ��Ǯ����
//-define(Send_Mail_Succ, 1).  �ɹ�

//-define(Read_Mail_Is_Not_Exit, -1). �ʼ�������
//-define(Delete_Mail_Is_Have_Attach, -2).�и�������ɾ��
//-define(Read_Mail_Succ, 1).

//-define(Delete_Mail_Is_Not_Exit, -1). �ʼ�������
//-define(Delete_Mail_Succ, 1).

//-define(Get_Attach_Mail_Is_Not_Exit, -1). �ʼ�������
//-define(Get_Attach_Mail_Bag_Is_Full, -2). ��������
//-define(Get_Attach_Mail_Money_Too_Much, -3).��Ǯ��������
//-define(Get_Attach_Mail_HaveGet, -4).�Ѿ���ȡ����
//-define(Get_Attach_Mail_Succ, 1).

//-define(System_Mail, 1).  ��ͨ�ʼ�
//-define(Common_Mail, 2).  ϵͳ�ʼ�

struct Mail_Item
{
	int8 bagType;  //��������, 1:װ��, 2:����, 3:����
	int64 itemId; //��Ʒid
	int32 index;
	int32 itemCnt;     //��Ʒ����
};

struct C2GS_Send_Mail ->
{
	int64 receivePlayerId;
	string mailTitle;
	string mailContent;
	int32 money;
	vector<Mail_Item> vec;
};

struct GS2C_Send_Mail_Result <-
{
	int8 retCode;
};

struct C2GS_Read_Mail ->
{
	int64 mailId;
};

struct GS2C_Read_Mail_Result <-
{
	int8 retCode;
	int64 mailId;
};

//ɾ���ʼ�
struct C2GS_Delete_Mail ->
{
	int64 mailId;
};

struct GS2C_Delete_Mail_Result <-
{
	int8 retCode;
	int64 mailId;
};

//����ɾ��
struct C2GS_Delete_Mail_List ->
{
	vector<int64> mailIdList;
};

struct GS2C_Delete_Mail_List_Result <-
{
	int8 retCode;
	vector<int64> mailIdList;//ɾ���ɹ���id�б�
};

//��ȡ����
struct C2GS_Get_Attach ->
{
	int64 mailId;
};

struct GS2C_Get_Attach_Result <-
{
	int8 retCode;
	int64 mailId;
};

//������ȡ����
struct C2GS_Get_Attach_List ->
{
	vector<int64> mailIdList;
};

struct GS2C_Get_Attach_List_Result <-
{
	int8 retCode;
	vector<int64> mailIdList;//��ȡ�����ɹ���id�б�
};