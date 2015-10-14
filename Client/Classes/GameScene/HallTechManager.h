/***
 * ģ�飺HallTechManager
 * ���ߣ�����
 * ʱ�䣺2015-09-24
 * ˵����ս�����ݹ���
 */

#ifndef __HallTechManager_h_
#define __HallTechManager_h_

#include "GameDef.h"
#include "db.h"

class HallTech
{
public:
	HallTech(int id,int lv,double nextLvTime);
	~HallTech();

	void onTimer(float dt);

	/* Name		��GetHallTechData
	 * Author	��Liyang
	 * Date		: 2015-09-24
	 * Desc		: ��ȡս����������
	 * Param	: none
	 * Return	: HallTechCfg* ��������
	 */
	inline HallTechCfg* GetHallTechData(){ return m_pHallTechData;}

	inline double GetHallTechUpgradeTime(){ return m_nextLvTime; }
	inline int GetHallTechID(){ return m_id; }
	inline int GetHallLevel(){ return m_lv; }
	inline int GetHallMaxLevel(){ return m_pHallTechData->max_lv; }
	//inline string GetHallName(){ return m_pHallTechData->name; }
	inline int GetUpgradeItemID(){return m_pHallTechData->item;}
	
	/* Name		��GetHallDesByLevel
	 * Author	��Liyang
	 * Date		: 2015-09-24
	 * Desc		: ��ȡս������
	 * Param	: none
	 * Return	: string ս������
	 */
	string GetHallDes();

	/* Name		��GetUpgradeGoldByLevel
	 * Author	��Liyang
	 * Date		: 2015-09-24
	 * Desc		: ��ȡս��������������Ľ��
	 * Param	: none
	 * Return	: int �������
	 */
	int GetUpgradeGold();
	
	/* Name		��GetUpgradeItemCountByLevel
	 * Author	��Liyang
	 * Date		: 2015-09-24
	 * Desc		: ��ȡս���������������������
	 * Param	: ս�����ܵĵȼ�
	 * Return	: int ��������
	 */
	int GetUpgradeItemCountByLevel(int level);

	/* Name		��GetUpgradeNeedTimeByLevel
	 * Author	��Liyang
	 * Date		: 2015-09-24
	 * Desc		: ��ȡս���������������ʱ�� ����
	 * Param	: ս�����ܵĵȼ�
	 * Return	: int ��������
	 */
	int GetUpgradeNeedTimeByLevel(int level);

	inline void SetLevel(int level){m_lv = level;}
	inline void SetNextLvTime(double nextTime){m_nextLvTime = nextTime;}

	/* Name		��Reload
	 * Author	��Liyang
	 * Date		: 2015-09-24
	 * Desc		: ����ս���������
	 * Param	: hallTechId
	 * Return	: void
	 */
	void Reload(int hallTechId);

public:
	int m_id;
	int m_lv;
	double m_nextLvTime;							// �����¼���ʱ�䣬0��ʾ��������״̬
	HallTechCfg*		m_pHallTechData;		// ս����������
};

typedef vector<HallTech*> HallTechList;

class HallTechManager
{
public:
	HallTechManager();
	~HallTechManager();

	/* Name		��Insert
	 * Author	��Liyang
	 * Date		: 2015-09-24
	 * Desc		: ���һ��ս��������Ϣ
	 * Param	: nextLvTime �����¼���ʱ�����0��ʾ��������״̬
	 * Return	: HallTech* �¼ӵ�ս��������Ϣָ��
	 */
	 HallTech*	Insert(int id,int lv,double nextLvTime);

	/* Name		��Insert
	 * Author	��Liyang
	 * Date		: 2015-09-24
	 * Desc		: ���һ��ս��������Ϣ
	 * Param	: HallTech* �¼ӵ�ս��������Ϣָ��
	 * Return	: void
	 */
	void		Insert(HallTech* pHallTech);

	/* Name		��Get
	 * Author	��Liyang
	 * Date		: 2015-09-24
	 * Desc		: ��ȡһ��ս��������Ϣ
	 * Param	: id ս��������Ϣ��ID
	 * Return	: HallTech* ս��������Ϣ
	 */
	HallTech*	Get(int id);


	/* Name		��GetByCfgID
	 * Author	��Liyang
	 * Date		: 2015-10-08
	 * Desc		: ��ȡһ��ս��������Ϣ
	 * Param	: cfgid ս��������Ϣ������ID
	 * Return	: HallTech* ս��������Ϣ
	 */
	HallTech*	GetByCfgID(int cfg_id);

	/* Name		��GetIsUpgrade
	 * Author	��Liyang
	 * Date		: 2015-09-24
	 * Desc		: ��ȡս�������Ƿ�������״̬
	 * Param	: id ս��������ϢID
	 * Return	: bool �Ƿ�������״̬
	 */
	bool	GetIsUpgrade(int id);

	/* Name		��GetUpgradeTime
	 * Author	��Liyang
	 * Date		: 2015-09-24
	 * Desc		: ��ȡս������������ɵ�ʱ��
	 * Param	: id ս��������ϢID
	 * Return	: float ������ɵ�ʱ��
	 */
	float	GetUpgradeTime(int id);

	/* Name		��GetUpgradeTimePercent
	 * Author	��Liyang
	 * Date		: 2015-10-09
	 * Desc		: ��ȡս������������ɵ�ʱ��ٷֱ�
	 * Param	: id ս��������ϢID
	 * Return	: float ������ɵ�ʱ��ٷֱ�
	 */
	float	GetUpgradeTimePercent(int id);

	/* Name		��GetLevelByID
	 * Author	��Liyang
	 * Date		: 2015-09-24
	 * Desc		: ��ȡս�����ܵȼ�
	 * Param	: id ս��������ϢID
	 * Return	: int ս�����ܵȼ�
	 */
	int	GetLevelByID(int id);

	/* Name		��GetLevelByCfgID
	 * Author	��Liyang
	 * Date		: 2015-10-08
	 * Desc		: ��ȡս�����ܵȼ�
	 * Param	: cfg_id ս��������Ϣ����ID
	 * Return	: int ս�����ܵȼ�
	 */
	int	GetLevelByCfgID(int cfg_id);

	/* Name		��GetHallTechList
	 * Author	��Liyang
	 * Date		: 2015-09-24
	 * Desc		: ��ȡս��������Ϣ�б�
	 * Param	: none
	 * Return	: HallTechList ս��������Ϣ�б�
	 */
	inline HallTechList GetHallTechList(){return m_HallTechs;}

	/* Name		��Clear
	 * Author	��Liyang
	 * Date		: 2015-09-24
	 * Desc		: ����ս����������
	 * Param	: none
	 * Return	: void
	 */
	void		Clear();

	void Update(float dt);
private:
	HallTechList m_HallTechs;
};

#endif //__RoleBuff_h_