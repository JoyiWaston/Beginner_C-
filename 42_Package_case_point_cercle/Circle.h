#pragma once
#include"Point.h"

//Բ��
class Circle
{
public:
	//���ð뾶
	void setR(int R);
	//��ȡ�뾶
	int getR();
	//����Բ��
	void setCenterPoint(Point center);
	//��ȡԲ��
	Point getCenterPoint();
private:
	int m_R;//�뾶

	//�����п�������һ������Ϊ��������ݳ�Ա
	Point m_Centerl;//Բ��
};
