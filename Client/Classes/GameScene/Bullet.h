/***
 * ģ�飺�ӵ�
 * ���ߣ�������
 * ʱ�䣺2015-06-19
 * ˵�����ӵ����ݼ��ӵ����������ӵ����������ڣ�1.��ը�����٣�2.�������ںľ�����
 */

#ifndef __Bullet_h_
#define __Bullet_h_

#include "GameDef.h"
#include "db.h"
#include "Effect.h"
#include "Singleton.h"
#include "MapObject.h"

enum BulletType
{
	BulletType_None,
	BulletType_SingleFly,		// ���ӵ���������
	BulletType_Multi,			// ���ӵ��������� ƽ��
	BulletType_MultiAngle,		// ���ӵ��������� �Ƕ�
	BulletType_SingleHitScan,	// ����ɨ�裬û����ײ��飬ֱ������Ŀ����ӣ����ף���ʯ������
};

class RoleFighter;

class Bullet : public Node
{
public:
	Bullet();
	Bullet(__int64 id,BulletCfg* pData);
	~Bullet();

	CREATE_FUNC(Bullet);

	static Bullet* CreateWithDataID(__int64 id,int dataid,const Point& pos,const Point& targetPos,MapObjectID casterid,SkillCfg* pSkill);
	static Bullet* CreateWithData(__int64 id,BulletCfg* pData,const Point& pos,const Point& targetPos,MapObjectID casterid,SkillCfg* pSkill);

	/* Name		��GetId
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ��ȡ�ӵ�ΨһID
	 * Param	: none
	 * Return	: id
	 */
	inline __int64 GetId(){ return m_llId; }
	inline int GetIndex(){ return m_nIndex; }

	/* Name		��GetData
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ��ȡ�ӵ���������
	 * Param	: none
	 * Return	: BulletCfg* �ӵ���������
	 */
	inline BulletCfg* GetData(){ return m_pData; }

	/* Name		��GetDataID
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ��ȡ�ӵ���������ID = �ӵ�ID
	 * Param	: none
	 * Return	: int �ӵ�ID
	 */
	inline int GetDataID(){ return GetData()->id; }

	/* Name		��GetType
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ��ȡ�ӵ�����
	 * Param	: none
	 * Return	: int �ӵ�type
	 */
	inline int GetType(){ return GetData()->type; }

	/* Name		��Reload
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: �����ӵ��������
	 * Param	: bulletid �ӵ�ID
	 * Return	: void
	 */
	void Reload(int bulletid);

	/* Name		��Reload
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: �����ӵ��������
	 * Param	: pData ��������
	 * Return	: void
	 */
	void Reload(BulletCfg* pData);

	void Clear();

	/* Name		��draw
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ���ӵ���ײ����
	 * Param	: none
	 * Return	: void
	 */
	virtual void draw(Renderer *renderer, const kmMat4& transform, bool transformUpdated);
	virtual void onDraw(Renderer *renderer, const kmMat4& transform, bool transformUpdated);

	/* Name		��Update
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: �����ӵ��������
	 * Param	: dt ʱ��λ��
	 * Return	: void
	 */
	virtual void Update(float dt);

	/* Name		��Prepare
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: Ԥ������
	 * Param	: none
	 * Return	: void
	 */
	virtual void Prepare();

	/* Name		��ProcessFly
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: �����ӵ�����
	 * Param	: dt ʱ��λ��
	 * Return	: void
	 */
	virtual void ProcessFly(float dt);

	/* Name		��OnHit
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: �ӵ�������Ӧ����
	 * Param	: none
	 * Return	: void
	 */
	virtual void OnHit(RoleFighter* pTarget);

	/* Name		��IsHited
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ���Ŀ���Ƿ�����ײ�б���
	 * Param	: none
	 * Return	: void
	 */
	virtual bool IsHited(RoleFighter* pTarget);

	/* Name		��OnBlast
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ��ը�����¼�����
	 * Param	: none
	 * Return	: void
	 */
	virtual void OnBlast();

	/* Name		��Blast
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ��ը������
	 * Param	: none
	 * Return	: void
	 */
	virtual void Blast();

	/* Name		��checkCollision
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ��ײ��⣬�ж��ӵ��Ƿ���ָ����������ײ
	 * Param	: Rect ��ײ����
	 * Return	: ��ײ����true ���򷵻�false
	 */
	virtual bool checkCollision(const Rect& rect);

	/* Name		��SetTargetPos
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ����Ŀ���
	 * Param	: pos λ��
	 * Return	: void
	 */
	virtual void SetTargetPos(const Point& pos);

	/* Name		��SetTargetVec
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ����Ŀ�귽��
	 * Param	: pos ��������
	 * Return	: void
	 */
	inline void SetTargetVec(const Point& pos){ m_TargetVec = pos; }

	/* Name		��SetId
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ����ID
	 * Param	: id 
	 * Return	: void
	 */
	inline void SetId(__int64 id){ m_llId = id; }
	inline void SetIndex(int idx){ m_nIndex = idx; }

	/* Name		��SetCasterID
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ���÷�����ID
	 * Param	: id ������ID
	 * Return	: void
	 */
	inline void SetCasterID(__int64 id){ m_CasterID = id; }

	/* Name		��SetCasterType
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ���÷���������
	 * Param	: type ���������ͣ��˻��ǹ���
	 * Return	: void
	 */
	inline void SetCasterType(int type){ m_nCasterType = type; }

	/* Name		��SetSkillData
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ���ü�����������
	 * Param	: pSkill ������������
	 * Return	: void
	 */
	inline void SetSkillData(SkillCfg* pSkill){ m_pSkillData = pSkill; }

	inline SkillCfg* GetSkillData(){ return m_pSkillData; }
	inline __int64 GetCasterID(){ return m_CasterID; }
	inline int GetCasterType(){ return m_nCasterType; }

	/* Name		��IsDie
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: �ж��ӵ������Ƿ�ľ�,�ӵ����������ڣ�1.��͸���ľ���ը�����٣�2.�������ںľ���ը������
	 * Param	: none
	 * Return	: true ������false û��
	 */
	inline bool IsDie(){ return (m_fLifeTime*1000>GetData()->duration || m_nPenetratePower <= 0 ); }

	/* Name		��IsCollisionNeed
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: �ж��ӵ��Ƿ�����ײ������Ҫ
	 * Param	: none
	 * Return	: true ��Ҫ��false û��
	 */
	inline bool IsCollisionNeed(){ return m_bCollision; }

	/* Name		��SetCollisionNeed
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: �����ӵ��Ƿ�����ײ������Ҫ
	 * Param	: val == true ��Ҫ��false û��
	 * Return	: none
	 */
	inline void SetCollisionNeed(bool val = true){ m_bCollision = val; }

protected:
	__int64			m_llId;			// �ӵ�Ψһ��ʶ
	int				m_nIndex;		// �ӵ����еĵڼ����ӵ�
	BulletCfg*		m_pData;		// �ӵ���������
	EffectList		m_effectListAim;		// �ӵ�������Ч
	EffectList		m_effectListFly;		// �ӵ�������Ч
	EffectList		m_effectListBlast;		// �ӵ�������Ч
	Point			m_TargetPos;	// Ŀ��λ��
	Point			m_TargetVec;	// Ŀ�귽��
	float			m_fLeft;		// ��ײ����
	float			m_fRight;
	float			m_fTop;
	float			m_fBottom;
	__int64			m_CasterID;		// ������ID
	int				m_nCasterType;	// ���������˻��ǹ���
	SkillCfg*		m_pSkillData;	// �����ӵ��ļ�������
	int				m_nPenetratePower;	// �ӵ���ǰ��͸��
	float			m_fLifeTime;		// ��������
	bool			m_bCollision;		// �Ƿ���Ҫ����ײ��⣬ֻ���Լ������ӵ�����Ҫ����ײ��⣬�����˷��Ĳ���Ҫ��
	vector<__int64> m_vCollisionList;	// ��ײ�б�
};

typedef vector<Bullet*>	BulletList;
typedef vector<Bullet*>	BulletGroup;

// �ӵ�������
class BulletManager : public Singleton<BulletManager>
{
public:
	BulletManager();
	~BulletManager();

	/* Name		��CreateBullet
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ����һ���ӵ�
	 * Param	: id �ӵ�Ψһ��ʶ��dataid �ӵ�ID,pCaster �ͷ��߶���ָ�룬SkillCfg* pSkill �����������ݣ�targetPos Ŀ���
	 * Return	: void
	 */
	void CreateBullet(__int64 id,int dataid,RoleFighter* pCaster,SkillCfg* pSkill,const Point& pos,int multi = 0);

	/* Name		��AddBullet
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ���һ���ӵ�
	 * Param	: pBullet �ӵ�ָ��
	 * Return	: void
	 */
	void AddBullet(Bullet* pBullet);

	/* Name		��Remove
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: �Ƴ�һ���ӵ�
	 * Param	: pBullet �ӵ�ָ��
	 * Return	: void
	 */
	void Remove(Bullet* pBullet);

	/* Name		��Clear
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ����ӵ��б�
	 * Param	: none
	 * Return	: void
	 */
	void Clear();

	/* Name		��UpdateBullet
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ���������ӵ�����
	 * Param	: dt ʱ��λ��
	 * Return	: void
	 */
	void UpdateBullet(float dt);

	/* Name		��GetBulletList
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ��ȡ�ӵ��б�
	 * Param	: none
	 * Return	: GetBulletList& �ӵ��б�����
	 */
	inline BulletList& GetBulletList() { return m_Bullets; }

private:
	BulletList m_Bullets;
};

#define gBulletMgr BulletManager::Instance()

#endif //__Bullet_h_