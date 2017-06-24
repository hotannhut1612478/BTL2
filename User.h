#pragma once
#include <string>
#include "ThoiGian.h"

class User {
	// Mã số tài khoản
	int m_id = 0;
	// Họ và tên
	char m_hoTen[40] = ".";
	// Tên đăng nhập - mật khẩu
	char m_nameLogin0[20] = ".";
	char m_passWord0[20] = ".";
	int m_ident0 = 0;
	char m_nameLogin1[20] = ".";
	char m_passWord1[20] = ".";
	int m_ident1 = 0;
	char m_nameLogin2[20] = ".";
	char m_passWord2[20] = ".";
	int m_ident2 = 0;
	// Nghề Nghiệp
	char m_job[30] = ".";
	// Địa chỉ
	char m_address[40] = ".";
	// Số điện thoại
	char m_sdt[14] = ".";
	// chứng minh nhân dân
	char m_cmnd[14] = ".";
	// Tình trạng hoạt động
	bool m_active = true;
	// Vai trò
	bool m_roleThuThu = false;
	bool m_roleAdmin = false;
	// Ngày đăng kí
	ThoiGian m_time;
public:
	User();
	~User();
public:
	void subscription();
	void ghi();
	void doc();
	void inUser();
	void inAccount();
	void changePassWord();
	int checkLogin(std::string, std::string, User &, int &);
	void find(int, std::string, bool &);
	void layID(int);
	// vào ra dữ liệu
	void taoTaiKhoan();
	void setJob(std::string);
	void setAddress(std::string);
	void setSDT(std::string);
	void setThuThu();
	void setAdmin();
	void khoaUser();
	void xoaUser(int);
	void all();
	int getID();
	std::string getHoTen();
	std::string getCMND();
	bool isThuThu();
	bool isAdmin();
	int getIdent(int );
	int tinhSoLuong();
private:
	int soTrungKhop(std::string, std::string, int &);
	void luuTamThoi();
	void thongTinTimKiem(int &);
};

