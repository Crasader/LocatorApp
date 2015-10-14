struct taskProgress
{
	int8 targetType; //Ŀ������
	int32 targetCnt; //�����ļ�����Ҫ��ɵ�����
	int32 curCnt; //��ǰ��ɵ�����
};

//��ȡ����
struct C2GS_AccpetTask ->
{
	int32 taskId;
	int32 npcDataId;
	int64 npcId;
};

struct GS2C_AccpetTask_Result <-
{
	int32 taskId;
	//1:�ɹ�, -1:npc������, -2:��ҵȼ�����, -3:���ְҵ����, -4:�ɽ�ȡ����ﵽ����, 
	//-5:�Ѿ���ȡ��, -6:�������Ѿ������, -7:ǰ������δ���, -8:��npc����̫Զ
	int8 retCode;
};

//ȡ������
struct C2GS_CannelTask ->
{
	int32 taskId;
	int32 npcDataId;
	int64 npcId;
};

struct GS2C_CannelTask_Result <-
{
	int32 taskId;
	//1:�ɹ�, -1:npc������, -2:��npc����̫Զ, -3:������δ��ȡ
	int8 retCode;
};

//�ύ����
struct C2GS_SubmitTask ->
{
	int32 taskId;
	int32 npcDataId;
	int64 npcId;
	int8  index;
};

struct GS2C_SubmitTask_Result <-
{
	int32 taskId;
	//1:�ɹ�, -1:npc������, -2:������δ��ȡ, -3:��ҵȼ�����, -4:��npc����̫Զ,
	//-5:��ҳ�������, -6:�����ռ䲻��, -7:����δ���, -8:�������
	int8 retCode;
};

struct acceptTask
{
	int32 taskId;
	vector<taskProgress> progress;
};

//�ѽ�ȡ�����б�
struct GS2C_AcceptTaskList <-
{
	vector<acceptTask> vec;
};

struct completeTask
{
	int32 taskId;
	int32 completeCnt;
};

//����������б�
struct GS2C_CompleteTaskList <-
{
	vector<completeTask> vec;
};

//������ȱ仯
struct GS2C_TaskProgressChange <-
{
	int32 taskId;
	vector<taskProgress> progress;
};



struct C2GS_CompleteGather ->
{
	int64 gatherId;
};

struct GS2C_CompleteGather_Result <-
{
	int64 gatherId;
	int8 retCode; //-1:ʱ��δ��, 1:�ɹ�
};




///////////////////////////////////////////////////////////////////////////////////////////////////////������///////////////////////////////////////////////////////////////////////////////////////////////////////

struct C2GS_AccpetTaskChain ->
{
	int32 taskId;
	int32 npcDataId;
	int64 npcId;	
};

struct GS2C_AccpetTaskChain <-
{
	int32 retCode; //1:�ɹ�,0:ʧ��
};

//�ύ������
struct C2GS_SubmitTaskChain ->
{
	int32 taskId;
	int32 npcDataId;
	int64 npcId;	
};

//ȡ��������
struct C2GS_CannelTaskChain ->
{
	int64 playerId;
};

struct GS2C_CannelTaskChain <-
{
	int8  retCode;
	int16 loopCnt;
};