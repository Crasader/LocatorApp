/***
 * ģ�飺��ɫָ��
 * ���ߣ�������
 * ʱ�䣺2015-07-2
 * ˵������ɫָ�����ݶ���
 * ÿ����ɫ����ͨ��ָ��ȥ��������Ϊ
 */

#pragma once

// ָ��
enum RoleCommandType
{
	RoleCommand_None,
	RoleCommand_Move,	// �ƶ�ָ��
	RoleCommand_Attack,	// ����Ŀ��ָ��
	RoleCommand_Skill,	// ʹ�ü���ָ��
	RoleCommand_Pursue,	// ׷��Ŀ��ָ��
};

struct RoleCommand
{
	int type;

	union
	{
		struct 
		{
			int x;
			int y;
		}pos;			// �ƶ�ָ����� �ƶ�Ŀ���

		struct
		{
			int		skillid;	// ����ID
			__int64 targetid;	// Ŀ��ID
		}skill;			// ����ָ����� 
		

	}param;
};