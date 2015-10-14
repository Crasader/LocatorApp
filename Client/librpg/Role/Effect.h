/***
 * ģ�飺��������Ч
 * ���ߣ�������
 * ʱ�䣺2015-06-19
 * ˵������Ϸ�ڳ��˽�ɫ�����������Ч������
 */

#pragma once

#include "GameDef.h"
#include "cocostudio/CCArmatureDataManager.h"
#include "cocostudio/CCArmature.h"
#include "NotifyCenter.h"


using namespace cocos2d;
using namespace cocostudio;
class Effect;
typedef vector<Effect*>	EffectList;

class Effect : public Node
{
public:
	/* Name		��SplitDataID
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ͨ��ָ��ID�����ֻ�ȡdataID ID�������2λΪ������������λΪdataid
	 * Param	: none
	 * Return	: int dataid
	 */
	static int SplitDataID(int id){ return id / 100; }

	/* Name		��SplitPlayIndex
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		:  ͨ��ָ��ID�����ֻ�ȡ��������
	 * Param	: none
	 * Return	: int index
	 */
	static int SplitPlayIndex(int id){ return id % 100; }

	/* Name		��GetEffectListByConfig
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ͨ�����ô�����Ч
	 * Param	: config ���ò�����list ��Ч�б�
	 * Return	: int count
	 */
	static int GetEffectListByConfig(const string& config,EffectList& list);

public: 
	Effect();
	virtual ~Effect();

	CREATE_FUNC(Effect);

	/* Name		��createWithDataID
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ͨ��dataID����һ����Ч
	 * Param	: id ��Ч��ID������ͨ��������������json�ļ���idx ָ��JSON�ļ��ĵڼ���������loop �Ƿ���Ҫѭ������
	 * Return	: ��Чָ��
	 */
	static Effect* createWithDataID(int id,bool bLoop = false);

	/* Name		��setDataID
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ����dataID
	 * Param	: id ��Ч��ID������ͨ��������������json�ļ���
	 * Return	: void
	 */
	virtual void setDataID(int dataid);

	/* Name		��onNotifyCenter
	 * Author	��YueLiangYou
	 * Date		: 2015-07-02
	 * Desc		: �յ�֪ͨ���Ĵ�����Ϣ
	 * Param	: msg ��Ϣ��
	 * Return	: void
	 */
	virtual void onNotifyCenter(int msg);

	/* Name		��onAnimationEvent
	 * Author	��YueLiangYou
	 * Date		: 2015-07-02
	 * Desc		: �����¼���Ӧ����
	 * Param	: armature movementType movementID
	 * Return	: void
	 */
	virtual void onAnimationEvent(cocostudio::Armature *armature, cocostudio::MovementEventType movementType, const std::string& movementID);

	/* Name		��onFrameEvent
	 * Author	��YueLiangYou
	 * Date		: 2015-07-02
	 * Desc		: ֡�¼���Ӧ����
	 * Param	: bone ������evt �¼��Զ��������
	 * Return	: void
	 */
	virtual void onFrameEvent(cocostudio::Bone *bone, const std::string& evt, int originFrameIndex, int currentFrameIndex);

	/* Name		��loadData
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ����ָ������
	 * Param	: name ��������
	 * Return	: void
	 */
	virtual void loadData(const char* name);

	/* Name		��unloadData
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ж�ؼ��ض���
	 * Param	: none
	 * Return	: void
	 */
	virtual void unloadData();

	/* Name		��playWithName
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ����ָ������
	 * Param	: name ��Ч���ƣ����ŵĶ������� loop �Ƿ�ѭ������ -1 ѭ������
	 * Return	: void
	 */
	virtual void playWithName(const string& name,int loop = -1);

	/* Name		��setDuration
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ���ö�������ʱ��
	 * Param	: duration ʱ�� S
	 * Return	: void
	 */
	virtual void setDuration(float duration);

	/* Name		��setSkinEffect
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ����Ƥ��Ч��
	 * Param	: type Ч������
	 * Return	: void
	 */
	virtual void setSkinEffect(SkinEffectType type);

	/* Name		��play
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ���Ŷ���
	 * Param	: none
	 * Return	: void
	 */
	virtual void play();

	/* Name		��getDataID
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ��ȡ�����ļ�����dataID
	 * Param	: none
	 * Return	: int dataId
	 */
	inline int getDataID(){ return m_nDataID; }

	/* Name		��getArmature
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ��ȡ��������ָ��
	 * Param	: none
	 * Return	: ��������ָ��
	 */
	inline Armature* getArmature(){ return m_pArmature; }

	/* Name		��getPlayIndex
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ��ȡ��������
	 * Param	: none
	 * Return	: int
	 */
	inline string getName(){ return m_sName; }

	/* Name		��getLoop
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ��ȡѭ������
	 * Param	: none
	 * Return	: int
	 */
	inline int getLoop(){ return m_nLoop; }

	/* Name		��getDuration
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ��ȡ����ʱ��
	 * Param	: none
	 * Return	: int
	 */
	inline float getDuration(){ return m_fDuration; }

	/* Name		��getHungingPoint
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ��ȡ��Ч�ҵ�
	 * Param	: none
	 * Return	: int
	 */
	inline int getHungingPoint(){ return m_nHungingPoint; }

	/* Name		��setPlayIndex
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ���ò�������
	 * Param	: index ��������
	 * Return	: void
	 */
	inline void setName(const string& name){ m_sName = name; play();}

	/* Name		��setLoop
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ����ѭ������
	 * Param	: loop ѭ������ -1 Ϊѭ������
	 * Return	: void
	 */
	inline void setLoop(int loop = -1){ m_nLoop = loop; play();}

	/* Name		��setHungingPoint
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ������Ч�ҵ�
	 * Param	: hpt �ҵ�
	 * Return	: void
	 */
	inline void setHungingPoint(int hpt){ m_nHungingPoint = hpt; }

protected:
	int			m_nDataID;			// dataid JSON�ļ�����
	string		m_sName;			// ��Ч���ƣ����Ŷ�������
	float 		m_fDuration;		// ����ʱ��
	int			m_nLoop;			// ѭ������ -1Ϊѭ������
	Armature*	m_pArmature;		// ��������
	int			m_nHungingPoint;	// ��Ч�ҵ�
	SkinEffectType m_nSkinEffectType;	// Ƥ��Ч��
};