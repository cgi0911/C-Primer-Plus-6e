// Leetcode #78

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void choose (vector<int> &arr, int st, vector<int> partial, vector<vector<int> > &res) {
    int n = arr.size ();
    partial.push_back (arr[st]);
    res.push_back (partial);

    for (int i = st + 1 ; i < n ; i++) {
        choose (arr, i, partial, res);   
    }
}

vector<vector<int> > allSubsets (vector<int> &arr) {
    int n = arr.size ();
    vector<vector<int> > res;
    sort (arr.begin (), arr.end ());

    vector<int> partial;

    for (int i = 0 ; i < n ; i++){
        choose (arr, i, partial, res);
    }

    return res;
}

int main() {
    vector<int> arr = {1, 3, 2, 5, 4};

    vector<vector<int> > res = allSubsets (arr);

    for (int i = 0 ; i < res.size () ; i++) {
        cout << "[";
        for (int j = 0 ; j < res[i].size () ; j++) {
            cout << res[i][j] << ", ";
        }
        cout << "]" << endl;
    }
}
