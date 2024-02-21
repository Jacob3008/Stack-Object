// Jacob Neuman 2/21/24

#pragma once
#include <vector>
#include <iostream>

using namespace std;

class Stack {
private:
    vector<string> elements;
public:
    void push(string);
    void pop();
    void display();
    void validate(string&);
};

void Stack::push(string val) {
    // bi-gramify and push to vector
    validate(val);
    elements.push_back(val);
}

void Stack::pop() {
    // check vector isnt empty
    if (elements.empty()) {
        cout << "error, underflow" << endl;
    }
    // pop last value
    else {
        cout << "Popped: " << elements.back() << endl;
        elements.pop_back();
    }
}

void Stack::display() {
    // display all stack elements
    cout << "Stack Elements:";
    for (int i = 0; i < elements.size(); i++) {
        cout << " " << elements.at(i);
    }
    cout << endl;
}

void Stack::validate(string& val) {
    // makes sure string is 2 characters
    if (val.length() > 2) {
        val = val.substr(0, 2);
    }
    // add space if length is 1 character
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