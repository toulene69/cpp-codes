//
//  main.cpp
//  ValidNumber
//
//  Created by Apoorv on 17/05/17.
//  Copyright © 2017 presonal. All rights reserved.
//

#include <iostream>

using namespace std;

bool isCharValid(char x)
{
    if (x>=48 && x<=57) {
        return true;
    }
    
    switch (x) {
        case 'e':
        case '+':
        case '-':
        case '.':
        case ' ':
            return true;
        default:
            break;
    }
    return false;
}

bool isDigit(char x)
{
    if (x>=48 && x<=57) {
        return true;
    }
    return false;
}

int isNumber(const string &A)
{
    bool expFound = false;
    bool decSign = false;
    bool expSign = false;
    bool decFound = false;
    bool digitFound = false;
    bool spaceFound = false;
    int j = 0;
    for (; j < A.length(); j++) {
        if (A[j] != ' ') {
            break;
        }
    }
    for (int i =j ; i<A.length(); i++)
    {
        if (!isCharValid(A[i])) {
            return 0;
        }
        if (isDigit(A[i]))
        {
            if ((spaceFound && digitFound) || (spaceFound && (expFound || decSign || expSign)))
            {
                return 0;
            }
            digitFound = true;
        }
        switch (A[i])
        {
            case ' ':
            {
                spaceFound = true;
                break;
            }
            case 'e':
            {
                if (expFound)
                {
                    return 0;
                }
                expFound = true;
                break;
            }
            case '+':
            case '-':
            {
                if (expFound)
                {
                    if (expSign)
                    {
                        return 0;
                    }
                    else
                    {
                        expSign = true;
                    }
                }
                else
                {
                    if (decSign)
                    {
                        return 0;
                    }
                    else
                    {
                        decSign = true;
                    }
                }
                break;
            }
            case '.':
            {
                if ((i+1)<A.length() && isDigit(A[i+1]))
                {
                    if (decFound)
                    {
                        return 0;
                    }
                    else if (expFound)
                    {
                        return 0;
                    }
                    decFound = true;
                }
                else
                {
                    return 0;
                }
            }
            default:
                break;
        }
    }
    if (digitFound) {
        return 1;
    }
    else
        return 0;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    string s = " 0.1";
    std::cout << isNumber(s) <<endl ;
    return 0;
}
