class Solution {
public:
    bool parseBoolExpr(string e)
    {

      stack<char>st1; // operators
      stack<char>st2; // expresn

      int i=0;

      int n=e.size();

      char opr;
      bool result,exr;
      char expr;


      while(i<n)
      {

         if(e[i]=='&' || e[i]=='|' || e[i]=='!')
         {
            st1.push(e[i]);
         }
         else if(e[i]==')')
         {
            opr=st1.top();
            st1.pop();

            expr=st2.top();
            if(expr=='f')
            result=false;
            else
            result=true;


            while(!st2.empty() && st2.top()!='(')
            {
                expr=st2.top();
                st2.pop();
                if(expr=='f')
                 exr=false;
                else
                 exr=true;

                if(opr=='|')
                {
                   result=result|exr;
                }
                else if(opr=='&')
                {
                    result=result&exr;
                }
                else
                {
                    result=!result;
                }
            }
            st2.pop();
            if(result)
            st2.push('t');
            else
            st2.push('f');

         }
         else if(e[i]=='(' || e[i]!=',')
         {
            st2.push(e[i]);
         }

         i+=1;

      }

      return st2.top()=='t'?true:false;

    }
};