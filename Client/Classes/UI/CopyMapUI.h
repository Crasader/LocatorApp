/* 
	����UI
	������
	2015-09-02
*/
#pragma once
#include "cocos2d.h"
#include "GameUI.h"
#include "Net/pk_map.h"

class CCopyMapUI:public GameUI
{
public:
	CCopyMapUI(int idu,const std::string& strJsonFile);
	~CCopyMapUI();

	virtual void			onClose();

	//������ʼ��
	virtual void			UpdateCopyInitInfo(pk::GS2C_CopyInitInfo* value);
	//�����������
	virtual void			UpdateCopyProgress(pk::GS2C_UpdateCopyProgress* value);
	//����С�ڣ��������������Ƿ񼤻�
	virtual void			updateMonsterWave(pk::GS2C_MonsterSpawnRemind* value);
	//�뿪����ʱ
	virtual void			UpdateCountTime(pk::GS2C_COPY_SUCC_TIME* value);

	//����ǰ�ص�
	virtual void			BeforeActive() {};
	//�����ص�
	virtual void			OnActive() {};

	//����Ŀ����
	virtual void			SetGoalNum(int nGoalNum);
	//��ǰĿ����
	virtual void			SetCurNum(int nCurNum);
	//��ǰС����
	virtual void			SetWaveIdx(int nWaveIdx);

	//��������ʱ
	virtual void			StartCountSeconds(int nSeconds);
	//��������ʱ
	virtual void			EndCountSeconds();
	//����ʱˢ��
	virtual void			ScheduleCountSeconds(float dt);

	inline Copy_stepCfg*	GetStepDataCfg() { return m_pStepDataCfg; }
	inline MapCfg*			GetMapDataCfg() { return m_pMapDataCfg; }
public:
	static	void			OpenCopyMapUI();
	static	void			CloseCopyMapUI();

private:
	void					CheckIfShowIndicator();

protected:
	Copy_stepCfg*		m_pStepDataCfg;
	MapCfg*				m_pMapDataCfg;

	Text*				m_pGoalTitle;
	Text*				m_pCurTitle;
	Text*				m_pCountSecondsTitle;

	Text*				m_pWaveIdx;
	Text*				m_pGoalNum;
	Text*				m_pCurNum;
	Text*				m_pCountSeconds;

	int					m_nWaveIdx;
	int					m_nGoalNum;
	int					m_nCurNum;
	int					m_nCountSeconds;

	bool				m_bActive;
};