    bool judgeSquareSum(int c) {


        long long  i=0;
        long long j=(int)sqrt(c);

        while(i<=j)
        {

            if( (i*i+j*j)==c)
            return true;
            else if( (i*i+j*j)>c)
            j-=1;
            else
            i+=1;

        }

        return false;


    }