#pragma once
#include <string>
class ThoiGian{
public:
	ThoiGian();
	ThoiGian(int, int, int);
	~ThoiGian();
public:
	int ngay;
	int thang;
	int nam;
	int gio;
	int phut;
	int giay;
	std::string str();
	void setTimeNow();
	void setTime(std::string);
	long tinhNgay();
};

