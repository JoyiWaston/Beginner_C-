#include "boss.h"

Boss::Boss(int id, string name, int depId)
{
	this->w_Id = id;
	this->w_Name = name;
	this->w_DepId = depId;
}

void Boss::showInfo()
{
	cout << "ְ�����" << this->w_Id
		<< " \tְ��������" << this->w_Name
		<< "\t��λ��" << this->getDepInformation()
		<< "\t��λְ�𣺹���˾����ҵ��" << endl;
}

string Boss::getDepInformation()
{
	return string("�ϰ�");
}