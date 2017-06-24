#include "Complex.h"
#include "thoiGian.h"
#include <iostream>
#include <string>
#include <sstream>
#include <ctime>
#include <conio.h>
#include <fstream>
#include <Windows.h>

using namespace std;
/////////////////////////////////////////////////////////////////////////////
int soSanh(string s1, string s) {
	int i, j, k, loi, saiSo;
	saiSo = round(s.length() * 0.2);
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

// Kiểm tra chuỗi chỉ chứa số hay không
bool number(string x) {
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

bool kiTuDacBiet(string x, string z) {
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
	};
	return k;
};

// Kiểm tra độ dài chuỗi
bool leng(string x, string z) {
	bool k = true;
	//kiểm tra độ dài
	if (x.length() > 18 || x.length() < 6) {
		system("cls");
		k = false;
	};
	return k;
};

bool chu(string x) {
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

// Xóa khoảng trống thừa
string xoaKhoangTrong(string mangkt) {
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
};

string xoaKTTrongChuoi(string S, int k) {
	while (S[k] != '\0') {
		S[k] = S[k + 1];
		k++;
	};
	return S;
}

string epKieuIntSangString(int k) {
	string str;
	stringstream ss;
	ss << k;
	ss >> str;
	return str;
}

string thoiGianHeThong() {
	time_t now = time('\0');
	tm t;
	localtime_s(&t, &now);
	string s = "";
	if (t.tm_hour < 10) s += "0";
	s += epKieuIntSangString(t.tm_hour) + ":";
	if (t.tm_min < 10) s += "0";
	s += epKieuIntSangString(t.tm_min);
	return s;
}

//Nhập mật khẩu ẩn với kí tự *
string nhapKiTuAn() {
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

string maHoa(string matKhau) {
	for (int i = 0; i < matKhau.length(); i++) matKhau[i] += i;
	return matKhau;
};

long chenhLechNgay(ThoiGian x, ThoiGian y) {
	long sum = 0;
	ThoiGian up, down;
	if (y.nam > x.nam) {
		up = y;
		down = x;
	}
	else {
		up = x;
		down = y;
	};

	for (int i = down.nam; i < up.nam; i++) {
		if (i % 4 == 0 && i % 100 != 0 || i % 400 == 0) sum += 366;
		else sum += 365;
	};
	sum += up.tinhNgay() - down.tinhNgay();
	return sum;
};

void xoaFile(string str) {
	ofstream xoaFile(str, ios_base::out | ios_base::trunc);
	if (xoaFile);
};

int luaChon() {
	string s;
	getline(cin, s);
	stringstream ss(s);
	int k = -1;
	ss >> k;
	return k;
};

// ham do hoa thay doi mau chu va mau nen;
void doHoa(int x){
	HANDLE mau;
	mau = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau, x);
};