#include "employee.h"

Employee::Employee(int id, string name, int deptid) {
	this->m_id = id;
	this->m_deptid = deptid;
	this->m_name = name;
}
 void Employee:: showInfo() {
	 cout << "ְ����ţ�" << this->m_id
		 << "\tְ��������" << this->m_name
		 << "\t��λ��" << this->getDeptName()
		<< "\t��λְ����ɾ�����������"<<endl;
}//��ʾ������Ϣ

 string Employee::getDeptName() {
	 return string("Ա��");
}//��ȡ��λ