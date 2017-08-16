//
//  StackQueueSolutions.cpp
//  Stack&Queue
//
//  Created by Apoorv on 14/08/17.
//  Copyright © 2017 presonal. All rights reserved.
//

#include "StackQueueSolutions.hpp"


vector<int> slidingMaximum(const vector<int> &A, int w) {
    deque<int> Q;
    vector<int> B;
    if (w>=A.size()) {
        B.push_back( *(max_element(A.begin(), A.end())) );
        return B;
    }
    for (int i = 0; i < w; i++) {
        while (!Q.empty() && A[i] >= A[Q.back()])
            Q.pop_back();
        Q.push_back(i);
    }
    for (int i = w; i < A.size(); i++) {
        B.push_back(A[Q.front()]);
        while (!Q.empty() && A[i] >= A[Q.back()])
            Q.pop_back();
        while (!Q.empty() && Q.front() <= i-w)
            Q.pop_front();
        Q.push_back(i);
    }
    B.push_back(A[Q.front()]);
    return B;
}




int largestRectangleArea(vector<int> &height) {
    int res = 0;
    stack<int> index;
    height.push_back(0);
    for (int i = 0; i<height.size(); ++i) {
        while (!index.empty() && height[index.top()] >= height[i]) {
            int h = height[index.top()];
            index.pop();
            
            int x = index.empty()? -1 : index.top();
            
            if (h*( i - x -1 ) > res) {
                res = h*( i - x -1 );
            }
        }
        index.push(i);
    }
    return res;
}

int trap(const vector<int> &arr) {
    int result = 0;
    int n = arr.size();
    // maximum element on left and right
    int left_max = 0, right_max = 0;
    
    // indices to traverse the array
    int lo = 0, hi = n-1;
    
    while(lo <= hi)
    {
        if(arr[lo] < arr[hi])
        {
            if(arr[lo] > left_max)
                // update max in left
                left_max = arr[lo];
            else
                // water on curr element = max - curr
                result += left_max - arr[lo];
            lo++;
        }
        else
        {
            if(arr[hi] > right_max)
                // update right maximum
                right_max = arr[hi];
            else
                result += right_max - arr[hi];
            hi--;
        }
    }
    
    return result;
}

int evalRPN(vector<string> &A) {
    stack<int> s;
    for (int i = 0 ; i<A.size(); ++i) {
        if (A[i] == "+") {
            int a = s.top();s.pop();
            int b = s.top();s.pop();
            s.push(a+b);
        }
        else if (A[i] == "-") {
            int a = s.top();s.pop();
            int b = s.top();s.pop();
            s.push(b-a);
        }
        else if (A[i] == "*") {
            int a = s.top();s.pop();
            int b = s.top();s.pop();
            s.push(a*b);
        }
        else if (A[i] == "/") {
            int a = s.top();s.pop();
            int b = s.top();s.pop();
            s.push(b/a);
        }
        else {
            s.push(stoi(A[i]));
        }
    }
    
    return s.top();
}

vector<int> prevSmaller(vector<int> &A) {
    vector<int> res;
    stack<int> a;
    if (A.size() == 0) {
        return res;
    }
    res.push_back(-1);
    a.push(A[0]);
    for (int i=1; i<A.size(); ++i) {
        while (!a.empty() && a.top() >= A[i]) {
            a.pop();
        }
        if (a.empty()) {
            res.push_back(-1);
        }
        else {
            res.push_back(a.top());
        }
        a.push(A[i]);
    }
    return res;
}

int braces(string A) {
    int res = 0;
    stack<string> s;
    int i = 0;
    while (i<A.length()) {
        if (A[i] == ')') {
            string temp = "";
            int x = 0;
            while (!s.empty() && s.top() != "(") {
                temp += s.top();
                s.pop();
                
                x++;
            }
            temp.reserve();
            if (x <=1) {
                res = 1;
                break;
            }
            if (!s.empty()) {
                s.pop();
            }
            s.push(temp);
        }
        else {
            s.push(A.substr(i,1));
        }
        i++;
    }
    return res;
}



string simplifyPath(string A) {
    stack<string> s, t;
    string temp = "";
    int i = 0, j = 0;
    while (i<A.length()) {
        temp = "";
        j = i+1;
        while (j< A.length() && A[j]!='/') {
            j++;
        }
        temp = A.substr(i,j-i);
        if (temp == "/..") {
            while (!s.empty() && s.top() == "/") {
                s.pop();
            }
            if (!s.empty()) {
                s.pop();
            }
        }
        else if ((temp == "/.")) {
            
        }
        else {
            if (!s.empty() && s.top() == "/") {
                s.pop();
            }
            s.push(temp);
        }
        i = j;
    }
    temp = "";
    while (!s.empty()) {
        t.push(s.top());
        s.pop();
    }
    while (!t.empty()) {
        temp+= t.top();
        t.pop();
    }
    if (temp.length()>1 && temp[temp.length()-1] == '/') {
        temp.pop_back();
    }
    if (temp == "") {
        temp = "/";
    }
    return temp;
}

string reverseString(string A) {
    stack<char> s;
    for (int i=0; i<A.length(); ++i) {
        s.push(A[i]);
    }
    string res = "";
    while (!s.empty()) {
        res += s.top();
        s.pop();
    }
    return res;
}

int isValid(string A) {
    int res = 1;
    stack<char> s;
    for (int i=0; i<A.length() && res == 1; i++) {
        
        switch (A[i]) {
            case '(':
            case '{':
            case '[':
                s.push(A[i]);
                break;
            case ')':
                if (!s.empty() && s.top() == '(') {
                    s.pop();
                }
                else {
                    res = 0;
                }
                break;
            case '}':
                if (!s.empty() && s.top() == '{') {
                    s.pop();
                }
                else {
                    res = 0;
                }
                break;
            case ']':
                if (!s.empty() && s.top() == '[') {
                    s.pop();
                }
                else {
                    res = 0;
                }
                break;
            default:
                break;
        }
    }
    if (res == 1 && !s.empty()) {
        res = 0;
    }
    
    return res;
}
