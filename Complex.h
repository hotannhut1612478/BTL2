#pragma once
#include <iostream>
#include <string>
#include "thoiGian.h"

int soSanh(std::string, std::string);
bool number(std::string);
bool kiTuDacBiet(std::string, std::string);
bool leng(std::string, std::string);
bool chu(std::string);
std::string xoaKhoangTrong(std::string);
std::string xoaKTTrongChuoi(std::string, int);
std::string epKieuIntSangString(int);
std::string thoiGianHeThong();
std::string nhapKiTuAn();
std::string maHoa(std::string matKhau);
long chenhLechNgay(ThoiGian, ThoiGian);
void xoaFile(std::string);
int luaChon();
void doHoa(int);