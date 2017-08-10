//
//  main.cpp
//  LLSolutions
//
//  Created by Apoorv on 09/08/17.
//  Copyright © 2017 presonal. All rights reserved.
//

#include <iostream>
#include "Solutions.hpp"

int main(int argc, const char * argv[]) {
    // insert code here...
    cout << "Hello, World!\n";
//    ListNode *n1 = new ListNode(1);
//    ListNode *n2 = new ListNode(2);
//    ListNode *n3 = new ListNode(3);
//    ListNode *n4 = new ListNode(4);
//    ListNode *n5 = new ListNode(5);
//    ListNode *n6 = new ListNode(6);
//    ListNode *n7 = new ListNode(7);
//    ListNode *n8 = new ListNode(8);
//    ListNode *n9 = new ListNode(9);
    
    ListNode *n1 = new ListNode(4);
    ListNode *n2 = new ListNode(1);
    ListNode *n3 = new ListNode(3);
    ListNode *n4 = new ListNode(2);
    ListNode *n5 = new ListNode(5);
    ListNode *n6 = new ListNode(2);
//    ListNode *n7 = new ListNode(7);
    n1->next = n2;
    //n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = n6;
//    n6->next = n7;
//    n7->next = n8;
//    n8->next = n9;
    
    //ListNode *res = deleteDuplicates2(n1);
    ListNode *res = sortList(n1);
    while (res) {
        cout<< res->val<<endl;
        res = res->next;
    }
    
    return 0;
}
