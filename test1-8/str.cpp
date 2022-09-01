#include "str.h"
#include <iostream>
using namespace std;


// 初始化构造函数
myString::myString(int size) {
	this->size = size+1;
	this->pc = new char[this->size];
	this->pc[0] = '\0';
}
myString::myString(int size, char* c) {
	this->size = size+1;
	this->pc = new char[this->size];
	memcpy(this->pc,c,this->size);
	this->pc[size] = '\0';
}
myString::myString(const myString& str) {
	this->size = str.size;
	this->pc = new char[this->size];
	memcpy(this->pc,str.pc,str.size);
}
// 析构造函数
myString::~myString() {
	delete []this->pc;
	this->pc = NULL;
	this->size = 0;
}

char& myString::operator[](int index){
	if (index < this->size) {
		return this->pc[index];
	}
	else {
		return this->pc[this->size-1];
	}
}
myString myString::operator+(const myString& str) {
	if (str.pc==NULL) {
		return *this;
	}

	int newSize = str.size + this->size;
	myString tmp(newSize);
	
	tmp.pc = new char[newSize];
	memcpy(tmp.pc, this->pc, newSize);
	//memset(tmp.pc,0,newSize);
	//strcpy_s(tmp.pc, this->size, this->pc);
	strcpy_s(tmp.pc, newSize, str.pc);

	delete [] this->pc;
	this->pc = NULL;
	return tmp;
}
myString myString::operator+(string str) {
	int newSize = this->size + str.size();
	myString tmp(newSize-1);
	
	memcpy(tmp.pc, this->pc, newSize);
	
	for (int i = newSize - str.size() - 1, j = 0; i < newSize - 1; ++i, ++j) {
		tmp.pc[i] = str.at(j);
	}

	tmp.pc[newSize - 1] = '\0';

	delete []this->pc;
	this->pc = NULL;

	return tmp;
}
myString& myString::operator+=(const myString& str) {
	if (str.pc == NULL) {
		return *this;
	}

	int newSize = str.size + this->size-1;
	char *tmp = new char[newSize];
	memcpy(tmp, this->pc, newSize);
	//memset(tmp.pc,0,newSize);
	//strcpy_s(tmp.pc, this->size, this->pc);
	strcat_s(tmp, newSize, str.pc);

	//cout << "myString& myString::operator+=(const myString& str) {} " << newSize << endl;
	delete[] this->pc;
	this->pc = NULL;
	this->pc = tmp;
	this->size = newSize;
	return *this;
}
myString& myString::operator+=(string str) {
	this->size = this->size + str.size();
	char* tmp = new char[this->size];

	memcpy(tmp, this->pc, this->size);

	for (int i = this->size - str.size() - 1,j=0; i < this->size-1;++i,++j) {
		tmp[i] = str.at(j);
	}

	tmp[this->size - 1] = '\0';
	delete[]this->pc;
	this->pc = NULL;
	this->pc = tmp;
	return *this;
}

myString myString::operator=(const myString& str) {
	this->size = str.size;
	delete []this->pc;
	this->pc = new char[this->size];
	memcpy(this->pc, str.pc, str.size);
	return *this;
}
myString myString::operator=(string str) {
	this->size = str.size() + 1;

	if(this->pc!=NULL) delete[]this->pc;

	this->pc = new char[this->size];

	for (int i = 0; i < this->size-1;++i) {
		this->pc[i] = str.at(i);
	}
	this->pc[this->size - 1] = '\0';
	return *this;
}
myString operator+(myString& str1,myString& str2) {
	int newSize = str1.size + str2.size-1;
	//cout <<"myString operator+(myString& str1,myString& str2){}" << newSize << endl;
	myString tmp(newSize-1);

	memcpy(tmp.pc, str1.pc, newSize);
	//memset(tmp.pc,0,newSize);
	//strcpy_s(tmp.pc, this->size, this->pc);
	strcat_s(tmp.pc, newSize, str2.pc);

	return tmp;
}

ostream& operator<<(ostream& out, const myString &str) {
	cout << str.pc;
	return out;
}


bool myString::operator==(const myString& str) {
	//cout << this->size <<"  " << str.size << endl;
	if (this->size != str.size) {
		return false;
	}
	for (int i = 0; i < this->size;++i) {
		//cout << "---" << this->pc[i] <<" " << str.pc[i] << " " << (this->pc[i] != str.pc[i]) << endl;
		if (this->pc[i] != str.pc[i]) {
			
			return false;
		}
	}
	return true;
}

bool myString::operator==(string str) {
	//cout << this->size << "  " << str.size()+1 << endl;
	if (this->size != str.size()+1) {
		return false;
	}
	for (int i = 0; i < this->size-1; ++i) {
		if (this->pc[i] != str[i]) {
			return false;
		}
	}
	return true;
}

bool myString::operator==(char* str) {
	int i = 0;
	for (; *str; str++) {
		if (this->pc[i] != str[i]) {
			return false;
		}
		i++;
	}
	if (i < this->size) {
		return false;
	}
	return true;
}

bool myString::operator>(const myString& str) {
	if (this->size > str.size)
		return true;
	else
		return false;
}
bool myString::operator>=(const myString& str) {
	if (this->size >= str.size)
		return true;
	else
		return false;
}
bool myString::operator<(const myString& str) {
	if (this->size < str.size)
		return true;
	else
		return false;
}
bool myString::operator<=(const myString& str) {
	if (this->size <= str.size)
		return true;
	else
		return false;
}

