#pragma once
#include<iostream>
#include"globalFile.h"
#include<string>
#include<map>
#include<fstream>
using namespace std;

class OrderFile {
public:

	OrderFile(); // Ĭ�Ϲ���

	void updateOrder(); // ����ԤԼ��¼

	map<int, map<string, string>>m_orderDate; // ��¼ԤԼ��¼�Ĺ��캯��

	int m_Size; // ԤԼ��¼������
};