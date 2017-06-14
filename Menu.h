#pragma once
#include "User.h"
#include "Book.h"
#include <string>
class Menu{
public:
	Menu();
	~Menu();
private:
	int ds = 1;
public:
	void menuIntro(User);
	void menuLogin(User);
	void menuRegister(User);
	void menuProvisions(User);
	void mainMenu(User);
	void menuQuanLiSach(User);
	void menuTimSach(User);
	void menuThemSach(User);
	void menuAccount(User);
	void menuThongBaoThuVien(User);
private:
};

