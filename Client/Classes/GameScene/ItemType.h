#ifndef __ItemType_h_
#define __ItemType_h_

#include "GameDef.h"

// ������Ͷ���
enum MoneyType
{
	MoneyType_Coin,		// ���
	MoneyType_BindCoin,	// �󶨽��
	MoneyType_Gold,			// Ԫ��
	MoneyType_BindGold,		// ��Ԫ��
};

// ��Ʒ���Ͷ���
enum ItemType
{
	ItemType_None = 0,
	ItemType_Equip,				// װ��
	ItemType_Others,			// ����
	ItemType_Material,			// ����
	ItemType_DrawingSheet,		// ͼֽ
	ItemType_SkyBook,			// ����
	ItemType_GodDevice,			// �������·���
};

enum EquipType
{
	EquipType_Weapon = 1,		// ����
	EquipType_MagicCimelia,		// ����
};

// ��Ʒ�����Ͷ���
enum ItemSubType
{
	//��Ʒ�����ͣ�
	//װ�������ͣ�
	//0 ��

	//ͼֽ������
	SubType_TUZHI_WEAPON = 1, //1 ����
	SubType_TUZHI_RELIC,      //2 ����
	SubType_TUZHI_AROMR,      //3 ����
	SubType_TUZHI_PET,        //4 ����
	SubType_TUZHI_MATERIAL,   //5 ����
	SubType_TUZHI_OTHER,      //6 ����


	//����������
	//0 ��

	//����������
	//����Ƕλ������дA������дB
	SubType_TIANSHU_WUJI = 1, //1 �似���飬��Ƕ�����������λ
	SubType_TIANSHU_WEAPON,   //2 ������ͨ���飬��Ƕ������һ���λ
	SubType_TIANSHU_HALO,     //3 �⻷���飬��Ƕ�����������λ
	SubType_TIANSHU_RELIC,    //4 ������ͨ���飬��Ƕ������һ���λ
	SubType_TIANSHU_MATERIAL, //5 �������飬������Ƕ��ֻ����Ϊ�����ò���
	SubType_TIANSHU_PET,      //6 �������飬��Ƕ�ڳ���һ���λ

	//����������
	SubType_ZAWU_REWARD = 1,  //1 ���
	SubType_ZAWU_XUQIU,       //2 Ѫ��
	SubType_ZAWU_FAQIU,       //3 ����
	SubType_ZAWU_COIN,        //4 �����ڵ���Ľ�ң���ֱ��ʰȡ
};

// װ�������� 6��
enum EquipColumnType
{
	EquipColumn_GodDevice,			// �������·���
	EquipColumn_Weapon,				// ����
	EquipColumn_MagicCimelia0,		// ����1
	EquipColumn_MagicCimelia1,		// ����2
	EquipColumn_MagicCimelia2,		// ����3
	EquipColumn_MagicCimelia3,		// ����4
	EquipColumn_MagicCimeliaMax,	// 
	EquipColumn_Max
};

//��ƷƷ��
enum ItemQualityType
{
	ItemQuality_None,
	ItemQuality_Green,
	ItemQuality_Blue,
	ItemQuality_Orange
};

#endif //__ItemType_h_