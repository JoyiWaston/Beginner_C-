#include "44_Initialization_and_cleanup_of_objects.h"

//��ǳ����Ϊ���Ծ���޿�
//ǳ�������򵥵ĸ�ֵ��������					����������:�������ڴ��ظ��ͷ�
//������ڶ�����������ռ䣬���п�������		���ǳ��������������


class Person
{
public:
	Person()
	{
		cout << "Person��Ĭ�Ϲ��캯������" << endl;
	}
	Person(int age,int Height)
	{
		m_Age = age;
		m_Height = new int(Height);
		cout << "Person���вι��캯������" << endl;
	}
	
	//�Լ�ʵ�ֿ������캯�����ǳ��������������
	Person(const Person& z)
	{
		cout << "Person�Ŀ�����������" << endl;
		m_Age = z.m_Age;
		//m_Height = p.m_Height;      ������Ĭ��ʵ�ִ��д���
		//�������

		m_Height = new int(*z.m_Height);

	}

	~Person()
	{
		//�������룬���������ٵ��������ͷŲ���
		if (m_Height != NULL)
		{
			delete m_Height;
			m_Height = NULL;		//��ֹҰָ�����
		}
		cout << "Person��������������" << endl;
	}

	int m_Age;
	int* m_Height;
};

void test05()
{
	Person p1(18,180);

	cout << "p1�����䣺" << p1.m_Age << "���Ϊ��" << *p1.m_Height << endl;

	Person p9 = Person (p1);

	cout << "p9�����䣺" << p9.m_Age << "���Ϊ��" << *p9.m_Height << endl;
}
int main()
{
	test05();
}