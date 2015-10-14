/***
 * ���ߣ�������
 * ʱ�䣺2015-06-19
 * ˵������ͼ������Ԫ�ض������
 */

#ifndef __MapObject_h_
#define __MapObject_h_

#include "GameDef.h"

// ��ͼԪ�����Ͷ���
enum MapObjectType{
	mapObjectType_None = 0,		// �Ƿ��ĵ�ͼ����
	mapObjectType_Mask,			// ��ͼ�ϵ��ڵ����
	mapObjectType_Effect,		// ��ͼ��װ�ε���Ч������
	mapObjectType_Item,			// ��ͼ�ϵ���Ʒ
	mapObjectType_Chests,		// ��ͼ�еı���
	mapObjectType_Npc,			// ��ͼ�е�NPC
	mapObjectType_Monster,		// ��ͼ�еĹ���
	mapObjectType_Player,		// ��ͼ���
	mapObjectType_Pet,			// ��ͼ����

	mapObjectType_Max			// ��ͼ���ͷ�Χ
};


typedef long long MapObjectID;

// ��ͼԪ�ػ�����Ϣ
struct MapObjectInfo
{
	MapObjectID		id;			// Ψһ��ʶ
	MapObjectType	type;		// ��ͼԪ������ �� MapObjectType
	int				dataid;		// ����ID��ͨ����������������ID

	int				cx;			// ��ͼ�߼�����λ��
	int				cy;

	int				sizeX;		// ռ�õ�ͼ���Ӵ�С
	int				sizeY;

	int				height;		// �߶�

	float			offsetX;	// �߼����굽���������ƫ��λ��
	float			offsetY;

	bool			selected;	// �Ƿ�ѡ��
	bool			insight;	// �Ƿ�����Ұ��
	bool			leaved;		// �Ƿ���Ϊ�뿪��ͼ
	bool			deleted;	// �Ƿ�ָ��Ϊɾ��
	int				skin_effect;// Ƥ��Ч��

	MapObjectInfo()
	{
		memset(this,0,sizeof(MapObjectInfo));
	}
};

class TileMap;
class CRegion;

class MapObject : public Node
{
public:
	MapObject();
	MapObject(MapObjectInfo& info);
	virtual ~MapObject();

	/* Name		��GetMap
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ��ȡ��ͼԪ�ص�ǰ���ڵ�ͼ
	 * Param	: 
	 * Return	: TileMap*
	 */
	inline TileMap*	GetMap(){ return m_pMap; }

	/* Name		��GetBaseInfo
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ��ȡ��ͼԪ�ػ�����Ϣ
	 * Param	: 
	 * Return	: MapObjectInfo&
	 */
	inline const MapObjectInfo& GetBaseInfo() const { return m_Info; }
	inline MapObjectID			GetId(){ return m_Info.id; }
	inline int					GetType(){ return m_Info.type; }
	inline int					GetDataID(){ return m_Info.dataid; }
	inline int					GetCellX(){ return m_Info.cx; }
	inline int					GetCellY(){ return m_Info.cy; }
	inline int					GetSizeX(){ return m_Info.sizeX; }
	inline int					GetSizeY(){ return m_Info.sizeY; }
	inline int					GetHeight(){ return m_Info.height; }
	inline float				GetOffsetX(){ return m_Info.offsetX; }
	inline float				GetOffsetY(){ return m_Info.offsetY; }
	inline bool					GetSelected(){ return m_Info.selected; }
	inline bool					GetInsight(){ return m_Info.insight; }
	inline bool					GetDeleted(){ return m_Info.deleted; }
	inline bool					GetLeaved(){ return m_Info.leaved;}
	inline int					GetSkinEffect(){ return m_Info.skin_effect; }

	inline void			SetId(MapObjectID id){ m_Info.id = id; }
	inline void			SetType(MapObjectType type){ m_Info.type = type; }
	inline void			SetInsight(bool val = true){ m_Info.insight = val; }
	inline void			SetLeaved(bool val = true){ m_Info.leaved = val; }
	inline void			SetDeleted(bool val = true){ m_Info.deleted = val; }

	/* Name		��SetSkinEffect
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ����Ƥ��Ч�� 
	 * Param	: type Ч������
	 * Return	: void
	 */
	virtual void SetSkinEffect(int type){ m_Info.skin_effect = type; }

	/* Name		��EnterMap
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ����ָ����ͼ��������
	 * Param	: pMap��ͼָ�룬pos��ͼ�е���������
	 * Return	: void
	 */
	virtual void EnterMap(TileMap* pMap,const Point& pos);

	/* Name		��EnterMap
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ����ָ����ͼ
	 * Param	: pMap��ͼָ�룬cx��cy��ͼ�е��߼�����
	 * Return	: void
	 */
	virtual void EnterMap(TileMap* pMap,int cx,int cy);

	/* Name		��LeaveMap
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: �뿪��ǰ��ͼ
	 * Param	: none
	 * Return	: void
	 */
	virtual void LeaveMap();

	/* Name		��EnterMapWithEffect
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ����ָ����ͼ ������Ч
	 * Param	: pMap��ͼָ�룬cx��cy��ͼ�е��߼�����
	 * Return	: void
	 */
	virtual void EnterMapWithEffect(TileMap* pMap,int cx,int cy);

	/* Name		��LeaveMapWithEffect
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: �뿪��ǰ��ͼ ������Ч
	 * Param	: none
	 * Return	: void
	 */
	virtual void LeaveMapWithEffect();

	/* Name		��SetDataID
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ���õ�ͼԪ�ص�ͼ����ID
	 * Param	: dataid
	 * Return	: void
	 */
	virtual void SetDataID(int dataid){ m_Info.dataid = dataid; }

	/* Name		��CheckSelected
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ����ͼԪ���Ƿ�ѡ��
	 * Param	: ��Ҫ���������������λ��
	 * Return	: trueΪѡ�У�falseδѡ��
	 */
	virtual bool CheckSelected(float x,float y);

	/* Name		��SetOffset
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ���õ�ͼԪ�ص��߼����������������ƫ��λ��
	 * Param	: ƫ����x,y
	 * Return	: void
	 */
	virtual void SetOffset(float x,float y);

	/* Name		��SetCell
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ���õ�ͼԪ�ص��߼�����λ��
	 * Param	: �߼�����cx,cy
	 * Return	: void
	 */
	virtual void SetCell(int cx,int cy);
	
	/* Name		��getBoundingBox
	 * Author	��YueLiangYou
	 * Date		: 2015-07-02
	 * Desc		: ��ȡ��ײ����
	 * Param	: none
	 * Return	: Rect ��ײ����
	 */
	virtual const Rect& getBoundingBox();

	/* Name		��getHungingPoint
	 * Author	��YueLiangYou
	 * Date		: 2015-07-02
	 * Desc		: ��ȡ��ɫ�ҵ�
	 * Param	: idx �ҵ�����
	 * Return	: Point �ҵ�λ��
	 */
	virtual Point getHungingPoint(int idx);

	/* Name		��getHungingPointOffset
	 * Author	��YueLiangYou
	 * Date		: 2015-07-02
	 * Desc		: ��ȡ��ɫ�ҵ�ƫ��
	 * Param	: idx �ҵ�����
	 * Return	: Point �ҵ�λ��ƫ��
	 */
	virtual Point getHungingPointOffset(int idx);

	/* Name		��SetBoundingInfo
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ���õ�ͼԪ����ײ��Ϣ
	 * Param	: sizeX,sizeY,h ռ�õ�ͼ�߼����Ӵ�С�͸߶�
	 * Return	: void
	 */
	virtual void SetBoundingInfo(int sizeX,int sizeY,int h);

	/* Name		��UpdateBoundingInfo
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ���õ�ͼԪ����ײ��Ϣ
	 * Param	: none
	 * Return	: void
	 */
	virtual void UpdateBoundingInfo();

	/* Name		��UpdatePos
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ����ͼԪ�ص��߼������ƫ��λ�ø��µ���������λ��
	 * Param	: 
	 * Return	: void
	 */
	virtual void UpdatePos();

	//////////////////////////////////////////////////////////////////////////
	// overrided ���غ����б�
	//////////////////////////////////////////////////////////////////////////
	/* Name		��init
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ��ʼ��
	 * Param	: 
	 * Return	: �ɹ�����true��ʧ��false
	 */
	virtual bool init(){ return true; }

	/* Name		��release
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: �ͷ�
	 * Param	: 
	 * Return	: void
	 */
	virtual	void release(){ Node::release();}

	/* Name		��setPosition
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ����Ԫ����������ϵλ��
	 * Param	: ��������x,y
	 * Return	: void
	 */
	virtual void setPosition(float x,float y);

	/* Name		��setPosition
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ����Ԫ����������ϵλ��
	 * Param	: ��������Point& position
	 * Return	: void
	 */
	virtual void setPosition(const Point &position);

	/* Name		��compareZ
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ��ָ��Ԫ�رȽ��ڵ���ϵ,
	 * Param	: pObj Ҫ�Ƚϵĵ�ͼԪ��
	 * Return	: �ڵ��������󷵻ش���0�����ڵ���ϵ���� == 0����ָ�������ڵ����� С��0
	 */
	virtual int compareZ(MapObject* pObj);

	//////////////////////////////////////////////////////////////////////////
	// �¼���Ӧ�����б�
	//////////////////////////////////////////////////////////////////////////
	/* Name		��onSelect
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: Ԫ�ر�ѡ�лص�����
	 * Param	: param == true ��ѡ�У�����δ��ѡ��
	 * Return	: void
	 */
	virtual void onSelect(bool param){}

	/* Name		��onCover
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: Ԫ�ر��ڵ��ص�����
	 * Param	: param == true ���ڵ�������δ�ڵ�
	 * Return	: void
	 */
	virtual void onCover(bool param){}

	/* Name		��onEnterSight
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: Ԫ�ؽ�����Ұ�ص�
	 * Param	: none
	 * Return	: void
	 */
	virtual void onEnterSight();

	/* Name		��onLeaveSight
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: Ԫ���뿪��Ұ�ص�
	 * Param	: none
	 * Return	: void
	 */
	virtual void onLeaveSight();

	/* Name		��onPreEnterSight
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: Ԫ�ؽ�����Ұ�ص���������Ч�������ظú���Ҳ����������Ч��
	 * Param	: none
	 * Return	: void
	 */
	virtual void onPreEnterSight();

	/* Name		��onPreLeaveSight
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: Ԫ���뿪��Ұ�ص���������Ч�������ظú���Ҳ����������Ч��
	 * Param	: none
	 * Return	: void
	 */
	virtual void onPreLeaveSight();

	/* Name		��onEnterSightCallBack
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: Ԫ�ؽ�����Ұaction������ϻص���������Ч�������ظú���Ҳ����������Ч��
	 * Param	: none
	 * Return	: void
	 */
	virtual void onEnterSightCallBack();

	/* Name		��onLeaveSightCallBack
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: Ԫ���뿪��Ұaction������ϻص���������Ч�������ظú���Ҳ����������Ч��
	 * Param	: none
	 * Return	: void
	 */
	virtual void onLeaveSightCallBack();

	/* Name		��onEnterRegion
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: Ԫ�ؽ�ȥĳ������ص�����
	 * Param	: pRegion���������ָ��
	 * Return	: void
	 */
	virtual void onEnterRegion(CRegion* pRegion){}
	
	/* Name		��onLeaveRegion
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: Ԫ���뿪ĳ������ص�����
	 * Param	: pRegion�뿪������ָ��
	 * Return	: void
	 */
	virtual void onLeaveRegion(CRegion* pRegion){}

	/* Name		��onEnterDoor
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: Ԫ�ؽ��봫���Żص�����
	 * Param	: pRegion����Ĵ�����ָ��
	 * Return	: void
	 */
	virtual void onEnterDoor(CRegion* pRegion){}

	/* Name		��onLeaveDoor
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: Ԫ���뿪�����Żص�����
	 * Param	: pRegion�뿪�Ĵ�����ָ��
	 * Return	: void
	 */
	virtual void onLeaveDoor(CRegion* pRegion){}

protected:
	MapObjectInfo		m_Info;			// ��ͼԪ�ػ�����Ϣ
	TileMap*			m_pMap;			// ��ͼԪ��������ͼ�����ж����ڵ�ͼ���ڵĵ�ͼԪ����û������ġ�

	Rect				m_RegionCell;		// ռ�ø�������
	Rect				m_CollisionRect;	// ��ײ����
	vector<Point>		m_HungingPoints;	// �ҵ��б�

private:
	static int			s_ID_COUNTER;			// ��ͼԪ��ID�����������ͻ���ʹ�ã�����Ԫ����Ҫʹ�÷�����ID
};

typedef map<MapObjectID,MapObject*>		MapObjectTable;
typedef	vector<MapObject*>				MapObjectList;

#endif