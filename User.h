#pragma once
#include <string>
class User{
protected:
	// Mã số user
	int m_id = 0;
	// Họ và tên
	char m_hoTen[40] = "";
	// Nghề Nghiệp
	char m_job[30] = "";
	// Địa chỉ
	char m_address[40] = "";
	// Số điện thoại
	char m_sdt[14] = {};
	// chứng minh nhân dân
	char m_cmnd[14] = {};
	// Tình trạng hoạt động
	bool m_active = true;
	// Ngày đăng kí
	int m_time[6] = {};
public:
	User();
	~User();
public:
	void subscription();
	void ghi();
	void doc();
	friend std::ostream &operator<< (std::ostream &, User &);
	int getID();
	void find(int, std::string, bool &);
	void layID(int);
	void khoaUser();
	int getIdent();
	std::string getHoTen();
	std::string getJob();
	std::string getAddress();
	std::string getSDT();
	std::string getCMND();
	int *getTime();
	void setJob(std::string);
	void setAddress(std::string);
	void setSDT(std::string);
	int tinhSoLuong();
	std::string thoiGianDangKi();
private:
	void setTime();
	void luuTamThoi();
	void thongTinTimKiem(int &);
};