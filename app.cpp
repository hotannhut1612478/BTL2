#include <iostream>
#include "User.h"
#include "Book.h"
#include "Menu.h"

using namespace std;

int main() {
	User user;
	Menu menu;
	menu.menuIntro(user);

	system("pause");
}