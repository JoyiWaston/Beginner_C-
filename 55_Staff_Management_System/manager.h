#pragma once
#include"worker.h"

//������
class Manager : public Worker
{
public:
	Manager(int id, string name, int depId);

	//��ʾ������Ϣ
	virtual void showInfo();

	//��ȡְ����λ����
	virtual string getDepInformation();
};