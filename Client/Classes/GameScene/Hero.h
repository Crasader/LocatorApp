#ifndef __Hero_h_
#define __Hero_h_

#include "Player.h"
#include "Singleton.h"
#include "Net/pk_role.h"
#include "Skill.h"
#include "Item.h"
#include "GridsManager.h"
#include "RoleBuff.h"
#include "MapItem.h"
#include "Net/pk_item.h"
#include "GodDeviceManager.h"
#include "HallTechManager.h"
#include "Net/pk_map.h"

typedef struct mySaleItem
{
	int32 price;
	int32 remainTime;
	int64 saleId;
	pk::GS2C_SignalItemInfo saleItem;
}MySaleItem;

typedef struct mySaleGold
{
	int32 price;
	int32 remainTime;
	int64 saleId;
	int32 goldType;
}MySaleGold;

class BeginnerGuide;
class CIndicatorLayer;

class CHero : public CPlayer,public Singleton<CHero>
{
public:
	static void	GetMoveCmd(int mapDataID,int cx,int cy,APath& path,pk::C2GS_PlayerMoveTo& cmd);
	static void	PathToPosInfo(int cx,int cy,APath& path,vector<pk::PosInfo>& posInfos);
	static void	PosInfoToPath(int cx,int cy,vector<pk::PosInfo>& posInfos,APath& path);

public:
	CHero();
	~CHero();

	bool initRole();
	void update(float dt);

	/* Name		��updateMove
	 * Author	��YueLiangYou
	 * Date		: 2015-07-02
	 * Desc		: �ƶ�����
	 * Param	: none
	 * Return	: true �����ƶ���false �ƶ�����
	 */
	bool updateMove(float dt);

	/* Name		��updateFlash
	 * Author	��YueLiangYou
	 * Date		: 2015-07-02
	 * Desc		: ��˸����
	 * Param	: none
	 * Return	: true ������˸��false ��˸����
	 */
	bool updateFlash(float dt);

	/* Name		��getModel
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ��ȡ��ɫչʾmodel����ָ��
	 * Param	: none
	 * Return	: RoleModel* ��ɫ����ָ��
	 */
	inline RoleModel* getModel(){ return m_pRoleModel; }

protected:
	RoleModel*	m_pRoleModel;	// ��ɫչʾModel

	// ��ɫ����
public:
	void SetProperty(RoleProperty idx,int val);
	void SetProperty(RoleProperty idx,__int64 val);
	void SetProperty(RoleProperty idx,const string& val);

	/* Name		��setProperty
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ���ý�ɫ��������
	 * Param	: value �������������Ľ�ɫ����
	 * Return	: void
	 */
	void setProperty(pk::GS2C_PlayerProperty* value);

	/* Name		��setFightProperty
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ���ý�ɫս������
	 * Param	: value �������������Ľ�ɫ����
	 * Return	: void
	 */
	void setFightProperty(pk::GS2C_PlayerFightProperty* value);

	/*��ɫ�������Ա仯*/
	void setSingleProperty(RoleProperty idx, __int64 value);

	inline __int64 GetExp(){ return GetPropertyInt64(RoleProperty_Exp); }
	inline __int64 GetMoneyBind(){ return GetPropertyInt64(RoleProperty_Coin_b); }
	inline __int64 GetMoney() { return GetPropertyInt64(RoleProperty_Coin_b); }
	inline int GetGold() { return GetPropertyInt(RoleProperty_Treasure_b); }
	inline string getHeadIcon(){ __String str; str.initWithFormat("%sCareer%d.png","assets/ui/icon/head/",GetCareer()); return str.getCString(); }

	/* Name		��SetLevel
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ���ý�ɫ�ȼ�
	 * Param	: val �ȼ�
	 * Return	: void
	 */
	void SetLevel(int val);

	/*���þ���*/
	void SetExp(__int64 val,bool tips = true);

	/*���ý�Ǯ*/
	void SetMoney(__int64 val,bool tips = true);

	/*���ð󶨽�Ǯ*/
	void SetMoneyBind(__int64 val,bool tips = true);

	/*����Ԫ��*/
	void SetGold(int val,bool tips = true);

	/*���ð�Ԫ��*/
	void SetGoldBind(int val,bool tips = true);

	/*���õ���Ѫ��*/
	void SetHP(__int64 val);

	/*�������Ѫ��*/
	void SetHPMax(__int64 val);

	/*���õ��ڷ���*/
	void SetMP(int val);

	/*���������*/
	void SetMPMax(int val);

// �ƶ����
public:
	/* Name		��setPosition
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ����Ԫ����������ϵλ��
	 * Param	: ��������x,y
	 * Return	: void
	 */
	void setPosition(float x,float y);

	/* Name		��setPosition
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ����Ԫ����������ϵλ��
	 * Param	: ��������Point& position
	 * Return	: void
	 */
	void setPosition(const Point &position);

	/* Name		��SetCell
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ���õ�ͼԪ�ص��߼�����λ��
	 * Param	: �߼�����cx,cy
	 * Return	: void
	 */
	void SetCell(int cx,int cy);

	/* Name		��MoveTo
	 * Author	��YueLiangYou
	 * Date		: 2015-07-02
	 * Desc		: �ƶ���ָ�����꣬�����ƶ�״̬
	 * Param	: cx,cy ָ���߼�����
	 * Return	: void
	 */
	void MoveTo(int cx,int cy);

	/* Name		��MoveBy
	 * Author	��YueLiangYou
	 * Date		: 2015-07-02
	 * Desc		: ��ָ���������ƶ��������ƶ�״̬
	 * Param	: dirָ������
	 * Return	: void
	 */
	void MoveBy(__Dir dir);

	/* Name		��NotifyServerStopMove
	 * Author	��YueLiangYou
	 * Date		: 2015-07-02
	 * Desc		: ֪ͨ������ֹͣ�ƶ�
	 * Param	: none
	 * Return	: void
	 */
	void NotifyServerStopMove();

	/* Name		��processCommand
	 * Author	��YueLiangYou
	 * Date		: 2015-07-02
	 * Desc		: ����ָ��
	 * Param	: none
	 * Return	: void
	 */
	void processCommand(const RoleCommand& cmd);

	/* Name		��ChangeMap
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: �л���ͼ
	 * Param	: mapID ��ͼID��cx cy ��ͼ�߼�����
	 * Return	: void
	 */
	void ChangeMap(ResID mapID,int cx,int cy);

	/* Name		��EnterMap
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ����ָ����ͼ��������
	 * Param	: pMap��ͼָ�룬pos��ͼ�е���������
	 * Return	: void
	 */
	void EnterMap(TileMap* pMap,int cx,int cy);

	/* Name		��LeaveMap
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: �뿪��ǰ��ͼ
	 * Param	: none
	 * Return	: void
	 */
	void LeaveMap();

	/* Name		��onEnterDoor
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: Ԫ�ؽ��봫���Żص�����
	 * Param	: pRegion����Ĵ�����ָ��
	 * Return	: void
	 */
	void onEnterDoor(CRegion* pRegion);

	/* Name		��IsTransfering
	 * Author	��YueLiangYou
	 * Date		: 2015-07-02
	 * Desc		: �Ƿ����ڴ��͵㴫��
	 * Param	: none
	 * Return	: true �ǣ�false ��
	 */
	inline bool IsTransfering()	{ return m_bTransDoorFlag;}

protected:
	bool	m_bTransDoorFlag;

public:

	/* Name		��searchItemByCell
	 * Author	��TangBo
	 * Date		: 2015-07-30
	 * Desc		: ���ظ�������װ��
	 * Param	: cx,cy ��ͼ�ĸ�������
	 * Return	: true �У�false ��
	 */
	bool     searchItemByCell(int cx, int cy);

	/* Name		��searchItemByCell
	 * Author	��TangBo
	 * Date		: 2015-07-30
	 * Desc		: ���ظ�������װ��
	 * Param	: cell ��ͼ�ĸ�������
	 * Return	: true �У�false ��
	 */
	bool     searchItemByCell(Point cell);

	bool TryPickupItem();
	bool IsRunningForPicking()	{return m_pPickupAction != NULL;}

	bool SelectTargetByPos(Point pos);
	void SelectTargetNearBy();
	void SelectTargetCancel();
	void SelectTarget(MapObject* pTarget);

	inline MapObject* GetSelectTarget(){ return m_pSelectTarget; }
protected:
	MapObject* m_pSelectTarget;
	CPickupItemAction *m_pPickupAction;

// װ���� ��װ
public:
	/* Name		��Equip
	 * Author	��YueLiangYou
	 * Date		: 2015-07-30
	 * Desc		: ������װ��
	 * Param	: pos ��������
	 * Return	: void
	 */
	void	Equip(int pos);

	/* Name		��UnEquip
	 * Author	��YueLiangYou
	 * Date		: 2015-07-30
	 * Desc		: ����ж��װ��
	 * Param	: type װ����ID
	 * Return	: void
	 */
	void 	UnEquip(EquipColumnType type);

	void	OnEquiped(int pos,EquipColumnType type);
	void	OnUnEquiped(int pos,EquipColumnType type);
	void	RefreshEquip();

	/* Name		��UseItem
	 * Author	��YueLiangYou
	 * Date		: 2015-07-30
	 * Desc		: ����ʹ����Ʒ
	 * Param	: pos ������������
	 * Return	: void
	 */
	void	UseItem(int pos);

	/* Name		��UseItem
	 * Author	��YueLiangYou
	 * Date		: 2015-07-30
	 * Desc		: ����ʹ����Ʒ
	 * Param	: pos ������������
	 * Return	: pItem ��Ʒָ��
	 */
	void	UseItem(CItem* pItem);

protected:
	// �ֿ�����
	//CItemGrid storage[];

	// ��������

//////////////////////////////////////////////////////////////////////////
// ��������
//////////////////////////////////////////////////////////////////////////
public:
	/* Name		��GetSkillManager
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ��ȡ��ɫ���ܹ�����
	 * Param	: none
	 * Return	: SkillManager&
	 */
	inline SkillManager& GetSkillManager(){ return m_SkillMgr; }

	/* Name		��GetSkill
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ��ȡ��ɫ����
	 * Param	: skillid ����ID
	 * Return	: Skill*
	 */
	inline CSkill* GetSkill(int skillid){ return GetSkillManager().Get(skillid); }
	inline CSkill* GetLastestSkill(){ return GetSkillManager().Last(); }
	inline CSkill* AddSkill(CSkill* pSkill){ return GetSkillManager().Insert(pSkill); }
	inline CSkill* AddSkill(int skillid){ return GetSkillManager().Insert(skillid); }

	inline void RemoveSkill(int skillid){ GetSkillManager().Remove(skillid); }
	inline void StartCd(int skillId) { return GetSkillManager().StartCd(skillId); }
	inline void UpdateSkillCd(float dt){ GetSkillManager().UpdateSkill(dt); }
	inline bool IsSkillStudyed(int skillid) { return GetSkillManager().IsStudyed(skillid);}

protected:
	SkillManager	m_SkillMgr;			// ���ܹ�����

	//////////////////////////////////////////////////////////////////////////
	// ս�����
	//////////////////////////////////////////////////////////////////////////
public:
	inline int	GetAttackID(){ return 1000+GetCareer()*100+1; }

	/* Name		��Evade
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: �ӱܶ���
	 * Param	: cx,cy �ӱܵ�Ŀ��λ��
	 * Return	: void
	 */
	void Evade(int cx,int cy);

	/* Name		��Forward
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ���
	 * Param	: cx,cy ����Ŀ��λ��
	 * Return	: void
	 */
	void Forward(int cx,int cy);

	/* Name		��UseSkill
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ��ɫʹ�ü���
	 * Param	: skillid ����ID
	 * Return	: void
	 */
	void Attack(int skillid);

	/* Name		��UseSkill
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ��ɫʹ�ü���
	 * Param	: pSkill ʹ�õļ��ܶ���pTarget Ŀ�����
	 * Return	: void
	 */
	void UseSkill(SkillCfg* pSkill,RoleFighter* pTarget);

	/* Name		��UseSkill
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ��ɫʹ�ü���
	 * Param	: pSkill ʹ�õļ��ܶ���cx,cy Ŀ���߼���
	 * Return	: void
	 */
	void UseSkill(SkillCfg* pSkill,int cx,int cy,int offsetX,int offsetY);

	/* Name		��PursueCheck
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ȡ��׷��
	 * Param	: none
	 * Return	: true ����׷�� false ȡ��׷��
	 */
	bool PursueCheck();

	/* Name		��PursueOk
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ׷����Ŀ��
	 * Param	: none
	 * Return	: true ׷����Ŀ�ִ꣬��ָ�� false ����׷��
	 */
	bool PursueOk();

	/* Name		��Dead
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ��ɫ��������
	 * Param	: pKiller ɱ�˷�
	 * Return	: void
	 */
	void Dead(RoleFighter* pKiller);

	/* Name		��DeadVirtual
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ��ɫ��������
	 * Param	: pKiller ɱ�˷�
	 * Return	: void
	 */
	void DeadVirtual(RoleFighter* pKiller);

	/* Name		��Relive
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ��ɫ�����
	 * Param	: pFighter �����ߣ��Զ�����ΪNULL
	 * Return	: void
	 */
	void Relive(RoleFighter* pFighter = nullptr);

	/* Name		��ShowDamageEffect
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: չʾ�˺���Ч����Ч
	 * Param	: pos ����λ�ã�damage �˺���ֵ
	 * Return	: void
	 */
	void ShowDamageEffect(Point pos,int damage);

	/* Name		��ShowCritEffect
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: չʾ������Ч����Ч
	 * Param	: pos ����λ�ã�damage �˺���ֵ
	 * Return	: void
	 */
	void ShowCritEffect(Point pos,int damage);

	/* Name		��ShowMissEffect
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: չʾ������Ч����Ч
	 * Param	: none
	 * Return	: void
	 */
	void ShowMissEffect();

	/* Name		��ShowRecoverHPByItem
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: չʾ��Ѫ��Ч��
	 * Param	: none
	 * Return	: void
	 */
	void ShowRecoverHPByItem(int value);

	/* Name		��ShowRecoverMPByItem
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: չʾ�Է���Ч��
	 * Param	: none
	 * Return	: void
	 */
	void ShowRecoverMPByItem(int value);

	//////////////////////////////////////////////////////////////////////////
	// ս������ 
	//////////////////////////////////////////////////////////////////////////
public:
	/* Name		��GetGodDeviceManager
	 * Author	��Liyang
	 * Date		: 2015-09-24
	 * Desc		: ��ȡս�����ݹ�����
	 * Param	: none
	 * Return	: HallTechManager&
	 */
	inline HallTechManager&	GetHallTechManager(){ return m_HallTechManager; }

protected:
	// ս�����ݹ�����
	HallTechManager m_HallTechManager;
	
	//////////////////////////////////////////////////////////////////////////
	// ----ս������ end----
	//////////////////////////////////////////////////////////////////////////
public:
	/* Name		��GetGodDeviceManager
	 * Author	��Liyang
	 * Date		: 2015-09-01
	 * Desc		: ��ȡ����������
	 * Param	: none
	 * Return	: GodDeviceManager&
	 */
	inline GodDeviceManager&	GetGodDeviceManager(){ return m_GodDeviceMgr; }

	/* Name		��GetGodDevice
	 * Author	��Liyang
	 * Date		: 2015-09-01
	 * Desc		: ��ȡָ����������
	 * Param	: godCfgID
	 * Return	: GodDevice*
	 */
	inline GodDevice* GetGodDevice(int godCfgID){ return GetGodDeviceManager().Get(godCfgID); }

	/* Name		��GetGodDevice
	 * Author	��Liyang
	 * Date		: 2015-09-01
	 * Desc		: ͨ���±��ȡָ����������
	 * Param	: index
	 * Return	: GodDevice*
	 */
	inline GodDevice* GetGodDeviceByIndex(int index){ return GetGodDeviceManager().GetDeviceList()[index]; }

	/* Name		��AddGodDevice
	 * Author	��Liyang
	 * Date		: 2015-09-01
	 * Desc		: �����������
	 * Param	: GodDevice* ��������
	 * Return	: void
	 */
	inline void	AddGodDevice(GodDevice* pGod){ GetGodDeviceManager().Insert(pGod); }

	/* Name		��AddGodDevice
	 * Author	��Liyang
	 * Date		: 2015-06-24
	 * Desc		: ���ָ��BUFF����
	 * Param	: buffid
	 * Return	: RoleBuff*
	 */
	inline GodDevice* AddGodDevice(int godCfgID,int isDress,int refineLevel,int enhanceLevel,int equipId,vector<pk::EquipTianshu> tianShuList,int content_lv,vector<pk::TianshuSoltStreng> soltStrengList,int tian_shu_use_index)
	{ return GetGodDeviceManager().Insert(godCfgID,isDress,refineLevel,enhanceLevel,equipId,tianShuList,content_lv,soltStrengList,tian_shu_use_index); }

	/* Name		��ClearGodDevice
	 * Author	��Liyang
	 * Date		: 2015-09-06
	 * Desc		: ��������б�
	 * Param	: none
	 * Return	: void
	 */
	inline void	ClearGodDevice(){ GetGodDeviceManager().Clear(); }

	//���븱����Ч
	void		ShowCopyEnterEffect();
	//�뿪����
	void		LeaveCopy();
	void		LeaveCopyWithEffect();
	inline void SetCanUseSkill(bool bCanUse) { m_bCanUseSkill = bCanUse; }
	inline bool CanUseSkill() { return m_bCanUseSkill; }
private:
	void		CopyEnterActionStart();
	void		CopyEnterActionProcess1();
	void		CopyEnterActionEnd();
	void		CopyLeaveActionStart();
	void		CopyLeaveActionProcess1();
	void		CopyLeaveActionEnd();
private:
	bool		m_bCanUseSkill;

protected:
	GodDeviceManager m_GodDeviceMgr;	// �������ݹ�����
	//////////////////////////////////////////////////////////////////////////
	// ----�������� end----
	//////////////////////////////////////////////////////////////////////////

	//////////////////////////////////////////////////////////////////////////
	// ----��������
	//////////////////////////////////////////////////////////////////////////
public:
	inline BeginnerGuide*	GetGuidePtr(){ return m_pGuide; }
	void					OnGuideStep(GuideCfg* pData);
	void					OnGuideInitialize();

protected:
	BeginnerGuide*			m_pGuide;

	/***************************����ָʾ******************************/
public:
	CIndicatorLayer*			GetIndicatorLayer() { return m_pIndicatorLayer; }
private:
	void						AddIndicatorLayer();
	CIndicatorLayer*			m_pIndicatorLayer;
};

#define gHero				CHero::Instance()
#define gMap				dynamic_cast<GameMap*>(gHero->GetMap())
#define GetMapRole(ID)		dynamic_cast<RoleFighter*>(gMap->getObjectManager()->getObject(ID))
#define GetMapPlayer(ID)	dynamic_cast<CPlayer*>(gMap->getObjectManager()->getObject(ID))
#define GetMapMonster(ID)	dynamic_cast<CMonster*>(gMap->getObjectManager()->getObject(ID))
#define GetMapItem(ID)	    dynamic_cast<CMapItem*>(gMap->getObjectManager()->getObject(ID))
#define GetMapObject(ID)	gMap->getObjectManager()->getObject(ID)
#define gIndicatorLayer		gHero->GetIndicatorLayer()

#endif //__Hero_h_