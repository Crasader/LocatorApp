#pragma once

#include "GameDef.h"
#include "UI/GameUIDef.h"
#include "GameScene/ItemType.h"
#include "DragCtrol.h"
#include "UI/CocosUI.h"

class CItem;

typedef bool (Ref::*IconClickEvent)(class CGridIcon* pIcon);
#define iconclickeventselector(_SELECTOR) (IconClickEvent)(&_SELECTOR)

class CGridIcon : public ImageView
{
	typedef enum
	{
		part_order_quality = 1,
		part_order_icon,
		part_order_mask,
		part_order_num,
		part_order_lock,
		part_order_cd
	}IconPartOrder;

	typedef enum
	{
		part_num,    //����
		part_name,   //����
		part_level,  //�ȼ�
		part_precent //����
	}BookPart;

public:
	CGridIcon();
	~CGridIcon();

	/* pos:��Ʒ�ڸ����е�λ�� */
    static CGridIcon*	create(CItem* pItem, int pos, emGridsType gridsType,bool bCanMove=false);

public:
	bool				init(CItem* pItem, int pos, emGridsType gridsType,bool bCanMove);

	//��ʼ������ Tangbo
	bool				initBook(CItem* pItem, int pos, emGridsType gridsType,bool bCanMove);
	//��ʾ�ȼ�   Tangbo
	//_point     ���ڵ�İٷ�λ��
	void                ShowLevel(Point _point = Point(0.8f, 0.2f));
	//��ʾ��ǰ���� Tangbo
	//_point     ���ڵ�İٷ�λ��
	void                ShowPrecentBar(Point _point = Point(0.5f, 0.2f));
	//��ʾ��ǰ�������� Tangbo
	//_point     ���ڵ�İٷ�λ��
	void                ShowName(Point _point = Point(0.2f, 0.8f));
	//��ʾ����ֵ Tangbo
	//_point     ���ڵ�İٷ�λ��
	void                ShowPrecent(Point _point = Point(0.5f, 0.2f));

	//�õ���ǰƷ���������ɫ,ֻ���������ʹ�� Tangbo
	Color3B             getNameColor(BookPart part);

	//�õ���ǰƷ������������ɫ,ֻ���������ʹ�� Tangbo
	Color4B             getLineColor(BookPart part);

	//�����Ƿ���ʾ����
	inline void         setShowNum(bool val){ if(m_pItemNum)m_pItemNum->setVisible(val);}

	void				updateByContent();
	inline void			SetItem(CItem* pItem)				{ m_pItem = pItem; }
	inline CItem*		GetItem()							{ return m_pItem; }
	inline void			SetQuickcutIcon(bool isQuickcut)	{ m_bIsQuickcut = isQuickcut; }

	void				ShowQuality();
	void				ShowIcon();
	string              getIconPath();
	void				ShowMask();
	void				ShowNum();
	void				ShowLock();
	void				ShowCd();
	void				RemoveCd();

	bool				CheckUseAble();
	bool				IfShowNum();

	inline void			SetTipsBtnBright(bool bBright)	{ m_bSetTipsBtnBright=bBright; }
	inline bool			GetTipsBtnBright()				{ return m_bSetTipsBtnBright; }
	inline int			GetIndex()						{ return m_GridPos; }

	/*�ֶ���ʾmask*/
	void				ShowMaskManual(bool bShow);

	void				clickGridIcon(Ref *pSender, TouchEventType type);
	void				AddIconClickEvent(Ref* pSender, IconClickEvent event) { m_clickEventListener=pSender; m_clickEventSelector=event; }

protected:
	CItem*					m_pItem;
	emGridsType				m_GridsType;
	int						m_GridPos;

	ImageView*				m_pQuality;
	ImageView*				m_pIcon;
	ImageView*				m_pMask;
	Text*					m_pItemNum;
	ImageView*				m_pLock;

	//add   Tangbo
	string                  m_sIconPath;
	Text*                   m_pName;
	Text*                   m_pLevel;
	Text*                   m_pPercent;
	LoadingBar*             m_pLoadingBar;


	bool					m_bSetTipsBtnBright;
	bool					m_bIsQuickcut;			//���ͼ�� tips����Ҫ������ť
	bool					m_bCanMove;

	Ref*					m_clickEventListener;
	IconClickEvent			m_clickEventSelector;
private:

};