//
//  main.cpp
//  MinCharacterRequiredForPallindrome
//
//  Created by Apoorv on 14/05/17.
//  Copyright © 2017 presonal. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;


int solve(string A)
{
    int n = A.length();
    reverse(A.begin(),A.end());
    int i = 0;
    int j = n-i-1;
    string temp = A;
    int count = 0;
    while (i<=j)
    {
        
        if (temp[i] == temp[j])
        {
            i++;
            j--;
        }
        else
        {
            bool flag = true;
            for (int k = i-1; k>=0; k--)
            {
                if (temp[i]==temp[k]) {
                    continue;
                }
                else
                {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                temp.push_back(A[i]);
                count ++;
            }
            else
            {
                temp = A;
                for (int k =i ; k>=0; k--)
                {
                    temp.push_back(temp[k]);
                }
                count = i+1;
                
            }
            i = 0;
            j = temp.length() - 1;
        }
    }
    return count;
    
}


int main(int argc, const char * argv[]) {
    // insert code here...
    string s = "aaaaabbc";
    std::cout << solve(s) << endl;
    return 0;
}
