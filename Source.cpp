#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include <string.h>
#include<Windows.h>

#define Max 1000
using namespace std;

int timSach();

// cac ham them vao: phien ban cap nhat 2.0
//1. Ham doi chu hoa thanh chu thuong;
void doiSangChuThuong(string &S) {
	char s[100] = "";
	for (int i = 0; S[i] != '\0'; i++) {
		s[i] = S[i];
	};
	_strlwr_s(s);
	S = s;
}
//2.

int timKiem() {
	string ten;

	cout << "nhap vao ten sach : ";
	fflush(stdin);
	getline(cin, ten);
	//===========
	// đổi mang in hoa sang mảng thường;

	doiSangChuThuong(ten);

	//=============
	string x, X[50];
	int dem = 0;
	stringstream SS(ten);
	while (SS >> x) {
		X[dem] = x;
		dem++;
	}
	// ket thuc tach chuoi con;

	int soDong = 0;
	ifstream docTenSach;
	string tenSach[Max];
	docTenSach.open("tenSachFile.txt", ios_base::in);
	while (!docTenSach.eof()) {
		string x;
		fflush(stdin);
		while (getline(docTenSach, x)) {
			tenSach[soDong] = x;
			soDong++;
			fflush(stdin);
		}
	}
	// de lay duoc so ten sach;
	int uuTien[Max];// tạo 1 mảng chứa các số là số điểm ưu tiên ;
	for (int i = 0; i < soDong; i++) {
		uuTien[i] = 0;
	}
	// so sánh ten trong du liệu của file với tên người dùng nhập vào
	for (int d = 0; d < soDong; d++) {
		string st;
		string tenSachCon[50];
		int demDem = 0;
		stringstream sst(tenSach[d]);
		while (sst >> st) {
			tenSachCon[demDem] = st;
			demDem++;
		}
		for (int i = 0; i < demDem; i++) {
			for (int j = 0; j < dem; j++) {
				if (tenSachCon[i] == X[j]) {
					uuTien[d]++;
					// nếu trùng nhau thì tăng độ ưu tiên lên 1;
				}
			}
		}
	}
	// sắp xếp lại mảng tenSach..theo chế độ ưu tiên giảm dần ..để in ra những tên sách phù hợp nhất cho người dùng...


	for (int i = 0; i < soDong - 1; i++)
	{
		for (int j = i + 1; j < soDong; j++)
		{
			if (uuTien[i] <= uuTien[j])
			{
				int tempi = uuTien[i];
				uuTien[i] = uuTien[j];
				uuTien[j] = tempi;
				string temp = tenSach[i];
				tenSach[i] = tenSach[j];
				tenSach[j] = temp;
			}
		}
	}

	// In ra ten sach
	int dieuKien = 0;
	for (int i = 0; i < 15; i++) {
		if (uuTien[i] > 0) dieuKien++;
	}

	if (dieuKien > 0) {
		cout << "======DANH SACH CAC SACH LIEN QUAN ======" << endl;

		for (int i = 0; i < dieuKien; i++) {
			cout << "\t" << i << ". " << tenSach[i] << endl;
		}
		cout << "\t" << dieuKien << ". " << "Nhap lai ten sach " << endl;
		cout << "=========================================" << endl;
		cout << "\t\t***" << endl;
		cout << "\t\t***" << endl;
		cout << "\t\t***" << endl;
		cout << "\t\t***" << endl;
		cout << "=========MOI BAN CHON SACH=========" << endl;
		int chon;

		// OK!
		cout << "\n\n\n\tNHAP LUA CHON CUA BAN: ";
		cin >> chon;
		while (chon<0 || chon>dieuKien) {
			cin.clear();
			cin.ignore(10, '\n');
			cout << "\tlua chon cua ban khong hop le ! vui long kiem tra va nhap lai ! " << endl;
			cout << "\t................................................................" << endl;
			cin >> chon;
		}

		// OK!


		for (int i = 0; i < dieuKien; i++) {
			if (chon == i) {
				cout << "\n\tSach ban da chon la: " << endl;
				cout << "\t______________________________________________________" << endl;
				cout << "\t\t" << tenSach[i] << endl;
				cout << "\t______________________________________________________" << endl;
			}
		}
		if (chon == dieuKien) {
			cin.ignore();
			timKiem();
		}
	}
	else {// dieu kien =0---> khong co sach;
		cout << "\t! KHONG CO SACH MA BAN TIM !: " << endl;
		cout << "\t.............................." << endl;
		cout << "\tBAN HAY NHAP LAI TEN SACH HOAC THOAT: " << endl;
		cout << "\t......................................" << endl;
		cout << "\n\t0.Thoat" << endl;
		cout << "\t......." << endl;
		cout << "\n\t1.Nhap lai ten sach" << endl;
		cout << "\t..................." << endl;
		int chonTiep;
		cout << "\n\n\n\tNHAP LUA CHON CUA BAN: " << endl;
		cout << "\t_____________________" << endl;
		cout << "\n\tlua chon : ";
		cin >> chonTiep;
		while (chonTiep<0 || chonTiep>1) {
			cin.clear();
			cin.ignore(10,'\n');
			cout << "\tlua chon cua ban khong hop le ! vui long kiem tra va nhap lai ! " << endl;
			cout << "\t................................................................" << endl;
			cin >> chonTiep;
		}

		// OK!
		if (chonTiep == 1) {
			cin.ignore();
			timKiem();
		}
		else {
			return 0;
		}
		return 0;
	}

	cout << "\n\n\n";
	cout << "NHAN ENTER ĐE TIEP TUC !" << endl;
	docTenSach.close();
	system("pause");
	return 0;
}


int timSach() {
	int chucNang;
	do {
		system("cls");
		cout << "================DANH SACH CHUC NANG================\n" << endl;
		cout << "0.TIM SACH" << endl;
		cout << "1.TIM THEM SACH" << endl;
		cout << "2.THOAT\n" << endl;
		cout << "===============MOI BAN CHON CHUC NANG===============\n" << endl;
		cout << "\tlua chon cua ban la: ";
		cin >> chucNang;
		cin.ignore();
		while (chucNang < 0 || chucNang>2) {
			cin.clear();
			cin.ignore(10,'\n');
			cout << "\tlua chon cua ban khong hop le ! vui long kiem tra va nhap lai ! " << endl;
			cout << "\t................................................................" << endl;
			cin >> chucNang;
		}
		switch (chucNang) {
		case 0:
			timKiem();
			break;
		case 1:
			timKiem();
			break;
		case 2:
			return 0;
			break;
		default:
			break;
		}
	} while (chucNang != 2);

	return 0;
}
//OK OK OK OK OK OK !!!!!!

int xoa() {
	string ten;
	int m = 0;

	cout << "nhap vao ten sach ban muon xoa : ";

	fflush(stdin);
	getline(cin, ten);

	doiSangChuThuong(ten);
	//=============
	string x, X[50];
	int dem = 0;
	stringstream SS(ten);
	while (SS >> x) {
		X[dem] = x;
		dem++;
	}
	// ket thuc tach chuoi con;

	int soDong = 0;
	ifstream docTenSach;
	string tenSach[Max];
	docTenSach.open("tenSachFile.txt", ios_base::in);
	while (!docTenSach.eof()) {
		string x;
		fflush(stdin);
		while (getline(docTenSach, x)) {
			tenSach[soDong] = x;
			soDong++;
			fflush(stdin);
		}
	}
	// de lay duoc so ten sach;
	int uuTien[Max];// tạo 1 mảng chứa các số là số điểm ưu tiên ;
	for (int i = 0; i < soDong; i++) {
		uuTien[i] = 0;
	}
	// so sánh ten trong du liệu của file với tên người dùng nhập vào
	for (int d = 0; d < soDong; d++) {
		string st;
		string tenSachCon[50];
		int demDem = 0;
		stringstream sst(tenSach[d]);
		while (sst >> st) {
			tenSachCon[demDem] = st;
			demDem++;
		}
		for (int i = 0; i < demDem; i++) {
			for (int j = 0; j < dem; j++) {
				if (tenSachCon[i] == X[j]) {
					uuTien[d]++;
					// nếu trùng nhau thì tăng độ ưu tiên lên 1;
				}
			}
		}
	}
	// sắp xếp lại mảng tenSach..theo chế độ ưu tiên giảm dần ..để in ra những tên sách phù hợp nhất cho người dùng...


	for (int i = 0; i < soDong - 1; i++)
	{
		for (int j = i + 1; j < soDong; j++)
		{
			if (uuTien[i] <= uuTien[j])
			{
				int tempi = uuTien[i];
				uuTien[i] = uuTien[j];
				uuTien[j] = tempi;
				string temp = tenSach[i];
				tenSach[i] = tenSach[j];
				tenSach[j] = temp;
			}
		}
	}

	// In ra ten sach
	int dieuKien = 0;
	for (int i = 0; i < 15; i++) {
		if (uuTien[i] > 0) dieuKien++;
	}

	if (dieuKien > 0) {
		cout << "======DANH SACH CAC SACH LIEN QUAN ======" << endl;

		for (int i = 0; i < dieuKien; i++) {
			cout << "\t" << i << ". " << tenSach[i] << endl;
		}
		cout << "\t" << dieuKien << ". " << "Nhap lai ten sach " << endl;
		cout << "=========================================" << endl;
		cout << "\t\t***" << endl;
		cout << "\t\t***" << endl;
		cout << "\t\t***" << endl;
		cout << "\t\t***" << endl;
		cout << "=========MOI BAN CHON SACH=========" << endl;
		int chon;

		// OK!
		cout << "\n\n\n\tNHAP LUA CHON CUA BAN: ";
		cin >> chon;
		while (chon<0 || chon>dieuKien) {
			cin.clear();
			cin.ignore();
			cout << "\tlua chon cua ban khong hop le ! vui long kiem tra va nhap lai ! " << endl;
			cout << "\t................................................................" << endl;
			cin >> chon;
		}

		// OK!


		for (int i = 0; i < dieuKien; i++) {
			if (chon == i) {
				m = i;
				cout << "\n\tBAN DA XOA CUON SACH NAY :     ";
				cout << tenSach[i] << endl;
				cout << "\t_________________________" << endl;
			}
		}
		if (chon == dieuKien) {
			cin.ignore();
			xoa();
		}
	}
	else {// dieu kien =0---> khong co sach;
		cout << "\t! KHONG CO SACH MA BAN TIM !: " << endl;
		cout << "\t.............................." << endl;
		cout << "\tBAN HAY NHAP LAI TEN SACH HOAC THOAT: " << endl;
		cout << "\t......................................" << endl;
		cout << "\n\t0.Thoat" << endl;
		cout << "\t......." << endl;
		cout << "\n\t1.Nhap lai ten sach" << endl;
		cout << "\t..................." << endl;
		int chonTiep;
		cout << "\n\n\n\tNHAP LUA CHON CUA BAN: " << endl;
		cout << "\t_____________________" << endl;
		cout << "\n\tlua chon : ";
		cin >> chonTiep;
		while (chonTiep<0 || chonTiep>1) {
			cin.clear();
			cin.ignore();
			cout << "\tlua chon cua ban khong hop le ! vui long kiem tra va nhap lai ! " << endl;
			cout << "\t................................................................" << endl;
			cin >> chonTiep;
		}

		if (chonTiep == 1) {
			cin.ignore();
			xoa();
		}
		else {
			return 0;
		}

		return 0;
	}

	docTenSach.close();
	cout << "\n\n\n";
	
	// buoc tiep theo: xoa tren file;

	ofstream ghiTenSach;
	ghiTenSach.open("tenSachFile.txt", ios_base::out);
	for (int i = 0; i < soDong; i++) {
		if (i != m) {
			ghiTenSach << tenSach[i] << endl;
		}
	}
	ghiTenSach.close();
	cout << "\n\n\nNHAN ENTER ĐE TIEP TUC !\n" << endl;
	system("pause");
	return 0;
}

int xoaSach() {
	int chucNang;
	do {

		system("cls");
		cout << "================DANH SACH CHUC NANG================\n" << endl;
		cout << "0.TIM VA XOA SACH" << endl;
		cout << "1.XOA THEM SACH" << endl;
		cout << "2.THOAT\n" << endl;
		cout << "===============MOI BAN CHON CHUC NANG===============\n" << endl;
		cout << "\tlua chon cua ban la: ";
		cin >> chucNang;
		cout << endl << endl;
		cin.ignore();
		while (chucNang < 0 || chucNang>2) {
			cin.clear();
			cin.ignore(10, '\n');
			cout << "\tlua chon cua ban khong hop le ! vui long kiem tra va nhap lai ! " << endl;
			cout << "\t................................................................" << endl;
			cin >> chucNang;
		}
		switch (chucNang)
		{
		case 0:
			xoa();
			break;
		case 1:
			xoa();
			break;
		case 2:
			return 0;
			break;
		default:
			break;
		}
	} while (chucNang != 2);
	
	return 0;
}
// OK OK OK OK OK !

int them() {
	
	string tenThem;
	cout << "Ten Sach muon them la: ";
	fflush(stdin);
	getline(cin, tenThem);
	//============
	char S[100] = "";
	for (int i = 0; tenThem[i] != '\0'; i++) {
		S[i] = tenThem[i];
	};
	_strlwr_s(S);
	tenThem = S;
	//===============
	ifstream docTenSach;
	string tenSach[Max];
	int soDong = 0;
	docTenSach.open("tenSachFile.txt", ios_base::in);
	while (!docTenSach.eof()) {
		string x;
		fflush(stdin);
		while (getline(docTenSach, x)) {
			tenSach[soDong] = x;
			soDong++;
		}
	}
	docTenSach.close();
	ofstream ghiTenSach;
	ghiTenSach.open("tenSachFile.txt", ios_base::out||ios_base::binary);
	for (int i = 0; i <= soDong; i++) {
		if (i < soDong) {
			ghiTenSach << tenSach[i] << endl;
		}
		else {
			ghiTenSach << tenThem;
		}
	}

	ghiTenSach.close();
	cout << "\n\n\nNHAN ENTER ĐE TIEP TUC !\n" << endl;
	system("pause");
	return 0;
}
int themSach() {
	int chucNang;
	do {
		system("cls");
		cout << "================DANH SACH CHUC NANG================\n" << endl;
		cout << "0.THEM SACH" << endl;
		cout << "1.THEM SACH TIEP" << endl;
		cout << "2.THOAT\n" << endl;
		cout << "===============MOI BAN CHON CHUC NANG===============\n" << endl;
		cout << "\tlua chon cua ban la: ";
		cin >> chucNang;
		cout << endl << endl;
		cin.ignore();
		while (chucNang < 0 || chucNang>2) {
			cin.clear();
			cin.ignore(10, '\n');
			cout << "\tlua chon cua ban khong hop le ! vui long kiem tra va nhap lai ! " << endl;
			cout << "\t................................................................" << endl;
			cin >> chucNang;
		}
		switch (chucNang)
		{
		case 0:
			them();
			break;
		case 1:
			them();
			break;
		case 2:
			return 0;
			break;
		default:
			break;
		}
	} while (chucNang != 2);

	return 0;
}
// OK OK OK OK OK !

int main() {
	timSach();
	/*xoaSach();*/
	/*themSach();*/
	system("pause");
	return 0;

}





