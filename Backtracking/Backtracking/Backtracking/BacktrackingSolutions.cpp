//
//  BacktrackingSolutions.cpp
//  Backtracking
//
//  Created by Apoorv on 17/08/17.
//  Copyright © 2017 presonal. All rights reserved.
//

#include "BacktrackingSolutions.hpp"

void backtrack_letterCombinations(string &a, int i, string temp ,vector<string> &res, map<char,string> &m) {
    if (i == a.length()) {
        if (temp.length() == a.length()) {
            res.push_back(temp);
        }
        return;
    }
    map<char, string>:: iterator it = m.find(a[i]);
    string s = it->second;
    for (int k = 0; k <s.length(); ++k) {
        temp.push_back(s[k]);
        backtrack_letterCombinations(a,i+1,temp,res,m);
        temp.pop_back();
    }

}

vector<string> letterCombinations(string A) {
    map<char,string> m;
    m.insert(make_pair('1', "1"));
    m.insert(make_pair('2', "abc"));
    m.insert(make_pair('3', "def"));
    m.insert(make_pair('4', "ghi"));
    m.insert(make_pair('5', "jkl"));
    m.insert(make_pair('6', "mno"));
    m.insert(make_pair('7', "pqrs"));
    m.insert(make_pair('8', "tuv"));
    m.insert(make_pair('9', "wxyz"));
    m.insert(make_pair('0', "0"));
    sort(A.begin(), A.end());
    vector<string> res;
    backtrack_letterCombinations(A,0,"",res,m);
    return res;
}

void backtrack_permute(int i,  vector<int> a, vector<vector<int>>&res) {
    if (i == a.size()) {
        res.push_back(a);
        return;
    }
    
    for (int j = i; j<a.size(); ++j) {
        int temp = a[j];
        a[j] = a[i];
        a[i] = temp;
        backtrack_permute(i+1, a, res);
        temp = a[j];
        a[j] = a[i];
        a[i] = temp;
    }
}


vector<vector<int> > permute(vector<int> &A) {
    vector<vector<int>> res;
    vector<int>temp;
    backtrack_permute(0,A,res);
    return res;
}


void backTrackSubset(int i, vector<int> &a, vector<int> temp, vector<vector<int>> &res) {

    if (i == a.size()) {
        res.push_back(temp);
        return;
    }
    temp.push_back(a[i]);
    backTrackSubset(i+1,a,temp,res);
    temp.pop_back();
    backTrackSubset(i+1, a, temp, res);
}

void backtrack_combine(int i, int n, int k, vector<int> temp, vector<vector<int>> &res) {
    if (i>n) {
        if (temp.size()==k) {
            res.push_back(temp);
        }
        return;
        
    }
    if (temp.size() == k) {
        res.push_back(temp);
        return;
    }
    temp.push_back(i);
    backtrack_combine(i+1, n, k, temp, res);
    temp.pop_back();
    backtrack_combine(i+1, n, k, temp, res);
}


set<vector<int>> s;
void backtrack_combinationSum(vector<int> &a, int i, int cur, int sum, vector<int> temp,vector<vector<int>> &res) {
    if (i== a.size()) {
        return;
    }
    if (cur>sum) {
        return;
    }
    if (cur == sum) {
        set<vector<int>>::iterator it = s.find(temp);
        if (it == s.end()) {
            sort(temp.begin(), temp.end());
            s.insert(temp);
            res.push_back(temp);
        }
        return;
    }
    if (cur+a[i] <= sum) {
        temp.push_back(a[i]);
        backtrack_combinationSum(a, i, cur+a[i], sum, temp, res);
        backtrack_combinationSum(a, i+1, cur+a[i], sum, temp, res);
        temp.pop_back();
    }
    backtrack_combinationSum(a, i+1, cur, sum, temp, res);
}

void backtrack_combinationSum2(vector<int> &a, int i, int cur, int sum, vector<int> temp,vector<vector<int>> &res) {
    if (cur == sum) {
        set<vector<int>>::iterator it = s.find(temp);
        if (it == s.end()) {
            sort(temp.begin(), temp.end());
            s.insert(temp);
            res.push_back(temp);
        }
        return;
    }
    if (i== a.size()) {
        return;
    }
    if (cur>sum) {
        return;
    }
    if (cur == sum) {
        set<vector<int>>::iterator it = s.find(temp);
        if (it == s.end()) {
            sort(temp.begin(), temp.end());
            s.insert(temp);
            res.push_back(temp);
        }
        return;
    }
    temp.push_back(a[i]);
    backtrack_combinationSum2(a, i+1, cur+a[i], sum, temp, res);
    temp.pop_back();
    backtrack_combinationSum2(a, i+1, cur, sum, temp, res);
}

vector<vector<int> > combinationSum2(vector<int> &A, int B) {
    s.clear();
    sort(A.begin(), A.end());
    vector<vector<int>> res;
    vector<int> temp;
    backtrack_combinationSum2(A, 0, 0, B, temp, res);
    //sort(res.begin(), res.end());
    return res;
}

vector<vector<int> > combinationSum(vector<int> &A, int B) {
    s.clear();
    sort(A.begin(), A.end());
    vector<vector<int>> res;
    vector<int> temp;
    backtrack_combinationSum(A, 0, 0, B, temp, res);
    sort(res.begin(), res.end());
    return res;
}

vector<vector<int> > combine(int n, int k) {
    vector<vector<int>> res;
    vector<int> temp;
    backtrack_combine(1, n, k, temp, res);
    //sort(res.begin(), res.end());
    return res;
}

void backtrack_subsetsWithDup(int i, vector<int> temp, vector<int>a, vector<vector<int>> &res) {
    if (i==a.size()) {
        set<vector<int>>::iterator it = s.find(temp);
        if (it==s.end()) {
            s.insert(temp);
            res.push_back(temp);
        }
        return;
    }
    temp.push_back(a[i]);
    backtrack_subsetsWithDup(i+1,temp,a,res);
    temp.pop_back();
    backtrack_subsetsWithDup(i+1,temp,a,res);
}

vector<vector<int> > subsetsWithDup(vector<int> &A) {
    vector<vector<int>> res;
    vector<int> temp;
    sort(A.begin(), A.end());
    backtrack_subsetsWithDup(0,temp,A,res);
    sort(res.begin(), res.end());
    return res;
}

vector<vector<int> > subsets(vector<int> &A) {
    vector<vector<int>> res;
    vector<int> temp;
    sort(A.begin(), A.end());
    backTrackSubset(0, A, temp, res);
    sort(res.begin(), res.end());
    return res;
}

int Mod(int x, int n, int p) {
    if (n == 0) return 1 % p;
    long long y = 0;
    if (n % 2 == 0) {
        y = Mod(x, n/2, p);
        y = (y * y) % p;
    } else {
        y = x % p;
        y = (y * Mod(x, n - 1, p)) % p;
    }
    // Incase y is negative.
    return (int)((y + p) % p);
}

ListNode *rev(ListNode *A) {
    if (A->next->next == NULL) {
        ListNode *q = A->next;
        q->next = A;
        return q;
    }
    ListNode *head = rev(A->next);
    ListNode *q = A->next;
    q->next = A;
    return head;
}

ListNode* reverseList(ListNode* A) {
    if (A == NULL || A->next == NULL  ) {
        return A;
    }
    ListNode *head = rev(A);
    A->next = NULL;
    return head;
}

