//
//  HashingSolutions.cpp
//  Hashing
//
//  Created by Apoorv on 27/08/17.
//  Copyright © 2017 presonal. All rights reserved.
//

#include "HashingSolutions.hpp"


typedef struct  {
    int sum;
    int first;
    int second;
} Sum2;

int row[9][9], col[9][9], quadrant[3][3][9];

vector<int> findSubstring(string A, const vector<string> &B) {
    vector<int> res;
    unsigned long sLen = B[0].length();
    int pHash[256];
    int tHash[256];
    unordered_map<string, int> str;
    memset(pHash, 0, sizeof(pHash));
    memset(tHash, 0, sizeof(tHash));
    int n = 0;
    
    for (int i=0; i<B.size(); i++)
    {
        for(char x : B[i])
        {
            pHash[x]++;
        }
        n += B[i].length();
        str[B[i]] ++;

    }
    int start = 0;
    int count = 0;
    for (int i =0 ; i<A.length(); i++)
    {
        if (pHash[A[i]] != 0)
        {
            tHash[A[i]] ++;
            if (tHash[A[i]] <= pHash[A[i]])
            {
                count++ ;
            }
            else
            {
                while (tHash[A[i]] > pHash[A[i]] && start <= i) {
                    tHash[A[start]] -- ;
                    start ++;
                    count  = i-start + 1;
                }
            }
            if (count == n)
            {
                bool match = true;
                unordered_map<string, int> str1;
                for (int j = 0; j<B.size(); j++)
                {
                    string s1 = A.substr(start+j*sLen,sLen);
                    if (str.find(s1) != str.end() && str1[s1] < str[s1]) {
                        str1[s1] ++;
                    }
                    else {
                        match = false;
                        break;
                    }
                }
                if (match)
                {
                    res.push_back(start);
                }
                tHash[A[start]] --;
                start ++ ;
                count = i - start + 1;
            }
        }
        else
        {
            start = i+1;
            count = 0;
            memset(tHash, 0, sizeof(tHash));
        }
    }
    return res;
}

int gcd(int a, int b) {
    if (a == 0) return b;
    if (b == 0) return a;
    if (a < 0) return gcd(-1 * a, b);
    if (b < 0) return gcd(a, -1 * b);
    if (a > b) return gcd(b, a);
    return gcd(b%a, a);
}

int maxPoints(vector<int> &X, vector<int> &Y) {
    map<pair<int, int>, int> M;
    int ans = 0;
    for (int i = 0; i < X.size(); i++) {
        M.clear();
        int same = 1, curMax = 0;
        // Try to find all the lines with same slope with points[i] as one end.
        // Points with the same slope lie on the same line.
        // We need to make sure we handle divisions by zero in cases like these.
        // We also need to take care of overlapping points.
        for (int j = i + 1; j < X.size(); j++) {
            int xdiff = X[i] - X[j];
            int ydiff = Y[i] - Y[j];
            if (xdiff == 0 && ydiff == 0) {
                // Same points
                same ++;
                continue;
            }
            if (xdiff < 0) {
                xdiff *= -1;
                ydiff *= -1;
            }
            int g = gcd(xdiff, ydiff);
            M[make_pair(xdiff / g, ydiff / g)]++;
            curMax = max(curMax, M[make_pair(xdiff / g, ydiff / g)]);
        }
        curMax+=same;
        ans = max(ans, curMax);
    }
    return ans;

}

string fractionToDecimal(int numerator, int denominator) {
    int64_t n = numerator, d = denominator;
    // zero numerator
    if (n == 0) return "0";
    
    string res;
    // determine the sign
    if (n < 0 ^ d < 0) res += '-';
    
    // remove sign of operands
    n = abs((double)n), d = abs((double)d);
    
    // append integral part
    res += to_string((n / d));
    
    // in case no fractional part
    if (n % d == 0) return res;
    
    res += '.';
    
    unordered_map<int, int> map;
    
    // simulate the division process
    for (int64_t r = n % d; r; r %= d) {
        
        // meet a known remainder
        // so we reach the end of the repeating part
        if (map.find(r) != map.end()) {
            // insert '(' at the start position where we first saw the remainder
            res.insert(map[r], 1, '(');
            res += ')';
            break;
        }
        
        // the remainder is first seen
        // remember the current position for it
        map[r] = res.size();
        
        r *= 10;
        
        // append the quotient digit
        res.push_back((char)('0' + (r / d)));
    }
    
    return res;
    
}


string minWindow(string S, string T) {
    
    int tHash[256];
    int sHash[256];
    unsigned long n1 = S.length();
    unsigned long n2 = T.length();
    memset(tHash, 0, sizeof(tHash));
    memset(sHash, 0, sizeof(sHash));
    for(char x : T)
    {
        tHash[x] ++;
    }
    int start = 0;
    int start_index = -1;
    int min_len = INT_MAX;
    int count = 0;
    for(int i = 0; i<n1 ; i++)
    {
        sHash[S[i]]++;
        if (tHash[S[i]] != 0 && sHash[S[i]] <= tHash[S[i]]) {
            count++;
        }
        if(count == n2) // window found
        {
            // shrink window from start to remove extra chars
            while( (sHash[S[start]] > tHash[S[start]]) || tHash[S[start]] == 0 ) {
                if (sHash[S[start]] > tHash[S[start]]) {
                    sHash[S[start]] -- ;
                }
                start++;
            }
            
            // update window
            int window_len = i - start + 1;
            if (min_len > window_len) {
                min_len = window_len;
                start_index = start;
            }
            
        }
    }
    if (start_index == -1) {
        return "";
    }
    else {
        return S.substr(start_index,min_len);
    }
}

int lengthOfLongestSubstring(string str) {
    int n = str.length();
    int cur_len = 1;  // lenght of current substring
    int max_len = 1;  // result
    int prev_index;  //  previous index
    int i;
    int visited[256];
    
    /* Initialize the visited array as -1, -1 is used to
     indicate that character has not been visited yet. */
    memset(visited, -1, sizeof(visited));
    
    /* Mark first character as visited by storing the index
     of first   character in visited array. */
    visited[str[0]] = 0;
    
    /* Start from the second character. First character is
     already processed (cur_len and max_len are initialized
     as 1, and visited[str[0]] is set */
    for (i = 1; i < n; i++)
    {
        prev_index =  visited[str[i]];
        
        /* If the currentt character is not present in the
         already processed substring or it is not part of
         the current NRCS, then do cur_len++ */
        if (prev_index == -1 || i - cur_len > prev_index)
            cur_len++;
        
        /* If the current character is present in currently
         considered NRCS, then update NRCS to start from
         the next character of previous instance. */
        else
        {
            /* Also, when we are changing the NRCS, we
             should also check whether length of the
             previous NRCS was greater than max_len or
             not.*/
            if (cur_len > max_len)
                max_len = cur_len;
            
            cur_len = i - prev_index;
        }
        
        // update the index of current character
        visited[str[i]] = i;
    }
    
    // Compare the length of last NRCS with max_len and
    // update max_len if needed
    if (cur_len > max_len)
        max_len = cur_len;
    
    return max_len;
}

RandomListNode* copyRandomList(RandomListNode* A)
{
    map<RandomListNode *, RandomListNode *>m;
    map<RandomListNode *, RandomListNode *>:: iterator it1, it2;
    RandomListNode *newList = NULL, *temp1, *temp2;
    temp1 = A;
    temp2 = newList;
    while (temp1!=NULL) {
        if (newList) {
            temp2->next = new RandomListNode(temp1->label);
            temp2 = temp2->next;
        }
        else
        {
            newList = new RandomListNode(temp1->label);
            temp2 = newList;
        }
        m.insert(make_pair(temp1, temp2));
        temp1 = temp1 ->next;
    }
    temp1 = A;
    while (temp1!=NULL) {
        it1 = m.find(temp1);
        it2 = m.find(temp1->random);
        if (it1!=m.end() && it2 != m.end()) {
            it1->second->random = it2->second;
        }
        temp1 = temp1->next;
    }
    return newList;
}


/*
 A[A1] + A[B1] = A[C1] + A[D1]
 A1 < B1, C1 < D1
 A1 < C1, B1 != D1, B1 != C1
 */
vector<int> equal(vector<int> &A) {
    vector<vector<int>> res;
    map<int, vector<int>> m;
    for (int i=0; i<A.size(); i++) {
        for (int j=i+1; j<A.size();j++) {
            int sum = A[i]+A[j];
            map<int,vector<int>>::iterator it = m.find(sum);
            vector<int> v1 = {i,j};
            if (it == m.end()) {
                m.insert(make_pair(sum, v1));
            }
            else {
                vector<int>v2 = it->second;
                if (v1[0] < v2[0] &&  v1[1] != v2[1] && v1[1] != v2[0] ) {
                    v1.insert(v1.end(), v2.begin(), v2.end());
                    res.push_back(v1);
                }
                else if (v2[0] < v1[0] &&  v2[1] != v1[1] && v2[1] != v1[0]){
                    v2.insert(v2.end(), v1.begin(), v1.end());
                    res.push_back(v2);
                }
                sort(res.begin(), res.end());
                if (res.size()>1) {
                    res.pop_back();
                }
            }
        }
    }
    sort(res.begin(), res.end());
    return res.front();
}

vector<vector<int> > anagrams1(const vector<string> &A) {
    vector<vector<int>> res;
    set<string> m;
    for (int i=0; i<A.size(); i++) {
        string s1 = A[i];
        vector<int> v;
        set<string>::iterator it = m.find(s1);
        if(it != m.end())
        {
            continue;
        }
        v.push_back(i+1);
        sort(s1.begin(), s1.end());
        for (int j = i+1; j<A.size(); j++) {
            string s2 = A[j];
            sort(s2.begin(), s2.end());
            if (s1==s2) {
                v.push_back(j+1);
                m.insert(A[j]);
            }
        }
        m.insert(A[i]);
        res.push_back(v);
    }
    
    return res;
}

vector<vector<int> > anagrams(const vector<string> &A) {
    vector<vector<int>> res;
    map<string, vector<int>> m;
    for (int i=0; i<A.size(); i++) {
        string s1 = A[i];
        sort(s1.begin(), s1.end());
        vector<int> v;
        map<string, vector<int>>::iterator it = m.find(s1);
        if(it != m.end())
        {
            it->second.push_back(i+1);
        }
        else
        {
            v.push_back(i+1);
            m.insert(make_pair(s1, v));
        }
    }
    for (map<string,vector<int>>::iterator it = m.begin(); it!=m.end(); ++it) {
        res.push_back(it->second);
    }
    return res;
}

int diffPossible(const vector<int> &num, int diff) {
    if (num.size() < 2 || diff < 0) return false;
    unordered_set<int> S;
    for (int i = 0; i < num.size(); i++) {
        int aj = num[i] - diff;
        int ai = num[i] + diff;
        if (S.find(aj) != S.end()) return true;
        if (S.find(ai) != S.end()) return true;
        S.insert(num[i]);
    }
    return false;
}


bool solve_sudoku( vector<string> a, int pos)
{
    if (pos>=9*9) {
        return true;
    }
    int i = pos/9;
    int j = pos%9;
    if(a[i][j] != '.')
    {
        return solve_sudoku(a, pos+1);
    }
    for (int num = 0; num<9; num++) {
        if (row[i][num] != 1 && col[j][num]!=1 && quadrant[i/3][j/3][num] != 1) {
            a[i][j] = '1' + num;
            row[i][num] = 1;
            col[j][num] = 1;
            quadrant[i/3][j/3][num] = 1;
            if (solve_sudoku(a, pos+1)) {
                return true;
            }
            a[i][j] = '.';
            row[i][num] = 0;
            col[j][num] = 0;
            quadrant[i/3][j/3][num] = 0;
        }
    }
    return false;
}

int isValidSudoku(const vector<string> &A) {
    memset(row, 0, sizeof(row));
    memset(col, 0, sizeof(col));
    memset(quadrant, 0, sizeof(quadrant));
    for (int i=0; i<9; i++) {
        for (int j=0; j<9; j++) {
            if (A[i][j] != '.') {
                int n = A[i][j] - '1';
                row[i][n] = 1;
                col[j][n] = 1;
                quadrant[i/3][j/3][n] = 1;
            }
        }
    }
    if(solve_sudoku(A,0))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int valid_soduku(const vector<string> &A)
{
    memset(row, 0, sizeof(row));
    memset(col, 0, sizeof(col));
    memset(quadrant, 0, sizeof(quadrant));
    for (int i=0; i<9; i++) {
        for (int j=0; j<9; j++) {
            if (A[i][j] != '.') {
                int num = A[i][j] - '1';
                if (row[i][num] == 1 || col[j][num] == 1 || quadrant[i/3][j/3][num] == 1) {
                    return 0;
                }
                row[i][num] = 1;
                col[j][num] = 1;
                quadrant[i/3][j/3][num] = 1;
            }
        }
    }
    return 1;
}

void backtrack_fourSum(vector<int> a, int i, int b, vector<int> temp, int sum, set<vector<int>> &s, vector<vector<int>> &res)
{
    if (sum == b) {
        if (temp.size() == 4) {
            if(s.find(temp) == s.end())
            {
                s.insert(temp);
                res.push_back(temp);
                return;
            }
        }
    }
    if (i>=a.size()) {
        return;
    }
    temp.push_back(a[i]);
    backtrack_fourSum(a,i+1,b, temp,sum+a[i], s,res);
    temp.pop_back();
    backtrack_fourSum(a,i+1,b, temp,sum, s,res);
}

vector<vector<int>> fourSum1(vector<int> &A, int B) {
    sort(A.begin(), A.end());
    vector<vector<int>> res;
    vector<int> temp;
    set<vector<int>> s;
    backtrack_fourSum(A, 0, B, temp, 0, s,res);
    return res;
}

vector<vector<int>> fourSum(vector<int> &A, int B) {
    sort(A.begin(), A.end());
    vector<vector<int>> res;
    vector<Sum2> couple_sum;
    unordered_multimap<int, int> dict;
    set<vector<int>> s;
    dict.clear();
    s.clear();
    res.clear();
    for (int i=0 ; i<A.size(); i++) {
        for (int j=i+1; j< A.size(); j++) {
            Sum2 a;
            a.sum = A[i]+A[j];
            a.first = i;
            a.second = j;
            couple_sum.push_back(a);
        }
    }
    for (int i=0; i<couple_sum.size(); i++) {
        Sum2 temp = couple_sum[i];
        if (dict.count(temp.sum) == 0) {
            dict.insert(make_pair(B-temp.sum, i));
        }
        else {
            auto range = dict.equal_range(temp.sum);
            dict.insert(make_pair(B-temp.sum, i));
            for (unordered_multimap<int, int>::iterator it = range.first; it!=range.second; it++) {
                Sum2 temp2 = couple_sum[it->second];
                if (temp.first == temp2.first || temp.first == temp2.second || temp.second == temp2.first || temp.second == temp2.second) {
                    continue;
                }
                else {
                    vector<int> v = {A[temp.first],A[temp.second], A[temp2.first], A[temp2.second]};
                    sort(v.begin(), v.end());
                    if (s.find(v)==s.end()) {
                        s.insert(v);
                        res.push_back(v);
                    }
                }
            }
        }
    }
    sort(res.begin(), res.end());
    return res;
}

vector<int> twoSum(const vector<int> &A, int B) {
    vector<int> res;
    unordered_map<int, int> dict;
    for (int i=0; i<A.size(); i++) {
        if (dict.find(A[i]) == dict.end()) {
            if (dict.find(B-A[i]) == dict.end()) {
                dict[B-A[i]] = i;
            }
        }
        else
        {
            return {dict[A[i]]+1,i+1};
        }
    }
    
    return res;
}

vector<int> lszero(vector<int> &A) {
    
    map<int, int> m;
    int max_len = 0;
    int start_index = 0;
    int sum = 0;
    for (int i=0; i<A.size(); i++)
    {
        sum += A[i];
        
        if (A[i]==0 && max_len==0) {
            max_len = 1;
            start_index = i;
        }
        if (sum==0) {
            max_len = i+1;
            start_index = 0;
        }
        
        if (m.find(sum) == m.end()) {
            m[sum] = i;
        }
        else {
            if (max_len < (i-m[sum])) {
                max_len = i-m[sum];
                start_index = m[sum]+1;
            }
        }
    }
    
    vector<int> res(A.begin()+start_index, A.begin()+start_index+max_len);
    return res;
}

int colorful(int A) {
    
    set<int> s;
    set<int>:: iterator it;
    vector<int> digits;
    int n = A;
    while (n>=10)
    {
        if (n/10) {
            digits.push_back(n%10);
            n = n/10;
        }
    }
    digits.push_back(n);
    
    for (int l=1; l<=digits.size(); l++) {
        for (int i = 0; i<=digits.size()-l; i++) {
            int p = 1;
            for (int j=i; j<i+l; j++) {
                p = p*digits[j];
            }
            it = s.find(p);
            if (it==s.end()) {
                s.insert(p);
            }
            else {
                return 0;
            }
        }
    }
    return 1;
    
}
