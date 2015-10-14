#ifndef __MPQPackage_h_
#define __MPQPackage_h_

#include <stdio.h>
#include <vector>
#include <string>
#include <pthread.h>
#include "../MD5.h"

using namespace std;

// �Ƿ�ֵ�Ķ���
#define MPQ_INVALID				-1
// MD5�볤�ȶ���
#define MPQ_MD5_CODE_LEN		16
// hash���ȶ���
#define MPQ_HASH_TABLE_SIZE		0x4FFF
//  ѹ��Ҫ�����С����
#define MPQ_COMPRESS_SIZE		0x40

// ǩ������
#define MPQ_HEADER_SIGN0		'M'		// 0λǩ��
#define MPQ_HEADER_SIGN1		'P'		// 1λǩ��
#define MPQ_HEADER_SIGN2		'Q'		// 2λǩ��
#define MPQ_HEADER_SIGN3		'.'		// 3λǩ��

// MPQ��������
#define MPQ_ENCRYPT_CODE1		0x9E
#define MPQ_ENCRYPT_CODE2		0x37
#define MPQ_ENCRYPT_CODE3		0x79
#define MPQ_ENCRYPT_CODE4		0xB9

// MPQ��ͷ�ṹ����
typedef struct _mpq_header_
{
	unsigned char	sign[4];			// 4λǩ��
	unsigned int	header_size;		// �ļ�ͷ����
	unsigned int	data_size;			// �����ݳ���
	unsigned int	hole_size;			// ���ڿն�����
	unsigned short	format_version1;	// �汾Э���
	unsigned short	format_version2;	// �汾Э���
	unsigned int	hash_table_offset;	// ��ϣ��ƫ��λ��
	unsigned int	block_table_offset;	// ���ݿ��ƫ��λ��
	unsigned int	hash_count;			// ��ϣ��ʵ�ʳ���
	unsigned int	block_count;		// ��ʵ�ʸ���

	_mpq_header_(){
		sign[0] = MPQ_HEADER_SIGN0;
		sign[1] = MPQ_HEADER_SIGN1;
		sign[2] = MPQ_HEADER_SIGN2;
		sign[3] = MPQ_HEADER_SIGN3;

		header_size = 0;
		data_size = 0;
		hole_size = 0;
		format_version1 = 0;
		format_version2 = 0;
		hash_table_offset = 0;
		block_table_offset = 0;
		hash_count = MPQ_HASH_TABLE_SIZE;
		block_count = 0;
	}
}MPQHeader;

// ���־λ���� �鱻����
#define MPQ_BLOCK_ENCRYPT		0x01
// ���־λ���� �鱻ѹ��
#define MPQ_BLOCK_COMPRESS		0x02
// ���־λ���� �鱻ɾ��
#define MPQ_BLOCK_DELETE		0x04

// ��ṹ����
typedef struct _mpq_block_
{
	string			name;					// ���� ���ļ�����
	unsigned int	offset;					// ����ƫ��λ��
	unsigned int	size;					// ����ѹ���󳤶�
	unsigned int	uncompress_size;		// ����ʵ�ʳ���
	unsigned int	flag;					// ���־λ
	unsigned char	md5_code[MPQ_MD5_CODE_LEN];// ������MD5������֤��

	_mpq_block_(){
		name = "";
		offset = 0;
		size = 0;
		uncompress_size = 0;
		flag = 0;
		memset(md5_code,0,MPQ_MD5_CODE_LEN);
	}

	void mark(unsigned int f)
	{
		flag |= f;
	}

	bool is_mark(unsigned int f){
		return (flag & f) != 0;
	}

	void cl_mark(unsigned int f)
	{
		flag &= ~f;
	}
}MPQBlock;

// ��ϣ��ڵ�ṹ����
typedef struct _mpq_hash_node_
{
	unsigned int verify_code_a;			// �ڵ���֤��A
	unsigned int verify_code_b;			// �ڵ���֤��B
	unsigned int block_index;			// �ڵ�Ŀ�����ֵ

	_mpq_hash_node_(){
		verify_code_a = MPQ_INVALID;
		verify_code_b = MPQ_INVALID;
		block_index = MPQ_INVALID;
	}

}MPQHashNode;

// MPQ������
class MPQPackage
{
public:
	MPQPackage();
	~MPQPackage();

public:
	/* Name		��is_block_valid
	 * Author	��YueLiangYou
	 * Date		: 2015-07-02
	 * Desc		: ������ݿ��Ƿ���Ч
	 * Param	: idx �±�����
	 * Return	: ��Ч����true ����false
	 */
	bool is_block_valid(unsigned int idx);

	/* Name		��is_hash_node_valid
	 * Author	��YueLiangYou
	 * Date		: 2015-07-02
	 * Desc		: ��ϣ�ڵ��Ƿ���Ч
	 * Param	: pNode �ڵ�ָ��
	 * Return	: ��Ч����true ����false
	 */
	bool is_hash_node_valid(MPQHashNode* pNode);

	/* Name		��is_hash_node_valid
	 * Author	��YueLiangYou
	 * Date		: 2015-07-02
	 * Desc		: ��ϣ�ڵ��Ƿ���Ч
	 * Param	: idx �±�����
	 * Return	: ��Ч����true ����false
	 */
	bool is_hash_node_valid(unsigned int idx);

	bool is_hash_node_hashed(unsigned int idx);

	/* Name		��get_hash_node
	 * Author	��YueLiangYou
	 * Date		: 2015-07-02
	 * Desc		: ��ȡ��ϣ��ڵ�
	 * Param	: idx �±�����
	 * Return	: MPQHashNode* ��ϣ�ڵ�ָ��
	 */
	MPQHashNode* get_hash_node(unsigned int idx);

	/* Name		��get_hash_node_new
	 * Author	��YueLiangYou
	 * Date		: 2015-07-02
	 * Desc		: ��ȡһ��δʹ�õĹ�ϣ��ڵ�
	 * Param	: hash_code �ļ���ϣֵ��verify_a��verify_b ��֤�� A �� B
	 * Return	: MPQHashNode* ��ϣ�ڵ�ָ��
	 */
	MPQHashNode*	get_hash_node_new(unsigned int hash_code,unsigned int verify_a,unsigned int verify_b);
	MPQHashNode*	get_hash_node_new_for_diff(unsigned int hash_code,unsigned int verify_a,unsigned int verify_b);

	/* Name		��get_hash_node_new
	 * Author	��YueLiangYou
	 * Date		: 2015-07-02
	 * Desc		: ��ȡһ��δʹ�õĹ�ϣ��ڵ�
	 * Param	: file_name �ļ���
	 * Return	: MPQHashNode* ��ϣ�ڵ�ָ��
	 */
	MPQHashNode* get_hash_node_new(const char* file_name);

	/* Name		��find_hash_node
	 * Author	��YueLiangYou
	 * Date		: 2015-07-02
	 * Desc		: ���ҹ�ϣ��ڵ�
	 * Param	: file_name �ļ���
	 * Return	: MPQHashNode* ��ϣ�ڵ�ָ��
	 */
	MPQHashNode* find_hash_node(const char* file_name);

	/* Name		��find_hash_node
	 * Author	��YueLiangYou
	 * Date		: 2015-07-02
	 * Desc		: ���ҹ�ϣ��ڵ�
	 * Param	: hash_code �ļ���ϣֵ��verify_a��verify_b ��֤�� A �� B
	 * Return	: MPQHashNode* ��ϣ�ڵ�ָ��
	 */
	MPQHashNode* find_hash_node(unsigned int hash_code,unsigned int verify_a,unsigned int verify_b);

	/* Name		��get_block
	 * Author	��YueLiangYou
	 * Date		: 2015-07-02
	 * Desc		: ��ȡ���ݿ�
	 * Param	: file_name �ļ���
	 * Return	: MPQBlock* ���ݿ�ָ��
	 */
	MPQBlock* get_block(const char* file_name);

	/* Name		��get_block
	 * Author	��YueLiangYou
	 * Date		: 2015-07-02
	 * Desc		: ��ȡ���ݿ�
	 * Param	: pNode ��ϣ��ڵ�
	 * Return	: MPQBlock* ���ݿ�ָ��
	 */
	MPQBlock* get_block(MPQHashNode* pNode);

	/************************************************************************/
	/* ����һ��mpq�ļ�
	/************************************************************************/
	bool create(const char* file_name);

	/************************************************************************/
	/* ��һ��mpq�ļ�
	/************************************************************************/
	bool open(const char* file_name);

	/************************************************************************/
	/* ����һ��mpq�ļ���Ϣ,file_name:�����ļ���
	/************************************************************************/
	bool backup(const char* file_name);
	bool revert(const char* file_name,const char* file_revert);

	/************************************************************************/
	/* �ر�mpq�ļ�
	/************************************************************************/
	void close(bool bSave = true);
	
	/************************************************************************/
	/* �Ӱ��ж�ȡ�ļ���Ϣ
	/************************************************************************/
	/* Name		��read_file
	 * Author	��YueLiangYou
	 * Date		: 2015-07-02
	 * Desc		: ��ȡ�ļ�����
	 * Param	: file_name �ļ�����size_read ��ȡ��ʵ�ʳ��ȣ�offset ��ȡƫ�ƣ�size ָ����ȡ�ĳ���
	 * Return	: ����ָ��
	 */
	unsigned char* read_file(const char* file_name,unsigned int& size_read,unsigned int offset = 0,unsigned int size = 0);

	/* Name		��read_node
	 * Author	��YueLiangYou
	 * Date		: 2015-07-02
	 * Desc		: ��ȡ��ϣ�ڵ�����
	 * Param	: pNode ��ϣ�ڵ�ָ�룬size_read ��ȡ��ʵ�ʳ��ȣ�offset ��ȡƫ�ƣ�size ָ����ȡ�ĳ���
	 * Return	: ����ָ��
	 */
	unsigned char* read_hash_node(MPQHashNode* pNode,unsigned int& size_read,unsigned int offset = 0,unsigned int size = 0);

	/* Name		��read_block
	 * Author	��YueLiangYou
	 * Date		: 2015-07-02
	 * Desc		: ��ȡ���ݿ�����
	 * Param	: pBlock ���ݿ�ָ�룬size_read ��ȡ��ʵ�ʳ��ȣ�offset ��ȡƫ�ƣ�size ָ����ȡ�ĳ���
	 * Return	: ����ָ��
	 */
	unsigned char* read_block(MPQBlock* pBlock,unsigned int& size_read,unsigned int offset = 0,unsigned int size = 0);

	/************************************************************************/
	/* �Ӱ���׷���ļ���Ϣ
	/************************************************************************/
	bool append_file(const char* file_name,bool bCompress = false,bool bEncrypt = false);

	/************************************************************************/
	/* �Ӱ���ɾ���ļ���Ϣ
	/************************************************************************/
	void remove_file(const char* file_name);

	/************************************************************************/
	/* ��mpq��׷�����ݣ����ؿ�������ʧ�ܷ��� MPQ_INVALID           
	/************************************************************************/
	unsigned int append_data(const unsigned char* pData,unsigned int size,bool bCompress = false,bool bEncrypt = false);

	/************************************************************************/
	/* �Ӱ���ɾ���ļ�������Ϣ ��������ɾ������ ֻ�Ǹ���Ӧ�����ݿ�ɾ����־λ��1
	/************************************************************************/
	void	remove_data(MPQHashNode* pNode);
	void	remove_data(MPQBlock* pBlock);
	void	remove_data(unsigned int idx);

public:
	/* Name		��encrypt
	 * Author	��YueLiangYou
	 * Date		: 2015-07-02
	 * Desc		: ���ݼ���
	 * Param	: in �������룬out ������� size ���ݳ�������
	 * Return	: void
	 */
	void encrypt(const unsigned char* in, unsigned char* out, int size);

	/* Name		��encrypt
	 * Author	��YueLiangYou
	 * Date		: 2015-07-02
	 * Desc		: ���ݽ���
	 * Param	: in �������룬out ������� size ���ݳ�������
	 * Return	: void
	 */
	void decrypt(const unsigned char* in, unsigned char* out, int size);

	/* Name		��reset_hash_node
	 * Author	��YueLiangYou
	 * Date		: 2015-07-02
	 * Desc		: ���ù�ϣ�ڵ�
	 * Param	: pNode �ڵ�ָ��
	 * Return	: void
	 */
	void reset_hash_node(MPQHashNode* pNode);

	/************************************************************************/
	/* ��д��ͷ����ϣ������ݿ��
	/************************************************************************/
	void read_header(FILE* fptr);
	void read_hash_table(FILE* fptr);
	void read_block_table(FILE* fptr);
	void write_header(FILE* fptr);
	void write_hash_table(FILE* fptr);
	void write_block_table(FILE* fptr);

	/************************************************************************/
	/* �������ݿ��
	/************************************************************************/
	void clear_block_table();

	/************************************************************************/
	/* ���ݿ��д��ָ����־�ļ�
	/************************************************************************/
	void format_block_table(const char* log);

protected:
	pthread_mutex_t m_readMutex;						// ��ȡ�������
	FILE*			m_fptr;								// �ļ�ָ��
	MPQHeader		m_stHeader;							// ��ͷ
	MPQHashNode		m_hashTable[MPQ_HASH_TABLE_SIZE];	// ��ϣ��
	typedef vector<MPQBlock*> MPQBlockTable;			// ���ݿ��
	MPQBlockTable	m_blockTable;						// ���ݿ��
	unsigned long	m_IdentCode;						// ��֤�� ������֤������
};

#endif