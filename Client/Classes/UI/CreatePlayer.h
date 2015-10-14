#pragma once
#include "GameDef.h"
#include "GameUI.h"
#include "CustomCtrl/RadioButtonSet.h"
#include "RoleModel.h"

RoleModel* createModelByPlayer(int career, int sex);

class CCreatePlayer : public GameUI
{
public:
	CCreatePlayer();
	~CCreatePlayer();

	bool			onInit();
	void			onOpen();

	void			SetRandomName();
	void			ShowCareerModel();

	void			update(float dt);

	void			clickCareerSel(int index);
	void			clickSexSel(int index);
	void			clickRandom(Ref* pSender, TouchEventType type);
	void			clickCreate(Ref* pSender, TouchEventType type);
	void			clickBack(Ref* pSender, TouchEventType type);
	void			clickMale(Ref* pSender, TouchEventType type);
	void			clickFemale(Ref* pSender, TouchEventType type);

	void            onEnter();

	void            onExit();

	/**
	 * Name : showFace
	 * Des  : �ı������ʾ
	 */
	void           showFace();

	/**
	 * Name : setHeroImag
	 * Des  : ����Ӣ����ʾͼƬ
	 * Param: _career  ְҵ
	 *        _sex     �Ա� 1Ĭ��������
	 */
	void            setHeroImag(int _career, int _sex = 1);


	/**
	 * Name : clickCallBack
	 * Des  : ���水ť�ص�����
	 */
	void            clickCallBack(Ref* pSender, TouchEventType type);


	/**
	 * Name : clickListHero
	 * Des  : ���listӢ�ۻص�����
	 */
	void            clickListHero(Ref* pSender, TouchEventType type);

	CREATE_FUNC(CCreatePlayer);

private:
	int				m_career;
	int				m_sex;
	TextField*		m_pName;


	string			m_name;
	RadioButtonSet*	m_pCareerSel;
	RadioButtonSet*	m_pSexSel;
	CheckBox*		m_pMaleBtn;
	CheckBox*		m_pFemaleBtn;
	CheckBox*		m_pCareerZS;
	CheckBox*		m_pCareerFS;
	CheckBox*		m_pCareerGJ;
	ImageView*		m_pCareerTxt[3];
	ImageView*		m_pPower[3];
	Text*			m_pPowerTxt;

	Point			m_pZSPos;
	Point			m_pFSPos;
	Point			m_pGJPos;

	RoleModel*		m_pModel;
};