// Given a sequence of n integers, the task is to find out the non-decreasing subsequence of
// length k with minimum sum. If no sequence exists output -1.
	int solve(int arr[],int sum,int ld,int i,int k,int n)
	{
	    if(i==n)
	    {
	        if(k==0)
	        {
	            return sum;
	        }
	        else
	        {
	            return INT_MAX;
	        }
	    }


	    if(k==0)
	    return sum;

	    int taken=INT_MAX;
	    if(arr[i]>=ld && k>0)
	    {
	        taken=solve(arr,sum+arr[i],arr[i],i+1,k-1,n);
	    }

	    int nottaken;

	    nottaken=solve(arr,sum,ld,i+1,k,n);

	    return min(taken,nottaken);


	}


	int minSum(int arr[], int N, int K)
	{

		// Your code goes here

		vector<int>ans;

		int minsum=INT_MAX;

		int i=0;


		while(i<=(N-K))
		{
		    int sum=arr[i];
		    minsum=min(minsum,solve(arr,sum,arr[i],i+1,K-1,N));
		    i+=1;
		}


		return minsum==INT_MAX?-1:minsum;




	}

/////////////////////------------------////////////
class Solution{

	public:
int t[1005][1005] ;
	int Solve(int *A, int i, int N, int K)
	{
	    if(K==0) return 0 ;

	    if(i==N) return 1e9;

	    if(t[i][K]!=-1)
	    return t[i][K] ;

	    int Ans = 1e9 ;

	    for(int j=i+1; j<N ; j++)
	    {
	        if(A[j] >= A[i]){
	            Ans = min(Ans, A[j] + Solve(A,j,N,K-1)) ;
	        }
	    }

	    return t[i][K] = Ans ;
	}

	int minSum(int arr[], int N, int K)
	{

		// Your code goes here
		memset(t,-1,sizeof(t)) ;
        int Ans = 1e9 ;
        for(int i=0 ; i<=N-K; i++)
        {
            Ans = min(Ans, arr[i] + Solve(arr,i,N,K-1));
        }
		if(Ans >= 1e9) return -1;
		return Ans ;
	}


};


///////////////////////////////-------------------------------//////////////////////////