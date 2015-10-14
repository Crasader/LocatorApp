/***
 * ģ�飺����������
 * ���ߣ�sndy
 * ʱ�䣺2015-07-22
 * ˵����ѡ���¼������
 */

#pragma once
#include "GameDef.h"
#include "GameUI.h"
#include "Net/pk_betweenClientLs.h"
#include "CustomCtrl/RadioButtonSet.h"

#define		Region_Server_Size		(12)
#define     AreaServer_Size          8

//��������ǰ��״̬����
enum ServerAreaType
{
	Recommendation_Type = 0,         //�Ƽ�
	Hot_Type            = 1,         //��
	Full_Type           = 10,        //����
	Defend_Type         = 100,       //ά��
	Close_Type          = 1000,      //�ر�
	Test_Type           = 10000,     //����
	NewArea_Type,                    //�·�
};

typedef vector<pk::GameServerInfo> ServerInfoList;
typedef map<int, ServerInfoList>   ServerInfoMap;

class CServerList : public GameUI
{
public:


	CServerList();
	~CServerList();

	/******************************************************************/
	void			clickEnterServer(Ref* pSender, TouchEventType type);
	void			clickBack(Ref* pSender, TouchEventType type);
	void			clickRegionItem(int nIndex);
	void			ShowRecommond();
	void			clickServerItem(Ref*, TouchEventType);
	/******************************************************************/

	bool			onInit();
	void			onClose();
	void			onOpen();
	void			Show(int regionCnt,vector<pk::GameServerInfo>& gameServers);
	void            onEnter();
	void            onExit();



	/**
	 * Name : setCurAreaSelectServ
	 * Des  : ���õ�ǰ����ѡ��ķ�����
	 * Param: _status    ״̬���� 
	 *        _serverid  ��������
	 *        _name      ��������
	 */
	void            setCurAreaSelectServ(ServerAreaType _status, int _serverid, const char * _name);

	/**
	 * Name : setStatus
	 * Des  : ���÷�������״̬ͼ
	 * Param: _status    ״̬����
	 *        _type      0 ��ͼƬ 1���ı�
	 *        pPtr       ����ָ��
	 */
	template  <typename T>
	void            setStatus(ServerAreaType _status, const T& pPtr,int _type = 0);

   /**
	 * Name : setCurAreaSelectServ
	 * Des  : ���÷���������ʾ
	 * Param: _status    ״̬���� 
	 *        _serverid  ��������
	 *        _name      ��������
	 *        _idx       ��ǰ��������
	 */
	void            setServerShow(ServerAreaType _status, int _serverid, const char * _name, int _idx);


	/**
	 * Name : changAreaBtnStatusByIdx
	 * Des  : �����±��������ť��״̬��ɫ
	 * Param: _idx ����ťid
	 */
	void            changAreaBtnStatusByIdx(int _idx);


	/**
	 * Name : setAreaListBtn
	 * Des  : ���õ�ǰ������ʾ,����Ӵ����¼�
	 * Param: _cnt�������
	 */
	void            setAreaListBtn(int _cnt);

	/**
	 * Name : setCurAreaShow
	 * Des  : ���õ�ǰѡ������ķ������б�
	 * Param: _areaid
	 */
	void           setCurAreaShow(int _areaid);


	/**
	 * Name : showAreaServerList
	 * Des  : ��ʾ��ǰѡ�������������б�
	 * Param: _id ����id  
	 */
	void      showAreaServerList(int _id);


	/**
	 * Name : setDefaultShow
	 * Des  : ����Ĭ����ʾ
	 */
	void      setDefaultShow();

	/**
	 * Name : getLastServerList
	 * Des  : ��ȡ�����¼�������б�
	 */
	std::vector<int> getLastServerList();


	/**
	 * Name : saveLastServerList
	 * Des  : ���������¼�ķ�����
	 */
	void           saveLastServerLsit();

	/**
	 * Name : findServerById
	 * Des  : ����������id���ҷ�������Ϣ
	 * Param: _id  ������id
	 * Ret  : pk::GameServerInfo ��������Ϣ
	 *        ���������idΪ-1
	 */
	pk::GameServerInfo findServerById(int _id);


	/**
	 * Name : findServerByName
	 * Des  : ����������Name���ҷ�������Ϣ
	 * Param: _name  ������name
	 * Ret  : pk::GameServerInfo ��������Ϣ
	 *        ���������idΪ-1
	 */
	pk::GameServerInfo findServerByName(const char* _name);


	/**
	 * Name : findServerByAreaName
	 * Des  : �������Name���ҷ�������Ϣ
	 * Param: _name  ����name
	 * Ret  : ����������б���Ϣ
	 */
	ServerInfoList findServerByAreaName(const char* _name);

	/**
	 * Name : callBackFunc
	 * Des  : ����İ�ť�ص�
	 */
	void            callBackFunc(Ref* pSender, TouchEventType type);

	/**
	 * Name : areaCallBack
	 * Des  : ����ť�ص�
	 */
	void            areaCallBack(Ref* pSender, TouchEventType type);

	/**
	 * Name : areaCallBack
	 * Des  : ��������ť�ص�
	 */
	void            serverCallBack(Ref* pSender, TouchEventType type);

	CREATE_FUNC(CServerList);

private:
	//sndy param
	Widget*             m_panelServer;                             //������ѡ�������
	Button*             m_areaServerBtn[AreaServer_Size];          //���������ѡ��ť
	Text*               m_text[3];                                 //��ǰѡ���������������ı�
	ImageView*          m_serverStatus;                            //��ǰѡ��������������״̬��־ָ��
	ListView*           m_serverList;                              //����ķ���������ָ��
	std::vector<int>    m_lastServerList;                          //�����¼�ķ������б�
	ServerInfoList      m_gameServers;                             //�������б�
	ServerInfoMap       m_gameAreaServers;                         //����������б�
	int                 m_curAreaIndex;                            //��ǰѡ�������id
	pk::GameServerInfo  m_curServerInfo;                           //��ǰѡ��ķ�����
};