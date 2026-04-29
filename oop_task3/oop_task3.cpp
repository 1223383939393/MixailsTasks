
#include <iostream>
using namespace std;

class WebLink {
private:
    char* url;
    char* description;
public:
    WebLink(const char* linkUrl, const char* linkDesc) {
        url = new char[strlen(linkUrl) + 1];
        description = new char[strlen(linkDesc) + 1];

        strcpy_s(url, strlen(linkUrl) + 1, linkUrl);
        strcpy_s(description, strlen(linkDesc) + 1, linkDesc);
    }
    void print() {
        cout << "Description: " << description << endl;
        cout << "Url: " << url << endl;
    }

};

int main()
{
    WebLink weblink("https://academy.top", "Сайт Компьютерной Академии");
    weblink.print();
}
