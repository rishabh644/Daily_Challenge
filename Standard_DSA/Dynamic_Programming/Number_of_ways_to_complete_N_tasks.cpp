Given an array A[ ] denoting the time taken to complete N tasks,
determine the minimum amount of time required to
finish the tasks considering that you can skip any task, but
skipping two consecutive tasks is forbidden.


/*you cannot skip two consecutive tasks*/

int minAmount(int A[] , int N)
{


        if(N==0)
        return 0;

        if(N==1)
        return A[0];

        int t2=0;
        int t1=A[0];

        // t2 minm time to complete takeing n-2th task
        // t1 represent time to complete taking n-1th task


        for(int i=2;i<=N;i++)
        {
            // t represent time to complete taking th task
            // if i take th task i have option to skip n-1 task hence
            // t=min(A[i-1]+t2,A[i-1]+t1)

            int t=min(A[i-1]+t2,A[i-1]+t1);

            t2=t1;

            t1=t;
        }


        // ans will be min of t1 and t2
        return min(t1,t2);

}