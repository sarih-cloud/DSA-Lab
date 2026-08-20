/**
 * Recursion Examples in C++
 * Includes: Factorial, Fibonacci, Tower of Hanoi, Binary Search
 * Demonstrates recursive thinking and problem-solving
 */

#include <iostream>
#include <vector>
using namespace std;

class RecursionExamples {
public:
    // Factorial - O(n)
    long long factorial(int n) {
        if (n == 0 || n == 1) return 1;
        return n * factorial(n - 1);
    }
    
    // Fibonacci - O(2^n) naive, can be optimized with memoization
    long long fibonacci(int n) {
        if (n <= 1) return n;
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
    
    // Tower of Hanoi - O(2^n)
    void towerOfHanoi(int n, char from_rod, char to_rod, char aux_rod) {
        if (n == 1) {
            cout << "Move disk 1 from rod " << from_rod << " to rod " << to_rod << endl;
            return;
        }
        towerOfHanoi(n - 1, from_rod, aux_rod, to_rod);
        cout << "Move disk " << n << " from rod " << from_rod << " to rod " << to_rod << endl;
        towerOfHanoi(n - 1, aux_rod, to_rod, from_rod);
    }
    
    // Binary Search Recursive - O(log n)
    int binarySearch(const vector<int>& arr, int target, int left, int right) {
        if (left > right) return -1;
        
        int mid = left + (right - left) / 2;
        
        if (arr[mid] == target) return mid;
        else if (arr[mid] < target) return binarySearch(arr, target, mid + 1, right);
        else return binarySearch(arr, target, left, mid - 1);
    }
    
    // Sum of digits - O(d) where d is number of digits
    int sumOfDigits(int n) {
        if (n == 0) return 0;
        return (n % 10) + sumOfDigits(n / 10);
    }
    
    // GCD using Euclidean algorithm - O(log(min(a,b)))
    int gcd(int a, int b) {
        if (b == 0) return a;
        return gcd(b, a % b);
    }
    
    // Power calculation - O(n)
    double power(double base, int exponent) {
        if (exponent == 0) return 1;
        if (exponent < 0) return 1 / power(base, -exponent);
        return base * power(base, exponent - 1);
    }
};

void demoRecursion() {
    cout << "=== RECURSION EXAMPLES DEMONSTRATION ===" << endl;
    
    RecursionExamples rec;
    
    // Factorial demonstration
    cout << "Factorials:" << endl;
    for (int i = 0; i <= 10; i++) {
        cout << i << "! = " << rec.factorial(i) << endl;
    }
    cout << endl;
    
    // Fibonacci demonstration
    cout << "Fibonacci Sequence:" << endl;
    for (int i = 0; i <= 10; i++) {
        cout << "F(" << i << ") = " << rec.fibonacci(i) << endl;
    }
    cout << endl;
    
    // Tower of Hanoi
    cout << "Tower of Hanoi for 3 disks:" << endl;
    rec.towerOfHanoi(3, 'A', 'C', 'B');
    cout << endl;
    
    // Binary Search
    vector<int> arr = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    int target = 11;
    int result = rec.binarySearch(arr, target, 0, arr.size() - 1);
    cout << "Binary Search for " << target << ": " 
         << (result != -1 ? "Found at index " + to_string(result) : "Not found") << endl;
    cout << endl;
    
    // Sum of digits
    int number = 12345;
    cout << "Sum of digits of " << number << " = " << rec.sumOfDigits(number) << endl;
    
    // GCD
    int a = 48, b = 18;
    cout << "GCD of " << a << " and " << b << " = " << rec.gcd(a, b) << endl;
    
    // Power
    double base = 2.0;
    int exponent = 8;
    cout << base << "^" << exponent << " = " << rec.power(base, exponent) << endl;
    
    cout << "=== END DEMONSTRATION ===" << endl << endl;
}

int main() {
    demoRecursion();
    return 0;
}