string roundToNearest(string str)
{
        // Complete the function


        int i=0;
        int n=str.size();


        char ch=str[n-1];

        if(ch<='5')
        {
            str[n-1]='0';

        }
        else
        {
            str[n-1]='0';

            int j=n-2;

            while(j>=0)
            {
                if(str[j]!='9')
                {
                    str[j]=str[j]+1;
                    break;
                }
                else
                {
                    str[j]='0';
                }

                j-=1;
            }

            if(j==-1)
            {
                str='1'+str;
            }

        }


        return str;

}