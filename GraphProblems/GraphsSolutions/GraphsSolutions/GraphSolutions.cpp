//
//  GraphSolutions.cpp
//  GraphsSolutions
//
//  Created by Apoorv on 04/01/18.
//  Copyright © 2018 presonal. All rights reserved.
//

#include "GraphSolutions.hpp"

UndirectedGraphNode* clone_util(UndirectedGraphNode* original, unordered_map<int, UndirectedGraphNode*>&d) {
    if (original == NULL) {
        return original;
    }
    if (d[original->label]) {
        return d[original->label];
    }
    UndirectedGraphNode *newNode = new UndirectedGraphNode(original->label);
    d[original->label] = newNode;
    for(UndirectedGraphNode* node : original->neighbors) {
        newNode->neighbors.push_back(clone_util(node, d));
    }
    return newNode;
}

UndirectedGraphNode* cloneGraph(UndirectedGraphNode *node) {
    unordered_map<int, UndirectedGraphNode*> dict;
    UndirectedGraphNode* root;
    root = clone_util(node, dict);
    return root;
}


/******************************************************/
void constructPaths(string start, string &end, unordered_map<string, vector<string> > & parents, vector<string> &current, vector<vector<string> > &answer) {
    if (start == end) {
        answer.push_back(current);
        return;
    }
    for (int i = 0; i < parents[start].size(); i++) {
        current.push_back(parents[start][i]);
        constructPaths(parents[start][i], end, parents, current, answer);
        current.pop_back();
    }
    return;
}

vector<vector<string> > findLadders(string start, string end, vector<string> &dictV) {
    unordered_set<string> dict(dictV.begin(), dictV.end());
    vector<vector<string> > answer;
    unordered_map<string, int> distance; // store the distance from start to the current word
    queue<string> q; // FIFO for bfs purpose
    unordered_map<string, vector<string> > parents;
    swap(start, end); // We do this because we construct the path later from end to start
    distance[start] = 1;
    q.push(start);
    while (!q.empty()) {
        string word = q.front();
        q.pop();
        if (word == end) break;
        for (int i = 0; i < word.size(); i++) {
            for (int j = 0; j < 26; j++) {
                string newWord = word;
                newWord[i] = 'a' + j;
                if (dict.find(newWord) != dict.end()) {
                    if (distance.find(newWord) == distance.end()) { // seen for the first time
                        distance[newWord] = distance[word] + 1;
                        q.push(newWord);
                        parents[newWord].push_back(word);
                    } else if (distance[newWord] == distance[word] + 1) { // if it is at the same level
                        parents[newWord].push_back(word);
                    }
                }
            }
        }
    }
    if (distance.find(end) == distance.end()) return answer; // not found
    // backtrack and construct all possible paths now that we know possible optimal parents.
    vector<string> current;
    current.push_back(end);
    constructPaths(end, start, parents, current, answer);
    return answer;
}

int wordLadderLength(string start, string end, vector<string> &dictV) {
    
    queue<string> q;
    unordered_set<string>dict (dictV.begin(), dictV.end());
    unordered_map<string,int> visited;
    set<char> chSet;
    for( string s: dictV ) {
        for (char x : s) {
            chSet.insert(x);
        }
    }
    for (char x : end) {
        chSet.insert(x);
    }
    int c = 0;
    q.push(start);
    visited[start] = 1;
    while (!q.empty()) {
        string w = q.front();
        int l = visited[w];
        q.pop();

        for (int i=0; i<w.length(); i++) {
            for (set<char>::iterator it = chSet.begin(); it!= chSet.end(); it++) {
                char t = w[i];
                w[i]= *it;
                if (w == end) {
                    return l+1;
                }
                if(dict.find(w) != dict.end() && visited.find(w) == visited.end()){
                    q.push(w);
                    visited[w] = l+1;
                }
                w[i] = t;
            }
        }
    }
    
    return 0;
}

int knight(int A, int B, int C, int D, int E, int F) {
    
    vector<vector<int>> board(A, vector<int>(B, INT_MAX));
    board[C-1][D-1] = 0;
    
    queue<pair<int, int>> q;
    int m = A;
    int n = B;
    q.push(make_pair(C-1, D-1));
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        if (x == E-1 && y == F-1) {
            break;
        }
        int moves = board[x][y];
        q.pop();
        if (x-2 >=0 && y-1 >=0 && board[x-2][y-1] > moves+1) {
            board[x-2][y-1] = moves+1;
            q.push(make_pair(x-2, y-1));
        }
        if (x-2 >=0 && y+1 <n && board[x-2][y+1] > moves+1) {
            board[x-2][y+1] = moves+1;
            q.push(make_pair(x-2, y+1));
        }
        if (x+2 <m && y+1 <n && board[x+2][y+1] > moves+1) {
            board[x+2][y+1] = moves+1;
            q.push(make_pair(x+2, y+1));
        }
        if (x+2 <m && y-1 >=0 && board[x+2][y-1] > moves+1) {
            board[x+2][y-1] = moves+1;
            q.push(make_pair(x+2, y-1));
        }
        if (x-1 >=0 && y+2 <n && board[x-1][y+2] > moves+1) {
            board[x-1][y+2] = moves+1;
            q.push(make_pair(x-1, y+2));
        }
        if (x-1 >=0 && y-2 >=0 && board[x-1][y-2] > moves+1) {
            board[x-1][y-2] = moves+1;
            q.push(make_pair(x-1, y-2));
        }
        if (x+1 <m && y-2 >=0 && board[x+1][y-2] > moves+1) {
            board[x+1][y-2] = moves+1;
            q.push(make_pair(x+1, y-2));
        }
        if (x+1 <m && y+2 <n && board[x+1][y+2] > moves+1) {
            board[x+1][y+2] = moves+1;
            q.push(make_pair(x+1, y+2));
        }
    }
    
    
    if (board[E-1][F-1] == INT_MAX) {
        return -1;
    }
    return board[E-1][F-1];
}

/**********************************/
int fibsum(int A) {
    vector<int> fibN;
    fibN.push_back(1);
    int a = 1;
    int b = 1;
    int t;
    while (b<=A) {
        fibN.push_back(b);
        t = a+b;
        a = b;
        b = t;
    }
    int m = fibN.size();
    int n = A+1;
    
    int c = 0;
    int s = A;
    while (!fibN.empty() && s>0) {
        if (s - fibN.back() >= 0) {
            s -= fibN.back();
            c++;
            fibN.pop_back();
        }
        else {
            fibN.pop_back();
        }
    }
    return c;
}

/*********************************************/
ListNode* findMidOfList(ListNode *start) {
    ListNode *slow, *fast;
    slow = fast = start;
    while (fast && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

TreeNode* sortedListToBST(ListNode* A) {
    
    TreeNode *root = NULL;
    if (A == NULL) {
        return root;
    }
    root = (TreeNode *)malloc(sizeof(TreeNode));
    ListNode *mid = findMidOfList(A);
    ListNode *t = A;
    while (t && t->next != mid) {
        t = t->next;
    }
    if (t) {
        t->next = NULL;
    }
    root->val = mid->val;
    
    root->right = sortedListToBST(mid->next);
    if (mid == A) {
        root->left = NULL;
    }
    else {
        root->left = sortedListToBST(A);
    }
    return root;
}

/**********************************/

bool wordsearch_util(vector<string> &a, string &b, int i, int j, int id) {
    if (id == b.length()) {
        return true;
    }
    int m = a.size();
    int n = a[0].length();
    if (i>=0 && i<m && j>=0 && j<n) {
        if (a[i][j] == b[id]) {
            return wordsearch_util(a,b,i+1,j,id+1) || wordsearch_util(a,b,i-1,j,id+1) || wordsearch_util(a,b,i,j+1,id+1) ||
            wordsearch_util(a,b,i,j-1,id+1) ;
        }
        else {
            return false;
        }
    }
    else {
        return false;
    }
}

int wordSearch(vector<string> &A, string B) {
    int m = A.size();
    int n = A[0].length();
    for (int i = 0; i<m; i++) {
        for (int j = 0; j<n; j++) {
            if (wordsearch_util(A, B, i, j, 0)) {
                return 1;
            }
        }
    }
    return 0;
}

bool isStepping(int x){
    int pre = x%10;
    x = x/10;
    bool flag = true;
    while (x) {
        int r = x%10;
        if (abs(pre-r) != 1) {
            flag = false;
            break;
        }
        pre = r;
        x = x/10;
    }
    return flag;
}

vector<int> stepnum(int A, int B) {
    unordered_set<int> _s;
    vector<int> _res;
    for (int i = A; i<=B; i++) {
        if (isStepping(i)) {
            _res.push_back(i);
        }
    }
    return _res;
}

/*************************************************/
class Graph1
{
public:
    vector<vector<int>> adj;     // Pointer to an array containing
    // adjacency lists
    
    Graph1(int V)
    {
        adj.resize(V);
    }
    
    void addEdge(int v, int w)
    {
        adj[v].push_back(w);    // Add w to v’s list.
        adj[w].push_back(v);    // Since the graph is undirected
    }
    
    //  method returns farthest node and its distance from node u
    pair<int, int> bfs(int u)
    {
        //  mark all distance with -1
        vector<int> dis(adj.size(), -1);
        
        queue<int> q;
        q.push(u);
        
        //  distance of u from u will be 0
        dis[u] = 0;
        
        while (!q.empty())
        {
            int t = q.front();       q.pop();
            
            //  loop for all adjacent nodes of node-t
            for (auto it = adj[t].begin(); it != adj[t].end(); it++)
            {
                int v = *it;
                
                // push node into queue only if
                // it is not visited already
                if (dis[v] == -1)
                {
                    q.push(v);
                    
                    // make distance of v, one more
                    // than distance of t
                    dis[v] = dis[t] + 1;
                }
            }
        }
        
        int maxDis = 0;
        int nodeIdx;
        
        //  get farthest node distance and its index
        for (int i = 0; i < adj.size(); i++)
        {
            if (dis[i] > maxDis)
            {
                maxDis = dis[i];
                nodeIdx = i;
            }
        }
        return make_pair(nodeIdx, maxDis);
    }
    
    //  method prints longest path of given tree
    int longestPathLength(int root)
    {
        pair<int, int> t1, t2;
        
        // first bfs to find one end point of
        // longest path
        t1 = bfs(root);
        
        //  second bfs to find actual longest path
        t2 = bfs(t1.first);
        return t2.second;
    }
};

int solve(vector<int> &A) {
    int n = A.size();
    vector<int> dp(n,-1);
    int root = -1;
    for (int i=0; i<n; i++) {
        if (A[i] == -1) {
            root = i;
            dp[i] = 0;
        }
    }
    Graph1 g(n);
    for (int i=0; i<n; i++) {
        if(A[i] != -1)
            g.addEdge(i, A[i]);
    }
    int res = 0;
    
    return g.longestPathLength(root);
}

int largestDistance(vector<int> &A) {
    int n = A.size();
    vector<int> dp(n,-1);
    int root = -1;
    for (int i=0; i<n; i++) {
        if (A[i] == -1) {
            root = i;
            dp[i] = 0;
        }
    }
    
    for (int i=0; i<n; i++) {
        if (A[i] != -1 && dp[i] == -1) {
            queue<int> q;
            int c = 0;
            int j = i;
            while (A[j] != -1 && dp[j] == -1) {
                q.push(j);
                c++;
                j = A[j];
            }
            if (A[j] != -1) {
                c += dp[j];
            }
            while (!q.empty()) {
                dp[q.front()] = c;
                q.pop();
                c--;
            }
        }
    }
    int res = 0;
    for (int i = 0; i<n; i++) {
        for (int j=i+1; j<n; j++) {
            int di = dp[i];
            int dj = dp[j];
            int c1 = i;
            int c2 = j;
            if (A[i] == -1) {
                res = max(res, dj);
            }
            else {
                // calculate LCA
                while (di != dj) {
                    if (di<dj) {
                        c2 = A[c2];
                        dj--;
                    }
                    else {
                        c1 = A[c1];
                        di--;
                    }
                }
                while (c1 != c2) {
                    c1 = A[c1];
                    c2 = A[c2];
                }
                res = max(res, (dp[i] - dp[c1]) + (dp[j] - dp[c2]));
            }
        }
    }
    return res;
}


short rowDir[] = {-1,0,0,1};
short colDir[] = {0,-1,1,0};

short rowDir1[] = {-1,0,0,1,-1,-1,1,1};
short colDir1[] = {0,-1,1,0,-1,1,-1,1};

bool svisited[1000][1000];

bool captureBoard_util(int r, int c, int m, int n, vector<vector<char> > &board) {
    if (svisited[r][c]) {
        if (board[r][c] == 'X') {
            return true;
        }
        else {
            return false;
        }
    }
    
    svisited[r][c] = true;
    bool ret = true;
    for (int x=0; x<4; x++) {
        int row = r+rowDir[x];
        int col = c+colDir[x];
        if ((row >=0 && row <m) && (col>=0 && col<n) && board[row][col]=='O' && !svisited[row][col] ) {
            ret = captureBoard_util(row, col, m, n, board);
//            if (!ret) {
//                return false;
//            }
        }
    }
    if (ret && r>0 && r<m-1 && c>0 && c<n-1) {
        board[r][c] = 'X';
        return true;
    }
    else {
        return false;
    }
}

void captureBoard(vector<vector<char> > &A) {
    int m = A.size();
    int n = A[0].size();
    memset(svisited, false, sizeof(svisited));
    for (int i=0; i<m; i++) {
        for (int j=0; j<n; j++) {
            if (A[i][j] == 'O' && !svisited[i][j]) {
                if(captureBoard_util(i,j,m,n,A)) {
                    if (i>0 && i<m-1 && j>0 && j<n-1) {
                        A[i][j] = 'X';
                    }
                }
            }
        }
    }
}

void visitShape(int r, int c, int m, int n,vector<string>&arr) {
    if (svisited[r][c]) {
        return;
    }
    svisited[r][c] = true;
    for (int x=0; x<4; x++) {
        int row = r+rowDir[x];
        int col = c+colDir[x];
        if ((row >=0 && row <m) && (col>=0 && col<n) && arr[row][col]=='X' && !svisited[row][col] ){
            visitShape(row, col, m, n, arr);
        }
    }
}

int numberOfblackShapes(vector<string> &A) {
    int m = A.size();
    int n = A[0].length();
    memset(svisited, false, sizeof(svisited));
    int numShapes = 0;
    for (int i=0; i<m; i++) {
        for (int j=0; j<n; j++) {
            if (A[i][j] == 'X' && !svisited[i][j]) {
                visitShape(i, j, m, n, A);
                numShapes++;
            }
        }
    }
    return numShapes;
}

/***********************************/
class Graph{
private:
    vector<vector<int>> adj_list;
    
public:
    Graph(int n) {
        adj_list.resize(n+1);
    }
    
    void add_edge(int a, int b) {
        adj_list[a].push_back(b);
    }
    
    bool topological_sort_util(int v, vector<short> &visited) {
        if (visited[v] == 1) {
            return false;
        }
        if (visited[v] == 2) {
            return true;
        }
        visited[v] = 1;
        for(int x: adj_list[v]) {
            if(!topological_sort_util(x, visited))
                return false;
        }
        visited[v] = 2;
        return true;
    }
    
    bool topological_sort() {
        vector<short> visited(adj_list.size(), 0);
        
        for (int i=1; i<adj_list.size(); i++) {
            if (visited[i]==0) {
                if(!topological_sort_util(i,visited))
                    return false;
            }
        }
        return true;
    }
};

int isCoursesPossible(int A, vector<int> &B, vector<int> &C) {
    int edges = B.size();
    Graph g(A);
    for (int i=0 ; i<edges; i++) {
        g.add_edge(B[i], C[i]);
    }
    
    return g.topological_sort();
}

/***********************************/
#define edge pair<int, int>
class DisjointSet {
private:
    int parent[10000];
    int rank[10000];
    
public:
    DisjointSet(int n) {
        memset(parent, 0, sizeof(parent));
        memset(rank, 0, sizeof(rank));
        
        for (int i=0; i<n; i++) {
            parent[i] = i;
            rank[i] = 1;
        }
    }
    
    int find_set(int x) {
        if (parent[x] == x) {
            return x;
        }
        else
            return  parent[x] = find_set(parent[x]);
    }
    
    void union_sets(int a, int b) {
        int pa = find_set(a);
        int pb = find_set(b);
        if (pa == pb) {
            return;
        }
        if (rank[pa] < rank[pb]) {
            parent[pa] = pb;
        }
        else if (rank[pa] > rank[pb]) {
            parent[pb] = pa;
        }
        else {
            parent[pb] = pa;
            rank[pa]++;
        }
    }
};

int commutableIslands(int A, vector<vector<int> > &B) {
    int res = 0;
    bool visited[10000];
    memset(visited, false, sizeof(visited));
    vector<pair<int, edge>> pq;
    for (int i = 0; i<B.size(); i++) {
        pq.push_back(make_pair(B[i][2], make_pair(B[i][0], B[i][1])));
    }
    sort(pq.begin(), pq.end());
    DisjointSet s(A);
    
    for (int i = 0; i<pq.size(); i++) {
        pair<int, edge> min_edge = pq[i];
        int p1 = s.find_set(min_edge.second.first);
        int p2 = s.find_set(min_edge.second.second);
        if (p1!=p2) {
            res+= min_edge.first;
            s.union_sets(p1, p2);
        }
    }
    
    return res;
}

/***********************************/

inline int findReminder(string t, int n) {
    int r = 0;
    for (int i = 0; i<t.length(); i++) {
        r = r*10 + (t[i] - '0');
        r %= n;
    }
    return r;
    
}

string multipleWith1and0(int A) {
    string t="1";
    unordered_set<int> visited;
    queue<string> q;
    q.push(t);
    while (!q.empty()) {
        t = q.front();
        q.pop();
        int r = findReminder(t, A);
        if (r==0) {
            return t;
        }
        else if (visited.find(r) == visited.end()) {
            visited.insert(r);
            t.push_back('0');
            q.push(t);
            t.pop_back();
            t.push_back('1');
            q.push(t);
        }
        
    }
    return "";
}

typedef long long ll;
//flag stores which nodes i have already visited
//parent and val array as described in hints
vector<int> flag,parent,val;

string solve(int n)
{
    int p,q,i,tot=0;
    
    //final string
    string ret="";
    
    //queue for bfs
    queue < int > myq;
    
    //initial node
    int temp=1%n;
    flag[temp]=1;
    val[temp]=1;
    myq.push(temp);
    
    while(1)
    {
        //pop from queue
        temp=myq.front();
        myq.pop();
        p=temp;
        
        //reached final state
        //build solution here
        if(p==0)
        {
            p=0;
            ret+=(char)(val[p]+'0');
            p=parent[p];
            while(p!=0)
            {
                ret+=(char)(val[p]+'0');
                p=parent[p];
            }
            reverse(ret.begin(), ret.end());
            return ret;
        }
        
        //visit two neighbors p*10 and p*10+1
        //if already not visited
        q=(p*10)%n;
        if(flag[q]==0)
            myq.push(q),flag[q]=1,parent[q]=p,val[q]=0;
        
        q++;
        if(q>=n)q-=n;
        if(flag[q]==0)
            myq.push(q),flag[q]=1,parent[q]=p,val[q]=1;
    }
}

string multiple(int A) {
    flag.clear();
    parent.clear();
    val.clear();
    flag.resize(A);
    parent.resize(A);
    val.resize(A);
    return solve(A);
}

/***************************************/
int rankSet[1005];
bool visited[1005];
int sets[1005];

void initialise(int n) {
    for (int i = 0; i<n; i++) {
        rankSet[i] = 1;
        visited[i] = false;
        sets[i] = i;
    }
}

int sets_find(int x) {
    if (sets[x] == x) {
        return x;
    }
    sets[x] = sets_find(sets[x]); // path compression
    return sets[x];
}

void sets_union(int x, int y) {
    int a = sets_find(x);
    int b = sets_find(y);
    if (a==b) {
        return;
    }
    if (rankSet[a] < rankSet[b]) {
        sets[a] = b;
    }
    else if (rankSet[a] > rankSet[b]) {
        sets[b] = a;
    }
    else {
        rankSet[a]++;
        sets[b] = a;
    }
}

bool findBlockage(int root, int x, int y, int N, int R, vector<pair<int, pair<int, int>>> vec ) {
    int top = 0;
    int right = 0;
    int bottom = INT_MAX;
    int left = INT_MAX;
    for (int i=0; i<N; i++) {
        if (sets[vec[i].first] == root) {
            int x = vec[i].second.first;
            int y = vec[i].second.second;
            top = max(top, y+R);
            bottom = min(bottom, y-R);
            left = min(left, x-R);
            right = max(right, x+R);
        }
    }
    if (top>= y && bottom <= 0) {
        return true;
    }
    if (right >=x && left<= 0) {
        return true;
    }
    if(top>=y and right>=x)return true;
    if(left<=0 and bottom<=0)return true;
    return false;
}

string validPathRectangle(int A, int B, int C, int D, vector<int> E, vector<int> F) {

    vector<pair<int, pair<int, int> >> vec;
    for (int i=0; i<C; i++) {
        vec.push_back(make_pair(i, make_pair(E[i], F[i])));
    }
    initialise(C);
    // find intersection set of the centers of the circle
    for (int i=0; i<C; i++) {
        int x1 = vec[i].second.first;
        int y1 = vec[i].second.second;
        for (int j = i+1; j<C; j++) {
            int x2 = vec[j].second.first;
            int y2 = vec[j].second.second;
            if ( ((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2)) <= 4*D*D) {
                sets_union(vec[i].first, vec[j].first);
            }
        }
    }
    for (int i=0; i<C; i++) {
        if ( !visited[sets[vec[i].first]] ) {
            visited[sets[vec[i].first]] = true;
            bool blockage = findBlockage( sets[vec[i].first], A, B, C, D, vec);
            if (blockage) {
                return "NO";
            }
        }
    }
    
    return "YES";
}
/***************************************/

vector<vector<int> > levelOrderTraversalBST(TreeNode* A) {
    queue<TreeNode *> q;
    vector<vector<int>> res;
    if (!A) {
        return res;
    }
    q.push(A);
    while (!q.empty()) {
        vector<int> t;
        queue<TreeNode*> tq;
        while (!q.empty()) {
            TreeNode *n = q.front();
            q.pop();
            t.push_back(n->val);
            if (n->left) {
                tq.push(n->left);
            }
            if (n->right) {
                tq.push(n->right);
            }
        }
        q = tq;
        res.push_back(t);
    }
    return res;
}

vector<int> solve(int A, int B, int C, int D) {
    vector<int> t, t1;
    t1.push_back(A);
    t1.push_back(B);
    t1.push_back(C);
    sort(t1.begin(), t1.end());
    t.push_back(1);
    int c1 ,c2,c3;
    c1 = c2 = c3 = 0;
    D;
    while (D>0) {
        int next = min( t1[0] * t[c1], min(t1[1] * t[c2], t1[2]*t[c3]) );
        t.push_back(next);
        if (next == t1[0] * t[c1]) {
            c1++;
        }
        if (t1[1] * t[c2] == next ) {
            c2++;
        }
        if (t1[2]*t[c3] == next ) {
            c3++;
        }
        D--;
    }
    vector<int> res(t.begin()+1, t.end());
    return res;
}
