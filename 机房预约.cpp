#include<iostream>
#include<string>
#include<fstream>
#include"globalFile.h"
#include"identity.h"
#include"student.h"
#include"teacher.h"
#include"manager.h"
using namespace std;



/*
*  ��ʦ�Ӳ˵�����ʵ��
*  ����������ָ���µ���ʦ �ſ��Ե����Ӳ˵�����
*/
void teacherMenu(Identity*& teacher) {
	while (true) {
		teacher->openMenu();
		// Ҫ�������Լ����еĳ�Ա���� ����Ѹ���ת��Ϊ����
		Teacher* tea = (Teacher*)teacher;
		int select;
		cin >> select;
		if (select == 1) {
			tea->showAllOrder();
		}
		else if (select == 2) {
			tea->validOrder();
		}
		else if (select == 0) {
			delete teacher;
			cout << "ע���ɹ�" << endl;
			system("pause");
			system("cls");
			return;
		}
		else {
			cout << "������������������" << endl;
			system("pause");
			system("cls");
		}
	}
}
/*
*  ѧ���Ӳ˵�����ʵ��
*  ����������ָ���µ�ѧ�� �ſ��Ե����Ӳ˵�����
*/
void studentMenu(Identity*& student) {
	while (true) {
		// ����ѧ���Ӳ˵�
		student->openMenu();
		Student* stu = (Student*)student;

		int select = 0;
		cin >> select;
		if (select == 1) {
			// ����ԤԼ
			stu->applyOrder();
		}
		else if (select == 2) {
			// �鿴����ԤԼ
			stu->showMyOrder();
		}
		else if (select == 3) {
			// �鿴����ԤԼ
			stu->showAllOrder();
		}
		else if (select == 4) {
			// ȡ��ԤԼ
			stu->cancelOrder();
		}
		else if (select == 0) {
			// ע����¼ Ҫ���ʼ����ʵ�����ĳ�Աdelete��
			delete student;
			cout << "ע���ɹ���" << endl;
			system("pause");
			system("cls");
			return;
		}
		else {
			cout << "�����������������룡" << endl;
			system("pause");
			system("cls");
		}
	}
}

/*
*  ����Ա�Ӳ˵�����ʵ��
*  ����������ָ���µĹ���Ա
*/
void managerMenu(Identity * &manager) {
	while (true) {
		manager->openMenu(); // ʵ���Ӳ˵�
		Manager* man = (Manager*)manager; // �Ѹ���ǿתΪ���� ��ΪҪʵ����������й���
		int select = 0;

		cin >> select;
		if (select == 1) {
			// ����˺�
			man->addPerson();
		}
		else if (select == 2) {
			// �鿴�˺�
			man->showPerson();
		}
		else if (select == 3) {
			// �鿴����
			man->showComputer();
		}
		else if (select == 4) {
			// ���ԤԼ
			man->cleanFile();
		}
		else if (select == 0)
		{
			// ע����¼
			delete manager;
			cout << "ע���ɹ���" << endl;
			system("pause");
			system("cls");
			return;
		}
		else {
			cout << "�����������������룡" << endl;
			system("pause");
			system("cls");
		}
	}
}

/*
 �������ܣ������û���ѡ�񣬽��벻ͬ����ݵ�¼ҳ��
 ������ fileName �����ļ���  type ��¼��� 1��ѧ�� 2����ʦ 3������Ա
*/
void LoginIn(string fileName, int type) {
	// ����һ������ָ�� ����ָ��ͬ���������
	Identity* person = NULL;

	ifstream ifs;
	ifs.open(fileName, ios::in);

	if (!ifs.is_open()) {
		cout << "�ļ������ڣ�" << endl;
		ifs.close();
		return ;
	}

	int id = 0;
	string name;
	string pwd;

	if (type == 1) {
		cout << "������ѧ�ţ�" << endl;
		cin >> id;
	}
	else if (type == 2) {
		cout << "������ְ���ţ�" << endl;
		cin >> id;
	}
	cout << "������������" << endl;
	cin >> name;
	cout << "���������룺" << endl;
	cin >> pwd;

	// ��֤��¼��Ϣ�Ƿ���ȷ
	if (type == 1) {
		// ��֤ѧ����¼
		int fId;
		string fName;
		string fPwd;

		while (ifs >> fId && ifs >> fName && ifs >> fPwd) {
			if (id == fId && name == fName && pwd == fPwd) {
				cout << " ѧ����֤�ɹ��� " << endl;
				system("pause");
				system("cls");
				person = new Student(id, name, pwd);
				studentMenu(person);
				return;
			}
			else {
				break;
			}
		}
	}
	else if (type == 2) {
		// ��֤��ʦ��¼
		int fId;
		string fName;
		string fPwd;

		while (ifs >> fId && ifs >> fName && ifs >> fPwd) {
			if (id == fId && name == fName && pwd == fPwd) {
				cout << "��ʦ��֤�ɹ���" << endl;
				system("pause");
				system("cls");
				person = new Teacher(id, name, pwd);
				teacherMenu(person);
				return;
			}
			else
				break;
		}

	}
	else if (type == 3) {
		// ��֤����Ա��¼
		string fName;
		string fPwd;

		while (ifs >> fName && ifs >> fPwd) {
			if (name == fName && pwd == fPwd) {
				cout << "����Ա��֤�ɹ���" << endl;
				system("pause");
				system("cls");
				person = new Manager(name, pwd);
				// ��֤�ɹ�������Ӳ˵����� Ȼ��ʵ�ֹ���
				managerMenu(person); // ��new�����ľ����˴���
				return;
			}
		}
	}
	// �������ѧ�ų�ͻ �������벻��ȷ�� ����֤ʧ��
	cout << "��֤ʧ�ܣ�" << endl;
	system("pause");
	system("cls");
	return;
}


int main() {

	int select;

	while (true) {
		cout << "-----------��ӭʹ�û���ԤԼϵͳ-------------" << endl;
		cout << "|                                          |" << endl;
		cout << "|           1��ѧ������                    |" << endl;
		cout << "|                                          |" << endl;
		cout << "|           2����    ʦ                    |" << endl;
		cout << "|                                          |" << endl;
		cout << "|           3���� �� Ա                    |" << endl;
		cout << "|                                          |" << endl;
		cout << "|           0���˳�ϵͳ                    |" << endl;
		cout << "--------------------------------------------" << endl;
		cout << "���������Ĳ���:" << endl;
		cin >> select;

		switch (select)
		{
		case 1: // ѧ������
			LoginIn(STUDENT_FILE, 1); // ��֤��¼
			break;
		case 2: // ��ʦ
			LoginIn(TEACHER_FILE, 2);
			break;
		case 3: // ����Ա
			LoginIn(ADMIN_FILE, 3);
			break;
		case 0: // �˳�ϵͳ
			cout << "��ӭ�´�ʹ�ã�" << endl;
			system("pause");
			system("cls"); // ����Ϊ������������Ҫ ��Ϊִ�е�return0��ֱ���˳�������
			return 0;
			break;
		default:
			cout << "�����������������룡" << endl;
			system("pause");
			system("cls");
			break;
		}
	}

	system("pause");
	return 0;
}