//
//  HashingSolutions.cpp
//  Hashing
//
//  Created by Apoorv on 27/08/17.
//  Copyright © 2017 presonal. All rights reserved.
//

#include "HashingSolutions.hpp"


int colorful(int A) {
    
    set<int> s;
    set<int>:: iterator it;
    vector<int> digits;
    int n = A;
    while (n>=10)
    {
        if (n/10) {
            digits.push_back(n%10);
            n = n/10;
        }
    }
    digits.push_back(n);
    
    for (int l=1; l<=digits.size(); l++) {
        for (int i = 0; i<=digits.size()-l; i++) {
            int p = 1;
            for (int j=i; j<i+l; j++) {
                p = p*digits[j];
            }
            it = s.find(p);
            if (it==s.end()) {
                s.insert(p);
            }
            else {
                return 0;
            }
        }
    }
    return 1;
    
}
