/***
 * ���ߣ�������
 * ʱ�䣺2015-06-19
 * ˵������ͼ��
 * ��ͼ�ļ��أ�ͨ��psd���أ�psd-->map_context-->TileMap;�����ڱ༭����ͨ��map���أ�map-->map_context-->TileMap���ÿͻ���
 * ��ͼ�ֲ�ܹ���
 * 1. Զ���㣬λ�ڵ�ͼ��ײ�
 * 2. �ر�㣬�����ڵ�ͼ��Զ���㣬��Ҫ�ǵ�ͼ��������
 * 3. ��������㣬λ�ڵ�ͼ���м�㣬�������ڵ��������ͼ��Ч����������ͼ�е���Ʒ����ͼ�еĽ�ɫ����ɫ�����NPC������֮�����໥�ڵ���ϵ
 * 4. ����Ч���㣬λ�ڵ�ͼ���ϲ�

 * ����������໥�ڵ���ϵ˵����
 * �ڵ�������ͼ�����ʱ�����������˳����Ϊzorder����ͼ��Ч����������Ʒ�ͽ�ɫ֮������������ϵλ��Y�������жϣ�YֵԽ��zorderԽ���ڵ����������֮����ɫ���߼��ж�zorder��
 * 
 */

#ifndef __TileMap_h_
#define __TileMap_h_

#include "Terrain.h"
#include "RegionManager.h"
#include "MapObject.h"
#include "MapObjectManager.h"
#include "Camera.h"
#include "TileMapLoader.h"
#include "MapEffect.h"
#include "AStar.h"

// ��ͼ�㼶����
enum zOrderTileMap{
	zOrderBottom,		// ��ͼ��Ͳ�
	zOrderFar,			// Զ����
	zOrderTerrain,		// �ر��
	zOrderObject,		// ���������
	zOrderMask,			// �ڵ���
	zOrderSky,			// ����Ч���� Ԥ��
	zOrderTop,			// ��ͼ��߲�
};

// ��ͼ�����Ϣ�ṹ
struct MapPartInfo
{
	MapPartInfo() : obj(NULL)
	{
		info.x = 0;
		info.y = 0;
		info.h = 0;
		info.dataid = 0;
	}

	map_part info;	// �ڵ����������Ϣ
	MapEffect* obj;	// �������ָ��
};

typedef vector<MapPartInfo*> MapPartList;


enum __maskRelation{
	MASK_RELATION_N=0,    //role����mask section����
	MASK_RELATION_FRONT,  //role���ڵ����ǰ��
	MASK_RELATION_BEHIND  //role���ڵ���ĺ���
};


class TileMap : public Layer
{
public:
	TileMap();
	virtual ~TileMap();
	
	CREATE_FUNC(TileMap);

	/* Name		��createWithMapContext
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ͨ����ͼ�����Ĵ�����ͼ
	 * Param	: context ��ͼ������
	 * Return	: �ɹ����ص�ͼָ�룬ʧ��NULL
	 */
	static TileMap* createWithMapContext(map_context* context);

	/* Name		��init
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ��ͼ��ʼ��
	 * Param	: none
	 * Return	: �ɹ�����true��ʧ��false
	 */
	virtual bool init();

	/* Name		��initWithPSD
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ͨ��PSD�ļ���ʼ����ͼ����map_context�л������������
	 * Param	: psd ָ��.psd��ʽ�ļ���
	 * Return	: �ɹ�����true��ʧ��false
	 */
	//virtual bool initWithPSD(const char* psd);

	/* Name		��initWithMAP
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ͨ��MAP�ļ���ʼ����ͼ����map_context�в�������������
	 * Param	: map ָ��.map��ʽ�ļ���
	 * Return	: �ɹ�����true��ʧ��false
	 */
	//virtual bool initWithMAP(const char* map);

	/* Name		��initWithMapContext
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ͨ��map_context��ʼ����ͼ����
	 * Param	: map_contextָ��
	 * Return	: �ɹ�����true��ʧ��false
	 */
	virtual bool initWithMapContext(map_context* context);

	/* Name		��updateMapContext
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ���µ�ͼcontext����ͼ��������Ϣ���༭���޸ĵ�ͼ���Ժ���Ҫ�޸ĵ�ͼ�����Ĳ��ܱ��浽�ļ����档
	 * Param	: none
	 * Return	: void
	 */
	virtual void updateMapContext();

	// Ѱ·���
	/* Name		��initAStar
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: A*Ѱ·�㷨Ԥ����
	 * Param	: none
	 * Return	: true �ɹ���ʧ�� false
	 */
	bool initAStar();

	/* Name		��searchForPath
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: Ѱ�������ɴ�·����
	 * Param	: none
	 * Return	: void
	 */
	void searchForPath(int cx0,int cy0,int cx1,int cy1,APath& path);

//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
///////////////////////////�ر����///////////////////////////////////////
public:
	/* Name		��getViewRect
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ��ȡ��Ļ��Ұ��Χ����������ϵΪ��λ
	 * Param	: out rect ��Ұ����
	 * Return	: void
	 */
	virtual void getViewRect(Rect& rect);

	/* Name		��refreshCellsInView
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ˢ������Ұ��Χ�ڵ��߼�����㣬��ͼ�༭���ڲ鿴�߼���������ʹ��
	 * Param	: none
	 * Return	: void
	 */
	virtual void refreshCellsInView();

	/* Name		��refreshTilesInView
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ˢ������Ұ��Χ�ڵĵ�ͼtile
	 * Param	: none
	 * Return	: void
	 */
	virtual void refreshTilesInView();

	/* Name		��refreshPartsInView
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ˢ������Ұ��Χ�ڵĲ���
	 * Param	: none
	 * Return	: void
	 */
	virtual void refreshPartsInView();

	/* Name		��draw
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ���༭������Ҫ�鿴�ĸ��ָ�����
	 * Param	: none
	 * Return	: void
	 */
	void draw(Renderer *renderer, const kmMat4& transform, bool transformUpdated);

	/* Name		��onDraw
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: �����ַ�ʽ���ܹ�ʹ��������������ͼ�ڵ�
	 * Param	: none
	 * Return	: void
	 */
	void onDraw(Renderer *renderer, const kmMat4& transform, bool transformUpdated);

	/* Name		��draw
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ���༭������Ҫ�鿴�ĸ��ָ�����
	 * Param	: none
	 * Return	: void
	 */
	void drawCellMask(Renderer *renderer, const kmMat4& transform, bool transformUpdated);
	void drawCellGrid(Renderer *renderer, const kmMat4& transform, bool transformUpdated);
	void drawTileGrid(Renderer *renderer, const kmMat4& transform, bool transformUpdated);
	void drawNpcRegions(Renderer *renderer, const kmMat4& transform, bool transformUpdated);
	void drawMonsterRegions(Renderer *renderer, const kmMat4& transform, bool transformUpdated);
	void drawDoorRegions(Renderer *renderer, const kmMat4& transform, bool transformUpdated);
	void drawRegions(Renderer *renderer, const kmMat4& transform, bool transformUpdated);
	void drawSelectedRegions(Renderer *renderer, const kmMat4& transform, bool transformUpdated);
	void drawPartRect(Renderer *renderer, const kmMat4& transform, bool transformUpdated);

	/* Name		��setGrey
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ����ͼȥɫ
	 * Param	: grey true ȥɫ��false��ԭ
	 * Return	: void
	 */
	virtual void setGrey(bool grey = true);

protected:
	vector<int>				m_vCellsInView;			// ��Ұ��Χ�ڵ��߼������
	CC_SYNTHESIZE(bool,m_bTileGrid,TileGrid);		// �Ƿ�tile������
	CC_SYNTHESIZE(bool,m_bCellGrid,CellGrid);		// �Ƿ��߼��������
	CC_SYNTHESIZE(bool,m_bRegionGrid,RegionGrid);	// �Ƿ��������
	CC_SYNTHESIZE_READONLY(bool,m_bGrey,Grey);		// �Ƿ�ȥɫ

public:
///////////////////////////����ת��///////////////////////////////////////
	/* Name		��touchToNode
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ��Ļ���굽���������ת��
	 * Param	: pt �������Ļ���꣬���Ϊ��������
	 * Return	: void
	 */
	void touchToNode(Point& pt);

	/* Name		��nodeToView
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: �������굽�ӿ������ת��
	 * Param	: pt ������������꣬���Ϊ�ӿ�����
	 * Return	: void
	 */
	void nodeToView(Point& pt);

	/* Name		��nodeToView
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: �ӿ����굽���������ת��
	 * Param	: pt ������ӿ����꣬���Ϊ��������
	 * Return	: void
	 */
	void viewToNode(Point& pt);
///////////////////////////����ת�� end///////////////////////////////////////

	/* Name		��update
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ÿ֡���µ�ͼ
	 * Param	: dt ����һ֡��ʱ���
	 * Return	: void
	 */
	virtual void update(float dt);

	/* Name		��updateTerLayer
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ���µر��
	 * Param	: none
	 * Return	: void
	 */
	virtual void updateTerLayer();

	/* Name		��updateFarLayer
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ����Զ����
	 * Param	: none
	 * Return	: void
	 */
	virtual void updateFarLayer();

	/* Name		��onTouchBegan
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ����¼���Ӧ
	 * Param	: none
	 * Return	: void
	 */
	virtual bool onTouchBegan(Touch *touch, Event *unused_event); 
	virtual void onTouchMoved(Touch *touch, Event *unused_event); 
	virtual void onTouchEnded(Touch *touch, Event *unused_event); 
	virtual void onTouchCancelled(Touch *touch, Event *unused_event);

	//virtual void onTouchesBegan(const std::vector<Touch*>& touches, Event *unused_event);
	//virtual void onTouchesMoved(const std::vector<Touch*>& touches, Event *unused_event);
	//virtual void onTouchesEnded(const std::vector<Touch*>& touches, Event *unused_event);
	//virtual void onTouchesCancelled(const std::vector<Touch*>&touches, Event *unused_event);

public:
	/* Name		��centerMap
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ���ӵ�����Ϊ��ͼ������
	 * Param	: none
	 * Return	: void
	 */
	void centerMap();

	/* Name		��moveMap
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: �ƶ���ͼ�ӵ�
	 * Param	: x,y�ƶ�ƫ����
	 * Return	: void
	 */
	void moveMap(int x,int y);

	/* Name		��SetView
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ���߼����������ӵ�
	 * Param	: cx,cy�ӵ��߼�����
	 * Return	: void
	 */
	void SetView(int cx,int cy);

	/* Name		��SetView
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ���������������ӵ�
	 * Param	: Point pt�ӵ���������
	 * Return	: void
	 */
	void SetView(Point pt);

	/* Name		��GetMaxViewX
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ��ͼX�߽磬�ӵ㲻�ܳ�����
	 * Param	: none
	 * Return	: ��ͼX�߽�
	 */
	float GetMaxViewX();

	/* Name		��GetMaxViewY
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ��ͼY�߽磬�ӵ㲻�ܳ�����
	 * Param	: none
	 * Return	: ��ͼY�߽�
	 */
	float GetMaxViewY();

	/* Name		��isCellInView
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: �ж�ָ���߼������Ƿ�����Ұ��
	 * Param	: cx,cyָ���߼������
	 * Return	: ��Ұ�ڷ���true����Ұ�ⷵ��false
	 */
	bool isCellInView(int cx,int cy);

	/* Name		��AddMapObject
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ����ͼԪ�ؼ����ͼ��ָ���߼������
	 * Param	: pObjectָ����ͼԪ�أ�cx,cyָ���߼������
	 * Return	: void
	 */
	void objectEnterMap(MapObject* pObject,int cx,int cy);

	/* Name		��AddMapObject
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ����ͼԪ�ؼ����ͼ��ָ���߼������
	 * Param	: pObjectָ����ͼԪ�أ�Point posָ����������㣬ת�����߼������
	 * Return	: void
	 */
	void objectEnterMap(MapObject* pObject,Point pos);

	/* Name		��RemoveMapObject
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ����ͼԪ���Ƴ���ͼ
	 * Param	: pObjectָ����ͼԪ��
	 * Return	: void
	 */
	void objectLeaveMap(MapObject* pObject);

	/* Name		��RemoveMapObject
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ����ͼԪ�����Ƴ���ͼ
	 * Param	: idָ����ͼԪ��ID
	 * Return	: void
	 */
	void objectLeaveMap(MapObjectID id);

	/* Name		��allObjectLeaveMap
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: �����е�ͼԪ���Ƴ���ͼ���л���ͼ��ʱ����Ҫ�õ�
	 * Param	: none
	 * Return	: void
	 */
	void allObjectLeaveMap();

	/* Name		��objectEnterSight
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ָ����ͼԪ�ؽ�����Ұ,�������Ҫ�����ڵ���ϵ
	 * Param	: pObjectָ����ͼԪ��
	 * Return	: void
	 */
	virtual void objectEnterSight(MapObject* pObject);

	/* Name		��objectLeaveSight
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ��ָ����ͼԪ���Ƴ���Ұ
	 * Param	: pObjectָ����ͼԪ��
	 * Return	: void
	 */
	virtual void objectLeaveSight(MapObject* pObject);

	/* Name		��allObjectLeaveSight
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: �����е�ͼԪ���Ƴ���Ұ���л���ͼ��ʱ����Ҫ�õ�
	 * Param	: none
	 * Return	: void
	 */
	virtual void allObjectLeaveSight();

//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
///////////////////////////�������////////////////////////////////////
public:
	/* Name		��getMapPartInfo
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ��ȡλ��ָ���߼������Ĳ�����Ϣ��ֻ�����ҵ��ĵ�һ����
	 * Param	: cx,cy�߼������
	 * Return	: ������Ϣָ��
	 */
	MapPartInfo* getMapPartInfo(int cx,int cy);

	/* Name		��addPart
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ���һ������
	 * Param	: MapPartInfo pInfo������Ϣ
	 * Return	: void
	 */
	void addMapPartInfo(MapPartInfo* pInfo);

	/* Name		��removePart
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: �Ƴ�����
	 * Param	: MapPartInfo pInfo������Ϣ
	 * Return	: void
	 */
	void removeMapPartInfo(MapPartInfo* pInfo);

	/* Name		��clearMapPartInfo
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: �Ƴ����в���
	 * Param	: none
	 * Return	: void
	 */
	void clearMapPartInfo();

//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
///////////////////////////�ڵ����////////////////////////////////////
public:
	/* Name		��clearMask
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ����ڵ���Ϣ
	 * Param	: none
	 * Return	: void
	 */
	void clearMask();

	/* Name		��isMaskInRect
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: �жϸ�����mask�Ƿ���ָ������Χ�ڣ��н���
	 * Param	: rect ָ������Χ��mask�����ڵ�����������Ϣ
	 * Return	: �н�������true���޽�������false
	 */
	bool isMaskInRect(const Rect& rect,const map_mask* mask);

	/* Name		��getMask
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ��ȡ�ڵ�����
	 * Param	: tag ����ID
	 * Return	: void
	 */
	MapMaskInfo* getMask(int tag);

	/* Name		��getMasksInRect
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ��ȡ��������Χ�����е��ڵ�����
	 * Param	: rect ��������Χ��masks out ���صĲ�����Ϣ�б�
	 * Return	: void
	 */
	void getMasksInRect(const Rect& rect,vector<MapMaskInfo*>& masks);

	/* Name		��getMasksInView
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ��ȡ������Ұ��Χ�ڵ��ڵ������б�
	 * Param	: masks ������Ϣ�б�
	 * Return	: void
	 */
	void getMasksInView(vector<MapMaskInfo*>& masks);

	/* Name		��getMasksNoneInRect
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ��ȡ��������Χ�ڵĵ���û�д����ڵ�����������ڵ������б��½�������Χ���ڵ�������
	 * Param	: rect ��������Χ��masks out ���صĲ�����Ϣ�б�
	 * Return	: void
	 */
	void getMasksNoneInRect(const Rect& rect,vector<MapMaskInfo*>& masks);

	/* Name		��getMasksNoneInView
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ��ȡ��Ұ��Χ�ڵĵ���û�д����ڵ�����������ڵ������б��½�������Χ���ڵ�������
	 * Param	: masks out ���صĲ�����Ϣ�б�
	 * Return	: void
	 */
	void getMasksNoneInView(vector<MapMaskInfo*>& masks);

	/* Name		��isTileInRect
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ������tile���Ƿ���ָ������Χ��
	 * Param	: rect ��������Χ��tile tile����Ϣ
	 * Return	: �ڷ���true�����ٷ���false
	 */
	bool isTileInRect(const Rect& rect,const TileInfo* tile);

	/* Name		��getTilesInRect
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ��ȡ��������Χ�ڵ�tiles
	 * Param	: rect ��������Χ��tiles out tile�б�
	 * Return	: void
	 */
	void getTilesInRect(const Rect& rect,vector<TileInfo*>& tiles);

	/* Name		��getTilesInView
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ��ȡ��Ұ��Χ�ڵ�tiles
	 * Param	: tiles out tile�б�
	 * Return	: void
	 */
	void getTilesInView(vector<TileInfo*>& tiles);

	/* Name		��getTilesNoneInRect
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ��ȡ��������Χ�ڵĵ���û�д�����ʾ�����tiles���½���Ұ��tiles��
	 * Param	: rect ��������Χ��tiles out tile�б�
	 * Return	: void
	 */
	void getTilesNoneInRect(const Rect& rect,vector<TileInfo*>& tiles);

	/* Name		��getTilesNoneInView
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ��ȡ��Ұ��Χ�ڵĵ���û�д�����ʾ�����tiles���½���Ұ��tiles��
	 * Param	: tiles out tile�б�
	 * Return	: void
	 */
	void getTilesNoneInView(vector<TileInfo*>& tiles);

	//virtual void setDataID();

	/* Name		��getMapName
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ��ȡ��ͼ���ƣ�����������������ͼ�ļ�
	 * Param	: none
	 * Return	: ��ͼ����
	 */
	inline string& getMapName(){ return m_pContext->name; }

	/* Name		��getMapFileName
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ��ȡ��ͼ�ļ�
	 * Param	: none
	 * Return	: ��ͼ����
	 */
	inline string getMapFileName(){ return "assets/map/"+m_pContext->name+".map"; }

	/* Name		��getMapContext
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ��ȡ��ͼ������map_context
	 * Param	: none
	 * Return	: map_context*
	 */
	inline map_context* getMapContext(){ return m_pContext; }

protected:
	map_context*	m_pContext;	// ��ͼ������
	MapPartList				m_vParts;	// ��ͼ�ڲ�������Ч
	MapMaskList				m_vMasks;	// ��ͼ�������ڵ�������Ϣ�б�
	CCamera			_camera;		// ��ͼ�����������
	Point			m_viewPoint;	// ��ͼ�ӵ�
	MapObjectList	m_Objects;		// ����Ұ��Χ�ڵĵ�ͼԪ���б�
	TileMapLoader	m_mapLoader;	// ��ͼ��Դ�첽���ض���
	AStar*			m_pAStar;		// A* Ѱ·�㷨����

	CC_SYNTHESIZE_READONLY(Layer*,m_pFarLayer,FarLayer);		// Զ���� Ԥ��
	CC_SYNTHESIZE_READONLY(Layer*,m_pTerrainLayer,TerrainLayer);// �ر��
	CC_SYNTHESIZE_READONLY(Layer*,m_pObjectLayer,ObjectLayer);	// ���������
	CC_SYNTHESIZE_READONLY(Layer*,m_pMaskLayer,MaskLayer);		// ���ֲ� Ԥ��
	CC_SYNTHESIZE_READONLY(Layer*,m_pSkyLayer,SkyLayer);		// ����Ч����

	CC_SYNTHESIZE_READONLY(CTileManager*,m_pTileMgrFar,TileMgrFar);		// Զ����TILE����
	CC_SYNTHESIZE_READONLY(CTileManager*,m_pTileMgrNear,TileMgrNear);	// ������TILE����
	CC_SYNTHESIZE_READONLY(CTerrain*,m_pTerrain,Terrain);				// �ر������
	CC_SYNTHESIZE_READONLY(CRegionManager*,m_pRegionManager,RegionManager);	// ���������
	CC_SYNTHESIZE_READONLY(CMapObjectManager*,m_pObjectManager,ObjectManager);	// ��ͼԪ�ع�����

	CC_SYNTHESIZE_READONLY(int,m_nWidth,MapWidth);				// ��ͼ��С
	CC_SYNTHESIZE_READONLY(int,m_nHeight,MapHeight);
};

#endif