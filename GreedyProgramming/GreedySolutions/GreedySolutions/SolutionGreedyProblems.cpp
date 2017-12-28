//
//  SolutionGreedyProblems.cpp
//  GreedySolutions
//
//  Created by Apoorv on 23/12/17.
//  Copyright © 2017 presonal. All rights reserved.
//

#include "SolutionGreedyProblems.hpp"

int majorityElement(const vector<int> &A) {
    int majorityIndex = 0;
    for (int count = 1, i = 1; i < A.size(); i++) {
        A[majorityIndex] == A[i] ? count++ : count--;
        if (count == 0) {
            majorityIndex = i;
            count = 1;
        }
    }
    
    return A[majorityIndex];
}

int canCompleteCircuit(const vector<int> &A, const vector<int> &B) {
    
    int n = A.size();
    int start = 0;
    int end =  1;
    
    int curr_petrol = A[start] - B[start];
    
    /* Run a loop while all petrol pumps are not visited.
     And we have reached first petrol pump again with 0 or more petrol */
    while (end != start || curr_petrol < 0)
    {
        // If curremt amount of petrol in truck becomes less than 0, then
        // remove the starting petrol pump from tour
        while (curr_petrol < 0 && start != end)
        {
            // Remove starting petrol pump. Change start
            curr_petrol -= A[start] - B[start];
            start = (start + 1)%n;
            
            // If 0 is being considered as start again, then there is no
            // possible solution
            if (start == 0)
                return -1;
        }
        
        // Add a petrol pump to current tour
        curr_petrol += A[end] - B[end];
        
        end = (end + 1)%n;
    }
    
    // Return starting point
    return start;
}


int mice(vector<int> &A, vector<int> &B) {
    int n = A.size();
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    int res = INT_MIN ;
    for (int i=0; i<n; i++) {
        if (abs(A[i] - B[i]) > res) {
            res = abs(A[i] - B[i]);
        }
    }
    return res;
}


int candy(vector<int> &A) {
    int n = A.size();
    int i = 0;
    int candies = 0;
    vector<int> c(n,0);
    c[0] = 1;
    for (int i=0; i<n; i++) {
        if (A[i] > A[i-1]) {
            c[i]= c[i-1]+1;
        }
        else {
            c[i] = 1;
        }
    }
    candies = c[n-1];
    for (int i = n-2; i>=0; i--) {
        int cur = 1;
        if (A[i]>A[i+1]) {
            cur = c[i+1]+1;
        }
        candies += max(cur, c[i]);
        c[i] = cur;
    }
    return candies;
}

int bulbs(vector<int> &A) {
    int n = A.size();
    int res = 0;
    int i = 0;
    while (i<n && A[i]==1) {
        i++;
    }
    int num1 = 0;
    int num0 = 0;
    while (i<n) {
        int j = i+1;
        while(j<n && A[i]==A[j])  {
            j++;
        }
        if (A[i] == 0) {
            num0 ++;
        }
        else {
            num1 ++;
        }
        i = j;
    }
    return num0+num1;
}

int maxProduct3Nums(vector<int> &A) {
    int n = A.size();
    sort(A.begin(), A.end());
    if (A[0]>=0) {
        return A[n-1]*A[n-2]*A[n-3];
    }
    else {
        if (A[0]*A[1]*A[n-1] > A[n-1]*A[n-2]*A[n-3]) {
            return A[0]*A[1]*A[n-1] ;
        }
        else {
            return A[n-1]*A[n-2]*A[n-3];
        }
    }
}
