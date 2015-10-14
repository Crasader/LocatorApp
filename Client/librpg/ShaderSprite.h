/***
 * ģ�飺shader ����
 * ���ߣ�sndy
 * ʱ�䣺2015-07-28
 * ˵���������ҶȾ���
 */

#pragma once
#include "cocos2d.h"

USING_NS_CC;

class ShaderSprite : public Sprite
{
public:
	ShaderSprite();
	~ShaderSprite();

	CREATE_FUNC(ShaderSprite);

	static ShaderSprite* createWithFile(const char * filename, float _rate = 1.5f);
	static ShaderSprite* createWithTexture(Texture2D* texture,float _rate = 1.5f);
	static ShaderSprite* createWithTexture(Texture2D *texture, const Rect& rect, float _rate = 1.5f);

	const GLchar* getShaderConfig();

	void initShader(float rate);
	void setTexture(const std::string &filename,float _rate = 1.5f );
	void setTexture(Texture2D* texture,float _rate = 1.5f );
	//�ı�Ҷ�ϵ�� Ĭ���ǻ�ԭ  ����1Ϊ���� С��1λ��ɫ
	void setGrayRate(float _rate = 1.0f);
	void setBackgroundNotification();
	void draw(Renderer *renderer, const kmMat4 &transform, bool transformUpdated) override;
	
protected:
	void onDraw(const kmMat4 &transform, bool transformUpdated);

	float			m_fGreyRate;               // �Ҷ�ϵ�� �ٷֱ�ֵ
	CustomCommand	_renderCommand;
};