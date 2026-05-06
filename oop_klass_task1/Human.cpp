#include "Human.h"

int Human::countPerson{ 0 };

void Human::print() {
	cout << ID << " " << Name << " " << Otchestvo << " " << Surname << endl;
}