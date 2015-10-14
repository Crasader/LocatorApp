/***
 * ���ߣ�������
 * ʱ�䣺2015-06-19
 * ˵������ͼ���ڵ������map_context�����ݴ�������
 */

#ifndef __MapMask_h_
#define __MapMask_h_

#include "MapObject.h"
#include "map_def.h"
#include "ShaderSprite.h"

class MapMask;

// ��ͼ�ڵ����������Ϣ
struct MapMaskInfo
{
	MapMaskInfo(int idx,map_mask* pMask) : tag(idx),flag(0),mask(pMask),mask_relation(NULL),obj(NULL)
	{
	}

	int tag;		// ����
	int flag;		// ״̬���
	const map_mask* mask;	// �ڵ����������Ϣ
	unsigned char* mask_relation;	// �ڵ���ϵ����
	MapMask* obj;	// �ڵ��������ָ��
};

typedef vector<MapMaskInfo*> MapMaskList;

class MapMask : public MapObject
{
public: 
	MapMask();
	~MapMask();

	/* Name		��createWithImage
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ͨ��image����MapMask����
	 * Param	: �Ѽ��غõ�imgͼƬ��Դ
	 * Return	: void
	 */
	static MapMask* createWithMaskInfo(MapMaskInfo* pInfo,Image* img,bool grey = false);

	/* Name		��initWithImage
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ͨ��image��ʼ��MapMask����
	 * Param	: �Ѽ��غõ�imgͼƬ��Դ
	 * Return	: void
	 */
	bool initWithMaskInfo(MapMaskInfo* pInfo,Image* img,bool grey = false);

	/* Name		��compareZ
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: override ��ָ��Ԫ�رȽ��ڵ���ϵ
	 * Param	: pObj Ҫ�Ƚϵĵ�ͼԪ��
	 * Return	: �ڵ��������󷵻ش���0�����ڵ���ϵ���� == 0����ָ�������ڵ����� С��0
	 */
	int compareZ(MapObject* pObj);

	/* Name		��calMaskRelation
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: �����ڵ���ϵ
	 * Param	: pos������߽�ɫ����������
	 * Return	: �ڵ��������󷵻�true�����ڵ��������󷵻�false
	 */
	bool calMaskRelation(const Point &pos);

	inline ShaderSprite* getShaderSprite(){ return m_pSprite; }

private:
	MapMaskInfo*	m_pInfo;
	ShaderSprite*	m_pSprite;
};

#endif // __MapMask_h_ 