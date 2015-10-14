/*
 * ģ�飺������������,�����滻cocos�༭�Ļ�����
 * ���ߣ�Tangbo
 * ʱ�䣺2015/8/20
 */
#pragma  once

#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"
#include "UIScrollView.h"
#include "UI/GameUIDef.h"
#include "../../Net/pk_trade.h"
#include "GridIcon.h"
#include "Net/pk_item.h"
#include "GameScene/ItemGrid.h"

USING_NS_CC;
using namespace cocos2d::ui;

struct GridIcon_st
{
	GridIcon_st(){
		gridIcon = nullptr;
		bgIcon   = nullptr;
	}
	CGridIcon *   gridIcon;          //����ͼ��
	Widget    *   bgIcon;            //����ͼ��

};

//�����¼�
enum ItemTouchEvent
{
	LONG_TOUCH_EVENT,               //�����¼�
	ONE_TOUCH_EVENT,                //�����¼�
	DOUBLE_TOUCH_EVENT,             //˫���¼�

	ITEMEVENT_MAX,
};

struct EquipNode_st
{
	EquipNode_st()
	{
		equipnode = nullptr;
		rect = Rect::ZERO;
	}
	Widget*         equipnode;       //װ���ڵ�
	Rect            rect;            //����
};

struct SelectItem_st
{
	pk::C2GS_NpcShopSell sell;
	int                  index;
};

typedef  vector<SelectItem_st>  Sale_V;                     //������������
typedef  vector<GridIcon_st>           ItemIcon_V;          //������ʾ����
typedef  vector<EquipNode_st>          EquipNode_V;
typedef  std::function<void(CItem*)>   funct_s;

class ScrollGrids_cl:public ScrollView
{
public:

	//��ʼ��
	/* Param: _gridType     ��������
	          _totalGrid    ������������
			  _lineGrid     ���뻬����һ�еĸ�����
			  _scroll       ����Ҫ�滻�Ļ�����
			  _parent       ��ڵ㣬����Ĭ��_scroll�ĸ��ڵ�
			  _limit        �Ƿ����ƴ�С
	*/
	bool init(emGridsType _gridType, int _totalGrid, int _lineGrid, ScrollView* &_scroll, Node * _parent, bool _limit);

	//�����µĻ�����,�滻�������  ����ʼ������
	/* Param: _gridType     ��������
	          _totalGrid    ������������
			  _lineGrid     ���뻬����һ�еĸ�����
			  _scroll       ����Ҫ�滻�Ļ�����
			  _parent       ��ڵ�,����Ĭ��_scroll�ĸ��ڵ�
			  _times        �Ƿ����ƴ�С Ĭ��������
	*/
	static ScrollGrids_cl* create(emGridsType _gridType, int _totalGrid, int _lineGrid, ScrollView* &_scroll, Node * _parent = nullptr, bool _limit = true);

	//�����µĻ�����,�滻�������  ����ʼ������
	/* Param: _gridType     ��������
	          _totalGrid    ������������
			  _lineGrid     ���뻬����һ�еĸ�����
			  _scroll       ����Ҫ�滻�Ļ�����
			  _parent       ��ڵ�,����Ĭ��_scroll�ĸ��ڵ�
			  _times        �Ƿ����ƴ�С Ĭ��������
	*/
	static ScrollGrids_cl* createWithOutData(emGridsType _gridType, int _totalGrid, int _lineGrid, ScrollView* &_scroll, Node * _parent = nullptr, bool _limit = true);

	//��ʼ��������ڵ㴴������
	void    initCreateData();

	//���ý���
	void   reset();

	//���ݴ���ֵ��ʼ���ý���  ɾ������
	void   resetByData(CItemGridArray* pGridsData);

	//���ݴ���ֵ��ʼ���ý��� ��ɾ������
	void   resetData(CItemGridArray* pGridsData);

	inline int	  getSelectIndex(){ return m_selectIndex; }


	//����˫��ʱ�����
	void   updateTime(float fd);

	//ɾ��ĳ������
	void   removeItemByIndex(int index);

	//����ĳ������
	void   addItemByIndex(int index);


	//����
	void   saleSelectItem();

	//����
	void   cleanBag();

	//����������Ƿ��������߷�������
	void   delwithItem(int _itemId);

	//���ӵ���¼��ص�
	void   clickGrid(Ref * _ref, TouchEventType _type);

	//˫���¼�
	void   doubleEvent();


	//��Ӵ���װ������
	void   addAreaEquip(EquipNode_V & _vec);
	void   addAreaEquip(Widget* _widget);

	//����Ƿ��ཻ
	void   checkIntersectsRect();

	//ע���¼�
	void   registerFunc(funct_s _func, ItemTouchEvent _event);

	//�õ��ڵ���
	const int    getChildrenCount(){return m_childrenCnt;}

	//��Ը������Խ���װ����,����������ˢ��
	void         freshRoleEquip(pk::GS2C_EquipExchangeRet* value);

	void	packupSelectEquip(int _cnt);

protected:
	ScrollGrids_cl();
	~ScrollGrids_cl();

	//��������
	CC_SYNTHESIZE_READONLY(int, m_totalPrice, TotalPrice);              //�����ܼ۸�          
	CC_SYNTHESIZE_READONLY(Sale_V, m_vSelectItem, SelectItems);         //��ǰѡ��
	CC_SYNTHESIZE_READONLY(int,m_totalGrids, TotalGrids);               //�ܵĸ�����
	CC_SYNTHESIZE_READONLY(ItemIcon_V,m_itemIconVec, ItemIconVec);      //������������
	CC_SYNTHESIZE_READONLY(int,m_selectIndex,SelectIndex);              //ѡ��ڵ�idx

	CC_SYNTHESIZE(bool, m_isdoubled, IsDoubled);                        //�����Ƿ���˫����־
	CC_SYNTHESIZE(bool, m_OneSelected, OneSelect);                      //�Ƿ�ѡģʽ true ��ѡ
	CC_SYNTHESIZE(bool, m_longTouched, LongTouched);                    //�Ƿ�֧�ֳ���

private:
	
	emGridsType                m_gridType;                 //�������ӱ�������
	int                        m_lineGrids;                //һ�еĸ�����
	int                        m_disX;                     //������
	int                        m_disY;                     //������
	Point                      m_startPos;                 //������ʼλ��
	bool                       m_blimit;                   //�Ƿ���ʾ������
	float                      m_delayTime;                //�ж�˫��ʱ��
	float                      m_longTime;                 //����ʱ��
	Widget*                    m_childnode;                //������ĵ����ڵ�
	Node*                      m_parent;                   //���ڵ�
	ImageView*                 m_pEquip;                   //�ƶ����߽ڵ�
	int                        m_recordcnt;                //��¼�Ƿ����������
	bool                       m_isLongTouch;              //�Ƿ��ǳ���  
	EquipNode_st*              m_changWidget;              //�ɴ����ڵ��id
	bool                       m_isOverEquip;              //װ���Ƿ��ཻ
	EquipNode_V                m_vEquipNode;               //����װ����ڵ�
	bool                       m_isDelete;                 //�Ƿ�ɾ��
	int                        m_childrenCnt;              //������ڵ���


	CItemGridArray*            m_curShowItemArr;           //��ǰҪ��ʾ�ĸ�����������ָ��

	funct_s                    m_func[ITEMEVENT_MAX];      //���غ���
};
