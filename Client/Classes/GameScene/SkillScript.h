/***
 * ģ�飺SkillScript
 * ���ߣ�������
 * ʱ�䣺2015-07-2
 * ˵���������߼�����
 * ÿһ�����͵ļ��ܶ�����һ�����ܴ���Ų�����ͬ�������ʹ���Ų���ͬ
 */

#ifndef __SkillScript_h_
#define __SkillScript_h_

#include "GameDef.h"
#include "RoleFighter.h"

enum SkillFlag
{
	SkillFlag_None,			// ��
	SkillFlag_SpecialEffect,// �ͷż�������Ч������
	SkillFlag_Chant,		// ����
	SkillFlag_Precast,		// ǰҡ
	SkillFlag_Complete,		// ��ҡ
};

class SkillScript
{
public:
	SkillScript();
	~SkillScript();

	/* Name		��IsSpecialEffectImme
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: �Ƿ�������ִ�е�����Ч��
	 * Param	: val ָ��Ч��ID
	 * Return	: true ����ִ�У�false ǰҡ����ִ��
	 */
	bool IsSpecialEffectImme(SkillSpecialEffectID val);

	/* Name		��Execute
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: �߼��������
	 * Param	: pFighter ʩ����
	 * Return	: true ��������ִ�У�false ����������ִ��
	 */
	virtual bool Execute(RoleFighter* pFighter);

	/* Name		��ExecuteSpecialEffect
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ����Ч���߼��������
	 * Param	: none
	 * Return	: void
	 */
	virtual void ExecuteSpecialEffect();

	/* Name		��Process
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: �߼�����ӿ�
	 * Param	: dt ʱ���
	 * Return	: true ��������ɣ�false ���������
	 */
	virtual bool Process(float dt);

	/* Name		��ProcessSpecialEffect
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ����������Ч��
	 * Param	: dt ʱ���
	 * Return	: true ��������ɣ�false ���������
	 */
	virtual bool ProcessSpecialEffect(float dt);

	/* Name		��ProcessChant
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: �����߼�����ӿ�
	 * Param	: dt ʱ���
	 * Return	: true ��������ɣ�false ���������
	 */
	virtual bool ProcessChant(float dt);

	/* Name		��ProcessPrecast
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ǰҡ�߼�����ӿ�
	 * Param	: dt ʱ���
	 * Return	: true ��������ɣ�false ���������
	 */
	virtual bool ProcessPrecast(float dt);

	/* Name		��ProcessComplete
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ��ҡ�߼�����ӿ�
	 * Param	: dt ʱ���
	 * Return	: true ��������ɣ�false ���������
	 */
	virtual bool ProcessComplete(float dt);

	/* Name		��Abort
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ������ϼ����ͷ�
	 * Param	: none
	 * Return	: void
	 */
	virtual void Abort();

	/* Name		��IsAbort
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: �����Ƿ��Ѿ�����ֹ
	 * Param	: none
	 * Return	: true ����ֹ��false δ��ֹ
	 */
	virtual bool IsAbort();

	/* Name		��Chant
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ��������
	 * Param	: none
	 * Return	: void
	 */
	virtual void Chant();

	/* Name		��IsChant
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: �Ƿ�������
	 * Param	: none
	 * Return	: true ��������false δ����
	 */
	virtual bool IsChant();

	/* Name		��Precast
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ��ʼ����ǰҡ
	 * Param	: none
	 * Return	: void
	 */
	virtual void Precast();

	/* Name		��IsPrecast
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: �Ƿ��ڼ���ǰҡ
	 * Param	: none
	 * Return	: void
	 */
	virtual bool IsPrecast();

	/* Name		��Complete
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ��ʼ���ܺ�ҡ
	 * Param	: none
	 * Return	: void
	 */
	virtual void Complete();

	/* Name		��IsComplete
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: �Ƿ��ڼ��ܺ�ҡ
	 * Param	: none
	 * Return	: true ��ҡ��false ���Ǻ�ҡ
	 */
	virtual bool IsComplete();

private:
	vector<SkillSpecialEffect> m_vSpecialEffects;
	Effect*			m_pChantEffect;	// ������Ч
	Effect*			m_pCastEffect;	// ʩ����Ч
	RoleFighter*	m_pCaster;		// ����ʩ���߶���ָ��
	union
	{
		RoleFighter* fighter;
		struct 
		{
			int cx;
			int cy;
		}pos;						// Ŀ���
	}Target;

	float m_fTimer;					// ���̼�ʱ��
	int m_nFlag;					// ���̱��
};

#endif //__SkillScript_h_