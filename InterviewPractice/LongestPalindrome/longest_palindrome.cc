// Leetcode #5

#include <iostream>
#include <string>
#include <utility>

using namespace std;

pair<int, int> extendPalindrome (const string& str, int st, int ed) {
    int n = str.length ();

    // Border reached
    if (st == 0 || ed == n - 1) {
        return make_pair (st, ed);
    }

    if (str[st - 1] != str[ed + 1]) {
        return make_pair (st, ed);
    }
    else {
        return extendPalindrome (str, st - 1, ed + 1);
    }
}


string longestPalindrome (const string &str) {
    int n = str.length ();
    if (n <= 1) {
        return str;
    }

    int maxlen = 1; // By default, the longest palidrome is set to [0, 0]
    pair<int, int> longest = make_pair (0, 0);

    for (int i = 0 ; i < n - 1 ; i++) {
        pair<int, int> temp;

        temp = extendPalindrome (str, i, i);
        if (temp.second - temp.first + 1 > maxlen) {
            maxlen = temp.second - temp.first + 1;
            longest = temp;
        }

        if (str[i] == str[i+1]) {
            temp = extendPalindrome (str, i, i+1);
            if (temp.second - temp.first + 1 > maxlen) {
                maxlen = temp.second - temp.first + 1;
                longest = temp;
            }
        }
    }

    return str.substr (longest.first, longest.second - longest.first + 1);
}


int main () {
    string myStr;

    cout << "Input string: ";
    cin >> myStr;

    string lp = longestPalindrome (myStr);

    cout << "Longest palindrome contained: " << lp << endl;
}
