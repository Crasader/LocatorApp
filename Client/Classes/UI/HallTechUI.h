/****************************************************************************
 ս��ϵͳUI
 ����
 2015-9-22
 ****************************************************************************/
#pragma once
#include "GameDef.h"
#include "GameUI.h"
#include "../GameScene/GameUILayer.h"
#include "GameScene/Hero.h"
#include "GameScene/GameDataManager.h"

// ս���Ƽ����ж��Ƿ�������������
inline bool isUnlockHallTech(int hallTech_id,int cur_level)
{
	string list_ = HallTechData.get(hallTech_id)->unlock_lv;
	vector<string> condition_vec_;
	vector<vector<int>> all_condition_vec_;

	StringSplit(list_,";",condition_vec_);

	for (size_t i = 0;i<condition_vec_.size();++i)
	{
		vector<int> single_condition_vec;
		StringSplitToInt(condition_vec_[i],",",single_condition_vec);
		all_condition_vec_.push_back(single_condition_vec);
	}	 

	// �����ǰ�ȼ��Ѿ��ﵽ���
	if (cur_level>=(int)all_condition_vec_.size())
	{
		return false;
	}

	vector<int> cur_level_condition_ = all_condition_vec_[cur_level];

	for (size_t i = 0;i<cur_level_condition_.size();i+=2)
	{
		int id_  = cur_level_condition_[i];
		int level_ = cur_level_condition_[i+1];

		if ( gHero->GetHallTechManager().GetLevelByID(id_) < level_)
		{
			return false;
		}
	}

	return true;
}

// ս���Ƽ����õ���������Ľ�Ǯ����
inline int GetUpgradeGoldByLevel(int hallTech_id,int level)
{
	vector<int> needGold_vec_;
	StringSplitToInt(HallTechData.get(hallTech_id)->gold,";",needGold_vec_);
	if (level>=HallTechData.get(hallTech_id)->max_lv) // ��ǰ�ȼ��Ѿ��ﵽ���ȼ�
	{
		return 0;
	}
	return needGold_vec_[level];
}

// ս���Ƽ����ж��Ƿ����������������������ı�
inline vector<Text*> GetUnlockHallTechText(int hallTech_id,int cur_level)
{
	string list_ = HallTechData.get(hallTech_id)->unlock_lv;
	vector<string> condition_vec_;
	vector<vector<int>> all_condition_vec_;

	vector<Text*> temp_text_vec_;

	condition_vec_.clear();
	all_condition_vec_.clear();
	temp_text_vec_.clear();

	StringSplit(list_,";",condition_vec_);

	for (size_t i = 0;i<condition_vec_.size();++i)
	{
		vector<int> single_condition_vec;
		StringSplitToInt(condition_vec_[i],",",single_condition_vec);
		all_condition_vec_.push_back(single_condition_vec);
	}	 

	// �����ǰ�ȼ��Ѿ��ﵽ���
	if (cur_level>=(int)all_condition_vec_.size())
	{
		return temp_text_vec_;
	}

	vector<int> cur_level_condition_ = all_condition_vec_[cur_level];

	for (size_t i = 0;i<cur_level_condition_.size();i+=2)
	{
		int id_  = cur_level_condition_[i];
		int level_ = cur_level_condition_[i+1];
		Text* temp_text_ = Text::create();
		string temp_name_ = HallTechData.get(id_)->name;
		temp_text_->setText(temp_name_.append(FORMAT_TO_STRING(" LV.%d",level_)));
		temp_text_->setFontSize(20);

		if ( gHero->GetHallTechManager().GetLevelByID(id_) < level_)
		{
			temp_text_->setColor(Color3B::RED);
		}else
		{
			temp_text_->setColor(Color3B::WHITE);
		}
		temp_text_vec_.push_back(temp_text_);
	}
	return temp_text_vec_;
}

inline bool GetHallUpgradeState(int hallTech_id)
{
	HallTech* temp_hallTech_ = gHero->GetHallTechManager().GetByCfgID(hallTech_id);
	if (temp_hallTech_ == nullptr)
	{
		return false;
	}else
	{
		if(temp_hallTech_->m_nextLvTime == 0)
		{
			return false;
		}
	}

	return true;
}

inline string GetHallDesByLevel(int hallTech_id,int cur_level)
{
	HallTechCfg* m_pHallTechData = HallTechData.get(hallTech_id);

	if (hallTech_id == 1)
	{
		switch (cur_level)
		{
		case 1:
			return m_pHallTechData->description1;
			break;
		case 2:
			return m_pHallTechData->description2;
			break;
		case 3:
			return m_pHallTechData->description3;
			break;
		default:
			return "not found";
			break;
		}
	}else
	{
		switch (cur_level)
		{
		case 0:
			return m_pHallTechData->description1;
			break;
		case 1:
			return m_pHallTechData->description2;
			break;
		case 2:
			return m_pHallTechData->description3;
			break;
		default:
			return "not found";
			break;
		}
	}
}

inline int GetHallItemNumberByLevel(int hallTech_id,int cur_level)
{
	HallTechCfg* m_pHallTechData = HallTechData.get(hallTech_id);
	vector<int> temp_item_number_vec_;
	StringSplitToInt(m_pHallTechData->item_number,";",temp_item_number_vec_);

	if (cur_level>=(int)temp_item_number_vec_.size())
	{
		return 0;
	}

	return temp_item_number_vec_[cur_level];
}

class CHallTechUI : public GameUI
{
public:
	CHallTechUI();
	~CHallTechUI();

	bool			onInit();
	void			onOpen();
	void			onClose();

	CREATE_FUNC(CHallTechUI);
public:				
	void			clickBackButton(Ref*, TouchEventType);			//  ������������水ť
	void			clickMapEnteranceButton(Ref*,TouchEventType);	//  ����˵�ͼ�ϵ���ڰ�ť
	void			clickEnteranceButton(Ref*, TouchEventType);		//  �����ڰ�ť
	void			ClickSwitchB(Ref*, TouchEventType);

	void			clickChat(Ref*, TouchEventType);				//  ��������찴ť
	void			updateChatMsg(pk::GS2C_Chat *value);

private:
	Text*						m_Lv;				// ͷ��ȼ��ı�
	ImageView*					m_head_img;			// ͷ��ͼƬ

	//����
	Layout*					m_pChatUI;

	class HornContorller*	m_pHornWind;
	class CScrollMsgWindow*	m_pMsgWind;
	Button*					m_pButtonChat;

	Layout*					m_panelMenuB;	//�ײ��˵�Panel
	Button*					m_BtnSwitchB;	//�ײ��˵�����

public:
};

