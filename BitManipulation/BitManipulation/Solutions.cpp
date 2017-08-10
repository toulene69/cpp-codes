//
//  Solutions.cpp
//  BitManipulation
//
//  Created by Apoorv on 02/08/17.
//  Copyright © 2017 presonal. All rights reserved.
//

#include "Solutions.hpp"

int numSetBits(unsigned int A) {

    int count = 0;
    while (A!=0) {
        if (A&1) {
            count++;
        }
        A = A>>1;
    }
    return count;
}

unsigned int reverse(unsigned int A) {

    unsigned int rev = 0;
    if (A == 0) {
        return rev;
    }
    int pos = 31;
    while (A!=0) {
        if (A&1) {
            rev |= (1<<pos);
        }
        A = A>>1;
        pos--;
    }
    return rev;
}

int findMinXor(vector<int> &A)
{
    int minXor = INT_MAX;
    sort(A.begin(), A.end());
    int x;
    for (int i=0; i<A.size()-1; i++)
    {
        x = A[i]^A[i+1];
        if (x < minXor)
        {
            minXor = x;
        }
    }
    
    return minXor;
}

int singleNumber(const vector<int> &A) {

    int num = A[0];
    for (int i = 1;i<A.size() ;++i) {
        num ^= A[i];
    }
    return num;
}

int singleNumber2(const vector<int> &A) {

    int ones = 0;
    int twos = 0;
    int not_threes = 0;
    for (int i=0; i<A.size(); ++i) {
        twos = twos| (ones & A[i]); // add to twice occuring
        ones = ones^A[i]; // add to once occuring
        not_threes = ~(ones & twos); // if number is in both onces and twice then
        ones = ones & not_threes; // remove from both
        twos = twos & not_threes;
    }
    
    return ones;
}

int divide(int dividend, int divisor) {

    long long n = dividend, m = divisor;
    // determine sign of the quotient
    int sign = n < 0 ^ m < 0 ? -1 : 1;
    
    // remove sign of operands
    n = abs(n), m = abs(m);
    
    // q stores the quotient in computation
    long long q = 0;
    
    // test down from the highest bit
    // accumulate the tentative value for valid bits
    for (long long t = 0, i = 31; i >= 0; i--)
        if (t + (m << i) <= n)
            t += m << i, q |= 1LL << i;
    
    // assign back the sign
    if (sign < 0) q = -q;
    
    // check for overflow and return
    return q >= INT_MAX || q < INT_MIN ? INT_MAX : q;
}

int cntBits(vector<int> &A)
{
    long long modulo = 1000000007;
    int res = 0;
    
    for (int i=0; i<32; ++i) {
        int bit0 = 0, bit1 = 0;
        for (int j = 0; j<A.size(); ++j) {
            
            if (A[j] & 1<<i) {
                bit1++;
            }
            else {
                bit0++;
            }
        }
        res = (res + 2*bit0*bit1)%modulo;
    }
    return res % modulo;
}
