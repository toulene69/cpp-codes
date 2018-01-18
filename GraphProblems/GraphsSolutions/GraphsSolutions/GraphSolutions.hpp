//
//  GraphSolutions.hpp
//  GraphsSolutions
//
//  Created by Apoorv on 04/01/18.
//  Copyright © 2018 presonal. All rights reserved.
//

#ifndef GraphSolutions_hpp
#define GraphSolutions_hpp

#include <stdio.h>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <string>
#include <set>
#include <unordered_set>
#include <list>
#include <unordered_map>
using namespace std;

struct TreeNode {
         int val;
         TreeNode *left;
         TreeNode *right;
         TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
};

struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};

UndirectedGraphNode* cloneGraph(UndirectedGraphNode *node);
vector<vector<string> > findLadders(string start, string end, vector<string> &dict);
int wordLadderLength(string start, string end, vector<string> &dictV);
int knight(int A, int B, int C, int D, int E, int F);
int fibsum(int A);
TreeNode* sortedListToBST(ListNode* A);
int wordSearch(vector<string> &A, string B);
vector<int> stepnum(int A, int B);
int largestDistance(vector<int> &A);
void captureBoard(vector<vector<char> > &A);
int numberOfblackShapes(vector<string> &A);
int isCoursesPossible(int A, vector<int> &B, vector<int> &C);
int commutableIslands(int A, vector<vector<int> > &B);
string multipleWith1and0(int A);
vector<vector<int> > levelOrderTraversalBST(TreeNode* A);
string validPathRectangle(int A, int B, int C, int D, vector<int> E, vector<int> F);
vector<int> solve(int A, int B, int C, int D) ;




#endif /* GraphSolutions_hpp */
