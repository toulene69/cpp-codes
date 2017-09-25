//
//  main.cpp
//  HeapsMaps
//
//  Created by Apoorv on 24/09/17.
//  Copyright © 2017 presonal. All rights reserved.
//
#include "SolutionHeapsMaps.hpp"
#include <iostream>

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> v1= {36, 27, -35, 43, -15, 36, 42, -1, -29, 12, -23, 40, 9, 13, -24, -10, -24, 22, -14, -39, 18, 17, -21, 32, -20, 12, -27, 17, -15, -21, -48, -28, 8, 19, 17, 43, 6, -39, -8, -21, 23, -29, -31, 34, -13, 48, -26, -35, 20, -37, -24, 41, 30, 6, 23, 12, 20, 46, 31, -45, -25, 34, -23, -14, -45, -4, -21, -37, 7, -26, 45, 32, -5, -36, 17, -16, 14, -7, 0, 37, -42, 26, 28};
    vector<int> v2 = {38, 34, -47, 1, 4, 49, -18, 10, 26, 18, -11, -38, -24, 36, 44, -11, 45, 20, -16, 28, 17, -49, 47, -48, -33, 42, 2, 6, -49, 30, 36, -9, 15, 39, -6, -31, -10, -21, -19, -33, 47, 21, 31, 25, -41, -23, 17, 6, 47, 3, 36, 15, -44, 33, -31, -26, -22, 21, -18, -21, -47, -31, 20, 18, -42, -35, -10, -1, 46, -27, -32, -5, -4, 1, -29, 5, 29, 38, 14, -22, -9, 0, 43};
    vector<int> n = {2147483647, 2000000014, 2147483647};
   // cout<< numberOfPossibleMaxHeaps(6);
    
//    ListNode *n1 = new ListNode(1);
//    ListNode *n2 = new ListNode(10);
//    ListNode *n3 = new ListNode(10);
//    ListNode *n4 = new ListNode(4);
//    ListNode *n5 = new ListNode(11);
//    ListNode *n6 = new ListNode(13);
//    ListNode *n7 = new ListNode(3);
//    ListNode *n8 = new ListNode(8);
//    ListNode *n9 = new ListNode(9);
//    n1->next = n2;
//    n2->next = n3;
//    n4->next = n5;
//    n5->next = n6;
//    n7->next = n8;
//    n8->next = n9;
//    vector<ListNode*> v = {n1,n4,n7};
//    ListNode* r = mergeKLists(v);
//    while (r) {
//        cout<<r->val << "->";
//        r = r->next;
//    }
    LRUCache *c = new LRUCache(2);
    c->set(1, 10);
    c->set(5, 12);
    cout<<c->get(5);
    cout<<c->get(1);
    cout<<c->get(10);
    c->set(6, 14) ;
    cout<<c->get(5);
    
//    vector<int> z = {1, 2, 1, 3, 4, 3};
//    vector<int> res = distinctNumsInWindow(z,5);
//    for( int x : res) {
//        cout<< x<< endl;
//    }
    return 0;
}
