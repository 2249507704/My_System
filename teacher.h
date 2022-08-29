#pragma once
#include"identity.h"
#include"orderFile.h"
#include<vector>
class Teacher : public Identity {
public:
	Teacher(); // 默认构造

	Teacher(int Empty,string Name,string Pwd); // 默认有参构造

	// ~Teacher(); // 析构

	void openMenu(); // 显示老师菜单

	void showAllOrder(); // 查看所有预约

	void validOrder(); // 审核预约

	int m_Empty; // 教师编号
};