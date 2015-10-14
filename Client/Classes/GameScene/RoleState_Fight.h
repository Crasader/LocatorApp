#pragma once

#include "RoleState.h"
#include "SkillScript.h"

/***
 * ģ�飺��ɫ״̬
 * ���ߣ�������
 * ʱ�䣺2015-06-19
 * ˵������ɫս��״̬�������ͷż��ܣ�ս������
 */

class FightState : public IRoleState
{
public:
	FightState();
	~FightState();

	void OnEnter(Role* pTarget);
	void OnLeave(Role* pTarget);
	void OnTimer(Role* pTarget,float dt);
	void OnEvent(Role* pTarget,IStateEvent* event);

private:
	SkillScript* m_pSkillScript;	// �����߼�
};