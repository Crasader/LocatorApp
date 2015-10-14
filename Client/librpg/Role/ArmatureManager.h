/***
 * ģ�飺����������
 * ���ߣ�������
 * ʱ�䣺2015-06-19
 * ˵�����������ж����������ͷ�
 */

#pragma once

#include "GameDef.h"
#include "cocostudio/CCArmatureDataManager.h"
#include "cocostudio/CCArmature.h"
#include "NotifyCenter.h"
#include "Singleton.h"


using namespace cocos2d;
using namespace cocostudio;

typedef map<string,Armature*> ArmatureMap;

class Role;
class Effect;

class ArmatureManager : public Ref,public Singleton<ArmatureManager>
{
public:
	ArmatureManager();
	~ArmatureManager();
	/* Name		��loadArmatureFileForEffect
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ���ض����ļ� ExportJson
	 * Param	: dataid ��������ID��pEffect���ض���
	 * Return	: void
	 */
	void loadArmatureFileForEffect(int dataid,Effect* pEffect);

	/* Name		��loadArmatureFileForRole
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ���ض����ļ� ExportJson
	 * Param	: dataid ��������ID��pRole���ض���
	 * Return	: void
	 */
	void loadArmatureFileForRole(int dataid,Role* pRole);

	/* Name		��onArmatureComplete
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ���ض����ļ���ɻص� ExportJson
	 * Param	: percent ��ɵĽ��ȣ�1.0f��ʾȫ����ɣ�����δȫ�����
	 * Return	: void
	 */
	void onArmatureComplete(float percent);

	/* Name		��getNotifyCenterRole
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ��ȡ��ɫ��Ϣ����
	 * Param	: none
	 * Return	: NotifyCenter<Role>&
	 */
	inline NotifyCenter<Role>& getNotifyCenterRole(){ return m_ncRole; }

	/* Name		��getNotifyCenterEffect
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ��ȡ��Ч֪ͨ����
	 * Param	: none
	 * Return	: NotifyCenter<Effect>&
	 */
	inline NotifyCenter<Effect>& getNotifyCenterEffect(){ return m_ncEffect; }

	/* Name		��getArmature
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ����һ��armature����
	 * Param	: none
	 * Return	: Armature*
	 */
	Armature* getArmature(const string& name);

	Armature* cloneArmature(const Armature* armature);

	

protected:
	ArmatureMap m_mapArmatures;		// ������
	NotifyCenter<Role> m_ncRole;	// ��ɫ֪ͨ����
	NotifyCenter<Effect> m_ncEffect;// ��Ч֪ͨ����
};

#define gArmatureManager ArmatureManager::Instance()