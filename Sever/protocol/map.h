//ʰȡ��Ʒ
//ʰȡ���Ӽ��ܵ���ʱ������ָ��id, �������id����д0
struct C2GS_PickUpItem ->
{
	int64 id;
};

struct GS2C_ChangeMap <-
{
	int32 mapDataID;
	int64 mapId;
	int16 x;
	int16 y;
};

//�鿴���λ��
struct C2GS_LookupPlayerPos ->
{
	int64 playerId;
};


//�鿴���λ��
struct GS2C_LookupPlayerPosRet <-
{
	int64 playerId;
	int64 mapId;
	int32 mapDataID;
	int16 x;
	int16 y;
};


//�鿴bossλ��
struct C2GS_LookupCurMapBossPos ->
{
	int32 bossDataId;
};


//�鿴bossλ��
struct GS2C_LookupCurMapBossPosRet <-
{
	int8  retCode; //0: �ɹ� 
	int32 mapDataID;
	int16 x;
	int16 y;
};


struct playerPos
{
	int64 playerId;
	int64 mapId;
	int32 mapDataID;
	int16 x;
	int16 y;
};

struct C2GS_LookupTeamPos ->
{
	int64 playerId;
};

struct GS2C_LookupTeamPos <-
{
	vector<playerPos> vec;
}

//�鿴λ��ģ����Ĵ��͹��ܣ��˴��ͽ����ĵ���
struct C2GS_TransferMapInLookupPos ->
{
	int64 mapId;
	int32 mapDataID;
	int16 x;
	int16 y;
	int8  isTransferWithTeam;//��������һ���ͣ�1   �����˴��ͣ�0
};


//�ڴ��͵�ʱ���ͻ���������
struct C2GS_ReqChangeMapInTransport ->
{
	int32 curMapDataID;
};

//�ڶ�̬���͵�ʱ���ͻ���������
struct C2GS_ReqChangeMapInDynamicTransport ->
{
	int32 curMapDataID;
	int64 doorId;
};

//�������ͼ�ϣ��ͻ���������
//���͵�Ŀ���ͼ�ĳ�����
struct C2GS_ReqChangeMapInWorldMap ->
{
	int32 desMapDataID;
};

//ͨ��npc���ͻ���������
struct C2GS_ReqChangeMapByNpc ->
{
	int64 id; //npc��Ψһid
	int32 npcDataID;//npc�������ļ����id 
	int16 npcTransferId;//npc_transfer���ñ��е�id
};

//������������븱��
struct C2GS_ReqEnterCopyMap ->
{
	int64  npcId; //npc��Ψһid
	int32  npcDataID;//npc�������ļ����id 
	int32  enterMapDataId;//�����������ʱ����д0
	int8   enterType; //1:���˽��� 2:����  3:ƥ��
};

struct GS2C_ReqEnterCopyMap_Ret <-
{
	int8 retCode;  //��鲻ͨ����ԭ��
	//int64 playerId;//�ĸ���Ҽ�鲻ͨ��, ֻҪ�����߷��Ͼ�ok,������Աֱ������ȥ
};

//�������Ա������������ŶӸ�����Ϣ
struct GS2C_BeginePrepareEnterCopy <-
{
	int64 npcId;
	int32 npcDataId;
	int32 copyMapDataId; //����data ID
	int8   enterType; //1:���˽��� 2:����  3:ƥ��
	int64 sponsorId;
};

//�ͻ��˻ظ�׼�����
struct C2GS_PrepareCompleteEnterCopy ->
{
	int64 sponsorId;
};
//�������յ�һ��C2GS_PrepareCompleteEnterCopy����Ҫת�����������˶�׼�����ʱ���͹㲥�������Ϣ
struct GS2C_AllPrepareEnterCopy <-
{
	int64 sponsorId;
};

//������ȡ�����븱��
struct C2GS_SponsorCancelEnterCopyMap ->
{
	int32 curMapDataId;
};

//ȡ�����븱��ʱ���͹㲥�������Ϣ
struct GS2C_CancelEnterCopyMap <-
{
	int32  cancelReason;
};

//���������ʼ���ͻ��˷���������Ϣ�����5�뵹��ʱ���븱��
struct C2GS_SponsorExitMatchEnterCopyMapNow ->
{
	int32 curMapDataId;
	int32  enterMapDataId;//�����������ʱ����д0
};

//���ȡ��ƥ�䣬���ٽ��븱��
struct C2GS_SponsorCancelMatchEnter ->
{
	int32 curMapDataId;
	int32  enterMapDataId;//�����������ʱ����д0
};

//�������븱��ʱ���͹㲥�������Ϣ
struct GS2C_ExitMatchEnterCopyMapNow <-
{
	int64 sponsorId;
};

struct GS2C_CancelMatchEnter <-
{
	int64 sponsorId;
};

//ƥ��ɹ�ʱ���㲥�������Ϣ
struct GS2C_MatchEnterCopySuccess <-
{
	int32  enterMapDataId; //��������ĸ�����
};

//����뿪����
struct C2GS_PlayerLeaveCopyMap ->
{
};


struct FightStatsInfo
{
	int64 playerId;     //��ҵ�id
	string playerName;  //��ҵ�����
	int8 damagePercent;//�˺����    �ٷ���
	int8 bearDamagePercent; //�˺�����     �ٷ���
	int16 killCnt;//��ɱ��
	int16 deadCnt;//�������� 
	int16 reliveCnt;//������Ѵ���
}
//
struct ItemDataIdAndCnt
{
	int32 itemDataID;
	int32 cnt;
};

//ͨ�ظ�����ʧ�ܣ�����ͨ����Ϣ���˸������������ң����isContinueΪ0���ͻ����յ��󣬿��ܵ���ʱ�뿪����
//�׶���ʤ����ѡ��򵹼�ʱ������Ҳ�ᷢ�ش���Ϣ�����isContinueΪ0���ͻ����뿪����
//���isContinueΪ1,�ͻ��˼������ڸ���
struct GS2C_CopyMapCompleted <-
{
	int8  successNum;   //  0����ս����ʧ��  1:�׶��Գɹ�  2:ͨ�ظ�����
	int8  isContinue;   //������1    ����������0
};

//�뿪�����󣬷���ͨ�ؽ�����Ϣ����ң��ͻ����յ�����Ļ���ֽ���Ի���
struct GS2C_CopyMapCheckOut <-
{
	int8  successNum;   //  0����ս����ʧ��  1:�׶��Գɹ�  2:ͨ�ظ�����
	//1) ս��ͳ��
	vector<FightStatsInfo> fightStats;
	//2)����
	int32  seconds;//���˶�����
	int16  steps; //��ɸ����Ĳ�����,
	int32  coin;  //���
	int32  exp;   //����
	vector<ItemDataIdAndCnt> itemInfos;//����
};


struct PlayerCopyCDInfo   
{
	int32 map_data_id;
	int8 enter_cnt; //�ѽ���Ĵ���
	int8 remain_cnt; //ʣ��Ĵ���
};
//������߻�cd����ʱ�����͸��ͻ��˵ĸ���cd ��Ϣ������ľ�Ӣ�����б�
struct GS2C_AllCopyCDInfo    <-
{
	vector<PlayerCopyCDInfo> copyCdInfos;//������CD��Ϣ
};


//֪ͨ�ͻ��ˣ�����ĳ������cd��Ϣ
struct GS2C_UpdatPlayerCopyCDInfo <-  
{
	int32 map_data_id;
	int8 enter_cnt; //�ѽ���Ĵ���
	int8 remain_cnt; //ʣ��Ĵ���
};

//�����رյ���ʱ,ʱ�䵽ʱ���ͻ���Ӧ�÷����뿪������Ϣ��������
struct GS2C_CopyMapClose_Countdown <-
{
	int8  second;     //����ʱʱ�䣬��λ��second
};

// ��ҽ��븱��ʱ�����ͳ�ʼ��Ϣ
struct GS2C_CopyInitInfo<-
{
	int16   copyStepId;      //��ɸ����Ĳ���Id ��Ӧcopy_step.xls���id
	int16  totalCnt;    //��Ҫ��ɵ�������
	int16  curCnt;     //��ǰ����ɵ�Ŀ������
	int16  remainSec;   //������ʣ��ʱ�䣬 ��λ����
	int16  mapDataID;
};

struct GS2C_UpdateCopyProgress<-
{
	int16   copyStepId;      //��ɸ����Ĳ���Id ��Ӧcopy_step.xls���id
	int16  curCnt;     //��ǰ����ɵ�Ŀ������
};

struct GS2C_MonsterSpawnRemind<-
{
	int16   waveIndex;      //�ڼ�������
	int16   delaySec;       //���ｫ�ڶ��������
	int16   isActive;       // 1:����Ҽ��������ǰ����
};

struct GS2C_GiveSelectionToContinueCopy<-
{
	int16  steps;      //��ɸ����Ĳ�����,
	vector<ItemDataIdAndCnt> itemInfos;//����
};

//�Ƿ������ѡ���
//��15��ĵ���ʱ�� ������������ʱ���������ѡ�� �ͻ���Ҫ��ʾ������ҵ�ѡ����
struct C2GS_ReplySelectionToContinueCopy ->
{
	int8 isContinue;//������1    ����������0
};
//�յ�C2GS_ReplySelectionToContinueCopy�󣬷������㲥����Ϣ����ͼ�ڵ��������
struct GS2C_ReplySelectionToContinueCopy <-
{
	int64 playerId; 
	int8 isContinue;//������1    ����������0
};

//�����ӵ��ļ��ܣ������ӵ�ʱ��ͬ����ҹ㲥Щ��Ϣ
struct GS2C_Missile <-
{
	int64 id;
	int64 ownerId;
	int32 skillId;
	int32 dataId;
	int16 targetX;
	int16 targetY;
	int16 offsetX;			// ƫ�Ƶ�x���� �ͻ��˱�����
	int16 offsetY;			// ƫ�Ƶ�y���� �ͻ��˱�����
	int8 multiNum;//���ظ���
};

// �ӵ�����Ŀ��󣬻�ը�������˺�
struct C2GS_MissileDamage ->
{
	int64 id;
	int64 targetId;   //��ײʱ��Ϊײ���Ķ���   ��ըʱΪ��ը�����꣨���ƴ��ļ��ܵ�ƴ�ӷ�ʽ)
	int8  index;
	int16 targetX;
	int16 targetY;
	int8 isExplosion;//�Ƿ�ը0: ��ײ   1����ը
};

struct GS2C_MissileDamage <-
{
	int64 id;
	int64 targetId;   //��ײʱ��Ϊײ���Ķ���   ��ըʱΪ��ը�����꣨���ƴ��ļ��ܵ�ƴ�ӷ�ʽ)
	int8  isExplosion;//0: ��ײ   1����ը
	int8  index;
};




struct BlockSectionInfo   
{
	int16 x; //�������ʼ���x����
	int16 y; //�������ʼ���y����
	int8 dx; //�����x����ĳ���
	int8 dy; //�����y����ĳ���
};
//��ҽ�����ʱ ������������Ҫ�����赵�������б�
struct GS2C_SetBlockSections    <-
{
	vector<BlockSectionInfo> blockSectionInfo;//�赵�������б�
};

//�����ʱ ������������Ҫ����赵������
struct GS2C_ClearBlockSections    <-
{
	vector<BlockSectionInfo> blockSectionInfo;//�赵�������б�
};

struct C2GS_OpenDoor_Req ->
{
	int64 id;//�ŵ�id
};
struct GS2C_OpenDoor_Ret <-
{
	int8  retCode;//0: �ɹ�  
	int64 id;     //�ŵ�id
};

//���� ���˸���
struct GS2C_ForbiddenArea_Exp <-
{
	int32 exp;//����ڴ˸������ȡ�ľ���
};


//�����ɹ�ʱ��
struct GS2C_COPY_SUCC_TIME <-
{
	int32 time;     //ʱ�����Ϊ0ʱ��ʾȡ��
};

struct OpenMap
{
	int32 id;
	int8 state;//0δ������1����
};

//�ص�����б�
struct GS2C_OPEN_MAP_LIST <-
{
	vector<OpenMap> bigMapList;//���ͼ
	vector<OpenMap> smallMapList;//С��ͼ
};

//�ص�������߸���
struct GS2C_OPEN_MAP_UPDATE_OR_ADD <-
{
	int8 type;//0���ͼ��1С��ͼ
	OpenMap map;
};

//�������
struct C2GS_OPEN_TREAS_Req ->
{
	int64 id;
	int64 open_state;//0������1ֹͣ����
};

struct GS2C_OPEN_TREAS_Ret <-
{
	int8  retCode;//0: �ɹ� 
	int64 id;
	int64 open_state;//0������1ֹͣ����
};

//����״̬����
struct GS2C_TREAS_STATE <-
{
	int64	id;
	int8	status;		// 0�����У�1������
	int32	disTime;	// ����ʱ��
};

//���俪���ɹ�
struct C2GS_OPEN_TREAS_Succ_Req ->
{
	int64 id;
};

struct GUIDE_INFO
{
	int16 x;
	int16 y;
};

struct GS2C_GUIDE_LIST <-
{
	vector<GUIDE_INFO> guides;
};


//-define(FreeFightCopyPhase_Wait,1).      %%�ȴ���������ս��
//-define(FreeFightCopyPhase_Countdown,2). %%����ʱ��������ս��
//-define(FreeFightCopyPhase_Started,3).   %%�ѿ�������ս��
struct GS2C_FreeFightCopyPhaseInfo <-
{
	int8 phase;         //����ս�������ĸ��׶�
	int16 countDownSecs;//�ڵ���ʱ�׶Σ������������׶���д0
};

//�����ȡ���ְ�
struct C2GS_FreeFightCopyScoreBoard_Req ->
{
};

struct scoreBoardItem
{
	string	name;
	int32	level;
	int16 killCnt;//��ɱ��
	int16 deadCnt;//�������� 
};
struct GS2C_FreeFightCopyScoreBoard <-
{
	int32 redCampScore;//�췽�Ļ���
	int32 blueCampScore;//�����Ļ���
	vector<scoreBoardItem> redVec;//
	vector<scoreBoardItem> blueVec;//
};

//��������淨�Ѿ�����������������4������30���ڹرո�����������Ҵ�������
struct GS2C_FreeFightCopyCloseTimerStart<-
{
	int16 countDownSecs;//�ڵ�������
};
//��������˹رո����ĵ���ʱ���������������ӵ���4���ˣ���ȡ������رո����ĵ���ʱ
struct GS2C_FreeFightCopyCloseTimerCancel<-
{
	int8 reserve;//Ԥ����û��ʹ��
};



struct freeFightCheckoutItem
{
	int64 id;
	string	name;
	int32	level;
	int16 killCnt;//��ɱ��
	int16 deadCnt;//�������� 
	int32 bindCoin;//�����İ���
	int32 exp;     //�����ľ���
	int32 honor;   //����
};
struct GS2C_FreeFightCopyCheckout<-
{
	int8  winCamp;  //��ʤ��һ����ƽ��ʱ����ʤ��һ����0
	int32 redCampScore;//�췽�Ļ���
	int32 blueCampScore;//�����Ļ���
	vector<freeFightCheckoutItem> redVec;//
	vector<freeFightCheckoutItem> blueVec;//
};


struct GS2C_LivePoint<-
{
	int16 livePoint;//ע��ȣ�-1Ϊ�����
};

struct ContentionPoint
{
	int8 id;
	int16 x;
	int16 y;
	int8 r;//�뾶
	int8 processOwner;//���ȹ���0��ң�1����
	int8 processType;//�����Ƿ���0ֹͣ��1��, 2����
	int16 process;//����
};
struct GS2C_ContentionInfo<-
{
	int16 monsterPoint;
	int16 playerPoint;
	vector<ContentionPoint> contentionPoints;
};