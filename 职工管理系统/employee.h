#pragma once
//��ͨԱ��

#include "worker.h"

class Employee :public Worker {
public:
	Employee(int id, string name, int deptid);
	virtual void showInfo() ;//��ʾ������Ϣ
	virtual string getDeptName();//��ø�λְ��
};