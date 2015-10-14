/***
 * ���ߣ�������
 * ʱ�䣺2015-06-19
 * ˵������ͼ�е����������
 */

#ifndef __RegionManager_h_
#define __RegionManager_h_

#include "GameDef.h"
#include "Region.h"

typedef vector<CRegion*> RegionList;

class CRegionManager : public Ref
{
public:
	CRegionManager();
	~CRegionManager();

public:
	void		addRegion(CRegion* pRegion);
	CRegion*	addRegion(int cx,int cy,int sx,int sy);

	void		addNpcRegion(CRegion* pRegion);
	CRegion*	addNpcRegion(int cx,int cy,int sx,int sy);

	void		addMonsterRegion(CRegion* pRegion);
	CRegion*	addMonsterRegion(int cx,int cy,int sx,int sy);

	void		addDoorRegion(CRegion* pRegion);
	CRegion*	addDoorRegion(int cx,int cy,int sx,int sy);

	bool		addDynamicTransferDoorIfNotExist(int64 id,int16 x,int16 y,int8 cx,int8 cy);

	CRegion*	getRegion(int cx,int cy);
	int			getRegionList(int cx,int cy,RegionList& list);
	CRegion*	getRegionFlag(int cx,int cy,int flag);
	CRegion*	getRegionNpc(int cx,int cy);
	CRegion*	getRegionMonster(int cx,int cy);
	CRegion*	getRegionDoor(int cx,int cy);

	void		removeRegion(CRegion* pRegion);

	bool		isRegionFlag(int cx,int cy,int flag);
	bool		isRegionDoor(int cx,int cy);

	inline RegionList*	getRegionList()	{ return &m_Regions; }
	inline RegionList*	getNpcList()	{ return &m_Npcs; }
	inline RegionList*	getMonsterList(){ return &m_Monsters; }
	inline RegionList*	getDoorList()	{ return &m_Doors; }

protected:
	RegionList				m_Regions;		// ������Ϣ
	RegionList				m_Npcs;			// NPC�ֲ���Ϣ
 	RegionList				m_Monsters;		// ��������
 	RegionList				m_Doors;		// ������
};

#endif