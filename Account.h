#pragma once
#include "User.h"
class Account : public User{
public:
	Account();
	~Account();
private:
	// Tên đăng nhập
	char m_nameLogin[20] = "";
	// Mật khẩu
	char m_passWord[20] = "";
	// Mã định danh
	int m_ident;
public:
	void taoTaiKhoan();
	void changePassWord();
	std::string nhapMatKhau();
	int checkLogin(std::string, std::string);
	void docGia();
	void thuThu();
	void admin();
	std::string getNameLogin();
	std::string getPassword();
	int getIdent();
};

