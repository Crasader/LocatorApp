#pragma once
/***
 * ģ�飺��ɫ����״̬
 * ���ߣ�������
 * ʱ�䣺2015-06-19
 * ˵������ɫ��������״̬���ϣ����ˣ�ѣ�Σ���Ĭ�ȵ�
 */

#include "RoleState.h"

/***
 * ģ�飺��ɫ״̬
 * ���ߣ�������
 * ʱ�䣺2015-06-19
 * ˵������ɫ������״̬������ѣ�Σ������ȵ������Ƶ�״̬
 */
class ForbiddenState : public IRoleState
{
public:
	ForbiddenState() : IRoleState(RoleState_Forbidden){}
	~ForbiddenState(){}

	void OnEnter(Role* pTarget);
	void OnLeave(Role* pTarget);
	void OnTimer(Role* pTarget,float dt);
	void OnEvent(Role* pTarget,IStateEvent* event);

protected:
	float m_fElapsed;		// ��ʱ��
};