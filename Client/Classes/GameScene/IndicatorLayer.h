/***
 * ģ�飺IndicatorLayer
 * ���ߣ�������
 * ʱ�䣺2015-09-25
 * ˵����Ӣ����ߵķ���ָʾ��
 */
#pragma once

#include "GameDef.h"
#include "UI/GameUI.h"
#include "Net/pk_map.h"

class RoleFighter;

class CIndicatorLayer : public Layer
{
public:
	//ָʾ��
	typedef struct _indicator
	{
		Widget* ui;
		Point	targetPos;
		int		offsetX;
		int		offsetY;

		_indicator(Widget* pUI = nullptr, Point pos = Point::ZERO, int X = 3, int Y = 3)
		{
			ui=pUI;
			targetPos = pos;
			offsetX = X;
			offsetY = Y;
		}
	}Indicator;

public:
	CIndicatorLayer(RoleFighter* pRole);
	~CIndicatorLayer();

	static CIndicatorLayer* createWithRole(RoleFighter* pRole);

	bool	Init();
	void	SetDynamicIndicators(pk::GS2C_GUIDE_LIST* value);
	void	AddStaticIndicator(int cx, int cy, int offsetX, int offsetY);
	void	RemoveDynamicIndicators();
	void	RemoveStaticIndicators();
	void	RemoveIndicators();
	void	UpdateDynamicIndicators();
	void	UpdateStaticIndicators();
	void	UpdateIndicators();

	inline RoleFighter* GetRole(){ return m_pRole; }

private:
	RoleFighter*		m_pRole;					// ��ɫ����ָ��
	vector<Indicator>	m_pDynamicIndicators;	//��̬����ָʾ�� 
	vector<Indicator>	m_pStaticIndicators;	//��̬����ָʾ��
};