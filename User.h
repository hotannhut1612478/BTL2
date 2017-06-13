#pragma once
#include <string>
class User{
	// Mã số tài khoản
	int m_id = 0;
	// Họ và tên
	char m_hoTen[40] = "";
	// Tên đăng nhập
	char m_nameLogin[20] = "";
	// Mật khẩu
	char m_passWord[20] = "";
	// Nghề Nghiệp
	char m_job[30] = "";
	// Địa chỉ
	char m_address[40] = "";
	// Số điện thoại
	char m_sdt[14] = {};
	// chứng minh nhân dân
	char m_cmnd[14] = {};
	// Mã định danh
	int m_ident;
	// Tình trạng hoạt động
	bool m_active = true;
public:
	User();
	~User();
public:
	void subscription();
	void ghi();
	void doc();
	void inThongTin();
	void changePassWord();
	std::string nhapMatKhau();
	int soSanh(std::string, std::string);
	std::string getName();
private:
	std::string xoaKTTrongChuoi(std::string, int);
	std::string xoaKhoangTrong(std::string);
	bool chu(std::string);
	bool leng(std::string, std::string);
	bool kiTuDacBiet(std::string, std::string);
	bool number(std::string);
	int soLuong();
};

