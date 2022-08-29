#include "student.h"

Student::Student()
{
}

Student::Student(int Id, string Name, string Pwd)
{
	// 初始化有参构造
	this->m_Id = Id;
	this->m_Name = Name;
	this->m_Pwd = Pwd;
	this->initvCom();
}

//Student::~Student()
//{
//}

void Student::openMenu()
{
	cout << "欢迎学生代表" << this->m_Name << "登录！" << endl;
	cout << "-----------欢迎使用机房预约系统-------------" << endl;
	cout << "|                                          |" << endl;
	cout << "|           1、申请预约                    |" << endl;
	cout << "|                                          |" << endl;
	cout << "|           2、查看自身预约                |" << endl;
	cout << "|                                          |" << endl;
	cout << "|           3、查看所有预约                |" << endl;
	cout << "|                                          |" << endl;
	cout << "|           4、取消预约                    |" << endl;
	cout << "|                                          |" << endl;
	cout << "|           0、注销登录                    |" << endl;
	cout << "|                                          |" << endl;
	cout << "--------------------------------------------" << endl;
	cout << "请输入您的操作:" << endl;
}

void Student::applyOrder()
{
	int date; // 日期
	int interval; // 上下午
	int room; // 机房号
	cout << "请输入您要预约的日期：" << endl;
	cout << "1、周一" << endl;
	cout << "2、周二" << endl;
	cout << "3、周三" << endl;
	cout << "4、周四" << endl;
	cout << "5、周五" << endl;
	
	while (true) {
		cin >> date;
		if (date >= 1 && date <= 5) {
			break;
		}
		cout << "输入有误，请重新输入！" << endl;
	}
	// 预约时间段
	cout << "请输入您要预约的时间段：" << endl;
	cout << "1、上午" << endl;
	cout << "2、下午" << endl;
	while (true) {
		cin >> interval;
		if (interval >= 1 && interval <= 2) {
			break;
		}
		cout << "输入有误，请重新输入！" << endl;
	}

	// 预约几号机房
	cout << "请输入您要预约的机房：" << endl;
	cout << "1号机房的容量为：" << vCom[0].m_MaxNum << endl;
	cout << "2号机房的容量为：" << vCom[1].m_MaxNum << endl;
	cout << "3号机房的容量为：" << vCom[2].m_MaxNum << endl;
	while (true) {
		cin >> room;
		if (room >= 1 && room <= 3) {
			break;
		}
		cout << "输入有误，请重新输入！" << endl;
	}

	cout << "预约信息录入成功！请等待老师的审核！" << endl;

	// 用ofs把信息写入到预约信息的文件中
	ofstream ofs;
	ofs.open(ORDER_FILE, ios::app);
	// 写信息
	ofs << "date:" << date << " ";
	ofs << "interval:" << interval << " ";
	ofs << "stuId:" << this->m_Id << " ";
	ofs << "stuName:" << this->m_Name << " ";
	ofs << "roomId:" << room << " ";
	ofs << "status:" << 1 << endl; // 1 为审核中

	// 关闭文件
	ofs.close();
	system("pause");
	system("cls");
}

void Student::showMyOrder()
{
	OrderFile of; // 创建好了就会调用构造函数
	if (of.m_Size == 0) {
		cout << "没有预约信息！" << endl;
		system("pause");
		system("cls");
		return;
	}
	// 找到自身的预约信息
	for (int i = 0; i < of.m_Size; i++) {
		if (this->m_Id == atoi(of.m_orderDate[i]["stuId"].c_str())) {
			cout << "预约日期：周" << of.m_orderDate[i]["date"] << " " << endl;
			cout << "预约时间段：" << (of.m_orderDate[i]["interval"] == "1" ? "上午" : "下午") << " " << endl;
			cout << "预约机房：" << of.m_orderDate[i]["roomId"] << "号机房" << " " << endl;
			string status = "状态："; // 0取消预约 1 审核中 2 预约成功 -1 预约失败
			if (of.m_orderDate[i]["status"] == "1") {
				status += "审核中";
			}
			else if (of.m_orderDate[i]["status"] == "2") {
				status += "预约成功";
			}
			else if (of.m_orderDate[i]["status"] == "-1") {
				status += "预约失败";
			}
			else {
				status += "预约已取消";
			}
			cout << status << endl;
			cout << "===========================================" << endl;
		}

	}
	system("pause");
	system("cls");
}

void Student::showAllOrder()
{
	OrderFile of; // 这里边有所有的预约
	if (of.m_Size == 0) {
		cout << "无预约记录！" << endl;
		system("pause");
		system("cls");
		return;
	}
	for (int i = 0; i < of.m_Size; i++) {
		cout << i + 1 << "、";
		cout << "预约日期：周" << of.m_orderDate[i]["date"] << endl;
		cout << "时间段：" << (of.m_orderDate[i]["interval"] == "1"?"上午":"下午") << endl;
		cout << "学号：" << of.m_orderDate[i]["stuId"] << endl;
		cout << "姓名：" << of.m_orderDate[i]["stuName"] << endl;
		cout << "预约机房：" << of.m_orderDate[i]["roomId"] << "号机房" << endl;
		string status = "状态：";
		if (of.m_orderDate[i]["status"] == "1") {
			status += "审核中";
		}
		else if (of.m_orderDate[i]["status"] == "2") {
			status += "预约成功";
		}
		else if (of.m_orderDate[i]["status"] == "-1") {
			status += "预约失败";
		}
		else {
			status += "预约已取消";
		}
		cout << status << endl;
		cout << "===========================================" << endl;
	}
	system("pause");
	system("cls");
}

void Student::cancelOrder()
{
	OrderFile of;
	if (of.m_Size == 0) {
		cout << "没有预约记录！" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "审核中的或者预约成功的可以取消预约" << endl;
	int index = 1;
	vector<int>v; // 用来存放满足条件的预约信息
	for (int i = 0; i < of.m_Size; i++) {
		// 只能自己修改自己的信息
		if (this->m_Id == atoi(of.m_orderDate[i]["stuId"].c_str())) {
			// 并且只有审核中和预约成功的可以取消 1 2
			if (of.m_orderDate[i]["status"] == "0" || of.m_orderDate[i]["status"] == "1") {
				// 把满足条件的放进容器里
				v.push_back(i);
				cout << index++ << "、" << endl;
				cout << "预约日期：周" << of.m_orderDate[i]["date"] << endl;
				cout << "预约时间段：" << (of.m_orderDate[i]["interval"] == "1"?"上午":"下午") << endl;
				cout << "预约机房：" << of.m_orderDate[i]["roomId"] << "号机房" << endl;
				string status = "状态：";
				if (of.m_orderDate[i]["status"] == "1") {
					status += "审核中";
				}
				else if (of.m_orderDate[i]["status"] == "2") {
					status += "预约成功";
				}
				cout << status << endl;
			}
		}
	}
	cout << "请输入要取消的记录，0代表返回" << endl;
	int select;
	while (true) {
		cin >> select;
		if (select >= 0 && select <= v.size()) {
			if (select == 0) {
				break;
			}
			else {
				// 找到要修改的信息 然后把他的status改为0
				// 在容器里找 因为符合条件的都放在容器里了
				of.m_orderDate[v[select - 1]]["status"] = "0";
				of.updateOrder();
				cout << "取消成功" << endl;
				break;
			}
		}
		else {
			cout << "输入有误，请重新输入" << endl;
		}
	}
	system("pause");
	system("cls");
}

void Student::initvCom()
{
	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);
	ComputerRoom c;
	while (ifs >> c.m_ComId && ifs >> c.m_MaxNum) {
		vCom.push_back(c);
	}
	ifs.close();
}
