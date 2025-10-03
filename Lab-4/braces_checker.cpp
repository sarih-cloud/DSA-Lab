#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool isOpening(char c) {
    return c == '(' || c == '[' || c == '{';
}

bool isClosing(char c) {
    return c == ')' || c == ']' || c == '}';
}

char matchingClose(char open) {
    if (open == '(') return ')';
    if (open == '[') return ']';
    else if (open == '{') return '}';
    else
    {
        cout << "[WARN] No matching close found for " << open << endl;
        return 'e';
    }
}

// Special function for this implementation
char popStack(stack<char> &stk)
{
    char temp = stk.top();
    stk.pop();
    return temp;
}

int main() 
{
    string exp;
    stack<char> stk;
    cout << "Input the mathematical expression: ";
    getline(cin, exp);

    for (int i = 0; i < exp.size(); i++)
    {
        char curr = exp[i];
        int position = i+1;
        
        if (isOpening(curr)) 
        {
            stk.push(curr);     // Push any opening braces
        }
        else if (isClosing(curr))
        {
            if (stk.empty())
            {
                cout << "[StackUnderFlow ERROR] No opening braces found for " << curr << endl;
                return -1;
            }
            // Check if the top matches the
            char top = popStack(stk);
            if (curr == matchingClose(top))
            {
                cout << "[OPERATION] Matching open found for " << curr << endl;
                continue;       // For readability
            }
            else 
            {
                cout << "[BracesMisMatch ERROR] The open braces " << top;
                cout << " did not match for " << curr << " for position "; 
                cout << position << endl;  // Printing in two statements
                return -1;
            }
        }
    }

    // Check if the stack is empty after the loop
    if (!stk.empty())
    {
        cout << "[InvalidExpression ERROR] No closing braces found for:" << endl;
        while (!stk.empty())
        {
            cout << popStack(stk) << " ";
        }
        cout << endl;
        return -1;
    }

    // If all tests passed
    cout << "[SUCCESS] The expression is correct." << endl;

    return 0;
}
