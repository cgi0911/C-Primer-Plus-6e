#include <iostream>
#include <vector>
#include <random>
#include <utility>
#include <algorithm>

using namespace std;

vector<int> amazingNumbers (vector<int> arr) {
    vector<int> res;
    int max = 0;
    int n = arr.size ();
    
    vector<int> int_st;
    vector<int> int_ed;
        
    for (int i = 0 ; i < n ; i++) {
        if (arr[i] >= n) {
            continue;
        }
        
        else if (arr[i] <= 0) {
            int_st.push_back (-1 * (n - 1));
            int_ed.push_back (n - 1);
            continue;
        }
        
        else if (arr[i] < n) {
            int_st.push_back (arr[i] - i);
            int_ed.push_back (n - 1 - i);
        }
    }    
    
    cout << "Interval starts: ";
    for (int i = 0 ; i < int_st.size () ; i++) {
        cout << int_st[i] << " ";
    }
    cout << endl;
    
    
    cout << "Interval ends:   ";
    for (int i = 0 ; i < int_ed.size () ; i++) {
        cout << int_ed[i] << " ";
    }
    cout << endl;
    
    // Now scan through the intervals
    sort (int_st.begin (), int_st.end ());
    sort (int_ed.begin (), int_ed.end ());
    int s = 0;  // index of int_st
    int t = 0;  // index of int_ed
    int curr_amazing = 0;
    int amazing_st = -1 * n;
    int amazing_ed = -1 * n;
        
    while (s < int_st.size () || t < int_ed.size ()) {        
        if (s < int_st.size () && int_st[s] <= int_ed[t]) {
            curr_amazing ++;
            if (curr_amazing > max) {
                amazing_st = int_st[s];
                max = curr_amazing;
            }
            s++;            
        }
        
        else {
            // s >= t
            if (curr_amazing == max) {
                amazing_ed = int_ed[t];                
            }
            curr_amazing --;
            t++;
        }
    }
    
    res.push_back (amazing_st);
    res.push_back (amazing_ed);
    res.push_back (max);
    
    return res;
}


int main (int argc, char *argv[]) {
    int n, lo, hi;
    
    cout << "# of integers in the seq: ";
    cin >> n;
    cout << "Range of integers [lo..hi]: ";
    cin >> lo >> hi;
    
    random_device rd;
    uniform_int_distribution<int> dist(lo, hi);
    vector<int> arr;
    
    for (int i = 0 ; i < n ; i++) {
        arr.push_back (dist (rd));
    }
    
    cout << "The sequence:" << endl;
    for (int i = 0 ; i < n ; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    vector<int> res = amazingNumbers (arr);
    
    cout << "Max # of amazing numbers = " << res[2] << endl;
    cout << "The interval is (" << res[0] << ", " << res[1] << ")" << endl;
    
    return 0;
    
}