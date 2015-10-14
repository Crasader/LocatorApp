#include "StringConverter.h"

// ---------------------------------------------------------------------------------------------------------------------------------------
// �ַ�ת����
string StringConverter::toString( const int& vaule, unsigned short width, char fill,  std::ios::fmtflags flags )
{
	std::ostringstream outStream;

	outStream.width(width);
	outStream.fill(fill);
	if(flags)
	{
		outStream.setf(flags);
	}

	outStream<<vaule;
	return outStream.str();
	
}

// ---------------------------------------------------------------------------------------------------------------------------------------
// ����ת�ַ�
string StringConverter::toString( const unsigned int& vaule, unsigned short width, char fill, std::ios::fmtflags flags )
{
	std::ostringstream outStream;
	outStream.width(width);
	outStream.fill(fill);
	if(flags)
	{
		outStream.setf(flags);
	}

	outStream<<vaule;
	return outStream.str();

}

// ---------------------------------------------------------------------------------------------------------------------------------------
// ������ת�ַ�
string StringConverter::toString( const short& vaule, unsigned short width, char fill,  std::ios::fmtflags flags )
{
	std::ostringstream outStream;
	outStream.width(width);
	outStream.fill(fill);
	if(flags)
	{
		outStream.setf(flags);
	}

	outStream<<vaule;
	return outStream.str();
}

// ---------------------------------------------------------------------------------------------------------------------------------------
// ����ת�ַ�
string StringConverter::toString( const unsigned short& vaule, unsigned short width, char fill, std::ios::fmtflags flags )
{
	std::ostringstream outStream;
	outStream.width(width);
	outStream.fill(fill);
	if(flags)
	{
		outStream.setf(flags);
	}

	outStream<<vaule;
	return outStream.str();

}

// ---------------------------------------------------------------------------------------------------------------------------------------
// ������ת�ַ�
string StringConverter::toString( const long& vaule, unsigned short width, char fill,  std::ios::fmtflags flags )
{
	std::ostringstream outStream;
	outStream.width(width);
	outStream.fill(fill);
	if(flags)
	{
		outStream.setf(flags);
	}

	outStream<<vaule;
	return outStream.str();
}


// ---------------------------------------------------------------------------------------------------------------------------------------
// �޷��ų�����ת�ַ�
string StringConverter::toString( const unsigned long& vaule, unsigned short width, char fill,  std::ios::fmtflags flags )
{
	std::ostringstream outStream;
	outStream.width(width);
	outStream.fill(fill);
	if(flags)
	{
		outStream.setf(flags);
	}

	outStream<<vaule;
	return outStream.str();
}
string StringConverter::toString( const long long& vaule, unsigned short width , char fill,  std::ios::fmtflags flags  )
{
    std::ostringstream outStream;
    outStream.width(width);
    outStream.fill(fill);
    if(flags)
    {
        outStream.setf(flags);
    }

    outStream<<vaule;
    return outStream.str();
}
// ---------------------------------------------------------------------------------------------------------------------------------------
// floatתstring
string StringConverter::toString( const float& vaule, unsigned short precision, unsigned short width, char fill,  std::ios::fmtflags flags )
{
	std::ostringstream outStream;
	outStream.precision(precision);
	outStream.width(width);
	outStream.fill(fill);

	if(flags)
	{
		outStream.setf(flags);
	}

	outStream<<vaule;
	return outStream.str();
}

// ---------------------------------------------------------------------------------------------------------------------------------------
// boolתstring
string StringConverter::toString( bool vaule, bool YesNo )
{
	if(YesNo)
	{
		if(vaule) return "yes";
		else return "no";
	}
	else
	{
		if(vaule) return "true";
		else  return "false";
	}

}

// ---------------------------------------------------------------------------------------------------------------------------------------
// �ַ�����תstring
void StringConverter::toString( const vector<string>& vaule, string& outText )
{

	for( unsigned i =0; i < vaule.size(); i++ )
	{
		outText += vaule[i] + '\n';
	}
}

// �ַ�Mapתstring
void StringConverter::toString( const map<string,string>& vaule, string& outText )
{
	map<string,string>::const_iterator beginIt = vaule.begin();
	map<string,string>::const_iterator endIt = vaule.end();

	while( beginIt != endIt )
	{
		outText += beginIt->second + '\n';
		beginIt++;
	} 
	
}


// ---------------------------------------------------------------------------------------------------------------------------------------
// �ַ�ת����
int StringConverter::toInt( const string& vaule )
{
	std::istringstream inStream(vaule);
	int Ret = 0;
	inStream>>Ret;
	return Ret;
}


// ---------------------------------------------------------------------------------------------------------------------------------------
// �ַ�ת�޷�������
unsigned int StringConverter::toUnsignedInt( const string& vaule)
{
	std::istringstream inStream(vaule);
	unsigned int Ret = 0;
	inStream>>Ret;
	return Ret;
}

// ---------------------------------------------------------------------------------------------------------------------------------------
// �ַ�ת������
short StringConverter::toShort( const string& vaule )
{
	std::istringstream inStream(vaule);
	short Ret = 0;
	inStream>>Ret;
	return Ret;
}


// ---------------------------------------------------------------------------------------------------------------------------------------
// �ַ�ת�޷��Ŷ�����
unsigned short StringConverter::toUnsignedShort( const string& vaule)
{
	std::istringstream inStream(vaule);
	unsigned short Ret = 0;
	inStream>>Ret;
	return Ret;
}

// ---------------------------------------------------------------------------------------------------------------------------------------
// �ַ�ת������
long StringConverter::toLong( const string& vaule )
{
	std::istringstream inStream(vaule);
	long Ret = 0;
	inStream>>Ret;
	return Ret;
}

// ---------------------------------------------------------------------------------------------------------------------------------------
// �ַ�ת�޷��Ŷ�����
unsigned long StringConverter::toUnsignedLong( const string& vaule)
{
	std::istringstream inStream(vaule);
	unsigned long Ret = 0;
	inStream>>Ret;
	return Ret;
}

// ---------------------------------------------------------------------------------------------------------------------------------------
// �ַ�תfloat
float StringConverter::toFloat( const string& vaule)
{
	std::istringstream inStream(vaule);
	float Ret = 0.0f;
	inStream>>Ret;
	return Ret;
}

// ---------------------------------------------------------------------------------------------------------------------------------------
// boolתstring
bool StringConverter::toBool(const string& vaule )
{
	return (vaule == "yes" || vaule == "true" || vaule == "1" );
}

// boolתstring
long long StringConverter::toLongLong( const string& vaule )
{
    std::istringstream inStream(vaule);
    long long Ret = 0;
    inStream>>Ret;
    return Ret;
}

unsigned char StringConverter::toUnsignedChar( const string& vaule )
{
	std::istringstream inStream(vaule);
	unsigned char Ret = 0;
	inStream>>Ret;
	return Ret;
}

