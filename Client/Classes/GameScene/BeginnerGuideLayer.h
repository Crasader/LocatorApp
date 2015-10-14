#ifndef __BEGINNER_GUIDE_UI_H__
#define __BEGINNER_GUIDE_UI_H__

#include "GameDef.h"
#include "UI/GameUI.h"
#include "db.h"

// ���������ؼ�ID
enum GuideControlID
{
	GControlID_None,
	GControlID_TaskMain = 1,		// �������������
	GControlID_TaskAccept = 2,		// ��������
	GControlID_TaskSubmit = 3,		// �ύ����
	GControlID_SkillIcon1 = 4,		// ���ܰ�ť
	GControlID_SkillIcon2 = 5,
	GControlID_SkillIcon3 = 6,
	GControlID_SkillIcon4 = 7,
	GControlID_SkillIcon5 = 8,
	GControlID_SkillIcon6 = 9,
	GControlID_SkillIcon7 = 10,
	GControlID_Head = 11,			// ͷ��
	GControlID_MainRole = 12,		// �������ɫ���ܰ�ť
	GControlID_MainBag = 13,		// �����汳��
	GControlID_MainStrength = 14,	// ������ǿ�����ܰ�ť
	GControlID_MainPet = 15,		// ��������﹦�ܰ�ť
	GControlID_MainGuild = 16,		// �����湫�Ṧ�ܰ�ť
	GControlID_MainFriend = 17,		// ��������ѹ��ܰ�ť
	GControlID_MainArchi = 18,		// ������ɾ͹��ܰ�ť
	GControlID_MainSet = 19,		// ���������ù��ܰ�ť
	GControlID_NewItem = 20,		// װ������Ʒ
	GControlID_Tips = 21,			// ����TIPs�е�ʹ�ð�ť
	GControlID_Strength = 22,		// ǿ������ǿ����ť
	GControlID_BagClose = 23,		// �رձ�����ť
	GControlID_StrClose = 24,		// �ر�ǿ����ť
	GControlID_MainActivity = 25,	// ���������İ�ť
	GControlID_Max,					// ���ֵ
};

struct GuideControlMapping
{
	GuideControlID	id;			// �ؼ�ID
	emIDU			idu;		// UI����ID
	int				type;		// �ؼ����� 0 ��ͨ�ؼ���1 ��Ʒ��2 װ��
	string			name;		// �ؼ�����
};

class BeginnerGuideLayer : public Layer
{
public:
	BeginnerGuideLayer();
	virtual ~BeginnerGuideLayer();
	virtual bool initWithGuideData(GuideCfg* pData);

	/* Name		��getGuideControlRect
	 * Author	��Yueliangyou
	 * Date		: 2015-07-16
	 * Desc		: ��ȡ�ؼ�����
	 * Param	: controlid[in]�ؼ�ID��rect[out] ���� 
	 * Return	: true �ɹ�;false ʧ��
	 */
	virtual bool getGuideControlRect(GuideControlID controlid,Rect& rect);

	/* Name		��getWidgetRect
	 * Author	��Yueliangyou
	 * Date		: 2015-07-16
	 * Desc		: ��ȡ��ͨ�ؼ�����
	 * Param	: idu �Ѵ򿪵Ľ��棬name[in] �ؼ�����rect[out] ���� 
	 * Return	: true �ɹ�;false ʧ��
	 */
	virtual bool getWidgetRect(int idu,const string& name,Rect& rect);

	/* Name		��getItemRect
	 * Author	��Yueliangyou
	 * Date		: 2015-07-16
	 * Desc		: ��ȡ��Ʒ�ؼ�����
	 * Param	: dataid[in] װ��ID��rect[out] ���� 
	 * Return	: true �ɹ�;false ʧ��
	 */
	virtual bool getItemRect(int dataid,Rect& rect);

	/* Name		��getEquipRect
	 * Author	��Yueliangyou
	 * Date		: 2015-07-16
	 * Desc		: ��ȡװ���ؼ�����
	 * Param	: dataid[in] װ��ID��rect[out] ���� 
	 * Return	: true �ɹ�;false ʧ��
	 */
	virtual bool getEquipRect(int dataid,Rect& rect);

	virtual void onComplete();
	virtual void onClose();

	inline GuideCfg*	getGuideData(){ return m_pGuideData; }
	inline float		getDelayTime(){ return m_fDelayTime; }
	inline void			setDelayTime(float dt){ m_fDelayTime = dt; }

protected:
	GuideCfg*	m_pGuideData;
	float		m_fDelayTime;
};

class BeginnerGuideCommon : public BeginnerGuideLayer
{
public:
	BeginnerGuideCommon();
	~BeginnerGuideCommon();
	static BeginnerGuideCommon* create(GuideCfg* pData);

	bool initWithGuideData(GuideCfg* pData);
	bool onTouchBegan(Touch *pTouch, Event *pEvent);
	//�����������˳���ʱ����onExit()�д���һЩ����
	void onExit();

protected:
	ImageView* m_pImage;
};

class BeginnerGuideForce : public BeginnerGuideLayer
{
public:
	BeginnerGuideForce();
	~BeginnerGuideForce();
	static BeginnerGuideForce* create(GuideCfg* pData);

	bool initWithGuideData(GuideCfg* pData);
	bool onTouchBegan(Touch *pTouch, Event *pEvent);
	void update(float delta);
	//�����������˳���ʱ����onExit()�д���һЩ����
	void onExit();

protected:
	ClippingNode*	m_pClippingNode;
};

class BeginnerGuideMove : public BeginnerGuideLayer
{
public:
	BeginnerGuideMove();
	~BeginnerGuideMove();
	static BeginnerGuideMove* create(GuideCfg* pData);

	bool initWithGuideData(GuideCfg* pData);
	bool onTouchBegan(Touch *pTouch, Event *pEvent);
	void onTouchMoved(Touch *pTouch, Event *pEvent);
	void onTouchEnded(Touch *touch, Event *unused_event); 
	void onTouchCancelled(Touch *touch, Event *unused_event);
	//�����������˳���ʱ����onExit()�д���һЩ����
	void onExit();

protected:
	Point			m_OriginPoint;
	bool			m_bFlag;
};

class BeginnerGuideSkill : public BeginnerGuideLayer
{
public:
	BeginnerGuideSkill();
	~BeginnerGuideSkill();
	static BeginnerGuideSkill* create(GuideCfg* pData);

	bool initWithGuideData(GuideCfg* pData);
	bool onTouchBegan(Touch *pTouch, Event *pEvent);
	void onTouchMoved(Touch *pTouch, Event *pEvent);
	//�����������˳���ʱ����onExit()�д���һЩ����
	void onExit();

	void onComplete();

protected:
	SkillCfg*		m_pSkillData;
	ImageView*		m_pSkillIcon;
};

#endif // __BEGINNER_GUIDE_UI_H__