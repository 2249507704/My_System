#pragma once
#include<iostream>
#include"globalFile.h"
#include<string>
#include<map>
#include<fstream>
using namespace std;

class OrderFile {
public:

	OrderFile(); // 默认构造

	void updateOrder(); // 更新预约记录

	map<int, map<string, string>>m_orderDate; // 记录预约记录的构造函数

	int m_Size; // 预约记录的条数
};