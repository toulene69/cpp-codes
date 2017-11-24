//
//  main.cpp
//  DynamicProgramming
//
//  Created by Apoorv on 06/11/17.
//  Copyright © 2017 presonal. All rights reserved.
//

#include <iostream>

#include "SolutionDynamicProgramming.hpp"

int main(int argc, const char * argv[]) {
    // insert code here...
    
    vector<vector<int>> v1 = {{1,0,1},{1,0,1},{1,0,1}};
    vector<int> v2 = {1};
    vector<int> v3 = {1};
    vector<vector<int>> v = {{1},
        {0},
        {1},
        {0},
        {1},
        {0},
        {1},
        {1},
        {1},
        {0},
        {0},
        {1},
        {0},
        {0},
        {1},
        {0},
        {0},
        {0},
        {0},
        {1},
        {1},
        {1},
        {0},
        {1},
        {0},
        {1},
        {0},
        {0},
        {1},
        {0},
        {0},
        {1},
        {0},
        {0},
        {0},
        {0},
        {1},
        {1},
        {1},
        {0},
        {0},
        {0},
        {0},
        {0},
        {1},
        {0},
        {0},
        {1},
        {1},
        {1},
        {0},
        {1},
        {1},
        {0},
        {0},
        {0},
        {0},
        {1},
        {0},
        {1},
        {0},
        {1},
        {1},
        {1},
        {0},
        {1},
        {1},
        {1},
        {1},
        {1},
        {1},
        {1},
        {0},
        {1},
        {1},{1}};

    
    vector<int>A1 = { 14, 24, 18, 46, 55, 53, 82, 18, 101, 20, 78, 35, 68, 9, 16, 93, 101, 85, 81, 28, 78 };
    string A = "LgR8D8k7t8KIprKDTQ7aoo7ed6mhKQwWlFxXpyjPkh";
    string B = "Q7wQk8rqjaH971SqSQJAMgqYyETo4KmlF4ybf";
    string C = "Q7wLgR8D8Qkk7t88KIrpqjarHKD971SqSQJTQ7aoAMgoq7eYd6yETmhoK4KmlQwWFlF4xybXfpyjPkh";
    cout <<    isInterleave(A,B,C);
    return 0;
}
