#pragma once			//��ֹͷ�ļ��ظ�����
#include "55_Staff_Management_System.h"
#include "worker.h"

#define FILENAME "W:\\C++_Workspace\\Beginner_C++\\out\\build\\x64-Debug\\55_Staff_Management_System\\empFile.txt"

class WorkManager
{
public:
	//���캯��
	WorkManager();

	
	//չʾ�˵�
	void showMenu();

	
	//�˳�ϵͳ
	void exitSystem();

	
	//���ְ��
	void Add_Emp();
	//��¼�ļ��������ĸ���
	int w_EmpNum;
	//Ա�������ָ��
	Worker** w_EmpArray;
	//�ļ�д�벢����
	void save();
	//��־�ļ��Ƿ�Ϊ��
	bool w_FileIsEmpty;
	
	
	//ͳ������
	int get_EmpNum();


	//��ʼ��Ա��
	void init_Emp();


	//��������
	~WorkManager();
};