#include <iostream>

using namespace std;

unsigned long int fib_recursive (unsigned int n) {
    if (n == 0) {
        return 0;
    }

    else if (n == 1) {
        return 1;
    }

    else return (fib_recursive (n - 1) + fib_recursive (n - 2));
}

unsigned long int fib_plain (unsigned int n) {
    if (n == 0) {
        return 0;
    }

    else if (n == 1) {
        return 1;
    }

    int res = 0;
    int j = 0;
    int k = 1;

    for (int i = 2 ; i <= n ; i++) {
        res = j + k;
        j = k;
        k = res;
    }

    return res;
}


int main () {
    unsigned int n;
    cout << "Input n: ";
    cin >> n;

    unsigned long int fibn = fib_plain(n);

    cout << "Fib(" << n << ") = " << fibn << endl;
}
