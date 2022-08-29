#include "orderFile.h"


// 分割的函数
//void find_Need(string& str, int pos, map<string, string>m) {
//	string key = str.substr(0, pos);
//	string value = str.substr(pos + 1, str.size() - pos);
//	m.insert(make_pair(key, value));
//}

OrderFile::OrderFile()
{
	string date; // 日期
	string interval; // 时间段
	string stuId; // 学号
	string stuName; // 学生姓名
	string roomId; // 机房
	string status; // 预约状态

	// 初始化m_Size;
	this->m_Size = 0;
	// 用ifs开始读ORDER里的数据 读出来将其分割 放到小map容器中，再将小map容器放到大的内
	ifstream ifs;
	ifs.open(ORDER_FILE, ios::in);
	/*OrderFile o;*/
	while (ifs >> date && ifs >> interval && ifs >> stuId && ifs >> stuName && ifs >> roomId && ifs >> status) {
		// 现在读出来的都是连着的 例如现在读到的date是date：1 这也是我们遇到的问题
		/*string key;
		string value;*/
		map<string, string>m; // 小容器
		int pos = date.find(":");
		if (pos != -1) {
			// 说明找到了这个： 接下来用substr分割就好了
			string key = date.substr(0, pos);
			string value = date.substr(pos + 1, date.size() - pos);
			m.insert(make_pair(key, value));
		}

		pos = interval.find(":");
		if (pos != -1) {
			// 说明找到了这个： 接下来用substr分割就好了
			string key = interval.substr(0, pos);
			string value = interval.substr(pos + 1, interval.size() - pos);
			m.insert(make_pair(key, value));
		}

		pos = stuId.find(":");
		if (pos != -1) {
			// 说明找到了这个： 接下来用substr分割就好了
			string key = stuId.substr(0, pos);
			string value = stuId.substr(pos + 1, stuId.size() - pos);
			m.insert(make_pair(key, value));
		}

		pos = stuName.find(":");
		if (pos != -1) {
			// 说明找到了这个： 接下来用substr分割就好了
			string key = stuName.substr(0, pos);
			string value = stuName.substr(pos + 1, stuName.size() - pos);
			m.insert(make_pair(key, value));
		}

		pos = roomId.find(":");
		if (pos != -1) {
			// 说明找到了这个： 接下来用substr分割就好了
			string key = roomId.substr(0, pos);
			string value = roomId.substr(pos + 1, roomId.size() - pos);
			m.insert(make_pair(key, value));
		}

		pos = status.find(":");
		if (pos != -1) {
			// 说明找到了这个： 接下来用substr分割就好了
			string key = status.substr(0, pos);
			string value = status.substr(pos + 1, status.size() - pos);
			m.insert(make_pair(key, value));
		}

		// 把小容器放到大容器里
		this->m_orderDate.insert(make_pair(this->m_Size, m));
		this->m_Size++;
	}
	// 关闭文件 一定要记得
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
