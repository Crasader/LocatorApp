/***
 * ���ߣ�������
 * ʱ�䣺2015-06-19
 * ˵������ͼ�ļ���д���
 * ��ͼ�ļ���ʽ .map��
 * 1. ��ͼ�ļ�ͷ
 * 2. ��ͼͼƬ����
 * 3. ��ͼ�ڵ����ͼƬ����
 */

#ifndef __map_io_h_
#define __map_io_h_

#include "commonRef.h"
#include "map_def.h"

namespace map_io
{
	/* Name		��load_from_map
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ��MAP�ļ��ж����ͼ
	 * Param	: map_file .map��ʽ�ļ�����context ��ͼ������ ������������
	 * Return	: MAP_STATUS_OK�ɹ�������ʧ��
	 */
	size_t load_from_map(const char* map_file,map_context* context);

	/* Name		��map_free
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: �ͷŵ�ͼ������
	 * Param	: context ��ͼ������
	 * Return	: void
	 */
	void map_free(map_context* context);

	/* Name		��read_image_data
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: �����ͼͼƬ��Ϣ
	 * Param	: array ���ݻ�������context ��ͼ������
	 * Return	: MAP_STATUS_OK�ɹ�������ʧ��
	 */
	Data read_image_data(const char* map_file,int index,map_context* context);

	/* Name		��read_mask_image_data
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: �����ͼ�ڵ�ͼƬ��Ϣ
	 * Param	: array ���ݻ�������context ��ͼ������
	 * Return	: MAP_STATUS_OK�ɹ�������ʧ��
	 */
	Data read_mask_image_data(const char* map_file,int index,map_context* context);

	/* Name		��read_map_header
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: �����ͼ�ļ�ͷ
	 * Param	: map_file ��ͼ�ļ����ƣ�context ��ͼ������
	 * Return	: MAP_STATUS_OK�ɹ�������ʧ��
	 */
	size_t read_map_header(const char* map_file,map_context* context);
	
	/* Name		��read_map_blocks
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: �����ͼ���ݿ�
	 * Param	: map_file ��ͼ�ļ����ƣ�context ��ͼ������
	 * Return	: MAP_STATUS_OK�ɹ�������ʧ��
	 */
	size_t read_map_blocks(const char* map_file,map_context* context);

	/* Name		��read_map_block
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: �����ͼ���ݿ�
	 * Param	: array ���ݻ�������context ��ͼ������
	 * Return	: MAP_STATUS_OK�ɹ�������ʧ��
	 */
	size_t read_map_block(ByteArray& array,map_context* context);

	/* Name		��read_map_terrain
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: �����ͼ����
	 * Param	: array ���ݻ�������context ��ͼ������
	 * Return	: MAP_STATUS_OK�ɹ�������ʧ��
	 */
	size_t read_map_terrain(ByteArray& array,map_context* context);

	/* Name		��read_map_mask
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: �����ͼ�ڵ���Ϣ
	 * Param	: array ���ݻ�������context ��ͼ������
	 * Return	: MAP_STATUS_OK�ɹ�������ʧ��
	 */
	size_t read_map_mask(ByteArray& array,map_context* context);

	/* Name		��read_map_part
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: �����ͼ������Ϣ
	 * Param	: array ���ݻ�������context ��ͼ������
	 * Return	: MAP_STATUS_OK�ɹ�������ʧ��
	 */
	size_t read_map_part(ByteArray& array,map_context* context);

	/* Name		��read_map_region
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: �����ͼ������Ϣ
	 * Param	: array ���ݻ�������context ��ͼ������
	 * Return	: MAP_STATUS_OK�ɹ�������ʧ��
	 */
	size_t read_map_region(ByteArray& array,map_context* context);

	/* Name		��map_save
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ����ͼ������.map��ʽ�ļ�
	 * Param	: map_file ��ͼ�ļ�����context ��ͼ������
	 * Return	: MAP_STATUS_OK�ɹ�������ʧ��
	 */
	size_t map_save(const char* map_file,map_context* context);

	/* Name		��save_image_data
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: д���ͼ����ͼƬ��Ϣ
	 * Param	: fptr ��ͼ�ļ�ָ�룬context ��ͼ������
	 * Return	: ����ʵ��д���С
	 */
	size_t save_image_data(FILE* fptr,map_context* context);

	/* Name		��save_mask_image_data
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: д���ͼ�ڵ������ͼƬ��Ϣ
	 * Param	: fptr ��ͼ�ļ�ָ�룬context ��ͼ������
	 * Return	: ����ʵ��д���С
	 */
	size_t save_mask_image_data(FILE* fptr,map_context* context);

	/* Name		��save_map_header
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: д���ͼ�ļ�ͷ
	 * Param	: fptr ��ͼ�ļ�ָ�룬context ��ͼ������
	 * Return	: ����ʵ��д���С
	 */
	size_t save_map_header(FILE* fptr,map_context* context);

	/* Name		��save_map_blocks
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: д���ͼ���ݿ�
	 * Param	: fptr ��ͼ�ļ�ָ�룬context ��ͼ������
	 * Return	: ����ʵ��д���С
	 */
	size_t save_map_blocks(FILE* fptr,map_context* context);

	/* Name		��save_map_terrain
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: д���������
	 * Param	: fptr ��ͼ�ļ�ָ�룬context ��ͼ������
	 * Return	: ����ʵ��д���С
	 */
	size_t save_map_terrain(FILE* fptr,map_context* context);

	/* Name		��save_map_mask
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: д���ڵ�����
	 * Param	: fptr ��ͼ�ļ�ָ�룬context ��ͼ������
	 * Return	: ����ʵ��д���С
	 */
	size_t save_map_mask(FILE* fptr,map_context* context);

	/* Name		��save_map_blocks
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: д���ͼ����
	 * Param	: fptr ��ͼ�ļ�ָ�룬context ��ͼ������
	 * Return	: ����ʵ��д���С
	 */
	size_t save_map_part(FILE* fptr,map_context* context);

	/* Name		��save_map_blocks
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: д���ͼ��������
	 * Param	: fptr ��ͼ�ļ�ָ�룬context ��ͼ������
	 * Return	: ����ʵ��д���С
	 */
	size_t save_map_region(FILE* fptr,map_context* context);

	//save tile map information to file
	size_t import_tmi(map_context* oldContext,map_context* context,const char *mapFileName);

};

#endif