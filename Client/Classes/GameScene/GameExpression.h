// ��Ϸ���ʽ

#ifndef __GAME_EXPRESSION_H__
#define __GAME_EXPRESSION_H__

#include "GameDef.h"

// �Ų���������
typedef bool (*KeyFunc)(string param);

/* Name		��KeyFuncMapping
 * Author	��YueLiangYou
 * Date		: 2015-07-02
 * Desc		: �ؼ��ֺͽŲ�����ӳ��ṹ
 * Param	: 
 * Return	: 
 */
struct KeyFuncMapping
{
	string	key;
	KeyFunc fn;
};

/* Name		��get_key_value
 * Author	��YueLiangYou
 * Date		: 2015-07-02
 * Desc		: ͨ��key�Ͳ�����ȡ���ִ�н��
 * Param	: key���ؼ��� param �ű�����
 * Return	: ִ�н�� true ��false
 */
bool get_key_value(const string& key,const string& param);

/* Name		��get_exp_value
 * Author	��YueLiangYou
 * Date		: 2015-07-02
 * Desc		: ��ȡһ���ű����ʽ��ֵ
 * Param	: expression �ű����ʽ
 * Return	: ִ�н�� true ��false
 */
bool get_exp_value(const string& expression);

// �ű������б� ����չ

// �ȼ��ﵽ���ټ�[10,20,30]���ﵽ�ȼ�ָ���ȼ� true ������ false
bool game_exp_level(string param);
// ��ǰ���ڵ�ͼ
bool game_exp_mapin(string param);
// ��ɹ���Щ����
bool game_exp_guide(string param);
// ��ǰ�����¼�
bool game_exp_proc_event(string param);
#endif // __GAME_EXPRESSION_H__