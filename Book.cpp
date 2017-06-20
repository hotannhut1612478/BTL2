#include "Book.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

Book::Book(){
};

Book::~Book() {
};

// Phương thức tìm kiếm sách, k là mã số tìm kiếm (1 : tìm theo tên, 2 : tìm theo mã số sách, 3 : tìm theo tác giả)
// str là từ khóa tìm kiếm
// valid là giá trị tìm được, trả về false nếu không tìm thấy sách nào
void Book::find(int k, string str, bool &valid) {
	// Tạo mảng để lưu mã số các sách tìm được
	ifstream doc("BookInfo.dat", ios::app);
	// i lưu vị trí con trỏ trỏ đến trong file BookInfo
	// ds là biến chạy thứ tự sách
	int i = 0, ds = 0;
	while (!doc.eof()) {
		doc.seekg(sizeof(Book) * i);
		doc.read(reinterpret_cast <char *> (this), sizeof(Book));
		// Tìm kiếm theo tên
		if (k == 1) {
			if (soSanh(m_name, str) == true) {
				cout << ds + 1 << ". " << m_name << endl;
				ds++;
				luuTamThoi();
			};
		};
		// Tìm kiếm theo ISBN
		if (k == 2) {
			stringstream ss; ss << m_ISBN;
			string str2; ss >> str2;
			if (str2 == str) {
				cout << ds + 1 << ". " << m_name << endl;
				ds++;
				luuTamThoi();
			};
		};
		// Tìm kiếm theo tên tác giả
		if (k == 3) {
			if (soSanh(m_author, str) == true) {
				cout << ds + 1 << ". " << m_name << endl;
				ds++;
				luuTamThoi();
			};
		};
		i++;
	};
	if (ds == 0) valid = false;
	else valid = true;
};

void Book::inThongTin() {
	cout << "-------------------------------------------------------------------------------" << endl;
	cout << "ID " << m_id << endl;
	cout << " =========     Ten sach       : " << m_name << endl;
	cout << "||       ||    Ngay phat hanh : " << m_date[0] << "/" << m_date[1] << "/" << m_date[2] << endl;
	cout << "||       ||    Tac gia        : " << m_author << endl;
	cout << "||       ||    Gia tien thue  : " << m_rentCost << " (gia goc : " << m_cost << ")" << endl;
	cout << "||       ||    Nha xuat ban   : " << m_publisher << endl;
	cout << " =========                      " << endl;
	cout << " Mo ta : " << m_describe << endl;
	cout << "-------------------------------------------------------------------------------" << endl;
};

//điền thông tin
void Book::fill(){
	m_id = soLuong() + 1;
	string str;
	cout << "Nhap ten sach : ";
	getline(cin, str);
	strcpy_s(m_name, str.c_str());
	cout << "Nhap ma so tieu chuan quoc te (ISBN) : ";
	cin >> m_ISBN;
	cout << "Nhap ten tac gia : ";
	cin.ignore();
	getline(cin, str);
	strcpy_s(m_author, str.c_str());
	cout << "Ngay phat hanh : ";
	cin >> m_date[0] >> m_date[1] >> m_date[2];
	cout << "Nha xuat ban : ";
	cin.ignore();
	getline(cin, str);
	strcpy_s(m_publisher, str.c_str());
	cout << "Nhap so tien thue : ";
	cin >> m_rentCost;
	cout << "Nhap gia tien sach : ";
	cin >> m_cost;
	cout << "Mo ta : ";
	cin.ignore();
	getline(cin, str);
	strcpy_s(m_describe, str.c_str());
	cout << "So luong : ";
	cin >> m_number;
};

// bổ sung vào thư viện
void Book::add() {
	ofstream ghi1("Book.txt", ios::app);
	ofstream ghi2("BookInfo.dat", ios::app);
	ghi1 << m_name << "\n";
	ghi2.write(reinterpret_cast <const char *> (this), sizeof(Book));
}

void Book::autoAdd() {
	ofstream ghi2("BookInfo.dat", ios::app);
	string str;
	while (str != "") {
		m_id = soLuong() + 1;
		getline(cin, str);
		strcpy_s(m_name, str.c_str());
		cin >> m_ISBN;
		cin.ignore();
		getline(cin, str);
		strcpy_s(m_author, str.c_str());
		cin >> m_date[0] >> m_date[1] >> m_date[2];
		ghi2.write(reinterpret_cast <const char *> (this), sizeof(Book));
	};
}

// lấy mã id lưu trong file tạm cho sách được chọn trong danh sách tìm kiếm
void Book::layID(int k) {
	string str;
	int id;
	ifstream doc1("luutam.txt");
	for (int i = 1; i < k; i++) getline(doc1, str);
	doc1 >> id;
	ifstream doc2("BookInfo.dat", ios::app);
	doc2.seekg((id - 1) * sizeof(Book));
	doc2.read(reinterpret_cast <char *> (this), sizeof(Book));
}

////////////////////////////////////////////////////////////////////////////////////////
//Private:
bool Book::soSanh(string s1, string s) {
	int i, j, k, loi, saiSo;
	saiSo = round(s.length() * 0.4);
	if (s1.length() < (s.length() - saiSo) || s1.length() >(s.length() + saiSo)) return false;
	i = j = loi = 0;
	while (i < s.length() && j < s1.length()) {
		if (s[i] != s1[j]) {
			loi++;
			for (k = 1; k <= saiSo; k++) {
				if ((i + k < s.length()) && s[i + k] == s1[j]) {
					i += k;
					break;
				}
				else if ((j + k < s1.length()) && s[i] == s1[j + k]) {
					j += k;
					break;
				};
			};
		};
		i++;
		j++;
	};
	loi += s.length() - i + s1.length() - j;

	if (loi <= saiSo) return true;
	else return false;
};

int Book::soLuong() {
	ifstream docThongTin("BookInfo.dat");
	//Kiểm tra số lượng sách bằng cách đọc id ở cuối
	int i = 0;
	if (docThongTin) {
		while (!docThongTin.eof()) {
			docThongTin.seekg(sizeof(Book)*i);
			docThongTin.read(reinterpret_cast <char *> (this), sizeof(Book));
			i++;
		};
	};
	return m_id;
};

//lưu danh sách tìm kiếm
void Book::luuTamThoi() {
	ofstream ghi("luutam.txt", ios::app);
	ghi << m_id << "\n";
}