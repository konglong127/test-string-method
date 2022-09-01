#pragma once
#ifndef STR_H_
#define STR_H_

#include <iostream>
using namespace std;

class myString {
	friend ostream& operator<<(ostream& out, const myString& str);
	friend myString operator+(myString& str1, myString& str2);
private:
	char* pc;
	int size;
public:
	myString(int size);
	myString(int size,char *c);
	myString(const myString& str);
	~myString();

	char& operator[](int index);
	myString operator+(const myString &str);
	myString operator+(string str);
	myString& operator+=(const myString& str);
	myString& operator+=(string str);
	myString operator=(const myString& str);
	myString operator=(string str);

	bool operator==(const myString& str);
	bool operator==(string str);
	bool operator==(char* str);
	bool operator>(const myString& str);
	bool operator>=(const myString& str);
	bool operator<(const myString& str);
	bool operator<=(const myString& str);

	int length() { return this->size; }
};

#endif //TEST1_STR_H