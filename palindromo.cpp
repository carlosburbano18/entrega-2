#include <iostream>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false; 

        int original = x;
        long reversed = 0;

        while (x > 0) {
            int digit = x % 10;        
            reversed = reversed * 10 + digit; 
            x /= 10;                   
        }

        return original == reversed; 
    }
};

int main() {
    Solution sol;
    int num;

    cout << "Ingresa un numero: ";
    cin >> num;

    if (sol.isPalindrome(num)) {
        cout << num << " es un palindromo" << endl;
    } else {
        cout << num << " no es un palindromo" << endl;
    }

    return 0;
}
