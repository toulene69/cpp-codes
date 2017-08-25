//
//  BacktrackingSolutions.hpp
//  Backtracking
//
//  Created by Apoorv on 17/08/17.
//  Copyright © 2017 presonal. All rights reserved.
//

#ifndef BacktrackingSolutions_hpp
#define BacktrackingSolutions_hpp

#include <stdio.h>
#include <stack>
#include <vector>
#include <deque>
#include <map>
#include <unordered_set>
#include <set>
#include <unordered_map>
#include <string>
#include <stdlib.h>

using namespace std;

struct ListNode {
         int val;
         ListNode *next;
         ListNode(int x) : val(x), next(NULL) {}
    };

ListNode* reverseList(ListNode* A);

int Mod(int A, int B, int C);

vector<vector<int> > subsets(vector<int> &A);

vector<vector<int> > combine(int n, int k);

vector<vector<int> > combinationSum(vector<int> &A, int B);

vector<vector<int> > combinationSum2(vector<int> &A, int B);

vector<vector<int> > subsetsWithDup(vector<int> &A);

vector<vector<int> > permute(vector<int> &A);

vector<string> letterCombinations(string A);

vector<vector<string> > partition(string A);

vector<string> generateParenthesis(int A);

vector<vector<string> > solveNQueens(int A);

void solveSudoku(vector<vector<char> > &A);

vector<int> grayCode(int A);

string getPermutation(int n, int k);

#endif /* BacktrackingSolutions_hpp */
