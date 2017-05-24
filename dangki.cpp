#include <iostream>
#include <string>
using namespace std;

class User {
public:
	// mã số tài khoản
	int id;
	// tên đăng nhập
	char nameLogin[18];
	// mật khẩu
	char passWord[18];
	// họ và tên
	char hoTen[40];
	// số điện thoại
	double sdt;
	// chứng minh nhân dân
	double cmnd;
	// mã định danh
	int ident;

public:
	// mẫu đăng kí
	void subscription() {
		cout << "Nhap ho va ten : ";
		cin >> hoTen;
		//sao chép nội dung sau khi kiểm tra tính hợp lệ từ hàm kiTuDacBiet sang hoTen
		strcpy_s(hoTen, kiTuDacBiet(hoTen, "Ho va ten"));

		cin.ignore(100,'\n');
		cout << "Nhap vao ten dang nhap : ";
		cin >> nameLogin;
		//sao chép nội dung sau khi kiểm tra độ dài từ hàm leng sang nameLogin
		strcpy_s(nameLogin, leng(nameLogin, "ten dang nhap"));
		strcpy_s(nameLogin, kiTuDacBiet(nameLogin, "Ten dang nhap"));

		cin.ignore(100, '\n');
		cout << "Nhap mat khau : ";
		cin >> passWord;
		strcpy_s(passWord, leng(passWord, "mat khau"));
		strcpy_s(passWord, kiTuDacBiet(passWord, "Mat khau"));

	}

private:

	char *leng(char x[],string z) {
		//kiểm tra độ dài
		if (strlen(x) > 18 || strlen(x) < 6) {
			system("cls");
			cout << "Do dai " << z << " khong the vuot qua 18 ky tu hoac nho hon 6 ky tu." << endl;
			subscription();
		};
		return x;
	};

	char *kiTuDacBiet(char x[], string z) {
		char S[40] = "";
		strcpy_s(S, x);
		// hàm _strlwr_s dùng để chuyển chuỗi ký tự thành chữ thường
		_strlwr_s(S);
		for (int i = 0; i < strlen(S); i++) {
			//kiểm tra ký tự đặc biệt
			bool j = false;
			// nếu S[i] bằng một trong những kí tự cho phép thì biến boolen j sẽ = true, nghĩa là kí tự S[i] đã hợp lệ
			for (char kt = 'a'; kt != 'z' + 1; kt++) if (S[i] == kt) j = true;
			for (char so = '0'; so <= '9'; so++) if (S[i] == so) j = true;
			if (j == false) {
				system("cls");
				cout << z << " khong chua khoang trong hoac ki tu dang biet. Hay thu lai." << endl;
				subscription();
			};
		};
		return x;
	};
};

int main() {
	User a;
	a.subscription();
	cout << a.hoTen << endl;
	cout << a.nameLogin << endl;
	cout << a.passWord << endl;


	system("pause");
}


