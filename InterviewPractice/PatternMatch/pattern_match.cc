#include <iostream>
#include <vector>
#include <string>
#include <random>

using namespace std;

int sub_match (const string &str, const string &pat, int idx, int pos) {
    if (idx == pat.length ()) {
        return pos;
    }
    
    else {
        if (pos + idx >= str.length ()) {
            return str.length ();
        }
        else if (str[pos + idx] != pat[idx]) {
            return str.length ();
        }
        else {
            return sub_match (str, pat, idx + 1, pos);
        }
    }
}

int pattern_match (const string &str, const string &pat) {
    if (str.length () == 0 || pat.length () == 0 || str.length () < pat.length ()) {
        return -1;
    }
    
    vector<int> init_pos;
    
    // Index the initial char
    for (int i = 0 ; i < str.length () ; i++) {
        if (str[i] == pat[0]) {
            init_pos.push_back (i);
        }
    }
    
    // Follow the index
    int first_occur = str.length ();    // Maximum + 1
    
    for (int i = 0 ; i < init_pos.size () ; i++) {
        int temp = sub_match (str, pat, 0, init_pos[i]);
        if (temp < first_occur) {
            first_occur = temp;
        }
    }
    
    if (first_occur == str.length ()) {
        return -1;
    }
    else {
        return first_occur;
    }
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