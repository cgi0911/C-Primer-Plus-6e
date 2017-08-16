// Leetcode #8
#include <iostream>
#include <string>
#include <climits>

using namespace std;

int myAtoI (string str) {
    long int ret = 0;
    int slen = str.length ();
    int pos = 0;
    int sign = 1;

    if (slen == 0) {
        return (int) ret; // Return 0 for empty string
    }

    // Remove leading white space
    while (str[pos] == ' ') {
        pos++;
        if (pos >= slen) {
            return (int) ret;     // All-white space, return zero
        }
    }

    // Parse an optional '+' or '-'
    if (str[pos] == '+') {
        pos++;
    }

    else if (str[pos] == '-') {
        sign = -1;
        pos++;
    }

    // Now start to parse the numerical string. Stop whenever a non-numerical char is encountered
    while (str[pos] <= '9' && str[pos] >= '0') {
        ret = ret * 10 + (str[pos] - '0');

        // Handle overflow/underflow cases
        // Overflow will result in return of INT_MAX, while underflow returns INT_MIN.
        if (sign == 1 && ret > INT_MAX) {
            return INT_MAX;
        }

        else if (sign == -1 && -1 * ret < INT_MIN) {
            return INT_MIN;
        }

        pos++;
        if (pos >= slen) {
            break;
        }
    }
    
    ret *= sign;
    return (int) ret;
}

int main () {
    string myStr;

    cout << "Input a numeric string: ";
    cin >> myStr;

    int num = myAtoI (myStr);
    cout << "Converted result: " << num << endl;
}
