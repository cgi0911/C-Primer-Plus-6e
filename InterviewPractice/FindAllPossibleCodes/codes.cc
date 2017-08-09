#include <iostream>
#include <string>

using namespace std;

int parseNumString (string code, string partial)
{
    int slen = partial.length ();
    
    if (slen == 0) {
        // Reached end of string
        cout << code << endl;
        return 1;
    }
    
    if (partial[0] == '0') {
        return 0;   // No code starting with '0'
    }
    
    int a = 0;
    int b = 0;
    
    // Parse 1 numeric character
    if (slen >= 1) {
        int onedigit = partial[0] - '1' + 1;
        char codechar = onedigit + 'a' + 1;
        a = parseNumString (code + codechar, partial.substr (1));
    }
    
    // Parse 2 numeric characters
    if (slen >= 2) {
        int twodigit = stoi (partial.substr(0, 2));
        if (1 <= twodigit && twodigit <= 26) {
            char codechar = twodigit + 'a' - 1;
            b = parseNumString (code + codechar, partial.substr (2));
        }
    }
    
    return a + b;
}


int findAllPossibleCodes (string numstr) {
    int slen = numstr.length ();
    
    if (slen == 0) {
        cout << "Empty string!" << endl;
        return 0;
    }
    
    else {
        return (parseNumString ("", numstr));
    }
}


int main (int argc, char *argv[]) {
    string num;
    cout << "Enter a numeric string: ";
    cin >> num;
    
    cout << "Finding all possible alphabet codes out of numeric string " << num << endl;
    
    int n_codes = findAllPossibleCodes (num);
    
    
    cout << "There are a total of " << n_codes << " possible codes." << endl;
}