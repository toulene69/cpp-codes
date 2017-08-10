//
//  main.cpp
//  ImplementStrStr
//
//  Created by Apoorv on 15/05/17.
//  Copyright © 2017 presonal. All rights reserved.
//

#include <iostream>
# define NO_OF_CHARS 256
using namespace std;
int max (int a, int b) { return (a > b)? a: b; }

void badCharHeuristic( string str, int badchar[])
{
    int i;
    int size = str.length();
    // Initialize all occurrences as -1
    for (i = 0; i < NO_OF_CHARS; i++)
        badchar[i] = -1;
    
    // Fill the actual value of last occurrence of a character
    for (i = 0; i < size; i++)
        badchar[(int) str[i]] = i;
}

int strStr(const string &haystack, const string &needle)
{
    int m = needle.length();
    int n = haystack.length();
    int badchar[NO_OF_CHARS];
    badCharHeuristic(needle, badchar);
    int s = 0;
    while (s<= (n-m))
    {
        int j = m-1;
        while (j>=0 && haystack[s+j] == needle[j])
        {
            j--;
        }
        if (j<0) { // found needle
            return s;
        }
        else
        {
            s += max(1, j - badchar[haystack[s+j]]);
        }
    }
    return -1;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    string haystack = "ABAAABCD";
    string needle = "ABC";
    std::cout << strStr(haystack,needle)<<endl;
    return 0;
}
