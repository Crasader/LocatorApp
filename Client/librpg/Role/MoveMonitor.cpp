#include "MoveMonitor.h"
#include "RoleState.h"
#include "RoleData.h"

Point DistanceByWorld(int cx0,int cy0,int cx1,int cy1)
{
	//double x = m_nOriginX + (double)cx*(double)cellInPixelsX/2.0-(double)cy*(double)cellInPixelsX/2.0;
	//double y = m_nOriginY - (double)cy*(double)cellInPixelsY/2.0-(double)cx*(double)cellInPixelsY/2.0 - cellInPixelsY/2.0;

	Point pos;

	pos.x = (float)cx1*(float)cellInPixelsX/2.0f-(float)cy1*(float)cellInPixelsX/2.0f - ((float)cx0*(float)cellInPixelsX/2.0f-(float)cy0*(float)cellInPixelsX/2.0f);
	pos.y = -(float)cy1*(float)cellInPixelsY/2.0f-(float)cx1*(float)cellInPixelsY/2.0f - cellInPixelsY/2.0f - (-(float)cy0*(float)cellInPixelsY/2.0f-(float)cx0*(float)cellInPixelsY/2.0f - cellInPixelsY/2.0f);
	
	return pos;
}

__Dir DirectionBy(int cx0,int cy0,int cx1,int cy1)
{
	int dx = cx1-cx0;
	int dy = cy1-cy0;

	float var = (float)abs(dx)/(float)abs(dy);
	float var1 = 1.0f/var;

	if ( dx < 0 && dy < 0 )
	{
		if ( var >=0.5f && var1 >= 0.5f )
		{
			return DIR_N;
		}
		if ( var < 0.5f )
		{
			return DIR_NE;
		}
		if ( var1 < 0.5f )
		{
			return DIR_NW;
		}
	}
	if ( dx == 0 && dy < 0 )
	{
		return DIR_NE;
	}
	if ( dx > 0 && dy < 0 )
	{
		if ( var >=0.5f && var1 >= 0.5f )
		{
			return DIR_E;
		}
		if ( var < 0.5f )
		{
			return DIR_NE;
		}
		if ( var1 < 0.5f )
		{
			return DIR_SE;
		}
	}
	if ( dx > 0 && dy == 0 )
	{
		return DIR_SE;
	}
	if ( dx > 0 && dy > 0 )
	{
		if ( var >=0.5f && var1 >= 0.5f )
		{
			return DIR_S;
		}
		if ( var < 0.5f )
		{
			return DIR_SW;
		}
		if ( var1 < 0.5f )
		{
			return DIR_SE;
		}
	}
	if ( dx == 0 && dy > 0 )
	{
		return DIR_SW;
	}
	if ( dx < 0 && dy > 0 )
	{
		if ( var >=0.5f && var1 >= 0.5f )
		{
			return DIR_W;
		}
		if ( var < 0.5f )
		{
			return DIR_SW;
		}
		if ( var1 < 0.5f )
		{
			return DIR_NW;
		}
	}
	if ( dx < 0 && dy == 0 )
	{
		return DIR_NW;
	}

	return DIR_S;
}

MoveMonitor::MoveMonitor() : m_nType(MoveType_Normal),m_nSpeed(0),m_lMoveTimeCost(0),m_lMoveTimeCorrect(0),m_lLastTime(0)
{

}

MoveMonitor::~MoveMonitor()
{

}

void MoveMonitor::Move(APoint start,APath& path,int speed,int timeOffset)
{
	Terminate();

	m_CurrPoint = start;

	m_Path = path;

	m_nSpeed = speed;

	m_lLastTime = GetCurrTimeMS();

	SetMoveTimeCost(0);
	AddMoveTimeCorrect(timeOffset);

	// ȡ����һ��Ŀ���
	if ( m_Path.size() > 0 )
	{
		Step(m_Path.pop());
		// ���㷽��
		m_nDir = DirectionBy(m_CurrPoint.x,m_CurrPoint.y,m_StepPoint.x,m_StepPoint.y);
	}
	else
	{
		Terminate();
	}

	m_nType = MoveType_Normal;
}

void MoveMonitor::Flash(const APoint& start,const APoint& end,int speed,int timeOffset)
{
	Terminate();
	m_CurrPoint = start;

	m_nSpeed = speed;
	m_lLastTime = GetCurrTimeMS();

	SetMoveTimeCost(0);
	AddMoveTimeCorrect(timeOffset);

	Step(end);
	// ���㷽��
	m_nDir = DirectionBy(m_CurrPoint.x,m_CurrPoint.y,m_StepPoint.x,m_StepPoint.y);

	m_nType = MoveType_Flash;
}

void MoveMonitor::MoveEnd(APoint point /* = APoint */)
{
	//Step(point);
	m_Path.clear();
}

void MoveMonitor::Terminate()
{
	// �����ǰ�ƶ�·��
	m_Path.clear();
	Step(APoint(0,0));
	SetMoveTimeCost(0);
	SetMoveTimeCorrect(0);
	m_CurrPointOffset = Point::ZERO;
}

void MoveMonitor::Update(float dt)
{
	if ( IsStepOver() )
	{
		return ;
	}

	if ( m_nType == MoveType_Normal )
	{
		UpdateMove(dt);
	}
	else if( m_nType == MoveType_Flash )
	{
		UpdateFlash(dt); 
	}
}

void MoveMonitor::UpdateMove(float dt)
{
	static const int MOVE_UNIT = 35;	// �ƶ�ƽ������

	// �����ƶ���֡
	//static int i = 0;
	//if ( i++ > 10 )
	//{
	//	i = 0;
	//	Sleep(50);
	//}
	long lNowTime = GetCurrTimeMS();
	long lTimeCost = lNowTime-m_lLastTime;
	if ( lTimeCost > MOVE_UNIT )
	{
		AddMoveTimeCorrect(lTimeCost-MOVE_UNIT);	// �޸Ľ���ʱ��
		lTimeCost = MOVE_UNIT;
	}

	if ( GetMoveTimeCost() + lTimeCost >= GetMoveTimeOneCell() )	// ����ƶ�ʱ�䳬��һ������ʱ��
	{
		lTimeCost = GetMoveTimeCost()+lTimeCost-GetMoveTimeOneCell();
		SetMoveTimeCost(0);
		// �����ƶ���������Ŀ��λ����Ϊ��ǰλ�ã�
		m_CurrPoint = m_StepPoint;

		// ��ȡ�ƶ�·���е���һ��λ�ã������ƶ���
		if ( m_Path.size() > 0 )
		{
			Step(m_Path.pop());
		}
		else
		{
			Terminate();
			return;
		}
	}

	m_lLastTime = lNowTime;
	AddMoveTimeCost(lTimeCost);
	
	//CCLOGERROR("lTimeCost:%d,getMoveTimeCost:%d,getMoveTimeOneCell:%d",lTimeCost,GetMoveTimeCost(),GetMoveTimeOneCell());

	// ���㷽��
	m_nDir = DirectionBy(m_CurrPoint.x,m_CurrPoint.y,m_StepPoint.x,m_StepPoint.y);
	// ���㵥λλ����
	float delta_s = GetMoveTimeOneCell()>0?(float)GetMoveTimeCost()/GetMoveTimeOneCell():1.0f;
	m_CurrPointOffset.x = _DELTA_X[m_nDir]*delta_s;
	m_CurrPointOffset.y = _DELTA_Y[m_nDir]*delta_s;
}

void MoveMonitor::UpdateFlash(float dt)
{	
	long lNowTime = GetCurrTimeMS();
	long lTimeCost = lNowTime-m_lLastTime;

	m_lLastTime = lNowTime;
	AddMoveTimeCost(lTimeCost);

	if ( GetMoveTimeCost() + lTimeCost >= GetFlashTime() )	// ����ƶ�ʱ�䳬��һ����˸��ʱ��
	{
		m_CurrPoint = m_StepPoint;
		Terminate();
		return ;
	}

	Point offset = DistanceByWorld(m_CurrPoint.x,m_CurrPoint.y,m_StepPoint.x,m_StepPoint.y);
	// ���㵥λλ����
	float delta_s = (float)GetMoveTimeCost()/(float)GetFlashTime();
	m_CurrPointOffset.x = offset.x*delta_s;
	m_CurrPointOffset.y = offset.y*delta_s;
}

float MoveMonitor::GetMoveSpeed()
{ 
	return 10000.0f/(float)m_nSpeed; 
}

float MoveMonitor::GetMoveSpeedRecover()
{ 
	// ��λ���ӵĽ���ʱ��
	float correctTimeOneCell = m_Path.size()>0?(float)GetMoveTimeCorrect()/(float)m_Path.size():(float)GetMoveTimeCorrect();

	// ����ƶ�ʱ��С�ڻ��ߵ��ڽ���ʱ�䣬ֱ�ӷ���0
	if ( GetMoveSpeed() <= correctTimeOneCell )
	{
		return 0.0f;
	}
	
	return GetMoveSpeed()-correctTimeOneCell; 
}

float MoveMonitor::GetMoveTimeOneCell()
{ 
	return GetMoveSpeedRecover();
}

long MoveMonitor::GetFlashTime()
{
	return m_nSpeed;
}