//
//  SolutionTrees.cpp
//  Trees
//
//  Created by Apoorv on 27/09/17.
//  Copyright © 2017 presonal. All rights reserved.
//

#include "SolutionTrees.hpp"

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
