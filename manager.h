#pragma once
#include"identity.h"
#include<fstream>
#include"globalFile.h"
#include<vector>
#include"student.h"
#include"teacher.h"
#include<algorithm>
#include"computerRoom.h"

class Manager : public Identity {
public:
	Manager(); // 默认构造

	Manager(string Name,string Pwd); // 默认有参构造

	void openMenu(); // 重写父类纯虚函数

	void addPerson(); // 添加账号

	void showPerson(); // 查看账号

	void showComputer(); // 查看机房信息

	void cleanFile(); // 清空预约记录

	void initVector(); // 初始化容器

	vector<Student> vStu; // 存放学生信息的容器

	vector<Teacher> vTea; // 存放老师信息的容器

	bool checkRepeat(int id, int type); // 判断是否有重复元素 有 返回true 没有 返回false

	vector<ComputerRoom> vCom; // 存放机房信息的容器

	void initvCom(); // 初始化机房容器

};