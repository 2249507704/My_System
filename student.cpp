#include "student.h"

Student::Student()
{
}

Student::Student(int Id, string Name, string Pwd)
{
	// ��ʼ���вι���
	this->m_Id = Id;
	this->m_Name = Name;
	this->m_Pwd = Pwd;
	this->initvCom();
}

//Student::~Student()
//{
//}

void Student::openMenu()
{
	cout << "��ӭѧ������" << this->m_Name << "��¼��" << endl;
	cout << "-----------��ӭʹ�û���ԤԼϵͳ-------------" << endl;
	cout << "|                                          |" << endl;
	cout << "|           1������ԤԼ                    |" << endl;
	cout << "|                                          |" << endl;
	cout << "|           2���鿴����ԤԼ                |" << endl;
	cout << "|                                          |" << endl;
	cout << "|           3���鿴����ԤԼ                |" << endl;
	cout << "|                                          |" << endl;
	cout << "|           4��ȡ��ԤԼ                    |" << endl;
	cout << "|                                          |" << endl;
	cout << "|           0��ע����¼                    |" << endl;
	cout << "|                                          |" << endl;
	cout << "--------------------------------------------" << endl;
	cout << "���������Ĳ���:" << endl;
}

void Student::applyOrder()
{
	int date; // ����
	int interval; // ������
	int room; // ������
	cout << "��������ҪԤԼ�����ڣ�" << endl;
	cout << "1����һ" << endl;
	cout << "2���ܶ�" << endl;
	cout << "3������" << endl;
	cout << "4������" << endl;
	cout << "5������" << endl;
	
	while (true) {
		cin >> date;
		if (date >= 1 && date <= 5) {
			break;
		}
		cout << "�����������������룡" << endl;
	}
	// ԤԼʱ���
	cout << "��������ҪԤԼ��ʱ��Σ�" << endl;
	cout << "1������" << endl;
	cout << "2������" << endl;
	while (true) {
		cin >> interval;
		if (interval >= 1 && interval <= 2) {
			break;
		}
		cout << "�����������������룡" << endl;
	}

	// ԤԼ���Ż���
	cout << "��������ҪԤԼ�Ļ�����" << endl;
	cout << "1�Ż���������Ϊ��" << vCom[0].m_MaxNum << endl;
	cout << "2�Ż���������Ϊ��" << vCom[1].m_MaxNum << endl;
	cout << "3�Ż���������Ϊ��" << vCom[2].m_MaxNum << endl;
	while (true) {
		cin >> room;
		if (room >= 1 && room <= 3) {
			break;
		}
		cout << "�����������������룡" << endl;
	}

	cout << "ԤԼ��Ϣ¼��ɹ�����ȴ���ʦ����ˣ�" << endl;

	// ��ofs����Ϣд�뵽ԤԼ��Ϣ���ļ���
	ofstream ofs;
	ofs.open(ORDER_FILE, ios::app);
	// д��Ϣ
	ofs << "date:" << date << " ";
	ofs << "interval:" << interval << " ";
	ofs << "stuId:" << this->m_Id << " ";
	ofs << "stuName:" << this->m_Name << " ";
	ofs << "roomId:" << room << " ";
	ofs << "status:" << 1 << endl; // 1 Ϊ�����

	// �ر��ļ�
	ofs.close();
	system("pause");
	system("cls");
}

void Student::showMyOrder()
{
	OrderFile of; // �������˾ͻ���ù��캯��
	if (of.m_Size == 0) {
		cout << "û��ԤԼ��Ϣ��" << endl;
		system("pause");
		system("cls");
		return;
	}
	// �ҵ������ԤԼ��Ϣ
	for (int i = 0; i < of.m_Size; i++) {
		if (this->m_Id == atoi(of.m_orderDate[i]["stuId"].c_str())) {
			cout << "ԤԼ���ڣ���" << of.m_orderDate[i]["date"] << " " << endl;
			cout << "ԤԼʱ��Σ�" << (of.m_orderDate[i]["interval"] == "1" ? "����" : "����") << " " << endl;
			cout << "ԤԼ������" << of.m_orderDate[i]["roomId"] << "�Ż���" << " " << endl;
			string status = "״̬��"; // 0ȡ��ԤԼ 1 ����� 2 ԤԼ�ɹ� -1 ԤԼʧ��
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

	}
	system("pause");
	system("cls");
}

void Student::showAllOrder()
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
		cout << "ʱ��Σ�" << (of.m_orderDate[i]["interval"] == "1"?"����":"����") << endl;
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

void Student::cancelOrder()
{
	OrderFile of;
	if (of.m_Size == 0) {
		cout << "û��ԤԼ��¼��" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "����еĻ���ԤԼ�ɹ��Ŀ���ȡ��ԤԼ" << endl;
	int index = 1;
	vector<int>v; // �����������������ԤԼ��Ϣ
	for (int i = 0; i < of.m_Size; i++) {
		// ֻ���Լ��޸��Լ�����Ϣ
		if (this->m_Id == atoi(of.m_orderDate[i]["stuId"].c_str())) {
			// ����ֻ������к�ԤԼ�ɹ��Ŀ���ȡ�� 1 2
			if (of.m_orderDate[i]["status"] == "0" || of.m_orderDate[i]["status"] == "1") {
				// �����������ķŽ�������
				v.push_back(i);
				cout << index++ << "��" << endl;
				cout << "ԤԼ���ڣ���" << of.m_orderDate[i]["date"] << endl;
				cout << "ԤԼʱ��Σ�" << (of.m_orderDate[i]["interval"] == "1"?"����":"����") << endl;
				cout << "ԤԼ������" << of.m_orderDate[i]["roomId"] << "�Ż���" << endl;
				string status = "״̬��";
				if (of.m_orderDate[i]["status"] == "1") {
					status += "�����";
				}
				else if (of.m_orderDate[i]["status"] == "2") {
					status += "ԤԼ�ɹ�";
				}
				cout << status << endl;
			}
		}
	}
	cout << "������Ҫȡ���ļ�¼��0������" << endl;
	int select;
	while (true) {
		cin >> select;
		if (select >= 0 && select <= v.size()) {
			if (select == 0) {
				break;
			}
			else {
				// �ҵ�Ҫ�޸ĵ���Ϣ Ȼ�������status��Ϊ0
				// ���������� ��Ϊ���������Ķ�������������
				of.m_orderDate[v[select - 1]]["status"] = "0";
				of.updateOrder();
				cout << "ȡ���ɹ�" << endl;
				break;
			}
		}
		else {
			cout << "������������������" << endl;
		}
	}
	system("pause");
	system("cls");
}

void Student::initvCom()
{
	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);
	ComputerRoom c;
	while (ifs >> c.m_ComId && ifs >> c.m_MaxNum) {
		vCom.push_back(c);
	}
	ifs.close();
}
