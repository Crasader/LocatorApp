
#include "../CCFileUtils.h"
USING_NS_CC;
#include "commonRef.h"
#include "map_io.h"
#include "StringUtil.h"
#include <assert.h>

size_t map_io::load_from_map(const char* map_file,map_context* context)
{
	// ��ȡ�ļ�ͷ
	size_t ret = read_map_header(map_file,context);
	if ( ret != MAP_STATUS_OK )
	{
		return ret;
	}

	// ��ȡ��
	ret = read_map_blocks(map_file,context);
	if ( ret != MAP_STATUS_OK )
	{
		return ret;
	}

	CCLOG("map_io::load_from_map[%s].",map_file);

	context->name = StringUtil::StringCutFileName(map_file);
	context->type = MAP_CONTEXT_MAP;

	CCLOG("map_io::load_from_map name=[%s].",context->name.c_str());

	return MAP_STATUS_OK;
}


void map_io::map_free(map_context* context)
{
	if ( !context )
	{
		return ;
	}

	//map_terrain terrain;
	map_terrain *pTerrain = &context->terrain;

	if ( pTerrain->cell_data )
	{
		delete[] pTerrain->cell_data;
	}


	//free struct tile_image_data *tile_data;	// ���ÿ����ƬͼƬ���ݵ�ƫ�Ƶ�ַ�ͳ���
	//malloc:terrain.tile_data = new tile_image_data[block_x*block_y];
	if ( pTerrain->tile_data )
	{
		delete[] pTerrain->tile_data;
	}

	//free unsigned char* image_data;
	//malloc: terrain.image_data = new unsigned char[terrain.image_data_size];
	if ( pTerrain->image_data )
	{
		delete[] pTerrain->image_data;
	}


	// free map_mask* masks;
	//map_c->masks = map_c->masks = new map_mask[shadowLayerCnt];
	//pMapMask->mask_data = new unsigned char[pMapMask->mask_data_size];
	map_mask* pMask = context->masks;
	if ( pMask )
	{
		for(int i=0; i<context->mask_count;++i)
		{
			if ( pMask->mask_data )
			{
				delete[] pMask->mask_data;
			}

			++pMask;
		}
		delete[] context->masks;
	}

	// free map_part* parts;
	if( context->parts )
	{
		delete[] context->parts;
	}

	// free map_region* regions;
	map_region* pRegions = context->regions;
	if ( pRegions )
	{
		for(int i=0;i<context->region_count;++i)
		{
			if( pRegions->properties )
			{
				delete[] pRegions->properties;
			}

			++pRegions;
		}

		delete[] context->regions;
	}

	delete context;
	context = NULL;
};

size_t map_io::read_map_header(const char* map_file,map_context* context)
{
	Data data = FileUtils::getInstance()->getDataFromFile(map_file,0,sizeof(map_header));
	if ( data.isNull() )
	{
		return MAP_STATUS_FILE_NOT_FOUND;
	}

	memcpy(&context->header,data.getBytes(),data.getSize());
	if ( context->header.signature != XMAP_SIG )
	{
		return MAP_STATUS_INVALID_FILE;
	}
	return MAP_STATUS_OK;
}

size_t map_io::read_map_blocks(const char* map_file,map_context* context)
{
 	Data data = FileUtils::getInstance()->getDataFromFile(map_file,context->header.block_offset,context->header.block_size);
 	if ( data.isNull() )
 	{
 		return MAP_STATUS_FILE_NOT_FOUND;
 	}

 	ByteArray block_array(data.getBytes(),data.getSize());
	context->block_count = block_array.read_integer();
	for ( int i = 0;i < context->block_count;++i )
	{
		size_t ret = read_map_block(block_array,context);
		if ( ret != MAP_STATUS_OK )
		{
			return ret;
		}
	}

	CCLOG("map_io::read_map_blocks ok.");

	return MAP_STATUS_OK;
}

size_t map_io::read_map_block(ByteArray& array,map_context* context)
{
	int id = array.read_integer();
	switch (id)
	{
	case MAP_BLOCK_TERRAIN: return read_map_terrain(array,context);
	case MAP_BLOCK_MASK:	return read_map_mask(array,context);
	case MAP_BLOCK_PART:	return read_map_part(array,context);
	case MAP_BLOCK_REGION:	return read_map_region(array,context);
	default:
		break;
	}

	return MAP_STATUS_READ_ERROR;
}

size_t map_io::read_map_terrain(ByteArray& array,map_context* context)
{
	context->terrain.tile_count = array.read_integer();
	context->terrain.format = array.read_integer();
	context->terrain.cell_size_x = array.read_integer();
	context->terrain.cell_size_y = array.read_integer();
	context->terrain.cell_origin_x = array.read_integer();
	context->terrain.cell_origin_y = array.read_integer();
	context->terrain.cell_data_size = array.read_integer();
	//_context.terrain.tile_data_size = array.read_integer();
	context->terrain.image_data_offset = array.read_integer();
	context->terrain.image_data_size = array.read_integer();

	// ��ȡ�߼����ݣ�ƫ������
	context->terrain.cell_data = new unsigned char[context->terrain.cell_data_size];
	array.read(context->terrain.cell_data,context->terrain.cell_data_size);

	context->terrain.tile_data = new tile_image_data[context->terrain.tile_count];
	array.read(context->terrain.tile_data,context->terrain.tile_count*sizeof(tile_image_data));

	return MAP_STATUS_OK;
}

size_t map_io::read_map_mask(ByteArray& array,map_context* context)
{
	int count = array.read_integer();
	int offset = array.read_integer();
	int size = array.read_integer();

	context->mask_count = count;
	context->mask_data_offset = offset;
	context->mask_data_size = size;

	if ( count > 0 )
	{
		context->masks = new map_mask[count];
		map_mask* pMask = context->masks;
		for ( int i = 0;i < count; ++i )
		{
			pMask->x = array.read_integer();
			pMask->y = array.read_integer();
			pMask->w = array.read_integer();
			pMask->h = array.read_integer();
			pMask->relate_data_size = array.read_integer();
			pMask->mask_data_offset = array.read_integer();
			pMask->mask_data_size = array.read_integer();
			pMask->mask_data = NULL;
			pMask++;
		}
	}

	return MAP_STATUS_OK;
}

size_t map_io::read_map_part(ByteArray& array,map_context* context)
{
	int count = array.read_integer();
	context->part_count = count;

	if ( count > 0 )
	{
		context->parts = new map_part[count];

		for ( int i = 0; i< count; ++i )
		{
			context->parts[i].x = array.read_integer();
			context->parts[i].y = array.read_integer();
			context->parts[i].h = array.read_integer();
			context->parts[i].dataid = array.read_integer();
			context->parts[i].name = array.read_string();
		}
		
		//array.read(context->parts,count*sizeof(map_part));
	}
	return MAP_STATUS_OK;
}


size_t map_io::read_map_region(ByteArray& array,map_context* context)
{
	int count = array.read_integer();
	context->region_count = count;
	if ( count > 0 )
	{
		context->regions = new map_region[count];
		for ( int i = 0;i < count; ++i )
		{
			context->regions[i].x = array.read_integer();
			context->regions[i].y = array.read_integer();
			context->regions[i].w = array.read_integer();
			context->regions[i].h = array.read_integer();
			context->regions[i].property_count = array.read_integer();

			if ( context->regions[i].property_count > 0 )
			{
				context->regions[i].properties = new map_region_property[context->regions[i].property_count];
			}

			for (int j = 0; j < context->regions[i].property_count; j++)
			{
				context->regions[i].properties[j].name = array.read_string();
				context->regions[i].properties[j].val = array.read_integer();
			}
		}
	}

	return MAP_STATUS_OK;
}

Data map_io::read_image_data(const char* map_file,int index,map_context* context)
{
	// ��ȡCELL DATA
	if( context->type == MAP_CONTEXT_NON || index > context->terrain.tile_count || index < 0 )
	{
		return Data::Null;
	}
	else
	{
		if ( context->type == MAP_CONTEXT_MAP )
		{
			return FileUtils::getInstance()->getDataFromFile(map_file,context->terrain.tile_data[index].offset,context->terrain.tile_data[index].size);
		}
		if ( context->type == MAP_CONTEXT_PSD )	// context����ֱ��ȡ
		{
			return FileUtils::getInstance()->getDataFromFile(map_file,context->terrain.tile_data[index].offset,context->terrain.tile_data[index].size);
		}

		return Data::Null;
	}
}

Data map_io::read_mask_image_data(const char* map_file,int index,map_context* context)
{
	// ��ȡMASK DATA
	if( context->type == MAP_CONTEXT_NON || index > context->mask_count || index < 0 )
	{
		return Data::Null;
	}
	else
	{
		if ( context->type == MAP_CONTEXT_MAP )
		{
			return FileUtils::getInstance()->getDataFromFile(map_file,context->masks[index].mask_data_offset,context->masks[index].mask_data_size);
		}
		if ( context->type == MAP_CONTEXT_PSD ) // context����ֱ��ȡ
		{
			return FileUtils::getInstance()->getDataFromFile(map_file,context->masks[index].mask_data_offset,context->masks[index].mask_data_size);
		}

		return Data::Null;
	}
}

////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
size_t map_io::map_save(const char* map_file,map_context* context)
{
	if ( !context )
	{
		return MAP_STATUS_INVALID_CONTEXT;
	}

	FILE* fptr = fopen(map_file,"rb+");
	if ( !fptr )
	{
		// �ļ�������ʱ����Ҫ�����ļ�
		fptr = fopen(map_file,"wb+");
		if ( !fptr )
		{
			return MAP_STATUS_FILE_NOT_FOUND;
		}
	}

	size_t ret = 0;
	do
	{
		if ( context->type == MAP_CONTEXT_PSD )
		{
			context->terrain.image_data_offset = sizeof(map_header);

			// ��ͼͼƬ��Ϣ֮������ڵ����ͼƬ��Ϣ
			context->mask_data_offset = context->terrain.image_data_offset + context->terrain.image_data_size;

			//map_terrain::image_data  multiple
			ret = save_image_data(fptr,context);
			//if(ret == 0) break;

			//map_mask::mask_data      multiple
			ret = save_mask_image_data(fptr,context);
			//if(ret == 0) break;

			context->header.block_offset = context->mask_data_offset + context->mask_data_size;
		}

		//blocks 
		ret = save_map_blocks(fptr,context);
		//if(ret == 0) break;

		// header
		ret = save_map_header(fptr,context);
		//if(ret == 0) break;
	}
	while(0);

	fflush(fptr);
	fclose(fptr);

	return MAP_STATUS_OK;
}

size_t map_io::save_image_data(FILE* fptr,map_context* context)
{
	if ( !context->terrain.image_data )
	{
		return 0;
	}

	context->terrain.image_data_offset = sizeof(map_header);
	
	// д�����ͼƬ����
	int offset = context->terrain.image_data_offset;
	int nWrite = 0;
	fseek(fptr,offset,SEEK_SET);

	nWrite += fwrite(context->terrain.image_data,1,context->terrain.image_data_size,fptr);

	// ���д�������Ƿ���ȷ
	assert(nWrite == context->terrain.image_data_size);

	// д�������Ҫ����ͼƬ����������
	tile_image_data *pTileImageData = context->terrain.tile_data;
	for(int i=0; i<context->terrain.tile_count; ++i)
	{		
		pTileImageData->offset = offset;
		offset += pTileImageData->size;
		pTileImageData++;
	}

	return nWrite;
}

size_t map_io::save_mask_image_data(FILE* fptr,map_context* context)
{
	// ��ͼͼƬ��Ϣ֮������ڵ����ͼƬ��Ϣ
	context->mask_data_offset = context->terrain.image_data_offset + context->terrain.image_data_size;
	
	// д���ڵ����ݣ����������ͼƬ��Ϣ������
	int nWrite =0;
	int offset = context->mask_data_offset;
	for ( int i = 0;i < context->mask_count; ++i )
	{
		if ( context->masks[i].mask_data )
		{
			context->masks[i].mask_data_offset = offset;
			nWrite += fwrite(context->masks[i].mask_data,1,context->masks[i].mask_data_size,fptr);
			offset += context->masks[i].mask_data_size;	
		}
	}

	// ���д���Ƿ���ȷ
	assert(nWrite == context->mask_data_size);

	return nWrite;
}

size_t map_io::save_map_blocks(FILE* fptr,map_context* context)
{
	fseek(fptr,context->header.block_offset,SEEK_SET);

	context->block_count = 4;
	context->header.block_size = 0;

	size_t nItem = fwrite(&context->block_count,sizeof(int),1,fptr);
	context->header.block_size += nItem * sizeof(int);

	context->header.block_size += save_map_terrain(fptr,context);
	context->header.block_size += save_map_mask(fptr,context);
	context->header.block_size += save_map_part(fptr,context);
	context->header.block_size += save_map_region(fptr,context);

	return context->header.block_size;
}

size_t map_io::save_map_header(FILE* fptr,map_context* context)
{
	fseek(fptr,0,SEEK_SET);

	return fwrite(&context->header,sizeof(map_header),1,fptr);
}

size_t map_io::save_map_terrain(FILE* fptr,map_context* context)
{
	int block_id = MAP_BLOCK_TERRAIN;
	size_t nWrite = 0;
	size_t nItem = 0;
	nItem = fwrite(&block_id,sizeof(int),1,fptr);
	nWrite += nItem * sizeof(int);
	nItem = fwrite(&context->terrain.tile_count,sizeof(int),1,fptr);
	nWrite += nItem * sizeof(int);
	nItem = fwrite(&context->terrain.format,sizeof(int),1,fptr);
	nWrite += nItem * sizeof(int);
	nItem = fwrite(&context->terrain.cell_size_x,sizeof(int),1,fptr);
	nWrite += nItem * sizeof(int);
	nItem = fwrite(&context->terrain.cell_size_y,sizeof(int),1,fptr);
	nWrite += nItem * sizeof(int);
	nItem = fwrite(&context->terrain.cell_origin_x,sizeof(int),1,fptr);
	nWrite += nItem * sizeof(int);
	nItem = fwrite(&context->terrain.cell_origin_y,sizeof(int),1,fptr);
	nWrite += nItem * sizeof(int);
	nItem = fwrite(&context->terrain.cell_data_size ,sizeof(int),1,fptr);
	nWrite += nItem * sizeof(int);
	//nItem = fwrite(&_context.terrain.tile_data_size,sizeof(int),1,fptr);
	//nWrite += nItem * sizeof(int);
	nItem = fwrite(&context->terrain.image_data_offset,sizeof(int),1,fptr);
	nWrite += nItem * sizeof(int);
	nItem = fwrite(&context->terrain.image_data_size,sizeof(int),1,fptr);
	nWrite += nItem * sizeof(int);

	// д������߼����ݣ��赲�����յ�
	nItem = fwrite(context->terrain.cell_data,1,context->terrain.cell_data_size,fptr);
	nWrite += nItem;
	nItem = fwrite(context->terrain.tile_data,sizeof(tile_image_data),context->terrain.tile_count,fptr);
	nWrite += nItem * sizeof(tile_image_data);

	return nWrite;
}

size_t map_io::save_map_mask(FILE* fptr,map_context* context)
{
	int block_id = MAP_BLOCK_MASK;
	size_t nWrite = 0;
	size_t nItem = 0;
	nItem = fwrite(&block_id,sizeof(int),1,fptr);
	nWrite += nItem * sizeof(int);
	nItem = fwrite(&context->mask_count,sizeof(int),1,fptr);
	nWrite += nItem * sizeof(int);
	nItem = fwrite(&context->mask_data_offset,sizeof(int),1,fptr);
	nWrite += nItem * sizeof(int);
	nItem = fwrite(&context->mask_data_size,sizeof(int),1,fptr);
	nWrite += nItem * sizeof(int);

	map_mask* pMask = context->masks;
	for ( int i = 0;i < context->mask_count; ++i )
	{
		nItem = fwrite(&(pMask->x),sizeof(int),1,fptr);
		nWrite += nItem * sizeof(int);
		nItem = fwrite(&(pMask->y),sizeof(int),1,fptr);
		nWrite += nItem * sizeof(int);
		nItem = fwrite(&(pMask->w),sizeof(int),1,fptr);
		nWrite += nItem * sizeof(int);
		nItem = fwrite(&(pMask->h),sizeof(int),1,fptr);
		nWrite += nItem * sizeof(int);
		nItem = fwrite(&(pMask->relate_data_size),sizeof(int),1,fptr);
		nWrite += nItem * sizeof(int);
		nItem = fwrite(&(pMask->mask_data_offset),sizeof(int),1,fptr);
		nWrite += nItem * sizeof(int);
		nItem = fwrite(&(pMask->mask_data_size),sizeof(int),1,fptr);
		nWrite += nItem * sizeof(int);
		pMask++;
	}
	return nWrite;
}

size_t map_io::save_map_part(FILE* fptr,map_context* context)
{
	int block_id = MAP_BLOCK_PART;
	size_t nWrite = 0;
	size_t nItem = 0;
	nItem = fwrite(&block_id,sizeof(int),1,fptr);
	nWrite += nItem * sizeof(int);
	nItem = fwrite(&context->part_count,sizeof(int),1,fptr);
	nWrite += nItem * sizeof(int);

	map_part* pPart = context->parts;
	for ( int i = 0;i < context->part_count; ++i )
	{
		int x = pPart->x;
		nItem = fwrite(&x,sizeof(int),1,fptr);
		nWrite += nItem * sizeof(int);
		int y = pPart->y;
		nItem = fwrite(&y,sizeof(int),1,fptr);
		nWrite += nItem * sizeof(int);
		int h = pPart->h;
		nItem = fwrite(&h,sizeof(int),1,fptr);
		nWrite += nItem * sizeof(int);

		int dataid = pPart->dataid;
		nItem = fwrite(&dataid,sizeof(int),1,fptr);
		nWrite += nItem * sizeof(int);

		char len = pPart->name.length();
		nItem = fwrite(&len,1,1,fptr);
		nWrite += nItem;
		const char* str = pPart->name.c_str();
		nItem = fwrite(str,1,len,fptr);
		nWrite += nItem;

		pPart++;
	}
	return nWrite;
}

size_t map_io::save_map_region(FILE* fptr,map_context* context)
{
	int block_id = MAP_BLOCK_REGION;
	size_t nWrite = 0;
	size_t nItem = 0;
	nItem = fwrite(&block_id,sizeof(int),1,fptr);
	nWrite += nItem * sizeof(int);
	nItem = fwrite(&context->region_count,sizeof(int),1,fptr);
	nWrite += nItem * sizeof(int);

	for ( int i = 0;i < context->region_count; ++i )
	{
		nItem = fwrite(&context->regions[i].x,sizeof(int),1,fptr);
		nWrite += nItem * sizeof(int);
		nItem = fwrite(&context->regions[i].y,sizeof(int),1,fptr);
		nWrite += nItem * sizeof(int);
		nItem = fwrite(&context->regions[i].w,sizeof(int),1,fptr);
		nWrite += nItem * sizeof(int);
		nItem = fwrite(&context->regions[i].h,sizeof(int),1,fptr);
		nWrite += nItem * sizeof(int);
		nItem = fwrite(&context->regions[i].property_count,sizeof(int),1,fptr);
		nWrite += nItem * sizeof(int);

		for (int j = 0; j < context->regions[i].property_count; j++)
		{
			string name = context->regions[i].properties[j].name;
			char len = (char)name.length();
			nItem = fwrite(&len,1,1,fptr);
			nWrite += nItem * 1;
			nItem = fwrite(name.c_str(),1,len,fptr);
			nWrite += nItem * 1;
			nItem = fwrite(&context->regions[i].properties[j].val,sizeof(int),1,fptr);
			nWrite += nItem * sizeof(int);
		}
	}

	return nWrite;
}
	


// map file�ļ���ʽ���£�
// head 
// image data (��ͼ������ķֿ�jpg����)  ( come from psd file)
// �ڵ�������  ( come from psd file)
// block 1 : terrain   �󲿷�����������psd,ֻ��cell_data���Բ߻�����
// block 2 : mask( come from psd file)
// block 3 : part (����߻�����) 
// block 4 : region (����߻�����) 

// add by wenzy
size_t map_io::import_tmi(map_context* oldContext,map_context* context,const char *mapFileName)
{
	//merge old map's tile map information to context

	// head ֻ��int block_size;	// �����ݴ�СΪ�ı䣬����д�ļ��Ƕ�̬�����ˣ����Բ��øı� 

	//change ���Բ߻����õ�cell_data  in block 1 : terrain
	assert(oldContext->terrain.cell_data_size == context->terrain.cell_data_size);
	memcpy(context->terrain.cell_data,oldContext->terrain.cell_data,oldContext->terrain.cell_data_size);

	// block 3 : part (����߻�����) 
	context->part_count = oldContext->part_count;
	if(context->parts)
	{
		delete [] context->parts;
		context->parts = NULL;
	}
	if(oldContext->part_count > 0)
	{
		//context->parts = new map_part[oldContext->part_count];
		//memcpy(oldContext->parts,context->parts,oldContext->part_count*sizeof(map_part) );

		context->parts = new map_part[oldContext->part_count];

		for ( int i = 0; i< oldContext->part_count; ++i )
		{
			context->parts[i].x = oldContext->parts[i].x;
			context->parts[i].y = oldContext->parts[i].y;
			context->parts[i].h = oldContext->parts[i].h;
			context->parts[i].dataid = oldContext->parts[i].dataid;
			context->parts[i].name = oldContext->parts[i].name;
		}
	}

	// block 4 : region (����߻�����) 
	if(context->regions)
	{
		for ( int i = 0;i < context->region_count; ++i )
		{
			if ( context->regions[i].property_count > 0 )
			{
				delete [] context->regions[i].properties;
			}

		}
		delete [] context->regions;
		context->regions = NULL;
	}
	
	int regionCnt = oldContext->region_count;
	context->region_count = regionCnt;
	if ( regionCnt > 0 )
	{
		context->regions = new map_region[regionCnt];
		for ( int i = 0;i < regionCnt; ++i )
		{
			context->regions[i].x = oldContext->regions[i].x;
			context->regions[i].y = oldContext->regions[i].y;
			context->regions[i].w = oldContext->regions[i].w;
			context->regions[i].h = oldContext->regions[i].h;
			context->regions[i].property_count = oldContext->regions[i].property_count;

			if ( context->regions[i].property_count > 0 )
			{
				context->regions[i].properties = new map_region_property[context->regions[i].property_count];
			}

			for (int j = 0; j < context->regions[i].property_count; j++)
			{
				context->regions[i].properties[j].name = oldContext->regions[i].properties[j].name;
				context->regions[i].properties[j].val = oldContext->regions[i].properties[j].val;
			}
		}
	}

	// save context to map file
	map_save(mapFileName,context);

	return 0;
}
