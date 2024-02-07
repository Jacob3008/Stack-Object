#include <iostream>
#include <vector>
using namespace std;

bool prompt(vector<string>&);
void display(vector<string>);
void validate(string&);

int main() {
	vector<string> stack;

	// repeate prompt until user exits
	while (prompt(stack))
		prompt(stack);

	return 0;
}

bool prompt(vector<string>& stack) {
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

	if (choice == 1) {
		string val;
		cout << "Enter value to push to the stack: "; cin >> val;
		validate(val);
		stack.push_back(val);
		cout << endl;
		return true;
	}
	else if (choice == 2) {
		cout << endl;

		// check vector isnt empty
		if (stack.empty()) {
			cout << "error, underflow" << endl;
		}
		else {
			cout << "Popped: " << stack.back() << endl;
			stack.pop_back();
		}
		cout << endl;
		return true;
	}
	else if (choice == 3) {
		cout << endl;
		display(stack);
		cout << endl;
		return true;
	}
	else {
		return false;
	}
}

void display(vector<string> stack) {
	cout << "Stack Elements:";
	for (int i = 0; i < stack.size(); i++) {
		cout << " " << stack.at(i);
	}
	cout << endl;
}

void validate(string& val) {
	// makes sure string is 2 characters
	if (val.length() > 2) {
		val = val.substr(0, 2);
	}
	else if (val.length() == 1)
	{
		val = val + ' ';
	}

	// changes value to uppercase or space
	for (int i = 0; i < val.length(); i++) {
		if (!isalpha(val.at(i))) {
			val.at(i) = ' ';
		}
		else {
			val.at(i) = toupper(val.at(i));
		}
	}
}