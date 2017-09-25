//
//  SolutionHeapsMaps.cpp
//  HeapsMaps
//
//  Created by Apoorv on 24/09/17.
//  Copyright © 2017 presonal. All rights reserved.
//

#include "SolutionHeapsMaps.hpp"

map<int, Node*> m;
deque<Node*> q;
int size  = 0;

void  moveNodeToFront(Node *node) {
    deque<Node *>::iterator it;// = std::find(this->q.begin(), this->q.end());
    for (it = q.begin(); it != q.end(); ++it) {
        if ((*it)->key == node->key) {
            break;
        }
    }
    if (it!= q.end()) {
        q.erase(it);
    }
    q.push_front(node);
    
}

LRUCache::LRUCache(int capacity) {
    size  = capacity;
    m.clear();
    q.clear();
}

int LRUCache::get(int key) {
    map<int, Node*> :: iterator it = m.find(key);
    if (it != m.end()) {
        moveNodeToFront(it->second);
        return it->second->value;
    }
    else {
        return -1;
    }
}

void LRUCache::set(int key, int value) {
    map<int, Node*> :: iterator it = m.find(key);
    Node *n = NULL;
    if (it != m.end()) {
        it->second->value = value;
        n = it->second;
    }
    else {
        n = new Node(key,value);
        if (m.size() >= size) {
            Node *least = q.back();
            q.pop_back();
            m.erase(least->key);
        }
        m[key] = n;
    }
    moveNodeToFront(n);
}




#define MAXN 105

long long int dp[MAXN];      /* dp[i] = number of max heaps for i distinct integers */
long long int nck[MAXN][MAXN];    /* nck[i][j] = i choose j if i>=j else 0 */
int log_2[MAXN];            /* log_2[i] = int(log_2 base 2 of i) */
long long int MOD = 1000000007;

long long int choose(int n,int k)
{
    if(k>n)
        return 0;
    if(n<=1)
        return 1;
    if(k==0)
        return 1;
    
    if(nck[n][k]!=-1)
        return nck[n][k];
    long long int answer = choose(n-1,k-1) + choose(n-1,k);
    answer%=MOD;
    nck[n][k] = answer;
    return answer;
}

int getL(int n)
{
    if(n==1)
        return 0;
    
    int h = log_2[n];
    int p = n - ((1<<(h)) - 1);
    int m = (1<<h);
    if(p>=(m/2))
        return (1<<(h)) - 1;
    else
        return (1<<(h)) - 1 - ((m/2) - p);
}

long long int getNumberOfMaxHeaps(int n)
{
    if(n<=1)
        return 1;
    
    if(dp[n]!=-1)
        return dp[n];
    
    int L = getL(n);
    long long int ans = (choose(n-1,L)*getNumberOfMaxHeaps(L))%MOD*(getNumberOfMaxHeaps(n-1-L));
    ans%=MOD;
    dp[n] = ans;
    return ans;
}

int numberOfPossibleMaxHeaps(int n)
{
    for(int i=0;i<=n;i++)
        dp[i]=-1;
    
    for(int i=0;i<=n;i++)
        for(int j=0;j<=n;j++)
            nck[i][j] = -1;
    
    int currlog_2Answer = -1;
    int currPower2 = 1;
    for(int i=1;i<=n;i++)
    {
        if(currPower2==i)
        {
            currlog_2Answer++;
            currPower2*=2;
        }
        log_2[i] = currlog_2Answer;
    }
    
    return (int)getNumberOfMaxHeaps(n);
}

struct compare {
    bool operator()(const void *a, const void *b)
    {
        return ((ListNode*)a)->val > ((ListNode*)b)->val;
    }
};

ListNode* mergeKLists(vector<ListNode*> &A) {
    ListNode *res , * temp;
    res = temp = NULL;
    priority_queue< ListNode* ,vector<ListNode*>, compare > q(A.begin(),A.end());
    while (!q.empty()) {
        ListNode *top = q.top();
        q.pop();
        if (!res) {
            res = top;
            temp = res;
        }
        else {
            temp->next = top;
            temp = temp->next;
        }
        top = top->next;
        if (top) {
            q.push(top);
        }
    }
    
    return res;
}


vector<int> distinctNumsInWindow(vector<int> &A, int B) {
    vector<int> res;
    map<int, int> m;
    if (B>A.size()) {
        for (int i=0; i<A.size(); i++) {
            m[A[i]]++;
        }
        res.push_back(m.size());
    }
    else {
        for (int i=0; i<B; i++) {
            m[A[i]]++;
        }
    }
    for (int i = 0; i+B <= A.size(); i++) {
        res.push_back(m.size());
        m[A[i]] -- ;
        if (m[A[i]] == 0) {
            m.erase(A[i]);
        }
        m[A[i+B]]++;
    }
    
    return res;
}


int nchoc(int A, vector<int> &B) {
    int res = 0;
    int m = 1000000007;
    priority_queue<int> q (B.begin(),B.end());
    while (A>0) {
        int top = q.top();;
        res = ((res % m) + (top%m))%m;
        q.pop();
        q.push(top/2);
        A--;
    }
    return res;
}


vector<int> solve(vector<int> &A, vector<int> &B) {
    priority_queue<pair<int, pair<int, int> > > hp;
    set<pair<int, int> > S;
    int n = A.size();
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    
    hp.push(make_pair(A[n-1]+B[n-1], make_pair(n-1, n-1)));
    S.insert(make_pair(n-1, n-1));
    
    vector<int> ans;
    int k=n;
    while(k--){
        pair<int, pair<int, int> > top = hp.top();
        hp.pop();
        ans.push_back(top.first);
        int L = top.second.first;
        int R = top.second.second;
        
        if( R>0 && L>=0  && S.find(make_pair(L,R-1)) == S.end() ){
            hp.push(make_pair(A[L]+B[R-1], make_pair(L,R-1)));
            S.insert(make_pair(L,R-1));
        }
        if( R>=0  && L>0 && S.find(make_pair(L-1, R))==S.end()){
            hp.push(make_pair(A[L-1]+B[R], make_pair(L-1,R)));
            S.insert(make_pair(L-1, R));
        }
    }
    return ans;
}
