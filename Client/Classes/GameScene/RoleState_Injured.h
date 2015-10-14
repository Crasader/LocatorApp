#pragma once

#include "RoleState.h"

/***
 * ģ�飺��ɫ״̬
 * ���ߣ�������
 * ʱ�䣺2015-06-19
 * ˵������ɫ����Ӳֱ״̬
 */
class InjuredState : public IRoleState
{
public:
	InjuredState() : IRoleState(RoleState_Injured){}
	~InjuredState(){}

	void OnEnter(Role* pTarget);
	void OnLeave(Role* pTarget);
	void OnTimer(Role* pTarget,float dt);
	void OnEvent(Role* pTarget,IStateEvent* event);

protected:
	float m_fElapsed;		// ��ʱ��
};