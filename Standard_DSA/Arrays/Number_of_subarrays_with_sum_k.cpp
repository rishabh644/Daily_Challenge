int findSubArraySum(int A[], int N, int k)
{
        // code here


        int cnt=0;

        for(int i=0;i<N;i++)
        {
            int sum=0;
            for(int j=i;j<N;j++)
            {
                sum+=A[j];
                if(sum==k)
                cnt+=1;
            }
        }

        return cnt;

}

/////////////////////////////---------------------//////////////////////////
