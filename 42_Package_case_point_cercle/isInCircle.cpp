#include"isInCircle.h"
//�жϵ��Բ֮��Ĺ�ϵ
void isInCircle(Circle& c, Point& p)
{
	//��������֮�����ƽ��
	int Distance =
		(c.getCenterPoint().getX() - p.getX()) * (c.getCenterPoint().getY() - p.getY()) +
		(c.getCenterPoint().getY() - p.getY()) * (c.getCenterPoint().getY() - p.getY());

	//����뾶��ƽ��
	int RDistance = c.getR() * c.getR();

	//�жϹ�ϵ
	if (Distance == RDistance)
	{
		cout << "����Բ��" << endl;
	}
	else if (Distance > RDistance)
	{
		cout << "����Բ��" << endl;
	}
	else
	{
		cout << "����Բ��" << endl;
	}
}