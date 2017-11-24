//
//  SolutionDynamicProgramming.cpp
//  DynamicProgramming
//
//  Created by Apoorv on 06/11/17.
//  Copyright © 2017 presonal. All rights reserved.
//

#include "SolutionDynamicProgramming.hpp"



bool rec_is_interleave(string &a, string &b, string &c, long i, long j, long k)
{
    if (i<0 && j<0 && k<0) {
        return true;
    }
    if (k<0 && (i>0 || j>0)) {
        return false;
    }
    
    if (a[i] == c[k]) {
        return rec_is_interleave(a, b, c, i-1, j, k-1);
    }
    else if (b[j] == c[k]) {
        return rec_is_interleave(a, b, c, i, j-1, k-1);
    }
    else {
        return false;
    }
    
}

int isInterleave(string A, string B, string C) {
    long i = A.length();
    long j = B.length();
    long k = C.length();
//    vector<vector<bool>> dp(i+1, vector<bool>(j+1, false));
//    dp[0][0] = true;
//    for (int x=1; x<i+1; x++) {
//        if (A[x-1] == C[x-1]) {
//            dp[x][0] = dp[x-1][0];
//        }
//    }
//    for (int x=1; x<j+1; x++) {
//        if (B[x-1] == C[x-1]) {
//            dp[0][x] = dp[0][x-1];
//        }
//    }
//    for (int x = 1; x<i+1; x++) {
//        for (int y=1; y<j+1; y++) {
//            if (A[x-1] == C[x+y-1] && B[y-1] == C[x+y-1]) {
//                dp[x][y] = (dp[x-1][y] || dp[x][y-1]);
//            }
//            else if (A[x-1] == C[x+y-1]) {
//                dp[x][y] = dp[x-1][y];
//            }
//            else if (B[y-1] == C[x+y-1]) {
//                dp[x][y] = dp[x][y-1];
//            }
//            else {
//                dp[x][y] = false;
//            }
//        }
//    }
//
//    return dp[i][j];
    return rec_is_interleave(A, B, C, i-1, j-1, k-1);
}

int numDistinctSubsequences(string S, string T) {
    long m = S.length();
    long n = T.length();
    int dp[m+1][n+1];
    for (int i=0; i<n+1; i++) {
        dp[0][i] = 0;
    }
    for (int i=0; i<m+1; i++) {
        dp[i][0] = 1;
    }
    for (int i=1; i<m+1; i++) {
        for (int j=1; j<n+1; j++) {
            if(S[i-1]!=T[j-1]) {
                dp[i][j] = dp[i-1][j];
            }
            else {
                dp[i][j] = dp[i-1][j] + dp[i-1][j-1];
            }
        }
    }
    return dp[m][n];
}

int repeatingSubsequence(string A){
    int n = A.length();
    int dp[n+1][n+1];
    for (int i=0; i<n+1; i++) {
        dp[0][i] = 0;
        dp[i][0] = 0;
    }
    
    for (int i=1; i<n+1; i++) {
        for (int j=1; j<n+1; j++) {
            if (A[i-1]==A[j-1] && i!= j) {
                dp[i][j] = dp[i-1][j-1]+1;
            }
            else {
                dp[i][j] = max(dp[i-1][j-1], max(dp[i-1][j], dp[i][j-1]));
            }
            if (dp[i][j]>=2) {
                return 1;
            }
        }
    }
    return 0;
}

int longestIncreasingSubsequence(const vector<int> &A) {
    
    int n = A.size();
    int dp[n];
    for (int i=0; i<n; i++) {
        dp[i] = 1;
    }
    for (int i=1; i<n; i++) {
        for (int j=0; j<i; j++) {
            if (A[i]>A[j] && dp[j] >= dp[i]) {
                dp[i] = dp[j]+1;
            }
        }
    }
    int res = 0;
    for (int i = 0; i < n; i++ )
        if (res < dp[i])
            res = dp[i];
    return res;
}

int minDistance(string A, string B) {
    
    int m = A.length();
    int n = B.length();
    int dp[m+1][n+1];
    
    for (int i=0; i<n+1; i++) {
        dp[0][i] = i;
    }
    for (int i=0; i<m+1; i++) {
        dp[i][0] = i;
    }
    
    for (int i = 1; i<m+1; i++) {
        for (int j = 1; j<n+1; j++) {
            if (A[i-1]==B[j-1]) {
                dp[i][j] = dp[i-1][j-1];
            }
            else {
                dp[i][j] = min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1])) + 1 ;
            }
        }
    }
    return dp[m][n];
}


int maxAreaRectangleWithPermutation(vector<vector<int> > A) {
    
    int r = A.size();
    int c = A[0].size();
    vector<vector<int>> m(r, vector<int>(c,0));

    for (int j = 0; j<c; j++) {
        for (int i=0; i<r; i++) {
            if (i==0) {
                m[i][j] = A[i][j];
            }
            else{
                if (A[i][j] !=0) {
                    m[i][j] = m[i-1][j]+1;
                }
            }
        }
    }
    if (c==1 || r==1) {
        int curr_ar=0, max_ar=0;
        for (int i=0; i<r; i++) {
            for (int j=0; j<c; j++) {
                curr_ar = (j+1)*m[i][j];
                if (curr_ar> max_ar) {
                    max_ar = curr_ar;
                }
            }
        }
        return max_ar;
    }
    for (int i=0; i<r; i++) {
        vector<int> counts(c+1,0);
        for (int j=0; j<c; j++) {
            int v = m[i][j];
            counts[v]++;
        }
        int j=0;
        for (int k=counts.size()-1; k>=0; k--) {
            int counti = counts[k];
            while (counti>0) {
                m[i][j] = k;
                j++;
                counti--;
            }
        }
    }
    
    int curr_ar=0, max_ar=0;
    for (int i=0; i<r; i++) {
        for (int j=0; j<c; j++) {
            curr_ar = (j+1)*m[i][j];
            if (curr_ar> max_ar) {
                max_ar = curr_ar;
            }
        }
    }
    
    return max_ar;
}

int chordCnt(int A){
    int p = 1000000007;
    int n = A;
    if(n == 0) return 1;
    vector<long> table (n + 1);
    table[0] = 1;
    table[1] = 1;
    for(int i = 2; i <= n; i++) {
        for(int j = 0; j < i; j++) {
            table[i] = (table[i] + (table[j] * table[i - 1 - j])%p)%p;
        }
    }
    return table[n];
}

int climbStairs(int A) {
    vector<int> m(A+1);
    m[0] = 1;
    m[1] = 1;
    for (int i = 2; i<=A; i++) {
        int s = m[i-1];
        if (i-2 >= 0) {
            s+=m[i-2];
        }
        m[i] = s;
    }
    return m[A];
}

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
