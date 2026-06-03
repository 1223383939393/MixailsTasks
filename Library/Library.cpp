#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
class Catalog
{
	string bookName;
	string authorName;
	int bookYear;


public:
	Catalog(string bookname, string author, int year) : bookName{ bookname }, authorName{ author }, bookYear{ year } {}

	void setName(string name) {
		name = bookName;
	}
	void setAuthorName(string name) {
		name = authorName;
	}
	void setYear(int name) {
		name = bookYear;
	}

	const string& getBookName() const { return bookName; }
	const string& getAuthorName() const { return authorName; }
	const int& getBookYear() const { return bookYear; }

	void AddBook(vector<Catalog> vex, Catalog c) {
		vex.push_back(c);
		ifstream in("Library.txt", ios::app);
		if (in.is_open())
		{
			in >> c;
		}
		in.close();
	}

	void seeAll() {
		string line;
		ifstream in("Library.txt");
		if (in.is_open()) {
			while (getline(in, line)) {
				cout << line << endl;
			}
		}
		in.close();
	}
	void findByName() {

	}
	void findByAuthor() {

	}
	void saveIntoFile(Catalog c) {
		ifstream in("Library.txt");
		in >> c;
	}
	void loadFromFile() {

	}
	friend istream& operator >> (std::istream& in, Catalog& catalog);
};


istream& operator >> (std::istream& in, Catalog& catalog)
{
	string name;
	string author;
	int age;
	in >> name >> author >> age; // читаем имя и возраст из потока
	catalog.setName(name); // устанавливаем имя
	catalog.setAuthorName(author);
	catalog.setYear(age);
	// устанавливаем возраст
	return in; // возвращаем поток для цепочек операций
}

ostream& operator << (ostream& out, const Catalog& catalog) {
	return out << catalog.getBookName() << " " << catalog.getAuthorName() << " " << catalog.getBookYear();
}
int main()
{
    std::cout << "Hello World!\n";
}

