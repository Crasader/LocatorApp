/* Name		��StringUtil
 * Author	��YueLiangYou
 * Date		: 2015-06-24
 * Desc		: �ַ���ͨ�ô���
 * Param	: none
 * Return	: void
 */

#ifndef StringUtils_h__
#define StringUtils_h__

#include "cocos2d.h"
USING_NS_CC;
using namespace std;

class StringUtil
{
public:

    /** ���ַ���ת��Ϊ��ɫ */
    static Color3B StringToColor( const string& str,const string& delimd="," );

	/** ���ַ���ת��Ϊ���� */
	static Rect StringToRect( const string& str,const string& delimd="," );

	/** �ָ��ַ�����strΪԴ�ַ�����delimdΪ�ָ�����desΪ������ַ������� */
	static int StringSplit( const string& str,const string& delimd,vector<string>& des );
    static int StringSplit( const string& str,const string& delimd,list<string>& des );

    static void ReplaceStr(char* buf,std::string str,std::string pattern,std::string dstPattern,int count=-1);
    static void ReplaceStr(std::string& str,std::string pattern,std::string dstPattern,int count=-1);

	/*ȥ�ո�*/
	static void StringTrim(string& str,char ch=' ');

    //תСд
    static void StringToLower(string& str);

    //ת��д
    static void StringToUper(string& str);

	/* Name		��StringCut
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: �ַ����ضϺ��������ֽضϣ�һ������Ϊ�����֣�Ӣ����ĸ������һ���� 
	 * Param	: str Դ�ַ�����max ���������tail �ضϺ����Ӽ�β��
	 * Return	: ��ͼ����
	 */
	static string StringCut(const string& str,int max,const string& tail);

	/* Name		��StringCutFileName
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ȥ���ļ�����׺
	 * Param	: none
	 * Return	: �ļ���������׺
	 */
	static string StringCutFileName(const string& fileName);
};


#endif // StringUtils_h__
