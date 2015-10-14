/****************************************************************************
 ս����ͣUI
 ������
 2015-07-29
 ****************************************************************************/
#pragma once

#include "GameDef.h"
#include "GameUI.h"

class CFightPause : public GameUI
{
public:
	CFightPause();
	~CFightPause();

	bool					onInit();

private:
	//����¼�����
	void					ClickBack(Ref *pSender, TouchEventType type);
	void					ClickLeave(Ref *pSender, TouchEventType type);
	void					ClickMusic(Ref*,CheckBoxEventType);
	void					ClickEffect(Ref*,CheckBoxEventType);
};