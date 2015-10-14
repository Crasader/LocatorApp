#ifndef __GameUIDef_h_
#define __GameUIDef_h_

/* 5 3 2 2 1 1*/
#define BAG_SIZE_EQUIP		(64)		//����װ��������
#define BAG_SIZE_ZAWU		(64)		//�������������
#define BAG_SIZE_MATERIAL	(64)		//�������ϸ�����
#define BAG_SIZE_TUZHI	    (64)		//����ͼֽ������
#define BAG_SIZE_TIANSHU	(64)		//�������������
#define GRIDS_SIZE_MAILSEND (4)			//�ʼ�������
#define GRIDS_SIZE_FURNACECOMPOUND (3)	//װ���ϳɸ�����
#define GRIDS_SIZE_ROLE		(11)		//��ɫװ��������
#define GRIDS_SIZE_TASK		(5)			//���������
#define GRIDS_SIZE_TRADE	(5)			//���׸�����
#define GRIDS_SIZE_SALEBANK_PROP	(5) //���۵���
#define GRIDS_SIZE_SALEBANK_MINE	(5) //���۵���
#define GRIDS_SIZE_SALEBANK_GOLD	(10)//����Ԫ��

#define BAG_SIZE_EQUIPACTIVE	(32)
#define BAG_SIZE_ZAWUACTIVE		(16)
#define BAG_SIZE_MATERIALACTIVE	(16)

#define	BAG_PAGE_SIZE				(16)
#define MAX_PAGE_SIZE				(5)
#define Page_Size_CopyCheckOut		(10)

enum emGridsType
{
	emGrids_None,
	emGrids_BagEquip,
	emGrids_BagZaWu,
	emGrids_BagMaterial,
	emGrids_BagTuZi,
	emGrids_BagBook,
	emGrids_Role,
	emGrids_StrengthMaterial,
	emGrids_TaskAward,
	emGrids_BagEquipRole, //add Tangbo  ��Ҫ��������װ������
	emGrids_CopyCheckout, //��������
	emGrids_Count	// ���ڴ���ǰ�棡����
};

enum emGUIS{
	GUIS_NONE,
	GUIS_SHOW,
	GUIS_OPEN,
	GUIS_CLOSED,
};

//���ӱ��
#define GRIDICON_TAG	(1)

//ui��Ʒֱ���
#define GAME_UI_ORIG_SIZE Size(1920, 1080)	//old
#define UI_ORIG_SIZE Size(1334, 750)	//new

/************************************************************************/
/* ui json �ļ�·��                                                     */
/************************************************************************/
#define JSONFILE_LOGIN				"assets/ui/LoginUI.json"
#define JSONFILE_MESSAGEBOXUI		"assets/ui/MessageBoxUI.json"
#define JSONFILE_CHATMAINUI			"assets/ui/ChatMainUI.json"
#define JSONFILE_CTeamUI				"assets/ui/CTeamUI.json"
#define JSONFILE_TEAMAPPLICATION	"assets/ui/TeamApplicationList.json"
#define JSONFILE_NPCDIALOG			"assets/ui/NpcDialog.json"
#define JSONFILE_TASKUI				"assets/ui/TaskUI.json"
#define JSONFILE_TASKDIALOG			"assets/ui/TaskDialog.json"
#define JSONFILE_RELIVE				"assets/ui/Revive.json"
#define JSONFILE_SERVERLIST			"assets/ui/SelectServerUI.json"
#define JSONFILE_CREATEPLAYER		"assets/ui/CreateHeroUI.json"
#define JSONFILE_SELECTPLAYER		"assets/ui/SelectHeroUI.json"
#define JsonFile_MainUINormal		"assets/ui/MainUINormal.json"
#define JsonFile_MainUIFight		"assets/ui/MainUIFight.json"
#define JsonFile_FightPause			"assets/ui/FightPause.json"
#define JsonFile_HeroInfo			"assets/ui/HeroInfo.json"
#define JsonFile_Social				"assets/ui/SocialUI.json"
#define JsonFile_WaveEnd			"assets/ui/CopyWaveEnd.json"
#define JsonFile_CopyEnd			"assets/ui/CopyEnd.json"
#define JsonFile_MailUI				"assets/ui/MailUI.json"
#define JSONFILE_WORLDMAPUI			"assets/ui/WorldMap.json"
#define JSONFILE_LOADUI             "assets/ui/LoadingUI.json"
#define JSONFILE_DRAMAUI            "assets/ui/DramaUI.json"
#define JSONFILE_FRIENDUI			"assets/ui/FriendsUI.json"
#define JSONFILE_FRICHILD			"assets/ui/ChildNode.json"
#define JSONFILE_ROLEATTRI          "assets/ui/RoleAttriUI.json"
#define JSONFILE_ROLEPACKAGE        "assets/ui/RolePackageUI.json"
#define JSONFILE_ROLEEATTRICHILD    "assets/ui/DetailChild.json"
#define JsonFile_MissionUI			"assets/ui/MissionUI.json"
#define JsonFile_SkyBookUI          "assets/ui/SkyBookUI.json"
#define JsonFile_SkyBookCalcUI      "assets/ui/SkyBookCalcUI.json"
#define JsonFile_GodDeviceUI		"assets/ui/GodDeviceUI.json"
#define JsonFile_StrengthenUI		"assets/ui/StrengthenUI.json"
#define JsonFile_ManufactureUI      "assets/ui/ManufactureUI.json"
#define JsonFile_ManufactureJiDuUI  "assets/ui/ManufactureJuDuTipsUI.json"
#define JsonFile_ManufactureMaterial "assets/ui/ManufactureMaterialTipsUI.json"
#define JsonFile_OneStrokeUI		"assets/ui/OneStroke.json"
#define JsonFile_OpenLockUI			"assets/ui/OpenLock.json"
#define JsonFile_ReviveUI			"assets/ui/ReviveUI.json"
#define JsonFile_ItemTipsUI         "assets/ui/ItemTipsUI.json"
#define JsonFile_HallTechUI			"assets/ui/HallTechUI.json"
#define JsonFile_HallTechTreeUI		"assets/ui/HallTechTreeUI.json"
#define JsonFile_AddLegionUI        "assets/ui/AddLegionUI.json"
#define JsonFile_LegionUI           "assets/ui/LegionUI.json"
#define JsonFile_FreeFightScoreUI	"assets/ui/FreeFightScore.json"
#define JsonFile_FreeFightCheckOut	"assets/ui/FreeFightCheckOut.json"

//��������Start
#define JsonFile_CopyCommon				"assets/ui/CopyCommon.json"				//ͨ�ø���
#define JsonFile_CopyDefUI				"assets/ui/CopyDef.json"				//�ػ�����
#define JsonFile_CopySurvive			"assets/ui/CopySurvive.json"			//���渱��
#define JsonFile_CopyContendFor			"assets/ui/CopyContendFor.json"			//���ḱ��
#define JsonFile_CopyFreeFight			"assets/ui/CopyFreeFight.json"			//����ս��
//��������End

#define JsonFile_PetUI				"assets/ui/PetUI.json"						//�������UI

enum emIDU{
	IDU_NONE = 0,
	IDU_LOGIN = 60001,			//��½����;
	IDU_CopyUIStart,
	//��������Start
	IDU_CopyCommon,				//ͨ�ø���
	IDU_CopyUIDef,				//�ػ�����
	IDU_CopyUISurvive,			//���渱��
	IDU_CopyUIContendFor,		//���ḱ��
	IDU_CopyFreeFight,			//����ս��
	//��������End
	IDU_MESSAGEBOX,				//��Ϣ��ʾ��
	IDU_REVIVEANDBACK,			//����ͻس�;
	IDU_CHATMAINUI,				//����������
	IDU_TEAMAPPLICATION,		//��������б�
	IDU_NPCDIALOG,				//NPC�Ի�;
	IDU_TASKUI,					//�������;
	IDU_TASKDIALOG,	            //����Ի�
	IDU_SERVERLIST,				//�������б�;
	IDU_CREATEPLAYER,			//������ɫ;
	IDU_SELECTPLAYER,			//ѡ���ɫ;
	IDU_MainUINormal,			//��ս��������
	IDU_MainUIFight,			//ս��������
	IDU_FightPause,				//ս����ͣ
	IDU_HeroInfo,				//Ӣ����Ϣ
	IDU_Social,					//�罻
	IDU_WaveEnd,				//����5������
	IDU_CopyEnd,				//������������
	IDU_MailUI,					//�ʼ�����  2015/8/17 ����
	IDU_WORLDMAPUI,				//��ͼ;
	IDU_Loading,				//���ؽ���
	IDU_Drama,					//�������
	IDU_Friend,					//���ѽ���
	IDU_RoleAttri,				//��ɫ���Խ���
	IDU_RolePackage,            //��ɫ��������
	IDU_MissionlUI,				//����ϵͳ����  2015/8/24 ����
	IDU_SkyBookUI,				//����ϵͳ����  2015/9/2  Tangbo
	IDU_SkyBookCalcUI,          //����������  
	IDU_GodDeviceUI,			//����ϵͳ����  2015/9/2 ����
	IDU_StrengthenUI,			//ǿ��ϵͳ����  2015/9/9 ����
	IDU_ManufactureUI,          //����ϵͳ����  
	IDU_OneStrokeUI,			//һ�ʻ�
	IDU_OpenLock,				//����
	IDU_ReviveUI,				//����
	IDU_ITEMTIPSUI,             //������ʾ����
	IDU_HallTechUI,				//ս��
	IDU_HallTechTreeUI,			//ս���Ƽ���
	IDU_AddLegionUI,            //��δ�������
	IDU_LegionUI,               //�Ѿ��������
	IDU_FreeFightScore,			//����ս���ȷ�
	IDU_FreeFightCheckOut,		//����ս������
	IDU_PetUI,					//�������
};

#endif