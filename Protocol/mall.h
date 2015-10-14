struct mallInfo
{
	int32 id;
	int32 itemId;
	int32 item_type; //��Ʒ���� 1:����, 2:ҩƷ, 3:��ʯ, 4:ʱװ
	int32 sale_type; //0 ��ͨ�̳� 1 �ػ��̳� 2 VIP�̳�
	int32 number; //��������
	int32 discount; //�Ƿ��ۿ�, 1:�ۿ�, 0:���ۿ�
	int32 price; //ԭ��
	int32 price_discount; //�ۿۼ�
	int32 price_lucky; //�ػݼ�
	vector<int32> price_vip_vec;
};

struct GS2C_MallInfo <-
{
	vector<mallInfo> mallVec;
};

struct GS2C_MallHot9 <-
{
	vector<int32> vec;
};

struct GS2C_MallLuckyPrice <-
{
	vector<int32> vec;
};

struct C2GS_Common_Buy ->
{
	int32 id;
	int32 cnt;
};

struct GS2C_Common_Buy_Result <-
{
	int8 retCode; //1:�ɹ�, -1:����Ʒ�����̳���, -2:Ԫ������, -3:��������
};

struct C2GS_Lucky_Buy ->
{
	int32 id;
};

struct GS2C_Lucky_Buy_Result <-
{
	int8 retCode; //1:�ɹ�, -1:����Ʒ�����̳���, -2:Ԫ������, -3:��������
	int32 id;
};

struct C2GS_Mall_Refresh ->
{
	int64 playerId;
};

struct GS2C_Mall_Refresh_Result <-
{
	int8 retCode;
};

struct C2GS_vip_Buy ->
{
	int32 id;
	int32 cnt;
};

struct GS2C_vip_Buy_Result <-
{
	int8 retCode; //1:�ɹ�, -1:����Ʒ�����̳���, -2:Ԫ������, -3:��������
};