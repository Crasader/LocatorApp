/***
 * ���ߣ�������
 * ʱ�䣺2015-06-19
 * ˵������ͼ������ݽṹ����
 */

#ifndef __Map_Def_H_
#define __Map_Def_H_

#ifndef CC_SAFE_DELETE
#define CC_SAFE_DELETE(p)            do { if(p) { delete (p); (p) = 0; } } while(0)
#endif

#ifndef CC_SAFE_DELETE_ARRAY
#define CC_SAFE_DELETE_ARRAY(p)     do { if(p) { delete[] (p); (p) = 0; } } while(0)
#endif

#ifndef CC_SAFE_FREE
#define CC_SAFE_FREE(p)                do { if(p) { free(p); (p) = 0; } } while(0)
#endif

#ifndef CC_SAFE_RELEASE
#define CC_SAFE_RELEASE(p)            do { if(p) { (p)->release(); } } while(0)
#endif

#ifndef CC_SAFE_RELEASE_NULL
#define CC_SAFE_RELEASE_NULL(p)        do { if(p) { (p)->release(); (p) = 0; } } while(0)
#endif

#ifndef CC_SAFE_RETAIN
#define CC_SAFE_RETAIN(p)            do { if(p) { (p)->retain(); } } while(0)
#endif

#ifndef CC_BREAK_IF
#define CC_BREAK_IF(cond)            if(cond) break
#endif

#define CC_UNUSED_PARAM(unusedparam) (void)unusedparam

#include <string>
using namespace std;

#define tileInPixelsX	256	
#define tileInPixelsY	256

#define cellInPixelsX	110
#define cellInPixelsY	78


// ������ض���
enum __Dir{
	DIR_N=0,
	DIR_NE,
	DIR_E,
	DIR_SE,
	DIR_S,
	DIR_SW,
	DIR_W,
	DIR_NW,
	DIR_MAX
};

const int _DELTA_CX[DIR_MAX]={-1,0,1,1,1,0,-1,-1};
const int _DELTA_CY[DIR_MAX]={-1,-1,-1,0,1,1,1,0};

const float _DELTA_X[DIR_MAX]={0.0f,cellInPixelsX/2,cellInPixelsX,cellInPixelsX/2,0.0f,-cellInPixelsX/2,-cellInPixelsX,-cellInPixelsX/2};
const float _DELTA_Y[DIR_MAX]={cellInPixelsY,cellInPixelsY/2,0.0f,-cellInPixelsY/2,-cellInPixelsY,-cellInPixelsY/2,0.0f,cellInPixelsY/2};

#define Distance(X,Y,X0,Y0)	MAX(abs(X-X0),abs(Y-Y0))

#define XMAP_SIG 0x583def

// ��ͼ��ID����
enum map_block_id
{
	MAP_BLOCK_FAR = 1000,	// ��ͼԶ����
	MAP_BLOCK_TERRAIN,		// ��ͼ�ر��
	MAP_BLOCK_MASK,			// ��ͼ�ڵ�����
	MAP_BLOCK_PART,
	MAP_BLOCK_REGION,
};

// ��ID�����С��������
struct map_block
{
	int			id;
	int			size;
	char*		data;
};

// 1. ��ͼ�ļ�ͷ
// 2. ��ͼ������
// 3. 

struct map_header
{
	map_header()
	{
		memset(this,0,sizeof(map_header));
	}
	int signature;	// XMAP
	int version;	// �汾��
	int width;		// ��ͼ��
	int height;		// ��ͼ��
	int mode;		// Ԥ��
	int block_offset;	// ������ƫ��λ��
	int block_size;	// �����ݴ�С
};

struct tile_image_data
{
	int offset;
	int size;
};

struct map_terrain
{
	map_terrain()
	{
		memset(this,0,sizeof(map_terrain));
	}
	int tile_count;		// �ֿ���
	int format;			// ͼƬ���ݸ�ʽ
	int cell_size_x;	// �߼�����X���С
	int cell_size_y;	// �߼�����Y���С
	int cell_origin_x;	// �߼�����ϵԭ��
	int cell_origin_y;
	int cell_data_size;
	int tile_data_size;
	int image_data_offset;	// ����ͼƬ����	
	int image_data_size;
	unsigned char* cell_data;
	struct tile_image_data *tile_data;	// ���ÿ����ƬͼƬ���ݵ�ƫ�Ƶ�ַ�ͳ���
	unsigned char* image_data;
};

struct map_mask
{
	int x,y,w,h;
	int relate_data_size;		// �ڵ���ϵ���ݳ���
	int mask_data_offset;		// �ڵ�����ƫ�Ƶ�ַ
	int mask_data_size;			// �ڵ������ܳ��ȣ������ڵ���ϵ���ڵ�����
	unsigned char* mask_data;
};

struct map_part
{
	int x,y,h;
	int dataid;
	string name;
};

struct map_region_property
{
	string name;
	int val;
};

struct map_region
{
	int x,y,w,h;
	int property_count;
	map_region_property* properties;
};

enum map_status
{
	MAP_STATUS_OK,				// �ɹ�
	MAP_STATUS_FILE_NOT_FOUND,	// δ�ҵ��ļ�
	MAP_STATUS_INVALID_FILE,	// �Ƿ���.map�ļ�
	MAP_STATUS_INVALID_PSD,		// δ��Ҫ��������PSD�ļ�
	MAP_STATUS_INVALID_CONTEXT,		// �Ƿ���context
	MAP_STATUS_TERRAIN_NOT_FOUND,	// δ�ҵ������ļ�
	MAP_STATUS_READ_ERROR,
	MAP_STATUS_UNKNOWN_ERROR,
	MAP_STATUS_MALLOC,			// �����ڴ����
	MAP_STATUS_UNSUPPORT,		// δ֧��
};

enum map_context_type
{
	MAP_CONTEXT_NON,		// δ����
	MAP_CONTEXT_PSD,		// �Ѽ���PSD
	MAP_CONTEXT_MAP,		// �Ѽ���MAP
};

struct map_context
{
	map_context() : type(MAP_CONTEXT_NON)
	{
		block_count = 0;
		mask_count = 0;
		mask_data_offset = 0;
		mask_data_size = 0;
		masks = NULL;
		part_count = 0;
		parts = 0;
		region_count = 0;
		regions = 0;
	}
	string name;
	map_header header;
	int	type;
	int block_count;
	map_terrain terrain;
	int mask_count;
	int mask_data_offset;
	int mask_data_size;
	map_mask* masks;
	int part_count;
	map_part* parts;
	int region_count;
	map_region* regions;
};

#endif