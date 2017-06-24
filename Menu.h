#pragma once
#include "User.h"
#include "Book.h"
#include <string>
class Menu {
public:
	Menu();
	~Menu();
private:
	// Đánh số thứ tự cho menu
	int ds = 1;
	std::string str;
	// biến lưu giá trị lựa chọn menu
	int choice;
public:
	void menuIntro();
	void menuLogin();
	void menuCho(User x, int &);
	void menuRegister(bool = false, bool = false);
	void menuProvisions();
	void mainMenu(User, int &);
	void menuQuanLiSach(User,int &);
	void menuTatCaSach(User,int &);
	void menuTimSach(User,int &);
	void menuThemSach(User,int &);
	void menuYeuCauMuonSach(User,int &);
	void menuTreHenTraSach(User, int &);
	void menuUser(User,int &);
	void menuAccount(User,int &);
	void menuManage(User,int &);
	void menuTimUser(User,int &);
	void menuTatCaUser(User,int &);
	void menuSuaThongTinUser(User,int &);
	void menuThongBaoThuVien(User,int &);
	void menuComment(User,int &);
	void menuDocGopY(User,int &);
private:
};

