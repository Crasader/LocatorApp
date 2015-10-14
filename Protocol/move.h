//���ļ��е�����λ����Ϣ����ʵ�ֵ��߼�����
struct PosInfo   
{
	int16 x;
	int16 y;
};

struct C2GS_PlayerMoveTo    ->
{	
	int32 curMapDataId; // player current map data id
	int16 posX;// player current position
	int16 posY;// player current position
	vector<PosInfo> posInfos;//move path
};



struct GS2C_PlayerStopMove <-
{
	int64 id;//player id
	int16 posX;// player current position
	int16 posY;// player current position
};

struct C2GS_PlayerStopMove ->
{
	int32 curMapDataId; // player current map data id
	int16 posX;// player current position
	int16 posY;// player current position
};

struct GS2C_PlayerMoveInfo    <-
{
	int64 	id;//player id
	int16    posX;// player current position
	int16    posY;// player current position
	vector<PosInfo> posInfos;//move path
};
// player look info
struct GS2C_LookInfoPlayer  <-
{
	int64	id;
	string	name;
	int64   guildId;
	int16	level;
	int8	career;
	int8	sex;
	int32 	weapon;
	int32	armor;
	int32	wing;

	int64	hp;
	int64	hpMax;
	int32	mp;
	int32	mpMax;

	int16	x;   // in logical, player current position
	int16	y;   // in logical, player current position
	int16	moveSpeed;
	int16   movedMs;
	int32	status;		// ״̬��־λ
	int8	vipLevel;	// vip�ȼ�
	vector<PosInfo> posInfos;//�����ҡ���ƶ���vector��ֻ�����һ��pos, ��¼dirx and diry
	int32   pkValue;
	int8    camp;
	int32   battleScore;
	int32   achievementId;
	int8   deadRestTime;//����״̬ʣ�ิ��ʱ��
	int16  restPoint;//ʣ�����
	int8 helpNum;//���Ƚ�ɫ��Ŀ
	int16 restTime;//ʣ�����
};

struct GS2C_LookInfoTreas  <-
{
	int64	id;
	int32   dataId;
	int16	x;   // in logical, player current position
	int16	y;   // in logical, player current position
	int8	status;		// 0�����У�1������
	int32	disTime;	// ����ʱ��
};

//virtaul player look info
struct GS2C_LookInfoVirtualPlayer  <-
{
	int64	id;
	string	name;
	int64   guildId;
	int16	level;
	int8	career;
	int8	sex;
	int32 	weapon;
	int32	armor;
	int32	wing;

	int64	hp;
	int64	hpMax;
	int32	mp;
	int32	mpMax;

	int16	x;   // in logical, player current position
	int16	y;   // in logical, player current position
	int16	moveSpeed;
	int16   movedMs;
	int32	status;		// ״̬��־λ
	int8	vipLevel;	// vip�ȼ�
	vector<PosInfo> posInfos;//�����ҡ���ƶ���vector��ֻ�����һ��pos, ��¼dirx and diry
	int32   pkValue;
	int8    camp;
	int8    profession;//ְҵ,
	int32   battleScore;
	int32   achievementId;
};
// monster look info
struct GS2C_LookInfoMonster   <-
{
	int64	id;
	int16	monster_data_id;//�����������ļ����id

	int64 hp;
	int64 hpMax;
	int32 mp;
	int32 mpMax;

	int16	x;   // in logical,current position
	int16	y;   // in logical,current position
	int16	moveSpeed;
	int16   movedMs;
	int32	status;		// ״̬��־λ
	vector<PosInfo> posInfos;//·���ڵ㣬���vectorΪ�գ�����Ҫ�ƶ�
	int8    camp;
};
// npc�����Ϣ
struct GS2C_LookInfoNpc   <-
{
	int64		id;
	int32	npc_data_id;//npc �������ļ����id
	int16	x;   // in logical
	int16	y;   // in logical
	
};


struct GS2C_LookInfoItem <-
{
	int64		id;
	int32	item_data_id;
	int64   ownerId;
	int16	x; // in logical
	int16	y;  // in logical
};

// trap look info
struct GS2C_LookInfoTrap  <-
{
	int64 id;
	int32	trapDataId;

	int16	x;   // in logical, ���Ͻǵ�x����
	int16	y;   // in logical, ���Ͻǵ�y����
	int16	dx;  // x ����ĳ���
	int16	dy;  // y ����ĳ���
};

// pet look info
struct GS2C_LookInfoPet  <-
{
	int64 id;
	int64 masterId; //���˵�id
	int16	dataId;//�������ļ����id
	string name;
	int16	level;

	int64 hp;
	int64 hpMax;
	int32 mp;
	int32 mpMax;

	int16	x;   // in logical,current position
	int16	y;   // in logical,current position
	int16	moveSpeed;
	int16   movedMs;
	int32	status;		// ״̬��־λ
	vector<PosInfo> posInfos;//·���ڵ㣬���vectorΪ�գ�����Ҫ�ƶ�
};

struct GS2C_LookInfoDynamicTransferDoor <-
{
	int64		id;
	int32	door_data_id;
	int16	x; // in logical
	int16	y;  // in logical
	int8    cx; //��x�����ϵĳ���
	int8    cy; //��y�����ϵĳ���
};

// �����ʧ
struct GS2C_ActorDisapearList<-
{
	vector<int64>		info_list;
};

struct GS2C_MonsterStopMove <-
{
	int64 id;//monster id
	int16 posX;// monster current position
	int16 posY;// monster current position
};
struct GS2C_MonsterMoveInfo    <-
{
	int64 	id;//monster id
	int16    posX;// monster current position
	int16    posY;// monster current position
	vector<PosInfo> posInfos;//move path
};


struct C2GS_PetMoveTo    ->
{
	int32 curMapDataId; // pet current map data id
	int16 posX;// pet current position
	int16 posY;// pet current position
	vector<PosInfo> posInfos;//move path
};



struct C2GS_PetStopMove ->
{
	int32 curMapDataId; // pet current map data id
	int16 posX;// pet current position
	int16 posY;// pet current position
};

struct GS2C_PetStopMove <-
{
	int64 id;//pet id
	int16 posX;// pet current position
	int16 posY;// pet current position
};

struct GS2C_PetMoveInfo    <-
{
	int64 	id;//pet id
	int16    posX;// pet current position
	int16    posY;// pet current position
	vector<PosInfo> posInfos;//move path
};



//��ң�������� ˲��
struct GS2C_RoleTeleport <-
{
	int64 id;//player or monster or pet id
	int16 posX;// ˲�Ƶ���λ��
	int16 posY;// ˲�Ƶ���λ��
};


struct C2GS_PetTeleport_OutOfView ->
{
	int32 curMapDataId; // pet current map data id
	int64 id;//pet id
};



struct PushRoleInfo   
{
	int64 id
	int16 curX;
	int16 curY;
	int16 targetX;
	int16 targetY;
};
struct GS2C_SkillPushRoleList <-
{
	int64 castId;//ʩ����id
	int32	skillId; //����ID
	vector<PushRoleInfo> affectRoles;
};



struct C2GS_PlayerEvade->
{
	int32 curMapDataId; //player current map data id
	int16 desPosX;
	int16 desPosY;
};
struct GS2C_PlayerEvade    <-
{
	int64 	id;//player id
	int16 desPosX;
	int16 desPosY;
};


