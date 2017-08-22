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
    vector<int> v = {1,2,3};//{8, 10, 6, 11, 1, 16, 8};
    map<char,string> m;
    vector<string> r = letterCombinations("234");
    for (int i = 0; i<r.size(); i++) {
        cout<<r[i]<<endl;
    }
//    vector<vector<int>> o = permute(v);
//    for (int i=0; i<o.size(); ++i) {
//        for (int j =0 ; j<o[i].size(); j++) {
//            cout<<o[i][j];
//        }
//        cout<<endl;
//    }
    //std::cout << Mod(-1, 1, 20);
    return 0;
}
