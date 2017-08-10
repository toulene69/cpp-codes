//
//  main.cpp
//  CountAndSay
//
//  Created by Apoorv on 10/05/17.
//  Copyright © 2017 presonal. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

string countAndSay(int A)
{
    string seq = "";
    if (A == 1) {
        return "1";
    }
    vector<int> m;
    m.push_back(1);
    for (int i=1; i<A; i++)
    {
        int s = m.size();
        int j = 0;
        vector<int> temp;
        while(j<s)
        {
            int count = 1;
            int x = m[j];
            while (j<s-1 && x == m[j+1])
            {
                count ++;
                j++;
            }
            temp.push_back(count);
            temp.push_back(x);
            j++;
        }
        m = temp;
    }
    for (int i = 0; i<m.size(); i++)
    {
        seq.append(to_string(m[i]));
    }
    return seq;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    cout << countAndSay(6) << endl;
    return 0;
}
