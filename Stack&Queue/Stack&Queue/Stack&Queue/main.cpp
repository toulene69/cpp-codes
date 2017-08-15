//
//  main.cpp
//  Stack&Queue
//
//  Created by Apoorv on 14/08/17.
//  Copyright © 2017 presonal. All rights reserved.
//

#include <iostream>
#include "StackQueueSolutions.hpp"


int main(int argc, const char * argv[]) {
    // insert code here...
    vector<string> v =  {"5", "1", "2", "+", "4", "*", "+", "3", "-"};
//    vector<int> r = prevSmaller(v);
//    for (int i=0; i<r.size(); i++) {
//        cout<<r[i]<<endl;
//    }
    std::cout << evalRPN(v) <<endl;
    return 0;
}
