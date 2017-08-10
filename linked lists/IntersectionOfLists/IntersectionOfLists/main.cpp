//
//  main.cpp
//  IntersectionOfLists
//
//  Created by Apoorv on 02/06/17.
//  Copyright © 2017 presonal. All rights reserved.
//

#include <iostream>

using namespace std;

struct ListNode {
         int val;
         ListNode *next;
         ListNode(int x) : val(x), next(NULL) {}
};

ListNode* getIntersectionNode(ListNode* A, ListNode* B) {
    
    ListNode *temp = A;
    int m=0,n=0;
    while (temp!=NULL) {
        m++;
        temp = temp->next;
    }
    temp = B;
    while (temp!=NULL) {
        n++;
        temp = temp->next;
    }
    while (m>n) {
        A = A->next;
        m--;
    }
    while (n>m) {
        B = B->next;
        n--;
    }
    while (A!=NULL && B!=NULL) {
        if (A==B) {
            return A;
        }
        A = A->next;
        B = B->next;
    }
    return NULL;
    
}



int main(int argc, const char * argv[]) {
    
    
    return 0;
}
