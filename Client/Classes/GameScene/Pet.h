#ifndef __Pet_h_
#define __Pet_h_

#include "RoleFighter.h"
#include "ui/UIText.h"

class CPet : public RoleFighter
{
public:
	CPet();
	~CPet();

	CREATE_FUNC(CPet);
	//new
	virtual bool init();
	virtual bool initRole();

	virtual void SetProperty(RoleProperty idx,int val);
	virtual void SetProperty(RoleProperty idx,__int64 val);
	virtual void SetProperty(RoleProperty idx,const string& val);

	virtual void update(float delta);
	virtual void onSelect(bool param);

	void ShowPetChat(int strId,int displayMs);
	void removePetChat();

	virtual void RefreshEquip();

	/* Name		��Dead
	 * Author	��Liyang
	 * Date		: 2015-09-28
	 * Desc		: ������������
	 * Param	: pKiller ɱ�˷�
	 * Return	: void
	 */
	virtual void Dead(RoleFighter* pKiller);

	/* Name		��DeadVirtual
	 * Author	��YueLiangYou
	 * Date		: 2015-09-28
	 * Desc		: �����������
	 * Param	: pKiller ɱ�˷�
	 * Return	: void
	 */
	virtual void DeadVirtual(RoleFighter* pKiller);

	virtual void Disappear();
	virtual void SetDataID(int dataid);

	int GetDataID(){ return m_pCfgData?m_pCfgData->id:0; }
	inline PetBaseCfg* GetMonsterData(){ return m_pCfgData; }

protected:
	PetBaseCfg* m_pCfgData;

	ui::Text *m_pChatText;
};

#endif

