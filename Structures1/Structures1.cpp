#include <iostream>
using namespace std;

template<typename T>
struct elem {
    int value;
    elem* next = nullptr;
};
template<typename T>
void push(elem<T>*& stack, int value) {
    elem<T>* newel = new elem;
    newel->value = value;

    if (!stack) {
        stack = newel;
    }
    else {
        newel->next = stack;
        stack = newel;
    }
}
template<typename T>
bool pop(elem<T>*& stack, int value) {
    if (!stack) return false;
    elem<T>* rem = stack;
    value = stack->value;
    stack = stack->next;
    delete rem;
    return true;
}
template<typename T>
const int* peek(const elem<T>* stack) {
    if (!stack) return nullptr;
    return &stack->value;
}
template<typename T>
elem<T>* next_elem(const elem<T>* elem) {
    if (elem) return elem->next;
    return nullptr;
}
template<typename T>
elem<T>* last(const elem<T>* el) {
    if (el) while (el->next) el = el->next;
    return (elem*)el;
}
template<typename T>
void clear(elem<T>*& stack) {
    while (stack) {
        elem* rem = stack;
        stack = stack->next;
        delete rem;
    }
}


struct Pair {
    int first;
    int second;
    Pair* next = nullptr;
};

void checkSumm(Pair*& stack, int x) {
    Pair* curr = stack;
    if (stack == nullptr) return;
    while (curr != nullptr) {
        if (curr->first + curr->second == x) {
            curr->first = 0;
            curr->second = 0;
        }
        curr = curr->next;
    }
}

int main()
{
    cout << "Hello World!\n";
}
