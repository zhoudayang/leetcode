/*************************************************************************
	> File Name: rotate_function.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年10月16日 星期日 14时47分57秒
 ************************************************************************/

#include<iostream>
using namespace std;
/*
	F(k) = 0 * Bk[0] + 1 * Bk[1] + ... + (n-1) * Bk[n-1]
	F(k-1) = 0 * Bk-1[0] + 1 * Bk-1[1] + ... + (n-1) * Bk-1[n-1]
	       = 0 * Bk[1] + 1 * Bk[2] + ... + (n-2) * Bk[n-1] + (n-1) * Bk[0]
	Then,

	F(k) - F(k-1) = Bk[1] + Bk[2] + ... + Bk[n-1] + (1-n)Bk[0]
		      = (Bk[0] + ... + Bk[n-1]) - nBk[0]
		      = sum - nBk[0]
	Thus,

	F(k) = F(k-1) + sum - nBk[0]
	What is Bk[0]?

	k = 0; B[0] = A[0];
	k = 1; B[0] = A[len-1];
	k = 2; B[0] = A[len-2];
	Thus:	
	
	Bk[0] = A[len-k]
	So:
	F(k) = F(k-1) + sum - nA[len-k]
...
*/

class solution {
public:
    int maxRotateFunction(vector<int>& A)
    {
        int f = 0;
        int sum = 0;
        int size = A.size();
        for (int i = 0; i<size; ++i)
        {
            sum += A[i];
            f += i*A[i];
        }
        int result = f;
        for (int i = 1; i<size; i++)
        {
            f = f+sum-size*A[size-i];
            result = max(result, f);
        }
        return result;
    }
};
