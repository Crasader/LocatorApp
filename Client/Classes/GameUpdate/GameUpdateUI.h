/***
 * ģ�飺��Ϸ���½���չʾ
 * ���ߣ�yueliangyou
 * ʱ�䣺2015-07-21
 * ˵�������½�����Դ��Դ��update�ļ��У��������Դ��Թ̶���δ���д����
 */
#pragma once

#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include "UI/CustomCtrl/ProgressBar.h"
USING_NS_CC;
using namespace std;
using namespace ui;

class GameUpdateUI : public Layer
{
public:
	GameUpdateUI();
	~GameUpdateUI();

	CREATE_FUNC(GameUpdateUI);

	/**
	 * Name : init
	 * Des  : ��ʼ���������ָ��
	 * Param:
	 */
	bool init();

	/**
	 * Name : GetProgressBar
	 * Des  : ��ȡ������
	 * Param: none
	 */
	inline ProgerssBar* GetProgressBar(){ return m_pProgressBar; }

	/**
	 * Name : GetTipsLabel
	 * Des  : ��ȡ��ʾ��ǩ
	 * Param: none
	 */
	inline Label* GetTipsLabel(){ return m_pLabelTips; }

	/**
	 * Name : update
	 * Des  : ���¼��ؽ���
	 * Parma: fd ʱ����
	 */
	void update(float dt);

private:
	Label*						m_pLabelTips;		// ������ʾ��ǩ
	ProgerssBar*				m_pProgressBar;		// ������
};