#pragma once
#include "55_Staff_Management_System.h"

//ְ���������
class Worker
{
public:
	//��ʾ������Ϣ
	virtual void showInfo() = 0;
	//��ȡ��λ��Ϣ
	virtual string getDepInformation() = 0;

	int w_Id;
	string w_Name;
	int w_DepId;
};