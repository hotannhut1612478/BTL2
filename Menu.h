#pragma once
#include "User.h"
#include <string>
class Menu{
public:
	Menu();
	~Menu();
public:
	void menuIntro(User);
	void menuLogin(User);
	void menuRegister(User);
	void menuProvisions(User);
	void mainMenu(User);
	void menuTimSach(User);
	void menuAccount(User);
private:
};

