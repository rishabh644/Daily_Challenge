#include<iostream>
#include<bits/stdc++.h>

using namespace std;

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

    string infixToPostfix(string s) {
        // Your code here

        string ans="";

        stack<char>st;

        st.push('(');

        s+=')';

        for(auto ch:s)
        {
            cout << "char  " << ch << endl;
            if( (ch>=65 && ch<=90) || (ch>=97 && ch<= 122) || (ch>=48 && ch<=57))
            {

                ans=ans+ch;

            }
            else if(ch=='(')
            {
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
                    st.pop(); //pop the '('
                }

            }
            else
            {   //Operator encountered

               while(!st.empty() && precedence(st.top())>=precedence(ch))
               {
                   ans+=st.top();
                   st.pop();
               }
              st.push(ch);
            }


            cout<<"ans "<<ans<<endl;

        }



        return ans;

    }

int main()
{
    infixToPostfix("h^m^q^(7-4)");
    return 0;
}