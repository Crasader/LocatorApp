#pragma once

#include "RoleState.h"

/***
 * ģ�飺��ɫ״̬
 * ���ߣ�������
 * ʱ�䣺2015-06-19
 * ˵������ɫ����״̬
 */
class DeadState : public IRoleState
{
public:
	DeadState() : IRoleState(RoleState_Dead){}
	~DeadState(){}

	void OnEnter(Role* pTarget);
	void OnLeave(Role* pTarget);
	void OnTimer(Role* pTarget,float dt);
	void OnEvent(Role* pTarget,IStateEvent* event);

	void HitActionCallBack(Role* pTarget);

protected:

};