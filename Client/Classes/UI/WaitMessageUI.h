#pragma once

#include "cocos2d.h"

class  WaitMessageUI:public cocos2d::Layer
{
public:

	bool  init();

	void  onExit();

	void  onEnter();

	//���ó�ʱ��Ӧʱ��
	inline void  reSetTimeout();


	static  WaitMessageUI * getInstance()
	{
		if(m_waitMsgPtr)
			m_waitMsgPtr = new WaitMessageUI();
		return m_waitMsgPtr;
	}

	/* ��ʾ�ȴ�����
	 * param: _isshow   
	 *      true:��ʾ�ȴ�ʱ��
	 *      false:�رյȴ�ʱ��
	 * ret  :    */
	void   setShow(bool _isshow = true);

	//�ͷű���̬����
	inline void   releaseFunc()
	{
		if(m_waitMsgPtr)
		{
			delete m_waitMsgPtr;
			m_waitMsgPtr = nullptr;
		}
	}

	//���µȴ��ӳ�
	void    update(float fd);

protected:
	WaitMessageUI();
	~WaitMessageUI();

private:

	static WaitMessageUI * m_waitMsgPtr;

	int                    m_timeout;                   //�ȴ���ʱʱ��

	bool                   m_show;                      //��ǰ�Ƿ���ʾ
};