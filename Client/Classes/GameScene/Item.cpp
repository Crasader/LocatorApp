#include "Item.h"
#include <math.h>
#include "GameDataManager.h"
#include "GridsManager.h"
#include "Net/NetDispatcher.h"
#include "Log.h"
#include "Common/CommonDef.h"

CItem::CItem()
{

}

CItem::CItem(ItemInfo& info)
{
	InitWithItemInfo(info);
}

CItem::~CItem()
{

}

CItem* CItem::Create(pk::BagItem* pBagItem)
{
	if ( !pBagItem )
	{
		return NULL;
	}
	ItemInfo item; 
	item.id = pBagItem->id;
	item.index = pBagItem->index;
	item.dataId = pBagItem->itemDataId;
	item.count = pBagItem->count;
	item.isBind = pBagItem->isBind !=0;
	item.enhanceLevel = pBagItem->enhanceLevel;
	item.refineLevel = pBagItem->refineLevel;
	item.content_lv = pBagItem->content_lv;
	item.score = pBagItem->score;
	item.soltStrengList = pBagItem->soltStrengList;
	item.tian_shu_exp = pBagItem->tian_shu_exp;
	item.tianShuList = pBagItem->tianShuList;
	item.tian_shu_set_list = pBagItem->tian_shu_set_list;

	return Create(item);
}

CItem* CItem::Create(pk::EquipItem* pEquipItem)
{
	if ( !pEquipItem )
	{
		return NULL; 
	}

	ItemInfo item; 
	item.id = pEquipItem->id;
	item.index = pEquipItem->part;
	item.dataId = pEquipItem->equipDataId;
	item.isBind = pEquipItem->isBind != 0;
	item.enhanceLevel = pEquipItem->enhanceLevel;
	item.refineLevel = pEquipItem->refineLevel;
	item.content_lv = pEquipItem->content_lv;
	item.score = pEquipItem->score;
	item.soltStrengList = pEquipItem->soltStrengList;
	item.tian_shu_use_index = pEquipItem->tian_shu_use_index;
	item.tianShuList = pEquipItem->tianShuList;

	return Create(item);
}

CItem* CItem::Create(pk::GS2C_SignalItemInfo* pMailItem)
{
	if ( !pMailItem )
	{
		return NULL; 
	}
	ItemInfo item; 
	item.id = pMailItem->id;
	item.dataId = pMailItem->itemDataId;
	item.count = pMailItem->count;
	item.isBind = pMailItem->isBind != 0;
	item.enhanceLevel = pMailItem->enhanceLevel;
	item.refineLevel = pMailItem->refineLevel;
	return Create(item);
}

CItem* CItem::Create(ItemInfo& info)
{
	CItem* pItem = new CItem();
	if ( pItem && pItem->InitWithItemInfo(info) )
	{
		return pItem;
	}

	CC_SAFE_DELETE(pItem);

	return NULL;
}

bool CItem::InitWithItemInfo(ItemInfo& info)
{
	m_Info.id = info.id;
	m_Info.index = info.index;
	m_Info.dataId = info.dataId;
	m_Info.count = info.count;
	m_Info.isBind = info.isBind != 0;
	m_Info.refineLevel = info.refineLevel;
	m_Info.enhanceLevel = info.enhanceLevel;
	m_Info.content_lv = info.content_lv;
	m_Info.score = info.score;
	m_Info.tian_shu_exp = info.tian_shu_exp;
	m_Info.tian_shu_use_index = info.tian_shu_use_index;

	m_Info.soltStrengList.clear();
	m_Info.tian_shu_set_list.clear();
	m_Info.tianShuList.clear();

	m_Info.soltStrengList = info.soltStrengList;
	m_Info.tian_shu_set_list = info.tian_shu_set_list;
	m_Info.tianShuList = info.tianShuList;


	refreshInlayStatus();

	m_pItemData = ItemData.get(m_Info.dataId);
	if ( !m_pItemData )
	{
		LOGE("can't find item[%d] itemdata.",m_Info.dataId);
		return false;
	}

	if ( isEquip() )
	{
		m_pEquipData = EquipBaseData.get(m_Info.dataId);
		if ( !m_pEquipData )
		{
			LOGE("can't find item[%d] itemequipdata.",m_Info.dataId);
			return false;
		}
		// ��ּ����б�
		StringSplitToInt(m_pEquipData->skillid,";",m_skillId_vec);

		// ��������б�
		vector<string> temp_str_;
		int number_ = StringSplit(m_pEquipData->attribute,";",temp_str_);

		for (size_t i = 0;i<temp_str_.size();i++)
		{
			vector<int> temp_int_vec_;
			StringSplitToInt(temp_str_[i],",",temp_int_vec_);
			m_all_attr_vec[0].push_back(temp_int_vec_);
		}

		temp_str_.clear();
		number_ = StringSplit(m_pEquipData->attribute1,";",temp_str_);
		for (size_t i = 0;i<temp_str_.size();i++)
		{
			vector<int> temp_int_vec_;
			StringSplitToInt(temp_str_[i],",",temp_int_vec_);
			m_all_attr_vec[1].push_back(temp_int_vec_);
		}

		temp_str_.clear();
		number_ = StringSplit(m_pEquipData->attribute2,";",temp_str_);
		for (size_t i = 0;i<temp_str_.size();i++)
		{
			vector<int> temp_int_vec_;
			StringSplitToInt(temp_str_[i],",",temp_int_vec_);
			m_all_attr_vec[2].push_back(temp_int_vec_);
		}

		temp_str_.clear();
		number_ = StringSplit(m_pEquipData->attribute3,";",temp_str_);
		for (size_t i = 0;i<temp_str_.size();i++)
		{
			vector<int> temp_int_vec_;
			StringSplitToInt(temp_str_[i],",",temp_int_vec_);
			m_all_attr_vec[3].push_back(temp_int_vec_);
		}

		temp_str_.clear();
		number_ = StringSplit(m_pEquipData->attribute4,";",temp_str_);
		for (size_t i = 0;i<temp_str_.size();i++)
		{
			vector<int> temp_int_vec_;
			StringSplitToInt(temp_str_[i],",",temp_int_vec_);
			m_all_attr_vec[4].push_back(temp_int_vec_);
		}

		temp_str_.clear();
		number_ = StringSplit(m_pEquipData->attribute5,";",temp_str_);
		for (size_t i = 0;i<temp_str_.size();i++)
		{
			vector<int> temp_int_vec_;
			StringSplitToInt(temp_str_[i],",",temp_int_vec_);
			m_all_attr_vec[5].push_back(temp_int_vec_);
		}
	}

	return true;
}

bool CItem::InitBagItem(pk::BagItem* pBagItem)
{
	if(!pBagItem) return false;
	ItemInfo info;
	info.id = pBagItem->id;
	info.index = pBagItem->index;
	info.dataId = pBagItem->itemDataId;
	info.count = pBagItem->count;
	info.isBind = pBagItem->isBind != 0;
	info.enhanceLevel = pBagItem->enhanceLevel;
	info.refineLevel = pBagItem->refineLevel;
	info.content_lv = pBagItem->content_lv;
	info.score = pBagItem->score;
	info.tian_shu_exp = pBagItem->tian_shu_exp;

	info.soltStrengList.clear();
	info.tian_shu_set_list.clear();
	info.tianShuList.clear();

	info.soltStrengList = pBagItem->soltStrengList;
	info.tian_shu_set_list = pBagItem->tian_shu_set_list;
	info.tianShuList = pBagItem->tianShuList;

	InitWithItemInfo(info);
	return true;
}

bool CItem::InitEquipItem(pk::EquipItem* pEquipItem)
{
	if(!pEquipItem) return false;

	ItemInfo info;
	info.id   = pEquipItem->id;	                           // 
	info.index = pEquipItem->part;			                   // װ����λ 
	info.isBind = pEquipItem->isBind != 0;	                       //
	info.dataId = pEquipItem->equipDataId;                   // װ��������id
	info.refineLevel = pEquipItem->refineLevel;          
	info.enhanceLevel = pEquipItem->enhanceLevel;
	info.score   = pEquipItem->score;                        //װ������
	info.tianShuList.clear();
	info.tianShuList = pEquipItem->tianShuList;	           // ����
	info.content_lv = pEquipItem->content_lv;                //�����ȼ�
	info.soltStrengList.clear();	                           // ����λ��ǿ����Ϣ
	info.soltStrengList = pEquipItem->soltStrengList;
	info.tian_shu_use_index = pEquipItem->tian_shu_use_index;//����ʹ��������

	InitWithItemInfo(info);
	return true;
}

EquipColumnType CItem::getEquipColumnType()
{
	switch (m_pItemData->type)
	{
	case ItemType_GodDevice:return EquipColumn_GodDevice;
	case ItemType_Equip:
		{
			if ( getEquipBaseData()->type == EquipType_Weapon )
			{
				return EquipColumn_Weapon;
			}
			else
			{
				for ( int i = EquipColumn_MagicCimelia0;i<EquipColumn_MagicCimeliaMax;++i )
				{
					if ( !gGridsManager->getGirdItem(emGrids_Role,i) )
					{
						return EquipColumnType(i);
					}
				}
				return EquipColumn_MagicCimelia0;
			}
		}
		break;
	default:
		break;
	}

	return EquipColumn_Max;
}

void CItem::refreshInlayStatus()
{
	if((int)m_Info.tian_shu_set_list.size()> 0)
	{
		m_Info.otherInlay = true;
		m_Info.curInlay = false;
		//��ȡ��ǰ��Ƕװ��
		for (int i = 0; i < (int)m_Info.tian_shu_set_list.size(); i++)
		{
			if(m_Info.tian_shu_set_list[i].type == 0) //����
			{
				
			}
			else if(m_Info.tian_shu_set_list[i].type == 1) //װ��
			{
				CItem* pEquip = gGridsManager->findItemInGrids(emGrids_Role, m_Info.tian_shu_set_list[i].id);
				if(pEquip && pEquip->getItemInfo().tian_shu_use_index < (int)pEquip->getItemInfo().tianShuList.size())
				{
					for (auto iter : pEquip->getItemInfo().tianShuList[pEquip->getItemInfo().tian_shu_use_index].tianShuList)
					{
						if(iter.tianShuDataId == m_Info.dataId)
						{
							m_Info.curInlay = true;
						}
					}
					
				}
			}
			
		}
	}
	else
	{
		m_Info.curInlay = false;
		m_Info.otherInlay = false;
	}
}

