#include "StrengthenUI.h"
#include "cocostudio/CCSGUIReader.h"
#include "GameScene/GameUILayer.h"
#include "Net/NetDispatcher.h"
#include "Common/DataPool.h"
#include "GameScene/Hero.h"
#include "MessageBoxUI.h"
#include "Common/CommonDef.h"
#include "GameScene/MessageCenter.h"

#define MAX_JINGLIAN_LEVEL 30
#define MAX_JINJIE_LEVEL 5

CStrengthenUI::CStrengthenUI()
	:GameUI(IDU_StrengthenUI,JsonFile_StrengthenUI)
{
	m_select_type_item = nullptr;
	m_img_jinjie_star_vec.clear();
	m_img_attr_jinjie_star_vec.clear();
}

CStrengthenUI::~CStrengthenUI()
{
	m_select_type_item = nullptr;
	m_img_jinjie_star_vec.clear();
	m_img_attr_jinjie_star_vec.clear();
}

void CStrengthenUI::setItemType(CItem* item)
{
	m_item_type = ItemType::ItemType_Equip;
	m_item = item; 
	m_jinglian_checkbox->setSelectedState(true);
	clickCheckBox(m_jinglian_checkbox,TOUCH_EVENT_ENDED);
}

void CStrengthenUI::setItemType(GodDevice* godDevice)
{
	m_item_type = ItemType::ItemType_GodDevice;
	m_godDevice = godDevice;
	m_jinglian_checkbox->setSelectedState(true);
	clickCheckBox(m_jinglian_checkbox,TOUCH_EVENT_ENDED);
}
bool CStrengthenUI::onInit()
{
	do 
	{
		BREAK_IF(!GameUI::onInit());

		Button *pBackBtn = (Button*)Helper::seekWidgetByName(m_pWidget, "back_btn");
		BREAK_IF(pBackBtn==NULL);
		pBackBtn->setButtonSpriteGray();
		pBackBtn->addTouchEventListener(this, SEL_TouchEvent(&CStrengthenUI::clickBackButton));


		//  ������ť
		m_jinglian_btn = (Button*)Helper::seekWidgetByName(m_pWidget, "btn_jinglian");
		BREAK_IF(m_jinglian_btn==NULL);
		m_jinglian_btn->setButtonSpriteGray();
		m_jinglian_btn->addTouchEventListener(this, SEL_TouchEvent(&CStrengthenUI::clickJinglianButton));
		
		//  �������ť
		m_jinglian_max_btn = (Button*)Helper::seekWidgetByName(m_pWidget, "btn_jinglian_max");
		BREAK_IF(m_jinglian_max_btn==NULL);
		m_jinglian_max_btn->setButtonSpriteGray();
		m_jinglian_max_btn->addTouchEventListener(this, SEL_TouchEvent(&CStrengthenUI::clickJinglianMaxButton));

		//  ���װ�ť
		m_jinjie_btn = (Button*)Helper::seekWidgetByName(m_pWidget, "btn_jinjie");
		BREAK_IF(m_jinjie_btn==NULL);
		m_jinjie_btn->setButtonSpriteGray();
		m_jinjie_btn->addTouchEventListener(this, SEL_TouchEvent(&CStrengthenUI::clickJinjieButton));

		m_jinglian_checkbox = (CheckBox*)Helper::seekWidgetByName(m_pWidget, "checkbox_jinglian");				// ����checkbox
		m_jinglian_checkbox->setTag(1);
		m_jinglian_checkbox->addTouchEventListener(this, SEL_TouchEvent(&CStrengthenUI::clickCheckBox));
		m_jinglian_checkbox_text = (Text*)Helper::seekWidgetByName(m_pWidget, "checkbox_title_jinglian");		// ����checkbox��title

		m_jinjie_checkbox = (CheckBox*)Helper::seekWidgetByName(m_pWidget, "checkbox_jinjie");					// ����check
		m_jinjie_checkbox->setTag(2);
		m_jinjie_checkbox->addTouchEventListener(this, SEL_TouchEvent(&CStrengthenUI::clickCheckBox));
		m_jinjie_checkbox_text = (Text*)Helper::seekWidgetByName(m_pWidget, "checkbox_title_jinjie");			// ����checkbox��title

		// �����Ʒͼ��
		m_bg_item_icon = (ImageView*)Helper::seekWidgetByName(m_pWidget,"bg_item_icon");
	
		m_img_jinjie_star_1 = (ImageView*)Helper::seekWidgetByName(m_pWidget,"img_jinjie_star_1");		// �����Ʒ�Ǽ�1
		m_img_jinjie_star_2 = (ImageView*)Helper::seekWidgetByName(m_pWidget,"img_jinjie_star_2");		// �����Ʒ�Ǽ�2
		m_img_jinjie_star_3 = (ImageView*)Helper::seekWidgetByName(m_pWidget,"img_jinjie_star_3");		// �����Ʒ�Ǽ�3
		m_img_jinjie_star_4 = (ImageView*)Helper::seekWidgetByName(m_pWidget,"img_jinjie_star_4");		// �����Ʒ�Ǽ�4
		m_img_jinjie_star_5 = (ImageView*)Helper::seekWidgetByName(m_pWidget,"img_jinjie_star_5");		// �����Ʒ�Ǽ�5

		m_img_jinjie_star_vec.push_back(m_img_jinjie_star_1);
		m_img_jinjie_star_vec.push_back(m_img_jinjie_star_2);
		m_img_jinjie_star_vec.push_back(m_img_jinjie_star_3);
		m_img_jinjie_star_vec.push_back(m_img_jinjie_star_4);
		m_img_jinjie_star_vec.push_back(m_img_jinjie_star_5);

		// ��ྫ������
		m_jingian_level_font = (Text*)Helper::seekWidgetByName(m_pWidget, "jingian_level_font");
		// ��ྫ���ȼ�
		m_jinglian_level_text = (Text*)Helper::seekWidgetByName(m_pWidget, "jinglian_level_text");

		// �Ҳ���Ʒͼ��
		m_img_attr_head_icon = (ImageView*)Helper::seekWidgetByName(m_pWidget,"img_attr_head_icon");

		// �Ҳ���Ʒ����
		m_item_name_text = (Text*)Helper::seekWidgetByName(m_pWidget, "item_name_text");		
		// �Ҳྫ������
		m_item_type_text = (Text*)Helper::seekWidgetByName(m_pWidget, "item_type_text");
		// �Ҳྫ���ȼ�
		m_item_level_text = (Text*)Helper::seekWidgetByName(m_pWidget, "item_level_text");

		m_img_attr_jinjie_star_1 = (ImageView*)Helper::seekWidgetByName(m_pWidget,"img_attr_jinjie_star_1");	// �Ҳ���Ʒ�Ǽ�1
		m_img_attr_jinjie_star_2 = (ImageView*)Helper::seekWidgetByName(m_pWidget,"img_attr_jinjie_star_2");	// �Ҳ���Ʒ�Ǽ�2
		m_img_attr_jinjie_star_3 = (ImageView*)Helper::seekWidgetByName(m_pWidget,"img_attr_jinjie_star_3");	// �Ҳ���Ʒ�Ǽ�3
		m_img_attr_jinjie_star_4 = (ImageView*)Helper::seekWidgetByName(m_pWidget,"img_attr_jinjie_star_4");	// �Ҳ���Ʒ�Ǽ�4
		m_img_attr_jinjie_star_5 = (ImageView*)Helper::seekWidgetByName(m_pWidget,"img_attr_jinjie_star_5");	// �Ҳ���Ʒ�Ǽ�5

		m_img_attr_jinjie_star_vec.push_back(m_img_attr_jinjie_star_1);
		m_img_attr_jinjie_star_vec.push_back(m_img_attr_jinjie_star_2);
		m_img_attr_jinjie_star_vec.push_back(m_img_attr_jinjie_star_3);
		m_img_attr_jinjie_star_vec.push_back(m_img_attr_jinjie_star_4);
		m_img_attr_jinjie_star_vec.push_back(m_img_attr_jinjie_star_5);

		// �Ҳ༼������
		m_item_skill_desc_text = (Text*)Helper::seekWidgetByName(m_pWidget, "item_skill_desc_text");		
		// װ��������Ҫ�ȼ�
		m_item_level_need_text = (Text*)Helper::seekWidgetByName(m_pWidget, "item_level_need_text");			
		// ���������ı�
		m_item_consume_text = (Text*)Helper::seekWidgetByName(m_pWidget, "item_consume_text");
		// ���Ľ�������ı�
		m_item_consume_gold_text = (Text*)Helper::seekWidgetByName(m_pWidget, "item_consume_gold_text");
		// ���Ĳ��������ı�����
		m_item_consume_item_name = (Text*)Helper::seekWidgetByName(m_pWidget, "item_consume_item_name");
		// ���Ĳ��������ı�ӵ��
		m_item_consume_item_have = (Text*)Helper::seekWidgetByName(m_pWidget, "item_consume_item_have");
		// ���Ĳ��������ı���Ҫ
		m_item_consume_item_need = (Text*)Helper::seekWidgetByName(m_pWidget, "item_consume_item_need");

		// ���Ĳ�����Ʒͼ��
		m_img_consume_head_icon = (ImageView*)Helper::seekWidgetByName(m_pWidget,"img_consume_head_icon");	

		// ���Ĳ�����Ʒͼ�걳��
		m_img_consume_head_frame_icon = (ImageView*)Helper::seekWidgetByName(m_pWidget,"img_consume_head_frame_icon");	
		// ���Ľ����Ʒͼ�걳��
		m_img_gold_frame_icon = (ImageView*)Helper::seekWidgetByName(m_pWidget,"img_gold_frame_icon");	
		

		//  �����б�
		m_attr_list = (ListView*)Helper::seekWidgetByName(m_pWidget, "attr_list");
		m_attr_list->setItemsMargin(8);

		m_skill_desc_list = (ListView*)Helper::seekWidgetByName(m_pWidget, "skill_desc_list");
		m_skill_desc_list->setItemsMargin(1);

		/*m_item_type = ItemType_GodDevice;
		m_godDevice = gHero->GetGodDeviceManager().GetIsDressGodPtr();*/

		//m_item_type = ItemType_Equip;
		//m_item = gGridsManager->findItemByDataID(emGrids_Role,1);
		
		return true;
	} while (0);

	return false;
}

void CStrengthenUI::onOpen()
{
	
}

// ���ǿ���ķ���checkbox 1���� 2����
void CStrengthenUI::clickCheckBox(Ref* pSender, TouchEventType type) 
{
	if(TOUCH_EVENT_ENDED == type)
	{
		int index_ = ((CheckBox*)pSender)->getTag();	// �������б��е�index

		if (m_select_type_item != nullptr) 
		{
			m_select_type_item->setSelectedState(false); // ����Ϊ���ɵ����״̬
		}

		if(m_select_type_item == (CheckBox*)pSender) // ����ľ��ǵ�ǰѡ���ѡ�
		{
			CCLOG("not update\n");
		}else
		{
			m_select_type_item =  ((CheckBox*)pSender);
			updateSelectType(index_);
			CCLOG("update\n");
		}
	}
}

Widget*	CStrengthenUI::createAtrributeItem()
{
	auto node = GUIReader::getInstance()->widgetFromJsonFile("assets/ui/StrengthenAtrributeItem.json");
	return node;
}

void CStrengthenUI::clickBackButton(Ref* pSender, TouchEventType type)
{
	if(TOUCH_EVENT_ENDED == type)
	{
		gGameUILayer->destroyUI(this);
	}
}

// ����˾�����ť
void CStrengthenUI::clickJinglianButton(Ref* pSender, TouchEventType type)
{
	if(TOUCH_EVENT_ENDED == type)
	{
		int jinjie_level_ = 0;
		int jinglian_level_ = 0;
		int need_gold_number_ = 0;
		int need_item_number_ = 0;
		int need_item_id_ = 0;

		if (m_item_type == ItemType_GodDevice)
		{
			jinjie_level_ =  m_godDevice->GetGodEnhanceLevel();
			jinglian_level_ = m_godDevice->GetGodRefineLevel();

			if (jinglian_level_>=MAX_JINGLIAN_LEVEL)
			{
				gMessageCenter->SystemMessage(SystemMessage_Prompt,STR_Text_Tip_jinglian_max);
				return;
			}
			
			need_item_id_ = getEquipItemCfgID(1,jinjie_level_,jinglian_level_,m_godDevice->GetGodDataId());
			need_gold_number_ = getEquipGoldConsume(1,jinjie_level_,jinglian_level_,m_godDevice->GetGodDataId());
			need_item_number_ = getEquipItemNumebr(1,jinjie_level_,jinglian_level_,m_godDevice->GetGodDataId());
		}else
		{
			jinjie_level_ =  m_item->getEnhanceLv();
			jinglian_level_ = m_item->getRefinedLv();

			if (jinglian_level_>=MAX_JINGLIAN_LEVEL)
			{
				gMessageCenter->SystemMessage(SystemMessage_Prompt,STR_Text_Tip_jinglian_max);
				return;
			}

			need_item_id_ = getEquipItemCfgID(1,jinjie_level_,jinglian_level_,m_item->getDataID());
			need_gold_number_ = getEquipGoldConsume(1,jinjie_level_,jinglian_level_,m_item->getDataID());
			need_item_number_ = getEquipItemNumebr(1,jinjie_level_,jinglian_level_,m_item->getDataID());
		}

		bool is_level_over_ = jinglian_level_ >= gHero->GetLevel()/2;
		if (is_level_over_)
		{
			gMessageCenter->SystemMessage(SystemMessage_Prompt,STR_Text_Tip_level_not_enough);
			return;
		}
		int temp_gold_ = gHero->GetMoney();
		bool is_gold_enough_ = gHero->GetMoney() >= need_gold_number_;
		if (!is_gold_enough_)
		{
			gMessageCenter->SystemMessage(SystemMessage_Prompt,STR_Text_Tip_gold_not_enough);
			return;
		}

		int temp_material_ = gGridsManager->getItemCountByDataID(emGrids_BagMaterial,need_item_id_);
		bool is_material_enough_ = gGridsManager->getItemCountByDataID(emGrids_BagMaterial,need_item_id_) >= need_item_number_;
		if (!is_material_enough_)
		{
			gMessageCenter->SystemMessage(SystemMessage_Prompt,STR_Text_Tip_item_not_enough);
			return;
		}

		CMessageBoxUI::Show(CMessageBoxUI::MBM_YESNO,STR_Text_Tip_Jinglian,[&](bool type){
			if(type)
			{
				pk::C2GS_Refine cmd;
				if (m_item_type == ItemType_Equip)
				{
					cmd.type = 2;
					cmd.equipId = m_item->getId();
				}else
				{
					cmd.type = 1;
					cmd.equipId = 0;
				}
				cmd.isRefineMaxLevel = 0;
				cmd.Send(gNetSocket);
			}
		},STR_MESSAGEBOX_COMFIRM.c_str(),STR_MESSAGEBOX_CANCEL.c_str(),
			this,NULL,CMessageBoxUI::Scene_Game);
	}
}

// ������������ť
void CStrengthenUI::clickJinglianMaxButton(Ref* pSender, TouchEventType type)
{
	if(TOUCH_EVENT_ENDED == type)
	{
		int jinjie_level_ = 0;
		int jinglian_level_ = 0;
		int need_gold_number_ = 0;
		int need_item_number_ = 0;
		int need_item_id_ = 0;

		if (m_item_type == ItemType_GodDevice)
		{
			jinjie_level_ =  m_godDevice->GetGodEnhanceLevel();
			jinglian_level_ = m_godDevice->GetGodRefineLevel();

			if (jinglian_level_>=MAX_JINGLIAN_LEVEL)
			{
				gMessageCenter->SystemMessage(SystemMessage_Prompt,STR_Text_Tip_jinglian_max);
				return;
			}

			need_item_id_ = getEquipItemCfgID(1,jinjie_level_,jinglian_level_,m_godDevice->GetGodDataId());
			need_gold_number_ = getEquipGoldConsume(1,jinjie_level_,jinglian_level_,m_godDevice->GetGodDataId());
			need_item_number_ = getEquipItemNumebr(1,jinjie_level_,jinglian_level_,m_godDevice->GetGodDataId());
		}else
		{
			jinjie_level_ =  m_item->getEnhanceLv();
			jinglian_level_ = m_item->getRefinedLv();

			if (jinglian_level_>=MAX_JINGLIAN_LEVEL)
			{
				gMessageCenter->SystemMessage(SystemMessage_Prompt,STR_Text_Tip_jinglian_max);
				return;
			}

			need_item_id_ = getEquipItemCfgID(1,jinjie_level_,jinglian_level_,m_item->getDataID());
			need_gold_number_ = getEquipGoldConsume(1,jinjie_level_,jinglian_level_,m_item->getDataID());
			need_item_number_ = getEquipItemNumebr(1,jinjie_level_,jinglian_level_,m_item->getDataID());
		}

		bool is_level_over_ = jinglian_level_ >= gHero->GetLevel()/2;
		if (is_level_over_)
		{
			gMessageCenter->SystemMessage(SystemMessage_Prompt,STR_Text_Tip_level_not_enough);
			return;
		}

		bool is_gold_enough_ = gHero->GetMoney() >= need_gold_number_;
		if (!is_gold_enough_)
		{
			gMessageCenter->SystemMessage(SystemMessage_Prompt,STR_Text_Tip_gold_not_enough);
			return;
		}
		bool is_material_enough_ = gGridsManager->getItemCountByDataID(emGrids_BagMaterial,need_item_id_) >= need_item_number_;
		if (!is_material_enough_)
		{
			gMessageCenter->SystemMessage(SystemMessage_Prompt,STR_Text_Tip_item_not_enough);
			return;
		}

		CMessageBoxUI::Show(CMessageBoxUI::MBM_YESNO,STR_Text_Tip_Jinglian_Max,[&](bool type){
			if(type)
			{
				pk::C2GS_Refine cmd;
				if (m_item_type == ItemType_Equip)
				{
					cmd.type = 2;
					cmd.equipId = m_item->getId();
				}else
				{
					cmd.type = 1;
					cmd.equipId = 0;
				}
				cmd.isRefineMaxLevel = 1;
				cmd.Send(gNetSocket);
			}
		},STR_MESSAGEBOX_COMFIRM.c_str(),STR_MESSAGEBOX_CANCEL.c_str(),
			this,NULL,CMessageBoxUI::Scene_Game);

	}
}

// ����˽��װ�ť
void CStrengthenUI::clickJinjieButton(Ref* pSender, TouchEventType type)
{
	if(TOUCH_EVENT_ENDED == type)
	{

		int jinjie_level_ = 0;
		int jinglian_level_ = 0;
		int need_gold_number_ = 0;
		int need_item_number_ = 0;
		int need_item_id_ = 0;

		if (m_item_type == ItemType_GodDevice)
		{
			jinjie_level_ =  m_godDevice->GetGodEnhanceLevel();
			jinglian_level_ = m_godDevice->GetGodRefineLevel();

			if (jinjie_level_>=MAX_JINJIE_LEVEL)
			{
				gMessageCenter->SystemMessage(SystemMessage_Prompt,STR_Text_Tip_jinjie_max);
				return;
			}

			need_item_id_ = getEquipItemCfgID(2,jinjie_level_,jinglian_level_,m_godDevice->GetGodDataId());
			need_gold_number_ = getEquipGoldConsume(2,jinjie_level_,jinglian_level_,m_godDevice->GetGodDataId());
			need_item_number_ = getEquipItemNumebr(2,jinjie_level_,jinglian_level_,m_godDevice->GetGodDataId());
		}else
		{
			jinjie_level_ =  m_item->getEnhanceLv();
			jinglian_level_ = m_item->getRefinedLv();

			if (jinjie_level_>=MAX_JINJIE_LEVEL)
			{
				gMessageCenter->SystemMessage(SystemMessage_Prompt,STR_Text_Tip_jinjie_max);
				return;
			}

			need_item_id_ = getEquipItemCfgID(2,jinjie_level_,jinglian_level_,m_item->getDataID());
			need_gold_number_ = getEquipGoldConsume(2,jinjie_level_,jinglian_level_,m_item->getDataID());
			need_item_number_ = getEquipItemNumebr(2,jinjie_level_,jinglian_level_,m_item->getDataID());
		}

		if (jinglian_level_<MAX_JINGLIAN_LEVEL/2)
		{
			gMessageCenter->SystemMessage(SystemMessage_Prompt,STR_Text_Tip_Jinjie_need);
			return;
		}

		bool is_gold_enough_ = gHero->GetMoney() >= need_gold_number_;
		if (!is_gold_enough_)
		{
			gMessageCenter->SystemMessage(SystemMessage_Prompt,STR_Text_Tip_gold_not_enough);
			return;
		}
		bool is_material_enough_ = gGridsManager->getItemCountByDataID(emGrids_BagMaterial,need_item_id_) >= need_item_number_;
		if (!is_material_enough_)
		{
			gMessageCenter->SystemMessage(SystemMessage_Prompt,STR_Text_Tip_item_not_enough);
			return;
		}

		CMessageBoxUI::Show(CMessageBoxUI::MBM_YESNO,STR_Text_Tip_Jinjie,[&](bool type){
			if(type)
			{
				pk::C2GS_Enhance cmd;
				if (m_item_type == ItemType_Equip)
				{
					cmd.type = 2;
					cmd.equipId = m_item->getId();
				}else
				{
					cmd.type = 1;
					cmd.equipId = 0;
				}
				cmd.Send(gNetSocket);
			}
		},STR_MESSAGEBOX_COMFIRM.c_str(),STR_MESSAGEBOX_CANCEL.c_str(),
			this,NULL,CMessageBoxUI::Scene_Game);
	}
}
void CStrengthenUI::updateSelectType(int index)
{
	switch (index)
	{
	case 1:// ����
		m_jinglian_checkbox_text->setColor(Color3B(222,209,164));
		m_jinjie_checkbox_text->setColor(Color3B::WHITE);
		updatejinglian();
		break;
	case 2:// ����
		m_jinglian_checkbox_text->setColor(Color3B::WHITE);
		m_jinjie_checkbox_text->setColor(Color3B(222,209,164));
		updatejinjie();
		break;
	default:
		break;
	}
}

// ���¾���
void CStrengthenUI::updatejinglian()
{	
	m_jinglian_max_btn->setEnabled(true);
	m_jinglian_btn->setEnabled(true);
	m_jinjie_btn->setEnabled(false);

	m_img_jinjie_star_1->setVisible(false);
	m_img_jinjie_star_2->setVisible(false);
	m_img_jinjie_star_3->setVisible(false);
	m_img_jinjie_star_4->setVisible(false);
	m_img_jinjie_star_5->setVisible(false);

	m_jingian_level_font->setVisible(true);
	m_jinglian_level_text->setVisible(true);

	int jinglian_level_ = 1;

	if (m_item_type == ItemType_GodDevice)
	{
		jinglian_level_ = m_godDevice->GetGodRefineLevel();
	}else
	{
		jinglian_level_ = m_item->getRefinedLv();
	}

	if (jinglian_level_<MAX_JINGLIAN_LEVEL)
	{
		m_img_gold_frame_icon->setVisible(true);
		m_img_consume_head_frame_icon->setVisible(true);
		m_item_consume_text->setVisible(true);
		m_item_consume_gold_text->setVisible(true);
		m_item_consume_item_name->setVisible(true);
		m_item_consume_item_need->setVisible(true);
		m_item_consume_item_have->setVisible(true);
	}else
	{
		m_img_gold_frame_icon->setVisible(false);
		m_img_consume_head_frame_icon->setVisible(false);
		m_item_consume_text->setVisible(false);
		m_item_consume_gold_text->setVisible(false);
		m_item_consume_item_name->setVisible(false);
		m_item_consume_item_need->setVisible(false);
		m_item_consume_item_have->setVisible(false);
	}

	m_jinglian_level_text->setText(FORMAT_TO_STRING("%d",jinglian_level_));
	m_item_consume_text->setText(STR_Text_Jinglian_Consume);

	updateAttribute(1);
}

// ���½���
void CStrengthenUI::updatejinjie()
{
	m_jinglian_max_btn->setEnabled(false);
	m_jinglian_btn->setEnabled(false);
	m_jinjie_btn->setEnabled(true);

	m_jingian_level_font->setVisible(false);
	m_jinglian_level_text->setVisible(false);

	int jinjie_level_ = 1;
	if (m_item_type == ItemType_GodDevice)
	{
		jinjie_level_ = m_godDevice->GetGodEnhanceLevel();
	}else
	{
		jinjie_level_ = m_item->getEnhanceLv();
	}
	setLeftStar(jinjie_level_);

	if (jinjie_level_<MAX_JINJIE_LEVEL)
	{
		m_img_gold_frame_icon->setVisible(true);
		m_img_consume_head_frame_icon->setVisible(true);
		m_item_consume_text->setVisible(true);
		m_item_consume_gold_text->setVisible(true);
		m_item_consume_item_name->setVisible(true);
		m_item_consume_item_have->setVisible(true);
		m_item_consume_item_need->setVisible(true);
	}else
	{
		m_img_gold_frame_icon->setVisible(false);
		m_img_consume_head_frame_icon->setVisible(false);
		m_item_consume_text->setVisible(false);
		m_item_consume_gold_text->setVisible(false);
		m_item_consume_item_name->setVisible(false);
		m_item_consume_item_have->setVisible(false);
		m_item_consume_item_need->setVisible(false);
	}

	m_item_consume_text->setText(STR_Text_Jinjie_Consume);
	updateAttribute(2);
}

// ��������
void CStrengthenUI::updateAttribute(int type) // type:1���� 2����
{
	m_attr_list->removeAllItems();
	m_skill_desc_list->removeAllItems();

	int need_level_ = 0;
	int need_gold_number_ = 0;
	int need_item_number_ = 0;
	int need_item_id_ = 0;

	int jinjie_level_ = 0;
	int jinglian_level_ = 0; 
	string item_name_text_; 

	if (m_item_type == ItemType_GodDevice)
	{
		jinjie_level_ =  m_godDevice->GetGodEnhanceLevel();
		jinglian_level_ = m_godDevice->GetGodRefineLevel();
		item_name_text_ = m_godDevice->GetGodName();

		auto all_attr_vec = m_godDevice->m_all_attr_vec[jinjie_level_];
		need_level_ = ItemData.get(m_godDevice->GetGodDataId())->uselevel;

		if (1 == type )
		{
			if (jinglian_level_<MAX_JINGLIAN_LEVEL)
			{
				need_gold_number_ = getEquipGoldConsume(type,jinjie_level_,jinglian_level_,m_godDevice->GetGodDataId());
				need_item_number_ = getEquipItemNumebr(type,jinjie_level_,jinglian_level_,m_godDevice->GetGodDataId());
				need_item_id_ = getEquipItemCfgID(type,jinjie_level_,jinglian_level_,m_godDevice->GetGodDataId());
			}
		}else
		{
			if (jinjie_level_<MAX_JINJIE_LEVEL)
			{
				need_gold_number_ = getEquipGoldConsume(type,jinjie_level_,jinglian_level_,m_godDevice->GetGodDataId());
				need_item_number_ = getEquipItemNumebr(type,jinjie_level_,jinglian_level_,m_godDevice->GetGodDataId());
				need_item_id_ = getEquipItemCfgID(type,jinjie_level_,jinglian_level_,m_godDevice->GetGodDataId());
			}
		}

		for (size_t i = 0;i<m_godDevice->GetGodSkillIdVec().size();i++)
		{
			int skill_id_ = m_godDevice->GetGodSkillIdVec()[i];
			string desc_string_ = SkillData.get(skill_id_)->desc;
			Text* desc_text_ = Text::create(desc_string_,"arial",18);
			desc_text_->setColor(Color3B(44,240,12)); // �Ѽ���������Ϊ��ɫ

			m_skill_desc_list->pushBackCustomItem(desc_text_);
		}

		for (size_t i = 0;i<all_attr_vec.size();++i)
		{
			auto temp_item_ = createAtrributeItem();
			auto attr_name_text_ = (Text*)Helper::seekWidgetByName(temp_item_, "attr_name_text");
			auto attr_number_text_ = (Text*)Helper::seekWidgetByName(temp_item_, "attr_number_text");
			auto attr_dif_number_text_ = (Text*)Helper::seekWidgetByName(temp_item_, "attr_dif_number_text");

			string attribute_name_ = getEquipAttributeName(jinjie_level_,i,m_godDevice->m_all_attr_vec);
			attribute_name_.append(":");
			attr_name_text_->setText(attribute_name_);

			string attribute_total_value_ = FORMAT_TO_STRING("%d",getEquipTotalAttribute(jinjie_level_,jinglian_level_,i,m_godDevice->m_all_attr_vec));
			attr_number_text_->setText(attribute_total_value_);
	
			if (1 == type )
			{
				if (jinglian_level_<MAX_JINGLIAN_LEVEL)
				{
					if (getEquipAtrributeIfChange(type,jinjie_level_,jinglian_level_,i,m_godDevice->m_all_attr_vec))
					{
						attr_dif_number_text_->setVisible(true);
						string attribute_change_value_ = getEquipAtrributeChange(type,jinjie_level_,jinglian_level_,i,m_godDevice->m_all_attr_vec);
						attr_dif_number_text_->setText(attribute_change_value_);
						attr_dif_number_text_->setColor(Color3B(44,240,12));
					}else
					{
						attr_dif_number_text_->setVisible(false);
					}
				}else
				{
					attr_dif_number_text_->setVisible(false);
				}
			}else
			{
				if (jinjie_level_<MAX_JINJIE_LEVEL)
				{
					if (getEquipAtrributeIfChange(type,jinjie_level_,jinglian_level_,i,m_godDevice->m_all_attr_vec))
					{
						attr_dif_number_text_->setVisible(true);
						string attribute_change_value_ = getEquipAtrributeChange(type,jinjie_level_,jinglian_level_,i,m_godDevice->m_all_attr_vec);
						attr_dif_number_text_->setText(attribute_change_value_);
						attr_dif_number_text_->setColor(Color3B(44,240,12));
					}else
					{
						attr_dif_number_text_->setVisible(false);
					}
				}else
				{
					attr_dif_number_text_->setVisible(false);
				}
			}

			m_attr_list->pushBackCustomItem(temp_item_);
		}

	}else if (m_item_type == ItemType_Equip)
	{
		jinjie_level_ =  m_item->getEnhanceLv();
		jinglian_level_ = m_item->getRefinedLv();
		item_name_text_ = m_item->getEquipBaseData()->name;

		auto all_attr_vec = m_item->m_all_attr_vec[jinjie_level_];
		need_level_ = ItemData.get(m_item->getDataID())->uselevel;

		if (type == 1)
		{
			if (jinglian_level_<MAX_JINGLIAN_LEVEL)
			{
				need_gold_number_ = getEquipGoldConsume(type,jinjie_level_,jinglian_level_,m_item->getDataID());
				need_item_number_ = getEquipItemNumebr(type,jinjie_level_,jinglian_level_,m_item->getDataID());
				need_item_id_ = getEquipItemCfgID(type,jinjie_level_,jinglian_level_,m_item->getDataID());
			}
		}else
		{
			if (jinjie_level_<MAX_JINJIE_LEVEL)
			{
				need_gold_number_ = getEquipGoldConsume(type,jinjie_level_,jinglian_level_,m_item->getDataID());
				need_item_number_ = getEquipItemNumebr(type,jinjie_level_,jinglian_level_,m_item->getDataID());
				need_item_id_ = getEquipItemCfgID(type,jinjie_level_,jinglian_level_,m_item->getDataID());
			}
		}
		
		for (size_t i = 0;i<m_item->m_skillId_vec.size();i++)
		{
			int skill_id_ = m_item->m_skillId_vec[i];
			string desc_string_ = SkillData.get(skill_id_)->desc;
			Text* desc_text_ = Text::create(desc_string_,"arial",18);
			desc_text_->setColor(Color3B(44,240,12)); // �Ѽ���������Ϊ��ɫ

			m_skill_desc_list->pushBackCustomItem(desc_text_);
		}

		for (size_t i = 0;i<all_attr_vec.size();i++)
		{
			auto temp_item_ = createAtrributeItem();
			auto attr_name_text_ = (Text*)Helper::seekWidgetByName(temp_item_, "attr_name_text");
			auto attr_number_text_ = (Text*)Helper::seekWidgetByName(temp_item_, "attr_number_text");
			auto attr_dif_number_text_ = (Text*)Helper::seekWidgetByName(temp_item_, "attr_dif_number_text");

			string attribute_name_ = getEquipAttributeName(jinjie_level_,i,m_item->m_all_attr_vec);
			attribute_name_.append(":");
			attr_name_text_->setText(attribute_name_);

			string attribute_total_value_ = FORMAT_TO_STRING("%d",getEquipTotalAttribute(jinjie_level_,jinglian_level_,i,m_item->m_all_attr_vec));
			attr_number_text_->setText(attribute_total_value_);

			if (type == 1)
			{
				if (jinglian_level_<MAX_JINGLIAN_LEVEL)
				{
					if (getEquipAtrributeIfChange(type,jinjie_level_,jinglian_level_,i,m_item->m_all_attr_vec))
					{
						attr_dif_number_text_->setVisible(true);
						string attribute_change_value_ = getEquipAtrributeChange(type,jinjie_level_,jinglian_level_,i,m_item->m_all_attr_vec);
						attr_dif_number_text_->setText(attribute_change_value_);
						attr_dif_number_text_->setColor(Color3B(44,240,12));
					}else
					{
						attr_dif_number_text_->setVisible(false);
					}
				}else
				{
					attr_dif_number_text_->setVisible(false);
				}
			}else
			{
				if (jinjie_level_<MAX_JINJIE_LEVEL)
				{
					if (getEquipAtrributeIfChange(type,jinjie_level_,jinglian_level_,i,m_item->m_all_attr_vec))
					{
						attr_dif_number_text_->setVisible(true);
						string attribute_change_value_ = getEquipAtrributeChange(type,jinjie_level_,jinglian_level_,i,m_item->m_all_attr_vec);
						attr_dif_number_text_->setText(attribute_change_value_);
						attr_dif_number_text_->setColor(Color3B(44,240,12));
					}else
					{
						attr_dif_number_text_->setVisible(false);
					}
				}else
				{
					attr_dif_number_text_->setVisible(false);
				}
			}

			m_attr_list->pushBackCustomItem(temp_item_);
		}
	}

	setRightStar(jinjie_level_);
	
	m_item_level_text->setText(FORMAT_TO_STRING("%d",jinglian_level_));
	m_item_name_text->setText(item_name_text_);

	m_item_level_need_text->setVisible(need_level_ != 1);
	m_item_level_need_text->setColor(Color3B(240,12,12)); // ������ȼ���Ϊ��ɫ
	m_item_level_need_text->setText(FORMAT_TO_STRING("Need:%d",need_level_));

	bool is_gold_enough_ = gHero->GetMoney() >= need_gold_number_;
	if (!is_gold_enough_)
	{
		m_item_consume_gold_text->setColor(Color3B::RED);
	}else
	{
		m_item_consume_gold_text->setColor(Color3B::WHITE);
	}
	m_item_consume_gold_text->setText(FORMAT_TO_STRING("%d",need_gold_number_));

	if (type == 1)
	{
		m_item_consume_item_name->setText(FORMAT_TO_STRING("%s:",STR_Text_Jinglian_Stone));
	}else if(type == 2)
	{
		m_item_consume_item_name->setText(FORMAT_TO_STRING("%s:",STR_Text_Jinjie_Stone));
	}

	m_item_consume_item_have->setText(FORMAT_TO_STRING("/%d",gGridsManager->getItemCountByDataID(emGrids_BagMaterial,need_item_id_)));
	m_item_consume_item_need->setText(FORMAT_TO_STRING("%d",need_item_number_));
	
	bool is_material_enough_ = gGridsManager->getItemCountByDataID(emGrids_BagMaterial,need_item_id_) >= need_item_number_;
	if (!is_material_enough_)
	{
		m_item_consume_item_need->setColor(Color3B::RED);
		m_item_consume_item_have->setColor(Color3B::RED);
	}else
	{
		m_item_consume_item_need->setColor(Color3B::WHITE);
		m_item_consume_item_have->setColor(Color3B::WHITE);
	}
	m_item_consume_item_need->setPositionX(m_item_consume_item_name->getPositionX()+ m_item_consume_item_name->getContentSize().width);
	m_item_consume_item_have->setPositionX(m_item_consume_item_need->getPositionX()+ m_item_consume_item_need->getContentSize().width);
}

void CStrengthenUI::setLeftStar(int star)
{

	for (int i = 0;i < 5;i++)
	{
		m_img_jinjie_star_vec[i]->setVisible(false);
	}

	for (int i = 0;i < star;i++)
	{
		m_img_jinjie_star_vec[i]->setVisible(true);
	}
}

void CStrengthenUI::setRightStar(int star)
{

	for (int i = 0;i < 5;i++)
	{
		m_img_attr_jinjie_star_vec[i]->setVisible(false);
	}

	for (int i = 0;i < star;i++)
	{
		m_img_attr_jinjie_star_vec[i]->setVisible(true);
	}
}


