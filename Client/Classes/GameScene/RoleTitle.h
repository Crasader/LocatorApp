/***
 * ģ�飺RoleTile
 * ���ߣ�������
 * ʱ�䣺2015-06-19
 * ˵������ɫͷ���ϵ�Ѫ�������Ƶ���ʾ����ɫ��ν���ɾ���Ч
 */

#ifndef __RoleTile_h_
#define __RoleTile_h_

#include "GameDef.h"
#include "UI/GameUI.h"
#include "GameScene/TaskMgr.h"

#define CampColor_Monster	Color3B::WHITE
#define CampColor_Player	Color3B(0x12,0xea,0x2c)
#define CampColor_Red		Color3B::RED
#define CampColor_Blue		Color3B::BLUE

class RoleFighter;

class RoleTitle : public Layer
{
public:
	RoleTitle(RoleFighter* pRole);
	~RoleTitle();

	/* Name		��createWithRole
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ���ݽ�ɫ���󴴽�һ��RoleTile
	 * Param	: pRole ��ɫ����
	 * Return	: RoleTitle* 
	 */
	static RoleTitle* createWithRole(RoleFighter* pRole);

	/* Name		��init
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ��ʼ��һ��RoleTile
	 * Param	: none
	 * Return	: bool true �ɹ���false ʧ��
	 */
	bool init();

	void updateRevivePanel();
	void clickReviveButton(Ref* pSender, TouchEventType type);

	void SetNameColor(Color3B clr);
	void SetTitleColor(Color3B clr);
	void SetGuildNameColor(Color3B clr);

	void SetNamePos(float x,float y);
	void SetTitlePos(float x,float y);
	void SetHPBarPos(float x,float y);

	/* Name		��SetRoleName
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ���ý�ɫ����
	 * Param	: str ��ɫ����
	 * Return	: void
	 */
	void SetRoleName(const string& str);
	void UpdateRoleNameCampColor();

	/* Name		��SetHPBar
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ����Ѫ���ٷֱ�
	 * Param	: none
	 * Return	: void
	 */
	void SetHPBar();

	/* Name		��SetHPPercent
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ����Ѫ���ٷֱ�
	 * Param	: nPercent Ѫ���ٷֱ�
	 * Return	: void
	 */
	void SetHPPercent(int nPercent);

	/* Name		��SetRoleTitle
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ���ý�ɫ��ν
	 * Param	: str ��ɫ��ν
	 * Return	: void
	 */
	void SetRoleTitle(const string& str);

	/* Name		��SetNPCTaskState
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: �ı�����״̬ ֻ����ҲŻ��õ�
	 * Param	: state ����״̬
	 * Return	: void
	 */
	void SetNPCTaskState(NPCTaskState state);

	/* Name		��SetVip
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ����VIP�ȼ���ʾ ֻ����ҲŻ��õ�
	 * Param	: none
	 * Return	: void
	 */
	void SetVip(bool vip);

	/* Name		��SetTeamLeader
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ���öӳ���Ч
	 * Param	: leader true �ӳ���false ���Ƕӳ�
	 * Return	: void
	 */
	void SetTeamLeader(bool leader = true);

	
	/* Name		��GetRole
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ��ȡ��ɫ����ָ��
	 * Param	: none
	 * Return	: RoleFighter* ��ɫ����ָ��
	 */
	void SetShowHPBar(bool bShow);

	/* Name		��GetRole
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ��ȡ��ɫ����ָ��
	 * Param	: none
	 * Return	: RoleFighter* ��ɫ����ָ��
	 */

	//���ñ�������ŵ���
	void SetLock();

	inline RoleFighter* GetRole(){ return m_pRole; }

	inline Text* GetName(){ return m_pName; }
	inline Text* GetTitle(){ return m_pTitle; }
	inline LoadingBar* GetHPBar(){ return m_pHPBar; }
	inline Text* GetGuildName(){ return m_pGuildName; }
	inline ImageView* GetTeamLeader(){ return m_pTeamLeader; }
	inline ImageView* GetVip(){ return m_pVip; }
	inline Widget*	GetLock() { return m_pLock; }

	void			updateTimer();								//  ����ʱ���º���
	void			updateProgress();							//  ���������º���

	//������,����
	void clickLock(Ref* pSender,TouchEventType type);

private:
	RoleFighter*	m_pRole;				// ��ɫ����ָ��
	Text*			m_pName;				// ��ɫ���ƣ����н�ɫ���еģ�һ��ʼ�ͱ�����
	LoadingBar*		m_pHPBar;				// Ѫ�������н�ɫ���еģ�һ��ʼ�ͱ�����
	Text*			m_pTitle;				// ��ɫ��ν�����ֽ�ɫ����
	Text*			m_pGuildName;			// �������ƣ����ֽ�ɫ����
	ImageView*		m_pTeamLeader;			// ��Ӷӳ���Ч�����ֽ�ɫ����
	ImageView*		m_pVip;					// VIP��ν�����ֽ�ɫ����
	ImageView*		m_pTaskFlag;			// ����ͷ���ϵ���Ч�����ֽ�ɫ����
	ImageView*		m_pAutoFight;			// �Զ��һ�ͷ���ϵ���Ч�����ֽ�ɫ����
	ImageView*		m_pAutoMove;			// �Զ�Ѱ·ͷ���ϵ���Ч�����ֽ�ɫ����
	Widget*			m_revivePanel;			// ������Ѱ�ť���
	ProgressTimer*	m_progressBar;			// ���������
	ImageView*		m_reviveTip;			// ������ʾͼƬ
	Text*			m_timer_text;			// ����ʱ�ı�
	Button*			m_progress_btn;			
	int m_deadRestTime;			//	����ʱ���� ��λ����
	int	m_restPoint;			//	���ν�����ʣ��ĵ��� ��ֵΪ10000

	Button*			m_pLock;					// �Ż��߱������͵Ĺֲ���
};

#endif	// __RoleTile_h_