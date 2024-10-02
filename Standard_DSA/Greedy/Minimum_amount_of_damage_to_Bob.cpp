class Solution {
public:
    long long minDamage(int power, vector<int>& D, vector<int>& H)
    {
        vector<int>A(D.size());

        for(int i=0;i<D.size();++i)
        {
            A[i]=i;
        }

        sort(A.begin(),A.end(),[&](int i,int j){
            return (H[i]+power-1)/power * D[j] < (H[j]+power-1)/power * D[i];
        });

        long long res=0,t=0;

        for(int i:A)
        {
            t+=(H[i]+power-1)/power;
            res+=D[i]*t;
        }

        return res;

    }
};