//
//  main.cpp
//  LengthOfLastWord
//
//  Created by Apoorv on 17/05/17.
//  Copyright © 2017 presonal. All rights reserved.
//

#include <iostream>

using namespace std;

int lengthOfLastWord(const string &A) {
    int len = 0;
    int i;
    for ( i=A.length()-1; i>=0; i--)
    {
        if (A[i] != ' ') {
            break;
        }
    }
    for (int j = i; j>=0; j--)
    {
        if (A[j] == ' ') {
            break;
        }
        len++;
    }
    return len;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    string s = "Lebz Q";
    std::cout << lengthOfLastWord(s) << endl;
    return 0;
}
