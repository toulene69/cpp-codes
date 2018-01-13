//
//  main.cpp
//  GraphsSolutions
//
//  Created by Apoorv on 03/01/18.
//  Copyright © 2018 presonal. All rights reserved.
//

#include <iostream>
#include "GraphSolutions.hpp"

int main(int argc, const char * argv[]) {
    // insert code here...
    //vector<int> r = solve(9,7,13,9);
    vector<int> E = {-1, 0, 1, 1, 2, 0, 5, 0, 3, 0, 0, 2, 3, 1, 12, 14, 0, 5, 9, 6, 16, 0, 13, 4, 17, 2, 1, 22, 14, 20, 10, 17, 0, 32, 15, 34, 10, 19, 3, 22, 29, 2, 36, 16, 15, 37, 38, 27, 31, 12, 24, 29, 17, 29, 32, 45, 40, 15, 35, 13, 25, 57, 20, 4, 44, 41, 52, 9, 53, 57, 18, 5, 44, 29, 30, 9, 29, 30, 8, 57, 8, 59, 59, 64, 37, 6, 54, 32, 40, 26, 15, 87, 49, 90, 6, 81, 73, 10, 8, 16};
    vector<int> F = {2,3,1};
    int n = 3;
    vector<string> A = {"FEDCBECD", "FABBGACG", "CDEDGAEC", "BFFEGGBA", "FCEEAFDA", "AGFADEAC", "ADGDCBAA", "EAABDDFF"};
    
//    vector<vector<char>> b = {{'X','O','O','O','O','O','O','X'},
//        {'X','X','O','O','X','O','O','X'},
//        {'O','X','X','O','X','O','X','X'}
//        };
//    vector<vector<char>> c(A.size());
//    for (int i=0; i<A.size(); i++) {
//        string s = A[i];
//        for (int j=0; j<s.length(); j++) {
//            c[i].push_back(s[j]);
//        }
//    }
    ListNode *a = new ListNode(1);
    ListNode *b = new ListNode(2);
    ListNode *c = new ListNode(3);
    ListNode *d = new ListNode(4);
    ListNode *e = new ListNode(5);
    ListNode *f = new ListNode(6);
    ListNode *g = new ListNode(7);
    ListNode *h = new ListNode(8);
    a->next = b;
    b->next = c;
    c->next = d;
    d->next = e;
    e->next = f;
    f->next = g; g->next = h;
    TreeNode * r = sortedListToBST(a);
    //cout << wordSearch(A, "BCDCB    ");
    return 0;
}
