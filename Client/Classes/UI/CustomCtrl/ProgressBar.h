#ifndef __ProgressBar_h_
#define __ProgressBar_h_

#include "cocos2d.h"
#include "ui/CocosGUI.h"
USING_NS_CC;
using namespace std;
using namespace ui;

// ������
#define PRECENT_MAX    100.f

class ProgerssBar : public Node
{
public:
	ProgerssBar();
	~ProgerssBar();

	CREATE_FUNC(ProgerssBar);

	bool init();

	void setTexture(const string& background,const string& progress,const string& cursor = "");

	void update(float dt);

	// ���ý�����ǰ���ٶ�
	inline void SetMoveSpeed(float speed){ m_fSpeed = speed; }
	inline float SetMoveSpeed(){ return m_fSpeed; }

	// �����α�
	inline void SetPercent(float percent){ m_fPercent = percent; }
	inline int GetPercent(){ return m_fPercent; }

	// �ж��������Ƿ����
	inline bool IsComplete(){ return m_fCursor >= PRECENT_MAX; }

	// ���ô�С
	inline const Size& GetSize(){ return m_Size; }
	void SetSize(Size size);

	// ����������ʾ
	void SetText(const string& str);

	void Reset();

protected:
	float	m_fSpeed;	// �����ߵ��ٶ�
	float	m_fCursor;	// �����������ƶ��α� �α�λ�ò��ᳬ����ǰ����
	float	m_fPercent;	// ��ǰ����

	Size	m_Size;		// �������Ĵ�С

	LayerColor* m_pLayerBackGround;	// ��
	LayerColor* m_pLayerProgress;	// ����
	Node*		m_pLoadginBg;		// ��������ͼƬ
	LoadingBar* m_pLoadingBar;		// ������ͼƬ
	Sprite*		m_pImageCursor;		// �α�ͼƬ
	Label*		m_pText;			// ����������
};

#endif