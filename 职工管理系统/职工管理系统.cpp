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
		cout << "请输入你的选择" << endl;
		cin >> choice;
		switch (choice)
		{
		case 0://退出系统
			workermanager.exitMenu();
			break;
		case 1://增加职工
			workermanager.addWorker();
			break;
		case 2://显示职工信息
			workermanager.showworker();
			break;
		case 3://删除离职员工
			workermanager.deleteworker();
			break;
		case 4:///修改职工职称
			workermanager.modifyworker();
			break;
		case 5://查找职工信息
			workermanager.findworker();
			break;
		case 6://按照编号排序
			workermanager.sortworker();
			break;
		case 7://清空所有文档
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