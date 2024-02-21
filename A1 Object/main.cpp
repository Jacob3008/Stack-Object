// Jacob Neuman 2/21/24

#include <iostream>
#include <vector>
#include "stack.h"
using namespace std;

bool prompt(Stack&);

int main() {
	Stack myStack;

	// repeate prompt until user exits
	while (prompt(myStack))
		prompt(myStack);

	return 0;
}

bool prompt(Stack& stack) {
	int choice;

	cout << "1. Push" << endl;
	cout << "2. Pop" << endl;
	cout << "3. Display" << endl;
	cout << "4. Exit" << endl;
	cout << "Enter choice 1-4: "; cin >> choice;

	// validate choice
	while (choice > 4 || choice < 1) {
		cout << "Please enter a value 1-4: "; cin >> choice;
	}

	// push value for 1
	if (choice == 1) {
		string val;
		cout << "Enter value to push to the stack: "; cin >> val;
		stack.push(val);
		cout << endl;
		return true;
	}

	// pop value for 2
	else if (choice == 2) {
		cout << endl;
		stack.pop();
		cout << endl;
		return true;
	}

	// display elements for 3
	else if (choice == 3) {
		cout << endl;
		stack.display();
		cout << endl;
		return true;
	}

	// exit
	else {
		return false;
	}
}