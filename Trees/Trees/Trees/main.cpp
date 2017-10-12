//
//  main.cpp
//  Trees
//
//  Created by Apoorv on 27/09/17.
//  Copyright © 2017 presonal. All rights reserved.
//

#include <iostream>
#include "SolutionTrees.hpp"
void inorder(TreeNode* root);
int main(int argc, const char * argv[]) {
    // insert code here...
    TreeNode *root = new TreeNode(3);
    TreeNode *root1;
    TreeNode *n1 = new TreeNode(4);
    TreeNode *n2 = new TreeNode(20);
    TreeNode *n3 = new TreeNode(1);
    TreeNode *n4 = new TreeNode(8);
    TreeNode *n5 = new TreeNode(15);
    TreeNode *n6 = new TreeNode(25);
   // root->left = n1;
    root->right = n1;
  //  n1->left = n3;
    n3->right = n4;
    //n2->left = n5;
   // n2->right = n6;
    root1 = new TreeNode(10);
    root1->left = n1;
    root1->right = n6;
    vector<int>v = {1,2,3,5,10,15,20};
    vector<int>v2 = {10,5,2,1,3,20,15};
    TreeNode *r = buildTreeFromInorderPreorder(v2, v);
    inorder(r);
    cout<< endl<< kthsmallest(r, 6) ;
    //TreeNode *res = getSuccessor(root, 102);
    //cout<<  minDepth(root);
//    vector<vector<int>> res = verticalOrderTraversal(root);
//    for(vector<int> x: res){
//        for(int y: x){
//        cout << y <<" " ;
//        }
//        cout<<endl;
//    }
    return 0;
}

void inorder(TreeNode* root)
{
    if (!root) {
        return;
    }
    inorder(root->left);
    cout<< root->val <<" ";
    inorder(root->right);
}
