#include <iostream>
using namespace std;

class LightBulb {
private:
	bool isOn;
public:
	void turnOn() {
		isOn = true;
	}
	void turnOff() {
		isOn = false;
	}
	void toggle() {
		isOn = !isOn;
	}
	const char* getState() {
		if (isOn == true) {
			cout << "ON" << endl;
		}
		if (isOn == false) {
			cout << "OFF" << endl;
		}
	}
};


int main() {
	LightBulb lightBulb;
	lightBulb.turnOn();
}