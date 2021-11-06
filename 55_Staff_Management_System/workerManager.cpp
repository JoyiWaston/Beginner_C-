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
	this->w_FileIsEmpty = false;
	
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
	int num = this->Get_EmpNum();
	//cout << "����ְ������Ϊ��" << num << endl; //���Դ���
	this->w_EmpNum = num;	//���³�Ա����

	//����ְ������������
	this->w_EmpArray = new Worker * [this->w_EmpNum];
	//��ʼ��ְ��			���ļ��е����ݴ��뵽������
	this->Init_Emp();

	////���Դ���
	//for (int i = 0; i < w_EmpNum; i++)
	//{
	//	cout << "ְ����" << this->w_EmpArray[i]->w_Id
	//		<< "ְ������" << this->w_EmpArray[i]->w_Name
	//		<< "���ű��" << this->w_EmpArray[i]->w_DepId << endl;
	//}
}

//չʾ�˵�
void WorkManager::ShowMenu()
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
void WorkManager::ExitSystem()
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
					worker = new Employee(id, name, depSelect);
					break;
				case 2:
					worker = new Manager(id, name, depSelect);
					break;
				case 3:
					worker = new Boss(id, name, depSelect);
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
		this->Save();
	}
	else
	{
		cout << " �������� " << endl;
	}

	system("pause");
	system("cls");
}

//д���ļ�������
void WorkManager::Save()
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
int WorkManager::Get_EmpNum()
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
void WorkManager::Init_Emp()
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

//��ʾְ��
void WorkManager::Show_Emp()
{
	if (this->w_FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
	}
	else
	{
		for (int i = 0; i < w_EmpNum; i++)
		{
			//���ö�̬���ýӿ�
			this->w_EmpArray[i]->showInfo();
		}
	}

	system("pause");
	system("cls");
}

//ɾ��ְ��		�����е�ɾ�� ���ʾ�������ǰ��
// 
void WorkManager::Del_Emp()
{
	if (this->w_FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
	}
	else
	{
		//����ְ�����ɾ��
		cout << "��������Ҫɾ��Ա���ı�ţ�" << endl;
		int id = 0;
		cin >> id;

		int index = this->IsExist(id);

		if (index != -1)	//˵��ְ�����ڣ�����Ҫɾ��indexλ���ϵ�ְ��
		{
			//����ǰ��
			for (int i = index; i < this->w_EmpNum - 1; i++)
			{
				this->w_EmpArray[i] = this->w_EmpArray[i + 1];
			}
			this->w_EmpNum--;//���������м�¼��Ա�ĸ���
			this->Save();//����ͬ�����µ��ļ���

			cout << "ɾ���ɹ���" << endl;
		}
		else
		{
			cout << "ɾ��ʧ�ܣ�δ�ҵ���ְ����" << endl;
		}
	}

	system("pause");
	system("cls");
}
//ְ���Ƿ����		���ڷ���ְ�����������е�λ��	�����ڷ���-1
int WorkManager::IsExist(int id)
{
	int index = -1;

	for (int i = 0; i < this->w_EmpNum; i++)
	{
		if (this->w_EmpArray[i]->w_Id == id)
		{
			index = i;
			break;
		}
	}
	return index;
}


//�޸�ְ��
void WorkManager::Mod_Emp()
{
	if (this->w_FileIsEmpty)
	{
		cout << "�ļ������ڻ�����Ϊ�գ�" << endl;
	}
	else
	{
		cout << "��������Ҫ�޸�Ա���ı�ţ�" << endl;
		int id;
		cin >> id;

		int ret = this->IsExist(id);
		if (ret != -1)		//��Ա������
		{
			delete this->w_EmpArray[ret];

			int newId = 0;
			string newName = "";
			int depSelect = 0;

			cout << "��ѯ����" << id << "��ְ������������ְ���ţ�" << endl;
			cin >> newId;

			cout << "�������ְ����������" << endl;
			cin >> newName;

			cout << "�������ְ���¸�λ��" << endl;
			cout << "1. ��ְͨ��" << endl;
			cout << "2. ����" << endl;
			cout << "3. �ϰ�" << endl;
			cin >> depSelect;

			Worker* worker = NULL;
			switch (depSelect)
			{
			case 1:
				worker = new Employee(id, newName, depSelect);
				break;
			case 2:
				worker = new Manager(id, newName, depSelect);
				break;
			case 3:
				worker = new Boss(id, newName, depSelect);
				break;
			default:
				break;
			}
			//�������� ��������
			this->w_EmpArray[ret] = worker;

			cout << "�޸ĳɹ�" << endl;

			//���浽�ļ�
			this->Save();
		}
		else
		{
			cout << "�޸�ʧ�ܣ����޴��ˣ�" << endl;
		}
	}

	system("pause");
	system("cls");
}

//����ְ��
void WorkManager::Find_Emp() {
	int type;
	cout << "�����������Ϣ�ķ�ʽ" << endl;
	cout << "1��ְԱ���" << endl;
	cout << "2��ְԱ����" << endl;
	cin >> type;

	switch (type) {
	case 1:
	{
		int id;
		cout << "������Ա����ְԱ��ţ�" << endl;
		cin >> id;

		int result = this->IsExist(id);
		if (result == -1) {
			cout << "ְ�������ڣ�" << endl;
		}
		else {
			cout << "��ѯ��Ա������ϢΪ��" << endl;
			this->showHeader();
			int deptTemp = this->w_EmpArray[result]->w_DepId;
			string deptName = deptTemp == 1 ? "��ͨԱ��" : deptTemp == 2 ? "����" : "�ϰ�";
			cout << this->w_EmpArray[result]->w_Id << "\t\t" << this->w_EmpArray[result]->w_Name<< "\t\t" << deptName << endl;
		}
	}
	break;
	case 2:
	{
		string name;
		cout << "������Ա����������" << endl;
		cin >> name;

		bool flag = false;
		for (int i = 0; i < this->w_EmpNum; i++) {
			if (this->w_EmpArray[i]->w_Name == name) {
				flag = true;
				this->showHeader();
				int deptTemp = this->w_EmpArray[i]->w_DepId;
				string deptName = deptTemp == 1 ? "��ͨԱ��" : deptTemp == 2 ? "����" : "�ϰ�";
				cout << this->w_EmpArray[i]->w_Id << "\t\t" << this->w_EmpArray[i]->w_Name << "\t\t" << deptName << endl;
				break;
			}
		}

		if (!flag) {
			cout << "û�в�ѯ��Ա����" << endl;
		}
	}
	break;
	default:
		break;
	}
	system("pause");
	system("cls");
}

void WorkManager::showHeader() {
	cout << "ְ�����" << "\t" << "ְ������" << "\t" << "ְԱ����" << endl;
}

//ְ���������ѡ������
void WorkManager:: Sort_Emp()
{
	if (this->w_FileIsEmpty)
	{
		cout << "�ļ������ڻ�����Ϊ�գ�" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "��ѡ������ʽ��" << endl;
		cout << "1����ְ������������У�" << endl;
		cout << "2����ְ����Ž������У�" << endl;
		int select = 0;
		cin >> select;

		for (int i = 0; i < w_EmpNum; i++)
		{
			int minORmax = i;
			for (int j = i + 1; j < w_EmpNum; j++)
			{
				if (select == 1)
				{
					//����
					if (w_EmpArray[minORmax]->w_Id > w_EmpArray[j]->w_Id)
					{
						minORmax = j;
					}
				}
				else
				{
					//����
					if (w_EmpArray[minORmax]->w_Id < w_EmpArray[j]->w_Id)
					{
						minORmax = j;
					}
				}
			}

			if (i != minORmax)
			{
				Worker* temp = w_EmpArray[i];
				w_EmpArray[i] = w_EmpArray[minORmax];
				w_EmpArray[minORmax] = temp;
			}
		}
		cout << "����ɹ��������Ľ��Ϊ��" << endl;
		this->Save();
		this->Show_Emp();
	}
}


//����ļ�
void WorkManager::Clean_File()
{
	cout << "ȷ����գ�" << endl;
	cout << "1��ȷ��" << endl;
	cout << "2��ȡ��" << endl;

	int select = 0;
	cin >> select;

	if (select == 1)
	{
		//��ģʽ ios::trunc ��������ļ���ɾ�������´���
		ofstream ofs(FILENAME, ios::trunc);
		ofs.close();

		if (this->w_EmpArray != NULL)
		{
			//ɾ��������ÿ��ְ������
			for (int i = 0; i < this->w_EmpNum; i++)
			{
				delete this->w_EmpArray[i];
				this->w_EmpArray[i] = NULL;
			}
			//ɾ����������ָ��
			delete[] this->w_EmpArray;
			this->w_EmpArray = NULL;
			this->w_EmpNum = 0;
			this->w_FileIsEmpty = true;
		}
		cout << "��ճɹ���" << endl;
	}
	system("pause");
	system("cls");
}

//����
WorkManager::~WorkManager()
{
	if (this->w_EmpArray != NULL)
	{
		for (int i = 0; i < this->w_EmpNum; i++)
		{
			if (this->w_EmpArray[i] != NULL)
			{
				delete this->w_EmpArray[i];
			}
		}

		delete[] this->w_EmpArray;
		this->w_EmpArray = NULL;
	}
}