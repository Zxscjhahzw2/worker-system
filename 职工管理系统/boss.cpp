#include"Boss.h"

Boss::Boss(int id, string name, int did) {
	this->m_id = id;
	this->m_deptid = did;
	this->m_name = name;
}

void Boss::showInfo() {
	cout << "ְ����ţ�" << this->m_id
		<< "\tְ��������" << this->m_name
		<< "\t��λ��" << this->getDeptName()
		<< "\t��λְ���·����������" << endl;

}//��ʾ������Ϣ

string Boss::getDeptName() {

	return string("�δ�");
}//��ø�λְ��