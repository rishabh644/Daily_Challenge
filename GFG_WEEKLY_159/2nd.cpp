class Solution {
  public:

    void count_set_bit(long long an,vector<int>&count)
    {
         int i=60;

         while(an)
         {
             if(an&1)
             {
                 count[i]+=1;
             }

             an>>=1;
             i-=1;
         }


    }

    int makeBridgeOne(int n, vector<long long> &arr) {
        // code here



        vector<int>count(61,0);

        int an;

        for(int i=0;i<n;i++)
        {

            count_set_bit(arr[i],count);

        }

        auto itr=count.begin();

        while(itr!=count.end())
        {
            if(*itr!=0)
            break;

            itr++;
        }

        int maxo=*max_element(itr,count.end());
        int mino=*min_element(itr,count.end());


        return n-maxo;





    }
};