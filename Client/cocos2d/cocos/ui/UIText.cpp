/****************************************************************************
Copyright (c) 2013-2014 Chukong Technologies Inc.

http://www.cocos2d-x.org

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
****************************************************************************/

#include "ui/UIText.h"

NS_CC_BEGIN

namespace ui {

static const int LABEL_RENDERER_Z = (-1);
    
IMPLEMENT_CLASS_GUI_INFO(Text)

Text::Text():
_touchScaleChangeEnabled(false),
_normalScaleValueX(1.0f),
_normalScaleValueY(1.0f),
_fontName("Thonburi"),
_fontSize(10),
_onSelectedScaleOffset(0.5),
_labelRenderer(nullptr),
_labelRendererAdaptDirty(true)
{
}

Text::~Text()
{
	//if ( _labelRenderer )
	//{
	//	this->removeProtectedChild(_labelRenderer);
	//}
}

Text* Text::create()
{
    Text* widget = new Text();
    if (widget && widget->init())
    {
        widget->autorelease();
        return widget;
    }
    CC_SAFE_DELETE(widget);
    return nullptr;
}

bool Text::init()
{
    if (Widget::init())
    {
        return true;
    }
    return false;
}
    
Text* Text::create(const std::string &textContent, const std::string &fontName, int fontSize)
{
    Text *text = new Text;
    if (text && text->init(textContent, fontName, fontSize)) {
        text->autorelease();
        return text;
    }
    CC_SAFE_DELETE(text);
    return nullptr;
}
    
bool Text::init(const std::string &textContent, const std::string &fontName, int fontSize)
{
    bool ret = true;
    do {
        if (!Widget::init()) {
            ret = false;
            break;
        }
        this->setText(textContent);
        this->setFontName(fontName);
        this->setFontSize(fontSize);
    } while (0);
    return ret;
}

void Text::initRenderer()
{
    _labelRenderer = LabelTTF::create();
    addProtectedChild(_labelRenderer, LABEL_RENDERER_Z, -1);
}

void Text::enableShadow(const Color4B& shadowColor/* = Color4B::BLACK*/,const Size &offset/* = Size(2,-2)*/, int blurRadius/* = 0*/)
{
	_labelRenderer->enableShadow(shadowColor,offset,blurRadius);
}

void Text::enableOutline(const Color4B& outlineColor,int outlineSize /*= -1*/)
{
	_labelRenderer->enableOutline(outlineColor,outlineSize);
}

void Text::enableGlow(const Color4B& glowColor)
{
	_labelRenderer->enableGlow(glowColor);
}

void Text::setText(const std::string& text)
{
    _labelRenderer->setString(text);
    updateContentSizeWithTextureSize(_labelRenderer->getContentSize());
    _labelRendererAdaptDirty = true;
}

const std::string& Text::getStringValue()
{
    return _labelRenderer->getString();
}

ssize_t Text::getStringLength()
{
    return _labelRenderer->getString().size();
}

void Text::setFontSize(int size)
{
    _fontSize = size;
    _labelRenderer->setSystemFontSize(size);
    updateContentSizeWithTextureSize(_labelRenderer->getContentSize());
    _labelRendererAdaptDirty = true;
}
    
int Text::getFontSize()
{
    return _fontSize;
}

void Text::setFontName(const std::string& name)
{
    _fontName = name;
    _labelRenderer->setSystemFontName(name);
    updateContentSizeWithTextureSize(_labelRenderer->getContentSize());
    _labelRendererAdaptDirty = true;
}
    
const std::string& Text::getFontName()
{
    return _fontName;
}

void Text::setTextAreaSize(const Size &size)
{
    _labelRenderer->setDimensions(size.width,size.height);
    updateContentSizeWithTextureSize(_labelRenderer->getContentSize());
    _labelRendererAdaptDirty = true;
}
    
const Size& Text::getTextAreaSize()
{
    return _labelRenderer->getDimensions();
}

void Text::setTextHorizontalAlignment(TextHAlignment alignment)
{
    _labelRenderer->setHorizontalAlignment(alignment);
    updateContentSizeWithTextureSize(_labelRenderer->getContentSize());
    _labelRendererAdaptDirty = true;
}
    
TextHAlignment Text::getTextHorizontalAlignment()
{
    return _labelRenderer->getHorizontalAlignment();
}

void Text::setTextVerticalAlignment(TextVAlignment alignment)
{
    _labelRenderer->setVerticalAlignment(alignment);
    updateContentSizeWithTextureSize(_labelRenderer->getContentSize());
    _labelRendererAdaptDirty = true;
}
    
TextVAlignment Text::getTextVerticalAlignment()
{
    return _labelRenderer->getVerticalAlignment();
}

void Text::setTouchScaleChangeEnabled(bool enable)
{
    _touchScaleChangeEnabled = enable;
}
    
bool Text::isTouchScaleChangeEnabled()
{
    return _touchScaleChangeEnabled;
}

void Text::onPressStateChangedToNormal()
{
    if (!_touchScaleChangeEnabled)
    {
        return;
    }
    _labelRenderer->setScaleX(_normalScaleValueX);
    _labelRenderer->setScaleY(_normalScaleValueY);
}

void Text::onPressStateChangedToPressed()
{
    if (!_touchScaleChangeEnabled)
    {
        return;
    }
    _labelRenderer->setScaleX(_normalScaleValueX + _onSelectedScaleOffset);
    _labelRenderer->setScaleY(_normalScaleValueY + _onSelectedScaleOffset);
}

void Text::onPressStateChangedToDisabled()
{
    
}

void Text::updateFlippedX()
{
     if (_flippedX)
    {
        _labelRenderer->setScaleX(-1.0f);
    } 
    else
    {
        _labelRenderer->setScaleX(1.0f);
    }
}
    
void Text::updateFlippedY()
{
    if (_flippedY)
    {
        _labelRenderer->setScaleY(-1.0f);
    } 
    else
    {
        _labelRenderer->setScaleY(1.0f);
    }
}

void Text::onSizeChanged()
{
    Widget::onSizeChanged();
    _labelRendererAdaptDirty = true;
}
    
void Text::adaptRenderers()
{
    if (_labelRendererAdaptDirty)
    {
        labelScaleChangedWithSize();
        _labelRendererAdaptDirty = false;
    }
}

const Size& Text::getVirtualRendererSize() const
{
    return _labelRenderer->getContentSize();
}

Node* Text::getVirtualRenderer()
{
    return _labelRenderer;
}

void Text::labelScaleChangedWithSize()
{
    if (_ignoreSize)
    {
        _labelRenderer->setDimensions(0,0);
        _labelRenderer->setScale(1.0f);
        _normalScaleValueX = _normalScaleValueY = 1.0f;
    }
    else
    {
        _labelRenderer->setDimensions(_size.width,_size.height);
        Size textureSize = _labelRenderer->getContentSize();
        if (textureSize.width <= 0.0f || textureSize.height <= 0.0f)
        {
            _labelRenderer->setScale(1.0f);
            return;
        }
        float scaleX = _size.width / textureSize.width;
        float scaleY = _size.height / textureSize.height;
        _labelRenderer->setScaleX(scaleX);
        _labelRenderer->setScaleY(scaleY);
        _normalScaleValueX = scaleX;
        _normalScaleValueY = scaleY;
    }
    _labelRenderer->setPosition(_contentSize.width / 2.0f, _contentSize.height / 2.0f);
}

std::string Text::getDescription() const
{
    return "Label";
}
    
void Text::updateTextureColor()
{
    updateColorToRenderer(_labelRenderer);
}

void Text::updateTextureOpacity()
{
    updateOpacityToRenderer(_labelRenderer);
}

void Text::updateTextureRGBA()
{
    updateRGBAToRenderer(_labelRenderer);
}

Widget* Text::createCloneInstance()
{
    return Text::create();
}

void Text::copySpecialProperties(Widget *widget)
{
    Text* label = dynamic_cast<Text*>(widget);
    if (label)
    {
        setFontName(label->_fontName);
        setFontSize(label->getFontSize());
        setText(label->getStringValue());
        setTouchScaleChangeEnabled(label->_touchScaleChangeEnabled);
        setTextHorizontalAlignment(label->_labelRenderer->getHorizontalAlignment());
        setTextVerticalAlignment(label->_labelRenderer->getVerticalAlignment());
        setTextAreaSize(label->_labelRenderer->getDimensions());
    }
}

}

NS_CC_END
