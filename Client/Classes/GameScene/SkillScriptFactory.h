/***
 * ģ�飺SkillScriptFactory
 * ���ߣ�������
 * ʱ�䣺2015-07-2
 * ˵���������߼�����
 * ÿһ�����͵ļ��ܶ�����һ�����ܴ���Ų�����ͬ�������ʹ���Ų���ͬ
 */

#ifndef __SkillScriptFactory_h_
#define __SkillScriptFactory_h_

#include "SkillScript.h"

class SkillScriptFactory
{
public:
	SkillScriptFactory();
	~SkillScriptFactory();

	/* Name		��CreateScript
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ���������߼��������
	 * Param	: type ��������
	 * Return	: SkillScript*
	 */
	static SkillScript* CreateScript(SkillType type);
};

#endif //__SkillScriptFactory_h_