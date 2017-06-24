#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "thoiGian.h"
#define Max_thong_bao 100
class ThongTinMuonSach{
public:
	ThongTinMuonSach();
	ThongTinMuonSach(int, int, std::string, std::string);
	~ThongTinMuonSach();
private:
	int m_ID_User;
	int m_ID_Book;
	std::string m_tenUser;
	std::string m_tenSach;
	ThoiGian m_time;
	std::string m_xacNhan;
	std::string m_traSach;
public:
	void luuThongTinMuonSach(std::fstream &, ThongTinMuonSach);
	void doc(std::vector < ThongTinMuonSach > &ds);
	void xacNhanMuonSach(std::fstream &f, std::vector< ThongTinMuonSach > &ds);
	void xuatDanhSachDangMuonSach(std::vector< ThongTinMuonSach > &ds);
	void danhSachTreHenTraSach(std::vector< ThongTinMuonSach > &ds);
	void xacNhanTraSach(std::fstream &f, std::vector< ThongTinMuonSach > &ds);
	void luuThongTin_last(std::fstream &f, std::vector< ThongTinMuonSach > &ds);
	void guiThongBao(std::vector< ThongTinMuonSach > &ds, int Id);
	// vào ra thông tin
	void setIDUser(std::string);
	void setIDBook(std::string );
	void setTenUser(std::string);
	void setTenBook(std::string);
	void setXacNhan(std::string);
	void setTraSach(std::string);
	void xuat(ThongTinMuonSach thongTin, int);
	int getIDUser();
	int getIDBook();
	std::string getTenUser();
	std::string getTenSach();
	int getNgay();
	int getThang();
	int getNam();
	std::string getXacNhan();
	std::string getTraSach();
};
