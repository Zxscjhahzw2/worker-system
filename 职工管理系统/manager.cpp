#include"manager.h"

Manager::Manager(int id, string name, int did) {
	this->m_id = id;
	this->m_deptid = did;
	this->m_name = name;
}

void Manager::showInfo() {
	cout << "职工编号：" << this->m_id
		<< "\t职工姓名：" << this->m_name
		<< "\t岗位：" << this->getDeptName()
		<< "\t岗位职责：完成牢大交给的任务,下发任务给普通员工" << endl;

}//显示个人信息

string Manager::getDeptName() {

	return string("经理");
}//获得岗位职称