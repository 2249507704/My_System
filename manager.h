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
	Manager(); // Ĭ�Ϲ���

	Manager(string Name,string Pwd); // Ĭ���вι���

	void openMenu(); // ��д���ി�麯��

	void addPerson(); // ����˺�

	void showPerson(); // �鿴�˺�

	void showComputer(); // �鿴������Ϣ

	void cleanFile(); // ���ԤԼ��¼

	void initVector(); // ��ʼ������

	vector<Student> vStu; // ���ѧ����Ϣ������

	vector<Teacher> vTea; // �����ʦ��Ϣ������

	bool checkRepeat(int id, int type); // �ж��Ƿ����ظ�Ԫ�� �� ����true û�� ����false

	vector<ComputerRoom> vCom; // ��Ż�����Ϣ������

	void initvCom(); // ��ʼ����������

};