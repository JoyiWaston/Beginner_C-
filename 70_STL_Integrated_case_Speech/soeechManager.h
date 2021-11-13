#pragma once
#include "70_STL_Integrated_case_Speech.h"

//ѡ����
class Speaker
{
public:
	string m_Name;//����
	double m_Score[2]; //���� ��������ֵ÷�
};
//�ݽ�������
class SpeechManager
{
public:
	//���캯��
	SpeechManager();

	//չʾ�˵�
	void Show_Menu();

	//�˳�ϵͳ
	void ExitSystem();

	//����ѡ�� ���� 12��
	vector<int>v1;
	//��һ�ֽ������� 6��
	vector<int>v2;
	//ʤ��ǰ�������� 3��
	vector<int>vVictory;
	//��ű�� �Լ���Ӧ�� ����ѡ�� ����
	map<int, Speaker> m_Speaker;
	//��������
	int m_Index;

	//��ʼ������
	void initSpeech();

	//��ʼ������12��ѡ��
	void CreateSpeaker();

	//��ʼ���� - �������̿���
	void startSpeech();

	//��ǩ
	void speechDraw();

	//����
	void speechContest();

	//��ʾ�������
	void showScore();

	//�����¼
	void saveRecord();

	//��ȡ��¼
	void loadRecord();
	//�ļ�Ϊ�յı�־
	bool fileIsEmpty;
	//�����¼
	map<int, vector<string>> m_Record;

	//��ʾ����÷�
	void showRecord();

	//��ռ�¼
	void clearRecord();



	//��������
	~SpeechManager();
};