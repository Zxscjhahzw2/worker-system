#pragma once
#include<iostream>
using namespace std;
#include"worker.h"
#include"Boss.h"
#include"employee.h"
#include"manager.h"
#include<fstream>
#define FILENAME "记录.txt"


class WorkerManager
{
public:

	WorkerManager();
	
	void showMenu();//展示菜单
	void exitMenu();//推出接口
	void addWorker();//添加员工
	void save();//保存文件
	void initworker();//初始化员工
	void showworker();//显示中
	void modifyworker();//修改职工
	void findworker();
	void sortworker();//排序
	void cleanfile(); 
	int isexit(int id);//-1表不存在，1存在
	void deleteworker();//删除职工
	int getworkernum();
	int m_workernum;//记录职工人数
	Worker** m_workerarray;//职工数组的指针
	bool fileIfnone;//判断文件是否为空
	
	~WorkerManager();
};