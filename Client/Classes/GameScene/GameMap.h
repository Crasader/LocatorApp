/***
 * ģ�飺GameMap
 * ���ߣ�������
 * ʱ�䣺2015-07-2
 * ˵������Ϸ��ͼ
 * ��tileMap�Ĺ�����չ
 */


#ifndef __GameMap_h_
#define __GameMap_h_

#include "GameDef.h"
#include "Map/TileMap.h"
#include "Map/AStar.h"
#include "db.h"
#include "GameMapTypes.h"

class GameMap : public TileMap
{
public:
	GameMap();
	~GameMap();

	CREATE_FUNC(GameMap);

	/* Name		��loadMap
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: �����������ݼ��ص�ͼ���첽����
	 * Param	: mapid ��ͼ��������ID
	 * Return	: true �ɹ���false ʧ��
	 */
	bool loadMap(int mapid);

	bool init();
	void update(float dt);

	/* Name		��updateView
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: �����ӵ�����
	 * Param	: none
	 * Return	: void
	 */
	void updateView();

	/* Name		��shake
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ��Ļ����
	 * Param	: float deltaX = 1.0f,float deltaY = 1.0f �𶯷���,float rate,int times �𶯵�Ƶ�������
	 * Return	: void
	 */
	void shake(float deltaX = 1.0f,float deltaY = 1.0f,float rate = 0.1f,int times = 5);

	/* Name		��onShakeEnded
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ��Ļ���������ص�
	 * Param	: none
	 * Return	: void
	 */
	void onShakeEnded();

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
	//void onTouchesBegan(const std::vector<Touch*>& touches, Event *unused_event);
	//void onTouchesMoved(const std::vector<Touch*>& touches, Event *unused_event);
	//void onTouchesEnded(const std::vector<Touch*>& touches, Event *unused_event);
	//void onTouchesCancelled(const std::vector<Touch*>&touches, Event *unused_event);

	/* Name		��getDistance
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: �ж������߼������֮��ľ���
	 * Param	: pos0 ��㣬pos1 Ŀ���
	 * Return	: ����
	 */
	int getDistance(const APoint& pos0,const APoint& pos1);

	/* Name		��checkTargetPos
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: �ж���㵽Ŀ���֮���Ƿ����赲�㣬���û��ֱ�ӷ����赲�ģ�������򷵻����һ�����赲��
	 * Param	: pos0 ��� �� pos1 Ŀ���
	 * Return	: ���һ�����赲��
	 */
	APoint checkTargetPos(const APoint& pos0,const APoint& pos1);

	/* Name		��checkTargetPos
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: �ж���㵽Ŀ���֮���Ƿ����赲�㣬���û��ֱ�ӷ����赲�ģ�������򷵻����һ�����赲��
	 * Param	: pos0 ��� �� pos1 Ŀ��㣬����������
	 * Return	: ���һ�����������������Ƶķ��赲��
	 */
	APoint checkTargetPosWithDistance(const APoint& pos0,const APoint& pos1,int dis);

	/* Name		��ShowEffect
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: �ڵ�ͼ����ʾһ����Ч
	 * Param	: int dataid,const string& name,const Point& pos,float duration ����ʱ�� S,scale �Ŵ�ϵ��
	 * Return	: void
	 */
	void ShowEffect(int dataid,const string& name,const Point& pos,float duration = 0.0f,float scale = 1.0f);

	/* Name		��ShowEffect
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: �ڵ�ͼ����ʾһ����Ч
	 * Param	: Effect* pEffect,const Point& pos,float duration ����ʱ�� S,scale �Ŵ�ϵ��
	 * Return	: void
	 */
	void ShowEffect(Effect* pEffect,const Point& pos,float duration = 0.0f,float scale = 1.0f);

	/* Name		��ShowEffectCallBack
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: չʾ��ͼ��Чͨ�ûص�
	 * Param	: Layer* pLayer ��Ч���ڲ�
	 * Return	: void
	 */
	void ShowEffectCallBack(Effect* pEffect);

	/* Name		��getMapId
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ��ȡ��ͼΨһ��ʶID
	 * Param	: none
	 * Return	: __int64 ��ͼID
	 */
	inline __int64 getMapId(){ return m_nId; }

	/* Name		��setMapId
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ���õ�ͼΨһ��ʶID
	 * Param	: __int64 id ��ͼID
	 * Return	: void
	 */
	inline void setMapId(__int64 id){ m_nId = id; }

	/* Name		��getMapData
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ��ȡ��ͼ��������
	 * Param	: none
	 * Return	: MapCfg* ��ͼ��������ָ��
	 */
	inline MapCfg* getMapData(){ return m_pData; }

	/* Name		��getMapDataID
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ��ȡ��ͼ��������ID
	 * Param	: none
	 * Return	: int ��ͼ��������ID
	 */
	inline int getMapDataID(){ return m_pData?m_pData->id:0; }

	/* Name		��isFightMap
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: �Ƿ���ս����ͼ
	 * Param	: none
	 * Return	: 
	 */
	inline bool isFightMap(){ return m_pData?m_pData->functiontype == GameMapFuncType_Fight:false; }

	/* Name		��isNormalMap
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: �Ƿ��ǳ����ͼ
	 * Param	: none
	 * Return	: 
	 */
	inline bool isNormalMap(){ return m_pData?m_pData->functiontype == GameMapFuncType_Normal:false; }

	/* Name		��getFuncType
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ��ȡ��ͼ�淨����
	 * Param	: none
	 * Return	: 
	 */
	inline GameMapFuncType getFuncType(){ return m_pData?GameMapFuncType(m_pData->functiontype):GameMapFuncType_Normal; }

	/* Name		��getPlayType
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ��ȡ��ͼ�淨����
	 * Param	: none
	 * Return	: 
	 */
	inline GameMapPlayType getPlayType(){ return m_pData?GameMapPlayType(m_pData->play_type):GameMapPlayType_None; }

	/*��������-����,����,����*/
	inline GameMapType	getType(){ return m_pData?GameMapType(m_pData->type):GameMapType_None; }

	/* Name		��getMapBgFileName
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ��ȡ��ͼģ�������ļ�
	 * Param	: none
	 * Return	: ��ͼ����
	 */
	inline string getMapBgFileName(){ return "assets/map/"+getMapContext()->name+".jpg"; }

	inline Layer* getEffectLayer(){ return m_pEffectLayer; }
	
	inline vector<int>&	getReliveRules() { return m_reliveRules; }

protected:
	__int64		m_nId;			// ��ͼID���ɷ��������ɵ�Ψһ��ʶ
	MapCfg*		m_pData;		// ��ͼ��������
	Layer*		m_pEffectLayer;	// ��Ϸ�е���Ч�㣬������Ч������һЩЧ����Ч

	vector<int>	m_reliveRules;
};

#endif //__GameMap_h_