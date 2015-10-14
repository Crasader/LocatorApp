#ifndef __NAMEMANAGER_H_
#define __NAMEMANAGER_H_

#include "GameDef.h"
#include "Singleton.h"
#include <string>
#include <vector>
#include <set>
#include <map>

#define  gStrManager (NameManager::Instance())

typedef std::set<std::string> T_CharSet;

typedef std::map<unsigned char,T_CharSet> T_CharMap;

class NameManager : public Singleton_Auto<NameManager>
{

public:
	NameManager();
	~NameManager();

	bool init();

	void readNames();
	void readSensitiveStrings();

	std::string randomName(int sex);
	int getRandomPos(int size);
	 
	void addSensitiveString(const std::string& msg);
	bool replaceMsgByFilter(std::string* msg);    //���ؼ���תΪ*;
    bool replaceMsgByFilter( std::string& msg ,char* outBuff=NULL,int outLen=0); //�滻���д�,�Ż�ʧ��

	std::string getString(std::string key);  

	std::string getCareerById(int id);
    std::string getClientString(int key) const;
 

public:
	std::vector<std::string> _surNameMale;   //���գ�
	std::vector<std::string> _NameMale;       //����1��
	std::vector<std::string> _surNameFamale;    //Ů�գ�
	std::vector<std::string> _NameFamale;    //Ů��2��

	std::set<std::string> _filterNameString;    //���дʵļ���;
    T_CharMap _filterNameStringArr; // �����ֽ��������6�ֽ�

	std::map< std::string , std::string > _stringsMap;
};
 



#endif