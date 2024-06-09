#include<iostream>
#include<bits/stdc++.h>

using namespace std;

string removeOuterParentheses(string s) {

           stack<char>st;
           st.push(0);
           int n=s.size();
           int ind;

           cout << "pushed" << endl;

           string ans="";

           for(int i=1;i<n;i++)
           {
              if(s[i]=='(')
              {
                cout << "pushed" << endl;
                st.push(i);
              }
              else
              {
                cout << "poped from front" << endl;
                if(st.size()==1)
                {
                    ind=st.top();
                    cout << ind << " " << i << endl;
                    ans += s.substr(ind + 1, i - ind - 1);

                }

                st.pop();
              }
           }


           return ans;

}

int main()
{
    string st = "(()())(())";

    cout << "After removing outermost parenthesis from each balanced parenthesis substring" << endl;
    cout << removeOuterParentheses(st) << endl;

    return 0;
}