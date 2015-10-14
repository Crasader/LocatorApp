#ifndef __zm_Log_h_
#define __zm_Log_h_

#include "Singleton.h"
#include <mutex>

enum LogType
{
	LogType_Info,		// �����Ϣ
	LogType_Warnning,	// ����
	LogType_System,		// ϵͳ
	LogType_Error,		// ����
	LogType_Debug,		// ����
	LogType_Max,
};

// ��־�����ʽ��[ʱ��][Type] ��־����
// ���磺
//[2015/05/09 12:15:08][debug] ��־��Ϣ��i�����ķ���
//[2015/05/09 12:15:08][warnning] ... ��־��Ϣ��i�����ķ��� ...
//[2015/05/09 12:15:08][error] ��־��Ϣ��i�����ķ���
//[2015/05/09 12:15:08][info] ... ��־��Ϣ��i�����ķ��� ...
//[2015/05/09 12:15:08][info] ��־��Ϣ��i�����ķ���
//[2015/05/09 12:15:08][warnning] ... ��־��Ϣ��i�����ķ��� ...

class zmLog : public Singleton_Auto<zmLog>
{
public:
	zmLog();
	~zmLog();

	bool Open(const char* file);
	void Close();
	void Log(LogType type,const char* format, ... );
	const char* GetTypeString(LogType type);
	inline bool IsOpen(){ return m_fptr != NULL; }

protected:
	FILE* m_fptr;
	std::mutex m_mutext;
};

#define gLog zmLog::Instance()
#define LOGI(FMT, ...)	gLog->Log(LogType_Info,FMT,##__VA_ARGS__)
#define LOGW(FMT, ...)	gLog->Log(LogType_Warnning,FMT,##__VA_ARGS__)
#define LOGS(FMT, ...)	gLog->Log(LogType_System,FMT,##__VA_ARGS__)
#define LOGE(FMT, ...)	gLog->Log(LogType_Error,FMT,##__VA_ARGS__)
#define LOGD(FMT, ...)	gLog->Log(LogType_Debug,FMT,##__VA_ARGS__)

#endif