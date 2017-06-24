#include <iostream>
#include "User.h"
#include "Book.h"
#include "Menu.h"
#include "thoiGian.h"
#include "Complex.h"

using namespace std;

int main() {
	User x;
	x.xoaUser(1);
	Menu menu;
	//menu.menuRegister(true, true);
	menu.menuIntro();

	system("pause");
}