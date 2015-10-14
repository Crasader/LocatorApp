/***
 * ���ߣ�������
 * ʱ�䣺2015-07-2
 * ˵������ɫ��أ���ɫ��۵�չʾ����ɫ�ƶ���׷�ٵ�
 * ���Լ���Ϊ������������AI��Monster,Player,Hero,Npc,Pet����һ����ɫ
 */

#ifndef __Role_H_
#define __Role_H_

#include "GameDef.h"
#include "cocostudio/CCArmatureDataManager.h"
#include "cocostudio/CCArmature.h"
#include "RoleData.h"
#include "RoleState.h"
#include "RoleEvent.h"
#include "NotifyCenter.h"
#include "MoveMonitor.h"
#include "Map/MapObject.h"
#include "RoleCommand.h"
#include "Effect.h"
#include "RoleEffect.h"

using namespace cocos2d;
using namespace cocostudio;

class Role : public MapObject,public StateMachine<Role>
{
public:
	static const int FACES = 5;

public:
	Role();
	virtual ~Role();

	CREATE_FUNC(Role);

	/* Name		��init
	 * Author	��YueLiangYou
	 * Date		: 2015-07-02
	 * Desc		: ��ɫ��ʼ��
	 * Param	: none
	 * Return	: true �ɹ���false ʧ��
	 */
	virtual bool init(){ return true; }

	/* Name		��update
	 * Author	��YueLiangYou
	 * Date		: 2015-07-02
	 * Desc		: ��֡����
	 * Param	: none
	 * Return	: void
	 */
	virtual void update(float dt);

	/* Name		��updateMove
	 * Author	��YueLiangYou
	 * Date		: 2015-07-02
	 * Desc		: �ƶ�����
	 * Param	: none
	 * Return	: true �����ƶ���false �ƶ�����
	 */
	virtual bool updateMove(float dt);

	/* Name		��updateFlash
	 * Author	��YueLiangYou
	 * Date		: 2015-07-02
	 * Desc		: ��˸����
	 * Param	: none
	 * Return	: true ������˸��false ��˸����
	 */
	virtual bool updateFlash(float dt);

	/* Name		��updateLightShadow
	 * Author	��YueLiangYou
	 * Date		: 2015-07-02
	 * Desc		: ���¶�̬��Ӱ
	 * Param	: none
	 * Return	: dt ʱ���
	 */
	virtual void updateLightShadow(float dt);

	/* Name		��GhostShadowCallBack
	 * Author	��YueLiangYou
	 * Date		: 2015-07-02
	 * Desc		: ��Ӱ�ص�����
	 * Param	: pSprite ��Ӱ����
	 * Return	: void
	 */
	virtual void GhostShadowCallBack(Sprite* pSprite);

	/* Name		��SetSkinEffect
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ����Ƥ��Ч�� 
	 * Param	: type Ч������
	 * Return	: void
	 */
	virtual void SetSkinEffect(int type);

public:
	/* Name		��EnterMap
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ����ָ����ͼ��������
	 * Param	: pMap��ͼָ�룬pos��ͼ�е���������
	 * Return	: void
	 */
	virtual void EnterMap(TileMap* pMap,const Point& pos);

	/* Name		��EnterMap
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ����ָ����ͼ
	 * Param	: pMap��ͼָ�룬cx��cy��ͼ�е��߼�����
	 * Return	: void
	 */
	virtual void EnterMap(TileMap* pMap,int cx,int cy);

	/* Name		��LeaveMap
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: �뿪��ǰ��ͼ
	 * Param	: none
	 * Return	: void
	 */
	virtual void LeaveMap();

	/* Name		��GetMoveMonitor
	 * Author	��YueLiangYou
	 * Date		: 2015-07-02
	 * Desc		: ��ȡ�ƶ����
	 * Param	: none
	 * Return	: �ƶ��������
	 */
	inline MoveMonitor& GetMoveMonitor(){ return m_MoveMonitor; }

	/* Name		��GetMovePath
	 * Author	��YueLiangYou
	 * Date		: 2015-07-02
	 * Desc		: ��ȡ��ǰ�ƶ�·��
	 * Param	: none
	 * Return	: �ƶ�·��
	 */
	inline APath& GetMovePath(){ return GetMoveMonitor().GetPath(); }

	/* Name		��MoveTo
	 * Author	��YueLiangYou
	 * Date		: 2015-07-02
	 * Desc		: �ƶ���ָ�����꣬�����ƶ�״̬
	 * Param	: cx,cy ָ���߼�����
	 * Return	: void
	 */
	virtual void MoveTo(int cx,int cy);

	/* Name		��MoveBy
	 * Author	��YueLiangYou
	 * Date		: 2015-07-02
	 * Desc		: ��ָ���������ƶ��������ƶ�״̬
	 * Param	: dirָ������
	 * Return	: void
	 */
	virtual void MoveBy(__Dir dir);

	/* Name		��MoveBy
	 * Author	��YueLiangYou
	 * Date		: 2015-07-02
	 * Desc		: ��ָ���ƶ�·��
	 * Param	: path·�� offset ʱ��ƫ����
	 * Return	: void
	 */
	virtual void Move(APath& path,long offset=0);

	/* Name		��Stop
	 * Author	��YueLiangYou
	 * Date		: 2015-07-02
	 * Desc		: ����ֹͣ�ƶ�
	 * Param	: none
	 * Return	: void
	 */
	virtual void Stop();

	/* Name		��StopTo
	 * Author	��YueLiangYou
	 * Date		: 2015-07-02
	 * Desc		: ��ָ��λ��ֹͣ�ƶ�
	 * Param	: x,yָ��λ��
	 * Return	: void
	 */
	virtual void StopTo(int x,int y);

	/* Name		��IsMoving
	 * Author	��YueLiangYou
	 * Date		: 2015-07-02
	 * Desc		: �Ƿ����ƶ�״̬
	 * Param	: none
	 * Return	: �ƶ�״̬����true������false
	 */
	inline bool IsMoving(){ return GetCurrStateID() == RoleState_Move; }

	/* Name		��IsStandStill
	 * Author	��YueLiangYou
	 * Date		: 2015-07-02
	 * Desc		: �Ƿ��ڴ���״̬
	 * Param	: none
	 * Return	: ����״̬����true������false
	 */
	inline bool IsStandStill(){ return GetCurrStateID() == RoleState_Idle; }

	/* Name		��IsFlipped
	 * Author	��YueLiangYou
	 * Date		: 2015-07-02
	 * Desc		: �Ƿ񾭹���ת
	 * Param	: none
	 * Return	: true �ѷ�ת��false δ��ת
	 */
	inline bool IsFlipped(){ return getArmor() ? getArmor()->getScaleX() == -1.0f : false; }

	inline Armature*	getArmor(){ return m_pArmor; }
	inline Armature*	getWeapon(){ return m_pWeapon; }
	inline Armature*	getWing(){ return m_pWing; }

	inline int			getDir(){ return m_nDir; }
	inline RoleAction	getActionName(){ return m_sActionName; }

	/* Name		��GetActionSpeed
	 * Author	��YueLiangYou
	 * Date		: 2015-07-02
	 * Desc		: ��ȡ���������ٶ�
	 * Param	: none
	 * Return	: �����ٶ�
	 */
	inline int  GetActionSpeed(){ return m_nActionSpeed; }

	/* Name		��GetData
	 * Author	��YueLiangYou
	 * Date		: 2015-07-02
	 * Desc		: ��ȡ��ɫ����
	 * Param	: none
	 * Return	: RoleData*
	 */
	inline RoleData* GetData(){ return m_pData; }

	virtual void SetProperty(RoleProperty idx,int val){ GetData()->SetProperty(idx,val); }
	virtual void SetProperty(RoleProperty idx,__int64 val){ GetData()->SetProperty(idx,val); }
	virtual void SetProperty(RoleProperty idx,const string& val){ GetData()->SetProperty(idx,val); }

	/* Name		��GetPropertyInt
	 * Author	��YueLiangYou
	 * Date		: 2015-07-02
	 * Desc		: ��ȡ��ɫ����
	 * Param	: none
	 * Return	: int ֵ
	 */
	inline int GetPropertyInt(RoleProperty idx){ int val = 0;GetData()->GetProperty(idx,val); return val; }

	/* Name		��GetPropertyInt64
	 * Author	��YueLiangYou
	 * Date		: 2015-07-02
	 * Desc		: ��ȡ��ɫ����
	 * Param	: none
	 * Return	: __int64 ֵ
	 */
	inline __int64 GetPropertyInt64(RoleProperty idx){ __int64 val = 0;GetData()->GetProperty(idx,val); return val; }

	/* Name		��GetPropertyStr
	 * Author	��YueLiangYou
	 * Date		: 2015-07-02
	 * Desc		: ��ȡ��ɫ����
	 * Param	: none
	 * Return	: string ֵ
	 */
	inline string GetPropertyStr(RoleProperty idx){ string val; GetData()->GetProperty(idx,val); return val; }

	/* Name		��GetRoleName
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ��ȡ��ɫ����
	 * Param	: none
	 * Return	: ��ɫ����
	 */
	inline string& GetRoleName(){ return GetData()->GetName(); }

	/* Name		��HasStateFlag
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: �жϽ�ɫ�Ƿ�ӵ��ĳ��״̬��־λ
	 * Param	: val ״ֵ̬
	 * Return	: true �У�false û��
	 */
	inline bool	HasStateFlag(int val){ return GetData()->HasStateFlag(RoleStatus(val)); }

	/* Name		��GetStateFlag
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ��ȡ��ɫ״̬��־λ
	 * Param	: none
	 * Return	: int ��ɫ״̬��־λ
	 */
	inline int GetStateFlag(){ return GetData()->GetStateFlag(); }

	/* Name		��GetMoveSpeed
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ��ȡ��ɫ�ƶ��ٶ�
	 * Param	: none
	 * Return	: int ��ɫ�ƶ��ٶ�
	 */
	inline int  GetMoveSpeed(){ return GetData()->GetSpeed(); }

	/* Name		��SetRoleName
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ���ý�ɫ����
	 * Param	: val ����
	 * Return	: void
	 */
	virtual void SetRoleName(const string& val){ GetData()->SetName(val); }

	/* Name		��SetStateFlag
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ���ý�ɫ״̬��־λ
	 * Param	: val ״ֵ̬
	 * Return	: void
	 */
	virtual void SetStateFlag(int val){ GetData()->SetStateFlag(RoleStatus(val)); }

	/* Name		��AddStateFlag
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ����ָ����ɫ״̬��־λ
	 * Param	: val ״ֵ̬
	 * Return	: void
	 */
	virtual void AddStateFlag(int val){ GetData()->AddStateFlag(RoleStatus(val)); }

	/* Name		��ClrStateFlag
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ���ָ����ɫ״̬��־λ
	 * Param	: val ״ֵ̬
	 * Return	: void
	 */
	virtual void ClrStateFlag(int val){ GetData()->ClrStateFlag(RoleStatus(val)); }

	/* Name		��SetMoveSpeed
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ��ȡ��ɫ�ƶ��ٶ�
	 * Param	: int ��ɫ�ƶ��ٶ�
	 * Return	: void
	 */
	virtual void SetMoveSpeed(int speed){ GetData()->SetSpeed(speed); }

	/* Name		��SetActionSpeed
	 * Author	��YueLiangYou
	 * Date		: 2015-07-02
	 * Desc		: ���ö��������ٶȣ�����ʱ��
	 * Param	: speed �����ٶ� ��λms
	 * Return	: void
	 */
	virtual void SetActionSpeed(int speed);

	/* Name		��changeDir
	 * Author	��YueLiangYou
	 * Date		: 2015-07-02
	 * Desc		: �ı䳯��
	 * Param	: dir ����
	 * Return	: void
	 */
	virtual void changeDir(__Dir dir);

	/* Name		��flip
	 * Author	��YueLiangYou
	 * Date		: 2015-07-02
	 * Desc		: ���÷�ת
	 * Param	: val true���÷�ת��false�����÷�ת
	 * Return	: void
	 */
	virtual void flip(bool val = true);

	/* Name		��playAction
	 * Author	��YueLiangYou
	 * Date		: 2015-07-02
	 * Desc		: ����ָ������
	 * Param	: action ����ID��durationTo loop
	 * Return	: void
	 */
	virtual void playAction(RoleAction action,int duration = 0, int loop = -1);

	/* Name		��stopAction
	 * Author	��YueLiangYou
	 * Date		: 2015-07-02
	 * Desc		: ֹͣ��ǰ���ŵĶ���
	 * Param	: none
	 * Return	: void
	 */
	virtual void stopAction();

	/* Name		��refreshAction
	 * Author	��YueLiangYou
	 * Date		: 2015-07-02
	 * Desc		: ���¶���
	 * Param	: go �Ƿ񱣳ֵ�ǰ֡
	 * Return	: void
	 */
	virtual void refreshAction(bool go = false);

	/* Name		��enableLightShadow
	 * Author	��YueLiangYou
	 * Date		: 2015-07-02
	 * Desc		: �������߹رն�̬��Ӱ
	 * Param	: flag = true ������= false �ر�
	 * Return	: void
	 */
	virtual void enableLightShadow(bool flag);

	/* Name		��enableGhostShadow
	 * Author	��YueLiangYou
	 * Date		: 2015-07-02
	 * Desc		: �������߹رղ�ӰЧ��
	 * Param	: flag = true ������= false �ر�
	 * Return	: void
	 */
	virtual void enableGhostShadow(bool flag);

	/* Name		��draw
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ����ɫ��ײ�����ռ�ø���
	 * Param	: none
	 * Return	: void
	 */
	virtual void draw(Renderer *renderer, const kmMat4& transform, bool transformUpdated);
	virtual void onDraw(Renderer *renderer, const kmMat4& transform, bool transformUpdated);

	/* Name		��drawCollisionRect
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ����ɫ��ײ����
	 * Param	: none
	 * Return	: void
	 */
	void drawCollisionRect(Renderer *renderer, const kmMat4& transform, bool transformUpdated);

	/* Name		��drawCollisionRect
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ����ɫռ�ø���
	 * Param	: none
	 * Return	: void
	 */
	void drawRoleCell(Renderer *renderer, const kmMat4& transform, bool transformUpdated);

	/* Name		��drawHungingPoints
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ����ɫ���Ϲҵ�
	 * Param	: none
	 * Return	: void
	 */
	void drawHungingPoints(Renderer *renderer, const kmMat4& transform, bool transformUpdated);

	// ��װ
	virtual void equipWeapon(int dataid);
	virtual void equipArmor(int dataid);
	virtual void equipWing(int dataid);

	virtual void equipWeapon(const char* weapon);
	virtual void equipArmor(const char* armor);
	virtual void equipWing(const char* wing);

	virtual void unequipWeapon();
	virtual void unequipArmor();
	virtual void unequipWing();
	virtual void unequipAll();

	/* Name		��ShowEffectAsync
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ͨ��չʾ��ɫ��Ч����Ч
	 * Param	: config��Ч��׼����
	 * Return	: void
	 */
	virtual void ShowEffectAsync(const string& config);

	/* Name		��ShowEffectAsync
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ͨ��չʾ��ɫ��Ч����Ч
	 * Param	: effectid ��Ч�ļ�ID��name ��Ч���Ʋ�������
	 * Return	: void
	 */
	virtual void ShowEffectAsync(int effectid,const string& name,int zorder = 0);

	/* Name		��ShowEffectAsync
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: �ڽ�ɫ������ʾһ����Ч
	 * Param	: Effect* pEffect
	 * Return	: void
	 */
	virtual void ShowEffectAsync(RoleEffect* pEffect);

	/* Name		��ShowEffect
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: �ڽ�ɫ��������ʾһ����Ч
	 * Param	: config �������� [id;name;hpoint;scale]
	 * Return	: void
	 */
	virtual void ShowEffect(const string& config);

	/* Name		��ShowEffect
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ͨ��չʾ��ɫ��Ч����Ч
	 * Param	: effectid ��Ч�ļ�ID��name ��Ч���Ʋ�������
	 * Return	: void
	 */
	virtual void ShowEffect(int effectid,const string& name,int hpt = 0,float scale = 1.0f,int zorder = 0);

	/* Name		��ShowEffect
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: �ڽ�ɫ��������ʾһ����Ч
	 * Param	: Effect* pEffect
	 * Return	: void
	 */
	virtual void ShowEffect(Effect* pEffect);

	/* Name		��ShowEffectCallBack
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: չʾ��ɫ��Чͨ�ûص�
	 * Param	: none
	 * Return	: void
	 */
	virtual void ShowEffectCallBack(Layer* pLayer);

	/* Name		��PushShowEffectLayer
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ����Ч��չʾ����
	 * Param	: pLayer
	 * Return	: void
	 */
	virtual void PushShowEffectLayer(Layer* pLayer);

	/* Name		��ClearShowEffectLayer
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: �����ɫ���ϵ�Ч��չʾ
	 * Param	: none
	 * Return	: void
	 */
	virtual void ClearShowEffectLayer(Layer* pLayer);

	/* Name		��ClearShowEffectLayer
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: �����ɫ���ϵ�Ч��չʾ
	 * Param	: none
	 * Return	: void
	 */
	virtual void ClearShowEffectLayer();

	/* Name		��attach
	 * Author	��YueLiangYou
	 * Date		: 2015-07-02
	 * Desc		: ������Ч
	 * Param	: config ��������
	 * Return	: void
	 */
	virtual void attach(const string& config);

	/* Name		��attach
	 * Author	��YueLiangYou
	 * Date		: 2015-07-02
	 * Desc		: ������Ч
	 * Param	: dataid ��Ч����ID��name ��Ч���ƣ����Ŷ�����
	 * Return	: void
	 */
	virtual Effect* attach(int dataid,const string& name,int zorder = 0);

	/* Name		��attach
	 * Author	��YueLiangYou
	 * Date		: 2015-07-02
	 * Desc		: ������Ч
	 * Param	: pEffect ��Ч����ָ��
	 * Return	: void
	 */
	virtual void attach(Effect* pEffect);

	/* Name		��isAttached
	 * Author	��YueLiangYou
	 * Date		: 2015-07-02
	 * Desc		: �Ƿ񸽼���Ч
	 * Param	: dataid name ��Чdataid������
	 * Return	: true �Ѹ��ӣ�false û�и���
	 */
	virtual bool isAttached(int dataid,const string& name);

	/* Name		��detach
	 * Author	��YueLiangYou
	 * Date		: 2015-07-02
	 * Desc		: ȥ����ɫ���ϵ�ĳ����Ч
	 * Param	: dataid name ��Чdataid������
	 * Return	: void
	 */
	virtual void detach(int dataid,const string& name);

	/* Name		��detach
	 * Author	��YueLiangYou
	 * Date		: 2015-07-02
	 * Desc		: ȥ����ɫ���ϵ�ĳ����Ч
	 * Param	: pEffect ��Чָ��
	 * Return	: void
	 */
	virtual void detach(Effect* pEffect);

	/* Name		��detach
	 * Author	��YueLiangYou
	 * Date		: 2015-07-02
	 * Desc		: ȥ����ɫ���ϵ�������Ч
	 * Param	: none
	 * Return	: void
	 */
	virtual void detach();

	/* Name		��onAnimationEvent
	 * Author	��YueLiangYou
	 * Date		: 2015-07-02
	 * Desc		: �����¼���Ӧ����
	 * Param	: armature movementType movementID
	 * Return	: void
	 */
	virtual void onAnimationEvent(cocostudio::Armature *armature, cocostudio::MovementEventType movementType, const std::string& movementID);

	/* Name		��onFrameEvent
	 * Author	��YueLiangYou
	 * Date		: 2015-07-02
	 * Desc		: ֡�¼���Ӧ����
	 * Param	: bone ������evt �¼��Զ��������
	 * Return	: void
	 */
	virtual void onFrameEvent(cocostudio::Bone *bone, const std::string& evt, int originFrameIndex, int currentFrameIndex);

	/* Name		��onNotifyCenter
	 * Author	��YueLiangYou
	 * Date		: 2015-07-02
	 * Desc		: �յ�֪ͨ���Ĵ�����Ϣ
	 * Param	: msg ��Ϣ��
	 * Return	: void
	 */
	virtual void onNotifyCenter(int msg);

	/* Name		��processCommand
	 * Author	��YueLiangYou
	 * Date		: 2015-07-02
	 * Desc		: ����ָ��
	 * Param	: none
	 * Return	: void
	 */
	virtual void processCommand(const RoleCommand& cmd);

	/* Name		��pushCommand
	 * Author	��YueLiangYou
	 * Date		: 2015-07-02
	 * Desc		: ����ָ��
	 * Param	: cmd ָ������
	 * Return	: void
	 */
	virtual void pushCommand(const RoleCommand& cmd);

	/* Name		��Pursue
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ׷��Ŀ��
	 * Param	: pTarget ׷��Ŀ�꣬distance ׷������Ŀ��ľ��룬cmd ׷����Ŀ���ִ��ָ��
	 * Return	: void
	 */
	virtual void Pursue(__int64 targetid,int distance,const RoleCommand& cmd);

	/* Name		��PursueCancel
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ȡ��׷��
	 * Param	: none
	 * Return	: void
	 */
	virtual void PursueCancel();

	/* Name		��PursueCheck
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ȡ��׷��
	 * Param	: none
	 * Return	: true ����׷�� false ȡ��׷��
	 */
	virtual bool PursueCheck();

	/* Name		��PursueOk
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ׷����Ŀ��
	 * Param	: none
	 * Return	: true ׷����Ŀ�ִ꣬��ָ�� false ����׷��
	 */
	virtual bool PursueOk();

	/* Name		��PursueUpdate
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ׷������
	 * Param	: none
	 * Return	: void
	 */
	virtual void PursueUpdate();

	/* Name		��IsPursueing
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: �Ƿ�����׷��
	 * Param	: none
	 * Return	: void
	 */
	inline bool IsPursueing(){ return m_nPursueTargetID != 0 ;}

	/* Name		��GetDistanceTo
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ��ȡ������Ŀ���߼���ľ���
	 * Param	: cx,cy Ŀ���߼���
	 * Return	: int ����
	 */
	inline int	GetDistanceTo(int cx,int cy){ return Distance(GetCellX(),GetCellY(),cx,cy); }

	/* Name		��GetDistanceTo
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ��ȡ������Ŀ��ľ���
	 * Param	: pTarget Ŀ�����
	 * Return	: int ����
	 */
	inline int	GetDistanceTo(Role* pRole){ return pRole ? GetDistanceTo(pRole->GetCellX(),pRole->GetCellY()) : -1; }

protected:
	Armature* m_pArmor;			// ����
	Armature* m_pWeapon;		// ����
	Armature* m_pWing;			// ���

	bool		m_bLightShadow;		// ��̬��Ӱ����
	int			m_nArmorShadowFrame;	// ���׵���Ӱ֡
	int			m_nWeaponShadowFrame;	// ���ڵ���Ӱ֡
	int			m_nWingShadowFrame;	// ������Ӱ֡
	Sprite*		m_pArmorShadow;		// ���׵���Ӱ
	Sprite*		m_pWeaponShadow;	// ���ڵ���Ӱ
	Sprite*		m_pWingShadow;		// ������Ӱ

	bool		m_bGhostShadow;// ��ӰЧ������
	Layer*		m_pGhostShadowLayer;// ��Ӱ��

	int			m_nArmorID;		// ����DataID
	int			m_nWeaponID;	// ����DataId
	int			m_nWingID;		// ���DataId

	int			m_nActionSpeed;	// ���������ٶ�
	RoleAction	m_sActionName;	// ����ID
	int			m_nDurationTo;	//
	int			m_nLoop;		// �Ƿ�ѭ��
	int			m_nDir;			// ��ǰ��������

	RoleData*	m_pData;		// ����

	__int64			m_nPursueTargetID;		// ׷��Ŀ���ID��ΪʲôҪ��¼ID����¼ָ�룬��ֹ������ɵ�Ұָ��
	APoint			m_pursueTargetPos;		// ׷��Ŀ���λ��
	int				m_nPursueDistance;		// ׷������Ŀ��ľ���
	RoleCommand		m_pursueCommand;		// ׷����Ŀ����ָ��

	MoveMonitor	m_MoveMonitor;	// �����ƶ��ļ��

	deque<RoleCommand> m_dequeCommands;	// ָ���б�

	EffectList		m_vEffects;				// ��ɫ������Ч
	vector<Layer*>	m_vShowEffectLayers;	// Ч����

};

#endif //__Role_H_