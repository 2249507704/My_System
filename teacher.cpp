#include "teacher.h"

Teacher::Teacher()
{
}

Teacher::Teacher(int Empty, string Name, string Pwd)
{
	this->m_Empty = Empty;
	this->m_Name = Name;
	this->m_Pwd = Pwd;
}

//Teacher::~Teacher()
//{
//}

void Teacher::openMenu()
{
	cout << "欢迎教师" << this->m_Name << "登录系统" << endl;
	cout << "-----------欢迎使用机房预约系统-------------" << endl;
	cout << "|                                          |" << endl;
	cout << "|           1、查看所有预约                |" << endl;
	cout << "|                                          |" << endl;
	cout << "|           2、审核预约                    |" << endl;
	cout << "|                                          |" << endl;
	cout << "|           0、注销登录                    |" << endl;
	cout << "|                                          |" << endl;
	cout << "--------------------------------------------" << endl;
	cout << "请输入您的操作:" << endl;
}

void Teacher::showAllOrder()
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
		cout << "时间段：" << (of.m_orderDate[i]["interval"] == "1" ? "上午" : "下午") << endl;
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

void Teacher::validOrder()
{
	OrderFile of;
	if (of.m_Size == 0) {
		cout << "没有预约记录" << endl;
		system("pause");
		system("cls");
		return;
	}
	int index = 1;
	vector<int>v;
	cout << "待审核的信息如下" << endl;
	for (int i = 0; i < of.m_Size; i++) {
		if (of.m_orderDate[i]["status"] == "1") {
			v.push_back(i);
			cout << index++ << "、";
			cout << "预约日期：周" << of.m_orderDate[i]["date"] << endl;
			cout << "时间段：" << (of.m_orderDate[i]["interval"] == "1" ? "上午" : "下午") << endl;
			cout << "学号：" << of.m_orderDate[i]["stuId"] << endl;
			cout << "姓名：" << of.m_orderDate[i]["stuName"] << endl;
			cout << "预约机房：" << of.m_orderDate[i]["roomId"] << "号机房" << endl;
			string status = "状态：";
			if (of.m_orderDate[i]["status"] == "1") {
				status += "审核中";
			}
			cout << status << endl;
			cout << "========================================" << endl;
		}
		/*else {
			cout << "没有要审核的预约信息" << endl;
			break;
		}*/
	}
	// 上边是把符合要求的预约信息都输出 供给下边来选择性的修改
	cout << "请输入您要审核的预约记录，0代表返回" << endl;
	int select = 0; // 表示第几条预约记录
	int ret; // 表示是否通过预约  1、通过 2、不通过
	while (true)
	{
		cin >> select;
		if (select >= 0 && select <= v.size()) {
			if (select == 0) {
				system("pause");
				system("cls");
				return;
			}
			else {
				cout << "请确认是否通过预约：" << endl;
				cout << "1、通过" << endl;
				cout << "2、不通过" << endl;
				while (true) {
					cin >> ret;
					if (ret == 1) {
						of.m_orderDate[v[select - 1]]["status"] = "2";
						break;
					}
					else if (ret == 2) {
						of.m_orderDate[v[select - 1]]["status"] = "-1";
						break;
					}
					else {
						cout << "输入有误，请重新输入";
					}
				}
				// 更新预约信息
				of.updateOrder();
				cout << "审核完毕" << endl;
				system("pause");
				system("cls");
				break;
			}
		}
		else
		{
			cout << "输入有误，请重新输入" << endl;
		}
	}
	system("pause");
	system("cls");
}
