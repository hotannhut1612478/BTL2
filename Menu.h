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
	void menuAccount(User);
private:
	Book *danhSachTimKiem(Book b, int i);
};

