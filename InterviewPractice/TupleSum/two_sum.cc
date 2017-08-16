// Leetcode #1

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <random>
#include <utility>

using namespace std;

namespace std
{
    template<>
    struct hash<std::pair<int, int> >
    {
        size_t operator () (std::pair<int, int> const& p)
        {
            // A bad example of computing the hash, 
            // rather replace with something more clever
            return (std::hash<int>()(p.first) + std::hash<int>()(p.second));
        }
    };
}

int two_sum_hash_dedup (vector<int> arr) {
    // Given an array, return all possible 2-tuples summing up to zero
    // Hash-based computation, no duplicated output (in terms of values)
    int n = 0;
    
    unordered_map<int, vector<int> > numidx;
    vector<int> unique;
    
    for (int i = 0 ; i < arr.size () ; i++) {
        int num = arr[i];
        if (numidx.find (num) == numidx.end ()) {
            numidx[num] = vector<int> (1, i);
            unique.push_back (num);
        }
        else {
            numidx[num].push_back (i);
        }
    }
    
    for (int i = 0 ; i < unique.size () ; i++) {
        int num1 = unique[i];
        int num2 = 0 - num1;
        
        if (numidx.find (num2) == numidx.end ()) {
            continue;   // Not found
        }
        
        else {
            if (num1 == num2) {
                if (numidx[num1].size () > 1) {
                    cout << "Index{" << numidx[num1][0] << ", " << numidx[num1][1] << "} -> ";
                    cout << "SUM{" << num1 << ", " << num2 << "} = 0" << endl;
                    n++;
                }
            }
            else {
                if (numidx[num2][0] > numidx[num1][0]) {
                    // Ensure no duplicated outputs
                    cout << "Index{" << numidx[num1][0] << ", " << numidx[num2][0] << "} -> ";
                    cout << "SUM{" << num1 << ", " << num2 << "} = 0" << endl;
                    n++;
                }
            }
        }
    }
    
    return n;
}

int two_sum_bf_dedup (vector<int> arr) {
    // Given an array, return all possible 2-tuples summing up to zero
    // Brute-force computation, use an unordered set to de-dup
    // The time complexity is O(n^2)
    int n = 0;
    
    unordered_set<pair<int, int> > used;
    
    for (int i = 0 ; i < arr.size () ; i++) {
        for (int j = 0 ; j < arr.size () ; j++) {
            if (i == j) {
                continue;
            }
            else {
                if (arr[i] + arr[j] == 0) {
                    pair<int, int> temp;
                    if (arr[i] <= arr[j]) {
                        temp = make_pair (arr[i], arr[j]);
                    }
                    else {
                        temp = make_pair (arr[j], arr[i]);
                    }
                    
                    if (used.find (temp) == used.end ()) {
                        // Not duplicate
                        used.insert (temp);
                        cout << "Index{" << i << ", " << j << "} -> ";
                        cout << "SUM{" << get<0> (temp) << ", " << get<1> (temp) << "} = 0" << endl;
                        n++;
                    }
                }
            }
        }
    }
    
    return n;
}

int two_sum_bf_nodedup (vector<int> arr) {
    // Given an array, return all possible 2-tuples summing up to zero
    // Brute-force computation
    // May print out duplicating tuples
    // The time complexity is O(n^2)
    int n = 0;
    
    for (int i = 0 ; i < arr.size () ; i++) {
        for (int j = 0 ; j < arr.size () ; j++) {
            if (i == j) {
                continue;
            }
            else {
                if (arr[i] + arr[j] == 0) {
                    cout << "Index{" << i << ", " << j << "} -> ";
                    cout << "SUM{" << arr[i] << ", " << arr[j] << "} = 0" << endl;
                    n++;
                }
            }
        }
    }
    
    return n;
}

void print_vector (vector<int> arr) {
    for (vector<int>::iterator it = arr.begin () ; it != arr.end () ; it++) {
        cout << *it << " ";
    }
    cout << endl;
}

int main (int argc, char *argv[]) {
    int n;
    int lo, hi;
    vector<int> arr;
    
    cout << "Input # of integers: ";
    cin >> n;
    cout << "Input range [lo, hi]: ";
    cin >> lo >> hi;
    
    random_device rd;   
    mt19937 mt(rd ());  // Use a random number to seed the mt19937 engine
    uniform_int_distribution<int> dist(lo, hi);
    
    for (int i = 0 ; i < n ; i++) {
        arr.push_back (dist (mt));
    }
    
    print_vector (arr);
    
    int nn = two_sum_bf_dedup (arr);
    
    cout << "A total of " << nn << " tuples sum up to zero." << endl;
}
