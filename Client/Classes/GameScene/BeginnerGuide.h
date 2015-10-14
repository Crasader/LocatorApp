#ifndef __BEGINNER_GUIDE_H__
#define __BEGINNER_GUIDE_H__

#include "GameDef.h"
#include "db.h"
#include "BeginnerGuideLayer.h"

// ��������ģʽ
enum GuideMode
{
	GuideMode_Common,	// ��ͨģʽ����
	GuideMode_Force,	// ǿ��ģʽ����
	GuideMode_Move,		// �ƶ�����
	GuideMode_Skill,	// �¼���ѧϰ����
};

class BeginnerGuide
{
public:
	BeginnerGuide();
	~BeginnerGuide();

public:
	/* Name		��Update
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ����������
	 * Param	: dt ʱ���
	 * Return	: void
	 */
	void Update(float dt);

	/* Name		��IsGuideActive
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ����������Ƿ���
	 * Param	: dataid ����������id
	 * Return	: true ������false δ����
	 */
	bool IsGuideActive(int dataid);

	/* Name		��OpenGuide
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ����������
	 * Param	: dataid ����������ID
	 * Return	: void
	 */
	void OpenGuide(int dataid);

	/* Name		��OpenGuide
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ����������
	 * Param	: pData ����������
	 * Return	: void
	 */
	void OpenGuide(GuideCfg* pData);

	/* Name		��CloseGuide
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: �ر�ָ����������
	 * Param	: dataid ����������id
	 * Return	: void
	 */
	void CloseGuide(int dataid);

	/* Name		��CloseGuide
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: �ر����е�������
	 * Param	: none
	 * Return	: void
	 */
	void CloseGuide();
	
	/* Name		��Initialize
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ��ʼ����������
	 * Param	: none
	 * Return	: void
	 */
	void Initialize();

	/* Name		��Exit
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: �˳�����
	 * Param	: none
	 * Return	: void
	 */
	void Exit();

protected:
	vector<int>					m_listID;			// ��ɹ�����������ID��¼
	vector<BeginnerGuideLayer*>	m_listGuideUI;		// ��ǰ�򿪵���������UI����
};

#endif