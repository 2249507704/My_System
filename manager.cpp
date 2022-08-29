#include "manager.h"

Manager::Manager()
{
}

Manager::Manager(string Name, string Pwd)
{
	this->m_Name = Name;
	this->m_Pwd = Pwd;

	this->initVector(); // ��ʼ������
	this->initvCom(); // ��ʼ����������
}

void Manager::openMenu()
{
	cout << "��ӭ����Ա" << this->m_Name << "��¼��" << endl;
	cout << "-----------��ӭʹ�û���ԤԼϵͳ-------------" << endl;
	cout << "|                                          |" << endl;
	cout << "|           1������˺�                    |" << endl;
	cout << "|                                          |" << endl;
	cout << "|           2���鿴�˺�                    |" << endl;
	cout << "|                                          |" << endl;
	cout << "|           3���鿴����                    |" << endl;
	cout << "|                                          |" << endl;
	cout << "|           4�����ԤԼ                    |" << endl;
	cout << "|                                          |" << endl;
	cout << "|           0��ע����¼                    |" << endl;
	cout << "|                                          |" << endl;
	cout << "--------------------------------------------" << endl;
	cout << "���������Ĳ���:" << endl;
}

/* ����˺ţ����ʱҪ��id�����ظ� */
void Manager::addPerson()
{
	cout << "��������Ҫ��ӵĳ�Ա��" << endl;
	cout << "1��ѧ������" << endl;
	cout << "2����ʦ" << endl;

	string fileName; // Ҫ�������ļ�
	string tip; // ��Ϊid������ ���tip������ʾ�û�
	ofstream ofs; // д�ļ��Ķ���
	string errorTip; // ��鵽���ظ�id����ӽ����Ĵ�����ʾ

	// ���ݲ�ͬ��������ofs�򿪲�ͬ���ļ� �Լ� �в�ͬ����ʾ
	int select = 0;
	while (true)
	{
		cin >> select;

		if (select == 1) {
			// ���ѧ��
			fileName = STUDENT_FILE;
			tip = "������ѧ��ѧ�ţ�";
			errorTip = "�������ѧ�ų����ظ��������ȷ�������������룡";
			// �������Ҫ�Ӹ�break
			break;
		}
		else if (select == 2) {
			// �����ʦ
			fileName = TEACHER_FILE;
			tip = "�������ʦְ���ţ�";
			errorTip = "�������ְ���ų����ظ��������ȷ�������������룡";
			break;
		}
		else {
			cout << "�����������������룡" << endl;
			system("pause");
			system("cls");
			return;
		}
	}

	// ����selectѡ�����ļ� ��������ofs���ļ� ��д����ӵĳ�Ա
	ofs.open(fileName,ios::out | ios::app);
	// ������������ ���ڽ����û�������
	int id;
	string name;
	string pwd;
	// ������ʾ ��ʼ��ofs����д��
	cout << tip << endl;

	while (true) {
		cin >> id;
		bool ret = this->checkRepeat(id, select);
		if (ret) {
			cout << errorTip << endl;
			system("pause");
			system("cls");
			return;
		}
		else {
			break;
		}
	}

	cout << "����������������" << endl;
	cin >> name;

	cout << "�������������룺" << endl;
	cin >> pwd;

	// ������Ϻ���ofs����Ϣд���Ӧ���ļ���
	ofs << id << " " << name << " " << pwd << " " << endl;

	system("pause");
	system("cls");

	ofs.close();

	// ���bug1 �������һ���˺� Ҫ����������� �����Ͳ������һ�����ظ���ӵ�bug��
	this->initVector();
}

void printStudent(Student& s)
{
	cout << "ѧ�ţ�" << s.m_Id << " " << "������" << s.m_Name << " " << "���룺" << s.m_Pwd << " " << endl;
}

void printTeacher(Teacher& t)
{
	cout << "ְ���ţ�" << t.m_Empty << " " << "������" << t.m_Name << " " << "���룺" << t.m_Pwd << " " << endl;
}


void Manager::showPerson()
{
	cout << "��������Ҫ�鿴�����ͣ�" << endl;
	cout << "1��ѧ������" << endl;
	cout << "2����ʦ" << endl;

	int select = 0;
	while (true) {
		cin >> select;
		if (select == 1) {
			// �鿴ѧ����Ϣ ����ѧ����������
			if (vStu.size() == 0) {
				cout << "��ǰѧ���ļ�û�г�Ա������Ӻ�鿴��" << endl;
				break;
			}
			else {
				cout << "����ѧ����Ϣ���£�" << endl;
				for_each(vStu.begin(), vStu.end(), printStudent);
				break;
			}
		}
		else if (select == 2) {
			// �鿴��ʦ��Ϣ ����ѧ����������
			if (vTea.size() == 0) {
				cout << "��ǰ��ʦ�ļ�û�г�Ա������Ӻ�鿴��" << endl;
				break;
			}
			else {
				cout << "������ʦ��Ϣ���£�" << endl;
				for_each(vTea.begin(), vTea.end(), printTeacher);
				break;	
			}
		}
		else {
			cout << "�����������������룡" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
	system("pause");
	system("cls");
}

void Manager::showComputer()
{
	// ������������ ���
	for (auto iter : vCom) {
		cout << "������ţ�" << iter.m_ComId << " " << "�û����������Ϊ��" << iter.m_MaxNum << " " << endl;
	}
	system("pause");
	system("cls");
}

void Manager::cleanFile()
{
	ofstream ofs;
	ofs.open(ORDER_FILE, ios::out | ios::trunc);
	ofs.close();
	cout << "��ճɹ���" << endl;
	system("pause");
	system("cls");
}
/* ��ʼ������ �ֱ��ѧ������ʦ����Ϣ�������ŵ���Ӧ�������� �����Ժ���� */
void Manager::initVector()
{
	vStu.clear();
	vTea.clear();
	// �ȶ�ѧ������Ϣ
	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);

	if (!ifs.is_open()) {
		cout << "�ļ������ڣ�" << endl;
		return;
	}

	// �����ļ�Ҳ���� ����һ��studentȥ��
	Student s;
	while (ifs >> s.m_Id && ifs >> s.m_Name && ifs >> s.m_Pwd) {
		vStu.push_back(s);
	}
	cout << "ѧ��һ����" << vStu.size() << "��" << endl;
	ifs.close();

	// ��ʼ����ʦ��Ϣ
	ifs.open(TEACHER_FILE, ios::in);
	Teacher t;
	while (ifs >> t.m_Empty && ifs >> t.m_Name && ifs >> t.m_Pwd) {
		vTea.push_back(t);
	}
	cout << "��ʦһ����" << vTea.size() << "��" << endl;
	ifs.close();
}

/* ����Ƿ���id���ظ��ĺ��� */
bool Manager::checkRepeat(int id, int type)
{
	if (type == 1) {
		// ������ѧ��
		// ����vStu���� ����id���ǲ���һ��
		for (auto iter : vStu) {
			if (id == iter.m_Id) {
				return true;
			}
		}
	}
	else {
		// ����������ʦ
		for (auto iter : vTea) {
			if (id == iter.m_Empty) {
				return true;
			}
		}
	}
	return false;
}

// ��ʼ���������� ��manager���вι�����ʵ��
void Manager::initvCom()
{
	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in); // ���ļ�������

	if (!ifs.is_open()) {
		cout << "�ļ������ڣ�" << endl;
		return;
	}
	ComputerRoom c;

	while (ifs >> c.m_ComId && ifs >> c.m_MaxNum) {
		vCom.push_back(c);
	}
	cout << "��ǰ��������Ϊ��" << vCom.size() << endl;
	ifs.close();
}

