#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int precedence(char ch)
    {

        if(ch=='+' || ch=='-')
        return 1;
        else if(ch=='*' || ch=='/')
        return 2;
        else if(ch=='^')
        return 3;

        return 0;

    }

    string infixToPostfix(string s)
    {

       // Your code here
       string ans;

       stack<char>st;

       st.push('(');
       s+=')';

       for(auto ch:s)
       {
          if(ch=='(')
          {
            st.push(ch);
          }
          else if(ch=='+' || ch=='-')
          {
              // Operator encountered

              while(!st.empty() && precedence(st.top())>=precedence(ch))
              {
                ans+=st.top();
                st.pop();
              }
              st.push(ch);
          }
          else if(ch==')')
          {
             while(!st.empty() && st.top()!='(')
             {
                ans+=st.top();
                st.pop();
             }
             if(!st.empty())
             {
                st.pop(); // pop the '('
             }
          }
          else if(ch==' ')
          {
              continue;
          }
          else
          {
             ans+=ch;
          }

       }

       return ans;

    }

    int calculate(string s)
    {

        int i=0;

        int n=s.size();

        string postfix=infixToPostfix(s);

        cout << "Postfix " << postfix << endl;

        stack<int>ans;

        for(auto ch:postfix)
        {
            if(ch=='+')
            {
                int b=ans.top();
                ans.pop();
                int a=ans.top();
                ans.pop();
                cout << a + b << endl;
                ans.push(a+b);
            }
            else if(ch=='-')
            {
                 int b=ans.top();
                 ans.pop();
                 if(ans.empty())
                 {
                    ans.push(-1*b);
                 }
                 else
                 {
                    int a=ans.top();
                    cout << a - b << endl;
                    ans.push(a-b);
                 }
            }
            else
            {
                ans.push(ch-'0');
            }

        }

        return ans.top();

    }
};

int main()
{
    Solution obj;

    string input = "1-(    -2)";

    cout<<"Evaulute result "<<obj.calculate(input)<<endl;

    return 0;
}
