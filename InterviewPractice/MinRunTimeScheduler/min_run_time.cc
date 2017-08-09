#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int calcRunTime (vector<char> tasks, int k) {
    int res = 0;
    for (vector<char>::iterator it = tasks.begin () ; it != tasks.end () ; it++) {
        res ++;
        if (*it == *(it + 1)) {
            res += k;
        }
    }
    
    return res;
}

void bruteforce (vector<char> tasks, int l, int r, int k, int *min) {
    if (l == r) {
        int r = calcRunTime (tasks, k);
        
        for (vector<char>::iterator it = tasks.begin () ; it != tasks.end () ; it++) {
            cout << *it << " ";
        }
        cout << ": " << r << endl;
         
        if (r < *min) {
            *min = r;
        }
        return;
    }
    
    else {
        for (int i = l ; i <= r ; i++) {
            char temp = tasks[l];
            tasks[l] = tasks[i];
            tasks[i] = temp;
            bruteforce (tasks, l + 1 , r, k, min);
            temp = tasks[l];
            tasks[l] = tasks[i];
            tasks[i] = temp;
        }
    }
}

int minRunTime (vector<char> tasks, int k) {
    int res = INT_MAX;
    
    bruteforce (tasks, 0, tasks.size () - 1, k, &res);
        
    return res;
}


int main (int argc, char *argv[]) {
    char taskarray[] = {'A', 'B', 'B', 'A', 'A', 'C', 'D'};    
    vector<char> tasks (taskarray, taskarray + sizeof(taskarray) / sizeof(taskarray[0]));
    int k = 3;
    
    int run_time = calcRunTime (tasks, k);
    
    for (vector<char>::iterator it = tasks.begin() ; it != tasks.end () ; it++) {
        cout << *it << " ";
    }
    cout << endl;
    
    cout << "Total run time = " << run_time << endl;
    
    int min_run_time = minRunTime (tasks, k);
    cout << "Min run time = " << min_run_time << endl;
}