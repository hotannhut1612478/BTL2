#include <iostream>
#include <fstream>
#include <string>
#include "User.h"
#include "Menu.h"
using namespace std;

int main() {
	User admin;
	Menu menu;
	menu.menuIntro(admin);

	
	string const duLieuDangNhap("F:/document/COMPUTER SCIENCE/giai thuat va lap trinh/assignment/assignment2/code/Project1/du lieu/taptindulieu.txt");
	
	ofstream ghiDuLieu(duLieuDangNhap.c_str(), ios::app); // c_str ?
	

	if (ghiDuLieu) {
		ghiDuLieu << duLieuDangNhap.c_str() << endl;
	}
	else {
		cout << "Loi : Khong mo duoc tep." << endl;
	};

	system("pause");
}

void checkLogin1(string tdn, string const dl) {
	
	ifstream read(dl.c_str());

	if (read) {
		char a;
		read.get(a);
		cout << a << endl;
	}
	else {
		cout << "Loi : Khong mo duoc tep." << endl;
	};
}