#include "User.h"
#include "Complex.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <fstream>
#include <ctime>
#include <Windows.h>

using namespace std;
User::User() {
};
User::~User(){
};

// mẫu đăng kí
void User::subscription() {
	cin.clear();
	cin.ignore();
	//Nhập vào Họ và tên, họ và tên chỉ có thể chứa kí tự
	cout << "Nhap ho va ten : ";
	string str1, str2, str3, str4, str5;
	getline(cin, str1);
	if (str1.length() > 40 || str1.length() == 0) {
		system("cls");
		cout << "Do dai Ho Ten khong hop le";
		subscription();
		return;
	};
	xoaKhoangTrong(str1);
	if (chu(str1) == false) {
		system("cls");
		cout << "Ho va ten chi co the chua ki tu !";
		subscription();
		return;
	};
	//Nhập nghề nghiệp :
	cout << "Nhap nghe nghiep : ";
	getline(cin, str2);
	if (str2.length() > 30) {
		system("cls");
		cout << "Do dai nghe nghiep khong the qua 30 ki tu";
		subscription();
		return;
	};
	// Nhập địa chỉ :
	cout << "Nhap dia chi : ";
	getline(cin, str3);
	if (str3.length() > 40) {
		system("cls");
		cout << "Do dai dia chi khong the qua 40 ki tu";
		subscription();
		return;
	};
	// Nhập mã số chứng minh nhân dân, cmnd chỉ có thể chứa chữ số
	cout << "Nhap ma so chung minh nhan dan : ";
	getline(cin, str4);
	if (number(str4) == false) {
		system("cls");
		cout << "So chung minh nhan dan khong ton tai !";
		subscription();
		return;
	};
	// Nhập vào số điện thoại, số điện thoại chỉ có thể chứa chữ số
	cout << "Nhap so dien thoai : ";
	getline(cin, str5);
	if (number(str5) == false) {
		system("cls");
		cout << "So dien thoai khong ton tai !";
		subscription();
		return;
	};

	cout << "Gui dang ki thanh cong !" << endl;
	cout << "Ban hay den thu vien gan nhat de xac nhan thanh vien" << endl;
	Sleep(1000);
	strcpy_s(m_hoTen, str1.c_str());
	strcpy_s(m_job, str2.c_str());
	strcpy_s(m_address, str3.c_str());;
	strcpy_s(m_cmnd, str4.c_str());
	strcpy_s(m_sdt, str5.c_str());
	m_id = tinhSoLuong() + 1;
	setTime();
};

// lưu thông tin User vào file "Users.dat"
void User::ghi() {
	ofstream ghi("Users.dat", ios::app | ios ::binary);
	if (ghi) ghi.write(reinterpret_cast <const char *> (this), sizeof(User));
};


void User::doc() {
	ifstream doc("Users.dat", ios::app);
	if (doc) doc.read(reinterpret_cast <char *> (this), sizeof(User));
};


ostream &operator << (ostream &xuat, User &x){
	xuat << "Ma so ID : " << x.getID() << endl;
	xuat << "Ho va ten : " << x.getHoTen() << endl;
	xuat << "Nghe nghiep hien tai : " << x.getJob() << endl;
	xuat << "Dia chi : " << x.getAddress() << endl;
	xuat << "So dien thoai : " << x.getSDT() << endl;
	xuat << "Chung minh nhan dan so : " << x.getCMND() << endl;
	xuat << "Ngay dang ki : " << x.thoiGianDangKi() << endl;
	return xuat;
};

// Phương thức tìm kiếm User, k là mã số tìm kiếm (1 : tìm theo tên, 2 : tìm theo mã số ID, 3 : tìm theo CMND)
// str là từ khóa tìm kiếm
// valid là giá trị tìm được, trả về false nếu không tìm thấy sách nào
void User::find(int k, string str, bool &valid) {
	// Tạo mảng để lưu mã số các User tìm được
	ifstream doc("Users.dat", ios::app);
	// i lưu vị trí con trỏ trỏ đến trong file User
	// ds là biến chạy thứ tự sách
	int i = 0, ds = 0;
	while (!doc.eof()) {
		doc.seekg(sizeof(User) * i);
		doc.read(reinterpret_cast <char *> (this), sizeof(User));
		// Tìm kiếm theo tên
		if (k == 1) {
			if (m_hoTen == str) {
				//In thông tin tìm kiếm
				thongTinTimKiem(ds);	
				luuTamThoi();
			};
		};
		// Tìm kiếm theo ISBN
		if (k == 2) {
			stringstream ss; ss << m_id;
			string str2; ss >> str2;
			if (str2 == str) {
				thongTinTimKiem(ds);
				luuTamThoi();
			};
		};
		// Tìm kiếm theo số cmnd
		if (k == 3) {
			if (m_cmnd == str) {
				thongTinTimKiem(ds);
				luuTamThoi();
			};
		};
		i++;
	};

	// Khi không tìm được kết quả nào thì chương trình sẽ không tạo table
	if (ds == 0) valid = false;
	else {
		valid = true;
		cout << "-------------------------------------------------------------------------------------------------" << endl;
	};
};

// lấy mã id lưu trong file tạm cho User được chọn trong danh sách tìm kiếm
void User::layID(int k) {
	string str;
	int id;
	ifstream doc1("luutam.txt");
	for (int i = 1; i < k; i++) getline(doc1, str);
	doc1 >> id;
	ifstream doc2("Users.dat", ios::app);
	// Di chuyển con trỏ tìm kiếm đến ID tương ứng
	doc2.seekg((id - 1) * sizeof(User));
	doc2.read(reinterpret_cast <char *> (this), sizeof(User));
};

void User::khoaUser() {
	m_active = false;
};


int User::getID() {
	return m_id;
};
string User::getHoTen() {
	return m_hoTen;
};
string User::getJob() {
	return m_job;
};
string User::getAddress() {
	return m_address;
};
string User::getSDT() {
	return m_sdt;
};
string User::getCMND() {
	return m_cmnd;
};
int *User::getTime() {
	return m_time;
};

void User::setJob(string str) {
	strcpy_s(m_job, str.c_str());
};
void User::setAddress(string str) {
	strcpy_s(m_address, str.c_str());
};
void User::setSDT(string str) {
	strcpy_s(m_sdt, str.c_str());
}

int User::tinhSoLuong() {
	ifstream doc("Users.dat", ios::app);

	////Kiểm tra file User là rỗng hay không, nếu không có dữ liệu thì so luong = 0
	doc.seekg(sizeof(User), ios::end);
	doc.read(reinterpret_cast <char *> (this), sizeof(User));

	////Kiểm tra số lượng sách bằng cách đọc id ở cuối
	//int i = 0;
	//if (doc) {
	//	while (!doc.eof()) {
	//		doc.seekg(sizeof(User)*i);
	//		doc.read(reinterpret_cast <char *> (this), sizeof(User));
	//		i++;
	//	};
	//};

	return m_id;
};

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Private:

void User::setTime() {
	time_t now = time(0);
	tm t;
	localtime_s(&t, &now);
	m_time[0] = t.tm_mday;
	m_time[1] = t.tm_mon + 1;
	m_time[2] = t.tm_year + 1900;
	m_time[3] = t.tm_hour;
	m_time[4] = t.tm_min;
	m_time[5] = t.tm_sec;
};

//lưu danh sách tìm kiếm
void User::luuTamThoi() {
	ofstream ghi("luutam.txt", ios::app);
	ghi << m_id << "\n";
};

// In thông tin theo định dạng table
void User::thongTinTimKiem(int &ds) {
	cout << "|" << setw(5) << left << ds + 1;
	cout << "|" << setw(8) << m_id;
	cout << "|" << setw(25) << m_hoTen;
	cout << "|" << setw(15) << m_cmnd;
	cout << "|" << setw(17) << m_sdt;
	cout << "|" << setw(20) << thoiGianDangKi() << "|" << endl;
	ds++;
};

string User::thoiGianDangKi() {
	string s0 = epKieuIntSangString(m_time[0]);
	string s1 = epKieuIntSangString(m_time[1]);
	string s2 = epKieuIntSangString(m_time[2]);
	string s3 = epKieuIntSangString(m_time[3]);
	string s4 = epKieuIntSangString(m_time[4]);
	string s5 = epKieuIntSangString(m_time[5]);

	string s = s0 + "/" + s1 + "/" + s2 + "  ";
	if (m_time[3] < 10) s += "0";
	s += s3 + ":";
	if (m_time[4] < 10) s += "0";
	s += s4 + ":";
	if (m_time[5] < 10) s += "0";
	s += s5;
	return s;
};

