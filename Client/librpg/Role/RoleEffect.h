/***
 * ģ�飺��ɫ��Ч
 * ���ߣ�������
 * ʱ�䣺2015-06-19
 * ˵�������ɫ�����󶨵���Ч��8����
 */

#ifndef __RoleEffect_h_
#define __RoleEffect_h_

#include "Effect.h"

enum RoleEffectType
{
	RoleEffect_None,
	RoleEffect_Miss,				// ����
	RoleEffect_Injured,				// ����
	RoleEffect_Dead,				// ����
	RoleEffect_Damage,				// ��ͨ�����˺�����BUFF�˺�
	RoleEffect_Crit,				// �����˺����߼����˺�
	RoleEffect_Revive,				// ����
	RoleEffect_LevelUP,				// ����
	RoleEffect_RecoverHP,			// ���ܺ�BUFF��ѪЧ��
	RoleEffect_RecoverMP,			// ���ܺ�BUFF��ħЧ��
	RoleEffect_RecoverHP_Ball,		// ��Ѫ���ѪЧ��
	RoleEffect_RecoverMP_Ball,		// �Է����ħЧ��
	RoleEffect_HitBack,				// ����Ч��
};

class Role;
class RoleEffect;
typedef vector<RoleEffect*> RoleEffectList;

class RoleEffect : public Effect
{
public:
	RoleEffect();
	~RoleEffect();

	CREATE_FUNC(RoleEffect);

	static RoleEffect* createWithDataID(Role* pRole,int dataid,const string& name);
	
	static int createRoleEffectListByConfig(Role* pRole,const string& config,RoleEffectList& list);

	/* Name		��onAnimationEnd
	 * Author	��YueLiangYou
	 * Date		: 2015-07-02
	 * Desc		: ���������ص�
	 * Param	: none
	 * Return	: void
	 */
	void onAnimationEnd();

	/* Name		��play
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ���Ŷ���
	 * Param	: none
	 * Return	: void
	 */
	void play();

	void setScale(float scale);

	inline void setRole(Role* pRole){ m_pRole = pRole; }
	inline Role* getRole(){ return m_pRole; }

protected:
	Role* m_pRole;
};

#endif //__RoleEffect_h_