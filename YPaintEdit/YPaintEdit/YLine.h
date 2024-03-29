#pragma once
#include "YOneDimension.h"
class YLine :public YOneDimension
{
	DECLARE_SERIAL(YLine);
public:
	YLine();
	YLine(CPoint start, CPoint end, int color, int thick, int pattern);    //시작점 , 끝점 , 색 , 두께 , 패턴
	YLine(YLine* p);
	~YLine();
	virtual void moveAll(int s, int e);
	virtual void deleteAll();
	virtual void draw(CDC* cPC);

	virtual void move(int s, int e);

	virtual void setRgn();
	BOOL virtual checkRgn(CPoint point);

	void setSPoint(CPoint point){
		sPoint = point;
	}
	CPoint getSPoint(){ return sPoint; }

	void setEPoint(CPoint point){
		ePoint = point;
	}
	CPoint getEPoint(){ return ePoint; }

	CRect* getMRect(){ return mRect; }

	void setMoveMode(int val){ moveMode = val; }
	int getMoveMode(){ return moveMode; }

	virtual void Serialize(CArchive& ar);

private:
	CPoint sPoint;
	CPoint ePoint;
	CRect mRect[2]; //끝점 동그라미 그리기위한 
	int moveMode; // 시작점,끝점 어떤걸 이동시킬지 변수 -1 -> sPoint ,1 -> ePoint  0 ->전체이동
};

