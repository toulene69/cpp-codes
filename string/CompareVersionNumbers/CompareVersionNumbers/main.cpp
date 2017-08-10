//
//  main.cpp
//  CompareVersionNumbers
//
//  Created by Apoorv on 15/05/17.
//  Copyright © 2017 presonal. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <iterator>

using namespace std;



int compareVersion(string A, string B) {
    
    vector<string> splitA , splitB;
    string temp;
    for (string::const_iterator it = A.begin() ; it != A.end(); it++)
    {
        if (*it == '.')
        {
            if (!temp.empty())
            {
                splitA.push_back(temp);
                temp.clear();
            }
        }
        else
        {
            temp += *it;
        }
    }
    if (!temp.empty()) {
        splitA.push_back(temp);
    }
    temp.clear();
    for (string::const_iterator it = B.begin() ; it != B.end(); it++)
    {
        if (*it == '.')
        {
            if (!temp.empty())
            {
                splitB.push_back(temp);
                temp.clear();
            }
        }
        else
        {
            temp += *it;
        }
    }
    if (!temp.empty()) {
        splitB.push_back(temp);
    }
    temp.clear();
    for (int i =0 ; i < splitA.size() && i < splitB.size(); i++)
    {
         long double v1 = stold(splitA[i]);
         long double v2 = stold(splitB[i]);
        if (v1>v2) {
            return 1;
        }
        else if (v1<v2)
        {
            return -1;
        }
    }
    if (splitA.size() < splitB.size())
    {

        for (int i = splitA.size(); i< splitB.size(); i++)
        {
            if (stold(splitB[i]) != 0) {
                return -1;
            }
        }
        return 0;
    }
    else if (splitA.size() > splitB.size())
    {
        for (int i = splitB.size(); i< splitA.size(); i++)
        {
            if (stold(splitA[i]) != 0) {
                return 1;
            }
        }
        return 0;
    }
    else
    {
        return 0;
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    string a = "444444444444444444444444";
    string b = "4444444444444444444444444";
    std::cout << compareVersion(a,b) << endl;
    return 0;
}
