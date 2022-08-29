#include "orderFile.h"


// �ָ�ĺ���
//void find_Need(string& str, int pos, map<string, string>m) {
//	string key = str.substr(0, pos);
//	string value = str.substr(pos + 1, str.size() - pos);
//	m.insert(make_pair(key, value));
//}

OrderFile::OrderFile()
{
	string date; // ����
	string interval; // ʱ���
	string stuId; // ѧ��
	string stuName; // ѧ������
	string roomId; // ����
	string status; // ԤԼ״̬

	// ��ʼ��m_Size;
	this->m_Size = 0;
	// ��ifs��ʼ��ORDER������� ����������ָ� �ŵ�Сmap�����У��ٽ�Сmap�����ŵ������
	ifstream ifs;
	ifs.open(ORDER_FILE, ios::in);
	/*OrderFile o;*/
	while (ifs >> date && ifs >> interval && ifs >> stuId && ifs >> stuName && ifs >> roomId && ifs >> status) {
		// ���ڶ������Ķ������ŵ� �������ڶ�����date��date��1 ��Ҳ����������������
		/*string key;
		string value;*/
		map<string, string>m; // С����
		int pos = date.find(":");
		if (pos != -1) {
			// ˵���ҵ�������� ��������substr�ָ�ͺ���
			string key = date.substr(0, pos);
			string value = date.substr(pos + 1, date.size() - pos);
			m.insert(make_pair(key, value));
		}

		pos = interval.find(":");
		if (pos != -1) {
			// ˵���ҵ�������� ��������substr�ָ�ͺ���
			string key = interval.substr(0, pos);
			string value = interval.substr(pos + 1, interval.size() - pos);
			m.insert(make_pair(key, value));
		}

		pos = stuId.find(":");
		if (pos != -1) {
			// ˵���ҵ�������� ��������substr�ָ�ͺ���
			string key = stuId.substr(0, pos);
			string value = stuId.substr(pos + 1, stuId.size() - pos);
			m.insert(make_pair(key, value));
		}

		pos = stuName.find(":");
		if (pos != -1) {
			// ˵���ҵ�������� ��������substr�ָ�ͺ���
			string key = stuName.substr(0, pos);
			string value = stuName.substr(pos + 1, stuName.size() - pos);
			m.insert(make_pair(key, value));
		}

		pos = roomId.find(":");
		if (pos != -1) {
			// ˵���ҵ�������� ��������substr�ָ�ͺ���
			string key = roomId.substr(0, pos);
			string value = roomId.substr(pos + 1, roomId.size() - pos);
			m.insert(make_pair(key, value));
		}

		pos = status.find(":");
		if (pos != -1) {
			// ˵���ҵ�������� ��������substr�ָ�ͺ���
			string key = status.substr(0, pos);
			string value = status.substr(pos + 1, status.size() - pos);
			m.insert(make_pair(key, value));
		}

		// ��С�����ŵ���������
		this->m_orderDate.insert(make_pair(this->m_Size, m));
		this->m_Size++;
	}
	// �ر��ļ� һ��Ҫ�ǵ�
	ifs.close();
	/*for (map<int, map<string, string>>::iterator it = m_orderDate.begin(); it != m_orderDate.end(); it++) {
		cout << "key = " << it->first << "value = " << endl;
		for (map<string,string>::iterator mit = m.begin)
	}*/
}

void OrderFile::updateOrder()
{
	if (this->m_Size == 0) {
		return;
	}
	ofstream ofs;
	ofs.open(ORDER_FILE, ios::in | ios::trunc);

	for (int i = 0; i < this->m_Size; i++) {
		ofs << "date:" << this->m_orderDate[i]["date"] << " ";
		ofs << "interval:" << this->m_orderDate[i]["interval"] << " ";
		ofs << "stuId:" << this->m_orderDate[i]["stuId"] << " ";
		ofs << "stuName:" << this->m_orderDate[i]["stuName"] << " ";
		ofs << "roomId:" << this->m_orderDate[i]["roomId"] << " ";
		ofs << "status:" << this->m_orderDate[i]["status"] << " ";
	}
	ofs.close();
}
