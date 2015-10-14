/***
 * ģ�飺RoleFighter
 * ���ߣ�������
 * ʱ�䣺2015-07-2
 * ˵������ս����ɫ���
 * ���Բ���ս����ʹ�ü��ܣ�����ս������
 */

#ifndef __RoleFighter_h_
#define __RoleFighter_h_

#include "GameDef.h"
#include "role.h"
#include "RoleState.h"
#include "Map/AStar.h"
#include "GameMap.h"
#include "db.h"
#include "RoleEffect.h"
#include "StateMachine.h"
#include "Skill.h"
#include "Net/pk_role.h"
#include "Bullet.h"
#include "RoleBuff.h"

// ״̬����������
struct RoleFighterStateMachineData
{
	union 
	{
		struct 
		{

		}Idle;

		struct 
		{
			
		}Move;

		struct 
		{
			
		}Fight;

		struct 
		{
			
		}Ready;

		struct 
		{
			
		}Injured;

		struct 
		{
			
		}Forbiden;

		struct
		{
			float   deadRestTime;	//����״̬ʣ�ิ��ʱ��
			int		restPoint;		//ʣ�����
			int		helpNum;		//���Ƚ�ɫ��Ŀ
			float	restTime;		//ʣ�����
			int		percent;		//��������ٶ�
		}Dead;
	};
};

class RoleFighter : public Role
{
public:
	RoleFighter();
	virtual ~RoleFighter();

	static inline EquipmentID	getNakedArmorID(int prof,int sex){ return 0; }
	static inline EquipmentID	getNakedWeaponID(int prof,int sex){ return 0; }
	static inline EquipmentID	getNakedWingID(int prof,int sex){ return 0; }

	static inline EquipmentID	getEquipedArmorID(int prof,int sex,int artid){ return artid; }
	static inline EquipmentID	getEquipedWeaponID(int prof,int sex,int artid){ return artid; }
	static inline EquipmentID	getEquipedWingID(int prof,int sex,int artid){ return artid; }

	virtual void update(float dt);

	virtual bool initRole();

	virtual bool isSelect(float x,float y);

	/* Name		��onSelect
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: Ԫ�ر�ѡ�лص�����
	 * Param	: param == true ��ѡ�У�����δ��ѡ��
	 * Return	: void
	 */
	virtual void onSelect(bool param);

	inline bool IsChests(){ return GetType() == mapObjectType_Chests; }
	inline bool IsMonster(){ return GetType() == mapObjectType_Monster; }
	inline bool IsPlayer(){ return GetType() == mapObjectType_Player; }
	inline bool IsNpc(){ return GetType() == mapObjectType_Npc; }

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

	/* Name		��isDynamicBlock
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: �ж�һ���߼������������Լ��Ƿ��Ƕ�̬�赲��
	 * Param	: cx,cy �߼������
	 * Return	: void
	 */
	bool isDynamicBlock(int cx,int cy);

	/* Name		��EnterMap
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ����ָ����ͼ
	 * Param	: pMap��ͼָ�룬cx��cy��ͼ�е��߼�����
	 * Return	: void
	 */
	virtual void EnterMap(TileMap* pMap,int cx,int cy);

	/* Name		��LeaveMap
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: �뿪��ǰ��ͼ
	 * Param	: none
	 * Return	: void
	 */
	virtual void LeaveMap();

	/* Name		��onEnterSight
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: Ԫ�ؽ�����Ұ�ص�
	 * Param	: none
	 * Return	: void
	 */
	virtual void onEnterSight();

	/* Name		��onLeaveSight
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: Ԫ���뿪��Ұ�ص�
	 * Param	: none
	 * Return	: void
	 */
	virtual void onLeaveSight();

	//////////////////////////////////////////////////////////////////////////
	// �������
	//////////////////////////////////////////////////////////////////////////
public:
	virtual void		SetProperty(RoleProperty idx,int val);
	virtual void		SetProperty(RoleProperty idx,__int64 val);
	virtual void		SetProperty(RoleProperty idx,const string& val);

	inline int			GetCareer(){ return GetPropertyInt(RoleProperty_Career); }
	inline int			GetSex(){ return GetPropertyInt(RoleProperty_Sex); }
	inline int			GetLevel(){ return GetPropertyInt(RoleProperty_Level); }
	inline int			GetCamp(){ return GetPropertyInt(RoleProperty_Camp); }
	inline __int64		GetHP(){ return GetPropertyInt64(RoleProperty_HP); }
	inline int			GetMP(){ return GetPropertyInt(RoleProperty_MP); }
	inline __int64		GetHPMax() { return GetPropertyInt64(RoleProperty_hp_max); }
	inline int			GetMPMax() { return GetPropertyInt(RoleProperty_mp_max); }

	virtual void		SetRoleName(const string& val);
	virtual void		SetCareer(int val);
	virtual void		SetSex(int val){ GetData()->SetProperty(RoleProperty_Sex,val); }
	virtual void		SetLevel(int val){ GetData()->SetProperty(RoleProperty_Level,val); }
	virtual void		SetCamp(int val);
	virtual void		SetHP(__int64 val);
	virtual void		SetMP(int val);
	virtual void		SetHPMax(__int64 val);
	virtual void		SetMPMax(int val);
	virtual void		SetCloth(int val){ GetData()->SetProperty(RoleProperty_Cloth,val); RefreshEquip(); }
	virtual void		SetWeapon(int val){ GetData()->SetProperty(RoleProperty_Weapon,val); RefreshEquip(); }
	virtual void		SetWing(int val){ GetData()->SetProperty(RoleProperty_Wing,val); RefreshEquip(); }

	/* Name		��SetStateFlag
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ���ý�ɫ״̬��־λ
	 * Param	: val ״ֵ̬
	 * Return	: void
	 */
	virtual void SetStateFlag(int val);

	/* Name		��AddStateFlag
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ����ָ����ɫ״̬��־λ
	 * Param	: val ״ֵ̬
	 * Return	: void
	 */
	virtual void AddStateFlag(int val);

	/* Name		��ClrStateFlag
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ���ָ����ɫ״̬��־λ
	 * Param	: val ״ֵ̬
	 * Return	: void
	 */
	virtual void ClrStateFlag(int val);

	/* Name		��RefreshEquip
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ���½�ɫװ�����
	 * Param	: none
	 * Return	: void
	 */
	virtual void RefreshEquip();

	/* Name		��RefreshRoleTitle
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ���½�ɫ������Ϣչʾ
	 * Param	: none
	 * Return	: void
	 */
	virtual void RefreshRoleTitle();

protected:
	class RoleTitle* m_pRoleTitle;			// ��ɫ������Ϣչʾ�����֣�Ѫ������ν���ɾͣ�VIP�ȼ��ȵ�

	//////////////////////////////////////////////////////////////////////////
	// �������
	//////////////////////////////////////////////////////////////////////////

public:
	/* Name		��ShowRoleEffect
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ͨ��Ч������������Ч��
	 * Param	: type Ч�����ͣ�val ������ֵ
	 * Return	: void
	 */
	virtual void ShowRoleEffect(pk::RoleEffectInfo* pInfo);

	/* Name		��ShowDamageEffect
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: չʾ�˺���Ч����Ч
	 * Param	: pos ����λ�ã�damage �˺���ֵ
	 * Return	: void
	 */
	virtual void ShowDamageEffect(Point pos,int damage);

	/* Name		��ShowCritEffect
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: չʾ������Ч����Ч
	 * Param	: pos ����λ�ã�damage �˺���ֵ
	 * Return	: void
	 */
	virtual void ShowCritEffect(Point pos,int damage);

	/* Name		��ShowMissEffect
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: չʾ������Ч����Ч
	 * Param	: none
	 * Return	: void
	 */
	virtual void ShowMissEffect();

	/* Name		��ShowRecoverHP
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: չʾ�ظ�Ѫ��Ч��
	 * Param	: none
	 * Return	: void
	 */
	virtual void ShowRecoverHP(int value);

	/* Name		��ShowRecoverMP
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: չʾ�ظ�ħ��Ч��
	 * Param	: none
	 * Return	: void
	 */
	virtual void ShowRecoverMP(int value);

	/* Name		��ShowRecoverHPByItem
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: չʾ��Ѫ��Ч��
	 * Param	: none
	 * Return	: void
	 */
	virtual void ShowRecoverHPByItem(int value);

	/* Name		��ShowRecoverMPByItem
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: չʾ�Է���Ч��
	 * Param	: none
	 * Return	: void
	 */
	virtual void ShowRecoverMPByItem(int value);

	/* Name		��ShowMissEffect
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: չʾ������Ч����Ч
	 * Param	: none
	 * Return	: void
	 */
	virtual void ShowLevelUPEffect();

	/* Name		��ShowStageEffect
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: չʾ��ɫ������Ч����Ч
	 * Param	: none
	 * Return	: void
	 */
	virtual void ShowStageEffect();

	/* Name		��ShowHitFly
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ����Ч�������ڽ�ɫ����
	 * Param	: pos �����λ��
	 * Return	: void
	 */
	virtual void ShowHitFly(const Point& pos);

// ս�����
public:
	/* Name		��IsForbiddenMove
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: �Ƿ��������ƶ�
	 * Param	: none
	 * Return	: true �����ƣ�false ��������
	 */
	virtual bool IsForbiddenMove();

	/* Name		��IsForbiddenAttack
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: �Ƿ������ƹ���
	 * Param	: none
	 * Return	: true �����ƣ�false ��������
	 */
	virtual bool IsForbiddenAttack();

	/* Name		��IsForbiddenSkill
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: �Ƿ�������ʹ�ü���
	 * Param	: none
	 * Return	: true �����ƣ�false ��������
	 */
	virtual bool IsForbiddenSkill();

	/* Name		��IsEnemyTo
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: �Ƿ���Ŀ��ж�
	 * Param	: pFighter Ŀ�����
	 * Return	: true �жԵģ�false �ǵжԵģ����������Ѻã�
	 */
	virtual bool IsEnemyTo(RoleFighter* pFighter);

	/* Name		��Forward
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ���
	 * Param	: cx,cy ����Ŀ��λ��
	 * Return	: void
	 */
	virtual void Forward(int cx,int cy);

	/* Name		��Evade
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: �ӱܶ���
	 * Param	: cx,cy �ӱܵ�Ŀ��λ��
	 * Return	: void
	 */
	virtual void Evade(int cx,int cy);

	virtual bool	IsAttacking();
	virtual bool	IsInjured();

	/* Name		��IsDead
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: �Ƿ���������
	 * Param	: none
	 * Return	: �Ƿ���true ������false
	 */
	virtual bool	IsDead();

	/* Name		��IsDeadVirtual
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: �Ƿ����״̬
	 * Param	: none
	 * Return	: �Ƿ���true ������false
	 */
	virtual bool	IsDeadVirtual();
	
	/* Name		��Injured
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ��ɫ���˴��� ��ֱ����
	 * Param	: none
	 * Return	: void
	 */
	virtual void Injured();

	/* Name		��Dead
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ��ɫ��������
	 * Param	: pKiller ɱ�˷�
	 * Return	: void
	 */
	virtual void Dead(RoleFighter* pKiller);

	/* Name		��DeadVirtual
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ��ɫ��������
	 * Param	: pKiller ɱ�˷�
	 * Return	: void
	 */
	virtual void DeadVirtual(RoleFighter* pKiller);

	/* Name		��Relive
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ��ɫ�����
	 * Param	: pFighter �����ߣ��Զ�����ΪNULL
	 * Return	: void
	 */
	virtual void Relive(RoleFighter* pFighter = nullptr);

	//////////////////////////////////////////////////////////////////////////
	// buff����
	//////////////////////////////////////////////////////////////////////////
public:
	/* Name		��GetBuffManager
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ��ȡBUFF������
	 * Param	: none
	 * Return	: RoleBuffManager&
	 */
	inline RoleBuffManager&	GetBuffManager(){ return m_BuffMgr; }

	/* Name		��GetBuff
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ��ȡָ��BUFF����
	 * Param	: buffid
	 * Return	: RoleBuff*
	 */
	inline RoleBuff* GetBuff(int64 buffid){ return GetBuffManager().Get(buffid); }

	/* Name		��AddBuff
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ���BUFF����
	 * Param	: RoleBuff* BUFF����
	 * Return	: void
	 */
	virtual void AddBuff(RoleBuff* pBuff);

	/* Name		��AddBuff
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ���ָ��BUFF����
	 * Param	: buffid
	 * Return	: RoleBuff*
	 */
	virtual RoleBuff* AddBuff(__int64 id,int buffid,int duration);

	/* Name		��RemoveBuff
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: �Ƴ�ָ��BUFF����
	 * Param	: buffid
	 * Return	: void
	 */
	virtual void RemoveBuff(int64 buffid);

protected:
	RoleBuffManager m_BuffMgr;	// buff������

	//////////////////////////////////////////////////////////////////////////
	// ----buff���� end----
	//////////////////////////////////////////////////////////////////////////
public:
	/* Name		��ConvertToTargetID
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ͨ���߼�������ȡĿ��ID
	 * Param	: cx,cy Ŀ���߼���
	 * Return	: __int64 targetid
	 */
	inline __int64 ConvertToTargetID(int cx,int cy){__int64 ret = cx;ret = ret << 32;ret += cy;return ret;}

	/* Name		��ConvertToCell
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ͨ���߼�������ȡĿ��ID
	 * Param	: cx,cy Ŀ���߼���
	 * Return	: __int64 targetid
	 */
	inline void ConvertToCell(__int64 targetId,int& cx,int& cy){ cy = targetId; cx = targetId >> 32; }

	/* Name		��GetCellByDir
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ��ȡ��ǰָ�����������
	 * Param	: cx,cy Ŀ���߼���
	 * Return	: void
	 */
	virtual void GetCellByDir(int distance,int& cx,int& cy);

	/* Name		��FaceToTarget
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ʹ�Լ�����Ŀ���
	 * Param	: pos Ŀ���߼��� ��������ϵ
	 * Return	: void
	 */
	virtual void FaceToTarget(const Point& pos);

	/* Name		��FaceToTarget
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ʹ�Լ�����Ŀ��
	 * Param	: cx,cy Ŀ���߼���
	 * Return	: void
	 */
	virtual void FaceToTarget(int cx,int cy);

	/* Name		��FaceToTarget
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ʹ�Լ�����Ŀ��
	 * Param	: pTarget Ŀ�����
	 * Return	: void
	 */
	virtual void FaceToTarget(RoleFighter* pTarget);

	/* Name		��MagicAttack
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ʹ�ü��ܣ�ս�����ܱ���
	 * Param	: pSkill ��������������Ϣ targetid Ŀ�����id��int offsetX,int offsetY Ŀ��λ��ƫ��
	 * Return	: void
	 */
	virtual void MagicAttack(SkillCfg* pSkill,__int64 targetid,int offsetX,int offsetY);

	/* Name		��GetActiveSkill
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ��ȡ��ǰʹ�õļ���
	 * Param	: none
	 * Return	: pSkill ���ܶ���ָ��
	 */
	inline SkillCfg* GetActiveSkill(){ return m_pActiveSkill; }

	/* Name		��GetTargetID
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ��ȡ��ǰĿ��ID
	 * Param	: none
	 * Return	: 
	 */
	inline __int64 GetTargetID(){ return m_nTargetID; }

	/* Name		��GetTargetOffsetX
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ��ȡ��ǰĿ��ƫ��
	 * Param	: none
	 * Return	: 
	 */
	inline int GetTargetOffsetX(){ return m_nTargetOffsetX; }
	inline int GetTargetOffsetY(){ return m_nTargetOffsetY; }

	inline RoleFighterStateMachineData& GetStateMachineData(){ return m_StateMachineData; }

	virtual float	GetDeadVirtualDeadRestTime();
	virtual int		GetDeadVirtualRestPoint();
	virtual int		GetDeadVirtualHelpNum();
	virtual float	GetDeadVirtualRestTime();
	virtual int		GetDeadVirtualPercent();

	virtual void SetDeadVirtualPercent();
	virtual void SetDeadVirtualDeadRestTime(float timer);
	virtual void SetDeadVirtualRestPoint(int restPoint);
	virtual void SetDeadVirtualHelpNum(int helpnum);
	virtual void SetDeadVirtualRestTime(float restTime);

protected:
	SkillCfg*		m_pActiveSkill;		// Ŀǰ����ʹ�õļ���		
	__int64			m_nTargetID;		// ����Ŀ��ID
	int				m_nTargetOffsetX;	// Ŀ��ƫ��
	int				m_nTargetOffsetY;	// Ŀ��ƫ��		
	RoleFighterStateMachineData m_StateMachineData;
};

#endif //__IRole_h_