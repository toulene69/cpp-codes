//
//  SolutionTrees.hpp
//  Trees
//
//  Created by Apoorv on 27/09/17.
//  Copyright © 2017 presonal. All rights reserved.
//

#ifndef SolutionTrees_hpp
#define SolutionTrees_hpp

#include <stdio.h>
#include <map>
#include <vector>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>


using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int kthsmallest(TreeNode* root, int k) ;
TreeNode* buildTreeFromInorderPreorder(vector<int> &preorder, vector<int> &inorder);
TreeNode* buildTree(vector<int> &inorder, vector<int> &postorder);
TreeNode* sortedArrayToBST(const vector<int> &A);
TreeNode* buildTree(vector<int> &A);

int minDepth(TreeNode* A);
int maxDepth(TreeNode* A);
int isSymmetric(TreeNode* A) ;
int isSameTree(TreeNode* A, TreeNode* B);
int isBalanced(TreeNode* A);
vector<vector<int>> verticalOrderTraversal(TreeNode* A);
vector<int> preorderTraversal(TreeNode* A);
vector<int> postorderTraversal(TreeNode* A);
vector<int> inorderTraversal(TreeNode* A);
int isValidBST(TreeNode* A);
TreeNode* getSuccessor(TreeNode* A, int B);

#endif /* SolutionTrees_hpp */
