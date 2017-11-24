//
//  SolutionDynamicProgramming.hpp
//  DynamicProgramming
//
//  Created by Apoorv on 06/11/17.
//  Copyright © 2017 presonal. All rights reserved.
//

#ifndef SolutionDynamicProgramming_hpp
#define SolutionDynamicProgramming_hpp

#include <stdio.h>
#include <string>
#include <vector>
#include <deque>

using namespace std;

int isInterleave(string A, string B, string C);
int numDistinctSubsequences(string S, string T);
int repeatingSubsequence(string A);
int longestIncreasingSubsequence(const vector<int> &A);
int minDistance(string A, string B);
int maxAreaRectangleWithPermutation(vector<vector<int> > A);
int chordCnt(int n);
int climbStairs(int A);
int numDecodings(string A);
int longestSubsequenceLength(const vector<int> &A);


#endif /* SolutionDynamicProgramming_hpp */
