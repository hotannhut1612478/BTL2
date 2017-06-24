#include "User.h"
#include "Complex.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <fstream>
#include <conio.h>
#include <Windows.h>

using namespace std;
User::User() {
};
User::~User() {
};

// mẫu đăng kí
void User::subscription() {
	User x;
	int k = 0;
	//Nhập vào Họ và tên
	cout << "Nhap ho va ten : ";
	string str1, str2, str3, str4, str5, str6, str7;
	getline(cin, str1);
	if (str1.length() > 40 || str1.length() == 0) {
		system("cls");
		cout << "Do dai Ho Ten khong hop le" << endl;
		subscription();
		return;
	};
	xoaKhoangTrong(str1);
	// nếu Họ và Tên chỉ chứa các kí tự thì next
	if (chu(str1) == false) {
		system("cls");
		cout << "Ho va ten chi co the chua ki tu !" << endl;
		subscription();
		return;
	};
	// Nhập vào tên đăng nhập và kiểm tra tính hợp lệ
	cout << "Nhap vao ten dang nhap : ";
	getline(cin, str2);
	if (leng(str2, "ten dang nhap") == false){
		cout << "Do dai ten dang nhap khong the vuot qua 18 ky tu hoac nho hon 6 ky tu !" << endl;
		subscription();
		return;
	};
	if (kiTuDacBiet(str2, "Ten dang nhap") == false) {
		cout << "Ten dang nhap khong chua khoang trong hoac ki tu dang biet. Hay thu lai !" << endl;
		subscription();
		return;
	};

	if (checkLogin(str2, "", x, k) >= 1) {
		system("cls");
		cout << "Ten dang nhap nay da ton tai !" << endl;
		subscription();
		return;
	};
	//Nhập vào mật khẩu và kiểm tra tính hợp lệ
	cout << "Nhap mat khau : ";
	str3 = nhapKiTuAn();
	if (leng(str3, "mat khau") == false || kiTuDacBiet(str3, "Mat khau") == false) {
		subscription();
		return;
	};
	//Xác nhận lại mật khẩu
	cout << "Xac nhan lai mat khau : ";
	string ts = nhapKiTuAn();
	// nếu xác nhận mật khẩu không khớp thì reset
	if (ts != str3) {
		system("cls");
		cout << "Xac nhan mat khau khong chinh xac !" << endl;
		subscription();
		return;
	};
	//Nhập nghề nghiệp :
	cout << "Nhap nghe nghiep : ";
	getline(cin, str4);
	if (str4.length() > 30) {
		system("cls");
		cout << "Do dai nghe nghiep khong the qua 30 ki tu" << endl;
		subscription();
		return;
	};
	// Nhập địa chỉ :
	cout << "Nhap dia chi : ";
	getline(cin, str5);
	if (str5.length() > 40) {
		system("cls");
		cout << "Do dai dia chi khong the qua 40 ki tu" << endl;
		subscription();
		return;
	};
	// Nhập mã số chứng minh nhân dân, cmnd chỉ có thể chứa chữ số
	cout << "Nhap ma so chung minh nhan dan : ";
	getline(cin, str6);
	// Nếu mã cmnd không hợp lệ thì reset
	if (number(str6) == false) {
		system("cls");
		cout << "So chung minh nhan dan khong ton tai !" << endl;
		subscription();
		return;
	};
	// Nhập vào số điện thoại, số điện thoại chỉ có thể chứa chữ số
	cout << "Nhap so dien thoai : ";
	getline(cin, str7);
	//nếu số điện thoại không hợp lệ thì reset
	if (number(str7) == false) {
		system("cls");
		cout << "So dien thoai khong ton tai !" << endl;
		subscription();
		return;
	};
	cout << "Dang ki thanh cong !" << endl;
	Sleep(1000);
	system("cls");
	strcpy_s(m_hoTen, str1.c_str());
	strcpy_s(m_nameLogin0, str2.c_str());
	// Mã hóa mật khẩu trước khi lưu
	str3 = maHoa(str3);
	strcpy_s(m_passWord0, str3.c_str());
	strcpy_s(m_job, str4.c_str());
	strcpy_s(m_address, str5.c_str());;
	strcpy_s(m_cmnd, str6.c_str());
	strcpy_s(m_sdt, str7.c_str());
	m_ident0 = 0;
	m_id = tinhSoLuong() + 1;
	m_time.setTimeNow();
};

void User::ghi() {
	ofstream ghi("Users.dat", ios::app | ios::binary);
	if (ghi) ghi.write(reinterpret_cast <const char *> (this), sizeof(User));
	else cout << "Loi : khong the mo file chua thong tin Users." << endl;
};

void User::doc() {
	ifstream doc("Users.dat", ios::app);
	if (doc) doc.read(reinterpret_cast <char *> (this), sizeof(User));
	else cout << "Loi : khong the mo file chua thong tin Users." << endl;
};

void User::inUser() {
	cout << "Ma so ID : " << m_id << endl;
	cout << "Ho va ten : " << m_hoTen << endl;
	cout << "Ten dang nhap : " << m_nameLogin0 << endl;
	cout << "Nghe nghiep hien tai : " << m_job << endl;
	cout << "Dia chi : " << m_address << endl;
	cout << "So dien thoai : " << m_sdt << endl;
	cout << "Chung minh nhan dan so : " << m_cmnd << endl;
	cout << "Ngay dang ki : " << m_time.str() << endl;
};

void User::inAccount() {
	string str1 = "", str2 = "", str3 = "";
	if (m_ident0 == 1) str1 = "THU THU";
	if (m_ident0 == 2) str1 = "ADMIN";
	if (m_ident1 == 1) str2 = "THU THU";
	if (m_ident1 == 2) str2 = "ADMIN";
	if (m_ident2 == 1) str3 = "THU THU";
	if (m_ident2 == 2) str3 = "ADMIN";

	cout << left << setw(20) << "    ___     " << setw(20) << "     ___     " << setw(20) << "     ___    " << endl;
	cout << left << setw(20) << "   /   \\   " << setw(20) << "    /   \\   " << setw(20) << "    /   \\  " << endl;
	cout << left << setw(20) << "   |   |    " << setw(20) << "    |   |    " << setw(20) << "    |   |   " << endl;
	cout << left << setw(20) << "    \\-/    " << setw(20) << "     \\-/    " << setw(20) << "     \\-/   " << endl;
	cout << left << setw(20) << " ---------  " << setw(20) << "  ---------  " << setw(20) << "  --------- " << endl;
	cout << left << setw(20) << "    / \\    " << setw(20) << "     / \\    " << setw(20) << "     / \\   " << endl;
	cout << left << setw(20) << "   /   \\   " << setw(20) << "    /   \\   " << setw(20) << "    /   \\  " << endl;

	cout << setw(24) << left << m_nameLogin0 << setw(21) << m_nameLogin1 << setw(18) << m_nameLogin2 << endl;
	cout << setw(25) << left << str1 << setw(20) << str2 << setw(20) << str3 << endl;
};

void User::changePassWord() {
	char mk[18] = "";
	cout << "Nhap mat khau cu : ";
	string ts = nhapKiTuAn();
	ts = maHoa(ts);
	if (ts == m_passWord0) {
		cout << "Nhap mat khau moi : ";
		ts = nhapKiTuAn();
		// Kiểm tra tính hợp lệ của mật khẩu mới
		if (leng(ts, "mat khau") == false) {
			cout << endl;
			changePassWord();
			return;
		};
		if (kiTuDacBiet(ts, "Mat khau") == false) {
			cout << endl;
			changePassWord();
			return;
		};
		cout << "Xac nhan mat khau moi : ";
		string ts2 = nhapKiTuAn();
		// Nếu xác nhận trùng khớp thì đổi mật khẩu thành công
		if (ts2 == ts) {
			ts = maHoa(ts);
			strcpy_s(m_passWord0, ts.c_str());
		}
		else {
			system("cls");
			cout << "Xac nhan mat khau khong chinh xac !" << endl;
			changePassWord();
			return;
		};
		xoaUser(m_id);
		ghi();
	}
	else {
		system("cls");
		cout << "Mat khau khong chinh xac !" << endl;
		changePassWord();
		return;
	};
	cout << "Thay doi mat khau thanh cong !" << endl;
	cout << "Nhan ENTER de quay lai ";
	string str;
	getline(cin, str);
};

void User::taoTaiKhoan() {
	string str1, str2;
	User x;
	int k = 0;
	// Nhập vào tên đăng nhập và kiểm tra tính hợp lệ
	cout << "Nhap vao ten dang nhap : ";
	getline(cin, str1);
	if (leng(str1, "ten dang nhap") == false || kiTuDacBiet(str1, "Ten dang nhap") == false) {
		taoTaiKhoan();
		return;
	};
	if (checkLogin(str1, "", x, k) >= 1) {
		system("cls");
		cout << "Ten dang nhap nay da ton tai !" << endl;
		taoTaiKhoan();
		return;
	};
	//Nhập vào mật khẩu và kiểm tra tính hợp lệ
	cout << "Nhap mat khau : ";
	str2 = nhapKiTuAn();
	if (leng(str2, "mat khau") == false || kiTuDacBiet(str2, "Mat khau") == false) {
		taoTaiKhoan();
		return;
	};
	//Xác nhận lại mật khẩu
	cout << "Xac nhan lai mat khau : ";
	string ts = nhapKiTuAn();
	// nếu xác nhận mật khẩu không khớp thì reset
	if (ts != str2) {
		system("cls");
		cout << "Xac nhan mat khau khong chinh xac !" << endl;
		taoTaiKhoan();
		return;
	};
	int choice;
	int ident;
	if (m_roleThuThu == true) {
		if (m_roleAdmin == true) {
			cout << "Chon chuc nang cho tai khoan : " << endl;
			cout << "1. Doc gia" << endl;
			cout << "2. Thu thu" << endl;
			cout << "3. Admin" << endl;
			choice = luaChon();
			switch (choice) {
			case 1:
				ident = 0;
				break;
			case 2:
				ident = 1;
				break;
			case 3:
				ident = 2;
				break;
			default:
				cout << "\tLua chon cua ban khong hop le ! vui long kiem tra va nhap lai ! " << endl;
				cout << "\t................................................................" << endl;
				taoTaiKhoan();
				break;
			};
		}
		else {
			cout << "Chon chuc nang cho tai khoan : " << endl;
			cout << "1. Doc gia" << endl;
			cout << "2. Thu thu" << endl;
			cin >> choice;
			switch (choice) {
			case 1:
				ident = 0;
				break;
			case 2:
				ident = 1;
				break;
			default:
				cout << "\tLua chon cua ban khong hop le ! vui long kiem tra va nhap lai ! " << endl;
				cout << "\t................................................................" << endl;
				taoTaiKhoan();
				break;
			};
		};
	}
	else {
		if (m_roleAdmin == true) {
			cout << "Chon chuc nang cho tai khoan : " << endl;
			cout << "1. Doc gia" << endl;
			cout << "2. Admin" << endl;
			cin >> choice;
			switch (choice) {
			case 1:
				ident = 0;
				break;
			case 2:
				ident = 2;
				break;
			default:
				cout << "\tLua chon cua ban khong hop le ! vui long kiem tra va nhap lai ! " << endl;
				cout << "\t................................................................" << endl;
				taoTaiKhoan();
				break;
			};
		}
		else ident = 0;
	};

	if (strlen(m_nameLogin1) == 1) {
		strcpy_s(m_nameLogin1, str1.c_str());
		// Mã hóa mật khẩu trước khi lưu
		str2 = maHoa(str2);
		strcpy_s(m_passWord1, str2.c_str());
		m_ident1 = ident;
	}
	else {
		if (strlen(m_nameLogin2) == 1) {
			strcpy_s(m_nameLogin2, str1.c_str());
			// Mã hóa mật khẩu trước khi lưu
			str2 = maHoa(str2);
			strcpy_s(m_passWord2, str2.c_str());
			m_ident2 = ident;
		}
		else {
			cout << "Chi co the tao toi da 3 tai khoan !" << endl;
			return;
		};
	};
	system("pause");
};

int User::checkLogin(string ch1, string ch2, User &z, int &ident) {
	fflush(stdin);
	ch2 = maHoa(ch2);
	// biến k lưu số lượng trùng khớp, khi tên đăng nhập và mật khẩu chính xác thì k == 2
	// Khi chỉ có tên đăng nhập thì k sẽ == 1 và k == 0 khi cả tên đăng nhập và mật khẩu không đúng
	int k = 0, idcur = 0;
	ifstream doc("Users.dat", ios::app | ios::binary);
	if (doc) {
		// Khi thông tin các User được cập nhật thì dữ liệu sẽ lưu ở cuối file
		int i = 0;
		User x, *y = &x;
		// Nếu chưa đọc hết file thì đọc tiếp tục lần lượt qua các Users
		while (!doc.eof()) {
			doc.seekg(sizeof(User) * i);
			doc.read(reinterpret_cast <char *> (y), sizeof(User));
			// So sánh thông tin tên đăng nhập và mật khẩu với ch1 và ch2
			int q = 0;
			if (x.soTrungKhop(ch1, ch2, q) != 0) {
				k = x.soTrungKhop(ch1, ch2, q);
				ident = q;
				z = x;
			};
			i++;
		};
	}
	else cout << "Loi ! Khong mo duoc file chua thong tin Users." << endl;
	return k;
};

// Phương thức tìm kiếm User, k là mã số tìm kiếm (1 : tìm theo tên, 2 : tìm theo mã số ID, 3 : tìm theo CMND)
// str là từ khóa tìm kiếm
// valid là giá trị tìm được, trả về false nếu không tìm thấy sách nào
void User::find(int k, string str, bool &valid) {
	// lưu mã số các User tìm được
	ifstream doc("Users.dat", ios::app);
	// i lưu vị trí con trỏ trỏ đến trong file User
	// ds là biến chạy thứ tự sách
	int i = 0, ds = 0;
	User x, *y = &x;
	while (!doc.eof()) {
		doc.seekg(sizeof(User) * i);
		doc.read(reinterpret_cast <char *> (y), sizeof(User));
		// Tìm kiếm theo tên
		if (k == 1) {
			if (x.getHoTen() == str) {
				//In thông tin tìm kiếm
				x.thongTinTimKiem(ds);
				x.luuTamThoi();
			};
		};
		// Tìm kiếm theo ISBN
		if (k == 2) {
			stringstream ss; ss << x.getID();
			string str2; ss >> str2;
			if (str2 == str) {
				thongTinTimKiem(ds);
				luuTamThoi();
			};
		};
		// Tìm kiếm theo số cmnd
		if (k == 3) {
			if (x.getCMND() == str) {
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

void User::setJob(string str) {
	strcpy_s(m_job, str.c_str());
};
void User::setAddress(string str) {
	strcpy_s(m_address, str.c_str());
};
void User::setSDT(string str) {
	strcpy_s(m_sdt, str.c_str());
}

void User::setThuThu() {
	m_roleThuThu = true;
};
void User::setAdmin() {
	m_roleAdmin = true;
};
void User::khoaUser() {
	m_active = false;
};

// xóa User có ID k
void User::xoaUser(int k) {
	ofstream xoa1("bin.dat", ios::trunc);
	if (xoa1);
	int i = 0;
	ifstream doc1("Users.dat", ios::app | ios::binary);
	ifstream doc2("bin.dat", ios::app | ios::binary);

	if (doc1) {
		while (!doc1.eof()) {
			User x, *y = &x;
			doc1.seekg(sizeof(User)*i);
			doc1.read(reinterpret_cast <char *> (y), sizeof(User));
			i++;
			if (x.getID() == k) continue;
			ofstream ghi1("bin.dat", ios::app | ios::binary);
			ghi1.write(reinterpret_cast <const char *> (y), sizeof(User));
		};
	};
	ofstream xoa2("Users.dat", ios::trunc);
	if (xoa2);
	i = 0;
	if (doc2) {
		while (!doc2.eof()) {
			User x, *y = &x;
			doc2.seekg(sizeof(User)*i);
			doc2.read(reinterpret_cast <char *> (y), sizeof(User));
			i++;
			ofstream ghi2("Users.dat", ios::app | ios::binary);
			ghi2.write(reinterpret_cast <const char *> (y), sizeof(User));
		};
	};
};

void User::all() {
	ifstream doc1("Users.dat", ios::app);
	int i, j = 0;
	if (doc1) {
		int max = 1;
		User x, *y = &x;
		do {
			i = 0;
			ifstream doc2("Users.dat", ios::app);
			while (!doc2.eof()) {
				User x, *y = &x;
				doc2.seekg(sizeof(User)*i);
				doc2.read(reinterpret_cast <char *> (y), sizeof(User));
				i++;
				if (x.getID() == max) {
					x.thongTinTimKiem(j);
				};
				//cout << x.getID() << " " << max << endl;
			};
			max++;
		} while (max <= x.tinhSoLuong());
	};
};

int User::getID() {
	return m_id;
};
string User::getHoTen() {
	return m_hoTen;
};
string User::getCMND() {
	return m_cmnd;
};
bool User::isThuThu() {
	return m_roleThuThu;
};
bool User::isAdmin() {
	return m_roleAdmin;
};
int User::getIdent(int k) {
	switch (k){
	case 1:
		return m_ident0;
		break;
	case 2:
		return m_ident1;
		break;
	case 3:
		return m_ident2;
		break;
	};
};
int User::tinhSoLuong() {
	ifstream doc("Users.dat", ios::app);
	//Kiểm tra file User là rỗng hay không, nếu không có dữ liệu thì so luong = 0
	int i = 0;
	int sl = 0;
	if (doc) {
		while (!doc.eof()) {
			User x, *y = &x;
			doc.seekg(sizeof(User)*i);
			doc.read(reinterpret_cast <char *> (y), sizeof(User));
			if (x.getID() > sl) sl = x.getID();
			i++;
		};
	};
	return sl;
};

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Private:

//Kiểm tra trùng khớp với tên đăng nhập và mật khẩu
int User::soTrungKhop(string ch1, string ch2, int &ident) {
	int k = 0;
	if (strcmp(ch1.c_str(), m_nameLogin0) == 0 && strcmp(ch2.c_str(), m_passWord0) == 0) {
		k = 2;
		ident = m_ident0;
	}
	else {
		if (strcmp(ch1.c_str(), m_nameLogin0) == 0) k = 1;
	};

	if (strcmp(ch1.c_str(), m_nameLogin1) == 0 && strcmp(ch2.c_str(), m_passWord1) == 0) {
		k = 2;
		ident = m_ident1;
	}
	else {
		if (strcmp(ch1.c_str(), m_nameLogin1) == 0) k = 1;
	};

	if (strcmp(ch1.c_str(), m_nameLogin2) == 0 && strcmp(ch2.c_str(), m_passWord2) == 0) {
		k = 2;
		ident = m_ident2;
	}
	else {
		if (strcmp(ch1.c_str(), m_nameLogin2) == 0) k = 1;
	};
	return k;
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
	cout << "|" << setw(20) << m_time.str() << "|" << endl;
	ds++;
};