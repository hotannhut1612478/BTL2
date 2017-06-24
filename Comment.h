#pragma once
#include <string>
class Comment{
public:
	Comment();
	Comment(std::string);
	~Comment();
private:
	std::string m_name;
	std::string m_comment;
public:
	void ghi();
	void docGopY(std::string[], int &);
	void setComment(std::string);
};

