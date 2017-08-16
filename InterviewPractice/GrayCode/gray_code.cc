// Leetcode #89

#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> grayCode_num (int n) {
    vector<int> ret;

    if (n < 1){
        return ret;
    }

    if (n == 1) {
        ret.push_back (0);
        ret.push_back (1);
        return ret;
    }

    else {
        vector<int> base = grayCode_num (n - 1);

        for (int i = 0 ; i < base.size () ; i++) {
            ret.push_back (base[i]);
        }

        for (int i = base.size () - 1 ; i >= 0 ; i--) {
            ret.push_back ( (1 << (n - 1)) | base[i]);
        }
    }

    return ret;
}

vector<string> grayCode_str (int n) {
    vector<string> ret;

    if (n < 1) {
        return ret;
    }

    if (n == 1) {
        ret.push_back ("0");
        ret.push_back ("1");
        return ret;
    }

    else {
        vector<string> base = grayCode_str (n - 1);

        for (int i = 0 ; i < base.size () ; i++) {
            ret.push_back ("0" + base[i]);
        }

        for (int i = base.size() - 1 ; i >= 0 ; i--) {
            ret.push_back ("1" + base[i]);
        }
    }

    return ret;
}

int main () {
    int n;
    cout << "Input n: ";
    cin >> n;

    vector<string> gcs = grayCode_str (n);

    cout << "Gray Code of " << n << " bits (represented in strings):" << endl;
    for (int i = 0 ; i < gcs.size () ; i++) {
        cout << gcs[i] << endl;
    }
    cout << "A total of " << gcs.size () << " codes." << endl;

    cout << endl;
  
    vector<int> gcn = grayCode_num (n);

    cout << "Gray Code of " << n << " bits (represented in integers):" << endl;
    for (int i = 0 ; i < gcn.size () ; i++) {
        cout << gcn[i] << endl;
    }
    cout << "A total of " << gcn.size () << " codes." << endl;

}
