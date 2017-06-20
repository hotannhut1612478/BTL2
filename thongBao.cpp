#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
#include <math.h>

#define Max_Anouce 100

using namespace std;

class thongBao{
public: 
	string tieuDe;
	string noiDung;
};
void themThongBao() {
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
void suaThongBao(thongBao thongbao[Max_Anouce], int k) {
	int set1, set2;
	cout << "Hay chon thong bao can sua: ";
	cin >> set1;
	cout << "\n Ban muon sua thong bao nay: ";
	cout << thongbao[set1-1].tieuDe << endl;
	cout << thongbao[set1-1].noiDung << endl;
	cout << "***1.Yes***   ***2.No*** \n";
	cin >> set2;
	switch (set2)
	{
	case 1: {
		cin.ignore(1);
		string data1, data2;
		cout << "Moi ban nhap tieu de  moi: ";
		getline(cin, data1);
		thongbao[set1-1].tieuDe = data1;
		cout << "Moi ban nhap noi dung  moi: ";
		getline(cin, data2);
		thongbao[set1-1].noiDung = data2;
		fstream f;
		f.open("thongbao.txt", ios::out);
		for (int i = 0; i < k; i++)
		{
			f << thongbao[i].tieuDe + "\n";
			f << thongbao[i].noiDung + "\n";
		}
		f.close();
		cout << "*****Da thay doi.*****" << endl;
		break;
	}
	case 2: {
		cout << "Tro ve menu.";
		break;
	default: cout << "Moi ban nhap lai";
	break;
	}
	}
}
void xoaThongBao(thongBao thongbao[Max_Anouce], int k) {
	ifstream docTenSach;
	int set1, set2;
	cout << "Chon thong bao can xoa: ";
	cin >> set1;
	cout << "Ban muon xoa thong bao nay: ";
	cout << thongbao[set1-1].tieuDe << endl;
	cout << thongbao[set1-1].noiDung << endl;
	cout << "***1.Yes***   ***2.No*** \n";
	cin >> set2;
	switch (set2)
	{
	case 1: {
		{
			ofstream ghiTenSach;
			ghiTenSach.open("thongbao.txt", ios_base::out);
			for (int i = 0; i < k; i++) {
				if (i != set1-1) {
					ghiTenSach << thongbao[i].tieuDe + "\n";
					ghiTenSach << thongbao[i].noiDung + "\n";
				}
			}
			ghiTenSach.close();
		}
		break;
		
	}
	case 2: {
		cout << "Tro ve menu.";
		break;
	default: cout << "Moi ban nhap lai"; 
	break;
	}
	}
}
void docThongBao(thongBao data[Max_Anouce]){
	cout << "Chon thong bao ban muon doc : ";
	int n;
	cin >> n;
	cout << data[n-1].tieuDe << endl;
	cout << data[n-1].noiDung << endl;
}
int menuThongBao() {
	int choice;
	do
	{
		system("cls");
		thongBao data[Max_Anouce];
		string str[Max_Anouce];
		cout << "TAT CA THONG BAO " << endl;

		fstream f;
		f.open("thongbao.txt", ios::in);

		int line = 0;
		int soDong;
		
		while (!f.eof()) {
			string x;
			fflush(stdin);
			while (getline(f, x)) {
			str[line] = x;
			line++;
			fflush(stdin);
			}
			
		}
		
		soDong = (line +1)/2;

		f.close();

		for (int i = 0; i < soDong; i++)
		{
			data[i].tieuDe = str[i*2];
			data[i].noiDung = str[i*2+1];
		}

		for (int d = 0; d < soDong; d++) {
			fflush(stdin);
			string S = data[d].noiDung;
			cout << "\t" << d + 1 << ". " << "* [TIEU DE]: "<<data[d].tieuDe << endl;
			cout << "\t   * [NOI DUNG]";
			cout << "\t";
			for (int i = 0; i < 15; i++) {
				cout << S[i];
			}
			cout << "..." << endl << endl << endl;	
		}
		
	
		cout << "-----------------" << endl;
		cout << "| Menu thong bao | " << endl;
		cout << "-----------------" << endl;
		cout << "\t" << "1. Them thong bao" << endl;
		cout << "\t" << "2. Chinh sua thong bao" << endl;
		cout << "\t" << "3. Xoa thong bao" << endl;
		cout << "\t" << "4. Doc noi dung thong bao" << endl;
		cout << "\t" << "5. Thoat" << endl;
		cout << "\t" << "***********************" << endl;


		cout << "\t" << "Nhap lua chon cua ban: ";
		cin >> (choice);
		
		switch (choice)
		{
		case 1:
			cin.ignore(1);
			themThongBao();
			break;
		case 2:
			cin.ignore(1);
			suaThongBao(data, soDong);
			break;
		case 3:
			cin.ignore(1);
			xoaThongBao(data, soDong);
			break;
		case 4: 
			cin.ignore(1);
			docThongBao(data);
			break;
		case 5:
			return 0;
			break;
		default: {cout << "Moi ban nhap lai"; 
			cin >> choice;	}
		break;
		}
	} while (choice != 4);
}
	
	
int main(){
	menuThongBao();
	system("pause");
	return 0;
}