//������
struct C2GS_RequestTrade ->
{
	int64 desPlayerId; //Ŀ�����
};

struct GS2C_RequestTrade <-
{
	int64 tradeId; //����id
	string requestName;
};

//��Ӧ����
struct C2GS_ReponseTrade ->
{
	int64 tradeId; //����id
	int8 reponse; //1:ͬ��, 0:�ܾ�
};

struct GS2C_ReponseTrade_Result <-
{
	int8 retCode; //-1:�Է��Ѿ�����, -2:���ײ�����, -3:����̫Զ, -4:�Է������������ڽ���, 1:ͬ��, 0:�ܾ�
	string name;
	int64 tradeId;
};

struct GS2C_RequestTrade_Result <-
{
	int8 retCode; //-1:�Է�������, -2:����̫Զ, -3:�Լ�����δ��, -4���Է�����δ��  1:�ɹ�
	int64 tradeId;
}

//ȡ������
struct C2GS_CannelTrade ->
{
	int64 tradeId;
};

struct GS2C_CannelTrade <-
{
	int64 playerId;
	int64 tradeId;
};

struct tradeItem
{
	int8 bagType;
	int32 index;
	int64 itemId;
	int32 itemCnt;
};

struct C2GS_InputItem ->
{
	int64 tradeId;
	int32 coin;
	vector<tradeItem> vec;
};

struct GS2C_InputItem <-
{
	int8 retCode; //-1:ʧ��, 0:�ɹ�
}

//��������
struct C2GS_LockTrade ->
{
	int32 coin;
	vector<tradeItem> vec;
	int64 tradeId;
};

struct GS2C_LockTrade_Result <-
{
	int8 retCode; //1:�ɹ�, -1:Ԫ������, -2:��Ҳ���, -3:��Ʒ����, -4:���ײ�����, -5:����״̬����, -6:�Է��Ѿ�����
	int64 tradeId;
};

struct C2GS_StartTrade ->
{
	int64 tradeId;
};

struct GS2C_StartTrade <-
{
	int8 retCode; //1:�ɹ�, 2,�Է�ȷ������, -1:���ײ�����, -2:����״̬����, -3:�Է��Ѿ�����, -4����ʧ��
	int64 tradeId;
};

struct C2GS_NpcShopBuy ->
{
	int64 npcId;
	int32 npcDataId;
	int32 itemDataId;
	int32 itemCnt;
};

struct GS2C_NpcShopBuy_Result <-
{
	int8 retCode; //0:�ɹ�, 1:�����ռ䲻�� 2: ��Ҳ��� 3���󶨽�Ҳ��� 4: Ԫ������ 5����Ԫ������ 
};

struct C2GS_NpcShopSell ->
{
	int64 itemId;
	int32 itemDataId;
	int8  bagType;
	int32 itemCnt;
};

struct GS2C_NpcShopSell_Result <-
{
	int8 retCode; //0:ʧ��, 1:�ɹ�
};

struct C2GS_PortableShopBuy ->
{
	int32 itemDataId;
	int32 itemCnt;
};

struct GS2C_PortableShopBuy_Result <-
{
	int8 retCode; //0:�ɹ�, 1:�����ռ䲻�� 2: ��Ҳ��� 3���󶨽�Ҳ��� 4: Ԫ������ 5����Ԫ������ 
};