#include<iostream>
using namespace std;
#include"workerspace.h"
#include"worker.h"
#include"employee.h"
#include"Boss.h"
#include"manager.h"
int main() {

	WorkerManager workermanager;
	int choice=0;
	while(1)
	{
		workermanager.showMenu();
		cout << "���������ѡ��" << endl;
		cin >> choice;
		switch (choice)
		{
		case 0://�˳�ϵͳ
			workermanager.exitMenu();
			break;
		case 1://����ְ��
			workermanager.addWorker();
			break;
		case 2://��ʾְ����Ϣ
			workermanager.showworker();
			break;
		case 3://ɾ����ְԱ��
			workermanager.deleteworker();
			break;
		case 4:///�޸�ְ��ְ��
			workermanager.modifyworker();
			break;
		case 5://����ְ����Ϣ
			workermanager.findworker();
			break;
		case 6://���ձ������
			workermanager.sortworker();
			break;
		case 7://��������ĵ�
			workermanager.cleanfile();
			break;
		default:
			break;
		}
		system("pause");
		system("cls");
	}
	




	return 0;
}