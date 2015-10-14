/***
 * ģ�飺GodDeviceManager
 * ���ߣ�����
 * ʱ�䣺2015-09-01
 * ˵�������������ݺ͹���
 */

#ifndef __GodDeviceManager_h_
#define __GodDeviceManager_h_

#include "GameDef.h"
#include "Net/pk_item.h"
#include "db.h"

enum GodDeviceType
{
	GodDeviceTypee_None,
};

class GodDevice
{
public:
	GodDevice(int godCfgID,int isDress,int refineLevel,int enhanceLevel,int equipId,vector<pk::EquipTianshu> tianShuList,int content_lv,vector<pk::TianshuSoltStreng> soltStrengList,int tian_shu_use_index);
	~GodDevice();
	static const int GOD_MAX_LEVEL = 5;
	static int getArtId(int dataid,int level);
	/* Name		��GetEquipBaseData
	 * Author	��Liyang
	 * Date		: 2015-09-10
	 * Desc		: ��ȡ������������
	 * Param	: none
	 * Return	: EquipBaseCfg* ��������
	 */
	inline EquipBaseCfg* GetEquipBaseData(){ return m_pEquipData;}
	inline ItemCfg* GetItemData(){ return m_pItemData;}

	inline int GetGodIsDress(){ return m_isDress; }
	inline int GetGodRefineLevel(){ return m_refineLevel; }
	inline int GetGodEnhanceLevel(){ return m_enhanceLevel; }
	inline int GetGodEquipId(){ return m_equipId; }
	inline int GetGodDataId(){ return m_pEquipData->id; }
	inline int GetGodArtId(){ return getArtId(GetGodDataId(),GetGodEnhanceLevel()); }
	inline string GetGodDes(){ return m_pEquipData->descripe; }
	inline string GetGodName(){ return m_pEquipData->name; }
	inline vector<int> GetGodSkillIdVec(){ return m_skillId_vec; }

	void SetIsDress(int isDress);

	inline void SetRefineLevel(int refineLevel){m_refineLevel = refineLevel;}
	inline void SetEnhanceLevel(int enhanceLevel){m_enhanceLevel = enhanceLevel;}

	/* Name		��Reload
	 * Author	��Liyang
	 * Date		: 2015-09-01
	 * Desc		: ���������������
	 * Param	: godid GodDevice ID
	 * Return	: void
	 */
	void Reload(int godid);

public:
	int m_isDress;						// 1:��ǰ����������,0����
	int m_refineLevel;					// �����ȼ�
	int m_enhanceLevel;					// ���׵ȼ�
	int m_equipId;						// �����󶨵�װ��id
	vector<int>			m_skillId_vec;	// ������Ӧ����ID vector

	vector<pk::EquipTianshu> m_tianShuList;			// ����
	int8 m_content_lv;								// �����ȼ�
	vector<pk::TianshuSoltStreng> m_soltStrengList;	// ����λ��ǿ����Ϣ
	int8 m_tian_shu_use_index;						// ����ʹ��������

	vector<vector<int>>			m_all_attr_vec[6];  // 6�ײ�ͬ������

	EquipBaseCfg*		m_pEquipData;		// ��Ʒ��������
	ItemCfg*			m_pItemData;		// ��Ʒ��������
};

typedef vector<GodDevice*> GodDeviceList;

class GodDeviceManager
{
public:
	GodDeviceManager();
	~GodDeviceManager();

	/* Name		��Insert
	 * Author	��Liyang
	 * Date		: 2015-09-01
	 * Desc		: ���һ������
	 * Param	: godCfgID ��������ID
	 * Return	: GodDevice* �¼ӵ�BUFFָ��
	 */
	GodDevice*	Insert(int godCfgID,int isDress,int refineLevel,int enhanceLevel,int equipId,vector<pk::EquipTianshu> tianShuList,int content_lv,vector<pk::TianshuSoltStreng> soltStrengList,int tian_shu_use_index);

	/* Name		��Insert
	 * Author	��Liyang
	 * Date		: 2015-09-01
	 * Desc		: ���һ������
	 * Param	: GodDevice* �¼ӵ�����ָ��
	 * Return	: void
	 */
	void		Insert(GodDevice* pGod);

	/* Name		��Get
	 * Author	��Liyang
	 * Date		: 2015-09-01
	 * Desc		: ��ȡһ������
	 * Param	: godCfgID ��������ID
	 * Return	: GodDevice* ����
	 */
	GodDevice*	Get(int godCfgID);

	/* Name		��GetIsDressGod
	 * Author	��Liyang
	 * Date		: 2015-09-01
	 * Desc		: ��ȡ��ǰ����������������ID
	 * Param	: NONE
	 * Return	: ��������ID
	 */
	int	GetIsDressGod();

	/* Name		��GetIsDressGod
	 * Author	��Liyang
	 * Date		: 2015-09-08
	 * Desc		: ��ȡ��ǰ����������
	 * Param	: NONE
	 * Return	: ��ǰ����������
	 */
	GodDevice*	GetIsDressGodPtr();

	/* Name		��GetIsDressGodIndex
	 * Author	��Liyang
	 * Date		: 2015-09-08
	 * Desc		: ��ȡ��ǰ������������index
	 * Param	: NONE
	 * Return	: ��ǰ������������index
	 */
	int	GetIsDressGodIndex();

	/* Name		��Clear
	 * Author	��Liyang
	 * Date		: 2015-09-01
	 * Desc		: ������������
	 * Param	: none
	 * Return	: void
	 */
	void		Clear();

	/* Name		��Count
	 * Author	��Liyang
	 * Date		: 2015-09-01
	 * Desc		: ͳ����������
	 * Param	: none
	 * Return	: int ��������
	 */
	inline int Count(){ return (int)m_GodDevices.size(); }

	/* Name		��GetBuffList
	 * Author	��Liyang
	 * Date		: 2015-08-21
	 * Desc		: ��ȡbuff�б�
	 * Param	: none
	 * Return	: RoleBuffList BUFF�б�
	 */
	inline GodDeviceList GetDeviceList(){return m_GodDevices;}

private:
	GodDeviceList m_GodDevices;
};

#endif //__RoleBuff_h_