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
	Student(); // Ĭ�Ϲ���

	Student(int Id,string Name,string Pwd); // �вι��� �������ʵ����

	// ~Student(); // ����

	void openMenu(); // ��̬

	void applyOrder(); // ����ԤԼ

	void showMyOrder(); // �鿴����ԤԼ

	void showAllOrder(); // �鿴����ԤԼ

	void cancelOrder(); // ȡ��ԤԼ

	vector<ComputerRoom> vCom; // ��������

	void initvCom(); // ��ʼ����������

	int m_Id; // ѧ��ѧ��
};