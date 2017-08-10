//
//  main.cpp
//  PallindromeString
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

ListNode* getNode(int x)
{
    ListNode *newNode = (ListNode*) malloc(sizeof(ListNode));
    newNode->val = x;
    newNode->next = NULL;
    return newNode;
}

int lPalin(ListNode* A) {
    struct ListNode *newList = NULL;
    ListNode *temp1 = A;
    ListNode *temp2 = A;
    while (temp1!=NULL) {
        if (newList==NULL) {
            newList = getNode(temp1->val);
            temp2 = newList;
        }
        else
        {
            temp2->next = getNode(temp1->val);
            temp2 = temp2->next;
        }
        temp1 = temp1->next;
    }
    ListNode *temp = NULL;
    ListNode *curr = newList;
    ListNode *pre = NULL;
    while (curr!=NULL) {
        temp = curr->next;
        curr->next = pre;
        pre = curr;
        curr = temp;
    }
    newList = pre;
    
    while (newList != NULL && A!=NULL) {
        if (newList->val != A->val) {
            return 0;
        }
        newList = newList->next;
        A = A->next;
    }
    return 1;
    
}

int main(int argc, const char * argv[]) {
    // insert code here...
    ListNode *a = getNode(1);
    a->next = getNode(2);
    a->next->next = getNode(1);
    cout << lPalin(a);
    return 0;
}
