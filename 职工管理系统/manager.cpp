#include"manager.h"

Manager::Manager(int id, string name, int did) {
	this->m_id = id;
	this->m_deptid = did;
	this->m_name = name;
}

void Manager::showInfo() {
	cout << "ְ����ţ�" << this->m_id
		<< "\tְ��������" << this->m_name
		<< "\t��λ��" << this->getDeptName()
		<< "\t��λְ������δ󽻸�������,�·��������ͨԱ��" << endl;

}//��ʾ������Ϣ

string Manager::getDeptName() {

	return string("����");
}//��ø�λְ��