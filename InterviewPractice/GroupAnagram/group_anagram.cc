// Leetcode 49

#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <vector>

using namespace std;

vector<vector<string> > groupAnagrams (vector<string> &words) {
    vector<vector<string> > results;
    unordered_map<string, vector<string> > groups;

    for (int i = 0 ; i < words.size () ; i++) {
        string temp = words[i]; // make a copy
        sort(temp.begin (), temp.end ());

        groups[temp].push_back (words[i]);
        // if temp is not in groups' keys, it will create a new vector and push back
    }

    for (unordered_map<string, vector<string> >::iterator it = groups.begin () ;
         it != groups.end () ; it++) {
        results.push_back (it->second);   
    }

    return results;
}

int main () {
    vector<string> words = {"abc", "acb", "cat", "tca", "cab", "cde", "edc", "eca"};

    vector<vector<string> > res = groupAnagrams (words);

    for (int i = 0 ; i < res.size () ; i++) {
        cout << "[";
        for (int j = 0 ; j < res[i].size () ; j++) {
            cout << res[i][j] << ", ";
        }
        cout << "]" << endl;
    }
}
