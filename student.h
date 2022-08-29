#pragma once
#include"identity.h"
#include<vector>
#include"computerRoom.h"
#include<fstream>
#include"globalFile.h"
#include"orderFile.h"
#include<string>
class Student :public Identity {
public:
	Student(); // 默认构造

	Student(int Id,string Name,string Pwd); // 有参构造 用来后边实例化

	// ~Student(); // 析构

	void openMenu(); // 多态

	void applyOrder(); // 申请预约

	void showMyOrder(); // 查看自身预约

	void showAllOrder(); // 查看所有预约

	void cancelOrder(); // 取消预约

	vector<ComputerRoom> vCom; // 机房容器

	void initvCom(); // 初始化机房容器

	int m_Id; // 学生学号
};