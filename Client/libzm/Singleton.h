/***
 * ���ߣ�������
 * ʱ�䣺2015-06-19
 * ˵��������ģ���� 
 */

#ifndef __Singleton_h_
#define __Singleton_h_

#include <memory>

/***
 * ���ߣ�������
 * ʱ�䣺2015-06-19
 * ˵��������ģ���� ��Ҫ�ֶ�����Destroy�ӿ��ͷ�
 */
template<class T>
class Singleton
{
public:
	Singleton(){}
	virtual ~Singleton(){}

	static T* Instance(){
		if ( s_pInstance )
		{
			return s_pInstance;
		}

		s_pInstance = new T;

		return s_pInstance;
	}

	static void Destroy(){
		if ( s_pInstance )
		{
			delete s_pInstance;
			s_pInstance = 0x0;
		}
	}

private:
	static T* s_pInstance;
};

template< class T > 
T* Singleton<T>::s_pInstance = 0x0;


/***
 * ���ߣ�������
 * ʱ�䣺2015-06-19
 * ˵�����Զ������ĵ���ģ�� �����ֶ��ͷ�
 */
template <typename T>
class Singleton_Auto
{
public:
	Singleton_Auto(){}
	virtual ~Singleton_Auto(){}

	static T* Instance()
	{
		if ( s_pInstance.get() )
		{
			return s_pInstance.get();
		} 

		s_pInstance = std::auto_ptr<T>(new T);

		return s_pInstance.get();
	}

private:
	static std::auto_ptr<T>		s_pInstance;
};

template< class T > std::auto_ptr<T>  Singleton_Auto<T>::s_pInstance(0x0);

#endif // __Singleton_h_
