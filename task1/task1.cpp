#include <iostream>
#include <string>
using namespace std;

void task_1() {
    string name = "Marat";
    cout << "Hi, " << name << "!" << endl;
    cout << name.length() << endl;
    cout << name.at(0) << endl;
}

void task_2() {
    string name;
    getline(cin, name);
    cout << "Good afternoon, " << name << "!" << endl;
}

void task_3() {
    string str = "C++ - is a strong programming language. Class string is very comfortable.";
    int ddd = str.find("string");
    if (ddd == string::npos) {
        cout << "Word is not found" << endl;
    }
    else {
        cout << "Word 'string' found on position " << ddd << endl;
    }
}

void task_4() {
    string name;
    bool fl = true;
    getline(cin, name);
    for (char &c : name)  {
        if (c == ' ') {
            fl = true;
        }
        else if (fl) {
            c = toupper(c);
            fl = 0;
        }
    }
    cout << name << endl;
}

void task_5() {
    string name = "Today is good weather";
    name.insert(8, " very");
    cout << name << endl;
    name.replace(9, 10, "the best ");
    cout << name << endl;
}

void task_6() {
    string name = "Error code: 404 - Not found";
    cout << name << endl;
    name.find(':');
    cout << name.substr(12, 3) << endl;
    cout << name.erase(15) << endl;

}

void task_7() {
    string numbers = "12345678910";
    string word = "";
    for (int i = 0; i <= 10; i++) {
        word.push_back(numbers[i]);
    }
    cout << word << endl;
    if (!(word.empty())) {
        for (int i = 0; i <= word.length() - 5; i++) {
            word.pop_back();
        }
        cout << word << endl;
    }
    
}
void task_8() {
    string pass;
    string pass1;
    getline(cin, pass);
    getline(cin, pass1);
    cout << (pass.compare(pass1) ? "Access denied" : "Access permitted") << endl;
    cout << (pass.length() == pass1.length() ? "They have the same length" : "They dont have the same length");
}

void task_9() {
    string name = "This is a neccesary message";
    cout << name.length() << endl;
    name.clear();
    cout << "String has been cleared. Length: " << name.length() << endl;
    if (name.empty()) {
        cout << "string is empty" << endl;
    }
    else {
        cout << " string is not empty" << endl;
    }
}

int main()
{
    task_9();
}

