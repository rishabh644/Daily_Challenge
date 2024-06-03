#include<iostream>
#include<bits/stdc++.h>

using namespace std;


bool isPalindrome(int n)
{
    int rev=0;

    while(n)
    {
        int digit=n%10;
        n/=10;
        rev*=10;
        rev+=digit;

    }
    cout << " n " << n << " rev " << rev << endl;
    if(rev==n)
    return true;
    else
    return false;

}

bool perfectSquare(int n)
{

    for(int i=1;i*i<=n;i++)
    {
        if(i*i==n)
        return true;
    }

    return false;
}

class Solution {
  public:
    int countSuperPalindrome(int l, int r) {
        // code here

        int i;
        int count =0;
        for(i=l;i<=r;i++)
        {
            if(isPalindrome(i) && perfectSquare(i))
            count++;
        }

        return count;
    }
};

int main()
{

    Solution obj;

    cout << obj.countSuperPalindrome(1, 10) << endl;

    return 0;
}