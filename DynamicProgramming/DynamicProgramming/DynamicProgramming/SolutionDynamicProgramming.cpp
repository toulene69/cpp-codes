//
//  SolutionDynamicProgramming.cpp
//  DynamicProgramming
//
//  Created by Apoorv on 06/11/17.
//  Copyright © 2017 presonal. All rights reserved.
//

#include "SolutionDynamicProgramming.hpp"
typedef long long LL;
int dict[1000][1000];
short table[100001];

vector<vector<vector<bool> > > dp4;
vector<int> res;
vector<int> original;
int total_size;

bool possible(int index, int sum, int sz) {
    if (sz == 0) return (sum == 0);
    if (index >= total_size) return false;
    
    if (dp4[index][sum][sz] == false) return false;
    
    if (sum >= original[index]) {
        res.push_back(original[index]);
        if (possible(index + 1, sum - original[index], sz - 1)) return true;
        res.pop_back();
    }
    
    if (possible(index + 1, sum, sz)) return true;
    
    return dp4[index][sum][sz] = false;
}
vector<vector<int> > avgset(vector<int> &Vec) {
    /*
     * SUM_of_Set1 / size_of_set1 = SUM_of_Set2 / size_of_set2
     * SUM_of_Set1 = SUM_of_Set2 * (size_of_set1 / size_of_set2)
     *
     * total_sum = Sum_of_Set1 + Sum_of_Set2
     * and size_of_set2 = total_size - size_of_set1
     *
     * Sum_of_Set1 = (total_sum - Sum_of_Set1) * (size_of_set1 / (total_size - size_of_set1))
     * OR on simplifying,
     *   total_sum / Sum_of_Set1 - 1 = (total_size - size_of_set1) / size_of_set1
     *   total_sum / Sum_of_Set1 = total_size / size_of_set1
     *   Sum_of_Set1 / size_of_set1 = total_sum / total_size
     *
     *   Now we can just iterate on size_of_set1, and we would know the required Sum_of_Set1
     */
    
    sort(Vec.begin(), Vec.end());
    original.clear();
    original = Vec;
    dp4.clear();
    res.clear();
    
    int total_sum = 0;
    total_size = Vec.size();
    
    for(int i = 0; i < total_size; ++i)
        total_sum += Vec[i];
    
    dp4.resize(original.size(), vector<vector<bool> > (total_sum + 1, vector<bool> (total_size, true)));
    
    // We need to minimize size_of_set1. So, lets search for the first size_of_set1 which is possible.
    for (int i = 1; i < total_size; i++) {
        // Sum_of_Set1 has to be an integer
        if ((total_sum * i) % total_size != 0) continue;
        int Sum_of_Set1 = (total_sum * i) / total_size;
        if (possible(0, Sum_of_Set1, i)) {
            
            // Ok. Lets find out the elements in Vec, not in res, and return the result.
            int ptr1 = 0, ptr2 = 0;
            vector<int> res1 = res;
            vector<int> res2;
            while (ptr1 < Vec.size() || ptr2 < res.size()) {
                if (ptr2 < res.size() && res[ptr2] == Vec[ptr1]) {
                    ptr1++;
                    ptr2++;
                    continue;
                }
                res2.push_back(Vec[ptr1]);
                ptr1++;
            }
            
            vector<vector<int> > ans;
            ans.push_back(res1);
            ans.push_back(res2);
            return ans;
        }
    }
    // Not possible.
    vector<vector<int> > ans;
    return ans;
}


struct node{
    int items;
    int weight;
}dp2[105][10005];
int flipArray(const vector<int> &A) {
    int n = A.size();
    int sum = 0;
    
    for(int i=0; i<n; i++) sum+=A[i];
    
    //knapsack algorithm for capacity sum/2
    int temp = sum/2;
    
    for(int i=0; i<=n; i++){
        for(int j=0; j<=temp; j++){
            if(i==0 || j==0) dp2[i][j] = {0, 0};
            else{
                int prev_items = dp2[i-1][j].items;
                int prev_weight = dp2[i-1][j].weight;
                
                if(j-A[i-1] >= 0){
                    int curr_weight = dp2[i-1][j-A[i-1]].weight + A[i-1];
                    int curr_items = dp2[i-1][j-A[i-1]].items + 1;
                    
                    if((curr_weight>prev_weight) || ((curr_weight==prev_weight) && (curr_items<prev_items))){
                        dp2[i][j] = {curr_items, curr_weight};
                    }
                    else{
                        dp2[i][j] = dp2[i-1][j];
                    }
                }
                else{
                    dp2[i][j] = dp2[i-1][j];
                }
            }
        }
    }
    
    
    return dp2[n][temp].items;
}

int tusharBDayParty(const vector<int> &A, const vector<int> &B, const vector<int> &C)
{
    int numOfFriends = A.size();
    int numOfDishes = B.size();
    vector<pair<int, int>> dishPrice(numOfDishes);
    for (int i=0; i<numOfDishes; i++) {
        dishPrice[i] = make_pair(B[i], C[i]);
    }
    sort(dishPrice.begin(), dishPrice.end());
    int maxCapacity = *(max_element(A.begin(), A.end())) ;
    vector<vector<int>> dp(numOfDishes, vector<int>(maxCapacity+1, 0) ) ;
    dp[0][0] = 0;
    for (int i = 1; i<maxCapacity+1; i++) {
        if (i < dishPrice[0].first) {
            dp[0][i] = 0;
        }
        else {
            dp[0][i] = dishPrice[0].second + dp[0][i - dishPrice[0].first];
        }
    }
    for (int i = 1; i<numOfDishes; i++) {
        for (int j = 1; j<maxCapacity+1; j++) {
            if (dishPrice[i].first > j) {
                dp[i][j] = dp[i-1][j];
            }
            else {
                dp[i][j] = min(dp[i-1][j], dishPrice[i].second + dp[i][j - dishPrice[i].first] );
            }
        }
    }
    int res = 0;
    for (int i = 0; i<numOfFriends; i++) {
        res += dp[numOfDishes-1][A[i]];
    }
    return res;
}


bool isPalindrome(string &str, int s, int e) {
    if (s == e) {
        return true;
    }
    while (s<e) {
        if (str[s] == str[e]) {
            s++; e--;
        }
        else {
            return false;
        }
    }
    return true;
}

int minCutPalindromePartitioning(string A) {
    int n = A.length();
    vector<vector<int>> dp(n, vector<int>(n,0));
    for (int l = 1; l<=n; l++) {
        for (int i = 0; i< n-l+1; i++) {
            int j = i+l-1;
            if (i==j) {
                dp[i][j] = 0;
            }
            else {
                if (isPalindrome(A,i,j)) {
                    dp[i][j] = 0;
                }
                else {
                    int r = INT_MAX;
                    for (int k = i ; k<j; k++) {
                        r = min(r, 1+dp[i][k]+dp[k+1][j]);
                    }
                    dp[i][j] = r;
                }
            }
        }
    }
    return dp[0][n-1];
}


int adjacent(vector<vector<int> > &A) {
    int n = A[0].size();
    vector<int> dp(n,0);
    dp[0] = max(A[0][0], A[1][0]);
    if (n == 1) {
        return dp[0];
    }
    dp[1] = max(A[0][1], A[1][1]);
    dp[1] = max(dp[0], dp[1]);
    if (n == 2) {
        return dp[1];
    }
    for (int i=2; i<n; i++) {
        dp[i] = 0;
        int with = max(A[0][i], A[1][i]) + dp[i-2];
        int without = dp[i-1];
        dp[i] = max(dp[i],max(with, without));
    }
    return dp[n-1];
}



vector<string> wordBreak2(string s, vector<string> &B) {
    unordered_set<string> dict(B.begin(), B.end());
    vector<vector<string> > words(s.length() + 1, vector<string>(0));
    
    // initialize the valid values
    words[s.length()].push_back("");
    
    // generate solutions from the end
    for(int i = s.length() - 1; i >= 0; i--) {
        vector<string> values;
        for(int j = i + 1; j <= s.length(); j++) {
            if (dict.find(s.substr(i, j - i)) != dict.end()) {
                for (int k = 0; k < words[j].size(); k++) {
                    values.push_back(s.substr(i, j - i) + (words[j][k].empty() ? "" : " ") + words[j][k]);
                }
            }
        }
        words[i] = values;
    }
    return words[0];
    
}

bool rec_wordBreak1(int index, string &s, unordered_set<string> &dict) {
    if (index >= s.length()) {
        return true;
    }
    if (table[index] != -1) {
        return table[index];
    }
    bool res = false;
    string sub = "";
    for (int i = index; i<s.length() && res == false; i++) {
        sub.push_back(s[i]);
        if (dict.find(sub) != dict.end()) {
            res |= rec_wordBreak1(i+1, s, dict);
        }
    }
    table[index] = res;
    return table[index];
}

int wordBreak1(string A, vector<string> B) {
    memset(table, -1, sizeof(int) * A.length());
    unordered_set<string> dict(B.begin(), B.end());
    return rec_wordBreak1(0,A,dict);
}


int wordBreak(string A, vector<string> B) {
    int n = A.size();
    vector<bool> dp(n+1,false);
    set<string> s(B.begin(),B.end());
    for (int i = 1; i<= n; i++) {
        if (dp[i] == false && s.find(A.substr(0,i)) != s.end()) {
            dp[i] = true;
        }
        if (dp[i] == true) {
            if (i == n) {
                return 1;
            }
            for (int j = i+1; j<=n; j++) {
                if (dp[j] == false && s.find(A.substr(i,j-i)) != s.end()) {
                    dp[j] = true;
                }
                if (dp[j] == true && j == n) {
                    return 1;
                }
            }
        }
    }
    return 0;
}

int numOfUniqueBSTs(int A) {
    vector<int> dp(A+1,0);
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i<A+1; i++) {
        for (int j = 0; j<i ; j++) {
            dp[i] = dp[i] + dp[j] * dp[i-j-1];
        }
    }
    return dp[A];
}


int productOfWhitAndBlack(string &s, int i, int j)
{
    if (i==j) {
        return 0;
    }
    int w = 0, b = 0;
    while (i<=j) {
        if (s[i] == 'W') {
            w++;
        }
        else {
            b++;
        }
        i++;
    }
    return w*b;
}

int arrangeHorses(string A, int B) {
    int n = A.size();
    if (n==0) {
        return 0;
    }
    if (B==0) {
        return -1;
    }
    if(n<B)
        return -1;
    vector<vector<int>> dp(B, vector<int>(n,0));
    for (int i = 0; i<B; i++) {
        for (int j = 0; j<n; j++) {
            if (i==0) {
                dp[i][j] = productOfWhitAndBlack(A,i,j);
            }
            else {
                int minProd = INT_MAX;
                for (int k = j; k>=0; k--) {
                    minProd = min(minProd, productOfWhitAndBlack(A, k, j) + dp[i-1][k-1]);
                }
                dp[i][j] = minProd;
            }
        }
    }
    return dp[B-1][n-1];
}

int maxProductSubArray(const vector<int> &A) {
    int res = A[0];
    int imax , imin ;
    imax = imin = res;
    for (int i = 1; i<A.size(); i++) {
        if (A[i] < 0) {
            swap(imax, imin);
        }
        imax = max(A[i], imax*A[i]);
        imin = min(A[i], imin*A[i]);
        res = max(res, imax);
    }
    return res;
}

int coinchange2(vector<int> A, int B) {
    long n = A.size();
    if (n == 0) {
        return 0;
    }
    sort(A.begin(),A.end());
    vector<int> dp(B+1,0);
    dp[0]= 1;
    for (int i = 1; i< B+1; i++) {
        if (A[0] <= i) {
            dp[i] = dp[i-A[0]] ? 1 : 0;
        }
        else {
            dp[i] = 0;
        }
    }
    
    for (int i= 1; i < n; i++) {
        for (int j = 1; j<B+1; j++) {
            if (j>=A[i]) {
                dp[j] = (dp[j - A[i]] + dp[j]) % 1000007;
            }
        }
    }
    return dp[B] % 1000007;
}


int longestValidParentheses(string str) {
    
    int n = str.length();
    
    // Create a stack and push -1 as initial index to it.
    stack<int> stk;
    stk.push(-1);
    
    // Initialize result
    int result = 0;
    
    // Traverse all characters of given string
    for (int i=0; i<n; i++)
    {
        // If opening bracket, push index of it
        if (str[i] == '(')
            stk.push(i);
        
        else // If closing bracket, i.e.,str[i] = ')'
        {
            // Pop the previous opening bracket's index
            stk.pop();
            
            // Check if this length formed with base of
            // current valid substring is more than max
            // so far
            if (!stk.empty())
                result = max(result, i - stk.top());
            
            // If stack is empty. push current index as
            // base for next valid substring (if any)
            else stk.push(i);
        }
    }
    
    return result;
}


int coinInALine(vector<int> &A) {
    int n = A.size(); // given n is even
    vector<vector<int>> dp(n, vector<int>(n,0));
    for (int k = 2; k<= n; k+=2) {
        for (int i = 0; i<= n-k; i++) {
            int j = i+k - 1;
            if (k == 2) {
                dp[i][j] = max(A[i], A[j]);
            }
            else {
                int x = A[i] + min(dp[i+1][j-1], dp[i+2][j]);
                int y = A[j] + min(dp[i][j-2] , dp[i+1][j-1]);
                dp[i][j] = max(x,y);
            }
        }
    }
    return dp[0][n-1];
}

vector<vector<int> > kManhattanDistanceNeighbourhood(int A, vector<vector<int> > &B) {
    int m = B.size();
    int n = B[0].size();
    if (A == 0) {
        return B;
    }
    vector<vector<int>> temp1 = B;
    vector<vector<int>> temp2 (m, vector<int>(n));
    for (int k=0; k<A; k++) {
        for (int i = 0; i<m; i++) {
            for (int j = 0; j<n; j++) {
                int l = 0, r = 0, u = 0, d = 0;
                if (i-1 >= 0) {
                    u = temp1[i-1][j];
                }
                if (i+1 < m) {
                    d = temp1[i+1][j];
                }
                if (j-1 >= 0) {
                    l = temp1[i][j-1];
                }
                if (j+1 < n) {
                    r = temp1[i][j+1];
                }
                temp2[i][j] = max(temp1[i][j] , max(l, max(r,max(u,d)) ) );
            }
        }
        temp1 = temp2;
    }
    return temp1;
}


int overlappingSuffixPrefix(string a, string b, string &c) {
    int maxPreSuff = INT_MIN;
    long l1 = a.length();
    long l2 = b.length();
    long n = min(a.length(), b.length());
    for (int i=1; i<=n; i++) {
        if ( a.compare(0, i, b, l2-i, i) == 0) {
            if (maxPreSuff < i) {
                maxPreSuff = i;
                c = b + a.substr(i);
            }
        }
    }
    for (int i = 1; i<= n; i++) {
        if (a.compare(l1-i,i,b,0,i) == 0) {
            if (maxPreSuff < i) {
                maxPreSuff = i;
                c = a + b.substr(i);
            }
        }
    }
    return maxPreSuff;
}

int shortestCommonSuperString(vector<string> A){
    long n = A.size();
    while (n != 1) {
        int maxOverlap = INT_MIN;
        int l,r;
        string resMaxOverlap;
        for (int i = 0; i<n; i++) {
            for (int j = i+1; j<n; j++) {
                string s;
                int m = overlappingSuffixPrefix(A[i], A[j], s);
                if ( maxOverlap < m) {
                    maxOverlap = m;
                    resMaxOverlap.assign(s);
                    l = i; r = j;
                }
            }
            
        }
        n--;
        if (maxOverlap == INT_MIN) {
            A[0] += A[n];
        }
        else {
            A[l] = resMaxOverlap;
            A[r] = A[n];
        }
    }
    return A[0].length();
}

int numberOfWaysToColorBoard(int A) {
    
    long color3 = 24; // When we to fill single column
    long color2 = 12;
    for (int i = 2; i <= A; i++)
    {
        long temp = color3;
        color3 = (11 * color3 + 10 * color2 ) % 1000000007;
        color2 = ( 5 * temp + 7 * color2 ) % 1000000007;
    }
    long num = (color3 + color2) % 1000000007;
    return (int)num;
    
}


int rec_numbersSum(int n, int s)
{
    if (n==0) {
        return s==0;
    }
    
    if (dict[n][s] != -1 ) {
        return dict[n][s] ;
    }
    int ans = 0;
    for (int i = 0; i<=9; i++) {
        if (s-i >=0) {
            ans = (ans + (rec_numbersSum(n-1, s-i) % 1000000007)) % 1000000007 ;
        }
    }
    dict[n][s] = ans;
    return ans;
}

int numbersWithSumS(int A, int B) {
    
    memset(&dict, -1, sizeof(dict));
    int ans = 0;
    for (int i = 1; i<=9; i++) {
        if (B-i >= 0) {
            ans = (ans + (rec_numbersSum(A-1, B-i) % 1000000007)) % 1000000007 ;
        }
    }
    return ans;
    
}

int longestArithematicProgressionSequence(const vector<int> &A) {
    
    int n = A.size();
    if (n<=2) {
        return n;
    }
    vector<int> temp (A.begin(), A.end());
    sort(temp.begin(),temp.end());
    vector<vector<int>> dp(n, vector<int>(n,0));
    int res = 2;
    for (int i = 0; i<n; i++) {
        dp[i][n-1] = 2; // marking last column as 2
    }
    for (int j = n-2; j>=0; j--) {
        int i = j-1;
        int k = j+1;
        while (i>=0 && k<= n-1) {
            if ((temp[i] + temp[k]) > 2*temp[j] )  {
                dp[i][j] = 2;
                i--;
            }
            else if ((temp[i] + temp[k]) < 2*temp[j] ) {
                k++;
            }
            else {
                dp[i][j] = dp[j][k] + 1;
                res = max(res, dp[i][j]);
                i--; k++;
            }
        }
    }
    return res;
}

int minJumps(vector<int> &A) {
    int n = A.size();
    if (n == 0) {
        return 0;
    }
    vector<int> temp (n, 100000007);
    temp[0] = 0;
    for (int i = 1; i<n ; i++) {
        for (int j = 0; j<i; j++) {
            if (i <= j+A[j] && A[j] != -1) {
                temp[i] = min(temp[i], temp[j] + 1);
                
            }
        }
    }
    if (temp[n-1] == 100000007) {
        return -1;
    }
    return temp[n-1];
}

int canJump(vector<int> &A) {
    int n = A.size();
    
    if (n==0) {
        return 1;
    }
    if (A[0] == 0 && n>1) {
        return 0;
    }
    if (A[0] == 0 && n==1) {
        return 1;
    }
    int max_reachable_index = A[0];
    for (int i = 1; i<n; i++) {
        if (max_reachable_index<=i && A[i] == 0) {
            return 0;
        }
        if (max_reachable_index < (i+A[i])) {
            max_reachable_index = i + A[i];
        }
        if ((max_reachable_index + i) >= n-1) {
            return 1;
        }
    }
    return 1;
}

vector<int> birthdayBombs(int A, vector<int> B)
{
    vector<int> res;
    int pre = INT_MAX;
    vector<pair<int, int>> temp;
    for (int i =0 ; i<B.size(); i++) {
        if (B[i] < pre) {
            temp.push_back(make_pair(B[i], i));
            pre = B[i];
        }
    }
    int n = temp.size();
    int minStrength = temp[n-1].first;
    int i = 0;
    
    while (i<n) {
        if (A >= temp[i].first && ( (1 + (A - temp[i].first)/minStrength)  == A/minStrength) ) {
            res.push_back(temp[i].second);
            A -= temp[i].first;
        }
        else {
            i++;
        }
    }
    
    return res;
}


int countSubMatrixWithSumZero(vector<vector<int> > A) {
    int m = A.size();
    int n = A[0].size();
    if (!m && !n ) {
        return 0;
    }
    int count = 0;
    vector<vector<int>> pre(m, vector<int>(n,0));
    for (int i = 0; i<m; i++) {
        for (int j = 0; j<n; j++) {
            pre[i][j] = A[i][j];
            if (i) {
                pre[i][j] += pre[i-1][j];
            }
            if (j) {
                pre[i][j] += pre[i][j-1];
            }
            if (i & j) {
                pre[i][j] -= pre[i-1][j-1];
            }
        }
    }
    for (int l = 0; l<m; l++) {
        for (int r = l; r<m; r++) {
            unordered_map<int,bool> sumMap;
            sumMap[0] = 1;
            // Traverse throught array and store prefix sums
            int sum = 0;
            
            for (int j = 0 ; j < n ; j++)
            {
                int val = pre[r][j];
                if (l) {
                    val -= pre[l-1][j];
                }
                count += sumMap[-val];
                sumMap[val] ++;
            }
        }
    }
    return count;
}

int buySellStock3(const vector<int> A) {
    int n = A.size();
    if(n==0 || n==1)
        return 0;
    
    vector<int> dp(n, 0);
    long res = 0;
    
    int max_price = A[n-1];
    for (int i = n-2; i>=0; i--) {
        if (max_price < A[i]) {
            max_price = A[i];
        }
        dp[i] = max( dp[i+1], max_price - A[i]);
    }
    int min_price = A[0];
    for (int i = 1; i<n; i++) {
        if (min_price > A[i]) {
            min_price = A[i];
        }
        dp[i] = max(dp[i-1], dp[i] + (A[i] - min_price));
    }
    
    return dp[n-1];
}

int buySellStock2(const vector<int> A) {
    int n = A.size();
    if(n==0 || n==1)
        return 0;
    
    int i = 0;
    int count = 0;
    while (i<n-1) {
        while (i<n-1 && A[i] >= A[i+1]) {
            i++;
        }
        if (i==n-1) {
            break;
        }
        int buy = A[i];
        i++;
        while (i<n && A[i] >= A[i-1]) {
            i++;
        }

        int sell = A[i-1];
        count += (sell - buy);
    }
    return count;
}

int buySellStock1(const vector<int> A) {
    
    int n = A.size();
    if(n==0 || n==1)
        return 0;
    int max_diff = A[1] - A[0];
    int min_ele = A[0];
    for (int i = 1; i<n; i++) {
        if (A[i] < min_ele) {
            min_ele = A[i];
        }
        if (max_diff < (A[i] - min_ele)) {
            max_diff = (A[i] - min_ele);
        }
    }
    return max_diff;
}

vector<vector<int> > dp1[8];
bool valid(int i, int j, int n, int m){
    if(i < 0 or i >= n or j < 0 or j >= m)return false;
    return true;
}

//direction vectors
int dir1[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dir2[8] = {0, 1, 1, 1, 0, -1, -1, -1};

//returns dp(i, j, k) as defined in hint
int rec(int i, int j, int k, vector<string> & A, int n, int m){
    
    //memoisation
    int &ret = dp1[k][i][j];
    if(ret != -1)return ret;
    
    ret=0;
    
    //new positions
    int ni = i + dir1[k];
    int nj = j + dir2[k];
    
    //if valid
    if(valid(ni, nj, n, m)){
        if(A[ni][nj] == '1') ret++;
        else ret += rec(ni, nj, k, A, n, m);
    }
    
    return ret;
}

vector<vector<int> > queenAttack(vector<string> &A) {
    int n = A.size(), m = A[0].size();
    for(int i = 0; i < 8; i++){
        dp1[i].clear();
        dp1[i].resize(n, vector<int>(m, -1));
    }
    
    vector< vector<int> > ret(n, vector<int>(m, 0));
    
    //calculate dp for all positions
    for(int k = 0; k < 8; k++)
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++){
                ret[i][j] += rec(i, j, k, A, n, m);
            }
    return ret;
}


vector<int> ans;
//cuts vector
vector<int> cuts;
//dp array
vector<vector<LL> > dp;
//parent array
vector<vector<int> > parent;

LL rec(int l, int r){
    //base case
    if(l+1 >= r)return 0;
    
    //for memoisation
    LL &ret = dp[l][r];
    
    if(ret != -1) return ret;
    
    
    ret = LLONG_MAX;
    int bestind;    //stores the best index
    
    for(int i = l + 1; i < r; i++) {
        //recurrence
        LL p = rec(l,i) + rec(i,r) + (LL)cuts[r] - (LL)cuts[l];
        
        //update best
        //note that we choose lexicographically smallest index
        //if multiple give same cost
        if(p < ret) {
            ret = p;
            bestind = i;
        }
    }
    
    //store parent of (l, r)
    parent[l][r] = bestind;
    
    return ret;
}

void back(int l, int r){
    //base case
    if(l+1 >= r)return;
    
    //first choose parent of (l,r)
    ans.push_back(cuts[parent[l][r]]);
    
    //call back recursively for two new segments
    //calling left segment first because we want lexicographically smallest
    back(l, parent[l][r]);
    back(parent[l][r], r);
}
void solve(int A, vector<int> &B) {
    //insert A and 0
    B.push_back(A);
    B.insert(B.begin(),0);
    
    
    int n = B.size();
    cuts.clear();
    
    for(int i = 0; i < n; i++)
        cuts.push_back(B[i]);
    
    //initialise dp array
    dp.resize(n);
    parent.resize(n);
    ans.clear();
    
    for(int i = 0; i < n; i++){
        
        dp[i].resize(n);
        parent[i].resize(n);
        for(int j = 0; j < n; j++)
            dp[i][j] =- 1;
    }
    
    //call recurrence
    LL best = rec(0, n-1);
    
    //build solution
    back(0, n-1);
    
}

int rec_rod_cutting(int s, int e, int cs, int ce, vector<int> &temp, int n, vector<int> &cuts)
{
    if (s == e) {
        return 0;
    }
    if (cs > ce) {
        return 0;
    }
    if (e <= cuts[cs] || s>= cuts[ce]) {
        return 0;
    }
    int min_cost = INT_MAX;
    vector<int> min_t;
    int temp_cost = e-s;
    for (int i = cs; i<=ce; i++) {
        vector<int> t;
        t.push_back(cuts[i]);
        int x = rec_rod_cutting(s, cuts[i], cs, i-1, t, n, cuts);
        int y = rec_rod_cutting(cuts[i], e, i+1, ce, t, n, cuts);
        if (min_cost > (temp_cost + x+ y)) {
            min_cost = (temp_cost + x+ y);
            min_t = t;
        }
    }
    for (int i =0 ; i<min_t.size(); i++) {
        temp.push_back(min_t[i]);
    }
    return min_cost;
}

vector<int> rodCut(int A, vector<int> &B) {
    //solve(A, B);
    vector<int> res;
    rec_rod_cutting(0, A, 0, B.size(), res, A, B);
    return res;
}

int areaUnderHistogram(vector<int> row)
{
    stack<int> indexs;
    int max_area = 0;
    int area = 0;
    int n = row.size();
    int i = 0;
    while (i<n) {
        if (indexs.empty() || row[indexs.top()] <= row[i] ) {
            indexs.push(i++);
        }
        else {
            int top_val = row[indexs.top()];
            indexs.pop();
            area = top_val * i;
            if (!indexs.empty()) {
                area = top_val * (i - indexs.top() - 1);
            }
             max_area = max(area,max_area);
        }
    }
    while (!indexs.empty()) {
        int top_val = row[indexs.top()];
        indexs.pop();
        area = top_val * i;
        if (!indexs.empty()) {
            area = top_val * (i - indexs.top() - 1);
        }
         max_area = max(area,max_area);
    }
    return max_area;
}

int maximalRectangle(vector<vector<int> > &A) {
    
    int max_area = areaUnderHistogram(A[0]);
    int m = A.size();
    int n = A[0].size();
    for (int i=1; i<m; i++) {
        for (int j = 0; j<n; j++) {
            if (A[i][j] != 0) {
                A[i][j] = A[i][j] + A[i-1][j];
            }
        }
        int area = areaUnderHistogram(A[i]);
        if (max_area<area) {
            max_area = area;
            
        }
    }
    return max_area;
}

int uniquePathsWithObstacles(vector<vector<int> > A) {
    int m = A.size();
    int n = A[0].size();
    if (A[0][0] == 1) {
        return 0;
    }
    A[0][0] = 1;
    for (int i = 1; i<n; i++) {
        if (A[0][i] != 1 && A[0][i-1] != -1) {
            A[0][i] = 1;
        }
        else {
            A[0][i] = -1;
        }
    }
    for (int i = 1; i<m; i++) {
        if (A[i][0] != 1 && A[i-1][0] != -1) {
            A[i][0] = 1;
        }
        else {
            A[i][0] = -1;
        }
    }
    for (int i = 1; i<m; i++) {
        for (int j = 1; j<n; j++) {
            if (A[i][j] == 1) {
                A[i][j] = -1;
            }
            else {
                if (A[i-1][j] == -1 && A[i][j-1] == -1) {
                    A[i][j] = -1;
                }
                else if (A[i-1][j] == -1) {
                    A[i][j] = A[i][j-1];
                }
                else if (A[i][j-1] == -1) {
                    A[i][j] = A[i-1][j];
                }
                else {
                    A[i][j] = A[i-1][j] + A[i][j-1];
                }
            }
        }
    }
    if (A[m-1][n-1] == -1) {
        return 0;
    }
    return A[m-1][n-1];
}

int minimumSumPathTriangle(vector<vector<int> > A) {
    long m = A.size();
    
    for (int i = 1; i<m; i++) {
        A[i][0] = A[i][0] + A[i-1][0];
        A[i][i] = A[i][i] + A[i-1][i-1];
    }
    for (int i = 2; i<m; i++) {
        for (int j = 1; j< i; j++) {
            int a = A[i][j] + A[i-1][j-1];
            int b = A[i][j] + A[i-1][j];
            A[i][j] = min(a , b );
        }
    }
    int res = INT_MAX;
    for (int i =0 ; i<m; i++) {
        if (A[m-1][i] < res) {
            res = A[m-1][i];
        }
    }
    return res;
}

int dungeonPrincess(vector<vector<int> > &A) {
    long m = A.size();
    long n = A[0].size();
    int dp[m][n];
    dp[m-1][n-1] = max(1, 1 - A[m-1][n-1]);
    for (int i = n-2; i>=0; i--) {
        dp[m-1][i] = max(1, 1 - A[m-1][i+1]);
    }
    for (int i = m-2; i>=0; i--) {
        dp[i][n-1] = max(1, 1 - A[i+1][n-1]);
    }
    for (int i = m-2; i>=0; i--) {
        for (int j = n-2; j>=0; j--) {
            dp[i][j] = min( max(dp[i+1][j] - A[i][j], 1) , max( dp[i][j+1] - A[i][j], 1)  );
        }
    }
    return dp[0][0];
}

int minPathSum(vector<vector<int> > &A) {
    
    long m = A.size();
    long n = A[0].size();
    
    for (int i=1; i<n; i++) {
        A[0][i] = A[0][i-1] + A[0][i];
    }
    for (int i=1; i<m; i++) {
        A[i][0] = A[i-1][0] + A[i][0];
    }
    for (int i=1; i<m; i++) {
        for (int j=1; j<n; j++) {
            A[i][j] = A[i][j] + min(A[i-1][j], A[i][j-1]);
        }
    }
    return A[m-1][n-1];
}


int isScramble(string s1, string s2) {
    long len = s1.size();
    bool dp[len + 1][len + 1][len + 1];
    memset(dp, 0, sizeof(dp));
    
    for (long i = len - 1; i >= 0; i--) {
        for (long j = len - 1; j >= 0; j--) {
            dp[i][j][1] = (s1[i] == s2[j]);
            for (int l = 2; i + l <=len && j + l <= len; l++) {
                for (int n = 1; n < l; n++) {
                    dp[i][j][l] |= dp[i][j][n] && dp[i+n][j+n][l-n];
                    dp[i][j][l] |= dp[i][j+l-n][n] && dp[i+n][j][l-n];
                }
            }
        }
    }
    return dp[0][0][len];
}


int regexMatch(const string &s, const string &p) {
    string pat = "";
    int i = 0;
    int n = p.length();
    int m = s.length();
    while (i<n) {
        pat.push_back(p[i]);
        i++;
        while (i<n && pat.back() == p[i] && pat.back()=='*') {
            i++;
        }
    }
    n = pat.length();
    vector<vector<bool>> dp (m+1, vector<bool>(n+1,false));
    dp[0][0] = true;
    for (int i = 1; i<n+1; i++) {
        if (pat[i-1] == '*') {
            dp[0][i] = dp[0][i-2];
        }
    }
    for (int i = 1; i<m+1; i++) {
        for (int j = 1; j<n+1; j++) {
            if (pat[j-1]=='.' || pat[j-1] == s[i-1]) {
                bool v = dp[i-1][j-1];
                dp[i][j] = v;
            }
            else if (pat[j-1] == '*') {
                bool v = dp[i][j-2] ;
                if (s[i-1] == pat[j-2] || pat[j-2] == '.') {
                    v = (v || dp[i-1][j]);
                }
                dp[i][j] = v;
            }
            else {
                dp[i][j] = false;
            }
        }
    }
    return dp[m][n];
}

int wildcardMatch(const string &s, const string &p) {
    long m = s.length();
    long n = p.length();
    vector<vector<bool>> dp (m+1, vector<bool>(n+1,false));
    dp[0][0] = true;
    for (int i=1; i<n+1; i++) {
        if (p[i-1] == '*') {
            dp[0][i] = dp[0][i-1];
        }
    }
    for (int i=1; i<m+1; i++) {
        for (int j=1; j<n+1; j++) {
            if (p[j-1] == '*') {
                bool v = (dp[i-1][j] || dp[i-1][j-1] || dp[i][j-1]);
                dp[i][j] = v;
            }
            else if (p[j-1] == '?') {
                bool v = dp[i-1][j-1];
                dp[i][j] = v;
            }
            else if (p[j-1] == s[i-1]) {
                bool v = dp[i-1][j-1];
                dp[i][j] = v;
            }
            else {
                dp[i][j] = false;
            }
        }
    }
    return dp[m][n];
}

bool rec_is_interleave(string &a, string &b, string &c, long i, long j, long k)
{
    if (i<0 && j<0 && k<0) {
        return true;
    }
    if (k<0 && (i>0 || j>0)) {
        return false;
    }
    
    if (a[i] == c[k]) {
        return rec_is_interleave(a, b, c, i-1, j, k-1);
    }
    else if (b[j] == c[k]) {
        return rec_is_interleave(a, b, c, i, j-1, k-1);
    }
    else {
        return false;
    }
    
}

int isInterleave(string A, string B, string C) {
    long i = A.length();
    long j = B.length();
    long k = C.length();
//    vector<vector<bool>> dp(i+1, vector<bool>(j+1, false));
//    dp[0][0] = true;
//    for (int x=1; x<i+1; x++) {
//        if (A[x-1] == C[x-1]) {
//            dp[x][0] = dp[x-1][0];
//        }
//    }
//    for (int x=1; x<j+1; x++) {
//        if (B[x-1] == C[x-1]) {
//            dp[0][x] = dp[0][x-1];
//        }
//    }
//    for (int x = 1; x<i+1; x++) {
//        for (int y=1; y<j+1; y++) {
//            if (A[x-1] == C[x+y-1] && B[y-1] == C[x+y-1]) {
//                dp[x][y] = (dp[x-1][y] || dp[x][y-1]);
//            }
//            else if (A[x-1] == C[x+y-1]) {
//                dp[x][y] = dp[x-1][y];
//            }
//            else if (B[y-1] == C[x+y-1]) {
//                dp[x][y] = dp[x][y-1];
//            }
//            else {
//                dp[x][y] = false;
//            }
//        }
//    }
//
//    return dp[i][j];
    return rec_is_interleave(A, B, C, i-1, j-1, k-1);
}

int numDistinctSubsequences(string S, string T) {
    long m = S.length();
    long n = T.length();
    int dp[m+1][n+1];
    for (int i=0; i<n+1; i++) {
        dp[0][i] = 0;
    }
    for (int i=0; i<m+1; i++) {
        dp[i][0] = 1;
    }
    for (int i=1; i<m+1; i++) {
        for (int j=1; j<n+1; j++) {
            if(S[i-1]!=T[j-1]) {
                dp[i][j] = dp[i-1][j];
            }
            else {
                dp[i][j] = dp[i-1][j] + dp[i-1][j-1];
            }
        }
    }
    return dp[m][n];
}

int repeatingSubsequence(string A){
    int n = A.length();
    int dp[n+1][n+1];
    for (int i=0; i<n+1; i++) {
        dp[0][i] = 0;
        dp[i][0] = 0;
    }
    
    for (int i=1; i<n+1; i++) {
        for (int j=1; j<n+1; j++) {
            if (A[i-1]==A[j-1] && i!= j) {
                dp[i][j] = dp[i-1][j-1]+1;
            }
            else {
                dp[i][j] = max(dp[i-1][j-1], max(dp[i-1][j], dp[i][j-1]));
            }
            if (dp[i][j]>=2) {
                return 1;
            }
        }
    }
    return 0;
}

int longestIncreasingSubsequence(const vector<int> &A) {
    
    int n = A.size();
    int dp[n];
    for (int i=0; i<n; i++) {
        dp[i] = 1;
    }
    for (int i=1; i<n; i++) {
        for (int j=0; j<i; j++) {
            if (A[i]>A[j] && dp[j] >= dp[i]) {
                dp[i] = dp[j]+1;
            }
        }
    }
    int res = 0;
    for (int i = 0; i < n; i++ )
        if (res < dp[i])
            res = dp[i];
    return res;
}

int minDistance(string A, string B) {
    
    int m = A.length();
    int n = B.length();
    int dp[m+1][n+1];
    
    for (int i=0; i<n+1; i++) {
        dp[0][i] = i;
    }
    for (int i=0; i<m+1; i++) {
        dp[i][0] = i;
    }
    
    for (int i = 1; i<m+1; i++) {
        for (int j = 1; j<n+1; j++) {
            if (A[i-1]==B[j-1]) {
                dp[i][j] = dp[i-1][j-1];
            }
            else {
                dp[i][j] = min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1])) + 1 ;
            }
        }
    }
    return dp[m][n];
}


int maxAreaRectangleWithPermutation(vector<vector<int> > A) {
    
    int r = A.size();
    int c = A[0].size();
    vector<vector<int>> m(r, vector<int>(c,0));

    for (int j = 0; j<c; j++) {
        for (int i=0; i<r; i++) {
            if (i==0) {
                m[i][j] = A[i][j];
            }
            else{
                if (A[i][j] !=0) {
                    m[i][j] = m[i-1][j]+1;
                }
            }
        }
    }
    if (c==1 || r==1) {
        int curr_ar=0, max_ar=0;
        for (int i=0; i<r; i++) {
            for (int j=0; j<c; j++) {
                curr_ar = (j+1)*m[i][j];
                if (curr_ar> max_ar) {
                    max_ar = curr_ar;
                }
            }
        }
        return max_ar;
    }
    for (int i=0; i<r; i++) {
        vector<int> counts(c+1,0);
        for (int j=0; j<c; j++) {
            int v = m[i][j];
            counts[v]++;
        }
        int j=0;
        for (int k=counts.size()-1; k>=0; k--) {
            int counti = counts[k];
            while (counti>0) {
                m[i][j] = k;
                j++;
                counti--;
            }
        }
    }
    
    int curr_ar=0, max_ar=0;
    for (int i=0; i<r; i++) {
        for (int j=0; j<c; j++) {
            curr_ar = (j+1)*m[i][j];
            if (curr_ar> max_ar) {
                max_ar = curr_ar;
            }
        }
    }
    
    return max_ar;
}

int chordCnt(int A){
    int p = 1000000007;
    int n = A;
    if(n == 0) return 1;
    vector<long> table (n + 1);
    table[0] = 1;
    table[1] = 1;
    for(int i = 2; i <= n; i++) {
        for(int j = 0; j < i; j++) {
            table[i] = (table[i] + (table[j] * table[i - 1 - j])%p)%p;
        }
    }
    return table[n];
}

int climbStairs(int A) {
    vector<int> m(A+1);
    m[0] = 1;
    m[1] = 1;
    for (int i = 2; i<=A; i++) {
        int s = m[i-1];
        if (i-2 >= 0) {
            s+=m[i-2];
        }
        m[i] = s;
    }
    return m[A];
}

int numDecodings(string A) {
    int n = A.size();
    vector<int> m(n);
    if(A[0] != '0')
    {
        m[0] = 1;
        m[1] = 1;
    }
    for (int i = 2; i <= n; i++)
    {
        m[i] = 0;
        
        // If the last digit is not 0, then last digit must add to
        // the number of words
        if (A[i-1] > '0')
            m[i] = m[i-1];
        
        // If second last digit is smaller than 2 and last digit is
        // smaller than 7, then last two digits form a valid character
        if (A[i-2] == '1' || (A[i-2] == '2' && A[i-1] < '7') )
            m[i] += m[i-2];
    }
    return m[n];
}

int longestSubsequenceLength(const vector<int> &A) {
    int n = A.size();
    if (n==0) {
        return 0;
    }
    vector<int> lis(n);
    vector<int> lds(n);
    
    for (int i=0; i<n; i++) {
        lis[i] = 1;
    }
    
    for (int i=1; i<n; i++) {
        for (int j=0; j<i; j++) {
            if (A[i] > A[j] && lis[i] < lis[j]+1) {
                lis[i] = lis[j]+1;
            }
        }
    }
    
    for (int i=0; i<n; i++) {
        lds[i] = 1;
    }
    for (int i = n-2; i>=0; i--) {
        for (int j = n-1; j>i; j--) {
            if (A[i] > A[j] && lds[i] < lds[j]+1) {
                lds[i] = lds[j]+1;
            }
        }
    }
    int res = INT_MIN;
    for (int i=0; i<n; i++) {
        if (lis[i]+lds[i] -1 > res) {
            res = lis[i]+lds[i] -1 ;
        }
    }
    return res;
}
