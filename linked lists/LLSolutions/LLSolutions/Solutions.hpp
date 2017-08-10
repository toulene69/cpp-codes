//
//  Solutions.hpp
//  LLSolutions
//
//  Created by Apoorv on 09/08/17.
//  Copyright © 2017 presonal. All rights reserved.
//

#ifndef Solutions_hpp
#define Solutions_hpp

#include <stdio.h>
#include <vector>
#include <iterator>

using namespace std;

struct ListNode {
         int val;
         ListNode *next;
         ListNode(int x) : val(x), next(NULL) {}
};

ListNode* deleteDuplicates(ListNode* A);

ListNode* deleteDuplicates2(ListNode* A); // keep only distinct nodes in LL

ListNode* mergeTwoLists(ListNode* A, ListNode* B);

ListNode* removeNthFromEnd(ListNode* A, int B);

ListNode *rotateRight(ListNode* A, int B);

ListNode* reverseBetween(ListNode* A, int m, int n);

ListNode* reorderList(ListNode* A);

ListNode* partition(ListNode* A, int B);

ListNode* insertionSortList(ListNode* A);

ListNode* sortList(ListNode* A);

#endif /* Solutions_hpp */
