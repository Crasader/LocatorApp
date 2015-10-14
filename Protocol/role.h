// -> client to server
// <- server to client
// <-> client & serverGS2C_PlayerProperty


// ��ҵ������Ըı���Ϣ
struct GS2C_PlayerSingleProperty  <-
{
	int16	type;		//���Զ�Ӧ�����ĸ�����
	int64	value;		//��Ӧ���Ե�ֵ
};


// ��ҵ������Ըı���Ϣ
struct GS2C_PlayerSinglePropertyStr  <-
{
	int16	type;		//���Զ�Ӧ�����ĸ�����
	string	value;		//��Ӧ���Ե�ֵ
};

// ��ҵ������Ըı�㲥��Ϣ value is number
struct GS2C_PlayerSinglePropertySync  <-
{
	int64	playerID;	//���ID
	int16	type;		//���Զ�Ӧ�����ĸ�����
	int64	value;		//��Ӧ���Ե�ֵ
};



// ��ҵ������Ըı�㲥��Ϣ value is string, eg:��Ұ������
struct GS2C_PlayerSinglePropertyStrSync  <-
{
	int64	playerID;	//���ID
	int16	type;
	string	value;		//��Ӧ���Ե�ֵ
};

struct PlayerProperty
{
	int16 type;
	int64	value;		//��Ӧ���Ե�ֵ
};
// ��Ҷ�����Ըı�㲥��Ϣ value is number
struct GS2C_PlayerMultiplePropertySync  <-
{
	int64	playerID;	//���ID
	vector<PlayerProperty> playerProperties;		// ��Ҷ������
};


// ����ʹ�õ�cdʱ��
struct GS2C_CdUseItem <-
{
	int32	id; //��Ʒ����
	int64	remainTime; //cdʣ��ʱ��
};

// BUFF��Ϣ
struct PlayerBuffInfo
{
	int64   id;      //Ψһid
	int32	buffDataId;  //����id
	int32	duration; //��λ������

	//int8    acc;  //��������
	//int32   power; //
	//int32   powerpercent;//ǧ����
};


// ������Ϣ
struct PlayerSkillInfo
{
	int16	skillId; //����ID
	int16   level;   //���ܵȼ�
	int16	cdtime; //cdʱ�� �˴�cd���ж�ã����ڱ���������ߺ��cdʱ��
};

//���������Ϸ��������ҽ�ɫ��������Ϣ
struct GS2C_PlayerProperty  <-
{
	// ��������
	int64	playerID;
	string	name;
	int32	level;
	int8	career;
	int64	exp;
	int64	bindCoin;		//�󶨽��,���Ĭ�ϲ�����
	int32	treasure;		//Ԫ��
	int32	bindTreasure;	//��Ԫ��
	int32	fight;			//ս����
	vector<GS2C_CdUseItem> cdTimeUseItem; //ʹ����Ʒ��cdʱ���б�
	int8	bagGridNum;		//��������
	int8    vipLevel; 		//vip�ȼ�
	int32   totalTreasure; 	// �ۼƳ�ֵ���
	int16   titleId; 		//��ҵĳƺ�ID
	int64   hp;             //��ǰѪ��
	int32   mp;             //��ǰħ��ֵ
	int8    recoverCount;//��Ѹ������
	int16   manufactureSize; //�������������
	// ս������
	vector<PlayerBuffInfo> buff_list;
	vector<PlayerSkillInfo> skill_list;
	int32	state;					//״ֵ̬
	int32	pk;						//pkֵ
	int8	pkState;				//pkģʽ
	
	int32 phy_dam;               //�����˺� 
    int32 fire_dam;              //���˺� 
	int32 code_dam;              //���˺�
    int32 elec_dam;              //����	
	int32 toxin_dam;             //���˺�
	int16 base_dam_increase;     //�����˺���ǿ
	int32 all_dam_increase;      //����˺�
	int32 all_dam_reduce;        //�ܵ��˺�ϵ��
	int32 atk_power;             //����ǿ�� 
	int64 hp_max;				 //���Ѫ��
	int32 hp_r;                  //�������ֵ 
	int32 hp_rp;                 //ÿ��ظ��������
	int32 by_cure_factor;        //�ܵ�����ϵ��
	int32 mp_max;				 //�����ֵ
	int32 mp_r;                  //�������ֵ
	int16 speed;                 //�ƶ��ٶ�
	int32 armor;                 //����
	int16 phy_res;               //������
	int16 fire_res;              //����
	int16 cold_res;              //������
	int16 elec_res;              //�翹��
	int16 toxin_res;             //������
	int16 tough;                 //����
	int16 penetrate;             //����
	int16 thickness;             //���
	int32 crit_p;                //������
	int32 crit_hurt;             //�����˺�
	int32 accurate_p;            //��׼��
	int32 dodge_p;               //������ 
	int32 trigger_p;             //������
	int16 atk_speed_increase;    //��������
	int16 mp_efficiency;         //��Լ����
	int16 skill_duration;        //���ܳ־�
	int32 skill_power;           //����ǿ��
	int16 skill_rang;            //���ܷ�Χ
	int32 hp_ball;               //����֮��
	int32 mp_ball;               //����֮��ָ�
	int16 armor_reduce;          //��������
};

//��ɫս������
struct GS2C_PlayerFightProperty  <-
{
	int32	state;				 //״ֵ̬
	int64   hp;                  //��ǰѪ��
	int32   mp;                  //��ǰħ��ֵ

	int32 phy_dam;               //�����˺� 
    int32 fire_dam;              //���˺� 
	int32 code_dam;              //���˺�
    int32 elec_dam;              //����	
	int32 toxin_dam;             //���˺�
	int16 base_dam_increase;     //�����˺���ǿ
	int32 all_dam_increase;      //����˺�
	int32 all_dam_reduce;        //�ܵ��˺�ϵ��
	int32 atk_power;             //����ǿ�� 
	int64 hp_max;				 //���Ѫ��
	int32 hp_r;                  //�������ֵ 
	int32 hp_rp;                 //ÿ��ظ��������
	int32 by_cure_factor;        //�ܵ�����ϵ��
	int32 mp_max;				 //�����ֵ
	int32 mp_r;                  //�������ֵ
	int16 speed;                 //�ƶ��ٶ�
	int32 armor;                 //����
	int16 phy_res;               //������
	int16 fire_res;              //����
	int16 cold_res;              //������
	int16 elec_res;              //�翹��
	int16 toxin_res;             //������
	int16 tough;                 //����
	int16 penetrate;             //����
	int16 thickness;             //���
	int32 crit_p;                //������
	int32 crit_hurt;             //�����˺�
	int32 accurate_p;            //��׼��
	int32 dodge_p;               //������ 
	int32 trigger_p;             //������
	int16 atk_speed_increase;    //��������
	int16 mp_efficiency;         //��Լ����
	int16 skill_duration;        //���ܳ־�
	int32 skill_power;           //����ǿ��
	int16 skill_rang;            //���ܷ�Χ
	int32 hp_ball;               //����֮��
	int32 mp_ball;               //����֮��ָ�
	int16 armor_reduce;          //��������
};


// ���Ӽ���
struct GS2U_AddSkillList <-
{
	vector<PlayerSkillInfo> skill_list;//�ͻ��˾ݼ������ñ����������������ܣ����Ǳ�������
};
//ɾ������
struct GS2U_RemoveSkillList <-
{
	vector<int16> skill_id_list;//����ID �ͻ��˾ݼ������ñ����������������ܣ����Ǳ�������
};
//�ȼ��ı�ļ����б�
struct GS2U_LevelChangeSkillList <-
{
	vector<PlayerSkillInfo> skill_list;//�ͻ��˾ݼ������ñ����������������ܣ����Ǳ�������
};

// ���ʹ�ü���
struct C2GS_UseSkill ->
{
	int16	skillId;		// ����ID
	int16   selfPosX;       // �Լ���x����
	int16   selfPosY;		// �Լ���y����
	int16   offsetX;		// ƫ�Ƶ�x���� �ͻ��˱�����
	int16   offsetY;		// ƫ�Ƶ�y���� �ͻ��˱�����
	int64	targetId;		// Ŀ��ID���������߼��㣬Ҳ�����ǽ�ɫID
};

// ���ʹ�ü��ܹ㲥
struct GS2U_UseSkill <-
{
	int64	casterId;			// ʩ����
	int16   offsetX;			// ƫ�Ƶ�x���� �ͻ��˱�����
	int16   offsetY;			// ƫ�Ƶ�y���� �ͻ��˱�����
	int64	targetId;			// Ŀ��ID���������߼��㣬Ҳ�����ǽ�ɫID
	int16	skillId;			// ����ID 
};
// ���ʹ�ô�˲�Ƶļ��ܹ㲥
struct GS2U_UseTransferSkill <-
{
	int64	casterId;			// ʩ����
	int64	targetId;			// Ŀ��
	int16	skillId;			// ����ID 
	int16   transferDesX;       // ˲�Ƶ�Ŀ����x����,
	int16   transferDesY;       // ˲�Ƶ�Ŀ����y����, 
};

	





//֪ͨclient��սʿ��һ�ι���Ϊ��ɱ
struct  GS2C_NextAttack_Is_GongSha <-
{
	int8 reserve;//��ʹ��
}

struct RoleEffectInfo
{
	int64   castId;             //ʩ����id
	int64	targetId;           //Ŀ��id
	int32   skillDataId;        //��������id ������ЩЧ������buff,����д0
	int32	effectType;			// Ч�� 
	int64	data;				// ����Ч����Ҫ����Ŀ���λ�ã���Ϊ64λ
};



// ��ɫЧ��
struct GS2U_RoleEffect <-
{
	vector<RoleEffectInfo>		effects;
};


// ����
struct C2GS_RecoverLife_Req ->
{
	int16 recoverRuleId; 
};

struct GS2C_RecoverLife_Ret <-
{
	int16 retCode;
	int8 recoverCount;
};

// �������ȸ���
struct C2GS_HelpRecover_Req ->
{
	int64 playerID;
	int8 state;//0����ʼ��1��ֹͣ
};

struct GS2C_HelpRecover_Ret <-
{
	int8 state;//Ϊ-1ʱ��ʾ���,0Ϊ�ɹ�,1������
	int64 playerID;
	int16 restTime;//ʣ�����
	int16 restPoint;//ʣ����������10000�㣩
	int8 helpNum;//���Ƚ�ɫ��Ŀ
};


// �������BUFF,���滻BUFF
struct GS2U_BufferAttach <-
{
	int64   id;      //Ψһid
	int32	buffDataId;  //����id
	int32	duration; //��λ������
	//int8    acc;  //��������
	//int32   power; //
	//int32   powerpercent;//ǧ����
};

struct GS2U_BufferRemove <-
{
	int64   id;      //buffΨһid
};

////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////

// ���������
struct GS2C_KickOut <-
{
	int32	type;
	string	desc;
};





//����л�ģʽ
//ģʽ��Ӧ��ID��0����ƽģʽ��2��ȫ��ģʽ��1�����ģʽ
struct C2GS_ChangePkState ->
{
	int64	playerID;			// ���ID
	int8	pkState;			// �л��ɵ�pkģʽ
};

// С�ˣ�����ѡ���ɫ����
struct C2GS_ReturnToSelectRoleDlg_Req ->
{
}




//�㲥ʹ��Ұ��ͻն��Ч��
//struct  GS2C_Use_SavageSuddenCut_Effect <-
//{
//}
// petʹ�ü���
struct C2GS_PetUseSkill ->
{
	int64	petID;
	int16	skillId;		// ����ID
	int16   selfPosX;       // �Լ���x����
	int16   selfPosY;		// �Լ���y����
	int16   offsetX;		// ƫ�Ƶ�x���� �ͻ��˱�����
	int16   offsetY;		// ƫ�Ƶ�y���� �ͻ��˱�����
	int64	targetId;		// Ŀ��ID���������߼��㣬Ҳ�����ǽ�ɫID
};




struct skill_shortcut_config
{
	int8 type; //0:itemId,1:skillId
	int8 index;
	int64 id;
};

struct C2GS_SkillShortCutConfig ->
{
	vector<skill_shortcut_config> vec;
};

struct GS2C_SkillShortCutConfig <-
{
	vector<skill_shortcut_config> vec;
};



// wing
struct GS2C_WingInfo<-
{
	vector<int32> wingIdVec;
	int32 equipWingId;
};

// �л�wing
struct C2GS_SummonWing ->
{
	int32	wingId;
};
// �л��ɹ�ʱ��֪ͨclient���swing
// ��ʧ�ܻ�ͨ�����õ��ı�֪ͨclient
struct GS2C_AddWing <-
{
	int32	wingId;
};

struct C2GS_EquipWing ->
{
	int32	wingId;
};
struct C2GS_UnEquipWing ->
{
	int32	wingId;
};

// upgrade wing
struct C2GS_UpgradeWing ->
{
	int32 wingId;
};
//���µ�wing�滻�ϵ�wing
struct GS2C_ReplaceWing <-
{
	int32 oldWingId;
	int32 newWingId;
};

// ���ս�������Ըı���Ϣ
struct GS2C_PlayerFightingCapacityChange  <-
{
	int8	eventId;	//���Զ�Ӧ�����ĸ�����
	int32	value;		//��Ӧ���Ե�ֵ
};

//-----------------------ս��ϵͳ����begin---------------------------
struct hallTech
{
	int16 id;
	int8 lv;
	int32 nextLvTime;//�����¼���ʱ�����0��ʾ��������״̬
};

struct GS2C_HallTechOpenList <-
{
	vector<hallTech> openList;
};

struct C2GS_HallTechLvUp_Req ->
{
	int16 id;
};

struct GS2C_HallTechLvUp_Ret <-
{
	int8 retCode;//-1:�����У�-2���Ѿ����ȼ���-3���������㣬-4��Ǯ���㣬-5���ϲ��㣬0: �ɹ�  
	int16 id;
	int32 nextLvTime;
};

struct GS2C_HallTechLvUp <-
{
	int16 id;
	int8 lv;
};
//-----------------------ս��ϵͳ����over---------------------------




