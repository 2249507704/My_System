#include<iostream>
#include<string>
#include<fstream>
#include"globalFile.h"
#include"identity.h"
#include"student.h"
#include"teacher.h"
#include"manager.h"
using namespace std;



/*
*  老师子菜单功能实现
*  参数：父类指针下的老师 才可以调用子菜单函数
*/
void teacherMenu(Identity*& teacher) {
	while (true) {
		teacher->openMenu();
		// 要调用他自己特有的成员函数 必须把父类转换为子类
		Teacher* tea = (Teacher*)teacher;
		int select;
		cin >> select;
		if (select == 1) {
			tea->showAllOrder();
		}
		else if (select == 2) {
			tea->validOrder();
		}
		else if (select == 0) {
			delete teacher;
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		}
		else {
			cout << "输入有误，请重新输入" << endl;
			system("pause");
			system("cls");
		}
	}
}
/*
*  学生子菜单功能实现
*  参数：父类指针下的学生 才可以调用子菜单函数
*/
void studentMenu(Identity*& student) {
	while (true) {
		// 调用学生子菜单
		student->openMenu();
		Student* stu = (Student*)student;

		int select = 0;
		cin >> select;
		if (select == 1) {
			// 申请预约
			stu->applyOrder();
		}
		else if (select == 2) {
			// 查看自身预约
			stu->showMyOrder();
		}
		else if (select == 3) {
			// 查看所有预约
			stu->showAllOrder();
		}
		else if (select == 4) {
			// 取消预约
			stu->cancelOrder();
		}
		else if (select == 0) {
			// 注销登录 要把最开始的类实例化的成员delete掉
			delete student;
			cout << "注销成功！" << endl;
			system("pause");
			system("cls");
			return;
		}
		else {
			cout << "输入有误，请重新输入！" << endl;
			system("pause");
			system("cls");
		}
	}
}

/*
*  管理员子菜单功能实现
*  参数：父类指针下的管理员
*/
void managerMenu(Identity * &manager) {
	while (true) {
		manager->openMenu(); // 实现子菜单
		Manager* man = (Manager*)manager; // 把父类强转为子类 因为要实现子类的特有功能
		int select = 0;

		cin >> select;
		if (select == 1) {
			// 添加账号
			man->addPerson();
		}
		else if (select == 2) {
			// 查看账号
			man->showPerson();
		}
		else if (select == 3) {
			// 查看机房
			man->showComputer();
		}
		else if (select == 4) {
			// 清空预约
			man->cleanFile();
		}
		else if (select == 0)
		{
			// 注销登录
			delete manager;
			cout << "注销成功！" << endl;
			system("pause");
			system("cls");
			return;
		}
		else {
			cout << "输入有误，请重新输入！" << endl;
			system("pause");
			system("cls");
		}
	}
}

/*
 函数功能：根据用户的选择，进入不同的身份登录页面
 参数： fileName 操作文件名  type 登录身份 1、学生 2、老师 3、管理员
*/
void LoginIn(string fileName, int type) {
	// 创建一个父类指针 用于指向不同的子类对象
	Identity* person = NULL;

	ifstream ifs;
	ifs.open(fileName, ios::in);

	if (!ifs.is_open()) {
		cout << "文件不存在！" << endl;
		ifs.close();
		return ;
	}

	int id = 0;
	string name;
	string pwd;

	if (type == 1) {
		cout << "请输入学号：" << endl;
		cin >> id;
	}
	else if (type == 2) {
		cout << "请输入职工号：" << endl;
		cin >> id;
	}
	cout << "请输入姓名：" << endl;
	cin >> name;
	cout << "请输入密码：" << endl;
	cin >> pwd;

	// 验证登录信息是否正确
	if (type == 1) {
		// 验证学生登录
		int fId;
		string fName;
		string fPwd;

		while (ifs >> fId && ifs >> fName && ifs >> fPwd) {
			if (id == fId && name == fName && pwd == fPwd) {
				cout << " 学生验证成功！ " << endl;
				system("pause");
				system("cls");
				person = new Student(id, name, pwd);
				studentMenu(person);
				return;
			}
			else {
				break;
			}
		}
	}
	else if (type == 2) {
		// 验证老师登录
		int fId;
		string fName;
		string fPwd;

		while (ifs >> fId && ifs >> fName && ifs >> fPwd) {
			if (id == fId && name == fName && pwd == fPwd) {
				cout << "老师验证成功！" << endl;
				system("pause");
				system("cls");
				person = new Teacher(id, name, pwd);
				teacherMenu(person);
				return;
			}
			else
				break;
		}

	}
	else if (type == 3) {
		// 验证管理员登录
		string fName;
		string fPwd;

		while (ifs >> fName && ifs >> fPwd) {
			if (name == fName && pwd == fPwd) {
				cout << "管理员验证成功！" << endl;
				system("pause");
				system("cls");
				person = new Manager(name, pwd);
				// 验证成功后进入子菜单界面 然后实现功能
				managerMenu(person); // 把new出来的具体人传入
				return;
			}
		}
	}
	// 如果遇到学号冲突 或者密码不正确的 就验证失败
	cout << "验证失败！" << endl;
	system("pause");
	system("cls");
	return;
}


int main() {

	int select;

	while (true) {
		cout << "-----------欢迎使用机房预约系统-------------" << endl;
		cout << "|                                          |" << endl;
		cout << "|           1、学生代表                    |" << endl;
		cout << "|                                          |" << endl;
		cout << "|           2、教    师                    |" << endl;
		cout << "|                                          |" << endl;
		cout << "|           3、管 理 员                    |" << endl;
		cout << "|                                          |" << endl;
		cout << "|           0、退出系统                    |" << endl;
		cout << "--------------------------------------------" << endl;
		cout << "请输入您的操作:" << endl;
		cin >> select;

		switch (select)
		{
		case 1: // 学生代表
			LoginIn(STUDENT_FILE, 1); // 验证登录
			break;
		case 2: // 教师
			LoginIn(TEACHER_FILE, 2);
			break;
		case 3: // 管理员
			LoginIn(ADMIN_FILE, 3);
			break;
		case 0: // 退出系统
			cout << "欢迎下次使用！" << endl;
			system("pause");
			system("cls"); // 我认为这里清屏不重要 因为执行到return0就直接退出程序了
			return 0;
			break;
		default:
			cout << "输入有误，请重新输入！" << endl;
			system("pause");
			system("cls");
			break;
		}
	}

	system("pause");
	return 0;
}