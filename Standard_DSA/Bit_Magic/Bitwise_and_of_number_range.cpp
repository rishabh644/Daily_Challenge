class Solution {
public:
    int rangeBitwiseAnd(int m, int n)
    {
         int shift=0;

         // find the common 1-bits

         while(m<n)
         {
            m>>=1;
            n>>=1;
            ++shift;
         }

         return m<<shift;

    }
};

//////////////--------------//////////////

class Solution {
public:
    int rangeBitwiseAnd(int m, int n)
    {
        while(m<n)
        {

          // turn off the righmost 1-bit
          n=n&(n-1);

        }

        return n;

    }
};

///////////////////---------------///////