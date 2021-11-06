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
	void ShowMenu();

	//�˳�ϵͳ
	void ExitSystem();

	//���ְ��
	void Add_Emp();
	//��¼�ļ��������ĸ���
	int w_EmpNum;
	//Ա�������ָ��
	Worker** w_EmpArray;
	//�ļ�д�벢����
	void Save();
	//��־�ļ��Ƿ�Ϊ��
	bool w_FileIsEmpty;
	
	
	//ͳ������
	int Get_EmpNum();

	//��ʼ��Ա��
	void Init_Emp();

	//��ʾְ��
	void Show_Emp();

	//ɾ��ְ��
	void Del_Emp();
	//Ա���Ƿ���ں���
	int IsExist(int id);

	
	//�޸�ְ��
	void Mod_Emp();

	//����ְ��
	void Find_Emp();
	//ʾ����
	void showHeader();


	//����ְ��(ѡ������)
	void Sort_Emp();

	//����ļ�
	void Clean_File();

	//��������
	~WorkManager();
};