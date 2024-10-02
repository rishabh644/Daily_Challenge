class Solution {
public:
    bool lemonadeChange(vector<int>& bills)
    {

        int cf=0;
        int ct=0;

        for(auto b:bills)
        {
            if(b==5)
            {
                cf+=1;
            }
            if(b==10)
            {
                if(cf>=1)
                {
                    cf-=1;
                    ct+=1;
                }
                else
                return false;
            }
            if(b==20)
            {
                if(cf>=1 && ct>=1)
                {
                    cf-=1;
                    ct-=1;
                }
                else if(cf>=3)
                {
                    cf-=3;
                }
                else
                return false;
            }

        }
        return true;
    }
};