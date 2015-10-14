/***
 * ģ�飺PetItemManager
 * ���ߣ�����
 * ʱ�䣺2015-09-28
 * ˵�����������ݹ���
 */

#ifndef __PetItemManager_h_
#define __PetItemManager_h_

#include "GameDef.h"
#include "db.h"
#include "Net/pk_item.h"

class CPetItem
{
public:
	CPetItem(int id,int dataId,int level,int exp,int strengLv,int isActive,
		pk::FightProperty prop,vector<pk::EquipTianshu> tianShuLis,int content_lv,vector<pk::TianshuSoltStreng> soltStrengList,int tian_shu_use_index);
	~CPetItem();

	/* Name		��GetPetBaseData
	 * Author	��Liyang
	 * Date		: 2015-09-28
	 * Desc		: ��ȡ������������
	 * Param	: none
	 * Return	: PetBaseCfg* ��������
	 */
	inline PetBaseCfg* GetPetBaseData(){ return m_pPetBaseData;}


	inline void updateProperty(int id,int dataId,int level,int exp,int strengLv,int isActive,
		pk::FightProperty prop,vector<pk::EquipTianshu> tianShuLis,int content_lv,vector<pk::TianshuSoltStreng> soltStrengList,int tian_shu_use_index){
			m_id = id;
			m_dataId = dataId;
			m_level = level;
			m_exp = exp;
			m_strengLv = strengLv;
			m_isActive = isActive;									
			m_prop = prop;
			m_tianShuList = tianShuLis;			
			m_content_lv = content_lv;								
			m_soltStrengList = soltStrengList;	
			m_tian_shu_use_index = tian_shu_use_index;						

			Reload(m_dataId);
	}
	inline int GetPetID(){ return m_id; }
	inline int GetPetDataID(){ return m_dataId; }
	inline int GetPetLevel(){ return m_level; }
	inline int GetPetExp(){ return m_exp; }
	inline int GetPetStrengLv(){ return m_strengLv; }
	inline int GetPetActive(){ return m_isActive; }
	inline pk::FightProperty GetPetProperty(){return m_prop;}
	inline vector<pk::EquipTianshu> GetTianShuList(){return m_tianShuList;}
	inline int GetPetContentLv(){return m_content_lv;}
	inline vector<pk::TianshuSoltStreng> GetTianshuSoltStreng(){return m_soltStrengList;}
	inline int GetPetTianShuUseIndex(){return m_tian_shu_use_index;}

	inline void SetLevel(int level){m_level = level;}
	inline void SetExp(int exp){m_exp = exp;}
	inline void SetStrengLv(int strengLv){m_strengLv = strengLv;}
	inline void SetIsActive(int isActive){m_isActive = isActive;}
	inline void SetProp(pk::FightProperty prop){m_prop = prop;}
	inline void SetContentLv(int content_lv){m_content_lv = content_lv;}
	inline void SetTianShuUseIndex(int tian_shu_use_index){m_tian_shu_use_index = tian_shu_use_index;}

	/* Name		��Reload
	 * Author	��Liyang
	 * Date		: 2015-09-28
	 * Desc		: ���ó����������
	 * Param	: dataId
	 * Return	: void
	 */
	void Reload(int dataId);

public:
	int m_id;
	int m_dataId;
	int m_level;
	int m_exp;
	int m_strengLv;
	int m_isActive;									//1��ս��0ι��ս
	pk::FightProperty m_prop;
	vector<pk::EquipTianshu> m_tianShuList;			// ����
	int m_content_lv;								// �����ȼ�
	vector<pk::TianshuSoltStreng> m_soltStrengList;	// ����λ��ǿ����Ϣ
	int m_tian_shu_use_index;						// ����ʹ��������

	PetBaseCfg* m_pPetBaseData;						// ������������
};

typedef vector<CPetItem*> PetItemList;

class PetItemManager
{
public:
	PetItemManager();
	~PetItemManager();

	/* Name		��Insert
	 * Author	��Liyang
	 * Date		: 2015-09-28
	 * Desc		: ���һ������
	 * Param	:
	 * Return	: CPetItem* �¼ӵĳ�������ָ��
	 */
	CPetItem*	Insert(int id,int dataId,int level,int exp,int strengLv,int isActive,
		pk::FightProperty prop,vector<pk::EquipTianshu> tianShuLis,int content_lv,vector<pk::TianshuSoltStreng> soltStrengList,int tian_shu_use_index);

	/* Name		��Insert
	 * Author	��Liyang
	 * Date		: 2015-09-28
	 * Desc		: ���һ������
	 * Param	: CPetItem* ��������ָ��
	 * Return	: void
	 */
	void		Insert(CPetItem* pPetData);

	/* Name		��GetByID
	 * Author	��Liyang
	 * Date		: 2015-09-28
	 * Desc		: ��ȡһ������
	 * Param	: id ����ID
	 * Return	: CPetItem* ��������ָ��
	 */
	CPetItem*	GetByID(int id);

	/* Name		��GetByDataID
	 * Author	��Liyang
	 * Date		: 2015-09-28
	 * Desc		: ��ȡһ������
	 * Param	: id ��������ID
	 * Return	: CPetItem* ��������ָ��
	 */
	CPetItem*	GetByDataID(int dataid);

	
	/* Name		��GetPetDataList
	 * Author	��Liyang
	 * Date		: 2015-09-24
	 * Desc		: ��ȡ���������б�
	 * Param	: none
	 * Return	: PetItemList ���������б�
	 */
	inline PetItemList GetPetDataList(){return m_PetItems;}

	/* Name		��Clear
	 * Author	��Liyang
	 * Date		: 2015-09-28
	 * Desc		: �����������
	 * Param	: none
	 * Return	: void
	 */
	void		Clear();
private:
	PetItemList m_PetItems;
};

#endif //__RoleBuff_h_