    bool isNonDecreasing(int n)
    {

        int lst=n%10;

        n=n/10;

        while(n)
        {
            int cd=n%10;

            if(cd>lst)
            return false;

            lst=cd;

            n/=10;
        }

        return true;

    }

    int find(int N){
        // code here

        int i=N;

        while(i>=1)
        {

            if(isNonDecreasing(i))
            return i;

            i-=1;
        }

    }


///////////////----------Optimized---------/////////////////////


    int find(int N){
        // code here

        string nums=to_string(N);
        int length=nums.size();

        // Iterate over the string to find and fix any decreasing order violations

        int ls=length;

        for(int i=length-1;i>0;i--)
        {
            if(nums[i]<nums[i-1])
            {

                // Decrement the previous digit
                nums[i-1]--;

                // Set all subsequent digits to '9'
                for(int j=i;j<ls;j++)
                {
                    nums[j]='9';
                }

                ls=i;


            }


        }

        for(int i=0;i<length;i++)
        {
            if(nums[i]!='0')
            return stoi(nums.substr(i));
        }

        return 0;

    }