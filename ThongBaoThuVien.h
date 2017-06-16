#pragma once
#include <string>

#define Max_Anouce 100
#define center 60
class ThongBaoThuVien{
public:
	ThongBaoThuVien();
	~ThongBaoThuVien();
public:
	std::string tieuDe;
	std::string noiDung;
public:
	int menuThongBao();
	void docThongBao(ThongBaoThuVien data[Max_Anouce]);
	void themThongBao();
	void suaThongBao(ThongBaoThuVien thongbao[Max_Anouce], int k);
	void xoaThongBao(ThongBaoThuVien thongbao[Max_Anouce], int k);
};

