#include "pk_achievement.h"

namespace pk{

	//����������ɵĳɾ�
	bool OnGS2C_FinishAndUnFinishAchievementList(GS2C_FinishAndUnFinishAchievementList* value)
	{
		return true;
	}

	//�ﵽĳ�ɾ�ʱ�����͸óɾ�
	bool OnGS2C_AddAchievement(GS2C_AddAchievement* value)
	{
		return true;
	}
	//ʹ�û���ȡ���ɾ�
	bool OnGS2C_UseAchievement(GS2C_UseAchievement* value)
	{
		return true;
	}

	bool OnGS2C_UpdateAchievementFinishCnt(GS2C_UpdateAchievementFinishCnt* value)
	{
		return true;
	}

	bool OnGS2C_AchieveProgressChange(GS2C_AchieveProgressChange* value)
	{
		return true;
	}
}

