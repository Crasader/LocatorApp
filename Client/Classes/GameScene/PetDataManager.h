/***
 * ģ�飺PetDataManager
 * ���ߣ�����
 * ʱ�䣺2015-09-28
 * ˵�����������ݹ���
 */

#ifndef __PetDataManager_h_
#define __PetDataManager_h_

#include "GameDef.h"
#include "db.h"
#include "Net/pk_item.h"

class PetData
{
public:
	PetData(int id,int dataId,int level,int exp,int strengLv,int isActive,
		pk::FightProperty prop,vector<pk::EquipTianshu> tianShuLis,int content_lv,vector<pk::TianshuSoltStreng> soltStrengList,int tian_shu_use_index);
	~PetData();

	/* Name		��GetPetBaseData
	 * Author	��Liyang
	 * Date		: 2015-09-28
	 * Desc		: ��ȡ������������
	 * Param	: none
	 * Return	: PetBaseCfg* ��������
	 */
	inline PetBaseCfg* GetPetBaseData(){ return m_pPetBaseData;}

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

typedef vector<PetData*> PetDataList;

class PetDataManager
{
public:
	PetDataManager();
	~PetDataManager();

	/* Name		��Insert
	 * Author	��Liyang
	 * Date		: 2015-09-28
	 * Desc		: ���һ������
	 * Param	:
	 * Return	: PetData* �¼ӵĳ�������ָ��
	 */
	PetData*	Insert(int id,int dataId,int level,int exp,int strengLv,int isActive,
		pk::FightProperty prop,vector<pk::EquipTianshu> tianShuLis,int content_lv,vector<pk::TianshuSoltStreng> soltStrengList,int tian_shu_use_index);

	/* Name		��Insert
	 * Author	��Liyang
	 * Date		: 2015-09-28
	 * Desc		: ���һ������
	 * Param	: PetData* ��������ָ��
	 * Return	: void
	 */
	void		Insert(PetData* pPetData);

	/* Name		��GetByID
	 * Author	��Liyang
	 * Date		: 2015-09-28
	 * Desc		: ��ȡһ������
	 * Param	: id ����ID
	 * Return	: PetData* ��������ָ��
	 */
	PetData*	GetByID(int id);

	/* Name		��GetByDataID
	 * Author	��Liyang
	 * Date		: 2015-09-28
	 * Desc		: ��ȡһ������
	 * Param	: id ��������ID
	 * Return	: PetData* ��������ָ��
	 */
	PetData*	GetByDataID(int dataid);

	
	/* Name		��GetPetDataList
	 * Author	��Liyang
	 * Date		: 2015-09-24
	 * Desc		: ��ȡ���������б�
	 * Param	: none
	 * Return	: PetDataList ���������б�
	 */
	inline PetDataList GetPetDataList(){return m_PetDatas;}

	/* Name		��Clear
	 * Author	��Liyang
	 * Date		: 2015-09-28
	 * Desc		: �����������
	 * Param	: none
	 * Return	: void
	 */
	void		Clear();
private:
	PetDataList m_PetDatas;
};

#endif //__RoleBuff_h_