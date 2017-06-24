#include "Book.h"
#include "Complex.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

Book::Book() {
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
	doHoa(12);
	cout << "-------------------------------------------------------------------------------" << endl;
	doHoa(14);
	cout << "ID " << m_id << endl;
	doHoa(10);
	cout << " =========    ";
	doHoa(12);
	cout << "Ten sach       : ";
	doHoa(15);
	cout << m_name << endl;
	doHoa(10);
	cout << "||       ||    ";
	doHoa(12);
	cout << " Ngay phat hanh : ";
	doHoa(15);
	cout << m_date[0] << "/" << m_date[1] << "/" << m_date[2] << endl;
	doHoa(10);
	cout << "||       ||    ";
	doHoa(12);
	cout << " Tac gia : ";
	doHoa(15);
	cout << m_author << endl;
	doHoa(10);
	cout << "||       ||    ";
	doHoa(12);
	cout << " Gia tien thue : ";
	doHoa(15);
	cout << m_rentCost << " (gia goc : " << m_cost << ")" << endl;
	doHoa(10);
	cout << "||       ||    ";
	doHoa(12);
	cout << " Nha xuat ban : ";
	doHoa(15);
	cout << m_publisher << endl;
	doHoa(10);
	cout << " =========     ";
	doHoa(12);
	cout << "Hien con ";
	doHoa(15);
	cout << m_number << " quyen                   " << endl;
	doHoa(12);
	cout << " Mo ta : ";
	doHoa(15);
	cout << m_describe << endl;
	doHoa(12);
	cout << "-------------------------------------------------------------------------------" << endl;
};

//điền thông tin
void Book::fill() {
	m_id = soLuong() + 1;
	string str;
	doHoa(12);
	cout << "Nhap ten sach : ";
	doHoa(15);
	getline(cin, str);
	strcpy_s(m_name, str.c_str());
	doHoa(12);
	cout << "Nhap ma so tieu chuan quoc te (ISBN) : ";
	doHoa(15);
	m_ISBN = luaChon();
	doHoa(12);
	cout << "Nhap ten tac gia : ";
	doHoa(15);
	getline(cin, str);
	strcpy_s(m_author, str.c_str());
	doHoa(12);
	cout << "Ngay phat hanh : ";
	doHoa(15);
	getline(cin, str);
	stringstream ss(str);
	ss >> m_date[0] >> m_date[1] >> m_date[2];
	doHoa(12);
	cout << "Nha xuat ban : ";
	doHoa(15);
	getline(cin, str);
	strcpy_s(m_publisher, str.c_str());
	doHoa(12);
	cout << "Nhap so tien thue : ";
	doHoa(15);
	m_rentCost = luaChon();
	doHoa(12);
	cout << "Nhap gia tien sach : ";
	doHoa(15);
	m_cost = luaChon();
	doHoa(12);
	cout << "Mo ta : ";
	doHoa(15);
	getline(cin, str);
	strcpy_s(m_describe, str.c_str());
	doHoa(12);
	cout << "So luong : ";
	doHoa(15);
	m_number = luaChon();
};

// bổ sung vào thư viện
void Book::add() {
	ofstream ghi1("Book.txt", ios::app);
	ofstream ghi2("BookInfo.dat", ios::app);
	ghi1 << m_id << " " << m_name << "\n";
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
	// lấy dữ liệu ID thứ k trong file lưu danh sách tìm kiếm tạm thời
	ifstream doc1("luutam.txt");
	for (int i = 1; i < k; i++) getline(doc1, str);
	doc1 >> id;
	// đọc đến vị trí id đó
	ifstream doc2("BookInfo.dat", ios::app);
	doc2.seekg((id - 1) * sizeof(Book));
	doc2.read(reinterpret_cast <char *> (this), sizeof(Book));
};

// In danh sách các sách hiện đang có
void Book::all() {
	ifstream docThongTin("BookInfo.dat");
	int i = 0;
	Book x, *y = &x;
	if (docThongTin) {
		while (!docThongTin.eof()) {
			docThongTin.seekg(sizeof(Book)*i);
			docThongTin.read(reinterpret_cast <char *> (y), sizeof(Book));
			i++;
			int ds = 0;
			x.thongTinTimKiem(ds);
		};
	};
};

void Book::muon(int k) {
	ifstream docThongTin("BookInfo.dat");
	int i = soLuong();
	Book x, *y = &x;
	while (i > 0) {
		docThongTin.seekg(sizeof(Book)*i);
		docThongTin.read(reinterpret_cast <char *> (y), sizeof(Book));
		i--;
		if (m_id = k) {
			m_number--;
			add();
			break;
		};
	};
}

int Book::getID() {
	return m_id;
};
string Book::getTenSach() {
	return m_name;
};
string Book::getTacGia() {
	return m_author;
};
int Book::getSL() {
	return m_number;
};

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
	ifstream doc("BookInfo.dat", ios::app);
	//Kiểm tra file User là rỗng hay không, nếu không có dữ liệu thì so luong = 0
	int i = 0;
	Book x, *y = &x;
	int sl = 0;
	if (doc) {
		while (!doc.eof()) {
			doc.seekg(sizeof(Book)*i);
			doc.read(reinterpret_cast <char *> (y), sizeof(Book));
			if (x.getID() > sl) sl = x.getID();
			i++;
		};
	};
	return sl;
};

//lưu danh sách tìm kiếm
void Book::luuTamThoi() {
	ofstream ghi("luutam.txt", ios::app);
	ghi << m_id << "\n";
}

// In thông tin theo định dạng table
void Book::thongTinTimKiem(int &ds) {
	cout << "|" << setw(5) << left << ds + 1;
	cout << "|" << setw(8) << m_id;
	cout << "|" << setw(25) << m_name;
	cout << "|" << setw(15) << m_author;
	cout << "|" << setw(17) << m_rentCost;
	cout << "|" << setw(20) << m_number << "|" << endl;
	ds++;
};