#include <iostream>
#include <stack>
#include <string>

using namespace std;

// Special function for this implementation
char popStack(stack<char> &stk) 
{
    char temp = stk.top();
    stk.pop();
    return temp;
}

int main() 
{
    string input;
    stack<char> stk;

    cout << "Enter a string to reverse: ";
    getline(cin, input);       // Read one full line (including spaces)

    // Traverse the string and push each character onto the stack
    for (int i = 0; i < input.size(); i++) 
    {
        char curr = input[i];
        int position = i + 1;
        stk.push(curr);
    }

    string reversed;
    while (!stk.empty()) {      // Pop characters to construct the reversed string
        char top = popStack(stk);
        reversed.push_back(top);
    }

    // Display original and reversed string
    cout << "Original: " << input << endl;
    cout << "Reversed: " << reversed << endl;

    return 0;
}
