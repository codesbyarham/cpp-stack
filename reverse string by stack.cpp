#include <iostream>
#include <string>
using namespace std;

class CharStack {
private:
    char items[100];
    int top;

public:
    CharStack() {
        top = -1;
    }

    void push(char c) {
        if(top < 99) {
            top++;
            items[top] = c;
        }
    }

    char pop() {
        if(top >= 0) {
            char c = items[top];
            top--;
            return c;
        }
        return ' ';
    }

    bool isEmpty() {
        return top < 0;
    }
};

int main() {
    string word;
    
    cout << "REVERSE STRING PROGRAM" << endl;
    cout << "Enter a word: ";
    getline(cin, word);
    
    CharStack s;
    
    for(int i = 0; i < word.length(); i++) {
        s.push(word[i]);
    }
    
    string rev = "";
    while(!s.isEmpty()) {
        rev = rev + s.pop();
    }
    
    cout << "Original: " << word << endl;
    cout << "Reversed: " << rev << endl;
    
    return 0;
}