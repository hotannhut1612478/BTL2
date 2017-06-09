#include "User.h"
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <conio.h>

using namespace std;
User::User() {
	m_id++;
	
};
User::~User(){
};

	// mẫu đăng kí
void User::subscription() {
	cout << "Nhap ho va ten : ";
	string str;
	cin.ignore();
	getline(cin, str);
	xoaKhoangTrong(str);
	for (int i = 0; i < str.length(); i++) m_hoTen[i] = str[i];
	// nếu Họ và tên chứa các kí tự đặc biệt hoặc số thì reset
	/*if (chu(m_hoTen) == false) {
		system("cls");
		cout << "Ho va ten khong the chua ki tu dac biet !" << endl;
		cin.clear();
		cin.ignore(100,'\n');
		subscription();
	};*/

	cout << "Nhap vao ten dang nhap : ";
	cin >> m_nameLogin;
	//sao chép nội dung sau khi kiểm tra độ dài từ hàm leng sang nameLogin
	if (leng(m_nameLogin, "ten dang nhap") == false) subscription();
	if (kiTuDacBiet(m_passWord, "Mat khau") == false) subscription();

	cin.ignore(100, '\n');
	cout << "Nhap mat khau : ";
	string ts = nhapMatKhau();
	for (int i = 0; i < ts.length(); i++) m_passWord[i] = ts[i];
	if (leng(m_passWord, "mat khau") == false) subscription();
	if (kiTuDacBiet(m_passWord, "Mat khau") == false) subscription();

	cout << "Xac nhan lai mat khau : ";
	char xnmk[18];
	cin >> xnmk;
	// nếu xác nhận mật khẩu không khớp thì reset
	if (strcmp(m_passWord, xnmk) != 0) {
		system("cls");
		cout << "Xac nhan mat khau khong chinh xac !" << endl;
		cin.clear();
		cin.ignore(100, '\n');
		subscription();
	};

	cout << "Nhap ma so chung minh nhan dan : ";
	cin >> m_cmnd;
	//nếu mã cmnd không hợp lệ thì reset
	if (number(m_cmnd) == false) {
		system("cls");
		cout << "So chung minh nhan dan khong ton tai !" << endl;
		cin.clear();
		cin.ignore(100, '\n');
		subscription();
	};

	cout << "Nhap so dien thoai : ";
	cin >> m_sdt;
	//nếu số điện thoại không hợp lệ thì reset
	if (number(m_sdt) == false) {
		system("cls");
		cout << "So dien thoai khong ton tai !" << endl;
		cin.clear();
		cin.ignore(100, '\n');
		subscription();
	};
	
};

string User::xoaKTTrongChuoi(string S, int k) {
	while (S[k] != '\0') {
		S[k] = S[k + 1];
		k++;
	};
	return S;
}

string User::xoaKhoangTrong(string mangkt) {
	int dem = 0;
	size_t dodai = 0;
	while (mangkt[dodai] != '\0') {
		if (mangkt[dodai] == ' ') {
			dem++;
			if (dem > 1) {
				mangkt = xoaKTTrongChuoi(mangkt, dodai);
				dodai--;
			};
		}
		else dem = 0;
		dodai++;
	};
	if (mangkt[dodai - 1] == ' ') {
		mangkt = xoaKTTrongChuoi(mangkt, dodai - 1);
		dodai--;
	};
	if (mangkt[0] == ' ') {
		mangkt = xoaKTTrongChuoi(mangkt, 0);
		dodai--;
	};
	char A[99] = "";
	for (int i = 0; i < dodai; i++) A[i] = mangkt[i];
	return A;
}

bool User::number(char x[]) {
	// nếu chuỗi kí tự x chỉ có số thì j sẽ bằng true 
	bool j = true;
	for (int i = 0; i < strlen(x); i++) {
		bool k = false;
		for (char so = '0'; so <= '9'; so++) {
			if (x[i] == so) k = true;
		};
		// chỉ cần một kí tự trong chuỗi x không phải số thì j sẽ bằng false
		if (k == false) j = false;
	};
	return j;
};

bool User::chu(char x[]) {
	// nếu chuỗi kí tự x chỉ chứa các kí tự trong bảng chữ cái thì j sẽ bằng true
	bool j = true;
	for (int i = 0; i < strlen(x); i++) {
		bool k = false;
		for (char kt = 'a'; kt != 'z' + 1; kt++) if (x[i] == kt) k = true;
		for (char kt = 'A'; kt != 'Z' + 1; kt++) if (x[i] == kt) k = true;
		if (x[i] == ' ') k = true;
		// chỉ cần một kí tự trong chuỗi x không phải chữ cái thì j sẽ bằng false
		if (k == false) j = false;
	};
	return j;
};

bool User::leng(char x[], string z) {
	bool k = true;
	//kiểm tra độ dài
	if (strlen(x) > 18 || strlen(x) < 6) {
		system("cls");
		cout << "Do dai " << z << " khong the vuot qua 18 ky tu hoac nho hon 6 ky tu !" << endl;
		cin.clear();
		cin.ignore(100, '\n');
		k = false;
	};
	return k;
};

bool User::kiTuDacBiet(char x[], string z) {
	bool k = true;
	char S[40] = "";
	strcpy_s(S, x);
	// hàm _strlwr_s dùng để chuyển chuỗi ký tự thành chữ thường
	_strlwr_s(S);
	for (int i = 0; i < strlen(S); i++) {
		//kiểm tra ký tự đặc biệt
		bool j = false;
		// nếu S[i] bằng một trong những kí tự cho phép thì biến boolen j sẽ = true, nghĩa là kí tự S[i] đã hợp lệ
		for (char kt = 'a'; kt != 'z' + 1; kt++) if (S[i] == kt) j = true;
		for (char so = '0'; so <= '9'; so++) if (x[i] == so) j = true;
		if (S[i] == '_') j = true;
		// nếu không hợp lệ sẽ reset lại từ đầu
		if (j == false) {
			system("cls");
			cout << z << " khong chua khoang trong hoac ki tu dang biet. Hay thu lai !" << endl;
			cin.clear();
			cin.ignore(100, '\n');
			k = false;
		};
	};
	return k;
};

void User::ghi() {
	ofstream ghi("Users.dat", ios::app);
	if (ghi) {
		ghi.write(reinterpret_cast <const char *> (this), sizeof(User));
	}
	else cout << "Loi : khong the mo file chua thong tin Users." << endl;
};

void User::doc() {
	ifstream doc("Users.dat", ios::app);
	if (doc) doc.read(reinterpret_cast <char *> (this), sizeof(User));
	else cout << "Loi : khong the mo file chua thong tin Users." << endl;
};

bool User::checkPass(char ch1[], char ch2[]) {
	bool x = false;
	ifstream doc("Users.dat", ios::app);
	if (doc) {
		int i = 1;
		while (!doc.eof()) {
			doc.seekg(sizeof(User) * i);
			doc.read(reinterpret_cast <char *> (this), sizeof(User));
			if (strcmp(ch1, m_nameLogin) == 0 && strcmp(ch2, m_passWord) == 0) {
				x = true;
				break;
			};
			i++;
		};
	}
	else cout << "Loi ! Khong mo duoc file chua thong tin Users." << endl;
	return x;
}

void User::inThongTin() {
	cout << "Ma so ID : " << m_id << endl;
	cout << "Ho va ten : " << m_hoTen << endl;
	cout << "Mat khau : " << m_passWord << endl;
	cout << "Ten dang nhap : " << m_nameLogin << endl;
	cout << "So dien thoai : " << m_sdt << endl;
	cout << "Chung minh nhan dan so : " << m_cmnd << endl;
}

void User::changePassWord() {
	cout << "Nhap mat khau cu : ";
	char mk[18] = "";
	string ts = nhapMatKhau();
	for (int i = 0; i < ts.length(); i++) mk[i] = ts[i];
	if (strcmp(mk, m_passWord) == 0) {
		cout << "Nhap mat khau moi : ";
		cin >> m_passWord;
		if (leng(m_passWord, "mat khau") == false) {
			changePassWord();
		};
		if (kiTuDacBiet(m_passWord, "Mat khau") == false) {
			changePassWord();
		};
		ofstream ghi("Users.dat", ios::app);
		ghi.seekp(sizeof(User) * m_id);
		if (ghi) ghi.write(reinterpret_cast <const char *> (this), sizeof(User));
		else cout << "Loi : khong the mo file chua thong tin Users." << endl;
	}
	else {
		system("cls");
		cout << "Mat khau khong chinh xac !" << endl;
		changePassWord();
	};
	cout << "Thay doi mat khau thanh cong !" << endl;
	cout << "Nhan ENTER de quay lai " << endl;
	string str;
	getline(cin, str);
}

//Nhập mật khẩu ẩn với kí tự *
string User::nhapMatKhau() {
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