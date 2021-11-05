# include"workerManager.h"
# include"employee.h"
# include"manager.h"
# include"boss.h"
//����������
//1.���û��Ĺ�ͨ�˵�����
//2.��ְ����ɾ�Ĳ�Ĳ���
//3.���ļ���д����

//����
WorkManager::WorkManager()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	
	//1.�ļ�������
	if (!ifs.is_open())
	{
		//cout << "�ļ�������,����������" << endl;

		//��ʼ������
		this->w_EmpNum = 0;

		//��ʼ���ļ�Ϊ�ձ�־
		this->w_FileIsEmpty = true;

		//��ʼ������ָ��
		this->w_EmpArray = NULL;

		//�ر��ļ�
		ifs.close();
		return;
	}
	//2.�ļ����ڵ�����Ϊ��
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		//cout << "�ļ�����,������Ϊ�գ�����д�����ݣ�" << endl;

		//��ʼ������
		this->w_EmpNum = 0;

		//��ʼ���ļ�Ϊ�ձ�־
		this->w_FileIsEmpty = true;

		//��ʼ������ָ��
		this->w_EmpArray = NULL;

		//�ر��ļ�
		ifs.close();
		return;
	}

	//3.�ļ����ڣ������м�¼����
	int num = this->get_EmpNum();
	//cout << "����ְ������Ϊ��" << num << endl; //���Դ���
	this->w_EmpNum = num;	//���³�Ա����

	//����ְ������������
	this->w_EmpArray = new Worker * [this->w_EmpNum];
	//��ʼ��ְ��			���ļ��е����ݴ��뵽������
	this->init_Emp();

	////���Դ���
	//for (int i = 0; i < w_EmpNum; i++)
	//{
	//	cout << "ְ����" << this->w_EmpArray[i]->w_Id
	//		<< "ְ������" << this->w_EmpArray[i]->w_Name
	//		<< "���ű��" << this->w_EmpArray[i]->w_DepId << endl;
	//}
}

//չʾ�˵�
void WorkManager::showMenu()
{
	cout << "***********************************" << endl;
	cout << "*****  ��ӭʹ��ְ������ϵͳ   *****" << endl;
	cout << "*****     0.�˳�����ϵͳ      *****" << endl;
	cout << "***** 	  1.����ְ����Ϣ      *****" << endl;
	cout << "*****	  2.��ʾְ����Ϣ      *****" << endl;
	cout << "*****	  3.ɾ����ְԱ��      *****" << endl;
	cout << "*****	  4.�޸�ְ����Ϣ      *****" << endl;
	cout << "*****	  5.����ְ����Ϣ      *****" << endl;
	cout << "*****	  6.���ձ������      *****" << endl;
	cout << "*****	  7.��������ĵ�      *****" << endl;
	cout << "***********************************" << endl;
	cout << endl;
}

//�˳�ϵͳ
void WorkManager::exitSystem()
{
	cout << "��ӭ���´�ʹ�ã�" << endl;
	system("pause");
	exit(0);//�˳�ϵͳ
}

//���Ա��
void WorkManager::Add_Emp()
{
	cout << "���������Ա��������" << endl;

	int addNum = 0;
	cin >> addNum;

	if (addNum > 0)
	{
		//�����¿ռ��С
		int newSize = this->w_EmpNum + addNum;		//�¿ռ����� = ԭ��¼���� + ���������

		//�����¿ռ�
		Worker** newSpace = new Worker * [newSize];

		//��ԭ�ռ������ݴ�ŵ��¿ռ���
		if (this->w_EmpArray != NULL)
		{
			for (int i = 0; i < this->w_EmpNum; i++)
			{
				newSpace[i] = this->w_EmpArray[i];
			}
		}

		//����������
		for (int i = 0; i < addNum; i++)
		{
			int id;
			string name;
			int depSelect;

			cout << "������� " << i + 1 << " ����ְ����ţ�" << endl;
			cin >> id;

			cout << "������� " << i + 1 << " ����ְ��������" << endl;
			cin >> name;

			cout << "��ѡ���ְ���ĸ�λ��" << endl;
			cout << "1. ��ְͨ��" << endl;
			cout << "2. ����" << endl;
			cout << "3. �ϰ�" << endl;
			cin >> depSelect;

			Worker* worker = NULL;
			switch (depSelect)
			{
				case 1:
					worker = new Employee(id, name, 1);
					break;
				case 2:
					worker = new Manager(id, name, 2);
					break;
				case 3:
					worker = new Boss(id, name, 3);
					break;
				default:
					break;
			}
			//������ְ��ְ�𣬱��浽������
			newSpace[this->w_EmpNum + i] = worker;
		}
		//�ͷ�ԭ�пռ�
		delete[] this->w_EmpArray;

		//�����¿ռ�ָ��
		this->w_EmpArray = newSpace;

		//�����µĸ���
		this->w_EmpNum = newSize;

		//����ְ����Ϊ�ձ�־
		this->w_FileIsEmpty = false;

		//��ʾ��Ϣ
		cout << "�ɹ����" << addNum << "����ְ����" << endl;

		//��������д���ļ�
		this->save();
	}
	else
	{
		cout << " �������� " << endl;
	}

	system("pause");
	system("cls");
}

//д���ļ�������
void WorkManager::save()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);

	for (int i = 0; i < this->w_EmpNum; i++)
	{
		ofs << this->w_EmpArray[i]->w_Id << " "
			<< this->w_EmpArray[i]->w_Name << " "
			<< this->w_EmpArray[i]->w_DepId << endl;
	}

	ofs.close();
}

//ְ������ͳ��
int WorkManager::get_EmpNum()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int depId;

	int num = 0;
	while (ifs >> id && ifs >> name && ifs >> depId)
	{
		//��¼����
		num++;
	}
	ifs.close();

	return num;
}

//��ʼ��Ա��
void WorkManager::init_Emp()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int depId;

	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> depId)
	{
		Worker* worker = NULL;
		//���ݲ�ͬ�Ĳ���id������ͬ����
		if (depId == 1)	//��ͨԱ��
		{
			worker = new Employee(id, name, depId);
		}
		else if (depId == 2)	//����
		{
			worker = new Manager(id, name, depId);
		}
		else                    //�ϰ�
		{
			worker = new Boss(id, name, depId);
		}
		//�����������
		this->w_EmpArray[index] = worker;
		index++;
	}
	//�ر��ļ�
	ifs.close();
}

//����
WorkManager::~WorkManager()
{
	if (this->w_EmpArray != NULL)
	{
		delete[] this->w_EmpArray;
		this->w_EmpArray = NULL;
	}
}