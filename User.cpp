#include "User.h"
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <conio.h>
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
	//Nhập vào Họ và tên
	cout << "Nhap ho va ten : ";
	string str1, str2, str3, str4, str5, str6, str7;
	getline(cin, str1);
	if (str1.length() > 40 || str1.length() == 0) {
		system("cls");
		cout << "Do dai Ho Ten khong hop le";
		subscription();
		return;
	};
	xoaKhoangTrong(str1);
	// nếu Họ và Tên chỉ chứa các kí tự thì next
	if (chu(str1) == false) {
		system("cls");
		cout << "Ho va ten chi co the chua ki tu !";
		subscription();
		return;
	};
	// Nhập vào tên đăng nhập và kiểm tra tính hợp lệ
	cout << "Nhap vao ten dang nhap : ";
	getline(cin, str2);
	if (leng(str2, "ten dang nhap") == false || kiTuDacBiet(str2, "Ten dang nhap") == false) {
		subscription();
		return;
	};
	if (soSanh(str2,"") >= 1) {
		system("cls");
		cout << "Ten dang nhap nay da ton tai !";
		subscription();
		return;
	};
	//Nhập vào mật khẩu và kiểm tra tính hợp lệ
	cout << "Nhap mat khau : ";
	str3 = nhapMatKhau();
	if (leng(str3, "mat khau") == false || kiTuDacBiet(str3, "Mat khau") == false) {
		subscription();
		return;
	};
	//Xác nhận lại mật khẩu
	cout << "Xac nhan lai mat khau : ";
	string ts = nhapMatKhau();
	// nếu xác nhận mật khẩu không khớp thì reset
	if (ts != str3) {
		system("cls");
		cout << "Xac nhan mat khau khong chinh xac !";
		subscription();
		return;
	};
	//Nhập nghề nghiệp :
	cout << "Nhap nghe nghiep : ";
	getline(cin, str4);
	if (str4.length() > 30) {
		system("cls");
		cout << "Do dai nghe nghiep khong the qua 30 ki tu";
		subscription();
		return;
	};
	// Nhập địa chỉ :
	cout << "Nhap dia chi : ";
	getline(cin, str5);
	if (str5.length() > 40) {
		system("cls");
		cout << "Do dai dia chi khong the qua 40 ki tu";
		subscription();
		return;
	};
	// Nhập mã số chứng minh nhân dân, cmnd chỉ có thể chứa chữ số
	cout << "Nhap ma so chung minh nhan dan : ";
	getline(cin, str6);
	// Nếu mã cmnd không hợp lệ thì reset
	if (number(str6) == false) {
		system("cls");
		cout << "So chung minh nhan dan khong ton tai !";
		subscription();
		return;
	};
	// Nhập vào số điện thoại, số điện thoại chỉ có thể chứa chữ số
	cout << "Nhap so dien thoai : ";
	getline(cin, str7);
	//nếu số điện thoại không hợp lệ thì reset
	if (number(str7) == false) {
		system("cls");
		cout << "So dien thoai khong ton tai !";
		subscription();
		return;
	};
	cout << "Dang ki thanh cong !" << endl;
	Sleep(1000);
	system("cls");
	cout << "============================= Xac nhan lai thong tin tai khoan =================================" << endl;
	strcpy_s(m_hoTen, str1.c_str());
	strcpy_s(m_nameLogin, str2.c_str());
	strcpy_s(m_passWord, str3.c_str());
	strcpy_s(m_job, str4.c_str());
	strcpy_s(m_address, str5.c_str());;
	strcpy_s(m_cmnd, str6.c_str());
	strcpy_s(m_sdt, str7.c_str());
	m_id = soLuong() + 1;
	inThongTin();
};

void User::ghi() {
	ofstream ghi("Users.dat", ios::app | ios ::binary);
	if (ghi) ghi.write(reinterpret_cast <const char *> (this), sizeof(User));
	else cout << "Loi : khong the mo file chua thong tin Users." << endl;
};

void User::doc() {
	ifstream doc("Users.dat", ios::app);
	if (doc) doc.read(reinterpret_cast <char *> (this), sizeof(User));
	else cout << "Loi : khong the mo file chua thong tin Users." << endl;
};

void User::inThongTin() {
	cout << "Ma so ID : " << m_id << endl;
	cout << "Ho va ten : " << m_hoTen << endl;
	cout << "Ten dang nhap : " << m_nameLogin << endl;
	cout << "Nghe nghiep hien tai : " << m_job << endl;
	cout << "Dia chi : " << m_address << endl;
	cout << "So dien thoai : " << m_sdt << endl;
	cout << "Chung minh nhan dan so : " << m_cmnd << endl;
}

void User::changePassWord() {
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

int User::soSanh(string ch1, string ch2) {
	fflush(stdin);
	// biến k lưu số lượng trùng khớp, khi tên đăng nhập và mật khẩu chính xác thì k == 2
	// Khi chỉ có tên đăng nhập thì k sẽ == 1 và k == 0 khi cả tên đăng nhập và mật khẩu không đúng
	int k = 0;
	ifstream doc("Users.dat", ios::app | ios::binary);
	if (doc) {
		// Khi thông tin các User được cập nhật thì dữ liệu sẽ lưu ở cuối file
		int i = 0;
		// Nếu chưa đọc hết file thì đọc tiếp tục lần lượt qua các Users
		while (!doc.eof()) {
			doc.seekg(sizeof(User) * i);
			doc.read(reinterpret_cast <char *> (this), sizeof(User));
			// So sánh thông tin tên đăng nhập và mật khẩu với ch1 và ch2
			if (strcmp(ch1.c_str(), m_nameLogin) == 0 && strcmp(ch2.c_str(), m_passWord) == 0) k = 2;
			else {
				if (strcmp(ch1.c_str(), m_nameLogin) == 0) k = 1;
			};
			i++;
		};
	}
	else cout << "Loi ! Khong mo duoc file chua thong tin Users." << endl;
	return k;
};

string User::getName() {
	return m_hoTen;
};

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Private:

string User::xoaKTTrongChuoi(string S, int k) {
	while (S[k] != '\0') {
		S[k] = S[k + 1];
		k++;
	};
	return S;
}
// Xóa khoảng trống thừa
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

bool User::chu(string x) {
	// nếu chuỗi kí tự x chỉ chứa các kí tự trong bảng chữ cái thì j sẽ bằng true
	bool j = true;
	for (int i = 0; i < x.length(); i++) {
		bool k = false;
		for (char kt = 'a'; kt != 'z' + 1; kt++) if (x[i] == kt) k = true;
		for (char kt = 'A'; kt != 'Z' + 1; kt++) if (x[i] == kt) k = true;
		if (x[i] == ' ') k = true;
		// chỉ cần một kí tự trong chuỗi x không phải chữ cái thì j sẽ bằng false
		if (k == false) j = false;
	};
	return j;
};
// Kiểm tra độ dài chuỗi
bool User::leng(string x, string z) {
	bool k = true;
	//kiểm tra độ dài
	if (x.length() > 18 || x.length() < 6) {
		system("cls");
		cout << "Do dai " << z << " khong the vuot qua 18 ky tu hoac nho hon 6 ky tu !";
		k = false;
	};
	return k;
};

bool User::kiTuDacBiet(string x, string z) {
	bool k = true;
	char S[40] = "";
	for (int i = 0; i < x.length(); i++) S[i] = x[i];
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
		if (j == false) k = false;
	};
	if (k == false) {
		system("cls");
		cout << z << " khong chua khoang trong hoac ki tu dang biet. Hay thu lai !";
	};
	return k;
};
// Kiểm tra chuỗi chỉ chứa số hay không
bool User::number(string x) {
	// nếu chuỗi kí tự x chỉ có số thì j sẽ bằng true 
	bool j = true;
	for (int i = 0; i < x.length(); i++) {
		bool k = false;
		for (char so = '0'; so <= '9'; so++) {
			if (x[i] == so) k = true;
		};
		// chỉ cần một kí tự trong chuỗi x không phải số thì j sẽ bằng false
		if (k == false) j = false;
	};
	return j;
};

int User::soLuong() {
	ifstream doc("Users.dat", ios::app);
	//Kiểm tra file User là rỗng hay không, nếu không có dữ liệu thì so luong = 0
	doc.seekg(sizeof(User), ios::end);
	doc.read(reinterpret_cast <char *> (this), sizeof(User));
	return m_id;
};

