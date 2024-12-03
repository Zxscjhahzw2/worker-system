#pragma once
#include<string>
#include<iostream>
using namespace std;

class Worker {//职工抽象类
public:


	virtual void showInfo() = 0;//显示个人信息
	virtual string getDeptName() = 0;//获得岗位职称
	int m_id;//职工编号
	string m_name;//职工姓名
	int m_deptid;//部门编号


};