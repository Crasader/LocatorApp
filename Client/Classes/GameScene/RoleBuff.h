/***
 * ģ�飺BUFF
 * ���ߣ�������
 * ʱ�䣺2015-06-19
 * ˵����BUFF���ݼ�BUFF����
 */

#ifndef __RoleBuff_h_
#define __RoleBuff_h_

#include "GameDef.h"
#include "db.h"
#include "Effect.h"

enum RoleBuffType
{
	RoleBuffType_None,
	RoleBuffType_ChangeProperty,	// 1 �޸�����
	RoleBuffType_Damage,			// 2 �������˺�������������dot��hot��
	RoleBuffType_SlowDown,			// 3 ���٣�״̬������Ŀ���ƶ��ٶȣ�p1=p1*(1+p2/10000*����ǿ��/10000)
	RoleBuffType_Skill,				// 4 �����Ե��ü��ܣ�p1 ���ü���id
	RoleBuffType_Transfer,			// 5 buff�˺��İٷֱ�ת��Ϊ����ֵ�ָ�,p1=p1*(1+p2/10000*����ǿ��/10000)
};

class RoleBuff
{
public:
	RoleBuff(__int64 id,int buffid,int duration);
	~RoleBuff();

	/* Name		��GetData
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ��ȡBUFF��������
	 * Param	: none
	 * Return	: BuffCfg* BUFF��������
	 */
	inline BuffCfg* GetData(){ return m_pData; }

	inline int64 GetBuffIdentity(){ return m_id; }
	inline int GetBuffDataID(){ return m_pData->id; }
	inline int GetDuration(){ return m_nDuration; }
	inline void SetDuration(int duration){ m_nDuration = duration; }
	inline string& GetIcon(){ return m_pData->icon; }
	inline EffectList& GetEffectList(){ return m_effectList; }

	/* Name		��Reload
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ����buff�������
	 * Param	: buffid BUFF ID
	 * Return	: void
	 */
	void Reload(int buffid);

	void Clear();

public:
	int64		    m_id;			// buff��ʶID
	int			    m_nDuration;	// Buff��ʱ
	BuffCfg*	    m_pData;		// BUFF��������
	EffectList		m_effectList;		// ��Ч�б�
};

typedef vector<RoleBuff*> RoleBuffList;

class RoleBuffManager
{
public:
	RoleBuffManager();
	~RoleBuffManager();

	/* Name		��Insert
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ���һ��BUFF
	 * Param	: RoleBuff* �¼ӵ�BUFFָ��
	 * Return	: void
	 */
	void		Insert(RoleBuff* pBuff);

	/* Name		��Remove
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: �Ƴ�һ��BUFF
	 * Param	: buffid BUFF����ID
	 * Return	: void
	 */
	void		Remove(int64 buffid);

	/* Name		��Get
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ��ȡһ��BUFF
	 * Param	: buffid BUFF����ID
	 * Return	: RoleBuff* ��ɫBUFF
	 */
	RoleBuff*	Get(int64 buffid);

	/* Name		��Clear
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ����BUFF����
	 * Param	: none
	 * Return	: void
	 */
	void		Clear();

	/* Name		��Count
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ͳ��BUFF����
	 * Param	: none
	 * Return	: int BUFF����
	 */
	inline int Count(){ return (int)m_Buffs.size(); }

	/* Name		��GetBuffList
	 * Author	��Liyang
	 * Date		: 2015-08-21
	 * Desc		: ��ȡbuff�б�
	 * Param	: none
	 * Return	: RoleBuffList BUFF�б�
	 */
	inline RoleBuffList	GetBuffList(){return m_Buffs;}

private:
	RoleBuffList m_Buffs;
};

#endif //__RoleBuff_h_