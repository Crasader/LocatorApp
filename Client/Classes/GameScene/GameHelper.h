
/***
 * ģ�飺GameHelper
 * ���ߣ�������
 * ʱ�䣺2015-7-7
 * ˵������Ϸ������ع���
 */

#include "Singleton.h"
#include "UI/WaitMessageUI.h"

class GameHelper : public Singleton_Auto<GameHelper>
{
public:
	GameHelper();
	~GameHelper();

public:
	/* Name		��IsDoubleClicked
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: �ж��Ƿ�Ϊ˫��
	 * Param	: void
	 * Return	: bool ˫������true�����򷵻�false
	 */
	bool IsDoubleClicked();

	/* Name		��setWaitMsgLayer
	 * Author	��TangBo
	 * Date		: 2015-07-16
	 * Desc		: ��ʾ�͹رյȴ�����
	 * Param	: _show 
	 * Return	: 
	 */
	void SetWaitMsgLayer(bool _show);

};

#define gGameHelper GameHelper::Instance()