// Leetcode #17
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

typedef unordered_map<char, vector<char> > PhoneKeys;

void traversal (const string &str, int pos, PhoneKeys &phone, string partial, vector<string> &results) {
    int n = str.length ();

    if (pos >= n) {
        if (partial.length () > 0) {
            results.push_back (partial);
        }
        return;
    }

    char num = str[pos];

    if (phone.find (num) == phone.end ()) {
        // Simply skip non-letter-matching chars
        traversal (str, pos + 1, phone, partial, results);
    }

    else {
        for (int i = 0 ; i < phone[num].size () ; i++) {
            traversal (str, pos + 1, phone, partial + phone[num][i], results);
        }
    }
}



vector<string> phone_letter_comb (const string &str) {
    vector<string> results;
    // Initialize a hash map from numeric char to a vector of possible letters.
    PhoneKeys phone = 
    { {'0', {' '} },
      {'2', {'a', 'b', 'c'} },
      {'3', {'d', 'e', 'f'} },
      {'4', {'g', 'h', 'i'} },
      {'5', {'j', 'k', 'l'} },
      {'6', {'m', 'n', 'o'} },
      {'7', {'p', 'q', 'r', 's'} },
      {'8', {'t', 'u', 'v'} },
      {'9', {'w', 'x', 'y', 'z'} }
    };

    traversal (str, 0, phone, "", results);

    return results;
}


int main () {
    string myStr;
    cout << "Enter a phone number: ";
    cin >> myStr;

    vector<string> res = phone_letter_comb (myStr);

    for (int i = 0 ; i < res.size () ; i++) {
        cout << res[i] << endl;
    }

    cout << "There are a total of " << res.size () << " combinations resulting from phone number " << myStr << "." << endl;
}
