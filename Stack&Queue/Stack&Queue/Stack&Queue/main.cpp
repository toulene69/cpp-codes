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
    vector<int> v =  {10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
    vector<int> r = slidingMaximum(v,5);
    for (int i=0; i<r.size(); i++) {
        cout<<r[i]<<endl;
    }
//       std::cout << slidingMaximum(v,3) <<endl;
    return 0;
}
