#ifndef __CTRLALLOCATOR__
#define __CTRLALLOCATOR__

#include <vector>
#include <map>
#include <string>
#include "Singleton.h"
#include "ui/CocosUI.h"

USING_NS_CC;
using std::map;
using std::string;

/************************************************************************/
/* ͨ����Դ�����࣬��һЩ��ɢ����ͼ���ϵ�һ��UI�������淽���ȡ
/************************************************************************/
class CCTrlAllocator : public Singleton<CCTrlAllocator>
{
public:
	CCTrlAllocator();
	~CCTrlAllocator();

	bool Initialize();
	void Release();

	Widget* LoadCtrl(const string &name);
private:
	map <string, Widget*>	m_mpTemplateCtrls;
	Widget*					m_pContainer;
};


#define gCtrlAllocator CCTrlAllocator::Instance()

#endif