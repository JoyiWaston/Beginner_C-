#pragma once
#include"42_Package_case_point_cercle.h"
//����
class Point
{
public:
	//����X
	void setX(int x);
	//��ȡX
	int getX();
	//����Y
	void setY(int y);
	//��ȡY
	int getY();
private:
	int m_X;
	int m_Y;
};