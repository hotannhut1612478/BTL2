#include "Comment.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;
Comment::Comment(){
};
Comment::Comment(string str) {
	m_name = str;
}
Comment::~Comment(){
};

void Comment::docGopY(string str[], int &n) {
	fstream f;
	f.open("gopY.txt", ios::in);
	while (!f.eof()) {
		string x;
		fflush(stdin);
		getline(f, x);
		str[n] = x;
		n++;
	};
	f.close();
};

void Comment::ghi() {
	fstream f;
	f.open("gopY.txt", ios::out | ios::app);
	f << m_name << ": " << m_comment << endl;
};

void Comment::setComment(string str) {
	m_comment = str;
};
