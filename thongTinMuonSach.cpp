#include "ThongTinMuonSach.h"
#include "Complex.h"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;
ThongTinMuonSach::ThongTinMuonSach(){
};
ThongTinMuonSach::ThongTinMuonSach(int id1, int id2, string str3, string str4) {
	m_ID_User = id1;
	m_ID_Book = id2;
	m_tenUser = str3;
	m_tenSach = str4;
	m_xacNhan = "NO";
	m_traSach = "NO";
	m_time.setTimeNow();
};
ThongTinMuonSach::~ThongTinMuonSach(){
};

// hàm lưu thông tin 1 phần tử 
void ThongTinMuonSach::luuThongTinMuonSach(fstream &f, ThongTinMuonSach t) {
	f << t.getIDUser() << endl << t.getIDBook() << endl << t.getTenUser() << endl <<
		t.getTenSach() << endl << t.m_time.ngay << " " << t.m_time.thang << " " << t.m_time.nam << endl << t.getXacNhan() << endl << t.getTraSach() << endl;
};

// ham đọc dữ liệu từ file và lấy được danh sach thông tin tra sach
void ThongTinMuonSach::doc(vector< ThongTinMuonSach> &ds) {
	fstream f("muonSach.txt", ios_base::in | ios_base::app);
	while (!f.eof()) {
		ThongTinMuonSach t;
		string str;
		getline(f, str);
		// kiểm tra dòng trống
		if (str == "") {
			continue;
		}
		else {
			t.setIDUser(str);
			getline(f, str);
			t.setIDBook(str);
			getline(f, str);
			t.setTenUser(str);
			getline(f, str);
			t.setTenBook(str);
			getline(f, str);
			t.m_time.setTime(str);
			getline(f, str);
			t.setXacNhan(str);
			getline(f, str);
			t.setTraSach(str);
			ds.push_back(t);
		};
	};
};

// hàm định dạng xuất bảng thông tin
void ThongTinMuonSach::xuat(ThongTinMuonSach thongTin, int dem){
	cout << setw(1) << "|" << setw(4) << dem << setw(1) << "|" << setw(10) << thongTin.getIDUser() << setw(1) << "|" << setw(7) << thongTin.getIDBook()
		<< setw(1) << "|" << setw(20)
		<< thongTin.getTenUser() << setw(1) << "|" << setw(20) << thongTin.getTenSach() << setw(1) << "|" << setw(12) <<
		thongTin.m_time.ngay << "/" << thongTin.m_time.thang << "/" << thongTin.m_time.nam << setw(1) << "|" << setw(6) << thongTin.getXacNhan() << setw(1) << "|" << setw(6) << thongTin.getTraSach() << setw(1) << "|" << endl;
};

// hàm thao tác xác nhận cho mượn sách của thủ  thư
void ThongTinMuonSach::xacNhanMuonSach(fstream &f, vector< ThongTinMuonSach > &ds) {
	int n = ds.size();
	int A[Max_thong_bao];
	int chon = 10;// gan gia tri ban ki de lay gia tri vao vong lap de so sanh;
	while (chon != 0) {
		system("cls");
		cout << "                             ";
		cout << "# DANH SACH CAC DOC GIA DANG KY MUON SACH #" << endl << endl;
		cout << "----------------------------------------------------------------------------------------------" << endl;
		cout << setw(1) << "|" << setw(4) << "Stt" << setw(1) << "|" << setw(10) << "ID doc gia" << setw(1) << "|" << setw(7) << "ID sach"
			<< setw(1) << "|" << setw(20)
			<< "Ten doc gia" << setw(1) << "|" << setw(20) << "Ten sach" << setw(1) << "|" << setw(12) <<
			"thoi gian" << setw(1) << "|" << setw(6) << "XNMS" << setw(1) << "|" << setw(6) << "XNTS" << setw(1) << "|" << endl;
		cout << "----------------------------------------------------------------------------------------------" << endl;
		int dem2 = 0;
		for (int i = 0; i < n; i++) {
			// nếu chưa được xác nhận mượn sách thì in ra màn hình
			if (ds[i].getXacNhan() == "NO") {
				xuat(ds[i], dem2);
				A[dem2] = i;
				dem2++;
			}
		};

		cout << "0.THOAT" << endl;
		cout << "1.XAC NHAN TOAN BO" << endl;
		cout << "2.CHON THEO TUNG STT DE XAC NHAN : " << endl;
		cout << "Chon chuc nang : "; 
		chon = luaChon();
		if (chon == 1) {
			for (int i = 0; i < dem2; i++) {
				// nếu chọn thì xác nhận toàn bộ,,chuyển trường ds[i].xacNhan thành "YES"
				ds[A[i]].setXacNhan("YES");
			}
		};
		if (chon == 2) {
			cout << "chon stt(so thu tu tuong ung tren bang) can xac nhan :"; int sepp; cin >> sepp;
			for (int i = 0; i < n; i++) {
				if (i == sepp) {
					// nếu chọn thì xác nhận ;
					ds[A[i]].setXacNhan("YES");
				}
			}
		};
	};
};

void ThongTinMuonSach::xuatDanhSachDangMuonSach(vector< ThongTinMuonSach > &ds) {
	system("cls");
	int dem = 0;
	cout << "                             ";
	cout << "# DANH SACH CAC DOC GIA DANG KY MUON SACH #" << endl << endl;
	cout << "----------------------------------------------------------------------------------------------" << endl;
	cout << setw(1) << "|" << setw(4) << "Stt" << setw(1) << "|" << setw(10) << "ID doc gia" << setw(1) << "|" << setw(7) << "ID sach"
		<< setw(1) << "|" << setw(20)
		<< "Ten doc gia" << setw(1) << "|" << setw(20) << "Ten sach" << setw(1) << "|" << setw(25) <<
		"thoi gian" << setw(1) << "|" << setw(6) << "XNMS" << setw(1) << "|" << setw(6) << "XNTS" << setw(1) << "|" << endl;
	cout << "----------------------------------------------------------------------------------------------" << endl;
	for (int i = 0; i < ds.size(); i++) {
		if (ds[i].getXacNhan() == "YES"&&ds[i].getTraSach() == "NO") {
			dem++;
			xuat(ds[i], dem);
		}
	}
};

void ThongTinMuonSach::danhSachTreHenTraSach(vector< ThongTinMuonSach > &ds) {
	int dem = 0;
	cout << "                             ";
	cout << "# DANH SACH CAC DOC GIA TRE HAN TRA SACH #" << endl << endl;
	cout << "----------------------------------------------------------------------------------------------" << endl;
	cout << setw(1) << "|" << setw(4) << "Stt" << setw(1) << "|" << setw(10) << "ID doc gia" << setw(1) << "|" << setw(7) << "ID sach"
		<< setw(1) << "|" << setw(20)
		<< "Ten doc gia" << setw(1) << "|" << setw(20) << "Ten sach" << setw(1) << "|" << setw(12) <<
		"thoi gian" << setw(1) << "|" << setw(6) << "XNMS" << setw(1) << "|" << setw(6) << "XNTS" << setw(1) << "|" << endl;
	cout << "----------------------------------------------------------------------------------------------" << endl;
	for (int i = 0; i < ds.size(); i++) {
		if (ds[i].getXacNhan() == "YES" && ds[i].getTraSach() == "NO" && (1)) {
			dem++;
			xuat(ds[i], dem);
		}
	}
};

void ThongTinMuonSach::xacNhanTraSach(fstream &f, vector< ThongTinMuonSach > &ds) {
	int n = ds.size();

	int A[Max_thong_bao];
	int chon = 10;// gan gia tri ban ki de lay gia tri vao vong lap de so sanh;
	while (chon != 0) {
		system("cls");
		int dem2 = 0;
		cout << "                             ";
		cout << "# DANH SACH CAC DOC GIA DANG MUON SACH #" << endl << endl;
		cout << "----------------------------------------------------------------------------------------------" << endl;
		cout << setw(1) << "|" << setw(4) << "Stt" << setw(1) << "|" << setw(10) << "ID doc gia" << setw(1) << "|" << setw(7) << "ID sach"
			<< setw(1) << "|" << setw(20)
			<< "Ten doc gia" << setw(1) << "|" << setw(20) << "Ten sach" << setw(1) << "|" << setw(12) <<
			"thoi gian" << setw(1) << "|" << setw(6) << "XNMS" << setw(1) << "|" << setw(6) << "XNTS" << setw(1) << "|" << endl;
		cout << "----------------------------------------------------------------------------------------------" << endl;
		for (int i = 0; i <n; i++) {
			if (ds[i].getXacNhan() == "YES") {
				if (ds[i].getTraSach() == "NO") {
					xuat(ds[i], dem2);
					A[dem2] = i;
					dem2++;
				}
			}
		}
		cout << "0.THOAT" << endl;
		cout << "1.CHON TUNG THONG BAO DE XAC NHAN TRA SACH : " << endl;
		cout << "Chon chuc nang : "; cin >> chon;
		if (chon == 1) {
			cout << "chon thong bao can xac nhan :"; int sepp; cin >> sepp;
			for (int i = 0; i < dem2; i++) {
				if (i == sepp) {
					ds[A[i]].getTraSach() = "YES";
				}
			}
		}
		else break;
	}
};

void ThongTinMuonSach::luuThongTin_last(fstream &f, vector< ThongTinMuonSach> &ds) {
	for (int i = 0; i < ds.size(); i++) {
		luuThongTinMuonSach(f, ds[i]);
	};
}

void ThongTinMuonSach::guiThongBao(vector< ThongTinMuonSach > &ds, int Id) {
	ThoiGian tg;
	tg.setTimeNow();
	for (int i = ds.size() - 1; i >= 0; i--){
		if (ds[i].getXacNhan() == "YES") {
			if (ds[i].getIDUser() == Id) {
				string Thu = "--->[THONG BAO MUON SACH]: Chao ban ! ban vua muon thanh cong cuon sach co ten la < "
					+ ds[i].getTenSach() + " > vao ngay ";
				cout << Thu << ds[i].getNgay() << "/" << ds[i].getThang() << "/" << ds[i].getNam() << endl;
				// thong bao den doc gia da muon sach thanh cong;
				// nhac nho tu ngay 8 9 10 cho doc gia tre sach
				if (ds[i].getTraSach() == "NO") {
					if (chenhLechNgay(ds[i].m_time, tg) > 21) {
						cout << "--->[THONG BAO TRA SACH]: chao ban ! ban da muon sach duoc HON 21 NGAY ke tu ngay dang ky muon sach ,";
						cout << "da QUA HAN muon sach... ban hay tra sach cho thu vien ! neu sau 30 ngay muon ma khong tra sach thi ban se bi phat! " << endl;
					};
					if (chenhLechNgay(ds[i].m_time, tg) > 30) {
						cout << "--->[THONG BAO QUA HAN TRA SACH]:Ban da qua han hon 30 ngay chua tra sach.. Hay tra sach gap cho thu vien .Neu khong tra ban se bi ";
						cout << "thu vien gui giay bao len phong dao tao truong, de truong khien trach..dong thoi ban cung phai dem theo mot ";
						cout << "khoang tien gap 3 lan so ngay ban tre hen tra sach(tinh tu ngay thu 21) de nop phat! tran tran!" << endl;
					};
					cout << "-----------------------" << endl;
				};
			}
		}
	}
};

void ThongTinMuonSach::setIDUser(string str) {
	stringstream ss(str);
	ss >> m_ID_User;
};
void ThongTinMuonSach::setIDBook(string str) {
	stringstream ss(str);
	ss >> m_ID_Book;
};
void ThongTinMuonSach::setTenUser(string str) {
	m_tenUser = str;
};
void ThongTinMuonSach::setTenBook(string str) {
	m_tenSach = str;
};
void ThongTinMuonSach::setXacNhan(string str) {
	m_xacNhan = str;
};
void ThongTinMuonSach::setTraSach(string str) {
	m_traSach = str;
};

int ThongTinMuonSach::getIDUser() {
	return m_ID_User;
};
int ThongTinMuonSach::getIDBook() {
	return m_ID_Book;
};
string ThongTinMuonSach::getTenUser(){
	return m_tenUser;
};
string ThongTinMuonSach::getTenSach(){
	return m_tenSach;
};
int ThongTinMuonSach::getNgay() {
	return m_time.ngay;
};
int ThongTinMuonSach::getThang() {
	return m_time.thang;
};
int ThongTinMuonSach::getNam() {
	return m_time.nam;
};
string ThongTinMuonSach::getXacNhan() {
	return m_xacNhan;
};
string ThongTinMuonSach::getTraSach() {
	return m_traSach;
};