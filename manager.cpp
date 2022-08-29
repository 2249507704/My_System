#include "manager.h"

Manager::Manager()
{
}

Manager::Manager(string Name, string Pwd)
{
	this->m_Name = Name;
	this->m_Pwd = Pwd;

	this->initVector(); // 初始化容器
	this->initvCom(); // 初始化机房容器
}

void Manager::openMenu()
{
	cout << "欢迎管理员" << this->m_Name << "登录！" << endl;
	cout << "-----------欢迎使用机房预约系统-------------" << endl;
	cout << "|                                          |" << endl;
	cout << "|           1、添加账号                    |" << endl;
	cout << "|                                          |" << endl;
	cout << "|           2、查看账号                    |" << endl;
	cout << "|                                          |" << endl;
	cout << "|           3、查看机房                    |" << endl;
	cout << "|                                          |" << endl;
	cout << "|           4、清空预约                    |" << endl;
	cout << "|                                          |" << endl;
	cout << "|           0、注销登录                    |" << endl;
	cout << "|                                          |" << endl;
	cout << "--------------------------------------------" << endl;
	cout << "请输入您的操作:" << endl;
}

/* 添加账号，添加时要求id不能重复 */
void Manager::addPerson()
{
	cout << "请输入您要添加的成员：" << endl;
	cout << "1、学生代表" << endl;
	cout << "2、老师" << endl;

	string fileName; // 要操作的文件
	string tip; // 因为id有两种 这个tip用与提示用户
	ofstream ofs; // 写文件的对象
	string errorTip; // 检查到有重复id号添加进来的错误提示

	// 根据不同的输入用ofs打开不同的文件 以及 有不同的提示
	int select = 0;
	while (true)
	{
		cin >> select;

		if (select == 1) {
			// 添加学生
			fileName = STUDENT_FILE;
			tip = "请输入学生学号：";
			errorTip = "您输入的学号出现重复情况，请确定后再重新输入！";
			// 这里可能要加个break
			break;
		}
		else if (select == 2) {
			// 添加老师
			fileName = TEACHER_FILE;
			tip = "请输入教师职工号：";
			errorTip = "您输入的职工号出现重复情况，请确定后再重新输入！";
			break;
		}
		else {
			cout << "输入有误，请重新输入！" << endl;
			system("pause");
			system("cls");
			return;
		}
	}

	// 根据select选好了文件 接下来用ofs打开文件 来写入添加的成员
	ofs.open(fileName,ios::out | ios::app);
	// 创建三个变量 用于接受用户的输入
	int id;
	string name;
	string pwd;
	// 输入提示 开始用ofs进行写入
	cout << tip << endl;

	while (true) {
		cin >> id;
		bool ret = this->checkRepeat(id, select);
		if (ret) {
			cout << errorTip << endl;
			system("pause");
			system("cls");
			return;
		}
		else {
			break;
		}
	}

	cout << "请输入您的姓名：" << endl;
	cin >> name;

	cout << "请输入您的密码：" << endl;
	cin >> pwd;

	// 输入完毕后用ofs将信息写入对应的文件中
	ofs << id << " " << name << " " << pwd << " " << endl;

	system("pause");
	system("cls");

	ofs.close();

	// 解决bug1 在添加完一个人后 要立马更新容器 这样就不会出现一次性重复添加的bug了
	this->initVector();
}

void printStudent(Student& s)
{
	cout << "学号：" << s.m_Id << " " << "姓名：" << s.m_Name << " " << "密码：" << s.m_Pwd << " " << endl;
}

void printTeacher(Teacher& t)
{
	cout << "职工号：" << t.m_Empty << " " << "姓名：" << t.m_Name << " " << "密码：" << t.m_Pwd << " " << endl;
}


void Manager::showPerson()
{
	cout << "请输入您要查看的类型：" << endl;
	cout << "1、学生代表" << endl;
	cout << "2、老师" << endl;

	int select = 0;
	while (true) {
		cin >> select;
		if (select == 1) {
			// 查看学生信息 遍历学生容器就行
			if (vStu.size() == 0) {
				cout << "当前学生文件没有成员！请添加后查看。" << endl;
				break;
			}
			else {
				cout << "所有学生信息如下：" << endl;
				for_each(vStu.begin(), vStu.end(), printStudent);
				break;
			}
		}
		else if (select == 2) {
			// 查看老师信息 遍历学生容器就行
			if (vTea.size() == 0) {
				cout << "当前老师文件没有成员！请添加后查看。" << endl;
				break;
			}
			else {
				cout << "所有老师信息如下：" << endl;
				for_each(vTea.begin(), vTea.end(), printTeacher);
				break;	
			}
		}
		else {
			cout << "输入有误，请重新输入！" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
	system("pause");
	system("cls");
}

void Manager::showComputer()
{
	// 遍历机房容器 输出
	for (auto iter : vCom) {
		cout << "机房编号：" << iter.m_ComId << " " << "该机房最大容量为：" << iter.m_MaxNum << " " << endl;
	}
	system("pause");
	system("cls");
}

void Manager::cleanFile()
{
	ofstream ofs;
	ofs.open(ORDER_FILE, ios::out | ios::trunc);
	ofs.close();
	cout << "清空成功！" << endl;
	system("pause");
	system("cls");
}
/* 初始化容器 分别把学生和老师的信息读出来放到对应的容器里 便于以后查重 */
void Manager::initVector()
{
	vStu.clear();
	vTea.clear();
	// 先读学生的信息
	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);

	if (!ifs.is_open()) {
		cout << "文件不存在！" << endl;
		return;
	}

	// 现在文件也有了 创建一个student去读
	Student s;
	while (ifs >> s.m_Id && ifs >> s.m_Name && ifs >> s.m_Pwd) {
		vStu.push_back(s);
	}
	cout << "学生一共有" << vStu.size() << "人" << endl;
	ifs.close();

	// 开始读老师信息
	ifs.open(TEACHER_FILE, ios::in);
	Teacher t;
	while (ifs >> t.m_Empty && ifs >> t.m_Name && ifs >> t.m_Pwd) {
		vTea.push_back(t);
	}
	cout << "老师一共有" << vTea.size() << "人" << endl;
	ifs.close();
}

/* 检查是否有id号重复的函数 */
bool Manager::checkRepeat(int id, int type)
{
	if (type == 1) {
		// 类型是学生
		// 遍历vStu容器 看看id号是不是一样
		for (auto iter : vStu) {
			if (id == iter.m_Id) {
				return true;
			}
		}
	}
	else {
		// 遍历的是老师
		for (auto iter : vTea) {
			if (id == iter.m_Empty) {
				return true;
			}
		}
	}
	return false;
}

// 初始化机房容器 在manager的有参构造中实现
void Manager::initvCom()
{
	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in); // 读文件两件套

	if (!ifs.is_open()) {
		cout << "文件不存在！" << endl;
		return;
	}
	ComputerRoom c;

	while (ifs >> c.m_ComId && ifs >> c.m_MaxNum) {
		vCom.push_back(c);
	}
	cout << "当前机房数量为：" << vCom.size() << endl;
	ifs.close();
}

