class Solution {
public:
    int evalRPN(vector<string>& tokens) {

     stack<int>st;

     for(auto s:tokens)
     {
        if(s=="+" || s=="-" || s=="*" || s=="/")
        {
            int b=st.top();
            st.pop();
            int a=st.top();
            st.pop();

            if(s=="+")
            st.push(a+b);
            else if(s=="-")
            st.push(a-b);
            else if(s=="/")
            st.push(a/b);
            else
            st.push(a*b);
        }
        else
        {
            int n=0;
            char ch=s[0];
            int i=0;
            int sgn=1;
            if(ch=='-')
            {
                sgn=-1;
                i=1;
            }
            while(i<s.size())
            {   ch=s[i];
                n=n*10+(ch-'0');
                i+=1;
            }
            st.push(sgn*n);
        }

     }

     return st.top();

    }
};