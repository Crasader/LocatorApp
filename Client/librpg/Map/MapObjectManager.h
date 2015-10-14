/***
 * ���ߣ�������
 * ʱ�䣺2015-06-19
 * ˵������ͼ�����н���Ԫ�ع����࣬�����ڵ�ͼ�ڵĶ��������棬�ڵ���ϵ���㴦��
 */

#ifndef __MapObjectManager_h_
#define __MapObjectManager_h_

#include "GameDef.h"
#include "MapObject.h"

class TileMap;

class CMapObjectManager : public Ref
{
public:
	CMapObjectManager(TileMap* pMap);
	~CMapObjectManager();

	/* Name		��GetMap
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ��ȡ��ǰ����ĵ�ͼ
	 * Param	: 
	 * Return	: TileMap*
	 */
	inline TileMap* GetMap(){ return m_pMap; }

	/* Name		��GetObjectList
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ��ȡ��ͼ������Ԫ��
	 * Param	: 
	 * Return	: MapObjectList&
	 */
	inline MapObjectList& GetObjectList(){ return m_Objects; }

	/* Name		��init
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ��ʼ��
	 * Param	: none
	 * Return	: �ɹ�����true��ʧ�ܷ���false
	 */
	bool init();

	/* Name		��clear
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: �������е�ͼԪ��
	 * Param	: none
	 * Return	: void
	 */
	void clear();

	/* Name		��release
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: override �ͷ�
	 * Param	: none
	 * Return	: void
	 */
	void release();

	/* Name		��update
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: �������е�ͼԪ�ظ���,����������Ϊɾ���Ķ���,�ڵ���ϵ����
	 * Param	: none
	 * Return	: void
	 */
	void update(float dt);

	/* Name		��sortZorder
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: �����ڵ���ϵ
	 * Param	: objs ��������,len �������鳤��
	 * Return	: void
	 */
	void sortZorder(MapObject** objs,int len);

	/* Name		��sortZorder
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ����zoderֵ
	 * Param	: obj ��Ҫ����Ķ���Ԫ�� objs ��������,len �������鳤��
	 * Return	: zoderֵ
	 */
	int getTopObject(MapObject** objs,int len,int idx = 0);

public:
	MapObject*		SelectObject(float x,float y,MapObject* pExclude = NULL );
	int				SelectObjects(float x,float y,MapObjectList& objects);
	int				SelectObjects(Point pos,MapObjectList& objects);

	MapObject*		getObject(MapObjectID id);
	MapObject*		getObject(int cx,int cy);
	int				getObjects(MapObjectType type,MapObjectList& objects);
	int				getObjects(int cx,int cy,MapObjectList& objects);
	int				getObjectsInView(MapObjectList& objects);
	int				getObjectsInView(MapObjectType type,MapObjectList& objects);
	MapObject*		getObjectNearBy(int cx,int cy,MapObjectType type);

	/* Name		��addObject
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ��������������
	 * Param	: pObject ָ����ͼԪ�ض���ָ��
	 * Return	: void
	 */
	void addObject(MapObject* pObject);

	/* Name		��removeObject
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: �Ƴ�����
	 * Param	: pObject ָ����ͼԪ�ض���ָ��
	 * Return	: void
	 */
	void removeObject(MapObject* pObject);

private:
	MapObjectList	m_Objects;			// ��ͼԪ���б�
	TileMap*		m_pMap;				// ��ǰ����ĵ�ͼ
};

#endif