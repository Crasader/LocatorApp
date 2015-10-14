/****************************************************************************
 ǿ��ϵͳUI
 ����
 2015-9-9
 ****************************************************************************/
#pragma once
#include "GameDef.h"
#include "GameUI.h"

class CStrengthenUI : public GameUI
{
public:
	CStrengthenUI();
	~CStrengthenUI();

	void			setItemType(CItem* item);
	void			setItemType(GodDevice* item);

	bool			onInit();
	void			onOpen();

	CREATE_FUNC(CStrengthenUI);
public:
	Widget*			createAtrributeItem();						

	void			clickCheckBox(Ref*, TouchEventType);			// ���ǿ���ķ���checkbox 1���� 2����
	void			clickBackButton(Ref*, TouchEventType);
	void			clickJinglianButton(Ref*, TouchEventType);      // ����˾�����ť
	void			clickJinglianMaxButton(Ref*, TouchEventType);   // ������������ť
	void			clickJinjieButton(Ref*, TouchEventType);		// ����˽��װ�ť
	void			updateSelectType(int index);					// ˢ�µ�ǰѡ��ǿ�����͵�������
	void			updatejinglian();								// ���¾���
	void			updatejinjie();									// ���½���
	void			updateAttribute(int type);						// ��������
	void			setLeftStar(int star);							// ���������׵��Ǽ�
	void			setRightStar(int star);							// �����Ҳ���׵��Ǽ�
private:
	ListView*					m_attr_list;				// ���Ե�list�б�
	ListView*					m_skill_desc_list;			// ����������list�б�

	CheckBox*					m_select_type_item;			// ѡ���ǿ������checkbox

	CheckBox*					m_jinglian_checkbox;		// ����checkbox
	Text*						m_jinglian_checkbox_text;	// ����checkbox��title
	CheckBox*					m_jinjie_checkbox;			// ����check
	Text*						m_jinjie_checkbox_text;		// ����checkbox��title

	Button*						m_jinglian_btn;				// ������ť
	Button*						m_jinglian_max_btn;			// �������ť
	Button*						m_jinjie_btn;				// ���װ�ť

	ImageView*					m_bg_item_icon;				// �����Ʒͼ��

	ImageView*					m_img_jinjie_star_1;		// �����Ʒ�Ǽ�1
	ImageView*					m_img_jinjie_star_2;		// �����Ʒ�Ǽ�2
	ImageView*					m_img_jinjie_star_3;		// �����Ʒ�Ǽ�3
	ImageView*					m_img_jinjie_star_4;		// �����Ʒ�Ǽ�4
	ImageView*					m_img_jinjie_star_5;		// �����Ʒ�Ǽ�5

	vector<ImageView*>			m_img_jinjie_star_vec;			//�����Ʒ�Ǽ�����
	vector<ImageView*>			m_img_attr_jinjie_star_vec;		//�Ҳ���Ʒ�Ǽ�����

	Text*						m_jingian_level_font;		// ��ྫ������
	Text*						m_jinglian_level_text;		// ��ྫ���ȼ�

	ImageView*					m_img_attr_head_icon;		// �Ҳ���Ʒͼ��
	Text*						m_item_name_text;			// �Ҳ���Ʒ����
	Text*						m_item_type_text;			// �Ҳྫ������
	Text*						m_item_level_text;			// �Ҳྫ���ȼ�

	ImageView*					m_img_attr_jinjie_star_1;	// �Ҳ���Ʒ�Ǽ�1
	ImageView*					m_img_attr_jinjie_star_2;	// �Ҳ���Ʒ�Ǽ�2
	ImageView*					m_img_attr_jinjie_star_3;	// �Ҳ���Ʒ�Ǽ�3
	ImageView*					m_img_attr_jinjie_star_4;	// �Ҳ���Ʒ�Ǽ�4
	ImageView*					m_img_attr_jinjie_star_5;	// �Ҳ���Ʒ�Ǽ�5

	Text*						m_item_skill_desc_text;		// �Ҳ༼������
	Text*						m_item_level_need_text;		// װ��������Ҫ�ȼ�
	Text*						m_item_consume_text;		// ���������ı�
	Text*						m_item_consume_gold_text;	// ���Ľ�������ı�
	Text*						m_item_consume_item_name;	// ���Ĳ��������ı�����
	Text*						m_item_consume_item_have;	// ���Ĳ��������ı�ӵ��
	Text*						m_item_consume_item_need;	// ���Ĳ��������ı���Ҫ

	ImageView*					m_img_consume_head_frame_icon;	// ���Ľ����Ʒͼ�걳��
	ImageView*					m_img_gold_frame_icon;			// ���Ľ����Ʒͼ�걳��

	ImageView*					m_img_consume_head_icon;	// ���Ĳ�����Ʒͼ��

	ItemType m_item_type;		// ǿ����Ʒ�����ͣ�1���� 2��Ʒ
	CItem* m_item;				// ��Ʒָ��
	GodDevice* m_godDevice;		// ����ָ��
public:
};

