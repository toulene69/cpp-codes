//
//  main.cpp
//  LongestCommonPrefix
//
//  Created by Apoorv on 10/05/17.
//  Copyright © 2017 presonal. All rights reserved.
//

#include <string>
#include <sstream>
#include <iostream>
#include <vector>


using namespace std;

int min(int a,int b)
{
    if (a<=b) {
        return a;
    }
    else
    {
        return b;
    }
}

string longestCommonPrefix(vector<string> &A)
{
    string pre = "";
    int n = A.size();
    int minLen = INT_MAX;
    for(int i = 0; i<n; i++)
    {
        minLen = min(minLen, A[i].length());
    }
    for (int i = 0; i<minLen; i++)
    {
        char c = A[0][i];
        bool flag= true;
        for (int j = 1 ; j<n; j++)
        {
            if (c != tolower(A[j][i]))
            {
                flag = false;
                return pre;
            }
        }
        if (flag)
        {
            pre.push_back(c);
        }
    }
    return pre;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<string> a;
    a.push_back("abcdefgh");
   // a.push_back("aefghijk");
    a.push_back("abcefgh");
    cout << longestCommonPrefix(a) << endl;
    return 0;
}
