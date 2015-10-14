#ifndef __Monster_h_
#define __Monster_h_

#include "RoleFighter.h"
#include "Net/pk_move.h"
#include "RoleModel.h"
#include "ui/UIText.h"
//class ui::Text;

class CMonster : public RoleFighter
{
public:
	enum _monsterType
	{
		MonsterType_Normal,//��ͨ����
		MonsterType_Boss,//boss
		MonsterType_DestroyDoor,//���Դ��Ƶ���
		MonsterType_Collect,//���Ʋɼ����򿪵���
		MonsterType_Build,//������
	}MonsterType;
public:
	CMonster();
	~CMonster();

	CREATE_FUNC(CMonster);
	//new
	virtual bool init();
	virtual bool initRole();

	virtual void SetProperty(RoleProperty idx,int val);
	virtual void SetProperty(RoleProperty idx,__int64 val);
	virtual void SetProperty(RoleProperty idx,const string& val);
	/*
	bool initWithRoleData( RoleData* data );
	virtual void GetHeadNameInfo(HeadNameInfo*);
	*/
	virtual void update(float delta);
	
	virtual void onSelect(bool param);

	void ShowMonsterChat(int strId,int displayMs);
	void removeMonsterChat();

	virtual void RefreshEquip();

	/* Name		��Dead
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ��ɫ��������
	 * Param	: pKiller ɱ�˷�
	 * Return	: void
	 */
	virtual void Dead(RoleFighter* pKiller);

	/* Name		��DeadVirtual
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ��ɫ��������
	 * Param	: pKiller ɱ�˷�
	 * Return	: void
	 */
	virtual void DeadVirtual(RoleFighter* pKiller);

	virtual void Disappear();
	virtual void SetDataID(int dataid);

	int GetDataID(){ return m_pCfgData?m_pCfgData->id:0; }
	inline MonsterBaseCfg* GetMonsterData(){ return m_pCfgData; }

	//�ɼ�����
	void CollectStart();
	void CollectTimeOut(float fNoUse);

protected:
	MonsterBaseCfg* m_pCfgData;

	ui::Text *m_pChatText;
	class TimerProgressBar*	m_pCollectionProgressBar;
};

#endif

