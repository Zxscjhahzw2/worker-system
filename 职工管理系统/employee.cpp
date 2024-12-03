#include "employee.h"

Employee::Employee(int id, string name, int deptid) {
	this->m_id = id;
	this->m_deptid = deptid;
	this->m_name = name;
}
 void Employee:: showInfo() {
	 cout << "职工编号：" << this->m_id
		 << "\t职工姓名：" << this->m_name
		 << "\t岗位：" << this->getDeptName()
		<< "\t岗位职责：完成经理交给的任务"<<endl;
}//显示个人信息

 string Employee::getDeptName() {
	 return string("员工");
}//获取岗位