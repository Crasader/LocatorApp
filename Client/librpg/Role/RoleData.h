#ifndef __RoleData_h_
#define __RoleData_h_

#include "RoleStatus.h"

// ��ɫְҵ����
enum RoleCareer
{
	RoleCareer_None = 0,        //��ְҵ
	RoleCareer_DunWei = 1,      //����
	RoleCareer_QiangShen,       //ǹ��
	RoleCareer_JianXian,        //����
	RoleCareer_JiGuanShi,       //����ʦ
	RoleCareer_Max,				//�������
};

// ��ɫ��Ӫ��ϵ
enum RoleCamp
{
	RoleCamp_None,
	RoleCamp_Player,
	RoleCamp_Red,
	RoleCamp_Blue,
};

enum RoleProperty
{
	//////////////////////////////////////////////////////////////////////////
	// ������ս������
	//////////////////////////////////////////////////////////////////////////
	RoleProperty_None,
	RoleProperty_phy_dam,    //�����˺�
	RoleProperty_fire_dam,    //���˺�
	RoleProperty_cold_dam,    //���˺�
	RoleProperty_elec_dam,    //���˺�
	RoleProperty_toxin_dam,    //���˺�
	RoleProperty_base_dam_increase,    //�����˺���ǿ
	RoleProperty_all_dam_increase,    //����˺�ϵ��
	RoleProperty_all_dam_reduce,    //�ܵ��˺�ϵ��
	RoleProperty_atk_power,    //����ǿ��
	RoleProperty_hp_max,    //�������ֵ
	RoleProperty_hp_r,    //�������ֵ
	RoleProperty_hp_rp,    //������ر�
	RoleProperty_by_cure_factor,    //�ܵ�����ϵ��
	RoleProperty_mp_max,    //�����ֵ
	RoleProperty_mp_r,    //�������ֵ
	RoleProperty_speed,    //�ƶ��ٶ�
	RoleProperty_armor,    //����
	RoleProperty_phy_res,    //������
	RoleProperty_fire_res,    //����
	RoleProperty_cold_res,    //������
	RoleProperty_elec_res,    //�翹��
	RoleProperty_toxin_res,    //������
	RoleProperty_tough,    //����
	RoleProperty_penetrate,    //����
	RoleProperty_thickness,    //���
	RoleProperty_crit,    //������
	RoleProperty_crit_dam_factor,    //�����˺�ϵ��
	RoleProperty_accurate,    //��׼��
	RoleProperty_dodge,    //������
	RoleProperty_trigger,    //������
	RoleProperty_atk_speed_increase,    //��������
	RoleProperty_mp_efficiency,    //��Լ����
	RoleProperty_skill_duration,    //���ܳ־�
	RoleProperty_skill_power,    //����ǿ��
	RoleProperty_skill_range,    //���ܷ�Χ
	RoleProperty_hp_ball,    //Ѫ���Ѫ��
	RoleProperty_mp_ball,    //����ط�����
	RoleProperty_armor_reduce,    //��������
	RoleProperty_Fight_Max,						// ս���������ֵ
	//////////////////////////////////////////////////////////////////////////
	// �����ǻ�������
	//////////////////////////////////////////////////////////////////////////
	RoleProperty_Name = 1000,	// ��ɫ����
	RoleProperty_Career,		// ְҵ
	RoleProperty_Sex,			// �Ա�
	RoleProperty_Level,			//
	RoleProperty_Lucky,			// ����ֵ
	RoleProperty_Camp,			// ��Ӫ
	RoleProperty_Weapon,               //%��� ����װ��
	RoleProperty_Cloth,                //%��� �·� 
	RoleProperty_Wing,                 //%��� ���
	RoleProperty_HP,                   //%��ǰѪ��
	RoleProperty_MP,                   //%��ǰħ��ֵ
	RoleProperty_Exp,                  //%����
	RoleProperty_Coin,                //%���
	RoleProperty_Coin_b,              //%��Ұ�
	RoleProperty_Treasure,            //%Ԫ��
	RoleProperty_Treasure_b,          //%Ԫ����
	RoleProperty_GuildID,			   //%����ID
	RoleProperty_StateFlag,			   //%״ֵ̬
	RoleProperty_Reputation,			// ����	
	RoleProperty_VipLevel,				// VIP�ȼ�
	RoleProperty_FightValue,			// ս����
	RoleProperty_Achievement,			// �ɾ�
	RoleProperty_ManufactureSize,       // ��������ߴ�С
	RoleProperty_RecoverCount,			// �Ѿ���Ѹ������ 0 1 2
	/************************************************/

	RoleProperty_Max// �������ǰ�棡����
};

class RoleData
{
public:
	RoleData();
	virtual ~RoleData(){}

	inline string&	GetName(){ return name; }
	inline int		GetSpeed(){ return speed; }
	inline int		GetStateFlag(){ return stateFlag; }
	inline int		GetRecoverCount(){return m_recoverCount;}
	inline void		SetName(const string& val){ name = val; }
	inline void		SetSpeed(int val){ speed = val; }
	inline void		SetStateFlag(RoleStatus val){ stateFlag = val; }
	inline bool		HasStateFlag(RoleStatus val){ return (stateFlag & (1<<val)) != 0; }
	inline void		AddStateFlag(RoleStatus val){ stateFlag |= (1<<val); }
	inline void		ClrStateFlag(RoleStatus val){ stateFlag &= ~(1<<val); }

	virtual void SetProperty(RoleProperty idx,__int64 val);
	virtual void SetProperty(RoleProperty idx,int val);
	virtual void SetProperty(RoleProperty idx,const string& val);

	virtual void GetProperty(RoleProperty idx,__int64& val);
	virtual void GetProperty(RoleProperty idx,int& val);
	virtual void GetProperty(RoleProperty idx,string& val);

protected:
	string	name;			// ����
	int		speed;			// �ƶ��ٶ�
	int		stateFlag;		// ״̬��־
	int		career;			// ְҵ
	int		sex;			// �Ա�
	int		level;			// �ȼ�
	int		weapon;			// �������
	int		cloth;			// �·����
	int		wing;			// ������
	int		m_recoverCount;			// �Ѿ���Ѹ������ 0 1 2
	int		m_lastRecoverTime;		// �ϴθ���ʱ��
};

class RoleFighterData : public RoleData
{
public:
	RoleFighterData();
	virtual ~RoleFighterData();

	virtual void SetProperty(RoleProperty idx,__int64 val);
	virtual void SetProperty(RoleProperty idx,int val);
	virtual void SetProperty(RoleProperty idx,const string& val);

	virtual void GetProperty(RoleProperty idx,__int64& val);
	virtual void GetProperty(RoleProperty idx,int& val);
	virtual void GetProperty(RoleProperty idx,string& val);

protected:
	__int64		hp;			// ��ǰѪ��
	int			mp;			// ��ǰħ����
	int			camp;		// ��Ӫ
	int			fightValue;		// ս����
	__int64		fight_array[RoleProperty_Fight_Max];	// ս�������б�
};

class NpcData : public RoleData
{
public:
	void SetProperty(RoleProperty idx,__int64 val);
	void SetProperty(RoleProperty idx,int val);
	void SetProperty(RoleProperty idx,const string& val);

	void GetProperty(RoleProperty idx,__int64& val);
	void GetProperty(RoleProperty idx,int& val);
	void GetProperty(RoleProperty idx,string& val);
};

class MonsterData : public RoleFighterData
{
public:
	MonsterData(){}
	~MonsterData(){}

	virtual void SetProperty(RoleProperty idx,__int64 val);
	virtual void SetProperty(RoleProperty idx,int val);
	virtual void SetProperty(RoleProperty idx,const string& val);

	virtual void GetProperty(RoleProperty idx,__int64& val);
	virtual void GetProperty(RoleProperty idx,int& val);
	virtual void GetProperty(RoleProperty idx,string& val);
};

class PetData : public RoleFighterData
{
public:
	PetData(){}
	~PetData(){}

	virtual void SetProperty(RoleProperty idx,__int64 val);
	virtual void SetProperty(RoleProperty idx,int val);
	virtual void SetProperty(RoleProperty idx,const string& val);

	virtual void GetProperty(RoleProperty idx,__int64& val);
	virtual void GetProperty(RoleProperty idx,int& val);
	virtual void GetProperty(RoleProperty idx,string& val);
};

class PlayerData : public RoleFighterData
{
public:
	PlayerData() : vipLevel(0),guildID(0){}
	virtual ~PlayerData(){}

	void SetProperty(RoleProperty idx,__int64 val);
	void SetProperty(RoleProperty idx,int val);
	void SetProperty(RoleProperty idx,const string& val);

	void GetProperty(RoleProperty idx,__int64& val);
	void GetProperty(RoleProperty idx,int& val);
	void GetProperty(RoleProperty idx,string& val);

protected:
	int			vipLevel;			// VIP�ȼ�
	int			achievement;		// �ɾ�
	__int64		guildID;			// ����ID
};

class HeroData : public PlayerData
{
public:
	HeroData() : lucky(0),exp(0),money(0),money_b(0),gold(0),gold_b(0),reputation(0){}
	~HeroData(){}

 	void SetProperty(RoleProperty idx,__int64 val);
 	void SetProperty(RoleProperty idx,int val);
 	void SetProperty(RoleProperty idx,const string& val);
 
 	void GetProperty(RoleProperty idx,__int64& val);
 	void GetProperty(RoleProperty idx,int& val);
 	void GetProperty(RoleProperty idx,string& val);

private:
	int			lucky;			// ����
	__int64		exp;			// ����
	__int64	    money;			// ���
	__int64		money_b;		// �󶨽��
	int			gold;			// Ԫ�� 
	int			gold_b;			// ��Ԫ��
	int			reputation;		// ����
	int16       manufactureSize;// ����������
};

#endif //__RoleData_h_