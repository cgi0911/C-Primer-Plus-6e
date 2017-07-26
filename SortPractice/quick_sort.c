#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void quick_sort (int *arr, int lo, int hi) {    
    if (lo >= hi) {
        printf ("quick_sort (arr, %d, %d) return\n", lo, hi);
        return;
    }
    
    printf ("quick_sort (arr, %d, %d)\n", lo, hi);
    
    int pivot = arr[hi];
    int x = lo - 1;
    int y;
    int temp;
    
    for (y = lo ; y <= hi - 1 ; y++) {
        if (arr[y] < pivot) {
            x++;
            temp = arr[x];
            arr[x] = arr[y];
            arr[y] = temp;
        }
    }
    
    temp = arr[x+1];
    arr[x+1] = arr[hi];
    arr[hi] = temp;
    
    quick_sort (arr, lo, x);
    quick_sort (arr, x + 2, hi);
}


void sort_array (int *arr, int n) {
    if (n <= 1) {
        return;
    }
    
    else {
        quick_sort (arr, 0, n-1);
    }
    
    return;
}


void print_array (int *arr, int n) {
    for (int i = 0 ; i < n ; i++) {
        printf ("%d ", arr[i]);
    }
    printf ("\n");
    return;
}


int *gen_rand_array (int n, int r) {
    int *arr = (int *) malloc (sizeof (int) * n);
    
    for (int i = 0 ; i < n ; i++) {
        arr[i] = rand () % r;
    }
    
    return arr;
}


int main () {
    srand (time (NULL));
    
    int n, r;
    
    printf ("Input size of array: ");
    scanf ("%d", &n);
    printf ("Input range of numbers [0..r-1]: ");
    scanf ("%d", &r);
    
    int *arr = gen_rand_array (n, r);
    
    printf ("The original array:\n");
    print_array (arr, n);
        
    sort_array (arr, n);
    
    printf ("The sorted array:\n");
    print_array (arr, n);
}