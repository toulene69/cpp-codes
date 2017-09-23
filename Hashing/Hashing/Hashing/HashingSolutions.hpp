//
//  HashingSolutions.hpp
//  Hashing
//
//  Created by Apoorv on 27/08/17.
//  Copyright © 2017 presonal. All rights reserved.
//

#ifndef HashingSolutions_hpp
#define HashingSolutions_hpp

#include <stdio.h>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <vector>
#include <string>
#include <functional>

struct RandomListNode {
         int label;
         RandomListNode *next, *random;
         RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

using namespace std;

vector<int> findSubstring(string A, const vector<string> &B);

int maxPoints(vector<int> &A, vector<int> &B);

string fractionToDecimal(int numerator, int denominator);

string minWindow(string S, string T);

int lengthOfLongestSubstring(string A);

RandomListNode* copyRandomList(RandomListNode* A);

vector<int> equal(vector<int> &A);

vector<vector<int> > anagrams(const vector<string> &A);

int diffPossible(const vector<int> &A, int B);

int isValidSudoku(const vector<string> &A);
int valid_soduku(const vector<string> &A);

vector<vector<int>> fourSum(vector<int> &A, int B);

vector<int> twoSum(const vector<int> &A, int B);

vector<int> lszero(vector<int> &A);

int colorful(int A);

#endif /* HashingSolutions_hpp */
