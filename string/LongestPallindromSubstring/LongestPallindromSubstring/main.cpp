//
//  main.cpp
//  LongestPallindromSubstring
//
//  Created by Apoorv on 14/05/17.
//  Copyright © 2017 presonal. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

string longestPalindrome(string A) {
    int n = A.length();
    if (n==1) {
        return A;
    }
    else if (n==2)
    {
        if (A[0] == A[1]) {
            return A;
        }
        else
        {
            string str = A.substr(0,1);
            return str;
        }
    }
    int len = 0;
    string pSub = "";
    vector<vector<bool>> dp (n) ;
    for (int i=0 ; i<n; i++)
    {
        vector<bool> temp (n);
        dp[i] = temp;
    }
    len = 1;
    pSub = A.substr(0,1);
    for (int i = 0; i< n; i++) {
        dp[i][i] = true;
    }
    for (int i=0; i<n-1; i++)
    {
        if (A[i] == A[i+1]) {
            dp[i][i+1] = true;
            if (len<2) {
                len = 2;
                pSub = A.substr(i,2);
            }
        }
        else
        {
            dp[i][i+1] = false;
        }
    }
    for (int k = 2; k<=n; k++)
    {
        for (int i=0; i< (n-k); i++) {
            if (A[i] == A[i+k]) {
                if (dp[i+1][i+k-1])
                {
                    dp[i][i+k] = true;
                    if (len< k+1) {
                        len = k+1;
                        pSub = A.substr(i,k+1);
                    }
                }
                else
                {
                    dp[i][i+k] = false;
                }
            }
            else
            {
                dp[i][i+k] = false;
            }
        }
    }
    return pSub;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    string s = "abaabaaba";
    std::cout << longestPalindrome(s)<<endl;
    return 0;
}
