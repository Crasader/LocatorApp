#ifndef __MoveMonitor_h_
#define __MoveMonitor_h_

/************************************************************************/
/* �ƶ��ٶȶ��壺10S �ƶ��ĸ�����                 
/************************************************************************/

#include "GameDef.h"
#include "Map/AStar.h"
#include "RoleData.h"
#include "Map/map_def.h"

__Dir DirectionBy(int cx0,int cy0,int cx1,int cy1);

Point DistanceByWorld(int cx0,int cy0,int cx1,int cy1);


enum MoveType
{
	MoveType_Normal,
	MoveType_Flash,
};

class MoveMonitor
{
public:
	MoveMonitor();
	~MoveMonitor();

public:
	/* Name		��Move
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: �ƶ���ʼ
	 * Param	: start ��� path �ƶ�·�� speed �ƶ��ٶ� timeoffset ʱ��ƫ��
	 * Return	: void
	 */
	void Move(APoint start,APath& path,int speed,int timeOffset);

	/* Name		��Flash
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ������ĳ��
	 * Param	: start ��� end �յ� speed �ƶ��ٶ� timeoffset ʱ��ƫ��
	 * Return	: void
	 */
	void Flash(const APoint& start,const APoint& end,int speed,int timeOffset);

	/* Name		��MoveEnd
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ֹͣ��ǰ�ƶ�
	 * Param	: pointֹͣ��Ŀ���
	 * Return	: void
	 */
	void MoveEnd(APoint point = APoint());

	/* Name		��Terminate
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: �ƶ���ֹ
	 * Param	: none
	 * Return	: void
	 */
	void Terminate();

	/* Name		��Update
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ����
	 * Param	: dt
	 * Return	: void
	 */
	void Update(float dt);

	/* Name		��UpdateMove
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ����
	 * Param	: dt
	 * Return	: void
	 */
	void UpdateMove(float dt);

	/* Name		��UpdateFlash
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ����
	 * Param	: dt
	 * Return	: void
	 */
	void UpdateFlash(float dt);

	
	//
	inline APath&	GetPath(){ return m_Path; }
	inline __Dir	GetDir(){ return m_nDir; }

	inline long		GetMoveTimeCost(){ return m_lMoveTimeCost; }
	inline void		SetMoveTimeCost(long s){ m_lMoveTimeCost = s; }
	inline void		AddMoveTimeCost(long s){ m_lMoveTimeCost += s; }
	inline long		GetMoveTimeCorrect(){ return m_lMoveTimeCorrect; }
	inline void		SetMoveTimeCorrect(long ms){ m_lMoveTimeCorrect = ms; }
	inline void		AddMoveTimeCorrect(long ms){ m_lMoveTimeCorrect += ms; }
	inline void		SubMoveTimeCorrect(long ms){ m_lMoveTimeCorrect -= ms; }

	inline int		GetStepX(){ return m_StepPoint.x; }
	inline int		GetStepY(){ return m_StepPoint.y; }
	inline APoint	GetCurrPoint(){ return m_CurrPoint; }
	inline APoint	GetStepPoint(){ return m_StepPoint; }
	inline Point	GetCurrPointOffset(){ return m_CurrPointOffset; }
	
	inline void		Step(int x,int y){ m_StepPoint.x = x; m_StepPoint.y = y; }
	inline void		Step(APoint point){ m_StepPoint = point; }

	inline bool		IsStepOver(){ return (m_StepPoint.x == 0 && m_StepPoint.y == 0) ;}

	inline MoveType GetMoveType(){ return m_nType; }

	/* Name		��GetMoveSpeed
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ��ȡ�ƶ��ٶȣ������ƶ�һ����������Ҫ��ʱ��MS
	 * Param	: none
	 * Return	: �ƶ��ٶ� long
	 */
	float GetMoveSpeed();

	/* Name		��GetMoveSpeedRecover
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ���ش����޸��ٶ�
	 * Param	: none
	 * Return	: �ƶ��ٶ� float
	 */
	float GetMoveSpeedRecover();

	/* Name		��GetMoveSpeed
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: �ƶ�һ������ʱ�� = �����ƶ��ٶ�+����ٶȡ�
	 * Param	: none
	 * Return	: �ƶ�һ������ʱ�� 
	 */
	float GetMoveTimeOneCell();

	/* Name		��GetFlashTime
	 * Author	��YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: ��ȡ��˸��ʱ��
	 * Param	: none
	 * Return	: ��˸��ʱ��
	 */
	long GetFlashTime();

protected:
	MoveType		m_nType;				// �ƶ����ͣ�����ͨ�ƶ�������˸
	APath			m_Path;					// �ƶ�·��
	APoint			m_CurrPoint;			// ���
	APoint			m_StepPoint;			// ��һ��λ��
	Point			m_CurrPointOffset;		// �ƶ�λ��
	
	__Dir			m_nDir;					// ��ǰ����,8����֮һ
	int				m_nSpeed;				// �ƶ��ٶ�
	long			m_lMoveTimeCost;		// ��ǰ�����ƶ�����ʱ��
	long			m_lMoveTimeCorrect;		// ��ǰ�����ƶ�����ʱ��
	long			m_lLastTime;			// ��һ��ʱ��
};

#endif