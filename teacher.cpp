#include "teacher.h"

Teacher::Teacher()
{
}

Teacher::Teacher(int Empty, string Name, string Pwd)
{
	this->m_Empty = Empty;
	this->m_Name = Name;
	this->m_Pwd = Pwd;
}

//Teacher::~Teacher()
//{
//}

void Teacher::openMenu()
{
	cout << "��ӭ��ʦ" << this->m_Name << "��¼ϵͳ" << endl;
	cout << "-----------��ӭʹ�û���ԤԼϵͳ-------------" << endl;
	cout << "|                                          |" << endl;
	cout << "|           1���鿴����ԤԼ                |" << endl;
	cout << "|                                          |" << endl;
	cout << "|           2�����ԤԼ                    |" << endl;
	cout << "|                                          |" << endl;
	cout << "|           0��ע����¼                    |" << endl;
	cout << "|                                          |" << endl;
	cout << "--------------------------------------------" << endl;
	cout << "���������Ĳ���:" << endl;
}

void Teacher::showAllOrder()
{
	OrderFile of; // ����������е�ԤԼ
	if (of.m_Size == 0) {
		cout << "��ԤԼ��¼��" << endl;
		system("pause");
		system("cls");
		return;
	}
	for (int i = 0; i < of.m_Size; i++) {
		cout << i + 1 << "��";
		cout << "ԤԼ���ڣ���" << of.m_orderDate[i]["date"] << endl;
		cout << "ʱ��Σ�" << (of.m_orderDate[i]["interval"] == "1" ? "����" : "����") << endl;
		cout << "ѧ�ţ�" << of.m_orderDate[i]["stuId"] << endl;
		cout << "������" << of.m_orderDate[i]["stuName"] << endl;
		cout << "ԤԼ������" << of.m_orderDate[i]["roomId"] << "�Ż���" << endl;
		string status = "״̬��";
		if (of.m_orderDate[i]["status"] == "1") {
			status += "�����";
		}
		else if (of.m_orderDate[i]["status"] == "2") {
			status += "ԤԼ�ɹ�";
		}
		else if (of.m_orderDate[i]["status"] == "-1") {
			status += "ԤԼʧ��";
		}
		else {
			status += "ԤԼ��ȡ��";
		}
		cout << status << endl;
		cout << "===========================================" << endl;
	}
	system("pause");
	system("cls");
}

void Teacher::validOrder()
{
	OrderFile of;
	if (of.m_Size == 0) {
		cout << "û��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}
	int index = 1;
	vector<int>v;
	cout << "����˵���Ϣ����" << endl;
	for (int i = 0; i < of.m_Size; i++) {
		if (of.m_orderDate[i]["status"] == "1") {
			v.push_back(i);
			cout << index++ << "��";
			cout << "ԤԼ���ڣ���" << of.m_orderDate[i]["date"] << endl;
			cout << "ʱ��Σ�" << (of.m_orderDate[i]["interval"] == "1" ? "����" : "����") << endl;
			cout << "ѧ�ţ�" << of.m_orderDate[i]["stuId"] << endl;
			cout << "������" << of.m_orderDate[i]["stuName"] << endl;
			cout << "ԤԼ������" << of.m_orderDate[i]["roomId"] << "�Ż���" << endl;
			string status = "״̬��";
			if (of.m_orderDate[i]["status"] == "1") {
				status += "�����";
			}
			cout << status << endl;
			cout << "========================================" << endl;
		}
		/*else {
			cout << "û��Ҫ��˵�ԤԼ��Ϣ" << endl;
			break;
		}*/
	}
	// �ϱ��ǰѷ���Ҫ���ԤԼ��Ϣ����� �����±���ѡ���Ե��޸�
	cout << "��������Ҫ��˵�ԤԼ��¼��0������" << endl;
	int select = 0; // ��ʾ�ڼ���ԤԼ��¼
	int ret; // ��ʾ�Ƿ�ͨ��ԤԼ  1��ͨ�� 2����ͨ��
	while (true)
	{
		cin >> select;
		if (select >= 0 && select <= v.size()) {
			if (select == 0) {
				system("pause");
				system("cls");
				return;
			}
			else {
				cout << "��ȷ���Ƿ�ͨ��ԤԼ��" << endl;
				cout << "1��ͨ��" << endl;
				cout << "2����ͨ��" << endl;
				while (true) {
					cin >> ret;
					if (ret == 1) {
						of.m_orderDate[v[select - 1]]["status"] = "2";
						break;
					}
					else if (ret == 2) {
						of.m_orderDate[v[select - 1]]["status"] = "-1";
						break;
					}
					else {
						cout << "������������������";
					}
				}
				// ����ԤԼ��Ϣ
				of.updateOrder();
				cout << "������" << endl;
				system("pause");
				system("cls");
				break;
			}
		}
		else
		{
			cout << "������������������" << endl;
		}
	}
	system("pause");
	system("cls");
}
