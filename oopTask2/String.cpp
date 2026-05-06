#include "String.h"
String::String(string te) {
	size = te.length();
	text = new char[size];
	for (int i = 0; i < size; i++) {
		te[i] = text[i];
	}
	/*text[size] = '\0';*/
}
void String::write() {
	string a;
	cin >> a;
	size = a.length();
	delete[] text;
	text = new char[a.length()];
	for (int i = 0; i < size; i++) {
		a[i] = text[i];
	}
	/*text[size] = '\0';*/
}