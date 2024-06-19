#include <iostream>
using namespace std;

int nCr(int n, int r)
{

    if (r == 0 || r == n)
        return 1;
    return nCr(n - 1, r - 1) + nCr(n - 1, r);
}

int main()
{

    cout << nCr(10, 3); // Output: 10
    return 0;
}

Time complexity O(2^n)
Space complexity O(n)