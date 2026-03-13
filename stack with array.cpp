#include <iostream>
using namespace std;

class Stack {
private:
    int arr[5];
    int top;

public:
    Stack() {
        top = -1;
    }

    void push(int x) {
        if(top >= 4) {
            cout << "Error: Stack is full. Cannot push " << x << endl;
            return;
        }
        top++;
        arr[top] = x;
        cout << x << " added to stack" << endl;
    }

    void pop() {
        if(top < 0) {
            cout << "Error: Stack is empty. Cannot pop" << endl;
            return;
        }
        cout << arr[top] << " removed from stack" << endl;
        top--;
    }

    void peek() {
        if(top < 0) {
            cout << "Stack is empty" << endl;
            return;
        }
        cout << "Top element: " << arr[top] << endl;
    }

    void checkEmpty() {
        if(top < 0) {
            cout << "Stack is empty" << endl;
        } else {
            cout << "Stack is not empty" << endl;
        }
    }

    void checkFull() {
        if(top >= 4) {
            cout << "Stack is full" << endl;
        } else {
            cout << "Stack is not full" << endl;
        }
    }

    void show() {
        if(top < 0) {
            cout << "Stack is empty" << endl;
            return;
        }
        cout << "Stack: ";
        for(int i = 0; i <= top; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Stack s;
    int choice, val;

    cout << "STACK PROGRAM" << endl;
    cout << "Stack size is 5" << endl;

    do {
        cout << "\n1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Peek" << endl;
        cout << "4. Check Empty" << endl;
        cout << "5. Check Full" << endl;
        cout << "6. Display" << endl;
        cout << "7. Show Overflow" << endl;
        cout << "8. Show Underflow" << endl;
        cout << "0. Exit" << endl;
        cout << "Choice: ";
        cin >> choice;

        if(choice == 1) {
            cout << "Enter number: ";
            cin >> val;
            s.push(val);
        }
        else if(choice == 2) {
            s.pop();
        }
        else if(choice == 3) {
            s.peek();
        }
        else if(choice == 4) {
            s.checkEmpty();
        }
        else if(choice == 5) {
            s.checkFull();
        }
        else if(choice == 6) {
            s.show();
        }
        else if(choice == 7) {
            cout << "\nTrying to push 6 items:" << endl;
            for(int i = 1; i <= 6; i++) {
                cout << "Pushing " << i << "... ";
                s.push(i);
            }
        }
        else if(choice == 8) {
            cout << "\nTrying to pop from empty stack:" << endl;
            Stack temp;
            temp.pop();
        }
        else if(choice == 0) {
            cout << "Bye!" << endl;
        }
        else {
            cout << "Wrong choice" << endl;
        }
    } while(choice != 0);

    return 0;
}