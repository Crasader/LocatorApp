
#ifndef  _COMMONDEF_H_
#define  _COMMONDEF_H_

#include "cocos2d.h"
#include "StringDef.h"
#include "GameScene/ItemType.h"
#include "CoCosAudioManager.h"

#define Name_Wrap_Len	12			// ��Ҫʡ�ԺŴ�������ֳ���

//��ǩ�Ͱ�ť�����С��ɫ(FontSize40,FontColor_ffe5b4)
//���̧ͷ��(FontSize36 FontColor_eac184)
//��������FontSize40��FontColor_eac184��
//ȦȦ��ʾ����(FontSize30,FontColor_ffe5b4)
//��ɫ����(FontSize36 FontColor_6a6a6a)
//��ɫ��ʾ�֣�FontSize36��FontColor_fff9ea��
//�μ�������⣨FontSize40 FontColor_ffe5b4��

#define FontSize28		(28)
#define FontSize30		(30)
#define FontSize36		(36)
#define FontSize40		(40)

#define FontColor_ffe5b4		Color3B(0xff, 0xe5, 0xb4)
#define FontColor_eac184		Color3B(0xea, 0xc1, 0x84)
#define FontColor_fff9ea		Color3B(0xff, 0xf9, 0xea)
#define FontColor_6a6a6a		Color3B(0x6a, 0x6a, 0x6a)
#define FontColor_70563d		Color3B(0x70, 0x56, 0x3d)

/*icon ·������*/
#define ICON_PATH_ITEM			"assets/ui/icon/item/"		/*��Ʒ*/
#define ICON_PATH_DROP			"assets/ui/icon/drop/"		/*������Ʒ*/
#define ICON_PATH_HEAD			"assets/ui/icon/head/"		/*ͷ��*/
#define ICON_PATH_EXPRESSION	"assets/ui/Expression/"		/*����*/
#define ICON_PATH_LOCALE		"assets/ui/icon/local/"		/*ͷ��*/

/*��Ʒ��Ч·��*/
#define EFFECT_PATH_DROP         "assets/effect/"        


#define INT_TO_STRING(val)       String::createWithFormat("%d", val)->getCString()
#define FORMAT_TO_STRING(fmt,...)       String::createWithFormat(fmt, ##__VA_ARGS__ )->getCString()

#define skill_cd_path		("assets/ui/skill/cd.png")
#define team_head_cd_path	("assets/ui/MainUIFight/img_duiyouxuetiao.png")
static const char *arrCareerFlags[] = {"flag_warrior", "flag_magacine", "flag_archer"};
static Color3B arrPKColor[6] = {Color3B(255, 255, 255), Color3B(166, 166, 166), Color3B(255, 0, 0), Color3B(0, 0, 255), Color3B(0, 255, 0), Color3B(255, 255, 0)};
#define CAREER_TEXT(T) arrCareerFlags[T - 1]

#define GetIntegerToXML cocos2d::CCUserDefault::getInstance()->getIntegerForKey
#define SetIntegerToXML cocos2d::CCUserDefault::getInstance()->setIntegerForKey
#define GetStringToXML cocos2d::CCUserDefault::getInstance()->getStringForKey
#define SetStringToXML cocos2d::CCUserDefault::getInstance()->setStringForKey
#define GetBoolToXML cocos2d::CCUserDefault::getInstance()->getBoolForKey
#define SetBoolToXML cocos2d::CCUserDefault::getInstance()->setBoolForKey

enum EquipAttribute
{
	AttributeID = 0,
	AttributeValue,
	AttributeType,
	AttributeFactor,
};


/************************************************************************************
			�Թ����ı����а�װ������ָ�����ȵ��� ... ����
			nWrapStartLen��ָ���ĳ���
************************************************************************************/
inline string WrapLongName(const string &strName, unsigned nWrapStartLen = Name_Wrap_Len, const string &strReplaceLonger = "...")
{
	int i = 0;
	int nLen = nWrapStartLen;
	while (strName[i] && nLen >= 0)
	{
		if ((strName[i] & 0xc0) != 0x80)
		{
			nLen -= ((strName[i + 1] == 0 || (strName[i + 1] & 0xc0) != 0x80) ? 1 : 2);
		}
		i++;
	}
	if (nLen >= 0)
	{
		return strName;
	}

	string strTmp = strName.substr(0, i - 1);
	strTmp += strReplaceLonger;

	return strTmp;
}

#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
inline std::string AnsiToUtf8(std::string strAnsi)
{
	std::string ret = "";
	if (strAnsi.length() > 0)
	{	
		int nWideStrLength = MultiByteToWideChar(CP_ACP, 0, strAnsi.c_str(), -1, NULL, 0);
		WCHAR* pwszBuf = (WCHAR*)malloc((nWideStrLength+1)*sizeof(WCHAR));
		memset(pwszBuf, 0, (nWideStrLength+1)*sizeof(WCHAR));
		MultiByteToWideChar(CP_ACP, 0, strAnsi.c_str(), -1, pwszBuf, (nWideStrLength+1)*sizeof(WCHAR));

		int nUtf8Length = WideCharToMultiByte( CP_UTF8,0,pwszBuf,-1,NULL,0,NULL,FALSE );
		char* pszUtf8Buf = (char*)malloc((nUtf8Length+1)*sizeof(char));
		memset(pszUtf8Buf, 0, (nUtf8Length+1)*sizeof(char));

		WideCharToMultiByte(CP_UTF8, 0, pwszBuf, -1, pszUtf8Buf, (nUtf8Length+1)*sizeof(char), NULL, FALSE);
		ret = pszUtf8Buf;

		free(pszUtf8Buf);
		free(pwszBuf);
	}
	return ret;
}
#else
inline std::string AnsiToUtf8(std::string strAnsi)
{
	return strAnsi;
}
#endif

inline int StringSplit( const string& str,const string& delimd,vector<string>& des )
{
	size_t start = 0;
	size_t pos = 0;

	if (str.empty())
		return 0;

	int delimdCount=0;
	for( unsigned int i = 0; ; i++ )
	{
		if( pos == str.npos )	break;

		pos = str.find(delimd,start);
		if( pos != str.npos )
			delimdCount++;
		des.push_back(str.substr( start, pos - start ));
		start = pos+delimd.size();
	}

	return delimdCount;
}

inline int StringSplitToInt( const string& str,const string& delimd,vector<int>& des )
{
	size_t start = 0;
	size_t pos = 0;

	if (str.empty())
		return 0;

	int delimdCount=0;
	for( unsigned int i = 0; ; i++ )
	{
		if( pos == str.npos )	break;

		pos = str.find_first_of(delimd,start);
		if( pos != str.npos )
			delimdCount++;
		des.push_back(atoi(str.substr( start, pos - start ).c_str()));
		start = pos+delimd.size();
	}

	return delimdCount;
}

inline void string_trim(string& str,char c = ';')
{
	for (string::iterator itr =str.begin(); itr != str.end(); )
	{
		if ( *itr == c )
		{
			*itr = ',';
		}
		++itr;
	}
}

//���ֹ���
inline string StringNumFilter(const string& str)
{
	string strResult;
	int intResult;
	char charRet[10] = {0};
	char c;

	for (size_t i=0; i<str.length(); ++i)
	{
		c = str.at(i);
		if ( c>='0' && c<='9')
		{
			strResult.push_back(c);
		}
	}
	intResult = atoi(strResult.c_str());
	if (intResult == 0)
	{
		return "";
	}
	sprintf(charRet,"%d",intResult);
	return charRet;
}

//formatType=1 : ת�ɷ���; formatType=2 : ת��ʱ��;formatType=3 : ת��ʱ����
inline string SecondsToTimeDes(int seconds,int formatType)
{
	int hour = seconds/3600;
	int minute = (seconds%3600)/60;
	int second = (seconds%3600)%60;
	if (formatType == 1)
	{
		return CCString::createWithFormat(STR_Sale_RemainTime1.c_str(),minute,second)->getCString();
	}
	else if (formatType == 2)
	{
		return CCString::createWithFormat(STR_Sale_RemainTime2.c_str(),hour,minute)->getCString();
	}
	else
	{
		return CCString::createWithFormat(STR_Sale_RemainTime3.c_str(),hour,minute,second)->getCString();
	}
}

/*�磺5��->00:05 formatType=1 : ת�ɷ���; formatType=2 : ת��ʱ��;formatType=3 : ת��ʱ����*/
inline string SecondsToTime(int seconds,int formatType)
{
	int hour = seconds/3600;
	int minute = (seconds%3600)/60;
	int second = (seconds%3600)%60;
	if (formatType == 1)
	{
		return CCString::createWithFormat("%02d:%02d",minute,second)->getCString();
	}
	else if (formatType == 2)
	{
		return CCString::createWithFormat("%02d:%02d",hour,minute)->getCString();
	}
	else
	{
		return CCString::createWithFormat("%02d:%02d:%02d",hour,minute,second)->getCString();
	}
}

inline string NumToThousandFormat(const int& num)
{
	string strNum = CCString::createWithFormat("%d",num)->getCString();
	string strThousandFormat;
	size_t numLen = strNum.size()-1;
	for (size_t i=0; i<=numLen; ++i)
	{
		strThousandFormat.push_back(strNum[i]);
		if ((numLen-i)%3==0&&(numLen-i)!=0)
		{
			strThousandFormat.push_back(',');
		}
	}
	return strThousandFormat;
}

inline int GetUtf8ByteNumByFirstWord(unsigned char firstCh)
{
	unsigned char temp = 0x80;
	int num = 0;	
	if(firstCh < 0x80)//ascii code.(0-127)
	{
		return 1;
	}
	while(temp & firstCh)
	{
		num++;
		temp = (temp >> 1);
	}
	return num;
}

//��ȡ��ǰ�ĺ���ʱ��
inline double getMilliSecond()
{
	struct timeval tv;
	memset(&tv, 0, sizeof(tv));
	gettimeofday(&tv, NULL);

	double f = (double)(tv.tv_sec * 1000) + (float)(tv.tv_usec/1000);
	return f;
}

//��ȡ��ǰ����ʱ��
inline double getCurSecond()
{
	struct timeval tv;
	memset(&tv, 0, sizeof(tv));
	gettimeofday(&tv, NULL);

	double f = (double)(tv.tv_sec) + (float)(tv.tv_usec/1000)/1000;
	return f;
}

// �ж��Ƿ������� ashin
inline int is_zh_ch(char p){
	if (p < 127)
		return 0;
	else
		return 1;
}

// ��ȡ�ַ�������ʵ���ȴ��� ashin
inline int getRealStringLength(string str){
	int i = 0;
	int len = str.length();
	int r = 0;
	while (i<=len){
		if (is_zh_ch(str[i])==1){
			r=r+1;
			i=i+3;
		}else{
			r=r+1;
			i=i+1;
		}
	}
	return r;
}

// �������Ե�����
inline string getEquipAttributeName(int jinjie_level,int index,vector<vector<int>> all_attr_vec[])
{
	vector<int> attr_item_id_vec = all_attr_vec[jinjie_level][index];
	AttributeInfoCfg* pData =  AttributeTableData.get(attr_item_id_vec[AttributeID]);
	if (pData!=NULL)
	{
		return pData->name;
	}
	LOGE("equipBase.xlsx attribute:list error, AttributeInfoCfg dont find cfgID:%d",attr_item_id_vec[AttributeID]);
	return NULL;
}

// ������������
inline int getEquipBasicAttribute(int jinjie_level,int index,vector<vector<int>> all_attr_vec[])
{
	vector<int> attr_item_id_vec = all_attr_vec[jinjie_level][index];
	return attr_item_id_vec[AttributeValue];
}

// ���������ӳ�ϵ��
inline float getEquipAttributeFactor(int jinjie_level,int jinglian_level,int index,vector<vector<int>> all_attr_vec[])
{
	vector<int> attr_item_id_vec = all_attr_vec[jinjie_level][index];
	if (jinglian_level == 0 || attr_item_id_vec[AttributeFactor] == 0)
	{
		return 1.0f;
	}
	float factor_ =  *(&(EquipRefineBonusData.get(jinglian_level)->id)+attr_item_id_vec[AttributeFactor]) / 10000.0f;
	return factor_;
}

// ��������ʾ��ʽ 0ֱ����ʾ 1��ʾ�ٷֱ�
inline int getEquipAttributeDisplayType(int jinjie_level,int index,vector<vector<int>> all_attr_vec[])
{
	vector<int> attr_item_id_vec = all_attr_vec[jinjie_level][index];
	AttributeInfoCfg* pData =  AttributeTableData.get(attr_item_id_vec[AttributeID]);
	int display_type = attr_item_id_vec[AttributeType];
	if (pData!=NULL)
	{
		return *(&(pData->total_display)+display_type);
	}
	LOGE("equipBase.xlsx attribute:list error, AttributeInfoCfg dont find cfgID:%d",attr_item_id_vec[AttributeID]);
	return 0;
}

// �����ӳɺ���ʾ������
inline int getEquipTotalAttribute(int jinjie_level,int jinglian_level,int index,vector<vector<int>> all_attr_vec[])
{
	int basic_value_ = getEquipBasicAttribute(jinjie_level,index,all_attr_vec);
	float factor_ = getEquipAttributeFactor(jinjie_level,jinglian_level,index,all_attr_vec);
	return int(basic_value_* factor_);
}

// �õ����������Ƿ�ı�
inline bool getEquipAtrributeIfChange(int strengthenType/*1���� 2����*/,int jinjie_level/*��ǰ���׵ĵȼ�*/,int jinglian_level/*��ǰ�����ĵȼ�*/,int index,vector<vector<int>> all_attr_vec[])
{
	if (strengthenType == 2)
	{
		int cur_basic_value_ = getEquipBasicAttribute(jinjie_level,index,all_attr_vec);
		int to_basic_value_ = getEquipBasicAttribute(jinjie_level+1,index,all_attr_vec);

		return to_basic_value_!=cur_basic_value_;

	}else if (strengthenType == 1)
	{
		int cur_basic_value_ = getEquipTotalAttribute(jinjie_level,jinglian_level,index,all_attr_vec);
		int to_basic_value_ = getEquipTotalAttribute(jinjie_level,jinglian_level+1,index,all_attr_vec);
		
		return to_basic_value_!=cur_basic_value_;

	}
	return false;
}

// �õ��������Եĸı�
inline string getEquipAtrributeChange(int strengthenType/*1���� 2����*/,int jinjie_level/*��ǰ���׵ĵȼ�*/,int jinglian_level/*��ǰ�����ĵȼ�*/,int index,vector<vector<int>> all_attr_vec[])
{
	int display_type_ = getEquipAttributeDisplayType(jinjie_level,index,all_attr_vec);
	if (strengthenType == 2)
	{
		int zero_basic_value_ = getEquipBasicAttribute(0,index,all_attr_vec);
		int cur_basic_value_ = getEquipBasicAttribute(jinjie_level,index,all_attr_vec);
		int to_basic_value_ = getEquipBasicAttribute(jinjie_level+1,index,all_attr_vec);
		
		if (display_type_ == 0) // ֱ����ʾ
		{
			return FORMAT_TO_STRING("+%d",(to_basic_value_ - cur_basic_value_));
		}else // �ٷֱ���ʾ
		{
			float per_ = (to_basic_value_ - cur_basic_value_)/(zero_basic_value_*1.0f)*100;
			return FORMAT_TO_STRING("+%d%%",(int)per_);
		}
	}else if (strengthenType == 1)
	{
		int zero_basic_value_ = getEquipTotalAttribute(jinjie_level,0,index,all_attr_vec);
		int cur_basic_value_ = getEquipTotalAttribute(jinjie_level,jinglian_level,index,all_attr_vec);
		int to_basic_value_ = getEquipTotalAttribute(jinjie_level,jinglian_level+1,index,all_attr_vec);

		if (display_type_ == 0) // ֱ����ʾ
		{
			return FORMAT_TO_STRING("+%d",(to_basic_value_ - cur_basic_value_));
		}else // �ٷֱ���ʾ
		{
			float per_ = (to_basic_value_ - cur_basic_value_)/(zero_basic_value_*1.0f)*100;
			return FORMAT_TO_STRING("+%d%%",int(per_));
		}
	}
	return "";
}

// �õ�����ǿ������Ҫ�Ľ������
inline int getEquipGoldConsume(int strengthenType/*1���� 2����*/,int jinjie_level/*��ǰ���׵ĵȼ�*/,int jinglian_level/*��ǰ�����ĵȼ�*/,int cfgID)
{
	if (strengthenType == 2)
	{
		vector<int> enhance_money_vec;
		StringSplitToInt(EquipBaseData.get(cfgID)->enhance_money,";",enhance_money_vec);
		return enhance_money_vec[jinjie_level];
	}else if (strengthenType == 1)
	{
		return EquipRefineCostData.get(jinglian_level+1)->money;
	}
	return 0;
}

// �õ�����ǿ������Ҫ�Ĳ��ϸ���
inline int getEquipItemNumebr(int strengthenType/*1���� 2����*/,int jinjie_level/*��ǰ���׵ĵȼ�*/,int jinglian_level/*��ǰ�����ĵȼ�*/,int cfgID)
{
	if (strengthenType == 2)
	{
		vector<int> enhance_item_number_vec;
		StringSplitToInt(EquipBaseData.get(cfgID)->enhance_item_number ,";",enhance_item_number_vec);
		return enhance_item_number_vec[jinjie_level];
	}else if (strengthenType == 1)
	{
		return EquipRefineCostData.get(jinglian_level+1)->item_number;
	}
	return 0;
}

// �õ�����ǿ������Ҫ�Ĳ�������ID
inline int getEquipItemCfgID(int strengthenType/*1���� 2����*/,int jinjie_level/*��ǰ���׵ĵȼ�*/,int jinglian_level/*��ǰ�����ĵȼ�*/,int cfgID)
{
	if (strengthenType == 2)
	{
		return EquipBaseData.get(cfgID)->enhance_item; 
	}else if (strengthenType == 1)
	{
		return EquipRefineCostData.get(jinglian_level+1)->item;
	}
	return 0;
}

#endif // _COMMONDEF_H_

