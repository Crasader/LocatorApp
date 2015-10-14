/*
 * ģ�飺������澲̬����
 * ���ߣ�TangBo
 * ʱ�䣺2015/8/11
 */

#pragma once

#include <vector>
#include "../Net/pk_friend.h"
#include "../Net/pk_item.h"
#include "Singleton.h"
#include "GameScene/Hero.h"
#include "UIData/CMatchMachine.h"
#include "Net/pk_map.h"
#include "UIData/CCopyDataMgr.h"
#include "UIData/Legion.h"
#include "UIData/ChatData.h"

using namespace std;


struct RecentlyPlayerData_st
{
	RecentlyPlayerData_st()
	{
		playerid = 0;
		name = "";
		level = 0;
	}
	int64       playerid;      //���id
	string      name;          //�������
	int         level;         //��ҵȼ�
};

static  int  fasttime = 30;    //����ʹ�ü��ٺ����ʱ��

struct ManufactureData_st
{
	ManufactureData_st(){
		leftTime = 0;
		startTime = 0;
		productTime = 0;
		baseGold = 0;
		minGold = 0;
		curGold = 0;
		icon = "";
		iconname = "";
		targetname = "";
		percent = 0;
	}
	pk::Manufacture_Element   serverData;
	int   leftTime;           //ʣ��ʱ��(��)
	long  startTime;          //���ؿ�ʼʱ�䣨�룩
	int   productTime;        //����ʱ��(��)
	int   baseGold;           //��������שʯ
	int   minGold;            //��С����שʯ
	int   curGold;            //��ǰ����שʯ
	int   percent;            //��������ֵ
	string  icon;             //ͼֽicon
	string  iconname;         //ͼֽ����
	string  targetname;       //Ŀ������
};


typedef  map<int64, RecentlyPlayerData_st*>  RecentPlayerData_m;
typedef  vector<pk::Friend_Info>     FriendInfo_v;
typedef  vector<pk::Mail_Info>		 MailInfo_v;
typedef  vector<ManufactureData_st*> ManufactureData_v;

class DataPool_cl : public Singleton_Auto<DataPool_cl>
{
public:
	DataPool_cl();
	~DataPool_cl();

	/*************************************************************************
					            �����ӿ�
	*************************************************************************/
	/*
	 * Name  :destoryData
	 * Des   :��������
	 * Author:Tangbo
	 */
	void                     destoryData();

	//��ʼ������
	void                     initData();

	//��������,ÿ֡����
	void					Update(float dt);


	/*************************************************************************
					            ����ϵͳ�ӿ�
	*************************************************************************/

	//��ָ���������Ƿ���ڴ���� Tangbo
	bool                    isExistPlayer(FriendInfo_v &_Tlist, int64 _id);

	//����ptr��������������
	void                    setPListDataByPtr(FriendInfo_v &_Tlist, pk::Friend_Info* _Ptr);


	//����ptrɾ������������ Tangbo
	void                    deletePListDataByPtr(FriendInfo_v &_Tlist, pk::Friend_Info* _Ptr);

	//����IDɾ������������  Tangbo
	void                    deletePListDataByID(FriendInfo_v& _Tlist, int64 _id);

	//������б���������
	void                    addPlayerToRecentList(pk::Friend_Info* _ptr);

	//��ȡ������ָ�������Ϣ  Tangbo
	pk::Friend_Info*        getFriendPlayerInfo( int64 _id);

	//��ȡ������ָ�������Ϣ  Tangbo
	pk::Friend_Info*        getRelativePlayerInfo( int64 _id);

	//���ֺ��Ѻͺ���������  Tangbo
	void                    sapratePDataList(FriendInfo_v& _list);

	//�õ������б�  Tangbo
	FriendInfo_v &getFriendList() { return m_friendlist;}


	//�õ��������б� Tangbo
	FriendInfo_v &getBlackList() { return m_blacklist;}


	 //�õ�����б� Tangbo
	FriendInfo_v &getRelativeList() { return m_relativelist;}

	RecentPlayerData_m & getRelativeMapData(){return m_relativeDate;};


	 //��������б�����      Tangbo
	void                     setRelativeList(FriendInfo_v& _Tlist);


	//��ȡ��������б�����   Tangbo
	void                     initRelativeData();

	//��������б��������� Tangbo
	void                     saveRelativeDate();

	//����ʱ����������  Tangbo
	void                     sortPlayerByOnline(FriendInfo_v &_Tlist);




	/*************************************************************************
					            �ʼ�ϵͳ�ӿ�
	*************************************************************************/
	//�ӷ�������ȡ�ʼ��б�	 ashin
	void					 setMailList(MailInfo_v& _list);

	//�õ��ʼ��б�			 ashin
	MailInfo_v&				 getMailList() { return m_maillist;}
	
	//ͨ��ID�õ��ʼ�		 ashin
	pk::Mail_Info*			 getMailByID(int64 _id);

	//ͨ��IDɾ���ʼ�		 ashin
	void					 deleteMailByID(int64 _id);
	
	//ͨ��ID�����ʼ�״̬     ashin
	void					 setMailStateByID(int64 _id,int _state);

	//����һ���ʼ�
	void					 addMailToList(pk::Mail_Info _mail);

	/*************************************************************************
					            ����ƥ��
	*************************************************************************/

	//ƥ���Ƿ�����---������
	CMatchMachine*			GetMatchMachine() { return &m_matchMachine; }

	/*************************************************************************
					            �������ݹ�����
	*************************************************************************/
	CCopyDataMgr*			GetCopyDataMgr() { return &m_copyDataMgr; }
	
	/*************************************************************************
					            ����ϵͳ�ӿ�
	*************************************************************************/
	enum SignBook
	{
		SignBook_InlayedBook,
		SignBook_RelicBook,
		SignBook_WeaponBook,
		SignBook_PetBook,
		SignBook_MaterialBook,
		SingBook_All,
		SignBook_Max,
	};

	//���鵯��������ʾ����
	struct ShowConditions_st
	{
		ShowConditions_st(){
			_type  = SignBook_Max;
			IsSubType = false;
			IsShowUp = false;
			IsCurUse = false;
			IsCurInlay = false;
			IsOtherInlay = false;
			exp = false;
		}

		SignBook _type;        //��ǰҪ��ʾ������
		// ����false��ʾ���ж�Ҫ��ʾ Ĭ�϶�Ҫ��ʾ  true����ʾҪ�ж� 
		bool IsSubType;        //�Ƿ��ж�������
		bool IsShowUp;         //�Ƿ���ʾ��������
		bool IsCurUse;         //��ǰ��λ�Ƿ�ʹ��
		bool IsCurInlay;       //��ǰ�Ƿ���Ƕ
		bool IsOtherInlay;     //�����Ƿ���Ƕ
		bool exp;              //�Ƿ�exp�Ƿ����0
	};

	//�жϵ�ǰ�����Ƿ�ǰ����
	bool judgeType(CItem* item, SignBook _type);
	
	//�����鱳����������� 
	CItemGridArray*          saparateDataFromBag(ShowConditions_st st);

	//��ȡ��ɫ��ǰװ��������itemgridָ��
	CItem*                   getHeroWeapon();

	//��ȡ��ǰװ����������Ƕ�����б�
	const vector<pk::EquipTianshu>& getCurRelicConfig();

	//��ȡ��ǰװ����������Ƕ�����б�
	const vector<pk::EquipTianshu>& getCurWeaponConfig();

	//��ȡ��ǰװ���������Ƕ�����б�
	const vector<pk::EquipTianshu>& getCurPetConfig();

	/*************************************************************************
					            ����ϵͳ����
	*************************************************************************/

	//��ʼ������ϵͳ����
	void  initManuFactureList(pk::GS2C_ManufactureList_Ret* value);

	//����һ����������
	void  addManuFactureData(pk::GS2C_New_Manufacture_Element_Ret* value);

	//����cdʱ����������
	void  cancelManuFactureCD(pk::GS2C_Eliminate_Cd_Ret* value);

	//ɾ��һ����������
	void  removeManuFactureData(int dataid);

	//��ȡ�����������б�
	inline ManufactureData_v& getManufactureData(){return m_vManuFactureList;}


	/*************************************************************************
					            ����ϵͳ����
	*************************************************************************/

	Legion_cl* getLegionData(){return m_pLegionData;}

	/*************************************************************************
					            �������ݹ�����
	*************************************************************************/

	CChatDataMgr* GetChatDataMgr(){return &m_chatDataMgr;}  

private:

	FriendInfo_v            m_friendlist;                         //�����б�

	FriendInfo_v            m_blacklist;                          //�������б�

	FriendInfo_v            m_relativelist;                       //����б�

	RecentPlayerData_m      m_relativeDate;                       //����б�����

	MailInfo_v              m_maillist;                           //�ʼ��б�

	CMatchMachine			m_matchMachine;						  //ƥ��״̬��

	CCopyDataMgr			m_copyDataMgr;						  //�������ݹ�����

	CItemGridArray*         m_pSignBook[SignBook_Max];            //�����ҳ��ǩ

	ManufactureData_v       m_vManuFactureList;                   //�������������

	Legion_cl*              m_pLegionData;                        //��������

	CChatDataMgr			m_chatDataMgr;						  //�������ݹ�����
};

#define  gDataPool          DataPool_cl::Instance()

#define  gMacthMachine		gDataPool->GetMatchMachine()			//ƥ������
#define  gCopyDataMgr		gDataPool->GetCopyDataMgr()				//��������	
#define  gChatDataMgr		gDataPool->GetChatDataMgr()				//��������		