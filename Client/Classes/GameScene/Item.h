#ifndef __Item_h_
#define __Item_h_

#include "Net/pk_item.h"
#include "GameDef.h"
#include "db.h"
#include "ItemType.h"
#include "UI/GameUIDef.h"

struct ItemInfo
{
	ItemInfo(){
		id = 0;
		index = 0;
		dataId = 0;
		count = 0;
		isBind = false;
		refineLevel = 0;
		enhanceLevel = 0;
		strengthenLevel = 0;
		cd=0;
		newAdd=false;
		dataEx = NULL;
		dataEx64 = 0;
		score = 0;
		tian_shu_exp = 0;
		tian_shu_use_index = 0;
		tian_shu_set_list.clear();
		soltStrengList.clear();
		tianShuList.clear();
		curInlay = false;
		otherInlay = false;
		gridUsed   = false;
		selectCount = 0;
	}

	//����
	ObjectID	id;					//��Ʒ������id
	int			dataId;				//��Ʒ����id
	int			index;				//��Ʒ�ڱ����еĸ���λ�ã���0��ʼ ���� װ�����еĲ�λ ��Ʒ��װ������Ч
	int			count;				//��������
	bool		isBind;				//�Ƿ��
	int8        refineLevel;	    //�����ȼ�    
	int8        enhanceLevel;       //���׵ȼ�
	//װ��
	int8        tian_shu_use_index; //��ǰʹ�õ���һ����Ƕ����id װ����Ч
	int16       tian_shu_exp;       //��ǰ�Ľ���ֵ ������Ч
	int8        strengthenLevel;	//ǿ���ȼ�     ������Ч
	vector<pk::EquipTianshu> tianShuList;	// װ��������Ƕ�������б� װ����Ч
	vector<pk::TianshuSoltStreng> soltStrengList;	// �����λǿ����Ϣ ������Ч
	vector<pk::TianShuSet> tian_shu_set_list;    // ����������Ƕ��װ����Ϣ�б� ������Ч

	//����
	bool        curInlay;           //��ǰ�Ƿ���Ƕ               ����
	bool        otherInlay;         //�����ط���Ƕ               ����
	bool        gridUsed;           //��ǰ���������Ƿ�����       ����
	int         selectCount;        //��ǰѡ��                   ����

	int32       score;              //Ʒ��
	int8        content_lv;         //�����ȼ�

	float		cd;					//��Ʒʹ��CD
	bool		newAdd;				//������ʶ
	void*		dataEx;				//�����ⲿ���Ӹ�������
	int64		dataEx64;		
};

class CItem : public Ref
{
public:
	CItem();
	CItem(ItemInfo& info);
	~CItem();

	static CItem* Create(ItemInfo& info);
	static CItem* Create(pk::BagItem* pBagItem);
	static CItem* Create(pk::EquipItem* pEquipItem);
	static CItem* Create(pk::GS2C_SignalItemInfo* pMailItem);

	bool InitWithItemInfo(ItemInfo& info);

	bool InitBagItem(pk::BagItem* pBagItem);

	bool InitEquipItem(pk::EquipItem* pEquipItem);

	inline ItemInfo& getItemInfo() { return m_Info; }

	//��Ʒ������id
	inline ObjectID	getId(){ return m_Info.id; }
	//��Ʒλ��
	inline void		setIndex(int nIndex) {m_Info.index=nIndex;}
	inline int		getIndex() { return m_Info.index; }
	//��Ʒ����id
	inline int		getDataID(){ return m_Info.dataId; }

	inline ItemCfg*	getItemData(){ return m_pItemData; }
	inline EquipBaseCfg* getEquipBaseData(){ return m_pEquipData; }
	inline int		getArtID(){ return getItemData()->artid; }
	inline int		getType(){ return getItemData()->type; }
	inline int		getSubType(){ return getItemData()->subtype;}
	//����ȼ�  add Tangbo
	inline int      getUseLevel(){ return getItemData()->uselevel; }
	//����ְҵ  add Tangbo
	inline int		getUseCareer(){ return getItemData()->career; }
	//�۶�    add Tangbo
	inline int		getItemPrice(){ return getItemData()->pricesell; }
	//��ȡ��ǰ��װ���ȼ����� add Tangbo
	inline int      getScore(){return m_Info.score;}
	//��ȡ��ǰ����ֵ  add Tangbo
	inline int      getBookPercent(){return m_Info.tian_shu_exp;}

	//��ȡ��ǰʹ��װ���Ƿ���Ƕ add Tangbo
	inline bool     getCurInlay(){return m_Info.curInlay;}
	inline void     setCurInlay(bool val){m_Info.curInlay = val;}

	//��ȡ��ǰδʹ��װ���Ƿ���Ƕ add Tangbo
	inline bool     getOtherInlay(){return m_Info.otherInlay;}
	inline void     setOtherInlay(bool val){m_Info.otherInlay = val;}

	//��ǰ���������Ƿ�����       ����
	inline void     setGridUsed(bool val){m_Info.gridUsed = val;};
	
	//��ǰѡ��                   ����
	inline void     setSelectCount(int val){m_Info.selectCount = val;}

	//��ȡ��ǰ����
	inline const ItemInfo& getCurItemInfo(){return m_Info;}   

	//ˢ����Ƕ״̬
	void            refreshInlayStatus();

	//��������
	inline void		setCount(int newCount){m_Info.count=newCount;}
	inline int		getCount(){ return m_Info.count;};
	//�Ƿ��
	inline bool		isBind() {return m_Info.isBind;}
	//�����ȼ�
	inline int		getRefinedLv(){return m_Info.refineLevel;}
	inline void		setRefinedLv(int nNewLv) { m_Info.refineLevel = nNewLv;}

	//���׵ȼ�
	inline int		getEnhanceLv(){return m_Info.enhanceLevel;}
	inline void		setEnhanceLv(int nNewLv) { m_Info.enhanceLevel = nNewLv;}


	//cd
	inline void		SetCdTime(float cd) { m_Info.cd=cd; }
	inline float	GetCdTime() { return m_Info.cd; }
	inline float	GetCdTimeTotal(){ return getItemData()->cdtime; }
	inline bool		IsCding() {return m_Info.cd>0;};
	inline void		updateCd(float dt) { if(m_Info.cd>0) m_Info.cd-=dt;}
	//������ʶ
	inline void		setNewAdd(bool bNewAdd) {m_Info.newAdd=bNewAdd;}
	inline bool		IsNewAdd() {return m_Info.newAdd;}
	//�����ⲿ���Ӹ�������
	inline void		setDataEx(void* pData) { m_Info.dataEx=pData; }
	inline void*	getDataEx() { return m_Info.dataEx; }
	inline void		setDataEx64(int64 pData) { m_Info.dataEx64=pData; }
	inline int64	getDataEx64() { return m_Info.dataEx64; }

	
	EquipColumnType getEquipColumnType();

	inline bool		isEquip(){ return getType() == ItemType_Equip; }
	inline bool		isGodDevice(){ return getType() == ItemType_GodDevice; }
	inline bool		isSkyBook(){ return getType() == ItemType_SkyBook; }
	inline bool		isDrawingSheet(){ return getType() == ItemType_DrawingSheet; }
	inline bool		isMaterial(){ return getType() == ItemType_Material; }
	//�Ƿ���� add Tangbo
	inline bool		isDoSell(){ return getItemPrice() > -1; }

	vector<int>		m_skillId_vec;					// ������Ӧ����ID vector
	vector<vector<int>>			m_all_attr_vec[6];  // 6�ײ�ͬ������

protected:
	ItemInfo		m_Info;
	ItemCfg*		m_pItemData;
	EquipBaseCfg*	m_pEquipData;
};

#endif //__Item_h_