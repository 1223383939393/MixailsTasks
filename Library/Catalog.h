//#pragma once
//#include <iostream>
//#include <fstream>
//#include <string>
//#include <vector>
//using namespace std;
//class Catalog
//{
//	string bookName;
//	string authorName;
//	int bookYear;
//
//	
//public:
//	Catalog(string bookname, string author, int year) : bookName{ bookname }, authorName{ author }, bookYear{year} { }
//	
//	void setName(string name) {
//		name = bookName;
//	}
//	void setAuthorName(string name) {
//		name = authorName;
//	}
//	void setYear(int name) {
//		name = bookYear;
//	}
//
//	const string& getBookName() { return bookName; }
//	const string& getAuthorName() { return authorName; }
//	const int& getBookYear() { return bookYear; }
//
//	void AddBook(vector<Catalog> vex, Catalog c) {
//		vex.push_back(c);
//		ifstream in("Library.txt", ios::app);
//		if (in.is_open())
//		{
//			in >> c;
//		}
//		in.close();
//	}
//
//	void seeAll() {
//		string line;
//		ifstream in("Library.txt");
//		if (in.is_open()) {
//			while (getline(in, line)) {
//				cout << line << endl;
//			}
//		}
//		in.close();
//	}
//	void findByName() {
//
//	}
//	void findByAuthor() {
//
//	}
//	void saveIntoFile(Catalog c) {
//		ifstream in("Library.txt");
//		/*in << c << endl;*/
//	}
//	void loadFromFile() {
//
//	}
//};
//
//istream& operator >> (std::istream& in, Catalog& catalog);
//
//ostream& operator << (ostream& out, const Catalog& catalog);
