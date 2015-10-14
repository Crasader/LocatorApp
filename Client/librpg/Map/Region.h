/***
 * ���ߣ�������
 * ʱ�䣺2015-06-19
 * ˵������ͼ������������
 */

#ifndef __Region_h_
#define __Region_h_

#include "GameDef.h"
#include "map_def.h"

typedef map<string,int> RegionProperties;

class CRegion
{
public:
	CRegion();
	CRegion(int cx,int cy,int sx,int sy);
	~CRegion();

public:
	/* Name		��initWithMapRegion
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ͨ��map_region�ṹ��ʼ������
	 * Param	: region 
	 * Return	: �ɹ�����true��ʧ�ܷ���false
	 */
	bool initWithMapRegion(map_region* region);
	
	/* Name		��getMapRegionData
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ��ȡmap_region�ṹ����
	 * Param	: region map_regionָ��
	 * Return	: void 
	 */
	void getMapRegionData(map_region* region);

	/* Name		��addProperty
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: Ϊ��������һ������,��������Ѵ��ڣ����滻����ֵ��
	 * Param	: name�������ƣ�valΪ����ֵ
	 * Return	: void
	 */
	void addProperty(string name,int val);

	/* Name		��setProperty
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: �޸�ָ�����Զ�Ӧ��ֵ
	 * Param	: name�������ƣ�valΪ����ֵ
	 * Return	: void
	 */
	void setProperty(string name,int val);

	/* Name		��getProperty
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ��ȡָ�����Զ�Ӧ��ֵ
	 * Param	: name��������
	 * Return	: ����ֵ
	 */
	int	getProperty(string name);

	/* Name		��removeProperty
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: �Ƴ�ָ������
	 * Param	: name��������
	 * Return	: void
	 */
	void removeProperty(string name);

	/* Name		��removeAllProperty
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: �Ƴ���������
	 * Param	: none
	 * Return	: void
	 */
	void removeAllProperty();

	/* Name		��containsCell
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ���ָ�������Ƿ�����������ڲ�
	 * Param	: �߼�����cx,cy
	 * Return	: true���ڲ���false�����ڲ�
	 */
	bool containsCell(int cx,int cy);

	inline int getEndX(){ return m_nOriginX+m_nSizeX; }
	inline int getEndY(){ return m_nOriginY+m_nSizeY; }
	inline RegionProperties& getProperties(){ return m_Properties; }

	/* Name		��isMonsterRegion
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: �ж���������Ƿ��ǹ�������
	 * Param	: none
	 * Return	: true�ǣ�false����
	 */
	bool isMonsterRegion();

protected:
	// �������㣬���߼�����Ϊ��λ
	CC_SYNTHESIZE(int,m_nOriginX,OriginX);
	CC_SYNTHESIZE(int,m_nOriginY,OriginY);
	// ����Ĵ�С�����߼��������Ϊ��λ
	CC_SYNTHESIZE(int,m_nSizeX,SizeX);
	CC_SYNTHESIZE(int,m_nSizeY,SizeY);
	// �������Զ�Ӧ��,������---����ֵ
	RegionProperties m_Properties;
	// �����Ƿ�ѡ��
	CC_SYNTHESIZE(bool,m_bSelected,Selected);
};

#endif