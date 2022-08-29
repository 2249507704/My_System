#pragma once
#include<iostream>
#include<string>
using namespace std;

class Identity {
public:
	// 操作菜单 之后子类会重新这个纯虚函数 来指向子类特有的菜单
	virtual void openMenu() = 0; // 纯虚函数

	// 三种身份的共性
	string m_Name;
	string m_Pwd;
};