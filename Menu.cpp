#include "menu.h"
#include "User.h"
#include "Book.h"
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
	cout << endl;
	ds = 1;
	cout << "----------------------------------------------------------------------" << endl;
	cout << "| " << ds++ << ". Dang nhap                                                       |" << endl;
	cout << "| " << ds++ << ". Dang ky tai khoan                                               |" << endl;
	cout << "| " << ds++ << ". Xem dieu khoan su dung thu vien truc tuyen LIBRO                |" << endl;
	cout << "----------------------------------------------------------------------" << endl;
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
	string tdn;
	cout << "Ten dang nhap : ";
	cin >> tdn;
	cout << "Mat khau : ";
	string mk = x.nhapMatKhau();

	if (x.soSanh(tdn, mk) == 2) {
		cout << "Dang nhap thanh cong !" << endl;
		cout << "Nhan ENTER de tiep tuc !";
		cin.ignore();
		string str;
		getline(cin, str);
		system("cls");
		cout << "Xin chao " << x.getName() << endl;
		cout << "Xin cho trong giay lat..." << endl;
		cout << "Ban dang dang nhap voi tu cach doc gia !" << endl;
		Sleep(5);
		mainMenu(x);
		return;
	}
	else {
		if (x.soSanh(tdn, mk) == 1) cout << "Mat khau khong chinh xac, hay thu lai !" << endl;
		else cout << "Ten dang nhap khong ton tai !" << endl;
	};
	system("pause");
	system("cls");

	ds = 0;
	cout << "----------------------------------------------------------------------" << endl;
	cout << "|===> " << ds++ << ". Quay lai                                                  |" << endl;
	cout << "|===> " << ds++ << ". Dang Nhap                                                 |" << endl;
	cout << "----------------------------------------------------------------------" << endl;
	cout << "Nhap lua chon :";

	int choice;
	cin >> choice;
	switch (choice) {
	case 0:
		menuIntro(x);
		break;
	case 1:
		menuLogin(x);
		break;
	default:
		cout << "\tLua chon cua ban khong hop le ! vui long kiem tra va nhap lai ! " << endl;
		cout << "\t................................................................" << endl;
		cin >> choice;
		break;
	};
}

void Menu::menuRegister(User x) {
	system("cls");

	cout << "==================DIEN THONG TIN VAO MAU BEN DUOI=================" << endl;
	x.subscription();
	ds = 1;
	cout << "Ban dong y voi dieu khoan su dung cua LIBRO ?" << endl;
	cout << "----------------------------------------------------------------------" << endl;
	cout << "|===> " << ds++ << ". Yes                                                         |" << endl;
	cout << "|===> " << ds++ << ". No                                                          |" << endl;
	cout << "|===> " << ds++ << ". Xem noi dung cac dieu khoan su dung                         |" << endl;
	cout << "----------------------------------------------------------------------" << endl;
	int choice;
	cin >> choice;
	switch (choice) {
	case 1:
		system("cls");
		x.ghi();
		cout << "Xin cho trong giay lat..." << endl;
		cout << "Ban dang dang nhap voi tu cach doc gia !" << endl;
		Sleep(100);
		mainMenu(x);
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
	else cout << "Loi : Khong mo duoc tep." << endl;
	
	cout << "=================================================================================================" << endl;
	cout << "Nhan enter de quay lai !" << endl;
	system("pause");
	menuIntro(x);
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
	ds = 1;
	cout << "----------------------------------------------------------------------" << endl;
	cout << "|===> " << ds++ << ". Tim kiem sach                                               |" << endl;
	cout << "|===> " << ds++ << ". Xem thong bao                                               |" << endl;
	cout << "|===> " << ds++ << ". Quan li tai khoan                                           |" << endl;
	cout << "|===> " << ds++ << ". Thoat                                                       |" << endl;
	cout << "|===> " << ds++ << ". Dang xuat                                                   |" << endl;
	cout << "----------------------------------------------------------------------" << endl;

	int choice;
	cin >> choice;
	switch (choice) {
	case 1:
		menuQuanLiSach(x);
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
		break;
	};
};

// Menu tìm sách
void Menu::menuQuanLiSach(User x) {
	system("cls");
	string str;
	Book b;
	cout << "================DANH SACH CHUC NANG================" << endl;
	cout << endl;
	ds = 0;
	cout << "----------------------------------------------------------------------" << endl;
	cout << "|===> " << ds++ << ". QUAY LAI                                                    |" << endl;
	cout << "|===> " << ds++ << ". TIM SACH                                                    |" << endl;
	cout << "|===> " << ds++ << ". THEM SACH                                                   |" << endl;
	cout << "----------------------------------------------------------------------" << endl;
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
		system("cls");
		cout << "Ban muon tim kiem theo ?" << endl;
		ds = 0;
		cout << "-----------------------------------------------------------------" << endl;
		cout << "|===> " << ds++ << ". Quay lai                                              |" << endl;
		cout << "|===> " << ds++ << ". Ten sach                                              |" << endl;
		cout << "|===> " << ds++ << ". Ma so sach                                            |" << endl;
		cout << "|===> " << ds++ << ". Ten tac gia                                           |" << endl;
		cout << "-----------------------------------------------------------------" << endl;
		cin >> choice;
		system("cls");
		switch (choice){
		// Quay lại
		case 0:
			menuQuanLiSach(x);
			break;
		// Tìm kiếm theo tên
		case 1 :
			cout << "Nhap vao ten sach : ";
			cin.ignore();
			getline(cin, str);
			cout << "======DANH SACH CAC SACH LIEN QUAN ======\n" << endl;
			b.find(1, str);
			break;
		// Tìm kiếm theo mã số sách
		case 2 :
			cout << "Nhap ma so sach : ";
			cin.ignore();
			getline(cin, str);
			cout << "======DANH SACH CAC SACH LIEN QUAN ======\n" << endl;
			b.find(2, str);
			break;
		// Tìm kiếm theo tác giả
		case 3 :
			cout << "Nhap ten tac gia : ";
			cin.ignore();
			getline(cin, str);
			cout << "======DANH SACH CAC SACH LIEN QUAN ======\n" << endl;
			b.find(3, str);
			break;
		default:
			cout << "Lua chon khong hop le" << endl;
			menuQuanLiSach(x);
			break;
		};
		cout << "\n===============================================" << endl;
		cout << "Chon sach : ";
		cin >> choice;
		system("cls");
		
		system("pause");
		mainMenu(x);
		break;
	case 2:
		system("cls");
		cout << "=========================== Nhap vao thong tin sach ==========================" << endl;
		b.fill();
		cout << "Nhan ENTER de tiep tuc !";
		getline(cin, str);
		system("cls");
		cout << "==================== Ban dong y them sach nay vao thu vien ? =================" << endl;
		b.inThongTin();
		cout << "----------------------------------------------------------------------" << endl;
		cout << "| 1. Yes                                               2. No         |" << endl;
		cout << "----------------------------------------------------------------------" << endl;
		cin >> choice;
		switch (choice){
		case 1:
			b.add();
			cout << "Da bo sung thong tin sach vao thu vien !" << endl;
			system("pause");
			mainMenu(x);
			break;
		case 2:
			break;
		default:
			break;
		};

		break;
	default:
		cout << "\tLua chon cua ban khong hop le ! vui long kiem tra va nhap lai ! " << endl;
		cout << "\t................................................................" << endl;
		menuQuanLiSach(x);
		break;
	};
};

// Menu quản lí tài khoản
void Menu::menuAccount(User x) {
	system("cls");
	x.inThongTin();
	ds = 0;
	cout << "----------------------------------------------------------------------" << endl;
	cout << "|===> " << ds++ << ". Quay lai                                                    |" << endl;
	cout << "|===> " << ds++ << ". Xem thong tin tai khoan                                     |" << endl;
	cout << "|===> " << ds++ << ". Doi mat khau                                                |" << endl;
	cout << "----------------------------------------------------------------------" << endl;
	cout << "Chon chuc nang : ";
	int choice;
	cin >> choice;
	switch (choice){
	case 0:
		mainMenu(x);
		break;
	case 1:
		x.inThongTin();
		break;
	case 2:
		system("cls");
		x.changePassWord();
		menuAccount(x);
		break;
	default:
		cout << "\tLua chon cua ban khong hop le ! vui long kiem tra va nhap lai ! " << endl;
		cout << "\t................................................................" << endl;
		cin >> choice;
		break;
	}
}

////////////////////////////////////////////////////////////////////////////////////
//private:5

Book *Menu::danhSachTimKiem(Book b, int i) {
	Book sach[100];
	sach[i] = b;
	return sach;
}


