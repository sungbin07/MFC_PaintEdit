#pragma once
#include "YTwoDimension.h"
class YEllipse :public YTwoDimension
{
public:
	YEllipse();
	YEllipse(CPoint start, CPoint end, int color, int thick, int pattern);
	~YEllipse();


	//void setType(YObject_Type t){ yType = t; }
	void moveAll(int s, int e) ;
	void deleteAll() ;
	void draw(CDC*) ;

	void move(int s, int e);
	void changeLineColor();

	void setRgn();
	BOOL  checkRgn(CPoint point);

	void setSPoint(CPoint point){
		sPoint = point;
	}
	CPoint getSPoint(){ return sPoint; }
	void setEPoint(CPoint point){
		ePoint = point;
	}
	CPoint getEPoint(){ return ePoint; }

	CRect* getMRect(){ return mRect; }


	void setSelect(BOOL select) { isSelected = select; }
	void setMPoint(int val){ mPoint = val; }
	int getMPoint(){ return mPoint; }

	void ChangeinColor();
	void ChangeSize(); //크기변경

	void drawCircle(CDC *pDC);// 리전 으로 선택시 원 생기게 할라고!!

private:
	CRect rect;
	CPoint sPoint;
	CPoint ePoint;
	CRect mRect[2]; //끝점 동그라미 그리기위한 

	int mPoint; //시작점 끝점 중 어떤거 이동시키는지 확인하는거

};

