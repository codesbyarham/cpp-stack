#include <iostream>
#include <string>
using namespace std;

class Stack {
private:
    char arr[100];
    int top;

public:
    Stack() {
        top = -1;
    }

    void push(char c) {
        if(top < 99) {
            top++;
            arr[top] = c;
        }
    }

    void pop() {
        if(top >= 0) {
            top--;
        }
    }

    bool isEmpty() {
        return top < 0;
    }
};

int main() {
    string exp;
    
    cout << "BALANCED PARENTHESES CHECKER" << endl;
    cout << "Enter expression: ";
    getline(cin, exp);
    
    Stack s;
    bool balanced = true;
    
    for(int i = 0; i < exp.length(); i++) {
        if(exp[i] == '(') {
            s.push('(');
            cout << "Found (, pushing to stack" << endl;
        }
        else if(exp[i] == ')') {
            if(s.isEmpty()) {
                cout << "Found ) but stack is empty" << endl;
                balanced = false;
                break;
            } else {
                s.pop();
                cout << "Found ), popping one (" << endl;
            }
        }
    }
    
    if(balanced && s.isEmpty()) {
        cout << "\nResult: Balanced" << endl;
        cout << "All brackets match" << endl;
    } else {
        cout << "\nResult: Not Balanced" << endl;
        cout << "Brackets don't match" << endl;
    }
    
    return 0;
}