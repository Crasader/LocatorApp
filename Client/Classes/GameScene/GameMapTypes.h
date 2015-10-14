/***
 * ģ�飺��Ϸ��ͼ��ض���
 * ���ߣ�������
 * ʱ�䣺2015-07-2
 * ˵������Ϸ��ͼ���Ͷ���
 */

#ifndef __GameMapTypes_h_
#define __GameMapTypes_h_

#include "StringDef.h"

typedef enum _gameMapPlayType
{
	GameMapPlayType_None,		// 0 ������
	GameMapPlayType_Def,		// 1 ����
	GameMapPlayType_Kill,		// 2 ����
	GameMapPlayType_Catch,		// 3 ����
	GameMapPlayType_Destroy,	// 4 �ƻ�
	GameMapPlayType_XB,			// 5 Ѱ��
	GameMapPlayType_Save,		// 6 Ӫ��
	GameMapPlayType_Survive,	// 7 ����
	GameMapPlayType_ContendFor,	// 8 ����
	GameMapPlayType_FreeFight = 20,			// 20 ����ս��
	GameMapPlayType_Count,
}GameMapPlayType;

enum GameMapFuncType
{
	GameMapFuncType_Normal,	// 0 �����ͼ
	GameMapFuncType_Fight,	// 1 ս����ͼ
};

enum GameMapType
{
	GameMapType_None,				
	GameMapType_Open,				// 1 ���ŵ�ͼ
	GameMapType_MultiPlayers,		// 1 ���˸�����ͼ
	GameMapType_SiglePlayer,		// 1 ���˸�����ͼ
};

enum GameMapTaskType
{
	GameMapTaskType_None,	// 0 ��
	GameMapTaskType_PT,		// 1 ��ͨ
	GameMapTaskType_XS,		// 2 ����
	GameMapTaskType_EM,		// 3 ج��
	GameMapTaskType_CT,		// 4 ��ͻ
};

enum GameMapEnemyType
{
	GameMapEnemyType_None,	// 0 ��
	GameMapEnemyType_YG,	// 1 ����
	GameMapEnemyType_SZ,	// 2 ˮ��
	GameMapEnemyType_YG_SZ	// 3 ����vsˮ��
};

#endif