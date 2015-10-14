#include "pk_guild.h"
#include "DataPool.h"

namespace pk{

	// ���½�һ�������
	bool OnGS2C_CreateGuild_Result(GS2C_CreateGuild_Result *value)
	{
		return true;
	}

	// �����½�һ������
	bool OnGS2C_CreateGuild(GS2C_CreateGuild *value)
	{
		return true;
	}

	// ����Ϸ��ʼ�������б�
	bool OnGS2C_GuildList(GS2C_GuildList *value)
	{
		Legion_cl* legion = gDataPool->getLegionData();
		legion->initLegion(value->vec);
		return true;
	}

	// ����Ϸ��ʼ���������Ա
	bool OnGS2C_MemberList(GS2C_MemberList *value)
	{
		Legion_cl* legion = gDataPool->getLegionData();
		legion->initMemberList(value->vec);
		return true;
	}
	 
	// ����Ϸ��ʼ��������
	bool OnGS2C_ApplyList(GS2C_ApplyList *value)
	{
		return true;
	}

	// ����������
	bool OnGS2C_RequestJoinGuild(GS2C_RequestJoinGuild *value)
	{
		return true;
	}

	// ����ͬ��һ����������
	bool OnGS2C_JoinGuild_Result(GS2C_JoinGuild_Result *value)
	{
		return true;
	}

	// ��������
	bool OnGS2C_UpgradeGuild_Result(GS2C_UpgradeGuild_Result *value)
	{
		return true;
	}

	// ĳ������������
	bool OnGS2C_UpgradeGuild(GS2C_UpgradeGuild *value)
	{
		return true;
	}

	// ĳ��/�� �˳�����
	bool OnGS2C_ExitGuild_Result(GS2C_ExitGuild_Result *value)
	{
		return true;
	}

	// ĳ��/�� ������
	bool OnGS2C_KillOutPlayer_Result(GS2C_KillOutPlayer_Result *value)
	{
		return true;
	}

	// ת�ƻ᳤
	bool OnGS2C_TransferLeader_Result(GS2C_TransferLeader_Result *value)
	{
		return true;
	}
	// �¹���
	bool OnGS2C_UpdateAnnouncement_Result(GS2C_UpdateAnnouncement_Result *value)
	{
		return true;
	}

	// ���׺�
	bool OnGS2C_GuildDonation_Result(GS2C_GuildDonation_Result *value)
	{
		return true;
	}

	// ĳ���ᷱ�ٶȱ仯
	bool OnGS2C_UpdateGuildProsperity(GS2C_UpdateGuildProsperity *value)
	{
		return true;
	}


	// ��ɢ����
	bool OnGS2C_DissolveGuild_Result(GS2C_DissolveGuild_Result *value)
	{
		return true;
	}

	// ������ս
	bool OnGS2C_GuildWar(GS2C_GuildWar *value)
	{
		return true;
	}

	bool OnGS2C_SetDeputyLeader_Result(GS2C_SetDeputyLeader_Result* value)
	{
		return true;
	}

	bool OnGS2C_RemoveDeputyLeader_Result(GS2C_RemoveDeputyLeader_Result* value)
	{
		return true;
	}

	bool OnGS2C_UpgradeSkill(GS2C_UpgradeSkill* value)
	{
		return true;
	}
}

