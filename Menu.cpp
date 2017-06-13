#include "menu.h"
#include "User.h"
#include <iostream>
#include <Windows.h>
#include <fstream>
using namespace std;
Menu::Menu(){
};
Menu::~Menu(){
};

void Menu::menuIntro(User x) {
	system("cls");
	cout << "*      *       *      ********      *             *******      ******        *        *          ********  " << endl;
	cout << " *    * *      *     *             *             *            *      *      *  *     * *        *	        " << endl;
	cout << "   *   *   *   *     ********      *             *            *       *     *   *   *  *        *******    " << endl;
	cout << "      * *     * *       *            *             *           *      *      *     *     *       *         " << endl;
	cout << "         *       *        ********    ********      *******      *******        *          *       ********" << endl;
	cout << endl;
	cout << "                                         *******   **** " << endl;
	cout << "                                            *     *    *" << endl;
	cout << "                                            *     *    *" << endl;
	cout << "                                            *     *    *" << endl;
	cout << "                                            *      **** " << endl;
	cout << endl;
	cout << "                                 *       *   * * *    * * *     * * * " << endl;
	cout << "                                 *       *   *    *   *    *   *     *" << endl;
	cout << "                                 *       *   * * *    * * *    *     *" << endl;
	cout << "                                 *       *   *    *   *    *   *     *" << endl;
	cout << "                                 * * *   *   * * *    *     *   * * * " << endl;
	cout << "==================================_______________________________________==================================" << endl;
	cout << "                                        THU VIEN HANG DAU VIET NAM !" << endl;
	cout << "==================================_______________________________________==================================" << endl;
	cout << "1. Dang nhap" << endl;
	cout << "2. Dang ky tai khoan" << endl;
	cout << "3. Xem dieu khoan su dung thu vien truc tuyen LIBRO" << endl;
	cout << "Chon chuc nang : ";
	int choice;
	cin >> choice;
	switch (choice) {
	case 1:
		menuLogin(x);
		break;
	case 2:
		menuRegister(x);
		break;
	case 3:
		menuProvisions(x);
		break;
	default:
		cout << "\tLua chon cua ban khong hop le ! vui long kiem tra va nhap lai ! " << endl;
		cout << "\t................................................................" << endl;
		cin >> choice;
		break;
	};
};

void Menu::menuLogin(User x) {
	system("cls");
	cout << "==============================DANG NHAP==============================" << endl;
	char tdn[18] = "", mk[18] = "";
	cout << "Ten dang nhap : ";
	cin >> tdn;
	cout << "Mat khau : ";
	string ts = x.nhapMatKhau();
	for (int i = 0; i < ts.length(); i++) mk[i] = ts[i];
	x.inThongTin();
	
	if (x.checkPass(tdn, mk) == true) {
		cout << "Dang nhap thanh cong !" << endl;
		cout << "Nhan ENTER de tiep tuc !";
		cin.ignore();
		string str;
		getline(cin, str);
		system("cls");
		cout << "Xin cho trong giay lat..." << endl;
		cout << "Ban dang dang nhap voi tu cach doc gia !" << endl;
		Sleep(5000);
		mainMenu(x);
	}
	else {
		cout << "Ten dang nhap hoac mat khau khong chinh xac !" << endl;
		system("pause");
		menuLogin(x);
	};
};

void Menu::menuRegister(User x) {
	system("cls");
	cout << "==================DIEN THONG TIN VAO MAU BEN DUOI=================" << endl;
	x.subscription();
	cout << "Dang ki thanh cong !" << endl;
	cout << "Ban dong y voi dieu khoan su dung cua LIBRO ?" << endl;
	cout << "1. Yes" << endl;
	cout << "2. No" << endl;
	cout << "3. Xem noi dung cac dieu khoan su dung" << endl;

	int choice;
	cin >> choice;
	switch (choice) {
	case 1:
		system("cls");
		cout << "Xac nhan lai thong tin tai khoan :" << endl;
		x.inThongTin();
		x.ghi();
		system("pause");
		break;
	case 2:
		cout << "Ban chi co the su dung thu vien truc tuyen khi da doc va dong y voi noi dung cac dieu khoan cua chung toi" << endl;
		cout << "Nhan enter de quay lai" << endl;
		system("pause");
		menuIntro(x);
		break;
	case 3:
		menuProvisions(x);
		break;
	default:
		cout << "\tLua chon cua ban khong hop le ! vui long kiem tra va nhap lai ! " << endl;
		cout << "\t................................................................" << endl;
		cin >> choice;
		break;
	};
};

// Menu Điều Khoản sử dụng của thư viện
void Menu::menuProvisions(User x) {
	system("cls");
	ifstream docDuLieu("dieukhoansudung.txt");
	if (docDuLieu) {
		while (!docDuLieu.eof()) {
			string a;
			getline(docDuLieu, a);
			cout << a << endl;
		};
	}
	else {
		cout << "Loi : Khong mo duoc tep." << endl;
	};
	cout << "=================================================================================================" << endl;
	cout << "Nhan enter de quay lai !" << endl;
	string str;
	getline(cin, str);
	mainMenu(x);
};

// Menu chính
void Menu::mainMenu(User x) {
	system("cls");
	cout << "-------    ---       /\\     |\\   |    ---        ---  |    |  |    |" << endl;
	cout << "   |      |   \\     /  \\    | \\  |   /  __      /     |----|  |    |" << endl;
	cout << "   |      |---     /----\\   |  \\ |   \\   /      |     |    |  |    |" << endl;
	cout << "   |      |   \\   /      \\  |   \\|    ---       \\___  |    |   \\__/ " << endl;
	cout << endl;
	cout << "  Chon menu : " << endl;
	cout << "1. Tim kiem sach" << endl;
	cout << "2. Xem thong bao" << endl;
	cout << "3. Quan li tai khoan" << endl;
	cout << "4. Thoat" << endl;
	cout << "5. Dang xuat" << endl;
	int choice;
	cin >> choice;
	switch (choice) {
	case 1:
		menuTimSach(x);
		break;
	case 2:
		break;
	case 3:
		system("cls");
		menuAccount(x);
		break;
	case 5:
		menuIntro(x);
		break;
	default:
		cout << "\tLua chon cua ban khong hop le ! vui long kiem tra va nhap lai ! " << endl;
		cout << "\t................................................................" << endl;
		cin >> choice;
		break;
	};
};

// Menu tìm sách
void Menu::menuTimSach(User x) {
	system("cls");
	cout << "================DANH SACH CHUC NANG================" << endl;
	cout << endl;
	cout << "0. QUAY LAI" << endl;
	cout << "1. TIM SACH" << endl;
	cout << endl;
	cout << "===============MOI BAN CHON CHUC NANG===============" << endl;
	cout << endl;
	cout << "\tLua chon cua ban la : ";
	int choice;
	cin >> choice;
	cin.ignore();
	switch (choice) {
	case 0:
		mainMenu(x);
		break;
	case 1: 
		break;
	default:
		cout << "\tLua chon cua ban khong hop le ! vui long kiem tra va nhap lai ! " << endl;
		cout << "\t................................................................" << endl;
		cin >> choice;
		break;
	};
};

// Menu quản lí tài khoản
void Menu::menuAccount(User x) {
	system("cls");
	x.inThongTin();
	cout << "1. Doi mat khau" << endl;
	cout << "2. ..." << endl;
	cout << "Chon chuc nang : ";
	int choice;
	cin >> choice;
	switch (choice){
	case 1:
		system("cls");
		x.changePassWord();
		menuAccount(x);
		break;
	case 2:
		break;
	default:
		cout << "\tLua chon cua ban khong hop le ! vui long kiem tra va nhap lai ! " << endl;
		cout << "\t................................................................" << endl;
		cin >> choice;
		break;
	}
}












