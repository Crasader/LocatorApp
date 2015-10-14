/* Name		��TileMapLoader
 * Author	��YueLiangYou
 * Date		: 2015-06-24
 * Desc		: ��ͼ�첽���ض���,�����ͼ������ص���Դ�첽���ء����ر�ͼƬ���ؼ���ͼ�ڵ�������أ�
 * Param	: none
 * Return	: void
 */

#ifndef __TileMapLoader_h_
#define __TileMapLoader_h_

#include "GameDef.h"
#include "ResBase.h"
#include "TileManager.h"
#include "MapMask.h"

struct TileInfoAsync
{
	int			tag;
	Image*		img;
};

struct MaskInfoAsync
{
	int tag;					// ����
	int relate_data_size;		// �ڵ���ϵ���ݳ���
	int mask_data_size;			// �ڵ������ܳ��ȣ������ڵ���ϵ���ڵ�����
	Image* img;					// ͼƬ��Ϣ
	unsigned char* mask_relation;	// �ڵ���ϵ����
};

class TileMap;

class TileMapLoader : public ResBase
{
public:
	TileMapLoader(TileMap* pMap);
	~TileMapLoader();

public:
	/* Name		��reset
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ������Ҫ���ص�Ԫ��
	 * Param	: tiles��Ҫ���ص�tile����Ϣ��masks��Ҫ���ص��ڵ������Ϣ
	 * Return	: void
	 */
	void reset(vector<TileInfo*>& tiles,vector<MapMaskInfo*>& masks);

	/* Name		��load
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: override ����ִ����
	 * Param	: none
	 * Return	: true�ɹ���falseʧ��
	 */
	bool load();

	/* Name		��onLoadComplete
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: override ������ɻص�
	 * Param	: pTask �������ָ��
	 * Return	: 
	 */
	void onLoadComplete(ResTask* pTask);

	/* Name		��loadTileImages
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ���ص�ͼ��
	 * Param	: none
	 * Return	: void
	 */
	void loadTileImages();

	/* Name		��loadMaskImages
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: �����ڵ����
	 * Param	: none
	 * Return	: void
	 */
	void loadMaskImages();

	/* Name		��loadMaskImages
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ������ɺ���µ�ͼ��
	 * Param	: none
	 * Return	: void
	 */
	void refreshTiles();

	/* Name		��loadMaskImages
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ������ɺ�����ڵ����
	 * Param	: none
	 * Return	: void
	 */
	void refreshMasks();

private:
	Image* fillMaskImageByMask(Data &data,MaskInfoAsync* pMask);

protected:
	vector<TileInfoAsync*>	m_vTiles;	// �����صĵ�ͼtile�б�
	vector<MaskInfoAsync*>	m_vMasks;	// �����صĵ�ͼ�ڵ�����б�

	TileMap*			m_pMap;		// ����ĵ�ͼָ��
};

#endif // __TileMapLoader_h_