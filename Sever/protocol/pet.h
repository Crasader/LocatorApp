
//���������·�
struct GS2C_PET_EXP_UPDATE <-
{
	int32 exp;
};

//�����ս
struct C2GS_CALL_PET_Req ->
{
	int64 id;
};

struct GS2C_CALL_PET_Ret <-
{
	int64 call_id;
	int64 call_back_id;
};

//�����л�
struct C2GS_CALL_BACK_PET_Req ->
{
	int64 id;
};

struct GS2C_CALL_BACK_PET_Ret <-
{
	int64 id;
};

//��ͼ������¹㲥��Ϣ
struct GS2C_PET_MAP_UPDATE <-
{
	int64 id;
	int16 level;
	int32 hp;
	int32 mp;
	int32 hp_max;
	int32 mp_max;
};

//����ǿ��
struct C2GS_PET_STRENG_Req ->
{
	int64 id;
};

struct GS2C_PET_STRENG_Ret <-
{
	int8 retCode;//0:�ɹ���-1�Ѿ����ȼ���-2��Ǯ���㣬-3���ϲ���
};

struct C2GS_PET_FEED_Req ->
{
	
};

struct GS2C_PET_FEED_Ret <-
{
	int8 retCode;//0:�ɹ���-1�Ѿ����ι��ֵ��-2���ϲ���
};