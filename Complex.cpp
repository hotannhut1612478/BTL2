#include "Complex.h"
#include <iostream>
#include <string>
#include <sstream>

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
		cout << z << " khong chua khoang trong hoac ki tu dang biet. Hay thu lai !";
	};
	return k;
};

// Kiểm tra độ dài chuỗi
bool leng(string x, string z) {
	bool k = true;
	//kiểm tra độ dài
	if (x.length() > 18 || x.length() < 6) {
		system("cls");
		cout << "Do dai " << z << " khong the vuot qua 18 ky tu hoac nho hon 6 ky tu !";
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