struct achievementBase
{
	int32 achievementId;
	int32 sort; //-1��������10��������������1��ʼ; �����δ��ɵĳɾ����ʾ�Ѿ���ɵ�������10��ʾ�Ѿ������10�μ�����
};

struct achievementProgress
{
	int32 achievementType;
	int32 cnt; //��ɴ���
};

struct GS2C_FinishAndUnFinishAchievementList <-
{
	vector<achievementBase> finishVec;//����ɵ��б�
	vector<achievementBase> unFinishVec;//δ��ɵ��б�
	vector<achievementProgress> progressVec;//���ɾͽ��ȣ���Щ��Ҫ��¼���ȵĳɾͲ����������vec������Ϊ0�ĳɾ�Ҳ������������vec
};

struct GS2C_AchieveProgressChange <-
{
	int32 achievementType;
	int32 cnt; //��ɴ���
};

struct GS2C_AddAchievement <-
{
	achievementBase st;
};

struct C2GS_UseAchievement ->
{
	int32 achievementId;
};

struct GS2C_UseAchievement <-
{
	int8 retCode; //0,�˳ɾ�δ���, 1�ɹ�
	int32 achievementId;
};

struct GS2C_UpdateAchievementFinishCnt <-
{
	int32 achievementId;
	int32 cnt;//��ô˳ɾ͵�����
};
