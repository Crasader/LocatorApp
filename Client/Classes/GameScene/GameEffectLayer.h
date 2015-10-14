/***
 * ģ�飺��Ϸ��Ч��
 * ���ߣ�������
 * ʱ�䣺2015-06-19
 * ˵����������Ч��Ч����Ч���������Զ��Ƴ�û�õ���Ч
 */

#ifndef __GameEffectLayer_h_
#define __GameEffectLayer_h_

#include "GameDef.h"
#include "Effect.h"

class GameEffectLayer : public Layer , public Singleton<GameEffectLayer>
{
public:
	GameEffectLayer(){}
	~GameEffectLayer(){}

	void update(float dt){}

protected:
	EffectList m_Effects;
};

#define gEffectLayer GameEffectLayer::Instance()

#endif // __GameEffectLayer_h_