#include"Boss.h"

Boss::Boss(int id, string name, int did) {
	this->m_id = id;
	this->m_deptid = did;
	this->m_name = name;
}

void Boss::showInfo() {
	cout << "职工编号：" << this->m_id
		<< "\t职工姓名：" << this->m_name
		<< "\t岗位：" << this->getDeptName()
		<< "\t岗位职责：下发任务给经理" << endl;

}//显示个人信息

string Boss::getDeptName() {

	return string("牢大");
}//获得岗位职称