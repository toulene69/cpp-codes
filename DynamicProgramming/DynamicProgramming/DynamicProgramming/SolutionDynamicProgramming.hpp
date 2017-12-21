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
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <string.h>
#include <set>


using namespace std;

int flipArray(const vector<int> &A);
int tusharBDayParty(const vector<int> &A, const vector<int> &B, const vector<int> &C);
vector<string> wordBreak2(string A, vector<string> &B);
int minCutPalindromePartitioning(string A);

int wordBreak(string A, vector<string> B);
int numOfUniqueBSTs(int A);

int arrangeHorses(string A, int B);
int maxProductSubArray(const vector<int> &A);
int coinchange2(vector<int> A, int B);


int longestValidParentheses(string str);
int coinInALine(vector<int> &A);
vector<vector<int> > kManhattanDistanceNeighbourhood(int A, vector<vector<int> > &B);
int shortestCommonSuperString(vector<string> A);
int numbersWithSumS(int A, int B);
int longestArithematicProgressionSequence(const vector<int> &A);

int minJumps(vector<int> &A);
int canJump(vector<int> &A);
vector<int> birthdayBombs(int A, vector<int> B);

int countSubMatrixWithSumZero(vector<vector<int> > A);

int buySellStock3(const vector<int> A);
int buySellStock2(const vector<int> A);
int buySellStock1(const vector<int> A);

vector<int> rodCut(int A, vector<int> &B);
int maximalRectangle(vector<vector<int> > &A);
int minimumSumPathTriangle(vector<vector<int> > A);
int minPathSum(vector<vector<int> > &A);

int isScramble(const string A, const string B);
int regexMatch(const string &s, const string &p);
int wildcardMatch(const string &s, const string &p);
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
