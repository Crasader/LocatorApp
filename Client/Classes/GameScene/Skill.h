/***
 * ģ�飺����
 * ���ߣ�������
 * ʱ�䣺2015-06-19
 * ˵�����������ݼ����ܹ���
 */

#ifndef __Skill_h_
#define __Skill_h_

#include "GameDef.h"
#include "db.h"
#include "SkillType.h"

class CSkill
{
public:
	typedef enum _cdType
	{
		CdType_None,
		CdType_Skill,	//����CD
		CdType_Globe,	//����CD
	}CdType;
public:
	CSkill();
	CSkill(int skillid);
	~CSkill();

	/* Name		��GetData
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ��ȡ������������
	 * Param	: none
	 * Return	: SkillCfg* ������������
	 */
	inline SkillCfg* GetData(){ return m_pData; }

	/* Name		��GetDataID
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ��ȡ������������ID = ����ID
	 * Param	: none
	 * Return	: int ����ID
	 */
	inline int GetDataID(){ return GetData()->id; }

	/* Name		��IsPassive
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: �жϼ����Ƿ��Ǳ�������
	 * Param	: none
	 * Return	: bool
	 */
	inline bool	IsPassive(){ return GetData()->passitive != 0; }

	/* Name		��IsNormalAttack
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: �жϼ����Ƿ�����ͨ����
	 * Param	: none
	 * Return	: bool
	 */
	inline bool	IsNormalAttack(){ return GetData()->normal_attack != 0; }

	/* Name		��GetLevel
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ��ȡ���ܵȼ�
	 * Param	: none
	 * Return	: int ���ܵȼ�
	 */
	inline int GetLevel(){ return m_nLevel; }

	/* Name		��SetLevel
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ���ü��ܵȼ�
	 * Param	: lv ���ܵȼ�
	 * Return	: void
	 */
	inline void	SetLevel(int lv){ m_nLevel = lv; }

	/* Name		��GetType
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ��ȡ��������
	 * Param	: none
	 * Return	: int ��������
	 */
	inline int GetType(){ return GetData()->type; }

	/* Name		��GetCDTime
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ��ȡ����CDʱ�� ms
	 * Param	: none
	 * Return	: int ����CDʱ�� ms
	 */
	inline int GetCDTime(){ return m_nCDTime; }

	/* Name		��SetCDTime
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ���ü���CDʱ�� ms
	 * Param	: cd ����CDʱ�� ms
	 * Return	: void
	 */
	inline void	SetCDTime(int cd){ m_nCDTime = cd; }

	//cd����
	inline CdType	GetCDType(){ return m_cdType; }
	inline void		SetCDType(CdType cdType){ m_cdType = cdType; }

	/* Name		��GetTickTime
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ��ȡ����������ʱ ms
	 * Param	: none
	 * Return	: int ����������ʱ ms
	 */
	inline int GetTickTime(){ return m_nTickTime; }

	/* Name		��SetTickTime
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ���ü�������ʱ�� ms
	 * Param	: tick ����ʱ�� ms
	 * Return	: void
	 */
	inline void	SetTickTime(int tick){ m_nTickTime += tick; }

	/* Name		��m_nTickIndex
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ��ȡ�����ڼ�����������
	 * Param	: none
	 * Return	: int �����ڼ�����������
	 */
	inline int GetTickIndex(){ return m_nTickIndex; }

	/* Name		��Reload
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ���ü����������
	 * Param	: skillid ����ID
	 * Return	: void
	 */
	void Reload(int skillid);

	/* Name		��GetTickSkill
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ��ȡ��������ID
	 * Param	: none
	 * Return	: CSkill* ��������������������ܣ����򷵻ر�����
	 */
	SkillCfg* GetTickSkill();

protected:
	int				m_nLevel;		// ���ܵȼ�
	int				m_nCDTime;		// ������ȴʱ��
	CdType			m_cdType;		// Cd����
	int				m_nTickTime;	// ����������ʱ
	int				m_nTickIndex;	// �����ڼ�����������
	vector<int>		m_vTickSkills;	// ��������ID
	SkillCfg*		m_pData;		// ������������
};

typedef vector<CSkill*>	SkillList;

// ���ܹ�����
class SkillManager
{
public:
	SkillManager();
	~SkillManager();

	/* Name		��Insert
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ���һ������
	 * Param	: skillid ����ID
	 * Return	: CSkill* �¼ӵļ���ָ��
	 */
	CSkill* Insert(int skillid);

	/* Name		��Insert
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ���һ������
	 * Param	: pSkill ����ָ��
	 * Return	: CSkill* �¼ӵļ���ָ��
	 */
	CSkill*	Insert(CSkill* pSkill);

	/* Name		��Remove
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: �Ƴ�һ������
	 * Param	: skillid ����ID
	 * Return	: void
	 */
	void Remove(int skillid);

	/* Name		��Clear
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ��������б�
	 * Param	: none
	 * Return	: void
	 */
	void Clear();

	/* Name		��Get
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ��ȡ����ָ��
	 * Param	: skillid ����ID
	 * Return	: CSkill*
	 */
	CSkill* Get(int skillid);

	/* Name		��IndexBy
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: �����±�������ȡ����ָ��
	 * Param	: idx �±�
	 * Return	: CSkill*
	 */
	CSkill* IndexBy(int idx);

	/* Name		��Last
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ��ȡ���һ������ָ��
	 * Param	: none
	 * Return	: CSkill*
	 */
	CSkill* Last();

	/* Name		��LastActive
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ��ȡ���һ��������������ָ��
	 * Param	: none
	 * Return	: CSkill*
	 */
	CSkill* LastActive();

	/* Name		��Count
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ͳ�Ƽ��ܸ���
	 * Param	: none
	 * Return	: int ���ܸ���
	 */
	int	Count();

	/* Name		��CountActive
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ͳ�������ͼ��ܸ���
	 * Param	: none
	 * Return	: int ���ܸ���
	 */
	int		CountActive();

	/* Name		��isStudyed
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: �Ƿ�ѧ����ĳ���ͼ���
	 * Param	: type ��������
	 * Return	: true ѧ�ᣬfalseδѧ��
	 */
	bool IsStudyed(int skillid);

	/* Name		��GetSkillLevel
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ��ȡ���ܵȼ�
	 * Param	: skillid ����id
	 * Return	: int ���ܵȼ�
	 */
	int GetSkillLevel(int skillid);

	/* Name		��StartCd
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ���ü���CDʱ��
	 * Param	: skillid ����id
	 * Return	: void
	 */
	void StartCd(int skillId);

	/* Name		��UpdateSkill
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: �������м��ܵ�CDʱ��
	 * Param	: dt ʱ��λ��
	 * Return	: void
	 */
	void UpdateSkill(float dt);

	/* Name		��GetSkillList
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ��ȡ�����б�
	 * Param	: none
	 * Return	: SkillList& �����б�����
	 */
	inline SkillList& GetSkillList() { return m_Skills; }

	/* Name		��GetSkillList
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ��ȡ�����б�
	 * Param	: val -1 ��Ἴ���б��������طǰ�Ἴ��
	 * Return	: SkillList& �����б�����
	 */
	void GetSkillListByFlag(int val,SkillList& lists);

private:
	SkillList m_Skills;
};



#endif //__Skill_h_