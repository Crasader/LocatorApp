/* ģ��: ��������
   ����: Tangbo
   ʱ��: 2015/9/24
 */


#include "Net/pk_guild.h"

//����ְ��ö��
enum  LegionTitle_em
{
	LegionTitle_JiangJun = 1,             //����
	LegionTitle_TaiWei,                   //̫ξ
	LegionTitle_DuWei,                    //��ξ
	LegionTitle_XiaoWei,                  //Уξ
	LegionTitle_ZhongWei,                 //��ξ
	LegionTitle_ShiBing,                  //ʿ��
};

//ְ��Ȩ�� 	%%�����ԱȨ��
enum  LegionPermission_em
{
	LegionPermission_Approve      = 1<<1, 	               //����Ȩ��
	LegionPermission_Kick         = 1<<2,    	           //����
	LegionPermission_Build        = 1<<3,   	           //����
	LegionPermission_Armament     = 1<<4,                  //��е
	LegionPermission_Alter_Announcement = 1<<5,            //�޸Ĺ���
	LegionPermission_Quiet        = 1<<6,                  //����
	LegionPermission_Appoint      = 1<<7,                  //ְ������
};



typedef vector<pk::memberList> Member_V;     //��Ա
typedef vector<pk::guildList>  Legion_V;       //����

//�����Ա��
class LegionMember_cl
{
public:
	LegionMember_cl();
	~LegionMember_cl();

	//��ȡ�����Ա�б�
	const Member_V&  getMemberList(){return m_vMemberList;}

	//�򹫻�����ӳ�Ա
	void addMember(pk::memberList* member);

	//ɾ�������Ա
	void removeMemberByPlayerId(int playerid);
	
	void removeMember(pk::memberList* member);

	//��ȡ��ǰ���������
	inline int getCount(){return (int)m_vMemberList.size();}

private:
	//�����Ա
	Member_V  m_vMemberList;
};

class  Legion_cl
{
public:
	Legion_cl();
	~Legion_cl();

	//��ʼ������
	void   initLegion(Legion_V _list);

	//��ʼ����Ա�б�
	void   initMemberList(Member_V _list);

	//��ȡ�����б�
	inline Legion_V& getGuildList(){return m_pGuild;}

	//��ȡ�����Ա
	inline LegionMember_cl* getLegionMemberList(){return m_pMember;}

private:

	//�����Ա
	LegionMember_cl * m_pMember;

	//�����б�
	Legion_V           m_pGuild;
};