#ifndef __GameDef_h_
#define __GameDef_h_

#include "zm.h"
#include "cocos2d.h"
USING_NS_CC;
#include "GameShared.h"

#define PI (3.1415926)

#ifdef _GameEditor

#else

#endif	// _GameEditor

#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
#define atoll _atoi64
#endif

#define Default_Font_File "assets/fonts/DroidSansFallback.ttf"

#define gDirector	Director::getInstance()
#define gFileUtils	FileUtils::getInstance()
#define readFromFile(NAME)	Data data=gFileUtils->getDataFromFile(NAME);ByteArray reader(data.getBytes(),data.getSize());

#define TIME_COST_DEF
#ifdef TIME_COST_DEF
#define TIME_COST_BEGIN struct timeval now1;\
struct timeval now2;\
	gettimeofday(&now1, NULL);

#define TIME_RECLOCK_BEGIN gettimeofday(&now1, NULL);

#define TIME_COST_LOG(STR)	gettimeofday(&now2, NULL);\
{float fDeltaTime = (now2.tv_sec - now1.tv_sec) + (now2.tv_usec - now1.tv_usec) / 1000.0f;\
	LOGW("%s cost %.4f ms!",STR,fDeltaTime);}

#define TIME_COST_LOG_RECLOCK_BEGIN(STR)  TIME_COST_LOG(STR)\
	TIME_RECLOCK_BEGIN

#define TIME_COST_LOG_IF(STR,CT)	gettimeofday(&now2, NULL);\
{float fDeltaTime = (now2.tv_sec - now1.tv_sec) + (now2.tv_usec - now1.tv_usec) / 1000.0f;\
	if( fDeltaTime > CT ) LOGW("%s cost %.4f ms!",STR,fDeltaTime);}
#else
#define TIME_COST_BEGIN 

#define TIME_RECLOCK_BEGIN 

#define TIME_COST_LOG(STR)	

#define TIME_COST_LOG_RECLOCK_BEGIN(STR)  TIME_COST_LOG(STR)\
	TIME_RECLOCK_BEGIN

#define TIME_COST_LOG_IF(STR,CT)
#endif

#define FLOAT_TO_INT(F)	(int)(F)
#define FLOAT_TO_INT_5(F) ((F-(int)(F)>=0.5f)?(int)(F+1):(int)(F))

//����ģʽ���׷��ִ���ص�
#define ReleaseMode			(1)
#define DebugMode			(0)
#define BREAK_IF(cond)           if(cond&&DebugMode) break

// 100-999Ϊ��ͼ���
// 1000-9999Ϊһ�㶯�����
// 10000-99999Ϊ���ＰNPC���
// 100000-999999Ϊװ�����
// 1000000-9999999Ϊ���߱��
// 10000000-99999999Ϊ���ＰNPCģ�Ͷ������
// 100000000-999999999Ϊ����ģ�Ͷ������
// 1000000000-199999999Ϊ��������ﶯ�����

// װ����Ź���ְҵ+�Ա�0��+��λ��00��+�ȼ���00��+Ʒ�ʣ�0��
// ���磺Ůսʿ���壬400000���з�ʦ10����ɫ���ۣ�201104;

// ���߱�Ź��򣺵������ͱ�ţ�0000��+��ţ�000��

// ģ�Ͷ�����Ź���װ����Ż��߹����Ż���NPC��ţ�000000��+������ţ�00��+����0��

typedef unsigned int	EquipmentID;
typedef __int64			AccountID;
typedef __int64			RoleID;
typedef __int64			PlayerID;
typedef __int64			ObjectID;



inline long GetCurrTimeMS()
{
	struct timeval now;
	gettimeofday(&now, nullptr);
	long ret = now.tv_sec*1000 + now.tv_usec / 1000;
	return ret;
}

inline long long GetCurrTimeMicroS()
{
	struct timeval now;
	gettimeofday(&now, nullptr);
	long long ret = now.tv_sec*1000000 + now.tv_usec;
	return ret;
}

#endif				// __GameDef_h_