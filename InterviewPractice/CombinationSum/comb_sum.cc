#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <cstdio>
#include <ctime>

using namespace std;

void solveCombSum (vector<int> &seq, vector<int> &partial, int partial_sum, int target, int offset) {
    if (partial_sum > target) {
        return;
    }
    
    else if (partial_sum == target) {
        printf ("%d = ", target);
        for (int i = 0 ; i < partial.size () ; i++) {
            printf ("%d", partial[i]);
            if (i < partial.size () - 1) {
                printf (" + ");
            }
            else {
                printf ("\n");
            }
        }
    }
        
    else {
        for (int i = offset ; i < seq.size () ; i++) {
            partial.push_back (seq[i]);
            solveCombSum (seq, partial, partial_sum + seq[i], target, i);
            partial.pop_back (); // backtrack
        }
    }
}

int myrandom (int i) { return rand () % i; }

int main (int argc, char *argv[]) {
    srand (time (NULL));
    
    int n, hi, target;
    
    cout << "# of unique positive integers in sequence: ";
    cin >> n;
    cout << "Range of unique positive integers [1..hi], hi >= n: ";
    cin >> hi;
    cout << "Sum target: ";
    cin >> target;
    
    if (hi < n) {
        return 1;
    }
    
    vector<int> choose_array;
    for (int i = 1 ; i <= hi ; i++) {
        choose_array.push_back (i);
    }
    random_shuffle (choose_array.begin (), choose_array.end (), myrandom);
    
    vector<int> seq (choose_array.begin (), choose_array.begin () + n);
    vector<int> partial;
    
    cout << "The sequence: ";
    for (int i = 0 ; i < seq.size () ; i++) {
        cout << seq[i] << " ";
    }
    cout << endl;
    
    
    solveCombSum (seq, partial, 0, target, 0);    
    
    return 0;
}