//
//  main.cpp
//  AtoI
//
//  Created by Apoorv on 16/05/17.
//  Copyright © 2017 presonal. All rights reserved.
//

#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

bool isNumeric(char x)
{
    if (x>=48 && x<=57) {
        return true;
    }
    return false;
}

int charToInt(char x)
{
    return x - '0';
}

bool isWhitespace(char x)
{
    if (x == 32 || x==9 || x == 10) {
        return true;
    }
    return false;
}

int atoi(const string &A)
{
    int isNegative = -1;
    vector<char> digits;
    string::const_iterator it = A.begin();
    while (it != A.end())
    {
        if (isWhitespace(*it))
        {
            if (digits.empty() && isNegative == -1)
            {
                it++;
                continue;
            }
            else
            {
                break;
            }
        }
        else if (*it == '-' )
        {
            if (digits.empty())
            {
                isNegative = 1;
            }
            else
            {
                break;
            }
        }
        else if(*it == '+')
        {
            if (digits.empty())
            {
                isNegative = 0;
            }
            else
            {
                break;
            }
        }
        else if (isNumeric(*it))
        {
            if (digits.empty() && *it == '0') {
                if(isNegative == -1)
                {
                    isNegative = 0;
                }
            }
            else
            {
                digits.push_back(*it);
            }
        }
        else
        {
            break;
        }
        it++;
    }
    int base = 10;
    int place = 0;
    int num = 0;
    for (int i = digits.size()-1 ; i>=0 ; i--)
    {
        num += (charToInt(digits[i]) * pow(base,place));
        if (num < 0)
        {
            if (isNegative == 1)
            {
                return INT_MIN;
            }
            else
            {
                return INT_MAX;
            }
        }
        place ++;
    }
    if (isNegative == 1) {
        return num *-1;
    }
    return num;
}

int t_atoi(const string &str)
{
    int sign = 1, base = 0, i = 0;
    while (str[i] == ' ') { i++; }
    if (str[i] == '-' || str[i] == '+') {
        sign = (str[i++] == '-') ? -1 : 1;
    }
    while (str[i] >= '0' && str[i] <= '9') {
        if (base >  INT_MAX / 10 || (base == INT_MAX / 10 && str[i] - '0' > 7)) {
            if (sign == 1) return INT_MAX;
            else return INT_MIN;
        }
        base  = 10 * base + (str[i++] - '0');
    }
    return base * sign;
}



int main(int argc, const char * argv[]) {
    // insert code here...
    string s = "07041 6784513221729 1128 43144";
    std::cout << t_atoi(s) << endl;
    return 0;
}
