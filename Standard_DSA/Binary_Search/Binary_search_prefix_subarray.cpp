constexpr int N=2e5;
int pre[N+1][6];

class Solution {
public:
    long long countOfSubstrings(string str, int k)
    {
       int n=str.size();

       vector<char>vowels={'a','e','i','o','u'};

       auto idx=[&](char c){
        for(int i=0;i<5;i++)
        if(c==vowels[i])
        return i;

        return -1;
       };

       for(int i=0;i<6;i++)
       pre[0][i]=0;

       for(int i=0;i<n;i++)
       {

          for(int j=0;j<6;j++)
          pre[i+1][j]=pre[i][j];

          if(idx(str[i])!=-1)
          {
            pre[i+1][idx(str[i])]++;
            pre[i+1][5]++;
          }
       }
          auto getCnt=[&](int l,int r,int i){
            return pre[r+1][i]-pre[l][i];
          };

          auto checkAllVowelsPresent=[&](int l,int r){

              for(int i=0;i<5;i++)
              {
                 if(getCnt(l,r,i)==0)
                 return false;
              }

              return true;
          };

          auto getConstantsCount=[&](int l,int r)
          {
             return (r-l+1)-getCnt(l,r,5);
          };

          auto getFirst=[&](int start){
            int s=start,e=n-1,res=n;
            while(s<=e)
            {
                int m=(s+e)/2;
                if(checkAllVowelsPresent(start,m) && getConstantsCount(start,m)>=k)
                {
                    res=m;
                    e=m-1;
                }
                else
                {
                    s=m+1;
                }
            }
            return res;
                                       };

          auto getLast=[&](int start){

              int s=start,e=n-1,res=start-1;

              while(s<=e)
              {
                 int m=(s+e)/2;
                 if(getConstantsCount(start,m)<=k)
                 res=m,s=m+1;
                 else
                 e=m-1;
              }

              return res;
                                     };


         long long ans=0;

         for(int i=0;i<n;i++)
         {
             int first=getFirst(i);
             int last=getLast(i);

             if(first<=last)
             ans+=last-first+1;

         }

         return ans;

       }





};