#include "menu.h"
#include "User.h"
#include "Book.h"
#include "Account.h"
#include "ThongBaoThuVien.h"
#include "Complex.h"
#include <iostream>
#include <iomanip>
#include <Windows.h>
#include <fstream>
using namespace std;
Menu::Menu(){
};
Menu::~Menu(){
};

void Menu::menuIntro(Account x) {
	system("cls");
	cout << "*       *       *    ********     *           *******      *******        *        *    ********  " << endl;
	cout << " *     * *     *     *            *          *            *       *       * *     * *   *	       " << endl;
	cout << "  *   *   *   *      ********     *         *            *         *      *  *   *  *   *******   " << endl;
	cout << "   * *     * *       *            *          *            *       *       *    *    *   *         " << endl;
	cout << "    *       *        ********     ********    *******      *******        *         *   ********  " << endl;
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
	cout << setw(103) << thoiGianHeThong() << endl;
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
		menuIntro(x);
		break;
	};
};

void Menu::menuLogin(Account x) {
	system("cls");
	cout << "==============================DANG NHAP==============================" << endl;
	string tdn;
	cout << "Ten dang nhap : ";
	cin.ignore();
	getline(cin, tdn);
	cout << "Mat khau : ";
	string mk = x.nhapMatKhau();
	int l = x.checkLogin(tdn, mk);

	switch (l){
	case 2:
		cout << "Dang nhap thanh cong !" << endl;
		cout << "Nhan ENTER de tiep tuc !";
		cin.ignore();
		getline(cin, str);
		system("cls");
		cout << "Xin chao " << x.getHoTen() << endl;
		cout << "Xin cho trong giay lat..." << endl;
		cout << "Ban dang dang nhap voi tu cach doc gia !" << endl;
		Sleep(5);
		mainMenu(x);
		return;
	case 1:
		cout << "Mat khau khong chinh xac, hay thu lai !" << endl;
		break;
	case 0:
		cout << "Ten dang nhap khong ton tai !" << endl;
		break;
	case -1:
		cout << "Tai khoan nay da bi khoa, xin lien he den chi nhanh thu vien gan nhat de biet them chi tiet !" << endl;
		break;
	};
	
	system("pause");
	system("cls");

	ds = 0;
	cout << "----------------------------------------------------------------------" << endl;
	cout << "|===> " << ds++ << ". Quay lai                                                  |" << endl;
	cout << "|===> " << ds++ << ". Dang nhap                                                 |" << endl;
	cout << "|===> " << ds++ << ". Dang ki                                                   |" << endl;
	cout << "----------------------------------------------------------------------" << endl;
	cout << "Nhap lua chon :";
	cin >> choice;
	switch (choice) {
	case 0:
		menuIntro(x);
		break;
	case 1:
		menuLogin(x);
		break;
	case 2:
		menuRegister(x);
		break;
	default:
		cout << "\tLua chon cua ban khong hop le ! vui long kiem tra va nhap lai ! " << endl;
		cout << "\t................................................................" << endl;
		menuLogin(x);
		break;
	};
};

// k là mã định danh đăng kí, k = 0 : độc giả, k = 1 : thủ thư, k = 2, admin
void Menu::menuRegister(Account x, int k) {
	system("cls");

	cout << "==================DIEN THONG TIN VAO MAU BEN DUOI=================" << endl;
	x.subscription();
	system("cls");
	cout << "============================= Xac nhan lai thong tin tai khoan =================================" << endl;
	cout << x;
	// Gán vai trò cho Account
	switch (k) {
	case 0:
		x.docGia();
		break;
	case 1:
		x.thuThu();
		break;
	case 2:
		x.admin();
		break;
	};

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
		system("pause");
		menuRegister(x);
		break;
	};
};

// Menu Điều Khoản sử dụng của thư viện
void Menu::menuProvisions(Account x) {
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
	
	cout << "============================================================================================================" << endl;
	cout << "Nhan enter de quay lai !" << endl;
	system("pause");
	menuIntro(x);
};

// Menu chính
void Menu::mainMenu(Account x) {
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
	cout << "|===> " << ds++ << ". Quan li tai khoan ca nhan                                   |" << endl;
	cout << "|===> " << ds++ << ". Quan li tai khoan va nguoi dung tren he thong               |" << endl;
	cout << "|===> " << ds++ << ". Gui thu gop y                                               |" << endl;
	cout << "|===> " << ds++ << ". Dang xuat                                                   |" << endl;
	cout << "|===> " << ds++ << ". Thoat                                                       |" << endl;
	cout << "----------------------------------------------------------------------" << endl;

	int choice;
	cin >> choice;
	switch (choice) {
	case 1:
		menuQuanLiSach(x);
		break;
	case 2:
		menuThongBaoThuVien(x);
		break;
	case 3:
		menuUser(x);
		break;
	case 4:
		menuManage(x);
		break;
	case 5:
		menuComment(x);
		break;
	case 6:
		menuIntro(x);
		break;
	case 7:
		break;
	default:
		cout << "\tLua chon cua ban khong hop le ! vui long kiem tra va nhap lai ! " << endl;
		cout << "\t................................................................" << endl;
		break;
	};
};

// Menu tìm sách
void Menu::menuQuanLiSach(Account x) {
	// xóa thông tin trong file lưu tạm
	ofstream ghi("luutam.txt", ios::trunc);

	system("cls");
	string str;
	cout << "================DANH SACH CHUC NANG================" << endl;
	cout << endl;
	ds = 0;
	cout << "----------------------------------------------------------------------" << endl;
	cout << "|===> " << ds++ << ". QUAY LAI                                                    |" << endl;
	cout << "|===> " << ds++ << ". TIM SACH                                                    |" << endl;
	cout << "|===> " << ds++ << ". THEM SACH                                                   |" << endl;
	cout << "|===> " << ds++ << ". XEM CAC SACH DUOC DANG KI MUON                              |" << endl;
	cout << "----------------------------------------------------------------------" << endl;
	cout << endl;
	cout << "===============MOI BAN CHON CHUC NANG===============" << endl;
	cout << endl;
	cout << "\tLua chon cua ban la : ";
	int choice;
	cin >> choice;
	switch (choice) {
	case 0:
		mainMenu(x);
		break;
	case 1:
		menuTimSach(x);
		break;
	case 2:
		menuThemSach(x);
		break;
	case 3:

		break;
	};
}

void Menu::menuTimSach(Account x) {
	system("cls");
	bool valid;
	int choice;
	string str;
	Book b;
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

	switch (choice) {
	// Quay lại
	case 0:
		menuQuanLiSach(x);
		break;
	// Tìm kiếm theo tên
	case 1:
		cout << "Nhap vao ten sach : ";
		cin.ignore();
		getline(cin, str);
		cout << "======DANH SACH CAC SACH LIEN QUAN ======\n" << endl;
		b.find(1, str, valid);
		break;
	// Tìm kiếm theo mã số sách
	case 2:
		cout << "Nhap ma so sach : ";
		cin.ignore();
		getline(cin, str);
		cout << "======DANH SACH CAC SACH LIEN QUAN ======\n" << endl;
		b.find(2, str, valid);
		break;
	// Tìm kiếm theo tác giả
	case 3:
		cout << "Nhap ten tac gia : ";
		cin.ignore();
		getline(cin, str);
		cout << "======DANH SACH CAC SACH LIEN QUAN ======\n" << endl;
		b.find(3, str, valid);
		break;
	default:
		cout << "Lua chon khong hop le" << endl;
		menuQuanLiSach(x);
		break;
	};

	if (valid == false) cout << "Khong tim thay sach tren trong thu vien !" << endl;
	cout << "\n===============================================" << endl;
	if (valid == true) {
		cout << "Chon sach : ";
		cin >> choice;
		b.layID(choice);
		system("cls");
		b.inThongTin();
		cout << endl;
		ds = 0;
		cout << "-----------------------------------------------------------------" << endl;
		cout << "|===> " << ds++ << ". Quay lai                                              |" << endl;
		cout << "|===> " << ds++ << ". Gui yeu cau dang ki muon sach                         |" << endl;
		cout << "-----------------------------------------------------------------" << endl;
		cin >> choice;
		switch (choice) {
		case 0:
			mainMenu(x);
			break;
		case 1:
			
			cout << "Yeu cau cua ban da duoc gui den thu thu !" << endl;
			system("pause");
			mainMenu(x);
			break;
		};
	}
	else {
		system("pause");
		menuTimSach(x);
	};
};

//Menu thêm sách ( tính năng của thủ thư )
void Menu::menuThemSach(Account x) {
	system("cls");
	string str;
	Book b;
	cin.ignore();
	int choice;
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
	switch (choice) {
	case 1:
		b.add();
		cout << "Da bo sung thong tin sach vao thu vien !" << endl;
		system("pause");
		mainMenu(x);
		break;
	case 2:
		mainMenu(x);
		break;
	default:
		cout << "\tLua chon cua ban khong hop le ! vui long kiem tra va nhap lai ! " << endl;
		cout << "\t................................................................" << endl;
		menuQuanLiSach(x);
		break;
	};
};


// Menu quản lí tài khoản
void Menu::menuUser(Account x) {
	system("cls");
	cout << x;
	ds = 0;
	cout << "----------------------------------------------------------------------" << endl;
	cout << "|===> " << ds++ << ". Quay lai                                                    |" << endl;
	cout << "|===> " << ds++ << ". Quan li tai khoan                                           |" << endl;
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
		menuAccount(x);
		break;
	case 2:
		system("cls");
		x.changePassWord();
		menuUser(x);
		break;
	default:
		cout << "\tLua chon cua ban khong hop le ! vui long kiem tra va nhap lai ! " << endl;
		cout << "\t................................................................" << endl;
		system("pause");
		menuUser(x);
		break;
	};
};

void Menu::menuAccount(Account x) {
	system("cls");
	cout << "Danh sach cac tai khoan :" << endl;
	cout << "----------------------------------------------------------------------" << endl;
	cout << "|===> " << ds++ << ". Quay lai                                                    |" << endl;
	cout << "|===> " << ds++ << ". Tao tai khoan moi                                           |" << endl;
	cout << "|===> " << ds++ << ". Xem thong tin tai khoan                                     |" << endl;
	cout << "----------------------------------------------------------------------" << endl;
	cout << x;
	cout << "Chon tai khoan : ";
	cin >> choice;
	switch (choice) {
	case 0:
		menuAccount(x);
	case 1:
		break;
	case 2:
		break;
	case 3:
		break;
	};
	ds = 0;
	cout << "----------------------------------------------------------------------" << endl;
	cout << "|===> " << ds++ << ". Doi mat khau                                                |" << endl;
	cout << "----------------------------------------------------------------------" << endl;

};

// Quản lí tài khoản và người dùng trên hệ thông ( tính năng của admin )
void Menu::menuManage(Account x) {
	// xóa thông tin trong file lưu tạm
	ofstream ghi("luutam.txt", ios::trunc);

	system("cls");
	cout << "He thong hien dang co : " << x.tinhSoLuong() << " thanh vien da dang ky" << endl;
	ds = 0;
	cout << "----------------------------------------------------------------------" << endl;
	cout << "|===> " << ds++ << ". Quay lai                                                    |" << endl;
	cout << "|===> " << ds++ << ". Tim User                                                    |" << endl;
	cout << "|===> " << ds++ << ". Danh sach cac nguoi dung hien tai                           |" << endl;
	cout << "|===> " << ds++ << ". Xem cac yeu cau muon sach                                   |" << endl;
	cout << "----------------------------------------------------------------------" << endl;
	cout << "Chon chuc nang : ";
	int choice;
	cin >> choice;
	switch (choice){
	case 0:
		mainMenu(x);
		break;
	case 1:
		menuTimUser(x);
		break;
	case 2:
		break;
	case 3:
		break;
	default:
		break;
	};
};

void Menu::menuTimUser(Account x) {
	system("cls");
	// trả về false khi không có kết quả tìm kiếm nào
	bool valid;
	cout << "Tim kiem theo ?" << endl;
	ds = 0;
	cout << "-----------------------------------------------------------------" << endl;
	cout << "|===> " << ds++ << ". Quay lai                                              |" << endl;
	cout << "|===> " << ds++ << ". Ten nguoi dung                                        |" << endl;
	cout << "|===> " << ds++ << ". Ma so ID                                              |" << endl;
	cout << "|===> " << ds++ << ". So CMND                                               |" << endl;
	cout << "-----------------------------------------------------------------" << endl;
	cin >> choice;
	switch (choice) {
	// Quay lại
	case 0:
		menuManage(x);
		break;
	// Tìm kiếm theo tên
	case 1:
		cout << "Nhap vao ten nguoi dung : ";
		cin.ignore();
		getline(cin, str);
		cout << "======DANH SACH CAC USER LIEN QUAN ======\n" << endl;
		cout << "-------------------------------------------------------------------------------------------------" << endl;
		cout << "| STT |Ma so ID|        Ho va ten        |    So CMND    |  So dien thoai  |    Ngay dang ki    |" << endl;
		cout << "-------------------------------------------------------------------------------------------------" << endl;
		x.find(1, str, valid);
		break;
	// Tìm kiếm theo mã ID
	case 2:
		cout << "Nhap ma so ID : ";
		cin.ignore();
		getline(cin, str);
		cout << "======DANH SACH CAC USER LIEN QUAN ======\n" << endl;
		cout << "-------------------------------------------------------------------------------------------------" << endl;
		cout << "| STT |Ma so ID|        Ho va ten        |    So CMND    |  So dien thoai  |    Ngay dang ki    |" << endl;
		cout << "-------------------------------------------------------------------------------------------------" << endl;
		x.find(2, str, valid);
		break;
	// Tìm kiếm theo số CMND
	case 3:
		cout << "Nhap so CMND : ";
		cin.ignore();
		getline(cin, str);
		cout << "======DANH SACH CAC USER LIEN QUAN ======\n" << endl;
		cout << "-------------------------------------------------------------------------------------------------" << endl;
		cout << "| STT |Ma so ID|        Ho va ten        |    So CMND    |  So dien thoai  |    Ngay dang ki    |" << endl;
		cout << "-------------------------------------------------------------------------------------------------" << endl;
		x.find(3, str, valid);
		break;
	default:
		cout << "Lua chon khong hop le" << endl;
		menuManage(x);
		break;
	};

	if (valid == false) cout << "Khong tim thay thong tin User tren trong thu vien !" << endl;
	cout << "\n===============================================" << endl;
	if (valid == true) {
		cout << "Chon User : ";
		cin >> choice;
		x.layID(choice);
		system("cls");
		cout << x;
		cout << endl;
		ds = 0;
		cout << "-----------------------------------------------------------------" << endl;
		cout << "|===> " << ds++ << ". Quay lai                                              |" << endl;
		cout << "|===> " << ds++ << ". Chinh sua thong tin User                              |" << endl;
		cout << "|===> " << ds++ << ". Xoa User                                              |" << endl;
		cout << "-----------------------------------------------------------------" << endl;
		cin >> choice;
		switch (choice) {
		case 0:
			mainMenu(x);
			break;
		case 1:
			menuSuaThongTinUser(x);
			break;
		case 2:
			cout << "Dong y khoa nguoi dung nay ?" << endl;
			cout << "1. Yes               2. No" << endl;
			cin >> choice;
			switch (choice) {
			case 1:
				x.khoaUser();
				x.ghi();
				cout << "Nguoi dung nay da bi khoa" << endl;
				break;
			case 2:
				break;
			};
			system("pause");
			mainMenu(x);
		};
	}
	else {
		system("pause");
		menuTimUser(x);
	};
};

void Menu::menuSuaThongTinUser(Account x) {
	system("cls");
	cout << x;
	cout << "Nhap thong tin muon chinh sua : ";
	cin.ignore();
	getline(cin, str);
	if (soSanh(str, "Nghe nghiep") == true) {
		cout << "Nhap nghe nghiep moi : ";
		getline(cin, str);
		x.setJob(str);
	};
	if (soSanh(str, "Dia chi") == true) {
		cout << "Nhap dia chi moi : ";
		getline(cin, str);
		x.setAddress(str);
	};
	if (soSanh(str, "So dien thoai") == true) {
		cout << "Nhap so dien thoai : ";
		getline(cin, str);
		x.setSDT(str);
	};
	cout << "Ban dong y chinh sua thong tin nay ?" << endl;
	cout << "1. Yes                         2. No" << endl;
	cin >> choice;
	switch (choice) {
	case 1:
		x.ghi();
		cout << "Da chinh sua thong tin" << endl;
		break;
	case 2:
		break;
	};
	system("pause");
	mainMenu(x);
};

//Menu thông báo thư viện
void Menu::menuThongBaoThuVien(Account x) {
	int choice;
	do {
		system("cls");
		ThongBaoThuVien data[Max_Anouce];
		string str[Max_Anouce];
		cout << "TAT CA THONG BAO :" << endl;

		fstream f;
		f.open("thongbao.txt", ios::in);
		int line = 0;
		int soDong;
		while (!f.eof()) {
			string x;
			fflush(stdin);
			getline(f, x);
			str[line] = x;
			line++;
		};
		f.close();

		soDong = (line + 1) / 2;
		for (int i = 0; i < soDong; i++) {
			data[i].tieuDe = str[i * 2];
			data[i].noiDung = str[i * 2 + 1];
			string S = data[i].noiDung;
			if (S != "") {
				cout << i + 1 << ". " << " [TIEU DE]: " << data[i].tieuDe << endl;
				cout << "\t    [NOI DUNG]";
				cout << "\t";
				for (int i = 0; i < 45; i++) {
					if (i < S.length()) cout << S[i];
				};
				cout << "..." << endl << endl << endl;
			};
		};

		cout << "-----------------" << endl;
		cout << "| Menu thong bao | " << endl;
		cout << "-----------------" << endl;
		cout << "\t" << "1. Them thong bao" << endl;
		cout << "\t" << "2. Chinh sua thong bao" << endl;
		cout << "\t" << "3. Xoa thong bao" << endl;
		cout << "\t" << "4. Doc noi dung thong bao" << endl;
		cout << "\t" << "5. Thoat" << endl;
		cout << "\t" << "***********************" << endl;
		cout << "\t" << "Nhap lua chon cua ban: ";
		cin >> (choice);

		ThongBaoThuVien x;
		switch (choice) {
		case 1:
			cin.ignore();
			x.themThongBao();
			break;
		case 2:
			cin.ignore();
			x.suaThongBao(data, soDong);
			break;
		case 3:
			cin.ignore();
			x.xoaThongBao(data, soDong);
			break;
		case 4:
			cin.ignore();
			x.docThongBao(data);
			break;
		case 5:
			return;
			break;
		default:
			cout << "Moi ban nhap lai";
			cin >> choice;
			break;
		};
	} while (choice != 4);
};

void Menu::menuComment(Account x) {
	system("pause");
};

////////////////////////////////////////////////////////////////////////////////////
//private:

string Menu::thoiGianHeThong() {
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