//
//  SolutionTrees.cpp
//  Trees
//
//  Created by Apoorv on 27/09/17.
//  Copyright © 2017 presonal. All rights reserved.
//

#include "SolutionTrees.hpp"


#define F first
#define S second

class SegTree{
public:
    int n;
    int *tree;
    
    SegTree(int nn){
        n=nn;
        tree=new int[5*nn+5];
        memset(tree,0,sizeof(tree));
        build(0,n-1,0);
    }
    
    int build(int l,int r,int i){
        if(l>r) return 0;
        if(l==r) {
            tree[i]=1;
            return 1;
        }
        int mid=(l+r)/2;
        int L=build(l,mid,left(i));
        int R=build(mid+1,r,right(i));
        tree[i]=L+R;
        return tree[i];
    }
    
    int update(int i,int value,int l,int r,int index){
        if(l>r) return 0;
        if(l==r) {
            tree[index]=value;
            return value;
        }
        int mid=(l+r)/2;
        int L=0,R=0;
        if(i<=mid) L=update(i,value,l,mid,left(index));
        else R=update(i,value,mid+1,r,right(index));
        
        return tree[index]=tree[left(index)] + tree[right(index)];
    }
    
    int query(int spaces,int l,int r,int i){
        if(l>r) return -1;
        int left_spaces=tree[left(i)];
        int right_spaces=tree[right(i)];
        
        if(l==r) return l;
        
        if(left_spaces>=spaces) {
            return query(spaces,l,(l+r)/2,left(i));
        }
        else {
            return query(spaces-left_spaces,(l+r)/2+1,r,right(i));
        }
    }
    
    int left(int i){
        return 2*i+1;
    }
    
    int right(int i){
        return 2*i+2;
    }
};

vector<int> order(vector<int> &heights, vector<int> &infronts) {
    
    vector< pair<int,int> > v;
    int n=heights.size();
    vector<int> ans(n);
    
    for(int i=0;i<n;i++){
        v.push_back(make_pair(heights[i],infronts[i]));
    }
    
    sort(v.begin(),v.end());
    
    SegTree s(n);
    
    for(int i=0;i<n;i++){
        int index=s.query(v[i].second+1,0,n-1,0); // where is v[i].second th empty position
        ans[index]=v[i].first;
        //cout<<index<<endl;
        s.update(index,0,0,n-1,0);
    }
    
    return ans;
}



struct TrieNode {
    unordered_map<char, TrieNode*> child;
    bool isEnd;
    int count;
};

//Trie node
struct node{
    bool exist;
    node* arr[26];
    node(bool bul=false){
        exist = bul;
        for(int i=0; i<26; i++)    arr[i] = NULL;
    }
};

void add(string s, TrieNode *root)
{
    int n = s.size();
    unordered_map<char, TrieNode*>::iterator it;
    for (int i = 0; i<n; i++) {
        it = root->child.find(s[i]);
        if (it == root->child.end()) {
            root->child[s[i]] = new TrieNode;
            root->child[s[i]]->count = 0;
        }
        root->count += 1;
        root = root->child[s[i]];
    }
    root->isEnd = true;
}

string unique_prefix(string s, TrieNode *root)
{
    unordered_map<char, TrieNode*>::iterator it;
    string r;
    r.push_back(s.front());
    root = root->child[s.front()];
    for(int i =1 ; i<s.size();i++)
    {
        if (root->count <= 1) {
            break;
        }
        r.push_back(s[i]);
        root = root->child[s[i]];
    }
    
    return r;
}

vector<string> prefix(vector<string> &A) {
    vector<string> res;
    TrieNode *root = new TrieNode;
    root->count = 0;
    for (int i=0; i<A.size(); i++) {
        add(A[i], root);
    }
    for (int i=0; i<A.size(); i++) {
        res.push_back(unique_prefix(A[i], root));
    }
    return res;
}


bool cmp(const pair<int, int>& a, const pair<int, int>& b){
    if(a.F == b.F) return a.S < b.S;
    return a.F > b.F;
}

void add(string s,node* trie){
    //add a node to the trie
    int n = s.size();
    for(int i=0; i<n; i++){
        if(trie->arr[s[i]-'a']==NULL)    trie->arr[s[i]-'a'] = new node();
        trie = trie->arr[s[i]-'a'];
    }
    trie->exist=true;
    return;
}

bool search(string s,node* trie){
    //search for a node in the trie
    for(int i=0; i<s.size(); i++){
        if(trie->arr[s[i]-'a']==NULL)    return false;
        trie = trie->arr[s[i]-'a'];
    }
    return trie->exist;
}

void convert(string &str){
    //Convert _ to spaces
    for(int i=0; i<str.size(); i++)    if(str[i]=='_')    str[i]=' ';
    return;
}

vector<int> solve(string good, vector<string>& review){
    convert(good);
    node* trie = new node();
    string word;
    stringstream ss;
    ss<<good;
    while(ss>>word)    add(word,trie);
    int n = review.size();
    int k;
    vector<pair<int,int> > rating(n);
    for(int i=0; i<n; i++){
        convert(review[i]);
        ss.clear();
        ss<<review[i];
        k=0;
        while(ss>>word)    if(search(word,trie))    k++;
        rating[i].first = k;    rating[i].second = i;
    }
    sort(rating.begin(),rating.end(),cmp);
    vector<int> ans(n);
    for(int i=0; i<n; i++)    ans[i] = rating[i].second;
    return ans;
}



class Trie
{
private:
    TrieNode *root;
    public:
    Trie(){
        root = new TrieNode;
    }
    void add(string word) {
        TrieNode *node = this->root;
        for (int i= 0; i<word.size(); i++) {
            if (node->child.find(word[i]) == node->child.end() ) {
                node->child[word[i]] = new TrieNode ;
                node = node->child[word[i]];
            }
        }
        node->isEnd = true;
    }
    
    bool search(string word) {
        TrieNode *node = this->root;
        for (int i= 0; i<word.size(); i++) {
            if (node->child.find(word[i]) != node->child.end() ) {
                node = node->child[word[i]];
            }
            else {
                return false;
            }
        }
        return node->isEnd;
    }
};

bool compare(pair<int, int>a, pair<int, int>b)
{
    if (a.second == b.second) {
        return a.first < b.first;
    }
    return a.second > b.second;
}

void convertTxt(string &txt)
{
    for(int i = 0 ;i<txt.size();i++) {
        if (txt[i] == '_') {
            txt[i] = ' ';
        }
    }
}

vector<int> hotelReviews(string A, vector<string> &B) {
    int n = B.size();
    vector<int> res(n);
    vector<pair<int, int>> counts(n);
    string word;
    convertTxt(A);
    stringstream ss;
    Trie *t = new Trie();
    ss<<A;
    while (ss>>word) {
        t->add(word);
    }
    for (int i=0; i<n; i++) {
        ss.clear();
        convert(B[i]);
        ss<<B[i];
        int matches = 0;
        while (ss>>word) {
            if (t->search(word)) {
                matches++;
            }
        }
        counts[i].first = i;
        counts[i].second = matches;
    }
    sort(counts.begin(), counts.end(), compare);
    for (int x = 0; x<n ; x++) {
        res[x] = counts[x].first;
    }
    return res;
}


TreeNode* flattenBinaryTree1(TreeNode* A) {
    if (!A) {
        return NULL;
    }
    if (A->left) {
        TreeNode *r = A->right;
        TreeNode *l = A->left;
        A->right = l;
        A->left = NULL;
        TreeNode *resL = flattenBinaryTree1(l);
        resL->right = r;
        TreeNode *resR = flattenBinaryTree1(r);
        if(resR)
            return resR;
        if(resL)
            return resL;
        return A;
    }
    else if(A->right) {
        TreeNode *resR = flattenBinaryTree1(A->right);
        if(resR)
            return resR;
        return A;
    }
    else {
        return A;
    }
}

TreeNode* flattenBinaryTree(TreeNode* A) {
    flattenBinaryTree1(A);
    return A;
}

int lca1(TreeNode* A, int val1, int val2, int &c) {
    if (!A) {
        return -1;
    }
    int l = lca1(A->left, val1, val2, c);
    int r = lca1(A->right, val1, val2, c);
    if (l == -1 && r == -1) {
        if (A->val == val1 && A->val == val2) {
            c = 2;
            return A->val;
        }
        if (A->val == val1 || A->val == val2) {
            c++;
            return A->val;
        }
        return -1;
    }
    if (l == -1) {
        if (A->val == val2) {
            c++;
            return A->val;
        }
        else if (A->val == val1) {
            c++;
            return A->val;
        }
        else {
            return r;
        }
    }
    else if (r == -1) {
        if (A->val == val2) {
            c++;
            return A->val;
        }
        else if (A->val == val1) {
            c++;
            return A->val;
        }
        else {
            return l;
        }
    }
    else {
            return A->val;
    }
}

int lca(TreeNode* A, int val1, int val2)
{
    int c = 0;
    int res = lca1(A, val1, val2, c);
    if (c == 2) {
        return res;
    }
    return -1;
}

void findSumNumbers(TreeNode* node, long long &sum, long long curr)
{
    if (curr) {
        curr = curr*10 + node->val;
    }
    else {
        curr += node->val;
    }
    curr %= 1003;
    if (!(node->left) && !(node->right)) {
        sum += curr;
        sum %= 1003;
        return;
    }
    if (node->left) {
        findSumNumbers(node->left, sum, curr);
    }
    if (node->right) {
        findSumNumbers(node->right, sum, curr);
    }
}

int sumNumbers(TreeNode* A) {
    long long res = 0;
    long long cur = 0;
    findSumNumbers(A, res, cur);
    return (int)res;
}

void findPathSums(TreeNode *node, vector<vector<int>> &res, vector<int> temp, int k )
{
    if (!(node->left) && !(node->right)) {
        if ((k - node->val) == 0) {
            temp.push_back(node->val);
            res.push_back(temp);
        }
        else {
            return;
        }
    }
    temp.push_back(node->val);
    if (node->left) {
        findPathSums(node->left, res, temp, k - node->val);
    }
    if (node->right) {
        findPathSums(node->right, res, temp, k - node->val);
    }
}

vector<vector<int> > pathSum(TreeNode* root, int sum) {
    vector<vector<int>> res;
    vector<int> temp;
    findPathSums(root, res, temp, sum);
    return res;
}

int hasPathSum(TreeNode* A, int B) {
    if (!(A->left) && !(A->right)) {
        if ((B - A->val)==0) {
            return 1;
        }
        return 0;
    }
    int l = 0,r = 0;
    if (A->left) {
        l = hasPathSum(A->left, B - A->val);
    }
    if (A->right) {
        r = hasPathSum(A->right, B - A->val);
    }
    if (l || r) {
        return 1;
    }
    return 0;
}

struct TreeLinkNode *getNextRight(struct TreeLinkNode *p)
{
    struct TreeLinkNode *temp = p->next;
    
    /* Traverse nodes at p's level and find and return
     the first node's first child */
    while (temp != NULL)
    {
        if (temp->left != NULL)
            return temp->left;
        if (temp->right != NULL)
            return temp->right;
        temp = temp->next;
    }
    
    // If all the nodes at p's level are leaf nodes then return NULL
    return NULL;
}

/* Sets nextRight of all nodes of a tree with root as p */
void connect(struct TreeLinkNode* p)
{
    struct TreeLinkNode *temp;
    
    if (!p)
        return;
    
    // Set nextRight for root
    p->next = NULL;
    
    // set nextRight of all levels one by one
    while (p != NULL)
    {
        struct TreeLinkNode *q = p;
        
        /* Connect all childrem nodes of p and children nodes of all other nodes
         at same level as p */
        while (q != NULL)
        {
            // Set the nextRight pointer for p's left child
            if (q->left)
            {
                // If q has right child, then right child is nextRight of
                // p and we also need to set nextRight of right child
                if (q->right)
                    q->left->next = q->right;
                else
                    q->left->next = getNextRight(q);
            }
            
            if (q->right)
                q->right->next = getNextRight(q);
            
            // Set nextRight for other nodes in pre order fashion
            q = q->next;
        }
        
        // start from the first node of next level
        if (p->left)
            p = p->left;
        else if (p->right)
            p = p->right;
        else
            p = getNextRight(p);
    }
}


vector<vector<int> > zigzagLevelOrder(TreeNode* A) {
    vector<vector<int>> res;
    stack<stack<TreeNode*>> s;
    if (!A) {
        return res;
    }
    stack<TreeNode*> temp;
    temp.push(A);
    s.push(temp);
    bool dirRight = false;
    while (!s.empty()) {
        temp = s.top();
        stack<TreeNode*> temp1;
        vector<int> t;
        while (!temp.empty()) {
            TreeNode *n = temp.top();
            temp.pop();
            if (n) {
                t.push_back(n->val);
                if (dirRight) {
                    temp1.push(n->right);
                    temp1.push(n->left);
                }
                else {
                    temp1.push(n->left);
                    temp1.push(n->right);
                }
            }
        }
        if(t.size()!=0)
            res.push_back(t);
        dirRight = !dirRight;
        s.pop();
        if (temp1.size()!= 0) {
            s.push(temp1);
        }
        
    }
    return res;
}

void inverTreeVertically(TreeNode*pa, TreeNode* a, TreeNode *pb,  TreeNode * b)
{
    if (!a && !b) {
        return;
    }
    if (!a) {
        TreeNode *temp = new TreeNode(b->val);
        if (pb->left == b) {
            pb->left = NULL;
            pa->right = temp;
        }
        else {
            pb->right = NULL;
            pa->left = temp;
        }
        a = temp;
    }
    else if (!b) {
        TreeNode *temp = new TreeNode(a->val);
        if (pa->left == a) {
            pa->left = NULL;
            pb->right = temp;
        }
        else {
            pa->right = NULL;
            pb->left = temp;
        }
        b = temp;
    }
    else {
        int temp = a->val;
        a->val = b->val;
        b->val = temp;
    }
    inverTreeVertically(a, a->left, b, b->right);
    inverTreeVertically(a, a->right, b, b->left);
}

TreeNode* invertTree(TreeNode* root) {
    //inverTreeVertically(root, root->left, root, root->right);
    if (!root) return root;
    root->left = invertTree(root->left);
    root->right = invertTree(root->right);
    TreeNode *temp = root->left;
    root->left = root->right;
    root->right = temp;
    return root;
}


void recoverBST(TreeNode* node, TreeNode **first, TreeNode** middle, TreeNode ** last, TreeNode **prev)
{
    if (!node) {
        return;
    }
    recoverBST(node->left, first, middle, last, prev);
    if (*prev && node->val < (*prev)->val) {
        if (!*first) {
            *first = *prev;
            *middle = node;
        }
        else{
            *last = node;
        }
    }
    *prev = node;
    recoverBST(node->right, first, middle, last, prev);
}

vector<int> recoverTree(TreeNode* A) {
    
    vector<int> res;
    TreeNode *first, *middle, *last, *prev;
    first = middle = last = prev = NULL;
    recoverBST(A, &first, &middle, &last, &prev);
    if (first && last) {
        res = {first->val , last->val };
    }
    else
        res = {first->val, middle->val};
    sort(res.begin(), res.end());
    return res;
}

vector<TreeNode*> s;
BSTIterator::BSTIterator(TreeNode *root) {
    s.clear();
    while (root) {
        s.push_back(root);
        root = root->left;
    }
}

/** @return whether we have a next smallest number */
bool BSTIterator::hasNext() {
    if (s.empty()) {
        return false;
    }
    return true;
}

/** @return the next smallest number */
int BSTIterator::next() {
    if (!s.empty()) {
        TreeNode *node = s.back();
        s.pop_back();
        int r = node->val;
        if (node->right) {
            node = node->right;
            while (node) {
                s.push_back(node);
                node = node->left;
            }
        }
        return r;
    }
    return -1;
}



int find_Val(TreeNode *root, TreeNode* node, int v)
{
    while (root) {
        if (root->val == v) {
            if (root == node) {
                return 0;
            }
            return 1;
        }
        else if (root->val < v) {
            root = root->right;
        }
        else
        {
            root = root->left;
        }
    }
    return 0;
}

bool find2Sum(TreeNode* root, TreeNode* node, int k)
{
    if (!node) {
        return false;
    }
    if (find2Sum(root, node->left, k)) {
        return true;
    }
    if (node->val <= k) {
        if (find_Val(root, node,k - node->val)) {
            return true;
        }
    }
    if (find2Sum(root, node->right, k)) {
        return true;
    }
    else {
        return false;
    }
}

int t2Sum(TreeNode* A, int B)
{
    if (!A) {
        return 0;
    }
    if (find2Sum(A,A,B)) {
        return 1;
    }
    return 0;
}

bool ksmall(TreeNode *root, int *k, int *i, int *val)
{
    if (!root) {
        return false;
    }
    if(ksmall(root->left,k, i,val))
        return true;
    (*i)++;
    if (*i== *k) {
        *val = root->val;
        return true;
    }
    if(ksmall(root->right, k, i, val))
        return true;
    return false;
}

int kthsmallest(TreeNode* root, int k) {
    if (!root) {
        return -1;
    }
    int i = 0;
    int val ;
    ksmall(root, &k, &i, &val);
    return val;
}

TreeNode* constructTreeFromInorderAndPreorder(vector<int>&inorder, int si, int ei, vector<int>& preorder, int sp, int ep)
{
    if (si>ei) {
        return NULL;
    }
    if (si == ei) {
        TreeNode *node = new TreeNode(inorder[si]);
        return node;
    }
    TreeNode *node = new TreeNode(preorder[sp]);
    vector<int> :: iterator it1 = find(inorder.begin()+si, inorder.begin()+ei, preorder[sp]);
    int root_in_inorder = (int)distance(inorder.begin(), it1);

    int pre_left_end = root_in_inorder -si;

    if (root_in_inorder-1 >= si) {
        node->left = constructTreeFromInorderAndPreorder(inorder, si, root_in_inorder-1, preorder, sp+1, sp+pre_left_end);
    }
    if (root_in_inorder+1 <= ei) {
        node->right = constructTreeFromInorderAndPreorder(inorder, root_in_inorder+1, ei, preorder, sp+pre_left_end+1, ep);
    }
    return node;
}

TreeNode* buildTreeFromInorderPreorder(vector<int> &preorder, vector<int> &inorder) {
    if (inorder.size()==0) {
        return NULL;
    }
    TreeNode *root = constructTreeFromInorderAndPreorder(inorder, 0 ,inorder.size()-1, preorder,0, preorder.size()-1);
    return root;
}

TreeNode *constructTreeFromInorderAndPostorder(vector<int> &inorder, int si, int ei, vector<int> &postorder, int sp, int ep)
{
    if (si>ei) {
        return NULL;
    }
    if (si==ei) {
        TreeNode *node = new TreeNode(inorder[si]);
        return node;
    }
    TreeNode *node = new TreeNode(postorder[ep]);
    vector<int> :: iterator it1 = find(inorder.begin()+si, inorder.begin()+ei, postorder[ep]);
    int root_in_inorder = (int)distance(inorder.begin(), it1);
    int post_left_end = root_in_inorder - si;

    if (root_in_inorder-1 >= si) {
        node->left = constructTreeFromInorderAndPostorder(inorder, si, root_in_inorder-1, postorder, sp, sp+post_left_end-1);
    }
    if (root_in_inorder+1 <= ei) {
        node->right = constructTreeFromInorderAndPostorder(inorder, root_in_inorder+1, ei, postorder, sp+post_left_end, ep-1);
    }
    return node;
}

TreeNode* buildTree(vector<int> &inorder, vector<int> &postorder) {
    if (inorder.size()==0) {
        return NULL;
    }
    TreeNode *root = constructTreeFromInorderAndPostorder(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1);
    
    return root;
}

TreeNode* constructTreeFromSortedArray(const vector<int> &a, int s, int e)
{
    if (s>e) {
        return NULL;
    }
    if (s==e) {
        TreeNode *node = new TreeNode(a[s]);
        return node;
    }
    int mid = (s+e)/2;
    TreeNode *node = new TreeNode(a[mid]);
    node ->left = constructTreeFromSortedArray(a, s, mid-1);
    node->right = constructTreeFromSortedArray(a, mid+1, e);
    return node;
}

TreeNode* sortedArrayToBST(const vector<int> &A) {
    if (A.size() ==0 ) {
        return NULL;
    }
    TreeNode *root = constructTreeFromSortedArray(A, 0, A.size()-1);
    return root;
}

TreeNode * buildCartesianTreeUtil (int root, vector<int> &arr,int parent[], int leftchild[], int rightchild[])
{
    if (root == -1)
        return NULL;
    
    // Create a new node with root's data
    TreeNode *temp = new TreeNode(arr[root]);
    
    // Recursively construct left and right subtrees
    temp->left = buildCartesianTreeUtil( leftchild[root],
                                        arr, parent, leftchild, rightchild );
    temp->right = buildCartesianTreeUtil( rightchild[root],
                                         arr, parent, leftchild, rightchild );
    
    return temp ;
}

// A function to create the Cartesian Tree in O(N) time
TreeNode * buildCartesianTree (vector<int> &arr)
{
    int n = arr.size();
    // Arrays to hold the index of parent, left-child,
    // right-child of each number in the input array
    int parent[n],leftchild[n],rightchild[n];
    
    // Initialize all array values as -1
    memset(parent, -1, sizeof(parent));
    memset(leftchild, -1, sizeof(leftchild));
    memset(rightchild, -1, sizeof(rightchild));
    
    // 'root' and 'last' stores the index of the root and the
    // last processed of the Cartesian Tree.
    // Initially we take root of the Cartesian Tree as the
    // first element of the input array. This can change
    // according to the algorithm
    int root = 0, last;
    
    // Starting from the second element of the input array
    // to the last on scan across the elements, adding them
    // one at a time.
    for (int i=1; i<=n-1; i++)
    {
        last = i-1;
        rightchild[i] = -1;
        
        // Scan upward from the node's parent up to
        // the root of the tree until a node is found
        // whose value is greater than the current one
        // This is the same as Step 2 mentioned in the
        // algorithm
        while (arr[last] <= arr[i] && last != root)
            last = parent[last];
        
        // arr[i] is the largest element yet; make it
        // new root
        if (arr[last] <= arr[i])
        {
            parent[root] = i;
            leftchild[i] = root;
            root = i;
        }
        
        // Just insert it
        else if (rightchild[last] == -1)
        {
            rightchild[last] = i;
            parent[i] = last;
            leftchild[i] = -1;
        }
        
        // Reconfigure links
        else
        {
            parent[rightchild[last]] = i;
            leftchild[i] = rightchild[last];
            rightchild[last] = i;
            parent[i] = last;
        }
        
    }
    
    // Since the root of the Cartesian Tree has no
    // parent, so we assign it -1
    parent[root] = -1;
    
    return buildCartesianTreeUtil(root, arr, parent, leftchild, rightchild);
}

int maxIndex(vector<int> &v, int s, int e)
{
    int i = -1;
    int m = INT_MIN;
    for (int x = s;x<=e ; x++) {
        if (v[x]>m) {
            m = v[x];
            i= x;
        }
    }
    return i;
}


void buildTree(TreeNode *root, int s, int e, vector<int>& v)
{
    if (s>e) {
        root = NULL;
        return;
    }
    if (s == e) {
        root->val = v[s];
        root->left = NULL;
        root->right = NULL;
        return;
    }
    int m = maxIndex(v, s, e);
    root->val = v[m];
    
    
    if (s<=m-1) {
        root->left = (TreeNode*) malloc(sizeof(TreeNode));
        buildTree(root->left, s, m-1, v);
    }
    if (m+1 <= e) {
        root->right = (TreeNode*) malloc(sizeof(TreeNode));
        buildTree(root->right, m+1, e, v);
    }
    
}

TreeNode* buildTree(vector<int> &A)
{
    if (A.size() ==0 ) {
        return NULL;
    }
    TreeNode *root = (TreeNode*) malloc(sizeof(TreeNode));
    buildTree(root, 0, A.size()-1, A);
    return root;
}

int minDepth(TreeNode* A) {
    if (!A) {
        return 0;
    }
    int lh = minDepth(A->left);
    int rh = minDepth(A->right);
    if (lh ==0 && rh == 0) {
        return 1;
    }
    if (!lh && rh ) {
        return rh+1;
    }
    if (lh && !rh) {
        return lh+1;
    }
    return min(lh, rh) + 1;
}

int maxDepth(TreeNode* A) {
    if (!A) {
        return 0;
    }
    int lh = maxDepth(A->left);
    int rh = maxDepth(A->right);
    return max(lh, rh) + 1;
}

bool isSymmetric1(TreeNode *a, TreeNode *b)
{
    if (!a && !b) {
        return true;
    }
    if ((!a && b)||(a && !b)){
        return false;
    }
    if (a->val == b->val) {
        return isSymmetric1(a->left, b->right) & isSymmetric1(a->right, b->left);
    }
    else {
        return false;
    }
}

int isSymmetric(TreeNode* A) {
    if (!A) {
        return 1;
    }
    if (isSymmetric1(A->left, A->right)) {
        return 1;
    }
    return 0;
}

int isSameTree(TreeNode* A, TreeNode* B) {
    if (!A && !B) {
        return 1;
    }
    if ((!A && B)||(A && !B)){
        return 0;
    }
    if (A->val == B->val) {
        int l = isSameTree(A->left, B->left);
        int r = isSameTree(A->right, B->right);
        return l&r;
    }
    else {
        return 0;
    }
}

int heightTree(TreeNode *root)
{
    if (!root) {
        return 0;
    }
    int lh = heightTree(root->left);
    int rh = heightTree(root->right);
    if (lh == -1 || rh == -1) {
        return -1;
    }
    if (abs(lh-rh)<=1) {
        return max(lh, rh) + 1;
    }
    else {
        return -1;
    }
}

int isBalanced(TreeNode* A) {
    int h = heightTree(A);
    if (h>=0) {
        return 1;
    }
    return 0;
}

void getVerticalOrder(TreeNode* root, int hd, map<int, vector<int>> &m)
{
    // Base case
    if (root == NULL)
        return;
    m[hd].push_back(root->val);
    
    getVerticalOrder(root->left, hd-1, m);

    getVerticalOrder(root->right, hd+1, m);
}

vector<vector<int>> verticalOrderTraversal1(TreeNode* A) {
    vector<vector<int>> res;
    
    map < int,vector<int> > m;
    int hd = 0;
    getVerticalOrder(A, hd,m);
    
    // Traverse the map and print nodes at every horigontal
    // distance (hd)
    map< int,vector<int> > :: iterator it;
    for (it=m.begin(); it!=m.end(); it++)
    {
        vector<int> a;
        for (int i=0; i<it->second.size(); ++i)
            a.push_back(it->second[i]);
        res.push_back(a);
    }
    
    return res;
}

vector<vector<int>> verticalOrderTraversal(TreeNode *root) {
    vector<vector<int>> res;
    if (!root)
        return res;
    
    // Create a map and store vertical oder in
    // map using function getVerticalOrder()
    map < int,vector<int> > m;
    int hd = 0;
    
    // Create queue to do level order traversal.
    // Every item of queue contains node and
    // horizontal distance.
    queue<pair<TreeNode*, int> > que;
    que.push(make_pair(root, hd));
    
    while (!que.empty())
    {
        // pop from queue front
        pair<TreeNode *,int> temp = que.front();
        que.pop();
        hd = temp.second;
        TreeNode* node = temp.first;
        
        // insert this node's data in vector of hash
        m[hd].push_back(node->val);
        
        if (node->left != NULL)
            que.push(make_pair(node->left, hd-1));
        if (node->right != NULL)
            que.push(make_pair(node->right, hd+1));
    }
    
    // Traverse the map and print nodes at
    // every horigontal distance (hd)
    map< int,vector<int> > :: iterator it;
    for (it=m.begin(); it!=m.end(); it++)
    {
        res.push_back(it->second);
    }
    return res;
}

vector<int> preorderTraversal(TreeNode* A) {
    stack<TreeNode*> s;
    vector<int> res;
    if (A== NULL) {
        return res;
    }
    s.push(A);
    while (!s.empty()) {
        TreeNode *n = s.top();
        res.push_back(n->val);
        s.pop();
        if (n->right) {
            s.push(n->right);
        }
        if (n->left) {
            s.push(n->left);
        }
    }
    
    return res;
}

vector<int> postorderTraversal(TreeNode* A) {
    stack<TreeNode*> s;
    vector<int> res;
    if (A == NULL) {
        return res;
    }
    
    s.push(A);
    while (!s.empty()) {
        TreeNode *n = s.top();
        res.push_back(n->val);
        s.pop();
        if (n->left) {
            s.push(n->left);
        }
        if (n->right) {
            s.push(n->right);
        }
    }
    reverse(res.begin(), res.end());
    return res;
}

vector<int> postorderTraversal1(TreeNode* A) {
    vector<int> res;
    if (!A) {
        return res;
    }
    stack<TreeNode*> parents;
    unordered_map<TreeNode* , int> m;
    TreeNode *n = A;
    while ( n != NULL || !parents.empty()) {
        if (n) {
            if (m.find(n) == m.end()) {
                m[n] = 1;
                parents.push(n);
                n = n->left;
            }
            else {
                if (m[n] == 2) {
                    res.push_back(n->val);
                    parents.pop();
                    if (!parents.empty()) {
                        n = parents.top();
                    }
                    else {
                        n = NULL;
                    }
                }
                else {
                    m[n] = 2;
                    n = n->right;
                }
            }
        }
        else {
            if (!parents.empty()) {
                n = parents.top();
            }
            else {
                n = NULL;
            }
        }
    }
    return res;
}

vector<int> inorderTraversal(TreeNode* A) {
    
    vector<int> res;
    if(!A) {
        return res;
    }
    stack<TreeNode*> parents;
    TreeNode *n = A;
    
    while (n != NULL || !parents.empty()) {
        if (n) {
            parents.push(n);
            n = n->left;
        }
        else {
            n = parents.top();
            parents.pop();
            res.push_back(n->val);
            n = n->right;
        }
    }
    return res;
}


bool isSubtreeLesser(TreeNode *root, int val) {
    if (root ==  NULL) {
        return true;
    }
    if (root->val < val && isSubtreeLesser(root->left, val) && isSubtreeLesser(root->right, val)) {
        return true;
    }
    else {
        return false;
    }
}

bool isSubtreeGreater(TreeNode *root, int val) {
    if (root ==  NULL) {
        return true;
    }
    if (root->val > val && isSubtreeGreater(root->left, val) && isSubtreeGreater(root->right, val)) {
        return true;
    }
    else {
        return false;
    }
}

int isValidBST(TreeNode* A) {
    if (A == NULL) {
        return 1;
    }
    if (isSubtreeLesser(A->left, A->val) && isSubtreeGreater(A->right, A->val) && isValidBST(A->left) && isValidBST(A->right)) {
        return 1;
    }
    return 0;
}

TreeNode* getSuccessor(TreeNode* A, int B) {
    stack<TreeNode *>s;
    if (A == NULL) {
        return NULL;
    }
    TreeNode *root = A;
    TreeNode *parent = NULL;
    TreeNode *node = NULL;
    while (root != NULL && root->val != B) {
        s.push(root);
        if (root->val < B) {
            root = root->right;
        }
        else {
            root = root->left;
        }
    }
    if (root) {
        node = root;
    }
    if (node->right != NULL) {
        TreeNode *rchild = node->right;
        while (rchild->left != NULL) {
            rchild = rchild->left;
        }
        return rchild;
    }
    else {
        while (!s.empty()) {
            parent = s.top();
            if (parent->left == node) {
                return parent;
            }
            else {
                node = parent;
                s.pop();
            }
        }
        return NULL;
    }
}
