#include "ThongBaoThuVien.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <math.h>
using namespace std;

ThongBaoThuVien::ThongBaoThuVien() {
}
ThongBaoThuVien::~ThongBaoThuVien() {
}

void ThongBaoThuVien::docThongBao(ThongBaoThuVien data[Max_Anouce]) {
	cout << "Chon thong bao ban muon doc : ";
	int n;
	cin >> n;
	system("cls");
	cout << setw(center) << data[n - 1].tieuDe << endl;
	cout << data[n - 1].noiDung << endl;
};

void ThongBaoThuVien::themThongBao() {
	fstream f;
	f.open("thongbao.txt", ios::out | ios::app);
	string data1, data2;
	cout << "Moi ban nhap vao tieu de: ";
	getline(cin, data1);
	f << data1 << endl;
	cout << "Moi ban nhap vao noi dung: ";
	getline(cin, data2);
	f << data2 << endl;
	f.close();
	cout << "*****Da them.*****" << endl;
}

void ThongBaoThuVien::suaThongBao(ThongBaoThuVien thongbao[Max_Anouce], int k) {
	int set1, set2;
	fstream f;
	string data1, data2;
	cout << "Hay chon thong bao can sua: ";
	cin >> set1;
	cout << "\n Ban muon sua thong bao nay: ";
	cout << thongbao[set1 - 1].tieuDe << endl;
	cout << thongbao[set1 - 1].noiDung << endl;
	cout << "***1.Yes***   ***2.No*** \n";
	cin >> set2;
	switch (set2) {
	case 1:
		cin.ignore(1);
		cout << "Moi ban nhap tieu de  moi: ";
		getline(cin, data1);
		thongbao[set1 - 1].tieuDe = data1;
		cout << "Moi ban nhap noi dung  moi: ";
		getline(cin, data2);
		thongbao[set1 - 1].noiDung = data2;
		f.open("thongbao.txt", ios::out);
		for (int i = 0; i < k; i++){
			f << thongbao[i].tieuDe + "\n";
			f << thongbao[i].noiDung + "\n";
		};
		f.close();
		cout << "*****Da thay doi.*****" << endl;
		break;
	case 2:
		cout << "Tro ve menu.";
		break;
	default:
		cout << "Moi ban nhap lai";
		break;
	};
}

void ThongBaoThuVien::xoaThongBao(ThongBaoThuVien thongbao[Max_Anouce], int k) {
	ifstream docTenSach;
	ofstream ghiTenSach;
	int set1, set2;
	cout << "Chon thong bao can xoa: ";
	cin >> set1;
	cout << "Ban muon xoa thong bao nay: ";
	cout << thongbao[set1 - 1].tieuDe << endl;
	cout << thongbao[set1 - 1].noiDung << endl;
	cout << "***1.Yes***   ***2.No*** \n";
	cin >> set2;
	switch (set2) {
	case 1:
		ghiTenSach.open("thongbao.txt", ios_base::out);
		for (int i = 0; i < k; i++) {
			if (i != set1 - 1) {
				ghiTenSach << thongbao[i].tieuDe + "\n";
				ghiTenSach << thongbao[i].noiDung + "\n";
			}
		}
		ghiTenSach.close();

		break;
	case 2:
		cout << "Tro ve menu.";
		break;
	default:
		cout << "Moi ban nhap lai";
		break;
	};
};
