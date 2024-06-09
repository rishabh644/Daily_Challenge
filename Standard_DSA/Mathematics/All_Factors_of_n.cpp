#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution{

   public:

   void Allfactors(int n)
  {

      stack<int> st;

      for (int i = 1; i * i <= n;i++)
      {
             if(n%i==0)
                { cout << i << " ";
                  if((n/i)!=i)
                  st.push((n / i));
                }
      }

      while(!st.empty())
      {
          cout << st.top() << " ";
          st.pop();
      }
  }

};

int main()
{
    int n;

    cout << "Enter value of n" << endl;

    cin >> n;

    Solution obj;

    obj.Allfactors(n);

    return 0;
}