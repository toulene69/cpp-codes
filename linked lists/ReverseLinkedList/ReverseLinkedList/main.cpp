//
//  main.cpp
//  ReverseLinkedList
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


ListNode* reverseList(ListNode* A) {
    ListNode *temp = NULL;
    ListNode *curr = A;
    ListNode *pre = NULL;
    while (curr!=NULL) {
        temp = curr->next;
        curr->next = pre;
        pre = curr;
        curr = temp;
    }
    return pre;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
