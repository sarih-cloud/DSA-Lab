#include <iostream>
#include <stack>
using namespace std;

// A simple OOP class for a rod in Tower of Hanoi
class Rod 
{
public:
    char name;
    stack<int> s;

    Rod(char name) 
    {
        this->name = name;
    }

    bool empty() const { return s.empty(); }
    int top() const { return s.top(); }

    void pushDisk(int d) 
    {
        s.push(d);
        cout << "[OPERATION] Pushed disk " << d << " on " << name << '\n';
    }

    int popDisk() 
    {
        int d = s.top();
        s.pop();
        cout << "[OPERATION] Popped disk " << d << " from " << name << '\n';
        return d;
    }
};

// Move one legal disk between two rods (handles empties and size rule)
void moveBetween(Rod &a, Rod &b) 
{
    if (a.empty() && b.empty()) 
    {
        cout << "[ERROR] Both rods empty. No legal move.\n";
        return;
    }
    if (a.empty()) 
    {
        int d = b.popDisk();
        a.pushDisk(d);
        cout << "Move disk " << d << " from " << b.name << " \u2192 " << a.name << '\n';
        return;
    }
    if (b.empty()) 
    {
        int d = a.popDisk();
        b.pushDisk(d);
        cout << "Move disk " << d << " from " << a.name << " \u2192 " << b.name << '\n';
        return;
    }
    if (a.top() < b.top()) 
    {
        int d = a.popDisk();
        b.pushDisk(d);
        cout << "Move disk " << d << " from " << a.name << " \u2192 " << b.name << '\n';
    } 
    else 
    {
        int d = b.popDisk();
        a.pushDisk(d);
        cout << "Move disk " << d << " from " << b.name << " \u2192 " << a.name << '\n';
    }
}

int main() {
    int n;
    cin >> n;                     // simplest input: just the number of disks

    Rod A('A'), B('B'), C('C');   // A = source, B = auxiliary, C = destination

    // Initialize source rod A with disks n..1 (largest at bottom)
    for (int d = n; d >= 1; d--) 
    {
        A.pushDisk(d);
        cout << "[INIT] Placed disk " << d << " on " << A.name << '\n';
    }

    if (n <= 0) 
    {
        cout << "[SUCCESS] Nothing to move.\n";
        return 0;
    }

    long long totalMoves = (1LL << n) - 1;   // 2^n - 1
    cout << "[COMPUTE] Total moves = " << totalMoves << '\n';

    // Iterative solution:
    // If n is even, swap roles of auxiliary and destination rods
    Rod *src = &A, *aux = &B, *dest = &C;
    if (n % 2 == 0) 
    {
        cout << "[INFO] n is even \u2192 swapping roles of B and C\n";
        Rod *tmp = aux; aux = dest; dest = tmp;
    }

    for (long long i = 1; i <= totalMoves; ++i) 
    {
        if (i % 3 == 1) 
        {
            cout << "[STEP] " << i << "/" << totalMoves
                 << ": Move between " << src->name << " and " << dest->name << '\n';
            moveBetween(*src, *dest);
        } 
        else if (i % 3 == 2) 
        {
            cout << "[STEP] " << i << "/" << totalMoves
                 << ": Move between " << src->name << " and " << aux->name << '\n';
            moveBetween(*src, *aux);
        } 
        else 
        { // i % 3 == 0
            cout << "[STEP] " << i << "/" << totalMoves
                 << ": Move between " << aux->name << " and " << dest->name << '\n';
            moveBetween(*aux, *dest);
        }
    }

    cout << "[SUCCESS] All disks moved from " << A.name
         << " to " << dest->name << ".\n";

    return 0;
}
