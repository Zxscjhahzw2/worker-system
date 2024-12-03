#include"workerspace.h"

WorkerManager::WorkerManager() {

	//1.�ļ����������
	ifstream ifs;
	ifs.open(FILENAME, ios::in);//���ļ�
	if (!ifs.is_open()) {
		cout << "�ļ�������" << endl;
		this->m_workernum = 0;
		this->m_workerarray = NULL;
		this->fileIfnone = true;
		ifs.close();
		return;
	}
	//2.�ļ���������Ϊ��
	char ch;
	ifs >> ch;
	if (ifs.eof()) {
		cout << "�ļ�Ϊ��" << endl;
		this->m_workernum = 0;
		this->m_workerarray = NULL;
		this->fileIfnone = true;
		ifs.close();
		return;
	}
	//3.���ļ����ڲ��Ҽ�¼����
	int num = this->getworkernum();
	//cout << "ְ������Ϊ��" << num << endl;
	this->m_workernum = num;

	this->m_workerarray = new Worker * [this->m_workernum];//���ٿռ�
	this->initworker();//���ļ����ݴ�ŵ�����
}//���캯��

WorkerManager::~WorkerManager() {
	if (this->m_workerarray != NULL) {
		delete[]this->m_workerarray;
		this->m_workerarray = NULL;
	}
}//��������

void WorkerManager::showMenu() {
	cout << "*****************************************" << endl;
	cout << "***********��ӭʹ��ְ������ϵͳ**********" << endl;
	cout << "***********0.�˳��������****************" << endl;
	cout << "***********1.����ְ����Ϣ****************" << endl;
	cout << "***********2.��ʾְ����Ϣ****************" << endl;
	cout << "***********3.ɾ����ְְ��****************" << endl;
	cout << "***********4.�޸�ְ����Ϣ****************" << endl;
	cout << "***********5.����ְ����Ϣ****************" << endl;
	cout << "***********6.���ձ������****************" << endl;
	cout << "***********7.��������ĵ�****************" << endl;
	cout << "*****************************************" << endl;
}
void WorkerManager::exitMenu() {
	cout << "��ӭ�´�ʹ��" << endl;
	system("pause");
	exit(0);
}

void WorkerManager::addWorker() {
	cout << "��������ӵ�ְ������" << endl;
	int addnum = 0;
	cin >> addnum;

	if (addnum > 0) {
		//add
		//������ӵ��¿ռ��С
		int newsize = this->m_workernum + addnum;
		//�����¿ռ�
		Worker* *newspace= new Worker*[newsize];
		//��ԭ�����ݿ�������
		if (this->m_workerarray != NULL) {
			for (int i = 0; i < this->m_workernum; i++) {
				newspace[i] = this->m_workerarray[i];
			}
		}
		//���������
		for (int i = 0; i < addnum; i++) {
			int id;
			string name;
			int did;//����choice
			cout << "�������" << i + 1 << "����ְ���ı��" << endl;
			cin >> id;
			cout << "�������" << i + 1 << "����ְ��������" << endl;
			cin >> name;
			cout << "��ѡ���ְ���ĸ�λ��" << endl;
			cout << "1.��ְͨ��" << endl;
			cout << "2.����" << endl;
			cout << "3.�ϰ�" << endl; 
			cin >> did;

			Worker* worker = NULL;
			switch (did)
			{
			case 1:
				worker = new Employee(id, name, did);
				break;
			case 2:
				worker = new Manager(id, name, did);
				break;
			case 3:
				worker = new Boss(id, name, did);
				break;
			default:
				break;
			}
			//��������ְ��ָ�뱣�浽������
			newspace[this->m_workernum + i] = worker;
		}
		//�ͷ�ԭ�еĿռ�
		delete[] this->m_workerarray;
		//�����¿ռ��ָ��
		this->m_workerarray = newspace;
		//�����µ�ְ������
		this->m_workernum = newsize;
		//��ʾ��ӳɹ�
		this->fileIfnone = false;//�ļ���Ϊ��
		cout << "�ɹ����" << addnum << "����ְ����" << endl;
		this->save();//�������ݵ��ļ���
	}
	else {
		cout << "��������" << endl;
		//false
	}
}//���ְ��

void WorkerManager::save(){
	ofstream ofs;
	ofs.open(FILENAME, ios::out);//������ķ�ʽ���ļ�

	//��ÿ���˵�����д�뵽�ļ���
	for (int i = 0; i<this->m_workernum; i++) {
		ofs << this->m_workerarray[i]->m_id << " "
			<< this->m_workerarray[i]->m_name << " "
			<< this->m_workerarray[i]->m_deptid << endl;
	}
	//�ر�
	ofs.close();
}

int WorkerManager::getworkernum() {
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int did;

	int num=0;
	while (ifs >> id && ifs >> name && ifs >> did) {
		num++;
	}
	return num;
}

void WorkerManager::initworker() {
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int did=0;
	int index=0;
	while (ifs >> id && ifs >> name && ifs >> did) {

		Worker* worker = NULL;
		if (did == 1) {
			worker = new Employee(id, name, did);
		}
		else if (did == 2) {
			worker = new Manager(id, name, did);
		}
		else {
			worker = new Boss(id, name, did);
		}
		this->m_workerarray[index] = worker;
		index++;

		
	}
	ifs.close();
}

void WorkerManager::showworker() {
	//�ж��ʼ��Ƿ�Ϊ��
	if (this->fileIfnone) {
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
	}
	else {
		for (int i = 0; i < m_workernum; i++) {
			this->m_workerarray[i]->showInfo();
		}
	}
}


int WorkerManager::isexit(int id){
	int index = -1;
	for (int i = 0; i < this->m_workernum; i++) {
		if (this->m_workerarray[i]->m_id == id) {
			index = i;
			break;
		}
	}
	return index;
}
void WorkerManager::deleteworker(){
	if (this->fileIfnone) {
		cout << "�ļ�������" << endl;
	}
	else {
		cout << "��������ɾ����ְ����ţ�" << endl;
		int id = 0;
		cin >> id;
		int index = this->isexit(id);
		if (index != -1) {
			for (int i = index; i < this->m_workernum - 1; i++) {

				this->m_workerarray[i] = this->m_workerarray[i + 1];
			}
			this->m_workernum--;//���������¼����
			//����ͬ�����µ��ļ�
			this->save();
		}
		else {
			cout << "�޸�Ա��" << endl;
		}
	}
}

void WorkerManager::modifyworker() {

	if (this->fileIfnone) {
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
	}
	else {
		cout << "�������޸�ְ���ı��" << endl;
		int id;
		cin >> id;
		int ret = this->isexit(id);

		if (ret != -1) {
			delete this->m_workerarray[ret];
			int newid = 0;
			string newname = "";
			int newdid = 0;
			cout << "�鵽:" << id << "��ְ������������ְ����:" << endl;
			cin >> newid;
			cout << "������������" << endl;
			cin >> newname;
			cout << "�������¸�λ" << endl;
			cout << "1.��ְͨ��" << endl;
			cout << "2.����" << endl;
			cout << "3.�ϰ�" << endl;
			cin >> newdid;

			Worker* worker = NULL;
			switch (newdid)
			{
			case 1:
				worker = new Employee(newid, newname, newdid);
				break;
			case 2:
				worker = new Manager(newid, newname, newdid);
				break;
			case 3:
				worker = new Boss(newid, newname, newdid);
				break;
			default:
				break;
			}
			//��������
			this->m_workerarray[ret] = worker;
			cout << "�޸ĳɹ�" << endl;
			//���浽�ļ�
			this->save();
		}
		else {
			cout << "�޸�Ա��" << endl;
		}

	}
}

void WorkerManager::findworker() {
	if (this->fileIfnone) {
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
	}
	else {
		int select=0;
		cout << "������ҷ�ʽ��" << endl;
		cout << "1.��ְ����Ų���" << endl;
		cout << "2.������������" << endl;
		cin >> select;
		if (select == 1) {
			int id;
			cout << "������:" << endl;
			cin >> id;
			int ret = this->isexit(id);
			if (ret != -1) {
				cout << "���ҳɹ���ְ����Ϣ����:" << endl;
				this->m_workerarray[ret]->showInfo();
			}
			else {
				cout << "���޴���" << endl;
			}
		}
		if (select == 2) {
			string name;
			cout << "��������:" << endl;
			cin >> name;
			//�����ж��Ƿ�鵽
			bool flag = false;//Ĭ��δ�ҵ�
			for (int i = 0; i < this->m_workernum; i++) {
				if (this->m_workerarray[i]->m_name == name) {
					cout << "���ҳɹ���ְ�����Ϊ" << this->m_workerarray[i]->m_id << "��ְ����Ϣ���£�" << endl;
					this->m_workerarray[i]->showInfo();
					flag = true;
					break;
				}
			}
			if(flag==false)
				cout << "���޴���" << endl;

		}
	}
}

void WorkerManager::sortworker() {
	if (this->fileIfnone) {
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
	}

	else {
		cout << "ѡ�����з�ʽ" << endl;
		cout << "1.����������" << endl;
		cout << "2.����������" << endl;

		int select = 0;
		cin >> select;
		for (int i = 0; i < this->m_workernum; i++) {
			int minormax = i;
			for (int j = i + 1; j < this->m_workernum; j++) {
				if (select == 1) {//����
					if (this->m_workerarray[minormax]->m_id > this->m_workerarray[j]->m_id) {
						minormax = j;
					}
				}
				else {//����
					if (this->m_workerarray[minormax]->m_id < this->m_workerarray[j]->m_id) {
						minormax = j;
					}
				}
			}
			if (i != minormax) {
				Worker* temp = this->m_workerarray[i];
				this->m_workerarray[i] = this->m_workerarray[minormax];
				this->m_workerarray[minormax] = temp;
			}
		}
		cout << "����ɹ�" << endl;
		this->save();
		this->showworker();
	}
}

void WorkerManager::cleanfile() {
	cout << "ȷ�����������1" << endl;
	int select = 0;
	cin >> select;
	if (select == 1) {
		//���ļ�
		ofstream ofs(FILENAME, ios::trunc);
		ofs.close();

		if (this->m_workerarray != NULL) {
			for (int i = 0; i < this->m_workernum; i++) {
				delete this->m_workerarray[i];
				this->m_workerarray[i] = NULL;
			}
			delete[]this->m_workerarray;
			this->m_workerarray = NULL;
			this->m_workernum = 0;
			this->fileIfnone = true;
		}
		cout << "��ճɹ�" << endl;
	}
	else {
		cout << "����" << endl;
	}
}