#include <iostream>
#include <string>
using namespace std;

class CallStack {
private:
    string calls[10];
    int top;

public:
    CallStack() {
        top = -1;
        cout << "Phone started. No calls" << endl;
    }

    void addCall(string name) {
        cout << "\nIncoming call from " << name << endl;
        
        if(top >= 9) {
            cout << "Cannot answer. Call log full" << endl;
            return;
        }
        
        top++;
        calls[top] = name;
        cout << name << " added to calls" << endl;
        cout << "Total calls: " << (top + 1) << endl;
    }

    void endCall() {
        cout << "\nEnding call..." << endl;
        
        if(top < 0) {
            cout << "No call to end" << endl;
            return;
        }
        
        cout << "Call with " << calls[top] << " ended" << endl;
        top--;
        
        if(top >= 0) {
            cout << "Now talking to " << calls[top] << endl;
        } else {
            cout << "No more calls" << endl;
        }
    }

    void currentCall() {
        if(top < 0) {
            cout << "No active call" << endl;
            return;
        }
        cout << "Current call: " << calls[top] << endl;
    }

    void checkEmpty() {
        if(top < 0) {
            cout << "No calls in log" << endl;
        } else {
            cout << "Calls in log: " << (top + 1) << endl;
        }
    }

    void showAll() {
        if(top < 0) {
            cout << "Call log empty" << endl;
            return;
        }
        
        cout << "\nCall History:" << endl;
        for(int i = 0; i <= top; i++) {
            cout << (i + 1) << ". " << calls[i] << endl;
        }
    }
};

int main() {
    CallStack phone;
    int ch;
    string name;
    
    cout << "\nPHONE CALL SIMULATOR" << endl;
    
    do {
        cout << "\n1. New Call" << endl;
        cout << "2. End Call" << endl;
        cout << "3. Current Call" << endl;
        cout << "4. Check Empty" << endl;
        cout << "5. Show All" << endl;
        cout << "0. Exit" << endl;
        cout << "Choice: ";
        cin >> ch;
        
        if(ch == 1) {
            cout << "Enter caller name: ";
            cin >> name;
            phone.addCall(name);
        }
        else if(ch == 2) {
            phone.endCall();
        }
        else if(ch == 3) {
            phone.currentCall();
        }
        else if(ch == 4) {
            phone.checkEmpty();
        }
        else if(ch == 5) {
            phone.showAll();
        }
        
    } while(ch != 0);
    
    cout << "Phone off" << endl;
    return 0;
}