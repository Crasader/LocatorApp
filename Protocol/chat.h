
// -define(ChannelType_World, 1).     %%����
// -define(ChannelType_Guild, 2).     %%����
// -define(ChannelType_Team, 3).      %%����
// -define(ChannelType_Map, 4).       %%ͬһ�ŵ�ͼ
// -define(ChannelType_System, 5).    %%ϵͳ
// -define(ChannelType_Horn, 6).      %%����
// -define(ChannelType_Horn, 7).      %%˽��

struct ItemLink
{
	int8 bagType;  //��������, 1:װ��, 2:����, 3:����
	int64 itemId; //��Ʒid
};

// �ͻ���������������Ϣ
struct C2GS_Chat ->
{
	int8	channelId;  //Ƶ��
	string	message;    //��Ϣ
	vector<ItemLink> vec;   //��Ʒid�б�
};

struct C2GS_Private_Chat ->
{
	int64   playerId;
	string  message;
};

struct GS2C_Monster_ChatMsg <-
{
	int64   monsterId; //
	int32   strId;//
	int32   displayMs;
};