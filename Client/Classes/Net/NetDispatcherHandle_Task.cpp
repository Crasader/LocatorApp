#include "GameDef.h"
#include "pk_task.h"
#include "GameScene/MessageCenter.h"
#include "GameScene/GameUILayer.h"
#include "UI/TaskUI.h"
#include "UI/TaskDialog.h"
#include "GameScene/TaskMgr.h"
#include "GameScene/Hero.h"
#include "../GameScene/Monster.h"
#include "GameScene/BeginnerGuide.h"
#include "UI/MissionUI.h"
#include "UI/DramaUi.h"
#include "GameScene/GameProcess.h"

namespace pk{

	bool OnGS2C_AccpetTask_Result(struct pk::GS2C_AccpetTask_Result *value)
	{
		if (value->retCode == 1)
		{
			// �׳������¼�
			gGameProcess->PushEvent(GameProcEvent_AcceptTask);
			Task *pTask = gTaskManager->AddTask(value->taskId);
			DramaUI::PlayDrama(pTask->GetAcceptDramaId());
			CMissionUI* pUI = dynamic_cast<CMissionUI*>(gGameUILayer->getActiveUI(IDU_MissionlUI));
			if (pUI)
			{
				pUI->onOpen();
			}

			//pObjectList objList;
			//gMap->getObjectManager()->getObjectsInView(mapObjectType_Npc, objList);
			//for (size_t i = 0; i < objList.size(); i++)
			//{
				//if (((CNpc*)objList[i])->GetDataID() ==  pTask->GetTarget()->nID)
				//{
				//	((CNpc*)objList[i])->CheckForCollect();	// �Ӳɼ����������ߵĲɼ����������
				//}
			//}

			// ������˾�����ͬһNPC�������������ʾ�ύ����
			/*if (gTaskManager->CanTaskBeFinished(value->taskId) && pTask->GetData()->startnpc == pTask->GetData()->endnpc)
			{
			TaskDialog::Open(pTask);
			}*/
			gCocosAudio->PlayEffect(111);
		}
		return true;
	}
	bool OnGS2C_CannelTask_Result(struct pk::GS2C_CannelTask_Result *value)
	{
		return true;
	}
	bool OnGS2C_SubmitTask_Result(struct pk::GS2C_SubmitTask_Result *value)
	{
		if (value->retCode == 1)
		{
			// �׳������¼�
			gGameProcess->PushEvent(GameProcEvent_SubmitTask);
            
			gTaskManager->FinishTask(value->taskId);

			CMissionUI* pUI = dynamic_cast<CMissionUI*>(gGameUILayer->getActiveUI(IDU_MissionlUI));
			if (pUI)
			{
				pUI->onOpen();
			}

			// ������˾�����ͬһNPC������������������ʾ���������
			//if (gTaskManager->GetAcceptableMainTask() && nNPCID == gTaskManager->GetAcceptableMainTask()->GetData()->startnpc)
			//{
			//	TaskDialog::Open(gTaskManager->GetAcceptableMainTask());
			//}
	
		}
		else
		{
			switch (value->retCode)
			{
			case -5:
				// ��ҳ�������
				gMessageCenter->SystemMessage(958);
			case -6:
				// �����ռ䲻��
				gMessageCenter->SystemMessage(955);
				break;
			case -7:
				gMessageCenter->SystemMessage(957);
				break;
			}
		}
		return true;
	}
	bool OnGS2C_AcceptTaskList(struct pk::GS2C_AcceptTaskList *value)
	{
		for (size_t i = 0; i < value->vec.size(); i++)
		{
			Task* pTask = gTaskManager->AddTask(value->vec[i].taskId);
			if (value->vec[i].progress.size() > 0)
				pTask->SetTargetCurNum(value->vec[i].progress[0].curCnt);
		}
		return true;
	}
	bool OnGS2C_CompleteTaskList(struct pk::GS2C_CompleteTaskList *value)
	{
		for (size_t i = 0; i < value->vec.size(); i++)
		{
			gTaskManager->AddFinishedTask(value->vec[i]);
		}
		return true;
	}
	bool OnGS2C_TaskProgressChange(struct pk::GS2C_TaskProgressChange *value)
	{
		gTaskManager->SetTsakProgress(value->taskId, &value->progress[0]);
		CMissionUI* pUI = dynamic_cast<CMissionUI*>(gGameUILayer->getActiveUI(IDU_MissionlUI));
		if (pUI)
		{
			pUI->updateMission(value->taskId);
		}

		string strName = TaskData.get(value->taskId)->targethittext;

		if (value->progress[0].curCnt) 
		gMessageCenter->SystemMessage(SystemMessage_Prompt, CCString::createWithFormat("%s %d / %d", strName.c_str(),
										value->progress[0].curCnt, value->progress[0].targetCnt)->getCString());
		return true;
	}
	/*
	bool OnGS2C_StartGather_Result(GS2C_StartGather_Result *value)
	{
		if (value->retCode == 1)
		{
			if(!gMap)
				return false;

			CNpc *pNPC = dynamic_cast<CNpc*> (gMap->getObjectManager()->getObject(value->gatherId));
			if (pNPC)
			{
				pNPC->CollectStart();
			}
		}
	
		return true;
	}
	*/
	bool OnGS2C_CompleteGather_Result(GS2C_CompleteGather_Result *value)
	{
		if(!gMap)
			return false;

		CNpc *pNPC = dynamic_cast<CNpc*> (gMap->getObjectManager()->getObject(value->gatherId));
		if (pNPC)
		{
			pNPC->CollectFinished();
		}
		return true;
	}
/*
	bool OnGS2C_InterruptGather(GS2C_InterruptGather *value)
	{
		if (1 > value->interruptType || !gMap)
		{
			return false;
		}

		IRole *pRole = (IRole *) (gMap->getObjectManager()->getObject(value->gatherId));
		CNpc* pNpc = (CNpc*)pRole;
		//CMonster* pMonster = (CMonster*)pRole;	//�����ſ����жϲɼ�
		if (pNpc)
		{
			pNpc->CollectInterrupted();
		}
		//if (pMonster)
		//{
		//	pMonster->CollectInterrupted();
		//}
		return true;
	}*/


	//-------------------------------������-----------------------------------------------------------

	bool OnGS2C_AccpetTaskChain(GS2C_AccpetTaskChain *value)
	{
		Task *pTask = gTaskManager->AddTask(gTaskManager->GetAcceptableChain()->GetID());

		if (pTask)	// ĳ��������˺�ɾ����ӦNPC��������
		{
			MapObjectList objList;
			gMap->getObjectManager()->getObjectsInView(mapObjectType_Npc, objList);
			for (size_t i = 0; i < objList.size(); i++)
			{
				vector<int> &tasks = ((CNpc*)objList[i])->GetTaskAcc();
				vector<int>::iterator it;
				if ((it = find(tasks.begin(), tasks.end(), pTask->GetID())) != tasks.end())
				{
					tasks.erase(it);
				}
			}
		}

		// ������˾�����ͬһNPC�������������ʾ�ύ����
		if (gTaskManager->CanTaskBeFinished(pTask->GetID()) && pTask->GetStage(TS_ACCEPT)->nTargetID == pTask->GetStage(TS_TURNIN)->nTargetID)
		{
			TaskDialog::Open(pTask);
		}
		gCocosAudio->PlayEffect(111);

		return true;
	}

	bool OnGS2C_CannelTaskChain(GS2C_CannelTaskChain *value)
	{
		Task *pTask = gTaskManager->GetChainTask();
		if (pTask)	// ĳ������ȡ����ɾ����Ӧ�ύNPC��������
		{
			MapObjectList objList;
			gMap->getObjectManager()->getObjectsInView(mapObjectType_Npc, objList);
			for (size_t i = 0; i < objList.size(); i++)
			{
				vector<int> &tasks = ((CNpc*)objList[i])->GetTaskFin();
				vector<int>::iterator it;
				if ((it = find(tasks.begin(), tasks.end(), pTask->GetID())) != tasks.end())
				{
					tasks.erase(it);
				}
			}
		}

		gTaskManager->RemoveChainTask();
		CNpc::s_AddtionalTasks.clear();

		return true;
	}
}

