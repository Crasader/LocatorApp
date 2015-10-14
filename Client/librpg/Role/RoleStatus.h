/***
 * ���ߣ�������
 * ʱ�䣺2015-07-2
 * ˵������ɫ����״̬��أ���ɫ������Ч����
 */

#ifndef __RoleStatus_h_
#define __RoleStatus_h_

enum RoleStatus
{
	RoleStatus_None = 0,		// ��״̬
};

// ״̬��־ ���֧��32��״̬�����ڿ����߼���buff���ڱ���
enum RoleStateFlag
{
	RoleStateFlag_0,			// ��
	RoleStateFlag_TeamLeader,	// 1. �ӳ�
	RoleStateFlag_Protect,		// 2. PK����
	RoleStateFlag_Invincible,	// 3. �޵У�״̬���ܵ������й�����Ч�������޵�״̬ʱ����������������м���BUFF
	RoleStateFlag_Void,			// 4. �黯��״̬�����ᱻ�κε�λѡ�У������黯״̬ʱ���Ƴ������������������buff
	RoleStateFlag_Coma,			// 5. ���ԣ�״̬������ʹ�ü��ܣ����ߣ������ƶ������ܶ��������ǿ��Ա����˺�ץȡЧ������
	RoleStateFlag_Deform,		// 6. �α䣺״̬�����ı����Σ�����ʹ�ü��ܣ���Ʒ����Ȼ�����ƶ������ܶ���
	RoleStateFlag_Fixed,		// 7. ����״̬�������ƶ������ǿ��Ա����˺�ץȡЧ������
	RoleStateFlag_Silence,		// 8. ��Ĭ��״̬������ʹ�÷���ͨ�����ļ���
	RoleStateFlag_Disarm,		// 9. ��е��״̬������ʹ����ͨ���������ǿ���ʹ�÷���ͨ�����ļ���
	RoleStateFlag_Fear,			// 10.�־壬���ܿ��Ƶ�����ƶ�������ʹ�ü��ܣ�����
	RoleStateFlag_Dead,			// 11.����
	RoleStateFlag_DeadVirtual,	// 12.����
	RoleStateFlag_Help,			// 13.����
};

#define RoleAction_Stand		"stand"
#define RoleAction_Move			"walk"
#define RoleAction_Evade		"evade"
#define RoleAction_Chant		"chant"
#define RoleAction_Injured		"gethit"
#define RoleAction_Death		"death"
#define RoleAction_Skill1		"skill_1"
#define RoleAction_Skill2		"skill_2"
#define RoleAction_Skill3		"skill_3"
#define RoleAction_Skill4		"skill_4"
#define RoleAction_Skill5		"skill_5"
#define RoleAction_Skill6		"skill_6"
#define RoleAction_Skill7		"skill_7"

#define RoleAction string

#endif //__RoleStatus_h_