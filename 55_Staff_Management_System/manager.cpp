#include "manager.h"

Manager::Manager(int id, string name, int depId)
{
	this->w_Id = id;
	this->w_Name = name;
	this->w_DepId = depId;
}

void Manager::showInfo()
{
	cout << "ְ�����" << this->w_Id
		<< " \tְ��������" << this->w_Name
		<< "\t��λ��" << this->getDepInformation()
		<< "\t��λְ������ϰ彻�������񣬲��·������Ա��" << endl;
}

string Manager::getDepInformation()
{
	return string("����");
}