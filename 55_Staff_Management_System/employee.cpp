#include"employee.h"

Employee::Employee(int id, string name, int depId)
{
	this->w_Id = id;
	this->w_Name = name;
	this->w_DepId = depId;
}

void Employee::showInfo()
{
	cout << "ְ�����" << this->w_Id
		<< "\tְ��������" << this->w_Name
		<< "\t��λ��" << this->getDepInformation()
		<< "\t��λְ����ɾ�����������" << endl;
}

string Employee::getDepInformation()
{
	return string("Ա��");
}