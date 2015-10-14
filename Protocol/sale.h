struct saleItem
{
	int8 bagType;
	int32 index;
	int64 itemId;
	int32 itemCnt;
};

//�ϼ���Ʒ
struct C2GS_PutOnItem ->
{
	saleItem item;
	int64 npcId;
	int32 npcDataId;
	int32 price;
};

//�ϼ�Ԫ��
//goldType;
//-define(Sale_Gold_Type_200, 1).
//-define(Sale_Gold_Type_500, 2).
//-define(Sale_Gold_Type_1000, 3).
//-define(Sale_Gold_Type_2000, 4).
//-define(Sale_Gold_Type_5000, 5).
//-define(Sale_Gold_Type_10000, 6).
struct C2GS_PutOnGold ->
{
	int64 npcId;
	int32 npcDataId;
	int32 price;
	int8 goldType;
};

struct GS2C_PutOnGold_Result <-
{
	int8 retCode; //1:�ɹ�, -1: Ԫ�����ʹ���, -2:Ԫ������, -3:δ�ҵ����۵�npc, -4:npc����̫Զ, -5:�����Ѿ��ﵽ����, -6:���Ѽ���Ԫ���Ѿ��ﵽ����
	int64 saleId;
	int32 goldType;
};

//�¼�
struct C2GS_TakeDown ->
{
	int64 saleId;
};

struct GS2C_TakeDown_Result <-
{
	int8 retCode; //1:�ɹ�, -1:�˼��۲�����, -2:��������, -3:Ԫ���ﵽ���ֵ
	int64 saleId;
};

//����
struct C2GS_Buy ->
{
	int64 saleId;
};

struct GS2C_Buy <-
{
	int64 saleId;
	int64 buyPlayerId;
	string buyPlayerName;
};

struct GS2C_Buy_Result <-
{
	int8 retCode;//-1;��Ҳ���, -2:��������, -3:Ԫ���������޻�����������, -4:�Ѿ�������������
};

//sub_typeӦ�ɲ߻�ָ��, ��:������, 1000--1999֮��
struct C2GS_Filter_Item ->
{
	int32 sub_type;   //��Ʒsub_type����ֵ
	int32 carrer; //ְҵ
	int32 grade; //Ʒ��
	int32 quality; //Ʒ��
};

struct C2GS_Filter_Item_Next_Page ->
{
	int32 page; //��ʾ�ڼ�ҳ(���±�2��ʼ)
};

struct C2GS_Filter_Gold ->
{
	int32 goldType;
};

struct C2GS_Filter_Gold_Next_Page ->
{
	int32 page; //��ʾ�ڼ�ҳ(���±�2��ʼ)
};

struct sale_filter_gold
{
	int32 price;
	int32 goldType;
	int64 saleId;
};

struct GS2C_Filter_Gold_Result <-
{
	int8 isNextPage;
	int32 totalPage;
	vector<sale_filter_gold> saleVec;
};

struct C2GS_Find_Item ->
{
	string itemName;
};

struct C2GS_Find_Item_Next_Page ->
{
	int32 page; //��ʾ�ڼ�ҳ(���±�2��ʼ)
};

struct GS2C_Delete_Sale <-
{
	int64 saleId;
};