// Leetcode #3

#include <iostream>
#include <string>
#include <vector>
#include <random>

using namespace std;

string longestNRCS (string &str) {
    int n = str.length ();

    if (n <= 1) {
        return str;     // Too short!
    }

    // Create an array (vector) recording "last occurrence position" of a character. Initialized to -1.
    // Assume ASCII encoding
    vector<int> visited (256, -1);

    int max_len = 0;
    int curr_len = 0;
    int max_ll = 0; // left bound of max substring
    int ll = 0;
    int rr = 0;

    while (rr < n) {
        int ch = (int) str[rr];
        int prev = visited[ch];

        if (prev == -1 || prev < ll) {
            // ch is unique in current substring
            curr_len++;
            if (curr_len > max_len) {
                max_len = curr_len;
                max_ll = ll;
            }
        }
        else {
            // ch repeated in current substring
            ll = prev + 1;
            curr_len = rr - ll + 1;
        }

        visited[ch] = rr;
        rr++;
    }

    return str.substr (max_ll, max_len);
}


int main () {
    int n;
    random_device rd;
    uniform_int_distribution<int> dist (0, 25);

    cout << "Length of string: ";
    cin >> n;

    string myStr (n, 0);
    for (int i = 0 ; i < n ; i++) { myStr[i] = 'a' + dist (rd); }

    cout << "The input string: " << endl;
    cout << myStr << endl;

    string nrcs = longestNRCS (myStr);

    cout << "Longest Non-Repetitive Character String (NRCS):" << endl;
    cout << nrcs << endl;
    cout << "Length of longest NRCS = " << nrcs.length () << endl;
}
