class Solution {
public:
    int evaluateExpr(stack<variant<int,char>>&st)
    {

       // If stack is empty or the expression starts with a symbol,
       // then append 0 to the stack

       if(st.empty() || !holds_alternative<int>(st.top()))
       {
        st.push(0);
       }

       int res=get<int>(st.top());
       st.pop();

       // Evaluate the expression till we get correspinding ')'
       while(!st.empty() && ( get<char>(st.top())!=')'))
       {
            char sign=get<char>(st.top());
            st.pop();

            if(sign=='+')
            {
                res+=get<int>(st.top());
            }
            else
            {
                res-=get<int>(st.top());
            }
            st.pop();
       }
       return res;
    }

    int calculate(string s)
    {

        int operand=0;
        int n=0;

        stack<variant<int,char>>st;

        for(int i=s.size()-1;i>=0;--i)
        {
            char ch=s[i];

            if(isdigit(ch))
            {
              // Forming the operand - in reverse order.
              operand=pow(10,n)*(ch-'0')+operand;
              n+=1;
            }
            else if(ch!=' ')
            {
                if(n!=0)
                {
                  // save the operand on the stack as we encounter some non-diigt
                  st.push(operand);
                  n=0;
                  operand=0;
                }
                if(ch=='(')
                {
                    int res=evaluateExpr(st);
                    st.pop();
                    //Append the evaluated result to the stack
                    st.push(res);
                }
                else
                {
                    // For other non-digits, judt push onto the stack
                    st.push(ch);
                }

            }

        }


        // Push the last operant to stack, if any
        if(n!=0)
        {
            st.push(operand);
        }

        // Evaluate any left overs in the stack

        return evaluateExpr(st);

    }
};