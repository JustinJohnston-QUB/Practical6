#include "ArrayStack.h"
#include<iostream>

template<typename T>
void setupStack(ArrayStack < T >* s, int num) {
	std::cout << "Enter Information in to the stack:" << endl;
	for (int i = 0; i < num; i++) {
		std::cout << i + 1<< ":";
		T input;
		std::cin >> input;
		s->push(input);
	}
}

template<typename T>
void printStack(ArrayStack<T>& s) {
	T* ptr = s.top();
	for (int i = 0; i < s.size(); i++) {
		std::cout <<  *ptr-- << " ";
	}	
	std:cout << endl;
}

template<typename T>
void removeAt(ArrayStack < T >* s, int n) {
	if (n< 0 || n > s->size()) {
		std::cout << "this value does not exist";
		return;
	}
	int newSize = s->size();
	ArrayStack<T> tempStack(newSize);

	for (int i = newSize; i > n; i--) {
		tempStack.push(*s->pop());
	}

	T removed = *s->pop();

	for (int i = n-1; i >0; i--) {
		tempStack.push(*s->pop());
	}

	newSize--;
	for (int i = 0; i <newSize; i++) {
		s->push(*tempStack.pop());
	}
}


int main() {
	int size = 7;
	ArrayStack<std::string> daysOfWeek(size);
	setupStack(&daysOfWeek, size);
	printStack(daysOfWeek);
	removeAt(&daysOfWeek, 2);
	printStack(daysOfWeek);
	return 0;
}