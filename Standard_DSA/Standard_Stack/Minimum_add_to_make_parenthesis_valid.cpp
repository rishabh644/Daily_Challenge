class Solution {
public:
    int minAddToMakeValid(string s)
    {
        stack<char>st;

        for(char ch:s)
        {
            if(ch=='(')
            st.push(ch);
            else if( !st.empty() && st.top()=='(' )
            st.pop();
            else
            st.push(')');
        }

        return st.size();
    }
};
///////////////////////////////////
class Solution {
public:
    int minAddToMakeValid(string s)
    {

        int openBrackets=0;

        int minAddsRequired=0;

        for(char c:s)
        {
            if(c=='(')
            {
                openBrackets++;
            }
            else
            {
                openBrackets>0?openBrackets--:minAddsRequired++;
            }
        }

        return minAddsRequired+openBrackets;

    }
};