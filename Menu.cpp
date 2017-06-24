#include "menu.h"
#include "User.h"
#include "Book.h"
#include "ThongBaoThuVien.h"
#include "Complex.h"
#include "thongTinMuonSach.h"
#include "Comment.h"
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <Windows.h>
#include <fstream>
using namespace std;
Menu::Menu() {
};
Menu::~Menu() {
};

void Menu::menuIntro() {
	system("cls");
	doHoa(10);
	cout << endl << endl;
	cout << "\t*       *       *    ********     *           *******      *******        *        *    ********  " << endl;
	cout << "\t *     * *     *     *            *          *            *       *       * *     * *   *	       " << endl;
	cout << "\t  *   *   *   *      ********     *         *            *         *      *  *   *  *   *******   " << endl;
	cout << "\t   * *     * *       *            *          *            *       *       *    *    *   *         " << endl;
	cout << "\t    *       *        ********     ********    *******      *******        *         *   ********  " << endl;
	cout << endl;
	cout << "\t                                         *******   **** " << endl;
	cout << "\t                                            *     *    *" << endl;
	cout << "\t                                            *     *    *" << endl;
	cout << "\t                                            *     *    *" << endl;
	cout << "\t                                            *      **** " << endl;
	cout << endl;
	cout << "\t                                 *       *   * * *    * * *     * * * " << endl;
	cout << "\t                                 *       *   *    *   *    *   *     *" << endl;
	cout << "\t                                 *       *   * * *    * * *    *     *" << endl;
	cout << "\t                                 *       *   *    *   *    *   *     *" << endl;
	cout << "\t                                 * * *   *   * * *    *     *   * * * " << endl;
	doHoa(12);
	cout << "=======================================_______________________________________=========================================" << endl;
	cout << "                                           THU VIEN HANG DAU VIET NAM !" << endl;
	cout << "=======================================_______________________________________=========================================" << endl;
	
	cout << endl;
	cout << setw(103) << right << thoiGianHeThong() << endl;
	cout << endl;

	doHoa(9);
	cout << "\t\t\t|@|--------------------------------------------------------------------|@|" << endl;
	cout << "\t\t\t|@| ";
	doHoa(8);
	cout << 1 << ". DANG NHAP                                                       ";
	doHoa(9);
	cout << "|@|" << endl;
	cout << "\t\t\t|@|--------------------------------------------------------------------|@|" << endl;
	cout << "\t\t\t|@| ";
	doHoa(8);
	cout << 2 << ". DANG KI THANH VIEN                                              ";
	doHoa(9);
	cout << "|@|" << endl;
	cout << "\t\t\t|@|--------------------------------------------------------------------|@|" << endl;
	cout << "\t\t\t|@| ";
	doHoa(8);
	cout << 3 << ".XEM DIEU KHOANG SU DUNG THU VIEN TRUC TUYEN LIBPRO               ";
	doHoa(9);
	cout << "|@|" << endl;
	cout << "\t\t\t|@|--------------------------------------------------------------------|@|" << endl;
	doHoa(11);
	cout << "\n\n\t\t\tChon chuc nang : ";

	choice = luaChon();
	switch (choice) {
	case 1:
		menuLogin();
		break;
	case 2:
		menuRegister();
		break;
	case 3:
		menuProvisions();
		break;
	default:
		doHoa(15);
		cout << "\n\tLua chon cua ban khong hop le ! vui long kiem tra va nhap lai ! " << endl;
		cout << "\t................................................................" << endl;
		menuIntro();
		break;
	};
};

void Menu::menuLogin() {
	system("cls");
	User x;
	int k;

	doHoa(14);
	cout << " \n\n\n\t\t    ==================================DANG NHAP================================     " << endl;
	cout << " \t\t           ============================================================             " << endl;
	cout << " \t\t                          ===================================                       \n\n\n" << endl;

	string tdn;
	doHoa(12);
	cout << "\t\t\tTen dang nhap : ";
	doHoa(15);
	getline(cin, tdn);
	doHoa(12);
	cout << "\t\t\tMat khau : ";
	doHoa(15);

	string mk = nhapKiTuAn();
	if (tdn == "" || mk == "") {
		menuLogin();
		return;
	};
	int l = x.checkLogin(tdn, mk, x, k);
	switch (l) {
	case 2:
		menuCho(x, k);
		return;
	case 1:
		doHoa(13);
		cout << "\t\t\tMat khau khong chinh xac, hay thu lai !" << endl;
		break;
	case 0:
		doHoa(13);
		cout << "\t\t\tTen dang nhap khong ton tai !" << endl;
		break;
	case -1:
		doHoa(13);
		cout << "\t\t\tTai khoan nay da bi khoa, xin lien he den chi nhanh thu vien gan nhat de biet them chi tiet !" << endl;
		break;
	};

	system("pause");
	system("cls");

	ds = 0;
	doHoa(10);
	cout << "----------------------------------------------------------------------" << endl;
	cout << "|===> " << ds++ << ". Quay lai                                                  |" << endl;
	cout << "|===> " << ds++ << ". Dang Nhap                                                 |" << endl;
	cout << "|===> " << ds++ << ". Dang ki                                                   |" << endl;
	cout << "----------------------------------------------------------------------" << endl;
	cout << "Nhap lua chon :";
	doHoa(15);
	choice = luaChon();
	switch (choice) {
	case 0:
		menuIntro();
		break;
	case 1:
		menuLogin();
		break;
	case 2:
		menuRegister();
		break;
	default:
		doHoa(5);
		cout << "\tLua chon cua ban khong hop le ! vui long kiem tra va nhap lai ! " << endl;
		cout << "\t................................................................" << endl;
		menuLogin();
		break;
	};
};

void Menu::menuCho(User x, int &k) {
	doHoa(9);
	cout << "\t\t\tDang nhap thanh cong !" << endl;
	cout << "\t\t\tNhan ENTER de tiep tuc !";
	getline(cin, str);
	system("cls");
	doHoa(15);
	cout << "\t\t\tXin chao " << x.getHoTen() << endl;
	cout << "\t\t\tXin cho trong giay lat..." << endl;
	if (k != 0) {
		cout << "\t\tBan dang dang nhap voi tu cach ";
		if (k == 1) cout << "\t\tthu thu !" << endl;
		if (k == 2) cout << "\t\tadmin !" << endl;
	};
	Sleep(300);
	mainMenu(x, k);
};

// k là mã định danh đăng kí, k = 0 : độc giả, k = 1 : thủ thư, k = 2 : admin
void Menu::menuRegister(bool a, bool b) {
	system("cls");
	User x;
	int k = 0;
	doHoa(12);
	cout << "\n\n============================================DIEN THONG TIN VAO MAU BEN DUOI=========================================" << endl;
	doHoa(15);
	x.subscription();
	ds = 1;
	doHoa(12);
	cout << "\n============================= Xac nhan lai thong tin tai khoan =================================" << endl;
	doHoa(15);
	x.inUser();
	if (a == true) x.setThuThu();
	if (b == true) x.setAdmin();
	cout << "Ban dong y voi dieu khoan su dung cua LIBRO ?" << endl;
	doHoa(10);
	cout << "----------------------------------------------------------------------" << endl;
	cout << "|===> " << ds++ << ". Yes                                                         |" << endl;
	cout << "|===> " << ds++ << ". No                                                          |" << endl;
	cout << "|===> " << ds++ << ". Xem noi dung cac dieu khoan su dung                         |" << endl;
	cout << "----------------------------------------------------------------------" << endl;
	choice = luaChon();
	switch (choice) {
	case 1:
		system("cls");
		x.ghi();
		doHoa(15);
		cout << "Xin cho trong giay lat..." << endl;
		cout << "Ban dang dang nhap voi tu cach doc gia !" << endl;
		Sleep(100);
		mainMenu(x, k);
		break;
	case 2:
		doHoa(15);
		cout << "Ban chi co the su dung thu vien truc tuyen khi da doc va dong y voi noi dung cac dieu khoan cua chung toi" << endl;
		cout << "Nhan enter de quay lai" << endl;
		system("pause");
		menuIntro();
		break;
	case 3:
		menuProvisions();
		break;
	default:
		doHoa(15);
		cout << "\tLua chon cua ban khong hop le ! vui long kiem tra va nhap lai ! " << endl;
		cout << "\t................................................................" << endl;
		system("pause");
		menuRegister();
		break;
	};
};

// Menu Điều Khoản sử dụng của thư viện
void Menu::menuProvisions() {
	system("cls");
	doHoa(15);
	ifstream docDuLieu("dieukhoansudung.txt");
	if (docDuLieu) {
		while (!docDuLieu.eof()) {
			string a;
			getline(docDuLieu, a);
			cout << a << endl;
		};
	}
	else cout << "Loi : Khong mo duoc tep." << endl;
	doHoa(15);
	cout << "=================================================================================================" << endl;
	cout << "Nhan enter de quay lai !" << endl;
	system("pause");
	menuIntro();
};

// Menu chính
void Menu::mainMenu(User x, int &k) {
	switch (k) {
	case 0:// doc gia
		system("cls");
		doHoa(12);
		cout << "\n\n\n";
		cout << "\t\t\t   -------    ---       /\\     |\\   |    ---        ---  |    |  |    |" << endl;
		cout << "\t\t\t      |      |   \\     /  \\    | \\  |   /  __      /     |----|  |    |" << endl;
		cout << "\t\t\t      |      |---     /----\\   |  \\ |   \\   /      |     |    |  |    |" << endl;
		cout << "\t\t\t      |      |   \\   /      \\  |   \\|    ---       \\___  |    |   \\__/ " << endl;
		cout << endl;
		doHoa(14);
		cout << setw(64) << thoiGianHeThong() << endl;
		cout << endl;
		doHoa(10);
		cout << "\n\n\t\t" << "SACH LA NGUON CUA CAI QUY BAU CUA THE GIOI VA LA DI SAN CUA CAC THE HE VA CUA CAC QUOC GIA ." << endl;
		cout << setw(74) << "– Henry David Thoreau –" << endl;
		cout << endl;
		cout << endl << endl;
		doHoa(14);
		cout << "\t\t\t\t\t    -----------------------------------" << endl;
		doHoa(13);
		cout << "\t\t\t||============================================================================||" << endl;
		cout << "\t\t\t|| ";
		doHoa(12);
		cout << "== > 1.TIM SACH                                                            ";
		doHoa(13);
		cout << "|| " << endl;
		cout << "\t\t\t||----------------------------------------------------------------------------||" << endl;
		cout << "\t\t\t|| ";
		doHoa(12);
		cout << "== > 2.XEM THONG BAO                                                       ";
		doHoa(13);
		cout << "|| " << endl;
		cout << "\t\t\t||----------------------------------------------------------------------------||" << endl;
		cout << "\t\t\t|| ";
		doHoa(12);
		cout << "== > 3.QUAN LY TAI KHOAN CA NHAN                                          ";
		doHoa(13);
		cout << "|| " << endl;
		cout << "\t\t\t||----------------------------------------------------------------------------||" << endl;
		cout << "\t\t\t|| ";
		doHoa(12);
		cout << "== > 4.GUI THU GOP Y                                                       ";
		doHoa(13);
		cout << "|| " << endl;
		cout << "\t\t\t||----------------------------------------------------------------------------||" << endl;
		cout << "\t\t\t|| ";
		doHoa(12);
		cout << "== > 5.DANG XUAT                                                           ";
		doHoa(13);
		cout << "|| " << endl;
		cout << "\t\t\t||----------------------------------------------------------------------------||" << endl;
		cout << "\t\t\t|| ";
		doHoa(12);
		cout << "== > 6.THOAT                                                               ";
		doHoa(13);
		cout << "|| " << endl;
		cout << "\t\t\t||============================================================================||" << endl;
		doHoa(14);
		cout << "\n\n\t\t\tChon menu : ";
		choice = luaChon();
		switch (choice) {
		case 1:
			menuTimSach(x, k);
			break;
		case 2:
			menuThongBaoThuVien(x, k);
			break;
		case 3:
			menuUser(x, k);
			break;
		case 4:
			menuComment(x, k);
			break;
		case 5:
			menuIntro();
			break;
		case 6:
			return;
			break;
		default:
			doHoa(15);
			cout << "\tLua chon cua ban khong hop le ! vui long kiem tra va nhap lai ! " << endl;
			cout << "\t................................................................" << endl;
			mainMenu(x, k);
			break;
		};
	case 1:
		system("cls");
		doHoa(12);
		cout << "\n\n\n";
		cout << "\t\t\t   -------    ---       /\\     |\\   |    ---        ---  |    |  |    |" << endl;
		cout << "\t\t\t      |      |   \\     /  \\    | \\  |   /  __      /     |----|  |    |" << endl;
		cout << "\t\t\t      |      |---     /----\\   |  \\ |   \\   /      |     |    |  |    |" << endl;
		cout << "\t\t\t      |      |   \\   /      \\  |   \\|    ---       \\___  |    |   \\__/ " << endl;
		cout << endl;
		doHoa(14);
		cout << right << setw(64) << thoiGianHeThong() << endl;
		cout << endl;
		doHoa(10);
		cout << "\n\n\t\t" << "SACH LA NGUON CUA CAI QUY BAU CUA THE GIOI VA LA DI SAN CUA CAC THE HE VA CUA CAC QUOC GIA ." << endl;
		cout << right << setw(74) << "– Henry David Thoreau –" << endl;
		cout << endl;
		cout << endl << endl;
		doHoa(9);
		cout << "\n\n\t\t\t\t\t\t    @@ -----THU THU----- @@" << endl;
		cout << "\t\t\t\t\t    -----------------------------------" << endl;
		doHoa(12);
		cout << "\t\t\t||==========================================================================||" << endl;
		cout << "\t\t\t|| ";
		doHoa(14);
		cout << " ==> 1.QUAN LY SACH                                                      ";
		doHoa(12);
		cout << "|| " << endl;
		cout << "\t\t\t||--------------------------------------------------------------------------||" << endl;
		cout << "\t\t\t||  ";
		doHoa(14);
		cout << "==> 2.QUAN LY TAI KHOAN CA NHAN                                         ";
		doHoa(12);
		cout << "|| " << endl;
		cout << "\t\t\t||--------------------------------------------------------------------------||" << endl;
		cout << "\t\t\t||";
		doHoa(14);
		cout << "  ==> 3.XEM THONG BAO      	                                            ";
		doHoa(12);
		cout << "|| " << endl;
		cout << "\t\t\t||--------------------------------------------------------------------------||" << endl;
		cout << "\t\t\t||  ";
		doHoa(14);
		cout << "==> 4.HOP THU GOP Y                                                     ";
		doHoa(12);
		cout << "|| " << endl;
		cout << "\t\t\t||--------------------------------------------------------------------------||" << endl;
		cout << "\t\t\t|| ";
		doHoa(14);
		cout << " ==> 5.DANG XUAT                                                         ";
		doHoa(12);
		cout << "|| " << endl;
		cout << "\t\t\t||--------------------------------------------------------------------------||" << endl;
		cout << "\t\t\t||  ";
		doHoa(14);
		cout << "==> 6.THOAT                                                             ";
		doHoa(12);
		cout << "||" << endl;
		cout << "\t\t\t||==========================================================================||" << endl;
		doHoa(10);
		cout << "\n\n\t\t\tChon menu : ";
		choice = luaChon();
		switch (choice) {
		case 1:
			menuQuanLiSach(x, k);
			break;
		case 2:
			menuUser(x, k);
			break;
		case 3:
			menuThongBaoThuVien(x, k);
			break;
		case 4:
			menuDocGopY(x, k);
			break;
		case 5:
			menuIntro();
			break;
		case 6:
			return;
			break;
		default:
			cout << "\tLua chon cua ban khong hop le ! vui long kiem tra va nhap lai ! " << endl;
			cout << "\t................................................................" << endl;
			mainMenu(x, k);
			break;
		};
	case 2:
		system("cls");
		doHoa(12);
		cout << "\n\n\n";
		cout << "\t\t\t   -------    ---       /\\     |\\   |    ---        ---  |    |  |    |" << endl;
		cout << "\t\t\t      |      |   \\     /  \\    | \\  |   /  __      /     |----|  |    |" << endl;
		cout << "\t\t\t      |      |---     /----\\   |  \\ |   \\   /      |     |    |  |    |" << endl;
		cout << "\t\t\t      |      |   \\   /      \\  |   \\|    ---       \\___  |    |   \\__/ " << endl;
		cout << endl;
		doHoa(14);
		cout << right << setw(64) << thoiGianHeThong() << endl;
		cout << endl;
		doHoa(10);
		cout << "\n\n\t\t" << "SACH LA NGUON CUA CAI QUY BAU CUA THE GIOI VA LA DI SAN CUA CAC THE HE VA CUA CAC QUOC GIA ." << endl;
		cout << right << setw(74) << "– Henry David Thoreau –" << endl;
		cout << endl;
		cout << endl << endl;
		doHoa(14);
		cout << "\n\n\t\t\t\t\t\t    @@ -----ADMIN----- @@" << endl;
		cout << "\t\t\t\t\t    -----------------------------------" << endl;
		cout << endl;
		doHoa(12);
		cout << "\t\t\t||==========================================================================||" << endl;
		cout << "\t\t\t|| ";
		doHoa(13);
		cout << left << setw(73) << "== > 1.Quan ly thong bao          ";
		doHoa(12);
		cout << "|| " << endl;
		cout << "\t\t\t||--------------------------------------------------------------------------||" << endl;
		cout << "\t\t\t||";
		doHoa(13);
		cout << left << setw(73) << " == > 2.Quan ly tai khoan ca nhan            ";
		doHoa(12);
		cout << " ||" << endl;
		cout << "\t\t\t||--------------------------------------------------------------------------||" << endl;
		cout << "\t\t\t|| ";
		doHoa(13);
		cout << left << setw(73) << "== > 3.Quan ly tai khoan va nguoi dung tren he thong           ";
		doHoa(12);
		cout << "|| " << endl;
		cout << "\t\t\t||--------------------------------------------------------------------------||" << endl;
		cout << "\t\t\t|| ";
		doHoa(13);
		cout << left << setw(73) << "== > 4.Hop thu gop y           ";
		doHoa(12);
		cout << "|| " << endl;
		cout << "\t\t\t||--------------------------------------------------------------------------||" << endl;
		cout << "\t\t\t|| ";
		doHoa(13);
		cout << left << setw(73) << "== > 5.Dang xuat           ";
		doHoa(12);
		cout << "|| " << endl;
		cout << "\t\t\t||--------------------------------------------------------------------------||" << endl;
		cout << "\t\t\t|| ";
		doHoa(13);
		cout << left << setw(73) << "== > 6.Thoat           ";
		doHoa(12);
		cout << "|| " << endl;
		cout << "\t\t\t||==========================================================================||" << endl;
		doHoa(14);
		cout << "\n\n \t\t Chon menu : ";
		choice = luaChon();
		switch (choice) {
		case 1:
			menuThongBaoThuVien(x, k);
			break;
		case 2:
			menuUser(x, k);
			break;
		case 3:
			menuManage(x, k);
			break;
		case 4:
			menuDocGopY(x, k);
			break;
		case 5:
			menuIntro();
			break;
		case 6:
			return;
			break;
		default:
			doHoa(15);
			cout << "\t\tLua chon cua ban khong hop le ! vui long kiem tra va nhap lai ! " << endl;
			cout << "\t\t................................................................" << endl;
			mainMenu(x, k);
			break;
		};
	};
};

// Menu tìm sách
void Menu::menuQuanLiSach(User x, int &k) {
	// xóa thông tin trong file lưu tạm
	ofstream ghi("luutam.txt", ios::trunc);

	system("cls");
	doHoa(12);
	cout << "================DANH SACH CHUC NANG================" << endl;
	cout << endl;
	ds = 0;
	doHoa(14);
	cout << "----------------------------------------------------------------------" << endl;
	cout << "|===> " << ds++ << ". QUAY LAI                                                    |" << endl;
	cout << "|===> " << ds++ << ". XEM CAC SACH HIEN CO                                        |" << endl;
	cout << "|===> " << ds++ << ". TIM SACH                                                    |" << endl;
	cout << "|===> " << ds++ << ". THEM SACH                                                   |" << endl;
	cout << "|===> " << ds++ << ". XAC NHAN CAC YEU CAU MUON SACH                              |" << endl;
	cout << "|===> " << ds++ << ". DANH SACH TRE HEN TRA SACH                                  |" << endl;
	cout << "----------------------------------------------------------------------" << endl;
	cout << endl;
	doHoa(12);
	cout << "===============MOI BAN CHON CHUC NANG===============" << endl;
	cout << endl;
	doHoa(15);
	cout << "\tLua chon cua ban la : ";
	choice = luaChon();
	switch (choice) {
	case 0:
		mainMenu(x, k);
		break;
	case 1:
		menuTatCaSach(x, k);
		break;
	case 2:
		menuTimSach(x, k);
		break;
	case 3:
		menuThemSach(x, k);
		break;
	case 4:
		menuYeuCauMuonSach(x, k);
		break;
	case 5:
		menuTreHenTraSach(x, k);
		break;
	default:
		cout << "\tLua chon cua ban khong hop le ! vui long kiem tra va nhap lai ! " << endl;
		cout << "\t................................................................" << endl;
		menuQuanLiSach(x, k);
		break;
	};
};

void Menu::menuTatCaSach(User x, int &k) {
	system("cls");
	Book b;
	doHoa(12);
	cout << "-------------------------------------------------------------------------------------------------" << endl;
	cout << "| STT |Ma so ID|        Ten sach         |    Tac gia    |  Gia tien thue  |  So luong con lai  |" << endl;
	cout << "-------------------------------------------------------------------------------------------------" << endl;
	doHoa(10);
	b.all();
	doHoa(12);
	cout << "-------------------------------------------------------------------------------------------------" << endl;
	system("pause");
	menuQuanLiSach(x, k);
};

void Menu::menuTimSach(User x, int &k) {
	system("cls");
	bool valid;
	string str;
	Book b;


	ds = 0;
	doHoa(10);
	cout << "\n\n\t\t-----------------------------------------------------------------" << endl;
	cout << "\t\t|===> " << ds++ << ". Quay lai                                              |" << endl;
	cout << "\t\t|===> " << ds++ << ". Ten sach                                              |" << endl;
	cout << "\t\t|===> " << ds++ << ". Ma so sach                                            |" << endl;
	cout << "\t\t|===> " << ds++ << ". Ten tac gia                                           |" << endl;
	cout << "\t\t-----------------------------------------------------------------" << endl;
	doHoa(14);
	cout << "\n\nBan muon tim kiem theo ?";
	choice = luaChon();
	system("cls");
	switch (choice) {
		// Quay lại
	case 0:
		mainMenu(x, k);
		break;
		// Tìm kiếm theo tên
	case 1:
		doHoa(15);
		cout << "Nhap vao ten sach : ";
		getline(cin, str);
		doHoa(12);
		cout << "======DANH SACH CAC SACH LIEN QUAN ======\n" << endl;
		doHoa(9);
		b.find(1, str, valid);
		break;
		// Tìm kiếm theo mã số sách
	case 2:
		doHoa(15);
		cout << "Nhap ma so sach : ";
		getline(cin, str);
		doHoa(12);
		cout << "======DANH SACH CAC SACH LIEN QUAN ======\n" << endl;
		doHoa(9);
		b.find(2, str, valid);
		break;
		// Tìm kiếm theo tác giả
	case 3:
		doHoa(15);
		cout << "Nhap ten tac gia : ";
		getline(cin, str);
		doHoa(12);
		cout << "======DANH SACH CAC SACH LIEN QUAN ======\n" << endl;
		doHoa(9);
		b.find(3, str, valid);
		break;
	default:
		doHoa(15);
		cout << "Lua chon khong hop le" << endl;
		mainMenu(x, k);
		break;
	};
	doHoa(15);
	if (valid == false) cout << "Khong tim thay sach tren trong thu vien !" << endl;
	cout << "\n===============================================" << endl;
	if (valid == true) {
		doHoa(15);
		cout << "Chon sach : ";
		choice = luaChon();
		b.layID(choice);
		system("cls");
		b.inThongTin();
		cout << endl;
		ds = 0;
		doHoa(10);
		cout << "-----------------------------------------------------------------" << endl;
		cout << "|===> " << ds++ << ". Quay lai                                              |" << endl;
		cout << "|===> " << ds++ << ". Gui yeu cau dang ki muon sach                         |" << endl;
		cout << "-----------------------------------------------------------------" << endl;
		choice = luaChon();
		switch (choice) {
		case 0:
			mainMenu(x, k);
			break;
		case 1:
			fstream f;
			f.open("muonSach.txt", ios_base::in | ios_base::out | ios_base::app);
			ThongTinMuonSach t(x.getID(), b.getID(), x.getHoTen(), b.getTenSach());
			t.luuThongTinMuonSach(f, t);
			doHoa(10);
			cout << "Yeu cau cua ban da duoc gui den thu thu !" << endl;
			system("pause");
			mainMenu(x, k);
			break;
		};
	}
	else {
		system("pause");
		menuTimSach(x, k);
	};
};

//Menu thêm sách ( tính năng của thủ thư )
void Menu::menuThemSach(User x, int &k) {
	system("cls");
	string str;
	Book b;
	doHoa(12);
	cout << "=========================== Nhap vao thong tin sach ==========================" << endl;
	doHoa(15);
	b.fill();
	system("cls");
	doHoa(12);
	cout << "==================== Ban dong y them sach nay vao thu vien ? =================" << endl;
	doHoa(10);
	b.inThongTin();
	doHoa(12);
	cout << "----------------------------------------------------------------------" << endl;
	cout << "| 1. Yes                                               2. No         |" << endl;
	cout << "----------------------------------------------------------------------" << endl;
	choice = luaChon();
	switch (choice) {
	case 1:
		b.add();
		doHoa(12);
		cout << "Da bo sung thong tin sach vao thu vien !" << endl;
		system("pause");
		mainMenu(x, k);
		break;
	case 2:
		mainMenu(x, k);
		break;
	default:
		doHoa(15);
		cout << "\tLua chon cua ban khong hop le ! vui long kiem tra va nhap lai ! " << endl;
		cout << "\t................................................................" << endl;
		menuQuanLiSach(x, k);
		break;
	};
};

// Menu các yêu cầu mượn sách
void Menu::menuYeuCauMuonSach(User x, int &k) {
	fstream f("muonSach.txt", ios_base::out | ios_base::app);
	ThongTinMuonSach t;
	vector < ThongTinMuonSach > ds;
	t.doc(ds);
	t.xacNhanMuonSach(f, ds);
	xoaFile("muonSach.txt");
	fstream ff("muonSach.txt", ios_base::out | ios_base::app);
	t.luuThongTin_last(ff, ds);
	system("pause");
	menuQuanLiSach(x, k);
};

// Menu danh sách người dùng trễ hẹn trả sách
void Menu::menuTreHenTraSach(User x, int &k) {
	fstream f("muonSach.txt", ios_base::out | ios_base::app);
	ThongTinMuonSach t;
	vector < ThongTinMuonSach > ds;
	t.doc(ds);
	t.danhSachTreHenTraSach(ds);
	system("pause");
	menuQuanLiSach(x, k);
};

// Menu quản lí tài khoản
void Menu::menuUser(User x, int &k) {
	system("cls");
	x.inUser();
	ds = 0;
	doHoa(14);
	cout << "----------------------------------------------------------------------" << endl;
	cout << "|===> " << ds++ << ". Quay lai                                                    |" << endl;
	cout << "|===> " << ds++ << ". Xem thong tin tai khoan                                     |" << endl;
	cout << "|===> " << ds++ << ". Doi mat khau                                                |" << endl;
	cout << "|===> " << ds++ << ". Xem tin nhan tu he thong                                    |" << endl;
	cout << "----------------------------------------------------------------------" << endl;
	doHoa(12);
	cout << "Chon chuc nang : ";
	choice = luaChon();
	switch (choice) {
	case 0:
		mainMenu(x, k);
		break;
	case 1:
		system("cls");
		doHoa(10);
		menuAccount(x, k);
		break;
	case 2:
		system("cls");
		doHoa(10);
		x.changePassWord();
		menuUser(x, k);
		break;
	case 3:
		break;
	default:
		doHoa(15);
		cout << "\tLua chon cua ban khong hop le ! vui long kiem tra va nhap lai ! " << endl;
		cout << "\t................................................................" << endl;
		menuUser(x, k);
		break;
	};
};

void Menu::menuAccount(User x, int &k) {
	system("cls");
	x.inAccount();
	ds = 0;
	doHoa(12);
	cout << ds++ << ". Quay lai" << endl;
	cout << ds++ << ". Chuyen tai khoan" << endl;
	cout << ds++ << ". Tao tai khoan" << endl;
	choice = luaChon();
	int g;
	switch (choice) {
	case 0:
		menuUser(x, k);
	case 1:
		doHoa(15);
		cout << "Chon tai khoan : " << endl;
		choice = luaChon();
		g = x.getIdent(choice);
		switch (choice) {
		case 1:
			doHoa(15);
			menuCho(x, g);
			break;
		case 2:
			doHoa(15);
			menuCho(x, g);
			break;
		case 3:
			doHoa(15);
			menuCho(x, g);
			break;
		default:
			doHoa(15);
			cout << "\tLua chon cua ban khong hop le ! vui long kiem tra va nhap lai ! " << endl;
			cout << "\t................................................................" << endl;
			menuAccount(x, k);
			break;
		};
	case 2:
		doHoa(15);
		x.taoTaiKhoan();
		x.ghi();
		doHoa(12);
		cout << "Dang nhap lai de tiep tuc !" << endl;
		system("pause");
		menuLogin();
		break;
	default:
		doHoa(15);
		cout << "\tLua chon cua ban khong hop le ! vui long kiem tra va nhap lai ! " << endl;
		cout << "\t................................................................" << endl;
		menuAccount(x, k);
		break;
	};
};

// Quản lí tài khoản và người dùng trên hệ thông ( tính năng của admin )
void Menu::menuManage(User x, int &k) {
	// xóa thông tin trong file lưu tạm
	ofstream ghi("luutam.txt", ios::trunc);

	system("cls");
	doHoa(12);
	cout << "\n\n\tHe thong hien dang co : " << x.tinhSoLuong() << " thanh vien da dang ky" << endl;
	ds = 0;
	doHoa(10);
	cout << "----------------------------------------------------------------------" << endl;
	cout << "|===> " << ds++ << ". Quay lai                                                    |" << endl;
	cout << "|===> " << ds++ << ". Tim User                                                    |" << endl;
	cout << "|===> " << ds++ << ". Danh sach cac nguoi dung hien tai                           |" << endl;
	cout << "----------------------------------------------------------------------" << endl;
	doHoa(12);
	cout << "Chon chuc nang : ";
	choice = luaChon();
	switch (choice) {
	case 0:
		mainMenu(x, k);
		break;
	case 1:
		menuTimUser(x, k);
		break;
	case 2:
		doHoa(15);
		menuTatCaUser(x, k);
		break;
	case 3:
		break;
	default:
		doHoa(15);
		cout << "\tLua chon cua ban khong hop le ! vui long kiem tra va nhap lai ! " << endl;
		cout << "\t................................................................" << endl;
		menuAccount(x, k);
		break;
	};
};

// Menu tìm User
void Menu::menuTimUser(User x, int &k) {
	system("cls");
	// trả về false khi không có kết quả tìm kiếm nào
	bool valid;

	doHoa(14);
	ds = 0;
	cout << "\n\n\n-----------------------------------------------------------------" << endl;
	cout << "|===> " << ds++ << ". Quay lai                                              |" << endl;
	cout << "|===> " << ds++ << ". Ten nguoi dung                                        |" << endl;
	cout << "|===> " << ds++ << ". Ma so ID                                              |" << endl;
	cout << "|===> " << ds++ << ". So CMND                                               |" << endl;
	cout << "-----------------------------------------------------------------\n\n" << endl;
	doHoa(15);
	cout << "Tim kiem theo ?" << endl;
	choice = luaChon();
	switch (choice) {
		// Quay lại
	case 0:
		menuManage(x, k);
		break;
		// Tìm kiếm theo tên
	case 1:
		doHoa(15);
		cout << "Nhap vao ten nguoi dung : ";
		getline(cin, str);
		doHoa(12);
		cout << "======DANH SACH CAC USER LIEN QUAN ======\n" << endl;
		cout << "-------------------------------------------------------------------------------------------------" << endl;
		cout << "| STT |Ma so ID|        Ho va ten        |    So CMND    |  So dien thoai  |    Ngay dang ki    |" << endl;
		cout << "-------------------------------------------------------------------------------------------------" << endl;
		doHoa(10);
		x.find(1, str, valid);
		break;
		// Tìm kiếm theo mã ID
	case 2:
		doHoa(15);
		cout << "Nhap ma so ID : ";
		getline(cin, str);
		doHoa(12);
		cout << "======DANH SACH CAC USER LIEN QUAN ======\n" << endl;
		cout << "-------------------------------------------------------------------------------------------------" << endl;
		cout << "| STT |Ma so ID|        Ho va ten        |    So CMND    |  So dien thoai  |    Ngay dang ki    |" << endl;
		cout << "-------------------------------------------------------------------------------------------------" << endl;
		doHoa(10);
		x.find(2, str, valid);
		break;
		// Tìm kiếm theo số CMND
	case 3:
		doHoa(15);
		cout << "Nhap so CMND : ";
		getline(cin, str);
		doHoa(12);
		cout << "======DANH SACH CAC USER LIEN QUAN ======\n" << endl;
		cout << "-------------------------------------------------------------------------------------------------" << endl;
		cout << "| STT |Ma so ID|        Ho va ten        |    So CMND    |  So dien thoai  |    Ngay dang ki    |" << endl;
		cout << "-------------------------------------------------------------------------------------------------" << endl;
		doHoa(10);
		x.find(3, str, valid);
		break;
	default:
		doHoa(15);
		cout << "Lua chon khong hop le" << endl;
		menuManage(x, k);
		break;
	};
	doHoa(15);
	if (valid == false) cout << "Khong tim thay thong tin User tren trong thu vien !" << endl;
	cout << "\n===============================================" << endl;
	if (valid == true) {
		cout << "Chon User : ";
		choice = luaChon();
		x.layID(choice);
		system("cls");
		x.inUser();
		cout << endl;
		ds = 0;
		doHoa(14);
		cout << "-----------------------------------------------------------------" << endl;
		cout << "|===> " << ds++ << ". Quay lai                                              |" << endl;
		cout << "|===> " << ds++ << ". Chinh sua thong tin User                              |" << endl;
		cout << "|===> " << ds++ << ". Xoa User                                              |" << endl;
		cout << "-----------------------------------------------------------------" << endl;
		doHoa(15);
		cout << "Nhap lua chon : ";
		choice = luaChon();
		switch (choice) {
		case 0:
			mainMenu(x, k);
			break;
		case 1:
			menuSuaThongTinUser(x, k);
			break;
		case 2:
			doHoa(12);
			cout << "Dong y khoa nguoi dung nay ?" << endl;
			cout << "1. Yes               2. No" << endl;
			choice = luaChon();
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
			mainMenu(x, k);
		};
	}
	else {
		system("pause");
		menuTimUser(x, k);
	};
};

//Menu tất cả User
void Menu::menuTatCaUser(User x, int &k) {
	system("cls");
	doHoa(12);
	cout << "-------------------------------------------------------------------------------------------------" << endl;
	cout << "| STT |Ma so ID|        Ho va ten        |    So CMND    |  So dien thoai  |    Ngay dang ki    |" << endl;
	cout << "-------------------------------------------------------------------------------------------------" << endl;
	doHoa(10);
	x.all();
	doHoa(12);
	cout << "-------------------------------------------------------------------------------------------------" << endl;
	system("pause");
	mainMenu(x, k);
};

void Menu::menuSuaThongTinUser(User x, int &k) {
	doHoa(15);
	system("cls");
	x.inUser();
	cout << "Nhap thong tin muon chinh sua : ";
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
	doHoa(12);
	cout << "Ban dong y chinh sua thong tin nay ?" << endl;
	cout << "1. Yes                         2. No" << endl;
	choice = luaChon();
	User u(x);
	switch (choice) {
	case 1:
		x.xoaUser(x.getID());
		x.ghi();
		cout << "Da chinh sua thong tin" << endl;
		break;
	case 2:
		break;
	};
	system("pause");
	mainMenu(x, k);
};

//Menu thông báo thư viện
void Menu::menuThongBaoThuVien(User x, int &k) {
	do {
		system("cls");
		ThongBaoThuVien data[Max_Anouce];
		string str[Max_Anouce];
		doHoa(12);
		cout << "TAT CA THONG BAO :" << endl;
		doHoa(15);
		fstream f;
		f.open("thongbao.txt", ios::in);
		int line = 0;
		int soDong;
		while (!f.eof()) {
			string x;
			fflush(stdin);
			getline(f, x);
			if (x == "") continue;
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

		ds = 0;
		doHoa(14);
		cout << "-----------------" << endl;
		cout << "| Menu thong bao | " << endl;
		cout << "-----------------" << endl;
		cout << "\t" << ds++ << ". Quay lai" << endl;
		cout << "\t" << ds++ << ". Them thong bao" << endl;
		cout << "\t" << ds++ << ". Chinh sua thong bao" << endl;
		cout << "\t" << ds++ << ". Xoa thong bao" << endl;
		cout << "\t" << ds++ << ". Doc noi dung thong bao" << endl;
		cout << "\t" << "***********************" << endl;
		doHoa(15);
		cout << "\t" << "Nhap lua chon cua ban: ";
		choice = luaChon();

		ThongBaoThuVien tb;
		switch (choice) {
		case 0:
			mainMenu(x, k);
			break;
		case 1:
			tb.themThongBao();
			menuThongBaoThuVien(x, k);
			break;
		case 2:
			tb.suaThongBao(data, soDong);
			menuThongBaoThuVien(x, k);
			break;
		case 3:
			tb.xoaThongBao(data, soDong);
			menuThongBaoThuVien(x, k);
			break;
		case 4:
			tb.docThongBao(data);
			system("pause");
			menuThongBaoThuVien(x, k);
			break;
		default:
			cout << "Moi ban nhap lai";
			choice = luaChon();
			break;
		};
	} while (choice != 4);
};

void Menu::menuComment(User x, int &k) {
	system("cls");
	Comment c(x.getHoTen());
	doHoa(14);
	cout << "\t  --------------------" << endl;
	cout << "\t  | CHUYEN MUC GOP Y |" << endl;
	cout << "\t  --------------------" << endl << endl;
	doHoa(15);
	cout << "Nhap y kien cua ban ve thu vien cua chung toi: ";
	getline(cin, str);
	c.setComment(str);
	c.ghi();
	cout << "Y kien cua ban da duoc gui den quan ly cua thu vien." << endl;
	cout << "Chan thanh cam on gop y cua ban, chung toi se co gang khac phuc." << endl;
	cout << "Bam Enter de tiep tuc " << endl;
	system("pause");
	mainMenu(x, k);
};

void Menu::menuDocGopY(User x, int &k) {
	system("cls");
	string s[1000];
	Comment c;
	int line = 0;
	c.docGopY(s, line);
	doHoa(14);
	cout << "------------------------------" << endl;
	cout << "|1. Doc nhung gop y moi nhat.| " << endl;
	cout << "|2. Doc toan bo gop y.       | " << endl;
	cout << "------------------------------" << endl;
	doHoa(15);
	cout << "Moi ban nhap: ";
	choice = luaChon();
	while (choice != 1 && choice != 2) {
		cout << "Moi ban nhap lai: ";
		choice = luaChon();
	};
	switch (choice) {
	case 1:
		doHoa(12);
		cout << "Danh sach cac gop y duoc gui den thu vien: " << endl;
		doHoa(15);
		if (line < 5) {
			for (int i = 0; i < line - 1; i++) cout << "\t" << i + 1 << ". " << s[i] << endl;
		}
		else {
			doHoa(15);
			int t = 1;
			for (int i = line - 6; i < line - 1; i++) cout << "\t" << t++ << ". " << s[i] << endl;
		};
		system("pause");
		break;
	case 2:
		doHoa(12);
		cout << "Danh sach cac gop y duoc gui den thu vien: " << endl;
		doHoa(15);
		for (int i = 0; i < line - 1; i++) cout << "\t" << i + 1 << ". " << s[i] << endl;
		system("pause");
		break;
	};
	mainMenu(x, k);
};

