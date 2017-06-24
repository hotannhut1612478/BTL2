#include "ThoiGian.h"
#include <string>
#include <sstream>
#include "Complex.h"
#include <ctime>

using namespace std;
ThoiGian::ThoiGian(){
};
ThoiGian::ThoiGian(int a,int b,int c) {
	ngay = a;
	thang = b;
	nam = c;
};
ThoiGian::~ThoiGian(){
};

string ThoiGian::str() {
	string s0 = epKieuIntSangString(ngay);
	string s1 = epKieuIntSangString(thang);
	string s2 = epKieuIntSangString(nam);
	string s3 = epKieuIntSangString(gio);
	string s4 = epKieuIntSangString(phut);
	string s5 = epKieuIntSangString(giay);

	string s = s0 + "/" + s1 + "/" + s2 + "  ";
	if (gio < 10) s += "0";
	s += s3 + ":";
	if (phut < 10) s += "0";
	s += s4 + ":";
	if (giay < 10) s += "0";
	s += s5;
	return s;
};

void ThoiGian::setTimeNow() {
	time_t now = time(0);
	tm t;
	localtime_s(&t, &now);
	ngay = t.tm_mday;
	thang = t.tm_mon + 1;
	nam = t.tm_year + 1900;
	gio = t.tm_hour;
	phut = t.tm_min;
	giay = t.tm_sec;
};

void ThoiGian::setTime(string str) {
	stringstream ss(str);
	ss >> ngay;
	ss >> thang;
	ss >> nam;
};

long ThoiGian::tinhNgay() {
	int sum = 0;
	for (int i = 1; i <= thang; i++) {
		switch (i) {
		case 1:
			break;
		case 3:
			if (nam % 4 == 0 && nam % 100 != 0 || nam % 400 == 0) sum += 29;
			else sum += 28;
			break;
		case 2:
		case 4:
		case 6:
		case 8:
		case 9:
		case 11:
			sum += 31;
			break;
		case 5:
		case 7:
		case 10:
		case 12:
			sum += 30;
			break;
		};
	};
	sum += ngay;
	return sum;
};