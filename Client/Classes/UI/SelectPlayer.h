#pragma once
#include "GameDef.h"
#include "GameUI.h"
#include "Net/pk_nonInGame.h"
#include "CustomCtrl/ScrollTable.h"
#include "CustomCtrl/TuoYuanAction.h"
#include "RoleModel.h"
#include "CustomCtrl/RichTextEX.h"

#define Max_Player_Num			(3)

class CSelectPlayer : public GameUI
{
public:
	CSelectPlayer();
	~CSelectPlayer();

	bool			onInit();
	void			onClose();
	void			onOpen();
	void			Show(vector<pk::UserPlayerData>& player_list);

	void			deletePlayer(bool bDel);

	/**
	 * Name : selectPlayer
	 * Des  : ѡ��ʹ���Ӣ��
	 * Param: tag Ӣ�۰�ť�±�
	 */

	void			selectPlayer(int tag);

	/**
	 * Name : setHeroImage
	 * Des  : ���ý�ɫ��ť�ͽ�ɫ����ʾͼƬ
	 * Param: _type Ӣ������
	 *        pPtr  ����ָ��
	 *        ptrType 0 Ϊ��ť 1ΪͼƬ
	 */
	template <typename T>
	void            setHeroImage(pk::UserPlayerData _type, const T& pPtr, int ptrType = 0);


	/**
	 * Name ��isExitHero
	 * Des  : ����Ƿ���Ӣ��
	 * Param: _idx ��ť���±�ֵ
	 * Ret  : ��true 
	 */
	bool            isExitHero(int _idx);

	/**
	 * Name : showFace
	 * Des  : ѡ��ť��,�ı�������ʾ
	 * Param: _idx ��ť���±�ֵ
	 */
	void            showFace(int _idx);

	/**
	 * Name : clickCallBack
	 * Des  : ��ťʱ��ص�
	 */
	void            clickCallBack(Ref* pSender, TouchEventType type);

	CREATE_FUNC(CSelectPlayer);

private:
	vector<pk::UserPlayerData>		m_players;
	lrTuoyuanConfig					m_tuoyuancfg;

	RoleModel*			m_roleModels[Max_Player_Num];
	Widget*				m_playerContainer[Max_Player_Num];
	RichTextEx*			m_playerName[Max_Player_Num];

	Button*             m_pButton[5];                         //���水ť
	int                 m_curIndex;                           //��ǰѡ��İ�ť�±�
	float               m_pos;                                //Ӣ�۰�ťĬ��λ��
};