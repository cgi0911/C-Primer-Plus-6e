#include <iostream>
#include <vector>
#include <string>
#include <random>

using namespace std;

int pattern_match_kmp (const string &str, const string &pat) {
    // Knuth-Morris-Pratt Algorithm
    int sl = str.length ();
    int pl = pat.length ();
    
    if (sl == 0 || pl == 0 || sl < pl) {
        return 0;
    }
    
    int pos = 0;
    int idx = 0;
    
}

int main () {    
    int n, p;
    
    cout << "String length = ";
    cin >> n;
    cout << "Pattern length = ";
    cin >> p;
    
    random_device rd;
    uniform_int_distribution<int> dist (0, 25);
    
    char str_c[n + 1];
    char str_p[p + 1];
    
    for (int i = 0 ; i < n ; i++) {
        str_c[i] = 'a' + dist (rd);
    }
    str_c[n] = 0;
    
    for (int i = 0 ; i < p ; i++) {
        str_p[i] = 'a' + dist (rd);
    }
    str_p[p] = 0;
    
    string str (str_c);
    string pat (str_p);    
    
    cout << "String: " << str << endl;
    cout << "Pattern: " << pat << endl;
    
    int first_occur = pattern_match (str, pat);
    
    cout << "First occurrence at position " << first_occur << "." << endl;
}