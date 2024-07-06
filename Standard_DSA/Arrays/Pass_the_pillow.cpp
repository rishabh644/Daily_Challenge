// Brute FOrce

int passThePillow(int n, int time) {

        int p=1;

        bool dir=true;
        while(time>0)
        {

           if(p==1)
           dir=true;
           else if(p==n)
           dir=false;

           if(dir)
           p+=1;
           else
           p-=1;

           time-=1;

        }

        return p;
    }
//////////////////-----------------------------////////////////////
    int passThePillow(int n, int time) {


    if(time==1)
    return 2;

    int dir=(time)/(n-1);
    int r=time%(n-1);
    if(dir%2==0)
    {
         return r+1;
    }
    else
    {
         return (n-r);
    }





    }
};