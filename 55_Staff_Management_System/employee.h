#pragma once
#include "worker.h"

//Ա����
class Employee : public Worker
{
public:
	//���캯��
	Employee(int id, string name, int depId);

	//��ʾ������Ϣ
	virtual void showInfo();

	//��ȡְ����λ����
	virtual string getDepInformation();

};