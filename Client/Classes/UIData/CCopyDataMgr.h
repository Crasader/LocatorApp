/****************************************************************************
 �������ݹ�����
 ������
 2015-09-10
 ****************************************************************************/
#pragma once
#include "GameDef.h"
#include "Net/pk_map.h"
#include "GameScene/db.h"
#include "GameScene/GameMapTypes.h"

typedef enum _placeType
{
	PlaceType_None = -1,
	PlaceType_Big,			//��ص�
	PlaceType_Small,		//С�ص�
	PlaceType_Count,
}PlaceType;

typedef struct _worldPlace
{
	int worldMapId;			//��ص�
	bool unLock;			//�Ƿ����
}WorldPlace;

typedef struct _gameCopy
{
	int worldMapId;			//��ص�
	int localeId;			//С�ص�
	int mapId;				//����
	bool baseCopy;			//true ��������,false ���񸱱�
	bool unLock;			//�Ƿ����
	GameMapTaskType TaskType;
}GameCopy;

typedef	 vector<GameCopy>			 GameCopys;
typedef	 vector<WorldPlace>			 WorldPlaces;

class CCopyDataMgr
{
public:
	CCopyDataMgr();
	~CCopyDataMgr();

	void					Init();
	void					Clear();

	//��ô�ص��б�
	WorldPlaces&			GetWorldPlaces() { return m_worldPlaces; }
	//��ô�ص��С�ص��б�(���������б�)
	vector<GameCopy*>		GetLocaleList(int nWorldMapId);
	//���С�ص�ĸ����б�
	vector<GameCopy*>		GetMapList(int nLocaleId);
	//���⸱���Ƿ��ڸ����б�
	bool					IsSpecialTaskExist(vector<GameCopy*>& gameCopys,GameMapTaskType type);
	//���С�ص�ĸ����б���������
	vector<GameCopy*>		GetMapListAndBaseGameCopy(int nLocaleId,GameCopy* &pBaseGameCopy);
	//�������񸱱�
	void					AddTaskGameCopy(int nWorldMapId, int nLocaleId, int nMapId);
	//�����Ϸ����
	GameCopy*				GetGameCopy(int nMapId);

	//��ʼ����ص��С�ص������Ϣ
	void					InitPlacesLockInfo(pk::GS2C_OPEN_MAP_LIST *value);
	//���½�����Ϣ
	void					UpdatePlacesLockInfo(pk::GS2C_OPEN_MAP_UPDATE_OR_ADD* value);
	void					UpdateBigPlaceLockInfo(pk::OpenMap openMap);
	void					UpdateSmallPlaceLockInfo(pk::OpenMap openMap);
	//�����Ƿ����
	//��ص��Ƿ�����
	bool					IsWorldPlaceUnLock(int nWorldPlaceId);
	bool					IsGameCopyUnLock(int nMapId);

	//����UI
	class CCopyMapUI*		GetCopyMapUI() { return m_copyMapUIOpened; }
	void					SetCopyMapUI(class CCopyMapUI* pMapUI) { m_copyMapUIOpened=pMapUI; }

	//����ĸ���������������
	class Task*				GetCopyDoingTask() { return m_copyDoingTask; }
	void					SetCopyDoingTask(class Task* pTask) { m_copyDoingTask=pTask; }

private:
	GameCopys				m_gameCopys;						  //��Ϸ���еĸ���
	WorldPlaces				m_worldPlaces;						  //��Ϸ��ص�

	class CCopyMapUI*		m_copyMapUIOpened;					  //�򿪵ĸ���UI
	class Task*				m_copyDoingTask;					  //����ĸ���������������
};

class CGameCopysItr :public ForeachIterator<WorldmapCfg>
{
public:
	CGameCopysItr(GameCopys& vtrGameCopys,WorldPlaces& vtrWorldPlaces)
		:m_vtrGameCopys(vtrGameCopys)
		,m_vtrWorldPlaces(vtrWorldPlaces)
	{

	}
	~CGameCopysItr()
	{

	}

	virtual bool execute(WorldmapCfg* item);

private:
	GameCopys&			m_vtrGameCopys;
	WorldPlaces&		m_vtrWorldPlaces;
};