#pragma once
#include<iostream>
using namespace std;
#include "worker.h"

class Boss :public Worker {
public:
	Boss(int id, string name, int did);
	virtual void showInfo() ;//显示个人信息
	virtual string getDeptName() ;//获得岗位职称
};