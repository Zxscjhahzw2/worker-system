#pragma once
#include<string>
#include<iostream>
using namespace std;

class Worker {//ְ��������
public:


	virtual void showInfo() = 0;//��ʾ������Ϣ
	virtual string getDeptName() = 0;//��ø�λְ��
	int m_id;//ְ�����
	string m_name;//ְ������
	int m_deptid;//���ű��


};