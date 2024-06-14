class Solution {
public:
    int change(int amount, vector<int>& coins) {

        int n=coins.size();

        vector<int>prev(amount+1,0);
        vector<int>cr(amount+1,0);
        prev[0]=1;


        for(int i=1;i<=n;i++)
        {
            cr[0]=1;
            for(int am=1;am<=amount;am++)
            {
                 cr[am]=prev[am];
                 if(am>=coins[i-1])
                 {
                    cr[am]=cr[am]+cr[am-coins[i-1]];
                 }
            }
            prev=cr;
        }

        return prev[amount];
    }
};