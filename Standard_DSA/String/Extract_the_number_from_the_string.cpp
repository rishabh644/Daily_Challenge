// Given a sentence containing several words
// and numbers. Find the largest number among them
// which does not contain 9. If no such number exists, return -1

long long my_convert(string& sentence,int j,int i)
{
    long long sum=0;

    int k=i-1;

    long long prod=1;

    while(k>=j)
    {
        sum=(sentence[k]-'0')*prod+sum;
        prod*=10;
        k-=1;
    }

    return sum;
}

class Solution {
  public:
    long long ExtractNumber(string sentence) {

        // code here

        int i=0;
        int n=sentence.size();
        int j=-1;

        bool ctn=false;

        long long ans=-1;
        long long temp;

        while(i<n)
        {
            if(isdigit(sentence[i]))
            {
               if(j==-1)
               {

                   j=i;
               }
               if(sentence[i]=='9')
               {
                   ctn=true;
               }

            }
            else if(sentence[i]==' ' && j!=-1 && !ctn)
            {
                temp=my_convert(sentence,j,i);

                if(ans<temp)
                {
                    ans=temp;
                }

            }
            if(sentence[i]==' ')
            {
                j=-1;
                ctn=false;
            }

            i+=1;
        }

        return ans;

    }
};
