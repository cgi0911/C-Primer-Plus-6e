#include <iostream>
#include <vector>
#include <random>

using namespace std;

int reorderAndCount (vector<int> &arr) {
    int n = arr.size ();
    
    if (n == 0) {
        return 0;
    }    
    
    int s = 0;
    int t = n - 1;
    
    while (s <= t) {
        if (arr[t] == 0) {
            t--;
        }

        else {
            if (arr[s] != 0) {
                s++;
            }
            
            else {
                int temp = arr[s];
                arr[s] = arr[t];
                arr[t] = temp;
                s++;
                t--;
            }
        }
    }
    
    return s;
}

int main () {
    int n;
    random_device rd;
    uniform_int_distribution<int> dist (-2, 10);
    
    cout << "# of numbers in array: ";
    cin >> n;
    
    vector<int> arr;
    
    for (int i = 0 ; i < n ; i++) {
        int temp = dist (rd);
        if (temp <= 0) {
            arr.push_back (0);
        }
        else {
            arr.push_back (temp);   
        }        
    }
    
    cout << "Original array: " << endl;
    for (int i = 0 ; i < n ; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    int n_nonzero = reorderAndCount (arr);
    
    cout << "Reordered array: " << endl;
    for (int i = 0 ; i < n ; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    cout << "# of nonzero elements = " << n_nonzero << endl;
}