#ifndef __SkillType_h_
#define __SkillType_h_

#include "GameDef.h"

#define Normal_Attack_ID		1001			// ��ͨ����ID

enum SkillTargetType
{
	SkillTarget_None,			// ����ָ��Ŀ��
	SkillTarget_Target,			// ָ��Ŀ��
	SkillTarget_Point,			// ָ����ͼ���߼���
	SkillTarget_Self,			// ������ʹ��
};

enum SkillType
{
	Skill_Normal1 = 11,				// ��ͨ����
	Skill_Normal2 = 12,				// ��ͨ����
	Skill_Normal3 = 13,				// ��ͨ����
	Skill_MultiArrow = 23,			// ���ؼ�
};

// �
//	Ч��id����Ч������Ч�����ʣ�Ч��Ŀ�꣬p1��p2��p3
//	��Ч����
//	1 ֱ����Ч
//	2 ����
//	3 ����
//	Ч������Ϊ0��10000������10000ʱ���㼸��=��дֵ*��������/8000
//
//	Ч��Ŀ�꣺
//	1 ����ѡ���Ŀ��
//	2 �ͷ����Լ�
//
//	Ч��id��
//	1.���˲�ƣ�ʩ���ߴ��͵�Ŀ���ٽ����ӣ�p1 λ�Ƶ��ٶ�
//	2.����buff��p1-3 ��дbuffid
//	3.������Ƴ��ļ���buff
//	4.���� ���ǽ p1Ϊtrap data id
//	5.�����ӵ���ֻ�����߼��㣬����λ�õļ���ʹ�� ��p1Ϊmissile data id��p2 ������ʱ
//	6.Ӳֱ
//	7.ÿ��ɱһ��Ŀ����ٸü�����ȴ��p1��д������
enum SkillSpecialEffectID
{
	SkillSpecialEffect_None,
	SkillSpecialEffect_Faward,		// ���˲��
 	SkillSpecialEffect_Buff,		// ��buff��p1-3 ��дbuffid
	SkillSpecialEffect_Clr,			// ������Ƴ��ļ���buff
	SkillSpecialEffect_Trap,		// ���� ���ǽ p1Ϊtrap data id
	SkillSpecialEffect_Missile,		// �����ӵ� ��p1Ϊmissile data id
	SkillSpecialEffect_Injured,		// Ӳֱ
	SkillSpecialEffect_Reduce_Cd,	// ���ټ���CD
};

enum SkillSpecialEffectCond
{
	SkillSpecialEffectCond_None,
	SkillSpecialEffectCond_Direct,	//	1 ֱ����Ч
	SkillSpecialEffectCond_Hit,		//	2 ����
	SkillSpecialEffectCond_Crit,	//	3 ����
};

enum SkillSpecialEffectTarget
{
	SkillSpecialEffectTarget_None,
	SkillSpecialEffectTarget_Hit,	//	1 ����ѡ���Ŀ��
	SkillSpecialEffectTarget_Self,	//	2 �ͷ����Լ�
};

//	Ч��id����Ч������Ч�����ʣ�Ч��Ŀ�꣬p1��p2��p3
struct SkillSpecialEffect
{
	int	id;
	int	cond;
	int rate;
	int target;
	int p1;
	int p2;
	int p3;
};

//��һ�������滻������ť
#define Fir_Skill_ZS			(30)
#define Fir_Skill_FS			(14)
#define Fir_Skill_GJ			(22)


#endif //__SkillType_h_