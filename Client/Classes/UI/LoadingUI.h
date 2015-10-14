/***
 * ģ�飺���ؽ���
 * ���ߣ�sndy
 * ʱ�䣺2015-07-21
 * ˵�������غ͸��½���
 */
#pragma once

#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include "Singleton.h"


//���ؽ������ʾ����
enum LoadType
{
	UPDATE_TYPE,
	LOADRES_TYPE,

};

class LoadingUI : public cocos2d::Layer,public Singleton<LoadingUI>
{
public:
	typedef void (Ref::*LoadEnd_Event)();
public:
	LoadingUI();
	~LoadingUI();

	/**
	 * Name : initWidget
	 * Des  : ��ʼ���������ָ��
	 * Param:
	 */
	void initWidget();

	/**
	 * Name : setPercent
	 * Des  : ���ý�������ָ��λ��
	 * Param: _percent ��ǰ���ȵ����ֵ
	 *        _fd      ��֡����
	 */
	inline void SetPercent(float _percent, float _fd = 4.f){ m_fPercent = _percent; m_fd = _fd; }

	/**
	 * Name : IsActive
	 * Des  : ���ؽ����Ƿ�����ʾ
	 * Param: none
	 * Ret  : ��ʾ true, �ر� false
	 */
	inline bool IsActive(){ return m_bActive; }

	/**
	 * Name : Show
	 * Des  : ��ʾ���ؽ���
	 * Parma: _type ��ǰҪ��ʾ�ļ��ؽ�������
	 *        _idu  ��Ҫ���صĽ���IDU
	 */
	//void Show(LoadType _type, int _idu, ...);

		/**
	 * Name : Show
	 * Des  : ��ʾ���ؽ���
	 * Parma: _type ��ǰҪ��ʾ�ļ��ؽ�������
	 */
	void Show(LoadType _type);

	/**
	 * Name : update
	 * Des  : ���¼��ؽ���
	 * Parma: fd ʱ����
	 */
	void update(float dt);

	/**
	 * Name : Close
	 * Des  : �رռ��ؽ���
	 * Param:
	 */
	void Close();

	//���ü��غ�ص�
	void	addLoadEndEvent(Ref* pListener, LoadEnd_Event loadEnd_event);
	void	ClearLoadEndEvent();
	void	LoadEndEvent();

private:
	bool						m_bActive;        //���ؽ���״ֵ̬,Ĭ��ֵ��false, ��ʾ״̬��true
	cocos2d::ui::Widget*		m_pWidget;		  //����ָ��
	float						m_fCursor;        //��ǰ�Ľ���ֵ�α꣬�α�ᚰ֡���е�֡����
	float						m_fPercent;		  //��ǰ�Ľ���ֵ������Ϊ0-100
	float						m_fd;             //���е�֡����
	
	std::string					m_showtips;       //������ʾ�ַ�
	cocos2d::ui::Text*			m_lable;          //������ʾ��ǩ
	cocos2d::ui::Text*			m_tipslable;      //������ʾ��ǩ
	cocos2d::ui::LoadingBar*	m_loadingbar;     //������ָ��
	cocos2d::ui::ImageView*		m_light;          //���ȸ���Ч��

	
	//std::vector<int>			m_iduV;           //����صĽ���IDU
	Ref*						_loadEndEventListener;
	LoadEnd_Event				_loadEndEventCallBack;
};


#define gLoadingUI LoadingUI::Instance()