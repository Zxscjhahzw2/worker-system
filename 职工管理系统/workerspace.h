#pragma once
#include<iostream>
using namespace std;
#include"worker.h"
#include"Boss.h"
#include"employee.h"
#include"manager.h"
#include<fstream>
#define FILENAME "��¼.txt"


class WorkerManager
{
public:

	WorkerManager();
	
	void showMenu();//չʾ�˵�
	void exitMenu();//�Ƴ��ӿ�
	void addWorker();//���Ա��
	void save();//�����ļ�
	void initworker();//��ʼ��Ա��
	void showworker();//��ʾ��
	void modifyworker();//�޸�ְ��
	void findworker();
	void sortworker();//����
	void cleanfile(); 
	int isexit(int id);//-1�����ڣ�1����
	void deleteworker();//ɾ��ְ��
	int getworkernum();
	int m_workernum;//��¼ְ������
	Worker** m_workerarray;//ְ�������ָ��
	bool fileIfnone;//�ж��ļ��Ƿ�Ϊ��
	
	~WorkerManager();
};