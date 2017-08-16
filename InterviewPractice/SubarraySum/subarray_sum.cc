#include <iostream>
#include <vector>
#include <unordered_map>
#include <random>
#include <utility>

using namespace std;

pair<int, int> findSubarray (const vector<int> arr, int k) {
    // Find the first subarray arr[a..b] which sums up to k.
    // Subarray is a continuous segment of the original array.
    // "First" subarray is defined as having minimal a.

    int n  = arr.size ();
    unordered_map<int, vector<int> > seg;

    // Create an mapping from partial sum to segment size
    int sum = 0;
    for (int i = 0 ; i < n ; i++) {
        sum += arr[i];
        seg[sum].push_back (i);
        //cout << "Segment [0.." << i << "] sums up to " << sum << endl;
    }

    /*
    for (unordered_map<int, vector<int> >::iterator it = seg.begin () ; it != seg.end () ; it++) {
        cout << it->first << ": {";
        for (vector<int>::iterator itt = it->second.begin () ; itt != it->second.end () ; itt++) {
            cout << *itt << " ";
        }
        cout << "}" << endl;
    }
    */

    // Now scan
    sum = 0;
    for (int i = -1 ; i < n - 1 ; i++) {
        if (seg.find (k + sum) != seg.end ()) {
            for (int j = 0 ; j < seg[k + sum].size () ; j++) {
                if (seg[k + sum][j] > i) {
                    return make_pair (i + 1, seg[k + sum][j]);
                }
            }
        }
        sum += arr[i+1];
    } 

    return make_pair (-1, -1);
}


int main () {
    random_device rd;
    uniform_int_distribution<int> dist (-10, 10);

    vector<int> arr;
    for (int i = 0 ; i < 20 ; i++) {
        arr.push_back (dist (rd));
    }

    cout << "The array:" << endl;
    for (int i = 0 ; i < 20 ; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    pair<int, int> res = findSubarray (arr, 10);
    
    cout << "Result:" << res.first << ", " << res.second << endl;
}
