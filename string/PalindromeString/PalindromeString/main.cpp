//
//  main.cpp
//  PalindromeString
//
//  Created by Apoorv on 10/05/17.
//  Copyright © 2017 presonal. All rights reserved.
//

#include <iostream>
using namespace std;
bool isAlphaNumeric(char c)
{
    if ((c >= 48 && c <= 57) || (c >= 97 && c <= 122))
    {
        return true;
    }
    return false;
}

int isPalindrome(string A)
{
    int n = A.length();
    int i = 0;
    int j = n-1;
    
    while(i<j)
    {
        char s = tolower(A[i]);
        char e = tolower(A[j]);
        if(!isAlphaNumeric(s))
        {
            i++;
            continue;
        }
        if(!isAlphaNumeric(e))
        {
            j--;
            continue;
        }
        if (isAlphaNumeric(s) && isAlphaNumeric(e))
        {
            if(s!=e)
            {
                return 0;
            }
            i++;
            j--;
        }
        
    }
    
    return 1;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    string s ="race a car";
    cout << isPalindrome(s);
    return 0;
}
