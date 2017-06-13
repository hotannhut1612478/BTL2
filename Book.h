﻿#pragma once
#include <string>
class Book{
public:
	Book();
	~Book();
private:
	// ID
	long m_id = 0;
	// Mã số sách
	int m_ISBN = -1;
	// Tên sách
	char m_name[64] = "";
	// Ngày phát hành
	int m_date[3] = { -1, -1, -1 };
	// Nhà xuất bản
	char m_publisher[64] = "";
	// Tác giả
	char m_author[64] = "";
	// Giá thuê
	long m_rentCost = -1;
	// Giá gốc
	long m_cost = -1;
	// Mô tả - giới thiệu
	char m_describe[500] = "";
public:
	void find(int, std::string);
	void inThongTin();
	void fill();
	void add();
	void autoAdd();
private:
	bool soSanh(std::string, std::string);
	int soLuong();

};
