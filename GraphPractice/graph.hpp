#include <random>
#include <vector>
#include <cstdio>

using namespace std;

typedef struct {
    int n;      // # of nodes
    int e;      // # of edges
    int **adj;  // Adjacency matrix
} Graph;        // Undirectional graph


Graph rand_graph (int n, int adeg) {
    // nn: input # of nodes, adeg: average degree per node
    Graph ret;
    ret.n = n;
    ret.adj = new int*[n] (); // C++ 11
    for (int i = 0 ; i < n ; i++) {
        ret.adj[i] = new int[n] ();
    }

    return ret;
}


void print_graph (Graph *g) {
    int n = g->n;
    
    printf ("# of nodes = %d\n", n);
    printf ("Adjacency matrix:\n\n");
    
    printf ("S\\D| ");
    for (int i = 0 ; i < n ; i++) {
        printf ("%3d ", i);        
    }
    printf ("\n");
    printf ("---|-");
    for (int i = 0 ; i < 4 * n ; i++) {
        printf ("-");
    }
    printf ("\n");     
    
    for (int i = 0 ; i < n ; i++) {
        printf ("%3d| ", i);
        for (int j = 0 ; j < n ; j++) {
            printf ("%3d ", g->adj[i][j]);
        }
        printf ("\n");
    }
    printf ("\n");
    
    return;    
}