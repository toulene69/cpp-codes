//
//  Solutions.cpp
//  LLSolutions
//
//  Created by Apoorv on 09/08/17.
//  Copyright © 2017 presonal. All rights reserved.
//

#include "Solutions.hpp"



ListNode* deleteDuplicates(ListNode* A) {
    ListNode *res = NULL, *temp = NULL;
    res = temp = A;
    A=A->next;
    while (A!=NULL)
    {
        if (temp->val != A->val) {
            temp->next = A;
            temp = A;
        }
        A = A->next;
    }
    temp->next = NULL;
    return res;
}

ListNode* deleteDuplicates2(ListNode* A) {
    ListNode *res = NULL, *temp = NULL, *temp2 = NULL;
    
    while (A!=NULL)
    {
        temp =A->next;
        if (temp && A->val == temp->val) {
            while (temp && A->val == temp->val) {
                temp = temp->next;
            }
            A = temp;
        }
        else
        {
            if (res) {
                temp2->next = A;
                temp2 = A;
            }
            else
            {
                res = A;
                temp2 = res;
            }
            A = A->next;
        }
    }
    if (temp2) {
        temp2->next = NULL;
    }
    
    return res;
}

ListNode* mergeTwoLists(ListNode* A, ListNode* B) {
    ListNode* res = NULL, *temp = NULL;
    while (A && B) {
        ListNode *i;
        if (A->val <= B->val) {
            i = A;
            A = A->next;
        }
        else  {
            i = B;
            B = B->next;
        }
        if (res) {
            temp->next = i;
            temp = i;
        }
        else {
            res = i;
            temp = res;
        }
    }
    ListNode *i = NULL;
    if (A == NULL && B) {
        i = B;
    }
    else if (B==NULL && A) {
        i = A;
    }
    if (res) {
        temp->next = i;
    }
    else {
        res = i;
    }
    return res;
}


ListNode* removeNthFromEnd(ListNode* A, int B) {
    ListNode *res = A;
    ListNode *start, *end;
    start = end = A;
    while (B>0) {
        end = end->next;
        if (end == NULL) {
            return A->next;
        }
        B--;
    }
    while (end->next) {
        end = end->next;
        start = start->next;
    }
    if (start->next) {
        start->next = start->next->next;
    }
    else {
        start->next = NULL;
    }
    
    return res;
}

ListNode *rotateRight(ListNode* A, int B) {
    
    int l = 0;
    ListNode *res, *start=A, *end=A;
    while (end) {
        l++;
        end = end->next;
    }
    int r = B%l;
    if (r==0) {
        return A;
    }
    end = A;
    while (r>0) {
        end = end->next;
        r--;
    }
    while (end->next) {
        start = start->next;
        end = end->next;
    }
    res = start->next;
    start->next = NULL;
    end->next = A;
    return res;
}

ListNode* reverseBetween(ListNode* A, int m, int n) {
    int w = n-m;
    ListNode *res, *start, *end, *prestart ,*prev;
    start = end = A;
    prestart = NULL;
    while (w>0) {
        end = end->next;
        w--;
    }
    while (m>1) {
        prestart = start;
        start = start->next;
        end = end->next;
        m--;
    }
    ListNode *first, *last,*temp;
    first = start;
    last = end->next;
    end->next = NULL;
    res = A;
    prev = NULL;
    while (start) {
        temp = start->next;
        start->next = prev;
        prev = start;
        start = temp;
    }
    first->next = last;
    if (prestart) {
        prestart->next = end;
        return res;
    }
    else
        return end;
}


/**
 L1->Ln->L2->Ln-1->L3->Ln-2 ...

 */
ListNode* reorderList(ListNode* A) {
    ListNode *res, *fast, *slow, *prev, *l1,*l2, *temp1, *temp2;
    res = NULL;
    slow = A;
    fast = A->next;
    while (fast && fast->next != NULL) { // find the mid of the list
        slow = slow->next;
        fast = fast->next->next;
    }
    prev = NULL;
    fast = slow->next;
    slow->next = NULL;
    slow = fast;
    while (slow) { // reverse the second half of the list
        fast = slow->next;
        slow->next = prev;
        prev = slow;
        slow = fast;
    }
    l1 = A;
    l2 = prev;
    slow = NULL;
    res = NULL;
    while (l1 && l2) {
        temp1 = l1;
        l1 = l1->next;
        temp1->next = NULL;
        temp2 = l2;
        l2 = l2->next;
        temp2->next = NULL;
        if (res) {
            slow->next = temp1;
            slow->next->next = temp2;
            slow = slow->next->next;
        }
        else {
            res = temp1;
            res->next = temp2;
            slow = res->next;
        }
    }
    if (slow) {
        if (l1) {
            slow->next = l1;
        }
        else {
            slow->next = l2;
        }
    }
    if (res) {
        return res;
    }
    else {
        return  A;
    }
}


ListNode* partition(ListNode* A, int B) {
    ListNode *res,*temp1, *temp2, *l1,*l2;
    l1 = l2 = temp1 = temp2 = NULL;
    while (A) {
        if (A->val < B) {
            if (l1) {
                temp1->next = A;
                temp1 = temp1->next;
            }
            else {
                l1 = A;
                temp1 = l1;
            }
        }
        else {
            if (l2) {
                temp2->next = A;
                temp2 = temp2->next;
            }
            else {
                l2 = A;
                temp2 = l2;
            }
        }
        A = A->next;
    }
    if (l1) {
        res = l1;
    }
    else {
        res = l2;
    }
    
    if (temp1) {
        temp1->next = l2;
    }
    if (temp2) {
        temp2->next = NULL;
    }
    
    return res;
}

ListNode* insertionSortList(ListNode* A) {
    ListNode *pre,*temp,*it;
    temp = NULL;
    pre = A;
    it = A->next;
    while (it) {
        temp = A;
        ListNode *p = NULL;
        while (temp!=it && temp->val <= it->val) {
            p = temp;
            temp = temp->next;
        }
        if (temp != it) {
            temp = it->next;
            if (p) {
                ListNode *x = p->next;
                p->next = it;
                it->next = x;
            }
            else {
                it->next = A;
                A = it;
            }
            pre->next = temp;
            it = temp;
        }
        else {
            pre = it;
            it = it->next;
        }
    }
    return A;
}


ListNode* merge_sort(ListNode *start, ListNode *end)
{
    if (start == end) {
        return start;
    }
    if (start->next == NULL) {
        return start;
    }
    if (start == NULL) {
        return NULL;
    }
    ListNode *slow, *fast;
    slow = start;
    fast = start->next;
    while (fast && fast->next!=NULL && fast != end) {
        slow = slow->next;
        fast = fast->next->next;
    }
    fast = slow->next;
    slow->next = NULL;
    slow = fast;
    ListNode *a = merge_sort(start, slow);
    ListNode *b = merge_sort(slow, end);
    return  mergeTwoLists(a, b);
}


/**
 Sort list in O(nlogn) Merge sort
 
 @param A list
 @return sorted list
 */
ListNode* sortList(ListNode* A) {
    
    return merge_sort(A, NULL);
}
