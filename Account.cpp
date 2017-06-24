#include "Account.h"
#include "Complex.h"
#include <iostream>
#include <fstream>
#include <conio.h>

using namespace std;
Account::Account(){
};

Account::~Account(){
};

void Account::taoTaiKhoan() {
	string str1, str2;
	// Nhập vào tên đăng nhập và kiểm tra tính hợp lệ
	cout << "Nhap vao ten dang nhap : ";
	getline(cin, str1);
	if (leng(str1, "ten dang nhap") == false || kiTuDacBiet(str1, "Ten dang nhap") == false) {
		subscription();
		return;
	};
	if (checkLogin(str1, "") >= 1) {
		system("cls");
		cout << "Ten dang nhap nay da ton tai !";
		subscription();
		return;
	};
	//Nhập vào mật khẩu và kiểm tra tính hợp lệ
	cout << "Nhap mat khau : ";
	str2 = nhapMatKhau();
	if (leng(str2, "mat khau") == false || kiTuDacBiet(str2, "Mat khau") == false) {
		subscription();
		return;
	};
	//Xác nhận lại mật khẩu
	cout << "Xac nhan lai mat khau : ";
	string ts = nhapMatKhau();
	// nếu xác nhận mật khẩu không khớp thì reset
	if (ts != str2) {
		system("cls");
		cout << "Xac nhan mat khau khong chinh xac !";
		subscription();
		return;
	};

	strcpy_s(m_nameLogin, str1.c_str());
	strcpy_s(m_passWord, str2.c_str());
};

void Account::changePassWord() {
	char mk[18] = "";
	cout << "Nhap mat khau cu : ";
	string ts = nhapMatKhau();
	if (ts == m_passWord) {
		cout << "Nhap mat khau moi : ";
		ts = nhapMatKhau();
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
		string ts2 = nhapMatKhau();
		// Nếu xác nhận trùng khớp thì đổi mật khẩu thành công
		if (ts2 == ts) strcpy_s(m_passWord, ts.c_str());
		else {
			system("cls");
			cout << "Xac nhan mat khau khong chinh xac !" << endl;
			changePassWord();
			return;
		};
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
	cin.ignore();
	string str;
	getline(cin, str);
};

//Nhập mật khẩu ẩn với kí tự *
string Account::nhapMatKhau() {
	string pass;
	for (char ch; (ch = _getch()); ) {
		// Nếu kí tự ch là các kí tự in ra được và độ dài nhỏ hơn 18 thì nhận vào pass, xuất ra màn hình '*'
		if (isprint(ch) && pass.size() < 18) {
			cout << '*';
			pass += ch;
		};
		//Khi nhập phím mũi tên thì không thực hiện 
		if (ch == -32) _getch();
		//Nếu nhập enter thì kết thúc dòng nhập
		if (ch == '\r' || ch == '\n') {
			cout << endl;
			break;
		};
		//Nếu kí tự nhập là backspace 
		if (ch == '\b') {
			if (!pass.empty()) {
				//Xóa một kí tự trên màn hình
				cout << "\b \b";
				//Xóa một kí tự trong chuỗi pass
				pass.erase(pass.size() - 1);
			};
		};
	};
	return pass;
};

int Account::checkLogin(string ch1, string ch2) {
	fflush(stdin);
	// biến k lưu số lượng trùng khớp, khi tên đăng nhập và mật khẩu chính xác thì k == 2
	// Khi chỉ có tên đăng nhập thì k sẽ == 1 và k == 0 khi cả tên đăng nhập và mật khẩu không đúng
	int k = 0;
	ifstream doc("Account.dat", ios::app | ios::binary);
	if (doc) {
		// Khi thông tin các User được cập nhật thì dữ liệu sẽ lưu ở cuối file
		int i = 0;
		// Nếu chưa đọc hết file thì đọc tiếp tục lần lượt qua các Users
		while (!doc.eof()) {
			doc.seekg(sizeof(Account) * i);
			doc.read(reinterpret_cast <char *> (this), sizeof(Account));
			// So sánh thông tin tên đăng nhập và mật khẩu với ch1 và ch2
			if (strcmp(ch1.c_str(), m_nameLogin) == 0 && strcmp(ch2.c_str(), m_passWord) == 0) {
				if (m_active == true) k = 2;
				else k = -1;
			}
			else {
				if (strcmp(ch1.c_str(), m_nameLogin) == 0) {
					if (m_active == true) k = 1;
					else k = -1;
				};
			};
			i++;
		};
	}
	else cout << "Loi ! Khong mo duoc file chua thong tin Users." << endl;
	return k;
};

void Account::docGia() {
	m_ident = 0;
};
void Account::thuThu() {
	m_ident = 1;
};
void Account::admin() {
	m_ident = 2;
};

string Account::getNameLogin() {
	return m_nameLogin;
};
string Account::getPassword() {
	return m_passWord;
};
int Account::getIdent() {
	return m_ident;
};

