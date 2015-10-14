

struct EquipTianshuDetail
{
	int8	solt;			// ���鲿λ��0-8,0Ϊ����λ�ã�
	int32	tianShuDataId;	// ����data_id
	int32	tianShuLv;		// ����ȼ�
}
//������Ϣ
struct EquipTianshu
{
	int8 index;//���úţ�1-3��
	vector<EquipTianshuDetail> tianShuList;	// ����
}

struct TianshuSoltStreng
{
	int8	solt;
	int8	strengLv;
}

//װ���Ļ�������
struct EquipItem
{
	int8	part;			// װ����λ 
	int64	id;				// 
	int8	isBind;			//
	int32	equipDataId;	// װ��������id
	int8  refineLevel;         // �����ȼ�
	int8  enhanceLevel;        //���׵ȼ�
	int32   score;  //װ������
	vector<EquipTianshu> tianShuList;	// ����
	int8 content_lv;//�����ȼ�
	vector<TianshuSoltStreng> soltStrengList;	// ����λ��ǿ����Ϣ
	int8 tian_shu_use_index;//����ʹ��������
};

//��ȡ��ҵ�װ����Ϣ
struct GS2C_EquipGetItem_Ret<-
{
	vector<EquipItem> equipItems;
}

//װ�� ����װ��
struct C2GS_EquipItem->
{
	int16 index;	//�����ڱ����е�index
	int8 part;		//װ�����Ĳ�λ
}

//����
struct C2GS_UnequipItem->
{
	int8 part;//װ�����Ĳ�λ
}

//���� or ���µ��¼���������յ����޸�װ���ͱ����������
struct GS2C_EquipExchangeRet<-
{
	int8	isEquip;	//1:����װ�� 0:����;
	int8	part;		//װ�����Ĳ�λ or ���µĲ�λ
	int16	index;		//Ҫװ���ڱ����е�index��or ����װ���󣬷ŵ���������һ����
}

struct C2GS_BagGetItems->
{
	int8 bagType;//1:װ������  2:���ﱳ�� 3: ���ϱ��� 4:ͼֽ����
};

struct TianShuSet
{
	int64 id;				//���ߵ�Ψһid
	int64 type;//װ�����ͣ�0������1װ��,����Ϊ����id
	int8 index;//���úţ�1-3��
}

struct BagItem
{
	int16 index;			//�����еĸ���λ�ã���0��ʼ
	int64 id;				//���ߵ�Ψһid
	int32 itemDataId;		//���ߵ�����id
	int16 count;			//��Ӧ������ĵ��������ı�Ϊ��ֵ
	int8 isBind;			//0��ʾ���󶨣�1��ʾ��
	int8 strengthenLevel;	//ǿ���ȼ�
	int8  refineLevel;      // �����ȼ�
	int8  enhanceLevel;     //���׵ȼ�
	int32   score;  //װ������
	vector<EquipTianshu> tianShuList;	// ����
	int8 content_lv;//�����ȼ�
	vector<TianshuSoltStreng> soltStrengList;	// ����λ��ǿ����Ϣ
	int16 tian_shu_exp;
	vector<TianShuSet> tian_shu_set_list;
};

//��ȡ�����е��ߵ���Ϣ
struct GS2C_BagGetItems_Ret<-
{
	int8	bagType;		//1:װ������  2:���ﱳ�� 3: ���ϱ��� 4:ͼֽ����
	int16	bagGridNum;		//������������
	vector<BagItem> getBagItems;
};

//������,���ӵ���
struct GS2C_BagAddItem<-
{
	int8 bagType;//1:װ������  2:���ﱳ�� 3: ���ϱ��� 4:ͼֽ����
	int8 reason;
	BagItem addItem;
};
//������,ĳ��������ĵ������������仯
struct GS2C_ItemCntChange<-
{
	int8  bagType;//1:װ������  2:���ﱳ�� 3: ���ϱ���
	int16 index;//�����еĸ���λ�ã���0��ʼ
	int16  newCount;
	int16  oldCount;
};

//������,ɾ������
struct GSWithC_BagDeleteItems<->
{
	int8 bagType;//1:װ������  2:���ﱳ�� 3: ���ϱ��� 4:ͼֽ����
	vector<int16> indexs;//�����еĸ���λ�ã���0��ʼ
};


struct GSWithC_ExchangeBagItem <->
{
	int8 bagType;//1:װ������  2:���ﱳ�� 3: ���ϱ��� 4:ͼֽ����
	int8 index1;
	int8 index2;
}

//������
struct C2GS_BagSort ->
{
	int8 bagType;//1:װ������  2:���ﱳ�� 3: ���ϱ��� 4:ͼֽ����
};

struct GS2C_SignalItemInfo <-
{
	int64 id;				//���ߵ�Ψһid
	int32 itemDataId;		//���ߵ�����id
	int16 count;			//��Ӧ������ĵ��������ı�Ϊ��ֵ
	int8 isBind;			//0��ʾ���󶨣�1��ʾ��
	int8  refineLevel;         // �����ȼ�
	int8  enhanceLevel;        //���׵ȼ�
	int32 score; //װ������
};

struct Mail_Info
{
	int64 mailId;
	int32 mailSendTime;
	int32 mailReadState; //0δ�� 1�Ѷ� 2����ȡ
	int8  mailType;
	string mailSendName;
	string mailTitle;
	string mailContent;
	int32 money;
	vector<GS2C_SignalItemInfo> vec;
};

struct GS2C_All_Mail_Info <-
{
	vector<Mail_Info> vec;
};

struct GS2C_Send_Mail <-
{
	Mail_Info st;
};

// GS֪ͨ�ͻ���������Ϣ
struct GS2C_Chat <-
{
	int8	channelId;  //Ƶ��, (�磺ChannelType_World)
	int8    isVip;      //�������Ƿ���vip, 1:��vip�û�, 0:����vip�û�
	int64	senderId;   //������id
	string	senderName; //����������
	string	message;    //��Ϣ
	vector<GS2C_SignalItemInfo> vec; //��Ʒ������Ϣ
};

struct C2GS_LookOverPlayerEquip ->
{
	int64 playerId;
};

struct GS2C_LookOverPlayerEquip_Result <-
{
	int8 retCode;
	int64	playerId;
	string	playerName;
	string	leagueName;
	int16	level;
	int8	career;
	int8	sex;
	int32 	weapon;
	int32	armor;
	int32	wing;
	vector<EquipItem> equipItems;
};

struct EquipId
{
	int64 equipId;
	int32 cnt;
};







// ѡ��ڼ��ſ���(������)
struct C2GS_SelectEquipCompose ->
{
	int8 equipComposeOrder; //��ȡ�ڼ����ںϵĽ��
};

struct GS2C_SelectEquipCompose <-
{
	int8 retCode; //1:�ɹ�, -1:��ʯ������ʧ��
};

// ȷ�ϵڼ��ſ���(ѡ��ڼ����ںϵĽ��)
struct C2GS_ConfirmEquipComposeOrder ->
{
	int8 equipComposeOrder;
};




struct C2GS_UseItem ->
{
	int8 bagType;
	int32 index;
	int64 itemId;
};

struct GS2C_UseItem_Result <-
{
	int8 retCode; //1:�ɹ���-1ʧ��
};

struct C2GS_StartEquipStrengthen ->
{
	int64 equipId;
	int8  isUseLuckyStone; //�Ƿ�ʹ�����˷�
	int8  isAutoBuyLuckyStone; //�Ƿ��Զ��������˷�
	int8  isAutoBuyStrengthenStone; //�Ƿ��Զ�����ǿ��ʯ
	int8  isTenStrengthen; // �Ƿ�һ��10��ǿ����1Ϊ�ǣ�0Ϊ��
};

struct GS2C_StartEquipStrengthen <-
{
	int8 retCode; //1:�ɹ�
};

struct GS2C_EquipLevelChange <-
{
	int64 id;
	int32 level;
	int32 score;
};

struct GS2C_DesPlayer_LockTrade_Result <-
{
	int32 coin;
	vector<GS2C_SignalItemInfo> vec;
};

struct GS2C_InputItem_Result <-
{
	int32 coin;
	vector<GS2C_SignalItemInfo> vec;
};

struct C2GS_SetBagGrid ->
{
	int8 bagType;
};

struct GS2C_SetBagGrid <-
{
	int8 bagType;
	int32 newNum;
	int8 retCode; //-1: �����Ѿ��ﵽ���ֵ, -2:���ƴ���, -3:��Ǯ����, 1:�ɹ�
};

struct C2GS_SplitItem ->
{
	int8 bagType;  //��������
	int32 itemCnt; //�������Ʒ������
	int64 itemId;  //�������Ʒ
	int32 splitItemCnt; //��ֳ�����Ʒ������
};

struct GS2C_SplitItem <-
{
	int8 retCode; //-1: ��Ʒ������, -2:��������2���ܲ��, -3:�����������С����Ʒ��ǰ����, -4:��������, 1:�ɹ�
};

// -define(TipType_Personal, 1). %%����
// -define(TipType_World, 2). %%����
// -define(TipType_Guild, 3). %%����
// -define(TipType_Team, 4). %%����
// -define(TipType_Map, 5). %%ͬһ�ŵ�ͼ
// GS֪ͨ�ͻ���ϵͳ��Ϣ
struct GS2C_Tip_Msg <-
{
	int32   tipId; //
	string	args;//�Զ���Ϊ�ָ�����������string
	vector<GS2C_SignalItemInfo> vec;
};

struct C2GS_DropItem ->
{
	int8 bagType;
	int32 index;
	int64 itemId;
};

struct GS2C_Sale_PutOnItem_Result <-
{
	int8 retCode; //1:�ɹ�, -1: ��Ʒ����, -2:δ�ҵ����۵�npc, -3:npc����̫Զ, -4:�����Ѿ��ﵽ����, -5:���Ѽ�����Ʒ�Ѿ��ﵽ����
	int64 saleId;
	GS2C_SignalItemInfo saleItem;
};

struct sale_filter_item
{
	int32 price;
	int64 saleId;
	GS2C_SignalItemInfo saleItem;
};

struct GS2C_Sale_Filter_Item_Result <-
{
	int8 isNextPage;
	int32 totalPage;
	vector<sale_filter_item> saleVec;
};

struct GS2C_Sale_Find_Item_Result <-
{
	int8 isNextPage;
	int32 totalPage;
	vector<sale_filter_item> saleVec;
};

struct my_sale_item
{
	int32 price;
	int32 remainTime;
	int64 saleId;
	GS2C_SignalItemInfo saleItem;
};

struct my_sale_gold
{
	int32 price;
	int32 remainTime;
	int64 saleId;
	int32 goldType;
};

//�ҵļ���
struct GS2C_Sale_My_Sale_Item <-
{
	vector<my_sale_item> mySaleVec;
};

struct GS2C_Sale_My_Sale_Gold <-
{
	vector<my_sale_gold> mySaleVec;
};

struct GS2C_SubmitTaskChain <-
{
	//1:�ɹ�, -1:npc������, -2:������δ��ȡ, -3:��ҵȼ�����, -4:��npc����̫Զ, -5:��������
	int8  retCode;
	int16 taskChainCnt; //����(�ڼ���, ��1��ʼ)
	int16 loopCnt; //����(һ����������200������, ��1��ʼ)
	int32 startNpcDataId;
	int32 endNpcDataId;
	int32 taskId;
	int32 exp;
	int32 coin;
	int32 bindCoin;
	int32 honor;
	vector<GS2C_SignalItemInfo> awardItem; //�̶�����
	vector<GS2C_SignalItemInfo> awardRandItem; //�������
};

struct taskChainProgress
{
	int8 targetType; //Ŀ������
	int32 targetCnt; //�����ļ�����Ҫ��ɵ�����
	int32 curCnt; //��ǰ��ɵ�����
};

//����ʱ�·����Ѿ���ȡ������(������)
struct GS2C_AcceptedTaskChain <-
{
	int32 taskId; //����id
	int32 startNpcDataId;
	int32 endNpcDataId;	
	int16 taskChainCnt; //����(�ڼ���, ��1��ʼ)
	int16 loopCnt; //����(һ����������200������, ��1��ʼ)	
	vector<taskChainProgress> progress;
	int32 exp;
	int32 coin;
	int32 bindCoin;
	int32 honor;
	vector<GS2C_SignalItemInfo> awardItem; //�̶�����
	vector<GS2C_SignalItemInfo> awardRandItem; //�������	
};

//������Ƕ
struct C2GS_TianShuSet_Req ->
{
	int8 index;//���úţ�1-3��
	int64 type;//װ�����ͣ�0������1װ��,����Ϊ����id
	int8 solt;//������Ƕλ�ã�0-8,0Ϊ����λ�ã�
	int16 bag_index;//���鱳��λ��
};

struct GS2C_TianShuSet_Ret <-
{
	int8 retCode; //-1: ϵͳ����, 1:�ɹ�
	int64 type;//װ�����ͣ�0������1װ��,����Ϊ����id
	vector<EquipTianshu> tianShuList;	// ����
	BagItem newTianShu;
};

//�������
struct GS2C_TianShuUpate <-
{
	BagItem newTianShu;
};

//װ��������Ϣ�仯����
struct GS2C_EquipTianShuUpate <-
{
	EquipItem newEquip;
};

//ȡ������
struct C2GS_TianShuTakeOff_Req ->
{
	int8 index;//���úţ�1-3��
	int64 type;//װ�����ͣ�0������1װ��,����Ϊ����id
	int8 solt;//����λ��
};

struct GS2C_TianShuTakeOff_Ret <-
{
	int8 retCode; //-1: ���ز���ȡ��, 1:�ɹ�
	int64 type;//װ�����ͣ�0������1װ��,����Ϊ����id
	vector<EquipTianshu> tianShuList;	// ����
};

struct tian_shu_material
{
	int16 index;//���鱳��λ��
	int16 count;//��������
};

//��������
struct C2GS_TianShuLvUp_Req ->
{
	int16 index;//�������鱳��λ��
	vector<tian_shu_material> materialList;//�������鱳��λ��
};

struct GS2C_TianShuLvUp_Ret <-
{
	int8 retCode; //-1: ������������,-2:�Ѿ������ȼ�,-3:��Ǯ���� 1:�ɹ�
	int8 newLv;
	int16 newExp;
};

//����ϳ�
struct C2GS_TianShuCompose_Req ->
{
	vector<tian_shu_material> materialList;//�������鱳��λ��
};

struct GS2C_TianShuCompose_Ret <-
{
	int8 retCode; //-1: ��Ǯ����, 1:�ɹ�
	int16 itemDataId;
};

//װ����������ǿ��
struct C2GS_TianShuEquipContentLvUp_Req ->
{
	int64 type;//װ�����ͣ�0������1װ��,����Ϊ����id
};

struct GS2C_TianShuEquipContentLvUp_Ret <-
{
	int8 retCode; //-2: ��Ǯ���㣬-1���ϲ��㣬1:�ɹ�
	int64 type;//װ�����ͣ�0������1װ��,����Ϊ����id
};

//װ�������λǿ��
struct C2GS_TianShuEquipSoltLvUp_Req ->
{
	int64 type;//װ�����ͣ�0������1װ��,����Ϊ����id
	int8 solt;//����λ�ã�0-8,0Ϊ����λ�ã�
};

struct GS2C_TianShuEquipSoltLvUp_Ret <-
{
	int8 retCode; //-2: ��Ǯ���㣬-1���ϲ��㣬1:�ɹ�
	int64 type;//װ�����ͣ�0������1װ��,����Ϊ����id
	int8 solt;//����λ�ã�0-8,0Ϊ����λ�ã�
};

//�����л�ҳ��
struct GS2C_TianShuChangeIndex_Req ->
{
	int64 type;//װ�����ͣ�0������1װ��,����Ϊ����id
	int8 index;
};

struct C2GS_TianShuChangeIndex_Ret <-
{
	int8 retCode; //1:�ɹ�
	int64 type;//װ�����ͣ�0������1װ��,����Ϊ����id
	int8 index;
};

//�����л�λ��
struct GS2C_TianShuChangeSolt_Req ->
{
	int64 type;//װ�����ͣ�0������1װ��,����Ϊ����id
	int8 index;
	int8 solt;//����λ�ã�1-8��
	int8 newsolt;//������λ�ã�1-8��
};

struct C2GS_TianShuChangeSolt_Ret <-
{
	int8 retCode; //1:�ɹ�
	int64 type;//װ�����ͣ�0������1װ��,����Ϊ����id
	int8 index;
	int8 solt;//����λ�ã�1-8��
	int8 newsolt;//������λ�ã�1-8��
};

struct PlayerGodDevice
{
	int8 isDress;   //1:��ǰ����������,0����
	int32 godDeviceCfgId; //��������id
	int8  refineLevel;         // �����ȼ�
	int8  enhanceLevel;        //���׵ȼ�
	int64 equipId; //�����󶨵�װ��id
	vector<EquipTianshu> tianShuList;	// ����
	int8 content_lv;//�����ȼ�
	vector<TianshuSoltStreng> soltStrengList;	// ����λ��ǿ����Ϣ
	int8 tian_shu_use_index;//����ʹ��������
};

struct GS2C_PlayerGodDeviceList<-
{
	vector<PlayerGodDevice>  playerGodDeviceList;
};


//������һ������
struct C2GS_GainGodDevice->
{
	int16 godDeviceCfgId;
};

struct GS2C_GainGodDevice_Ret <-
{   
	int8 errorCode;  //0 �ɹ�,������
	vector<PlayerGodDevice> playerGainGodDevice;
};

//�����л�����
struct C2GS_ChangeGodDevice->
{
	int8 index;         //�������б��е��±�
};

struct GS2C_ChangeGodDevice_Ret <-
{
	int8 errorCode;     //0 �ɹ�������ʧ��
	int8 oldIndex;      //���滻�µ������±�
	int8 newIndex;      //�»��ϵ������±�
};

//����һ������,����Ƕ
struct GS2C_UpdateGodDevice_Ret<-
{
	PlayerGodDevice playerGodDevice;
};


//װ������������
struct C2GS_Enhance ->
{
	int8 type;      //1 ����,  2 װ��
	int64 equipId;       //�����װ����Ϊװ��id,�����͸���0��Ĭ��ֵ
};

struct GS2C_Enhance_Ret <-
{
	int8 type;     //1 ����,  2 װ��
	int64 equipId;
	int8 inWhere; //1 ����, 2 ��ɫ����
	int8 enhanceLevel;  //��ǰ���׵ȼ�
};


//װ������
struct C2GS_Refine ->
{
	int8 type;      //1 ����,  2 װ��
	int64 equipId;       //�����װ����Ϊװ��id,�����͸���0��Ĭ��ֵ
	int8 isRefineMaxLevel;//�Ƿ��������ȼ� 1:���������ȼ�, 0 ֻ����һ��
};

struct C2GS_Refine_All ->
{
	
};

struct PlayerRefine
{
	int8 type; //1 ����,  2 װ��
	int64 equipId;
	int8 inWhere; //1 ����, 2 ��ɫ����
	int8 refineLevel;
}

struct GS2C_Refine_Ret <-
{
	int16 errorCode;
	vector<PlayerRefine> playerRefineList;
};

//����ϵͳ
struct Manufacture_Element
{
	int32 itemDataId;     //����������id
	int8 eliminateCdFlag; //�Ƿ�������cd, 0 û��, 1 ʹ�ù�
	int32 remainSeconds; //ʣ��ʱ��, ��Ϊ��λ
	int8 isDone;          // 1 ���, 0 δ��� 
};

//�����б�
struct GS2C_ManufactureList_Ret <-
{
	vector<Manufacture_Element> manufactureList;
};

//�����µ����쵥Ԫ
struct C2GS_New_Manufacture_Element ->
{
	int32 itemDataId;     //����������id
};

//�ظ�������
struct GS2C_New_Manufacture_Element_Ret <-
{
	int16 errorCode;      // 0 ��ȷ,>0 ����ʾ����
	Manufacture_Element manufactureElement;
}

//��������cd
struct C2GS_Eliminate_Cd ->
{
	int32 itemDataId;
};
//�ظ�����cd
struct GS2C_Eliminate_Cd_Ret <-
{
	int16 errorCode;
	Manufacture_Element manufactureElement;
}
//�����ȡ�Ѿ���ɵ��������
struct C2GS_Gain_Item ->
{
	int32 itemDataId;
};

struct GS2C_Gain_Item_Ret <-
{
	int32 itemDataId;
	int16 errorCode;
};

//������Ϣ����ת�ƣ��������Э�����Զ�����ߣ�
struct FightProperty  <-
{
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

struct PetInfo
{
	int64 id;
	int32 dataId;
	int16 level;
	int32 exp;
	int16 strengLv;
	int8 isActive;//1��ս��0ι��ս
	FightProperty prop;
	vector<EquipTianshu> tianShuList;	// ����
	int8 content_lv;//�����ȼ�
	vector<TianshuSoltStreng> soltStrengList;	// ����λ��ǿ����Ϣ
	int8 tian_shu_use_index;//����ʹ��������
};

//���߻���ι��ʱ���·�
struct GS2C_AllPets  <-
{
	vector<PetInfo> pets;
};

//������Ϣ���£�������ǿ�����߻���³���ʱ���·�
struct GS2C_UpdatePetInfo  <-
{
	int64 id;
	int32 dataId;
	int16 level;
	int32 exp;
	int16 strengLv;
	int8 isActive;//1��ս��0ι��ս
	FightProperty prop;
	vector<EquipTianshu> tianShuList;	// ����
	int8 content_lv;//�����ȼ�
	vector<TianshuSoltStreng> soltStrengList;	// ����λ��ǿ����Ϣ
	int8 tian_shu_use_index;//����ʹ��������
};





