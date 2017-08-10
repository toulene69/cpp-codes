//
//  main.cpp
//  ReverseStringWordByWord
//
//  Created by Apoorv on 17/05/17.
//  Copyright © 2017 presonal. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;

void reverseWords(string &A)
{
    vector<string> temp;
    int i,j;
    for (i = A.length()-1; i>=0; i--) {
        if (A[i] != ' ') {
            break;
        }
    }
    string s;
    for (j = i; j>=0; j--)
    {
        if (A[j] == ' ')
        {
            if (!s.empty())
            {
                temp.push_back(s);
                temp.push_back(" ");
                s.clear();
            }
        }
        else
        {
            s += A[j];
        }
    }
    if (!s.empty()) {
        temp.push_back(s);
    }
    while (temp.back() == " ") {
        temp.pop_back();
    }
    A.clear();
    for (int k =0 ; k < temp.size(); k++) {
        reverse(temp[k].begin(), temp[k].end());
        A.append(temp[k]);
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    string s = " ankrqzzcel  dyaiug y rkicv t";
    reverseWords(s);
    std::cout << s << endl;
    return 0;
}
