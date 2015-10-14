#pragma once
#include "GameDef.h"
#include "GameScene/db.h"
#include "UI/GameUIDef.h"
#include "GameScene/ItemType.h"
#include "UI/CocosUI.h"

//��ȡְҵicon·��
string GetCareerIcon(int nCareer);
//��ȡ�����ͼְҵicon·��
string GetWorldMapCareerIcon(int nCareer);
//��ȡ��Ա����icon·��
string GetTeamIconDead(int nCareer);
//��ȡ��Ա���ŵ�icon·��
string GetTeamIconAlive(int nCareer);

/*��ȡƷ��color*/
Color3B GetQualityColor(ItemQualityType quality);
string GetQualityImgPath(ItemQualityType type);
string GetQualityDesc(ItemQualityType type);

string GetBagTypeDes(int type);

/****************************װ��ͨ�� start ************************************/
/*��ȡְҵ����*/
string GetCareerDes(int career);

/****************************װ��ͨ�� end ************************************/

/*��ȡĬ�ϼ��������*/
int GetDefaultActiveGrids(emGridsType type);

string GetAtkTypeDes(int type);

int getPageNum(int itemCount,int numsOfPage=BAG_PAGE_SIZE);

class CCommonUI
{
public:
	CCommonUI();
	~CCommonUI();

	static Point getWorldPosition(Widget* pWidget);

	/*�������ǩ*/
	static void changeToLeftLabel(Widget* pWidget);

private:

};