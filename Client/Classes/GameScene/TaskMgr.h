#ifndef __TaskMgr_h_
#define __TaskMgr_h_

#include "GameDef.h"
#include "Singleton.h"
#include "GameDataManager.h"
#include "Net/pk_task.h"
#include "Net/pk_item.h"

enum NPCTaskState	// NPC���ϵ�����״̬��������ɽ��������С��ɽӣ���
{
	NTS_NOTHING = 0,
	NTS_ONGOING,
	NTS_ACCEPTABLE,
	NTS_FINISHABLE,
};

enum eTaskState		// ���������״̬���ɽ��������С�δ�ӣ���
{
	TS_NOT_ACCEPTED = 0,
	TS_ONGOING,
	TS_FINISHABLE,
	TS_FINISHED,
};

struct TaskStage	// ��������Ľ׶�Ҫ�����£��ӡ���������
{
	int		nMapID;
	int		nTargetID;
	Point	ptPos;
	string	strTargetName;
};

struct TaskTarget
{
	string strName;
	int	nID;
	pk::taskProgress progress;	
};

struct TaskAward
{
	struct ItemAward
	{
		ItemCfg*	pItem;
		int			nNum;
		bool		nBind;
	};
	vector<ItemAward>	vtrItems;
	bool				bSelectable;
	int					nExp;
	int					nHonour;
	int					nCoin;
	int					nCoinB;
};

enum eTaskStage	// ��ʶ���������׶Σ��ӡ�������
{
	TS_ACCEPT,
	TS_DO,
	TS_TURNIN,

	TS_NOUSE
};

class Task
{
public:
	Task(int id);
	virtual ~Task(){};
	virtual bool CanFinish() = 0;
	TaskCfg*	 GetData()						{return m_pData;}
	int			 GetID()						{return m_pData->id;}
	int			 GetType()						{return m_pData->type;}
	string&		 GetName()						{return m_pData->title;}
	//�����������ID
	int			 GetAcceptDramaId()				{return m_pData->accept_drama;}
	//���븱������ID
	int			 GetEnterCopyDramaId()			{return m_pData->enter_copy_drama;}
	//�˳���������ID
	int			 GetQuitCopyDramaId()			{return m_pData->quit_copy_drama;}

	eTaskStage	 GetCurStage();
	TaskStage*	 GetStage(eTaskStage nStage)	{return &m_arrTargets[nStage];}
	TaskTarget*	 GetTarget()					{return &m_Target;}
	TaskAward*	 GetAward()						{return &m_Award;}
	int			 GetCurTurn()					{return m_nTurn;};
	void		 SetCurTurn(int nNum)			{m_nTurn = nNum;};
	void		 SetTargetCurNum(int nNum);//		{m_Target.progress.curCnt = nNum;};
	void		 GoToTarget(eTaskStage nStage);
	string		 GetManagedTalkString(eTaskStage nStage);
	string		 GetManagedTargetString(eTaskStage nStage);
	int			 GetCopyID()					{return m_pData->copyid;}; //liyang 2015/8/31 �õ��ؿ�����ID

private:
	string _manage_tring(string strText);

protected:
	TaskCfg*		m_pData;
	TaskStage		m_arrTargets[TS_NOUSE];	// ������׶�Ҫ�����Ŀ�ĵ�
	TaskTarget		m_Target;				// Ŀǰ���һ��Ŀ��
	TaskAward		m_Award;
	int				m_nTurn;				// �ڼ���
};

class CommonTask : public Task
{
public:
	CommonTask(int id): Task(id){}
	virtual bool CanFinish();
};

// �������񣬱���Ӻ��ѣ������ᣬ�ܣ������������޹��ɵ�����
class SpecialTask : public Task
{
public:
	SpecialTask(int id): Task(id){}
	virtual bool CanFinish(){return true;}
};

class TasksIterator : public ForeachIterator<TaskCfg>
{
public:
	TasksIterator():m_pvtrLevelTask(), m_pvtrMainTask(), m_pvtrNPCTaskAcc(), m_pvtrNPCTaskFin(){m_nNPC = 0;}
	bool execute(TaskCfg* pItem)
	{
		if (m_pvtrLevelTask && pItem->autoget != 0)
		{
			(*m_pvtrLevelTask)[pItem->autoget] = pItem;
		}
		if (m_pvtrMainTask && pItem->type == 2)	// ����
		{
			m_pvtrMainTask->push_back(pItem);
		}

		if (m_nNPC)
		{
			if (pItem->startnpc == m_nNPC)
				m_pvtrNPCTaskAcc->push_back(pItem->id);
			if (pItem->endnpc == m_nNPC)
				m_pvtrNPCTaskFin->push_back(pItem->id);
		}
		return true;
	}

public:
	map<int, TaskCfg*>*	m_pvtrLevelTask;
	vector<TaskCfg*>*	m_pvtrMainTask;
	vector<int>*		m_pvtrNPCTaskAcc;
	vector<int>*		m_pvtrNPCTaskFin;
	int					m_nNPC;
}; 


class TaskMgr : public Singleton_Auto<TaskMgr>
{
public:
	TaskMgr();
	~TaskMgr();

	//bool Initialize();
	void			Update(float dt);

	Task*			AddTask(int id);
	Task*			SetAcceptableChain(pk::GS2C_SubmitTaskChain *pTask);
	void			AddFinishedTask(pk::completeTask task);
	void			FinishTask(int id);
	void			FinishTaskChain(int id);
	bool			CanTaskBeAccepted(int id);
	bool			CanTaskBeFinished(int id);
	eTaskState		GetTaskState(int id);
	Task*			GetTask(int id);	// ���ˣ����߿ɽ�
	Task*			GetTaskOngoing(int id);
	vector<Task*>&	GetAllTasksOngoing();
	//��ø�����ص�����
	Task*			GetMapTask(int nMapId);
	TaskAward*		GetMapTaskAward(int nMapId);
	int&			GetTaskFinishedTimes(int id);
	NPCTaskState	GetTheseTaskState(vector<int> vtrTasks);
	bool			IsTaskChanged()	{return m_bTaskChanged;}
	void			TaskChanged();
	void			SetTsakProgress(int nTaskID, pk::taskProgress *pData);
	Task*			GetMainTask();
	Task*			GetChainTask();
	Task*			GetAcceptableMainTask()	{return m_pAcceptable;};
	Task*			GetAcceptableChain()	{return m_pAcceptableChain;};
	vector<Task*>&	GetAcceptableTask()		{return m_vtrAcceptable;};
	void			RemoveChainTask();
	void			AutoDoAfterMoveTo(int nTaskID, int nMap, Point pos)	{m_nTaskIDGoingTo = nTaskID; m_nMapGoingTo = nMap; m_ptPointGoingTo = pos;}
	void			Clear();
private:
	vector<Task*>::iterator	_get_task(int id);
	void					_find_acceptable();
private:
	Task*				m_pAcceptable;		// �ɽӵ�����
	Task*				m_pAcceptableChain;
	vector<TaskCfg*>	m_vtrAllTask;		// ��Ϸ���������������������жϿɽӵ�
	vector<Task*>		m_vtrAcceptable;	// �ɽӵ���������
	vector<Task*>		m_vtrAccepted;		// �ѽӵ���������
	map<int, int>		m_vtrFinished;		// id,����
	map<int, TaskCfg*>	m_vtrLevelTask;		// �����ȼ�������
	bool				m_bTaskChanged;		// ����ˢ��UI����ֱ��֪ͨUI��UI����ȡ���ֵ
	int					m_nFrameCounter;	// ����m_bTaskChanged�����������ֵ�֡��

	// ����������ʱ��Ŀ��ص��Զ���֡��ɼ�
	int					m_nMapGoingTo;		// ��ֱ���ĵ�ͼ
	Point				m_ptPointGoingTo;	// ��ֱ���ľ���λ�ã����˿����һ����ɼ�
	int					m_nTaskIDGoingTo;	// �����ƶ�������
};

#define gTaskManager	TaskMgr::Instance()

#endif