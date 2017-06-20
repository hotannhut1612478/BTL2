#pragma once
#include "User.h"
#include "Book.h"
#include "Account.h"
#include <string>
class Menu{
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
	void menuIntro(Account);
	void menuLogin(Account);
	void menuRegister(Account, int = 0);
	void menuProvisions(Account);
	void mainMenu(Account);
	void menuQuanLiSach(Account);
	void menuTimSach(Account);
	void menuThemSach(Account);
	void menuUser(Account);
	void menuAccount(Account);
	void menuManage(Account);
	void menuTimUser(Account);
	void menuSuaThongTinUser(Account);
	void menuThongBaoThuVien(Account);
	void menuComment(Account);
private:
	std::string thoiGianHeThong();
};

