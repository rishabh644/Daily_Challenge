class Solution {
  public:
    int XOR(int n, int m) {
        // code here

        return n^m;
    }
    int check(int a, int b) {
        // code here
        int count=0;

        while(a>1)
        {
            b>>=1;
            a-=1;
        }

        return b&1;

    }
    int setBit(int c, int d) {
        // code here

        int mask=1;

        while(c>0)
        {
            mask<<=1;
            c-=1;
        }

        d=mask|d;

        return d;
    }
};
/////////////////////----------///
class Solution {
  public:
    int XOR(int n, int m) {
        // code here

        return n^m;
    }
    int check(int a, int b) {
        // code here

        b=b>>(a-1);

        return b&1;



    }
    int setBit(int c, int d) {
        // code here

        int mask=1;

        mask=mask<<c;

        d=mask|d;
        return d;

    }
};