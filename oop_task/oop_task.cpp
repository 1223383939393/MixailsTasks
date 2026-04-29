#include <iostream>
using namespace std;

class Product {
public:
	char name[50];
	int quantity;
	double price;

	void printProduct() {
		cout << "Tovar: " << name << endl;
		cout << "Quantity: " << quantity << " sth. " << endl;
		cout << "Price: " << price << " rub " << endl;
	}

	double getTotalCost() {
		return quantity * price;
	}
};

int main()
{
	Product monik;
	char text[] = "Monitor";
	strcpy_s(monik.name, strlen(text) + 1, text);
	monik.quantity = 15;
	monik.price = 15000.0;
	monik.printProduct();
	cout << monik.getTotalCost();
	
}


