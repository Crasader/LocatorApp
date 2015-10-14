/* Name		��MapEffect
 * Author	��YueLiangYou
 * Date		: 2015-06-24
 * Desc		: ��ͼ�ϵ���Ч���������е������õģ��е��Ƕ�̬���������
 * Param	: none
 * Return	: void
 */

#ifndef __MapEffect_h_
#define __MapEffect_h_

#include "MapObject.h"
#include "Role/Effect.h"

class MapEffect : public MapObject
{
public: 
	MapEffect();
	~MapEffect();

	/* Name		��createWithDataID
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ͨ����������ID������Ч
	 * Param	: dataid
	 * Return	: void
	 */
	static MapEffect* createWithDataID(int dataid);

	/* Name		��initWithDataID
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ͨ����������ID��ʼ����Ч
	 * Param	: dataid
	 * Return	: void
	 */
	bool initWithDataID(int dataid);

	/* Name		��update
	 * Author	��YueLiangYou
	 * Date		: 2015-07-02
	 * Desc		: ��֡����
	 * Param	: none
	 * Return	: void
	 */
	virtual void update(float dt);

	/* Name		��SetDataID
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: override ���õ�ͼԪ�ص�ͼ����ID
	 * Param	: dataid
	 * Return	: void
	 */
	void SetDataID(int dataid);

	/* Name		��getEffect
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ��ȡ��Ч����ָ��
	 * Param	: none
	 * Return	: ��Ч����ָ��
	 */
	inline Effect* getEffect(){ return m_pEffect; }

	/* Name		��SetSkinEffect
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ����Ƥ��Ч�� 
	 * Param	: type Ч������
	 * Return	: void
	 */
	virtual void SetSkinEffect(int type);

protected:
	Effect* m_pEffect;		// ��Ч����
};

#endif //__MapEffect_h_