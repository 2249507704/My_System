#pragma once
#include"identity.h"
#include"orderFile.h"
#include<vector>
class Teacher : public Identity {
public:
	Teacher(); // Ĭ�Ϲ���

	Teacher(int Empty,string Name,string Pwd); // Ĭ���вι���

	// ~Teacher(); // ����

	void openMenu(); // ��ʾ��ʦ�˵�

	void showAllOrder(); // �鿴����ԤԼ

	void validOrder(); // ���ԤԼ

	int m_Empty; // ��ʦ���
};