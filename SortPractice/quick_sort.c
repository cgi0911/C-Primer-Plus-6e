#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void quick_sort (int *arr, int lo, int hi) {
    if (lo >= hi) {
        return;
    }
    
    int pivot = arr[hi];
    int x = lo - 1;
    int y;
    int temp;
    
    for (y = lo ; y <= hi - 1 ; y++) {
        if (arr[y] < pivot) {
            x++;            
            temp = arr[y];
            arr[y] = arr[x];
            arr[x] = temp;
        }
    }
    
    // Finally swap pivot and arr[x+1]
    temp = arr[x+1];
    arr[x+1] = arr[hi];
    arr[hi] = temp;
    
    quick_sort (arr, lo, x);
    quick_sort (arr, x + 2, hi);
}


int main () {
    srand (time (NULL));
    
    int n, r;
    
    printf ("Input size of array: ");
    scanf ("%d", &n);
    printf ("Input range of numbers [0..r-1]: ");
    scanf ("%d", &r);
    
    int *array = (int *) malloc (sizeof (int) * n);
    
    for (int i = 0 ; i < n ; i++) {
        array[i] = rand () % r;
    }
    
    printf ("Current array:\n");
    
    for (int i = 0 ; i < n ; i++) {
        printf ("%d ", array[i]);
    }
    printf ("\n");
    
    quick_sort (array, 0, n-1);
    
    printf ("Array after sorting:\n");
    
    for (int i = 0 ; i < n ; i++) {
        printf ("%d ", array[i]);
    }
    printf ("\n");
        
}