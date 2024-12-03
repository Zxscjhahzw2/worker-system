#pragma once
//普通员工

#include "worker.h"

class Employee :public Worker {
public:
	Employee(int id, string name, int deptid);
	virtual void showInfo() ;//显示个人信息
	virtual string getDeptName();//获得岗位职称
};