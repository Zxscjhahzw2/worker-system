#include"workerspace.h"

WorkerManager::WorkerManager() {

	//1.文件不存在情况
	ifstream ifs;
	ifs.open(FILENAME, ios::in);//读文件
	if (!ifs.is_open()) {
		cout << "文件不存在" << endl;
		this->m_workernum = 0;
		this->m_workerarray = NULL;
		this->fileIfnone = true;
		ifs.close();
		return;
	}
	//2.文件存在数据为空
	char ch;
	ifs >> ch;
	if (ifs.eof()) {
		cout << "文件为空" << endl;
		this->m_workernum = 0;
		this->m_workerarray = NULL;
		this->fileIfnone = true;
		ifs.close();
		return;
	}
	//3.当文件存在并且记录数据
	int num = this->getworkernum();
	//cout << "职工人数为：" << num << endl;
	this->m_workernum = num;

	this->m_workerarray = new Worker * [this->m_workernum];//开辟空间
	this->initworker();//将文件数据存放到数组
}//构造函数

WorkerManager::~WorkerManager() {
	if (this->m_workerarray != NULL) {
		delete[]this->m_workerarray;
		this->m_workerarray = NULL;
	}
}//析构函数

void WorkerManager::showMenu() {
	cout << "*****************************************" << endl;
	cout << "***********欢迎使用职工管理系统**********" << endl;
	cout << "***********0.退出管理程序****************" << endl;
	cout << "***********1.增加职工信息****************" << endl;
	cout << "***********2.显示职工信息****************" << endl;
	cout << "***********3.删除离职职工****************" << endl;
	cout << "***********4.修改职工信息****************" << endl;
	cout << "***********5.查找职工信息****************" << endl;
	cout << "***********6.按照编号排序****************" << endl;
	cout << "***********7.清空所有文档****************" << endl;
	cout << "*****************************************" << endl;
}
void WorkerManager::exitMenu() {
	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(0);
}

void WorkerManager::addWorker() {
	cout << "请输入添加的职工数量" << endl;
	int addnum = 0;
	cin >> addnum;

	if (addnum > 0) {
		//add
		//计算添加的新空间大小
		int newsize = this->m_workernum + addnum;
		//开辟新空间
		Worker* *newspace= new Worker*[newsize];
		//将原来数据拷贝过来
		if (this->m_workerarray != NULL) {
			for (int i = 0; i < this->m_workernum; i++) {
				newspace[i] = this->m_workerarray[i];
			}
		}
		//添加新数据
		for (int i = 0; i < addnum; i++) {
			int id;
			string name;
			int did;//部门choice
			cout << "请输入第" << i + 1 << "个新职工的编号" << endl;
			cin >> id;
			cout << "请输入第" << i + 1 << "个新职工的姓名" << endl;
			cin >> name;
			cout << "请选择该职工的岗位：" << endl;
			cout << "1.普通职工" << endl;
			cout << "2.经理" << endl;
			cout << "3.老板" << endl; 
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
			//将创建的职工指针保存到数组中
			newspace[this->m_workernum + i] = worker;
		}
		//释放原有的空间
		delete[] this->m_workerarray;
		//更改新空间的指向
		this->m_workerarray = newspace;
		//更新新的职工人数
		this->m_workernum = newsize;
		//提示添加成功
		this->fileIfnone = false;//文件不为空
		cout << "成功添加" << addnum << "名新职工！" << endl;
		this->save();//保存数据到文件中
	}
	else {
		cout << "输入有误" << endl;
		//false
	}
}//添加职工

void WorkerManager::save(){
	ofstream ofs;
	ofs.open(FILENAME, ios::out);//用输出的方式打开文件

	//将每个人的数据写入到文件中
	for (int i = 0; i<this->m_workernum; i++) {
		ofs << this->m_workerarray[i]->m_id << " "
			<< this->m_workerarray[i]->m_name << " "
			<< this->m_workerarray[i]->m_deptid << endl;
	}
	//关闭
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
	//判断问键是否为空
	if (this->fileIfnone) {
		cout << "文件不存在或记录为空" << endl;
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
		cout << "文件不存在" << endl;
	}
	else {
		cout << "请输入想删除的职工编号：" << endl;
		int id = 0;
		cin >> id;
		int index = this->isexit(id);
		if (index != -1) {
			for (int i = index; i < this->m_workernum - 1; i++) {

				this->m_workerarray[i] = this->m_workerarray[i + 1];
			}
			this->m_workernum--;//更新数组记录人数
			//数据同步更新到文件
			this->save();
		}
		else {
			cout << "无该员工" << endl;
		}
	}
}

void WorkerManager::modifyworker() {

	if (this->fileIfnone) {
		cout << "文件不存在或记录为空" << endl;
	}
	else {
		cout << "请输入修改职工的编号" << endl;
		int id;
		cin >> id;
		int ret = this->isexit(id);

		if (ret != -1) {
			delete this->m_workerarray[ret];
			int newid = 0;
			string newname = "";
			int newdid = 0;
			cout << "查到:" << id << "号职工，请输入新职工号:" << endl;
			cin >> newid;
			cout << "请输入新姓名" << endl;
			cin >> newname;
			cout << "请输入新岗位" << endl;
			cout << "1.普通职工" << endl;
			cout << "2.经理" << endl;
			cout << "3.老板" << endl;
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
			//更新数据
			this->m_workerarray[ret] = worker;
			cout << "修改成功" << endl;
			//保存到文件
			this->save();
		}
		else {
			cout << "无该员工" << endl;
		}

	}
}

void WorkerManager::findworker() {
	if (this->fileIfnone) {
		cout << "文件不存在或记录为空" << endl;
	}
	else {
		int select=0;
		cout << "输入查找方式：" << endl;
		cout << "1.按职工编号查找" << endl;
		cout << "2.按姓名来查找" << endl;
		cin >> select;
		if (select == 1) {
			int id;
			cout << "输入编号:" << endl;
			cin >> id;
			int ret = this->isexit(id);
			if (ret != -1) {
				cout << "查找成功，职工信息如下:" << endl;
				this->m_workerarray[ret]->showInfo();
			}
			else {
				cout << "查无此人" << endl;
			}
		}
		if (select == 2) {
			string name;
			cout << "输入姓名:" << endl;
			cin >> name;
			//加入判断是否查到
			bool flag = false;//默认未找到
			for (int i = 0; i < this->m_workernum; i++) {
				if (this->m_workerarray[i]->m_name == name) {
					cout << "查找成功，职工编号为" << this->m_workerarray[i]->m_id << "号职工信息如下：" << endl;
					this->m_workerarray[i]->showInfo();
					flag = true;
					break;
				}
			}
			if(flag==false)
				cout << "查无此人" << endl;

		}
	}
}

void WorkerManager::sortworker() {
	if (this->fileIfnone) {
		cout << "文件不存在或记录为空" << endl;
	}

	else {
		cout << "选择排列方式" << endl;
		cout << "1.按升序排列" << endl;
		cout << "2.按降序排列" << endl;

		int select = 0;
		cin >> select;
		for (int i = 0; i < this->m_workernum; i++) {
			int minormax = i;
			for (int j = i + 1; j < this->m_workernum; j++) {
				if (select == 1) {//升序
					if (this->m_workerarray[minormax]->m_id > this->m_workerarray[j]->m_id) {
						minormax = j;
					}
				}
				else {//降序
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
		cout << "排序成功" << endl;
		this->save();
		this->showworker();
	}
}

void WorkerManager::cleanfile() {
	cout << "确认清空请输入1" << endl;
	int select = 0;
	cin >> select;
	if (select == 1) {
		//清文件
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
		cout << "清空成功" << endl;
	}
	else {
		cout << "返回" << endl;
	}
}