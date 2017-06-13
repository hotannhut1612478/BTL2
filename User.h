#pragma once
#include <string>
class User{
	//số lượng Users
	int static soLuong;
	// mã số tài khoản
	int m_id = 0;
	// tên đăng nhập
	char m_nameLogin[20] = "";
	// mật khẩu
	char m_passWord[20] = "";
	// họ và tên
	char m_hoTen[40] = "";
	// số điện thoại
	char m_sdt[14] = {};
	// chứng minh nhân dân
	char m_cmnd[14] = {};
	// mã định danh
	int m_ident;
	// tình trạng hoạt động
	bool m_active = true;
public:
	User();
	~User();
public:
	bool checkPass(char[], char[]);
	void subscription();
	void ghi();
	void doc();
	void inThongTin();
	void changePassWord();
	std::string nhapMatKhau();
private:
	std::string xoaKTTrongChuoi(std::string, int);
	std::string xoaKhoangTrong(std::string);
	bool chu(char []);
	bool number(char[]);
	bool leng(char[], std::string);
	bool kiTuDacBiet(char[], std::string);
		
};

