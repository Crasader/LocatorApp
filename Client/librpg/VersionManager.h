#ifndef __VersionManager_h_
#define __VersionManager_h_

#include "GameDef.h"
#include "Version.h"
#include "Singleton.h"

// ����APK���а汾�ļ�����
typedef struct _local_version_desc_ 
{
	int				pid;				// APK�������ƽ̨�ű�ʶ
	int				pro;				// ����Э���
	VersionDef		ver;				// ���ذ汾��
	int				ext;				// ��չ��Դ����ʶ
	string			url;				// �����ļ��б��ļ�URL
	string			ip;					// ��¼������IP
	unsigned short	port;				// ��¼�������˿ں�
}LVD;


enum
{
	ResExtPack1 = 0,
	ResExtPackN,
};

#define ResExtPack(N)	1<<(N)

// .rvd��Դ�汾�ļ�����
typedef struct _resource_version_desc_
{
	_resource_version_desc_() : ext(0){}
	VersionDef	ver;			// ��Դ�汾��
	int			ext;			// ��չ��Դ����ʶ,��λ��ʶ

	inline bool hasExtension(int idx){
		return (ext & idx) != 0;
	}

	inline void setExtension(int idx){
		ext |= idx;
	}

	inline void clrExtension(int idx){
		ext &= ~idx;
	}
}RVD;

// ���·������ϰ汾�ļ�����
typedef struct _server_version_desc_
{
	VersionDef		ver;			// ���°汾��
	string			ip;				// ��¼������IP
	unsigned short	port;			// ��¼�������˿ں�
}SVD;

class VersionManager : public Singleton_Auto<VersionManager>
{
public:
	VersionManager();
	~VersionManager();

	bool initialize();
	void release();

public:
	bool	readLVDFromFile(const string& xml);
	bool	readLVDFromBuffer(const char* pBuffer,size_t size);

	bool	readSVDFromFile(const string& xml);
	bool	readSVDFromBuffer(const char* pBuffer,size_t size);

	bool	readRVD(const string& rvd);
	bool	saveRVD(const string& rvd);

	bool	readUpdateDescFromFile(const string file);
	bool	readUpdateDescFromBuffer(const char* pBuffer,size_t size);

	bool	isResExpired();
	bool	isApkExpired();
	bool	isDebugMode();
	bool	isApkNeedUpdate();
	bool	isResNeedUpdate();

	VersionDef*		get_target_version();
	string			key_to_url(string key);

	inline string	key_to_apk(){ 
		string ret = "tz_v";
		ret += m_svd.ver.to_str();
		return ret;
	}
	inline string	key_to_res_dif(VersionDef& ver){
		string ret = "tz_dif_v";
		ret += ver.to_str();
		ret += "_v";
		ret += m_rvd.ver.to_str();
		return ret;
	}
	inline string	key_to_res_ext(int n){
		string ret = "tz_ext_v";
		ret += m_rvd.ver.to_str();
		ret += "_1";
		return ret;
	}

	inline LVD&	lvd(){ return m_lvd; }
	inline RVD&	rvd(){ return m_rvd; }
	inline SVD&	svd(){ return m_svd; }
	inline SVD&	svd_d(){ return m_svd_d; }
	
protected:
	LVD		m_lvd;		// APK���а汾�ļ�����
	RVD		m_rvd;		// ��Դ�汾�ļ�����
	SVD		m_svd;		// �������汾�ļ���ʽ�汾����
	SVD		m_svd_d;	// �������汾�ļ����԰汾����
	int		m_debug;	// ���԰汾��־

	typedef map<string,VersionDef>	VersionMapping;
	VersionMapping	m_mapping;	// �汾ӳ���
	typedef map<string,string>		UpdateList;
	UpdateList		m_list;		// �����ļ��б�
};

#define gGameVersion VersionManager::Instance()

#endif