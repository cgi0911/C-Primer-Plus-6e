#include <iostream>
#include <vector>
#include <random>
#include <climits>

using namespace std;

void print_arr (const vector<int> &arr) {
    for (int i = 0 ; i < arr.size () ; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}


void swap (vector<int> &arr, int m, int n) {
    int temp = arr[m];
    arr[m] = arr[n];
    arr[n] = temp;
}


void quick_sort (vector<int> &arr, int st, int ed) {
    // Overload the function. st = starting index, ed = ending index.
    
    if (st >= ed) {
        return;
    }

    int pivot = arr[ed];
    int i = st - 1;

    for (int j = st ; j < ed ; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap (arr, i, j);
        }
    }

    swap (arr, i + 1, ed);

    quick_sort (arr, st, i);
    quick_sort (arr, i + 2, ed);
}



void quick_sort (vector<int> &arr) {
    int n = arr.size ();

    quick_sort (arr, 0, n - 1);
}


void merge_sort (vector<int> &arr, int st, int ed) {
    // Overload the function. st = starting index, ed = ending index.
    if (st == ed) {
        return;
    }

    if (st + 1 == ed) {
        if (arr[st] > arr[ed]) {
            swap (arr, st, ed);
        }
        return;
    }

    int n = ed - st + 1;
    int halfn = n / 2;

    // Split the problem into upper and lower halves
    merge_sort (arr, st, st + halfn - 1);
    merge_sort (arr, st + halfn, ed);

    // Merge the two halves
    vector<int> merged;
    int j = st;
    int k = st + halfn;

    while (j < st + halfn || k <= ed) {
        if (j < st + halfn && k <= ed) {
            if (arr[j] < arr[k]) {
                merged.push_back (arr[j]);
                j++;
            }
            else {
                merged.push_back (arr[k]);
                k++;
            }
        }
        else if (j < st + halfn) {
            merged.push_back (arr[j]);
            j++;
        }
        else {
            merged.push_back (arr[k]);
            k++;
        }
    }

    for (int i = 0 ; i < merged.size () ; i++) {
        arr[st+i] = merged[i];
    }
}


void merge_sort (vector<int> &arr) {
    int n = arr.size ();

    if (n <= 1) {
        return;
    }

    merge_sort (arr, 0, n - 1);
}


void heap_sort (vector<int> &arr) {
}


void insert_sort (vector<int> &arr) {
    int n = arr.size ();
    
    for (int i = 1 ; i < n ; i++) {
        int insert_pos = i;

        // Find insertion location
        for (int j = 0 ; j < i ; j++) {
            if (arr[i] < arr[j]) {
                insert_pos = j;
                break;
            }
        }

        // Do insertion
        for (int k = i - 1 ; k >= insert_pos ; k--) {
            swap (arr, k, k+1);
        }
    }
}


void select_sort (vector<int> &arr) {
    int n = arr.size ();
    for (int i = n ; i > 1 ; i--) {
        int max_idx = -1;
        int max = INT_MIN;
        for (int j = 0 ; j < i ; j++) {
            if (arr[j] > max) {
                max_idx = j;
                max = arr[j];
            }
        }

        swap (arr, max_idx, i-1);
    }
}


void bubble_sort (vector<int> &arr) {
    int n = arr.size ();
    for (int i = n - 1 ; i > 0 ; i--) {
        for (int j = 0 ; j < i ; j++) {
            if (arr[j] > arr[j+1]) {
                swap (arr, j, j+1);
            }
        }
    }
}


int main () {
    int n, r;
    cout << "# of integers: ";
    cin >> n;
    cout << "Max of integers: ";
    cin >> r;

    random_device rd;
    uniform_int_distribution<int> dist (0, r);

    vector<int> arr;
    for (int i = 0 ; i < n ; i++) {
        arr.push_back (dist (rd));
    }

    cout << "Original array:" << endl;
    print_arr (arr);
    cout << endl;

    quick_sort (arr);

    cout << "Sorted array:" << endl;
    print_arr (arr);
}
