#include <iostream>
#include <list>
#include <unordered_map>
#include <cstdlib>
#include <ctime>
#include <utility>
#include <cstdio>

using namespace std;

typedef list<int> Li;
typedef list<int>::iterator Lii;
typedef unordered_map<int, Lii> Mapi;
typedef Mapi::iterator Mapii;

int main () {
    srand (time (NULL));
    
    int n, m, q;
    cout << "Enter number of all possible rules: ";
    cin >> n;
    cout << "Enter capacity of table/timeline: ";
    cin >> m;
    cout << "Enter number of lookups: ";
    cin >> q;
    
    Li tline;
    Mapi ltable;
    
    for (int i = 0 ; i < q ; i++) {
        int r = rand () % n;    // r: incoming lookup
        
        if (ltable.find (r) != ltable.end ()) {
            // The case of a hit
            printf ("Hit on rule #%d. Promote to front of timeline. ", r);
            tline.erase (ltable[r]);
            tline.push_front (r);
            ltable[r] = tline.begin ();
        }
        else {
            // The case of a miss
            printf ("Miss on rule #%d. ", r);
            if (tline.size () >= m) {
                int rr = tline.back (); // rule # to remove
                tline.pop_back ();  // Remove from timeline
                ltable.erase (rr);  // Remove from lookup table
                printf ("Pop LRU rule #%d. ", rr);
            }
            
            printf ("Push new rule to front of timeline. ");
            tline.push_front (r);
            ltable[r] = tline.begin ();
        }
        
        printf ("Timeline size = %lu.\n", tline.size ());
    }
    return 0;
}