class Solution {
public:
    int mySqrt(int x)
    {


        int l=0;
        int r=x;
        long long mid,ans;
        while(l<=r)
        {
            mid=(l+r)/2;

            if(mid*mid<x)
            {
                ans=mid;
                l=mid+1;
            }
            else if(mid*mid>x)
            {
                r=mid-1;
            }
            else
            {
                ans=mid;
                break;
            }
        }

        return ans;

    }
};