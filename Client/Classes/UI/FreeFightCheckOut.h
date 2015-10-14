/****************************************************************************
 ����ս������UI
 ������
 2015-10-37
 ****************************************************************************/
#pragma once
#include "GameDef.h"
#include "GameUI.h"
#include "Net/pk_map.h"

class CFreeFightCheckOut : public GameUI
{
public:
	CFreeFightCheckOut();
	~CFreeFightCheckOut();

	bool			onInit();
	void			clickTab(int index);
	void			setCheckOutData(pk::GS2C_FreeFightCopyCheckout* value);
	void			clickExit(Ref*, TouchEventType);

private:
	pk::GS2C_FreeFightCopyCheckout			m_checkOutdata;

	Text*					m_pBlueScore;
	Text*					m_pRedScore;
	Text*					m_pVictory;
	Slider*					m_pSlider;							//������
	ListView*				m_pListView;						//�б�
	Widget*					m_pListItem;						//�б�item
	RadioButtonSet*			m_pRadioBtn;
};

