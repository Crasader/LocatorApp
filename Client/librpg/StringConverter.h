#ifndef __StringConverter_H__
#define __StringConverter_H__

#include <string>
#include <vector>
#include <map>
#include <list>
#include <sstream>

using namespace std;

class StringConverter
{
public:

	// ����ת�ַ�
	static string toString( const int& vaule, unsigned short width = 0, char fill = ' ',  std::ios::fmtflags flags = std::ios::fmtflags(0) );

	// �޷�������ת�ַ�
	static string toString( const unsigned int& vaule, unsigned short width = 0, char fill = ' ',  std::ios::fmtflags flags = std::ios::fmtflags(0) );

	// ������ת�ַ�
	static string toString( const short& vaule, unsigned short width = 0, char fill = ' ',  std::ios::fmtflags flags = std::ios::fmtflags(0) );

	// �޷��Ŷ�����ת�ַ�
	static string toString( const unsigned short& vaule, unsigned short width = 0, char fill = ' ',  std::ios::fmtflags flags = std::ios::fmtflags(0) );

	// ������ת�ַ�
	static string toString( const long& vaule, unsigned short width = 0, char fill = ' ',  std::ios::fmtflags flags = std::ios::fmtflags(0) );

	// �޷��ų�����ת�ַ�
	static string toString( const unsigned long& vaule, unsigned short width = 0, char fill = ' ',  std::ios::fmtflags flags = std::ios::fmtflags(0) );

    // �޷��ų�����ת�ַ�
    static string toString( const long long& vaule, unsigned short width = 0, char fill = ' ',  std::ios::fmtflags flags = std::ios::fmtflags(0) );
	
	// floatתstring
	static string toString( const float& vaule, unsigned short precision, unsigned short width = 0, char fill = ' ',  std::ios::fmtflags flags = std::ios::fmtflags(0));

	// boolתstring
	static string toString( bool vaule, bool YesNo );

	// �ַ�����תstring
	static void toString( const vector<string>& vaule, string& outText );

	// �ַ�Mapתstring
	static void toString( const map<string,string>& vaule, string& outText );

	// �ַ�ת����
	static int toInt( const string& vaule);

	// �ַ�ת�޷�������
	static unsigned int toUnsignedInt( const string& vaule);

	// �ַ�ת������
	static short toShort( const string& vaule);

	// �ַ�ת�޷��Ŷ�����
	static unsigned short toUnsignedShort( const string& vaule);

	// �ַ�ת�޷��Ŷ�����
	static unsigned char toUnsignedChar( const string& vaule);

	// �ַ�ת������
	static long toLong( const string& vaule);

	// �ַ�ת�޷��ų�����
	static unsigned long toUnsignedLong( const string& vaule);

	// �ַ�תfloat
	static float toFloat( const string& vaule);

	// boolתstring
	static bool toBool( const string& vaule );

    // boolתstring
    static long long toLongLong( const string& vaule );

};


#endif // __StringConverter_H__
