class Solution {
public:

    void swap(vector<int>&arr,int i,int j)
    {
        int t=arr[i];
        arr[i]=arr[j];
        arr[j]=t;
    }

    int countbeautifulpermutation(vector<int>arr,int i)
    {
          if(i==arr.size())
          {
              for(int k=1;k<arr.size();k++)
              {
                 if(k%arr[k]!=0 && arr[k]%k!=0)
                 return 0;
              }

              return 1;

          }

          int cnt=0;

          for(int j=i;j<arr.size();j++)
          {

              swap(arr,i,j);
              cnt+=countbeautifulpermutation(arr,i+1);
              swap(arr,i,j);

          }

          return cnt;

    }

    int countArrangement(int n)
    {

        vector<int>arr(n+1,0);

        for(int i=1;i<=n;i++)
        {
            arr[i]=i;
        }

        int res=countbeautifulpermutation(arr,1);

        return res;

    }
};
/////////////////////////////////////////////////////////////-------------------------------------------///////////////////////////////////-------------------------------------------------//////////////////////////////////////
class Solution {
public:

    void swap(vector<int>&arr,int i,int j)
    {
        int t=arr[i];
        arr[i]=arr[j];
        arr[j]=t;
    }

    int countbeautifulpermutation(vector<int>arr,int i)
    {
          if(i==arr.size())
          {

              return 1;

          }

          int cnt=0;

          for(int j=i;j<arr.size();j++)
          {
              // swap the elements to generate new permutation

              swap(arr,i,j);

              if(arr[i]%i==0 || i%arr[i]==0)
              cnt+=countbeautifulpermutation(arr,i+1);

              // backtrack
              swap(arr,i,j);

          }

          return cnt;

    }

    int countArrangement(int n)
    {

        vector<int>arr(n+1,0);

        for(int i=1;i<=n;i++)
        {
            arr[i]=i;
        }

        int res=countbeautifulpermutation(arr,1);

        return res;

    }
};
//////////////////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
private:
    int count=0;
    vector<bool>visited;
public:
    int countArrangement(int n)
    {

       visited=vector<bool>(n+1,false);
       calculate(n,1,visited);
       return count;
    }

    void calculate(int N,int pos,vector<bool>visited)
    {

       if(pos>N)
       count++;

       for(int i=1;i<=N;i++)
       {
           if(!visited[i] && (pos%i==0 || i%pos==0))
           {
              visited[i]=true;
              calculate(N,pos+1,visited);
              visited[i]=false;
           }

       }

    }
};