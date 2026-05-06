#pragma once
#include <iostream>
#include <string>
using namespace std;
class String
{
	char* text;
	int size;
public:
	String() {
		text = new char[80];
	}
	String(int num) {
		text = new char[num];		
	}
	String(string te);
	String(const String& object) : text{ object.text }, size{object.size} {
		cout << "String Copy constructed for" << this << '\n';
	}
	void print() {
		cout << text << endl;
	}
	void write();
};

