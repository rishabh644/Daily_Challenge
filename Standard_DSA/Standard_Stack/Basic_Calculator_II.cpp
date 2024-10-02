#include<stdio.h>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
   int precedence(char ch)
   {

      if(ch=='+' || ch=='-')
      return 1;
      else if(ch=='*' || ch=='/')
      return 2;

      return 0;
   }

    string infix_to_postfix(string s)
    {
        string ans;

        stack<char>st;

        for(auto ch:s)
        {

            if(isdigit(ch))
            {
                ans=ans+ch;
            }
            else{
                if(ch!=' ')
                {
                ans+=' ';
            while(!st.empty() && precedence(st.top())>=precedence(ch))
            {
                ans=ans+st.top();
                st.pop();

            }
            st.push(ch);
                }
              }
        }

        while(!st.empty())
        {
            ans=ans+st.top();
            st.pop();
        }

        return ans;
    }
    int calculate(string s)
    {
        string postfix=infix_to_postfix(s);
        //cout<<"postfix expression " << postfix << endl;
        stack<int>st;
        int n=0;
        char ch;
        bool buildingNumber=false;
        for(int i=0;i<postfix.size();i++)
        {
            ch=postfix[i];
            if(isdigit(ch))
            {
                n=n*10+(ch-'0');
                buildingNumber=true;
            }
            else if(ch==' ' && buildingNumber)
            {
                st.push(n);
                n=0;
                buildingNumber=false;
            }
            else
            {
                if(buildingNumber)
                {
                    st.push(n);
                    n = 0;
                    buildingNumber = false;
                }

                int b=st.top();
                st.pop();
                int a=st.top();
                st.pop();
                //cout << "a " << a << " b " << b << endl;
                if(ch=='+')
                st.push(a+b);
                else if(ch=='-')
                st.push(a-b);
                else if(ch=='*')
                st.push(a*b);
                else
                st.push(a/b);



            }


        }
        if(buildingNumber)
        st.push(n);

        return st.top();

    }
};

int main()
{
    Solution obj;
    string st = "3+5/2";
    cout<<"Result of evaluation "<<obj.calculate(st)<<endl;
    return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:

    int calculate(string s)
    {
        int len=s.length();
        if(len==0)
        return 0;

        stack<int>st;

        int currentNumber=0;

        char operation='+';

        for(int i=0;i<len;i++)
        {
            char currentChar=s[i];

            if(isdigit(currentChar))
            {
                currentNumber=(currentNumber*10)+(currentChar-'0');
            }

            if(!isdigit(currentChar) && !iswspace(currentChar) || i==len-1)
            {
                if(operation=='-')
                {
                    st.push(-currentNumber);
                }
                else if(operation=='+')
                {
                    st.push(currentNumber);
                }
                else if(operation=='*')
                {
                    int stackTop=st.top();
                    st.pop();
                    st.push(stackTop*currentNumber);
                }
                else if(operation=='/')
                {
                    int stackTop=st.top();
                    st.pop();
                    st.push(stackTop/currentNumber);
                }
                operation=currentChar;
                currentNumber=0;
            }

        }
        int result=0;
        while(st.size()!=0)
        {
            result+=st.top();
            st.pop();
        }
        return result;
    }
};
////////////////////////////////////////////////////////////////////////////////////////////////////////////
