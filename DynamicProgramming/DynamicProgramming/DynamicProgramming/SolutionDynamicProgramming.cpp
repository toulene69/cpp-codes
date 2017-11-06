//
//  SolutionDynamicProgramming.cpp
//  DynamicProgramming
//
//  Created by Apoorv on 06/11/17.
//  Copyright © 2017 presonal. All rights reserved.
//

#include "SolutionDynamicProgramming.hpp"

int numDecodings(string A) {
    int n = A.size();
    vector<int> m(n);
    if(A[0] != '0')
    {
        m[0] = 1;
        m[1] = 1;
    }
    for (int i = 2; i <= n; i++)
    {
        m[i] = 0;
        
        // If the last digit is not 0, then last digit must add to
        // the number of words
        if (A[i-1] > '0')
            m[i] = m[i-1];
        
        // If second last digit is smaller than 2 and last digit is
        // smaller than 7, then last two digits form a valid character
        if (A[i-2] == '1' || (A[i-2] == '2' && A[i-1] < '7') )
            m[i] += m[i-2];
    }
    return m[n];
}

int longestSubsequenceLength(const vector<int> &A) {
    int n = A.size();
    if (n==0) {
        return 0;
    }
    vector<int> lis(n);
    vector<int> lds(n);
    
    for (int i=0; i<n; i++) {
        lis[i] = 1;
    }
    
    for (int i=1; i<n; i++) {
        for (int j=0; j<i; j++) {
            if (A[i] > A[j] && lis[i] < lis[j]+1) {
                lis[i] = lis[j]+1;
            }
        }
    }
    
    for (int i=0; i<n; i++) {
        lds[i] = 1;
    }
    for (int i = n-2; i>=0; i--) {
        for (int j = n-1; j>i; j--) {
            if (A[i] > A[j] && lds[i] < lds[j]+1) {
                lds[i] = lds[j]+1;
            }
        }
    }
    int res = INT_MIN;
    for (int i=0; i<n; i++) {
        if (lis[i]+lds[i] -1 > res) {
            res = lis[i]+lds[i] -1 ;
        }
    }
    return res;
}
