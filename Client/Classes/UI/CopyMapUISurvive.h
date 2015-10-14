/* 
	���渱��UI
	������
	2015-09-02
*/
#pragma once
#include "cocos2d.h"
#include "GameUI.h"
#include "CopyMapUI.h"

//���渱��
class CCopyMapUISurvive:public CCopyMapUI
{
public:
	CCopyMapUISurvive();
	~CCopyMapUISurvive();

	virtual bool			onInit();
	virtual void			onClose();

	virtual void			UpdateCopyInitInfo(pk::GS2C_CopyInitInfo* value);
	virtual void			BeforeActive();
	virtual void			OnActive();

	//��������ʱ
	virtual void			StartSurviveSeconds(int nSeconds);
	//��������ʱ
	virtual void			EndSurviveSeconds();
	//����ʱˢ��
	virtual void			ScheduleSurviveSeconds(float dt);

	void					updateLivePoint(pk::GS2C_LivePoint* value);

private:
	Text*	m_pAttentionValue;
	Layout* m_pAttentionFrame;
	Widget* m_pAttentionBar;
	Widget* m_pAttention;
	Text*   m_pSurviveSeconds;
	Text*   m_pSurviveSecondsTitle;
	int		m_nSurviveSeconds;
};