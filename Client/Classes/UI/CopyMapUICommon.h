/* 
	����ͨ��UI
	������
	2015-09-02
*/
#pragma once
#include "cocos2d.h"
#include "GameUI.h"
#include "CopyMapUI.h"

//ͨ�ø��� (����,�ƻ�,����,Ѱ��,Ӫ��)
class CCopyMapCommon:public CCopyMapUI
{
public:
	CCopyMapCommon();
	~CCopyMapCommon();

	virtual bool onInit();
	virtual void onOpen();
};