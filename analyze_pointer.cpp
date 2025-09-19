#include <iostream>

using namespace std;

void analyze_pointer(int* ptr)
{
    // Print the address
    cout << "The address pointed to by the pointer is: " << ptr << endl;
    // Print the value of the integar pointed to
    cout << "The value of the integar being pointed to: " << *ptr << endl;
}

int main() 
{
    int iValue = 7;     // Create an int with value 7
    int *iptr = new int(10);

    // Pass iValue's address to the function
    analyze_pointer(&iValue);
    // Pass the second variable to the function
    analyze_pointer(iptr);

    delete iptr;        // Free the allocated memory
    return 0;
}