//
//  SolutionHeapsMaps.hpp
//  HeapsMaps
//
//  Created by Apoorv on 24/09/17.
//  Copyright © 2017 presonal. All rights reserved.
//

#ifndef SolutionHeapsMaps_hpp
#define SolutionHeapsMaps_hpp

#include <stdio.h>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <math.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct Node {
    int key;
    int value;
    Node(int x, int y) : key(x), value(y) {}
};

class LRUCache {
public:
    LRUCache(int capacity);
    int get(int key);
    void set(int key, int value);
};

vector<int> distinctNumsInWindow(vector<int> &A, int B);

ListNode* mergeKLists(vector<ListNode*> &A);

int numberOfPossibleMaxHeaps(int A);

int nchoc(int A, vector<int> &B);

vector<int> solve(vector<int> &A, vector<int> &B) ;

#endif /* SolutionHeapsMaps_hpp */
