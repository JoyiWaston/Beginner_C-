#include"Circle.h"

//���ð뾶
void Circle::setR(int R)
{
	m_R = R;
}
//��ȡ�뾶
int Circle::getR()
{
	return m_R;
}
//����Բ��
void Circle::setCenterPoint(Point center)
{
	m_Centerl = center;
}
//��ȡԲ��
Point Circle::getCenterPoint()
{
	return m_Centerl;
}