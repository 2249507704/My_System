#pragma once
#include<iostream>
#include<string>
using namespace std;

class Identity {
public:
	// �����˵� ֮�����������������麯�� ��ָ���������еĲ˵�
	virtual void openMenu() = 0; // ���麯��

	// ������ݵĹ���
	string m_Name;
	string m_Pwd;
};