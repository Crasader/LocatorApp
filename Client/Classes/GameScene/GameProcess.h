
/***
 * ģ�飺GameProcess
 * ���ߣ�������
 * ʱ�䣺2015-7-7
 * ˵������Ϸ���̹��� ���Ŷ���������Ի���ִ��������
 */

#include "Singleton.h"
#include "db.h"
#include <deque>

enum GameProcType
{
	GameProcType_Main,		// ���� ��ǰ���̺Ų�����������ʱִ��
	GameProcType_Branch,	// ��֧ �¼���������������ִ��
};

enum GameProcFuncType
{
	GameProcFuncType_Succ,		// ʲôҲ��ִ�У�ֱ�ӳɹ�
	GameProcFuncType_Animation,	// ���Ŷ���
	GameProcFuncType_Drama,		// ����Ի�
	GameProcFuncType_Guide,		// ����
	GameProcFuncType_SystemMsg,	// ϵͳ��ʾ
};

enum GameProcEvent
{
	GameProcEvent_None,			// ���¼����� Ҳ�����������¼�������
	GameProcEvent_Timer,		// ��֡����
	GameProcEvent_LevelUp,		// ����
	GameProcEvent_AcceptTask,	// ��������
	GameProcEvent_SubmitTask,	// �ύ����
	GameProcEvent_EnterMap,		// �����ͼ
	GameProcEvent_NpcView,		// ����NPC��Ұ
	GameProcEvent_MonsterView,	// ���������Ұ

	GameProcEvent_LookInfoMonster = 3,	// ���������Ұ
	GameProcEvent_GuideNext = 4,		// ���һ������
	GameProcEvent_TaskDialog = 6,		// ����Ի�
	GameProcEvent_StudySkill = 9,		// ѧϰ����
	GameProcEvent_GetItem = 10,		// �������Ʒ
	GameProcEvent_NewAchievement = 12,// ����³ɾ�
	GameProcEvent_MenuShow = 14,		// ��������ʾ����
	GameProcEvent_BagShow = 15,		// �򿪱�������
	GameProcEvent_StrengthShow = 16,	// ��ǿ������
	GameProcEvent_TipsShow = 17,		// TIPS��ʾ 
	GameProcEvent_Max,
};

class GameProcess : public Singleton_Auto<GameProcess>
{
public:
	GameProcess();
	~GameProcess();

public:
	/* Name		��GetStepID
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ��ȡ��ǰ���ȼ�¼ID
	 * Param	: none
	 * Return	: ��ǰ���ȼ�¼ID
	 */
	inline int GetStepID(){ return m_nStepID; }

	/* Name		��SetStepID
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ���õ�ǰ���ȼ�¼ID
	 * Param	: step ���̱��
	 * Return	: void
	 */
	inline void SetStepID(int step){ m_nStepID = step; Reload(); }

	/* Name		��PushEvent
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: �׳�һ����Ϸ�����¼�
	 * Param	: event �¼����
	 * Return	: void
	 */
	inline void PushEvent(GameProcEvent event){ m_dequeEvents.push_back(event); }
	inline void ClearEvent(){ m_dequeEvents.clear(); }
	inline GameProcEvent GetCurrEventID(){ return m_nEventID; }
	/* Name		��GetEvent
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ��ȡһ����Ϸ�����¼�
	 * Param	: none
	 * Return	: GameProcEvent �¼����
	 */
	GameProcEvent GetEvent();

	/* Name		��TranslateEvent
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ����һ����Ϸ�����¼�
	 * Param	: event �¼����
	 * Return	: true �ɹ���false ʧ��
	 */
	bool TranslateEvent(GameProcEvent event);

	/* Name		��Reload
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ������Ϸ��������
	 * Param	: none
	 * Return	: true �ɹ���false ʧ��
	 */
	bool Reload();

	/* Name		��Execute
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ִ����Ϸ����
	 * Param	: pData ��������
	 * Return	: bool �ɹ�����true ʧ�ܷ���false
	 */
	bool Execute(GameProcCfg* pData);

	void Update(float dt);

protected:
	int				m_nStepID;			// ��ǰ������Ϸ����ID
	GameProcCfg*	m_pGameProcData;
	GameProcEvent	m_nEventID;			// ��ǰ�����¼�
	deque<int>		m_dequeEvents;		// �¼��б�
};

#define gGameProcess GameProcess::Instance()