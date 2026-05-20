#include <iostream>
#include <string>
#include "Second.h"

int main() {
    std::cout << "=== Testing Second<int> (basic) ===" << std::endl;

    Second<int> intArray(5);

    std::cout << "Pushing values..." << std::endl;
    intArray.push_back(10);
    intArray.push_back(20);
    intArray.push_back(30);

    std::cout << "Size: " << intArray.size() << std::endl;
    std::cout << "Is empty: " << (intArray.empty() ? "Yes" : "No") << std::endl;

    std::cout << "Elements: ";
    for (int i = 0; i < intArray.size(); ++i) {
        std::cout << intArray[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Last element: " << intArray.back() << std::endl;

    std::cout << "Search 20: ";
    int index = intArray.find(20);
    std::cout << "Result index: " << index << std::endl;

    std::cout << "Done." << std::endl;
    return 0;
}