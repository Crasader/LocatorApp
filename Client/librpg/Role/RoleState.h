/***
 * ģ�飺��ɫ״̬
 * ���ߣ�������
 * ʱ�䣺2015-06-19
 * ˵������ɫ����״̬�������壬��ɫ״̬����ɲ���
 */

#ifndef __RoleState_h_
#define __RoleState_h_

#include "StateMachine.h"
#include "Map/AStar.h"

enum RoleState
{
	RoleState_Idle,		// ����״̬
	RoleState_Move,		// �ƶ�״̬
	RoleState_Fight,	// ս��״̬
	RoleState_Ready,	// ��ս״̬ 
	RoleState_Injured,	// ����״̬
	RoleState_Forbidden,// ����״̬
	RoleState_Dead,		// ����״̬
};

class Role;

/***
 * ģ�飺��ɫ״̬
 * ���ߣ�������
 * ʱ�䣺2015-06-19
 * ˵������ɫ״̬����
 */
class IRoleState : public IState<Role>
{
public:
	IRoleState(int id) : IState(id){}
	virtual ~IRoleState(){}
};

/***
 * ģ�飺��ɫ״̬
 * ���ߣ�������
 * ʱ�䣺2015-06-19
 * ˵������ɫ���д���״̬
 */
class IdleState : public IRoleState
{
public:
	IdleState() : IRoleState(RoleState_Idle){}
	~IdleState(){}

	void OnEnter(Role* pTarget);
	void OnLeave(Role* pTarget);
	void OnTimer(Role* pTarget,float dt);
	void OnEvent(Role* pTarget,IStateEvent* event);
};


/***
 * ģ�飺��ɫ״̬
 * ���ߣ�������
 * ʱ�䣺2015-06-19
 * ˵������ɫ�ƶ�״̬
 */
class MoveState : public IRoleState
{
public:
	MoveState() : IRoleState(RoleState_Move),m_fDelay(0.0f){}
	~MoveState(){}

	void OnEnter(Role* pTarget);
	void OnLeave(Role* pTarget);
	void OnTimer(Role* pTarget,float dt);
	void OnEvent(Role* pTarget,IStateEvent* event);

protected:
	float m_fDelay;
};

/***
 * ģ�飺��ɫ״̬
 * ���ߣ�������
 * ʱ�䣺2015-06-19
 * ˵����ս������״̬
 */
class ReadyState : public IRoleState
{
public:
	ReadyState() : IRoleState(RoleState_Ready){}
	~ReadyState(){}

	void OnEnter(Role* pTarget);
	void OnLeave(Role* pTarget);
	void OnTimer(Role* pTarget,float dt);
	void OnEvent(Role* pTarget,IStateEvent* event);

private:
	float m_fDelayTime;
};

#endif	// __RoleState_h_