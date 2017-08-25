//
//  BacktrackingSolutions.cpp
//  Backtracking
//
//  Created by Apoorv on 17/08/17.
//  Copyright © 2017 presonal. All rights reserved.
//

#include "BacktrackingSolutions.hpp"

void backtrack_getKPermutation(int i,int k, int &count,vector<int>p, string &res) {
    if (res != "") {
        return;
    }
    if (i==p.size()) {
        count++;
        if (count == k) {
            for (int v : p) {
                res+= to_string(v);
            }
        }
        return;
    }
    if (res != "") {
        return;
    }
    sort(p.begin()+i, p.end());
    for (int j = i; j<p.size(); j++) {
        
        int temp = p[j];
        p[j] = p[i];
        p[i] = temp;
        //vector<int> aux(p.begin(),p.end());
        //sort(aux.begin()+i+1, aux.end());
        backtrack_getKPermutation(i+1,k,count,p,res);
        temp = p[j];
        p[j] = p[i];
        p[i] = temp;
    }
}


int factorial(int n) {
    if (n > 12) {
        // this overflows in int. So, its definitely greater than k
        // which is all we care about. So, we return INT_MAX which
        // is also greater than k.
        return INT_MAX;
    }
    // Can also store these values. But this is just < 12 iteration, so meh!
    int fact = 1;
    for (int i = 2; i <= n; i++) fact *= i;
    return fact;
}

string backtrack_getPermutationn(int k, vector<int> &candidateSet) {
    int n = candidateSet.size();
    if (n == 0) {
        return "";
    }
    if (k > factorial(n)) return ""; // invalid. Should never reach here.
    
    int f = factorial(n - 1);
    int pos = k / f;
    k %= f;
    string ch = to_string(candidateSet[pos]);
    // now remove the character ch from candidateSet.
    candidateSet.erase(candidateSet.begin() + pos);
    return ch + backtrack_getPermutationn(k, candidateSet);
}

string getPermutation(int n, int k) {
    vector<int> p;
    for (int i=1; i<=n; i++) {
        p.push_back(i);
    }
    
    return backtrack_getPermutationn(k-1,p);;
}


void backtrack_grayCode(int val, int n, set<int> &s,vector<int>&res) {
    set<int>::iterator it = s.find(val);
    if (it == s.end()) {
        s.insert(val);
        res.push_back(val);
    }
    else {
        return;
    }
    for (int i=0; i<n; i++) {
            val = val ^ 1<<i;
            backtrack_grayCode(val,n,s,res);
            val = val ^ 1<<i;
    }
}

vector<int> grayCode(int A) {
    set<int> s;
    vector<int> res;
    backtrack_grayCode(0,A,s,res);
    return res;
}


bool isPlaceable( vector<vector<char>> &board, int i, int j, int val){
    // row check
    vector<char> row = board[i];
    for(char c : row) {
        if (c == ('0'+val)) {
            return false;
        }
    }
    // col check
    for (int x=0; x<board.size(); ++x) {
        if (board[x][j] == ('0'+val)) {
            return false;
        }
    }
    // quadrant check
    int x,y;
    int n = sqrt(board.size());
    x = i - i%n;
    y = j - j%n;
    for (int s = 0; s<n; s++) {
        for (int t = 0; t<n; t++) {
            if (board[s+x][t+y] == ('0'+val)) {
                return false;
            }
        }
    }
    return true;
}

bool emptyCell(vector<vector<char>> board, int &row, int &col) {
    for ( row=0 ; row<board.size(); row++) {
        for (col=0; col<board.size(); col++) {
            if (board[row][col] == '.') {
                return true;
            }
        }
    }
    return false;
}

bool backtrack_solveSudoku(vector<vector<char>> &board) {
    int row, col;
    if (!emptyCell(board, row, col)) {
        return true;
    }
    for (int val =1; val<=board.size(); val++) {
        if (isPlaceable(board, row, col, val)) {
            board[row][col] = '0' + val;
            if(backtrack_solveSudoku(board))
                return true;
            board[row][col] = '.';
        }
    }
    return false;
}

void solveSudoku(vector<vector<char> > &A) {
    backtrack_solveSudoku(A);
}


bool isQueenSafe(vector<int> cols, int row, int col) {
    for (int i =0 ; i<cols.size(); ++i) {
        if (cols[i] == col || abs(row-i) == abs(col - cols[i])) {
            return false;
        }
    }
    return true;
}

vector<string> generate_solution_Nqueens(vector<int>cols) {
    vector<string> sol;
    for (int c : cols) {
        string s(cols.size(),'.');
        s[c] = 'Q';
        sol.push_back(s);
    }
    return sol;
}

void backtrack_solveNQueens(int queen, int n, vector<int> columns, vector<vector<string>> &res) {
    if (queen == n) {
        vector<string> sol = generate_solution_Nqueens(columns);
        res.push_back(sol);
        return;
    }
    for (int j=0; j<n; j++) {
        if (isQueenSafe(columns, queen, j)) {
            columns.push_back(j);
            backtrack_solveNQueens(queen+1,n,columns,res);
            columns.pop_back();
        }
    }
}

vector<vector<string> > solveNQueens(int A) {
    vector<vector<string> > res;
    vector<int> cols;
    backtrack_solveNQueens(0,A,cols,res);
    return res;
}

void backtrack_generateParenthesis(int a, int o, int c, string temp, vector<string> &res) {
    if (o == c and o == a) {
        res.push_back(temp);
        return;
    }
    if (o > a || c > a) {
        return;
    }
    if (o<a) {
        temp.push_back('(');
        backtrack_generateParenthesis(a,o+1,c,temp,res);
        temp.pop_back();
    }
    if (c<o) {
        temp.push_back(')');
        backtrack_generateParenthesis(a,o,c+1,temp,res);
        temp.pop_back();
    }
    
}

vector<string> generateParenthesis(int A) {
    vector<string> res;
    string temp;
    backtrack_generateParenthesis(A,0,0,temp,res);
//    generateHelper(temp, 0, 0, A, res);
    //sort(res.begin(), res.end());
    return res;
}


bool isPlaindrome(string s, int i, int j){
    if (i<0 || j>= s.size()) {
        return false;
    }
    while (i<j) {
        if (s[i] == s[j]) {
            i++;
            j--;
        }
        else{
            return false;
        }
    }
    return true;
}

void bactrack_partition(int i, string s, vector<string> temp, vector<vector<string>> &res) {
    if (i>s.size()) {
        return;
    }
    if (i == s.size()) {
        res.push_back(temp);
        return;
    }
    int l = 1;
    int j = i;
    while ((j+l-1) <s.size()) {
        if (isPlaindrome(s, j, j+l-1)) {
            temp.push_back(s.substr(j,l));
            bactrack_partition(i+l,s,temp,res);
            temp.pop_back();
        }
        l++;
    }
}

vector<vector<string> > partition(string A) {
    vector<vector<string>> res;
    vector<string> temp;
    bactrack_partition(0,A,temp,res);
    sort(res.begin(), res.end());
    return res;
}

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

