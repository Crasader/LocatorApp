/****************************************************************************
 ����ս���ȷ�UI
 ������
 2015-09-29
 ****************************************************************************/
#pragma once
#include "GameDef.h"
#include "GameUI.h"
#include "Net/pk_map.h"

class CFreeFightScoreUI : public GameUI
{
public:
	CFreeFightScoreUI();
	~CFreeFightScoreUI();

	bool			onInit();
	void			clickExit(Ref*, TouchEventType);
	void			UpdateScore(pk::GS2C_FreeFightCopyScoreBoard* value);

private:
	Text*					m_pBlueScore;
	Text*					m_pRedScore;
	Slider*					m_pSlider;							//������
	ListView*				m_pListView;						//�б�
	Widget*					m_pListItem;						//�б�item
};

