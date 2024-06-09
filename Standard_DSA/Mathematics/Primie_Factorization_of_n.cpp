#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution
{

  public:
  void Allprimevectors(int n)
  {

0

      for (int i = 2; i * i <= n;i++)
      {
            while(n%i==0)
            {

                cout << i<<" ";
                n = n / i;
            }

      }
  }
};

int main()
{

    int n;

    cout << "Enter value of n " << endl;

    cin >> n;

    cout << " See its prime factorisation " << endl;

    Solution obj;

    obj.Allprimevectors(1000);

    return 0;
}
