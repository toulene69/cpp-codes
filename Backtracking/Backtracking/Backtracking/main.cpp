//
//  main.cpp
//  Backtracking
//
//  Created by Apoorv on 17/08/17.
//  Copyright © 2017 presonal. All rights reserved.
//

#include <iostream>
#include "BacktrackingSolutions.hpp"


int main(int argc, const char * argv[]) {
    
//    ListNode *n1 = new ListNode(1);
//    ListNode *n2 = new ListNode(2);
//    ListNode *n3 = new ListNode(3);
//    //n1->next = n2;
//    n2->next = n3;
//    ListNode *h = reverseList(NULL);
//    while (h!=NULL) {
//        cout<<h->val<<endl;
//        h = h->next;
//    }
//    vector<int> v = {1,2,3};//{8, 10, 6, 11, 1, 16, 8};
//    map<char,string> m;
//    vector<string> r = generateParenthesis(3);
//    for (int i = 0; i<r.size(); i++) {
//        cout<<r[i]<<endl;
//    }
//    vector<vector<string>> o =  solveNQueens(5);
//    for (int i=0; i<o.size(); ++i) {
//        for (int j =0 ; j<o[i].size(); j++) {
//            cout<<o[i][j]<< endl;
//        }
//        cout<<endl;
//    }
   // cout<< 5+'0'<<endl;
    vector<vector<char>> s = {{'5','3','.','.','7','.','.','.','.'}, {'6','.','.','1','9','5','.','.','.'}, {'.','9','8','.','.','.','.','6','.'}, {'8','.','.','.','6','.','.','.','3'}, {'4','.','.','8','.','3','.','.','1'}, {'7','.','.','.','2','.','.','.','6'}, {'.','6','.','.','.','.','2','8','.'}, {'.','.','.','4','1','9','.','.','5'}, {'.','.','.','.','8','.','.','7','9'}};
    solveSudoku(s);
    for (int i=0; i<s.size(); ++i) {
        for (int j =0 ; j<s[i].size(); j++) {
            cout<<s[i][j]<<" ";
        }
        cout<<endl;
    }
    //std::cout << Mod(-1, 1, 20);
    return 0;
}
