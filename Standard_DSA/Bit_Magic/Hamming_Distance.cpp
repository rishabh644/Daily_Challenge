class Solution {
public:
    int hammingDistance(int x, int y) {

        int result=x^y;

        int count=0;

        while(result>0)
        {
            if(result&1)
            count+=1;

            result>>=1;
        }

        return count;
    }
};
///////////////////
class Solution {
public:
    int hammingDistance(int x, int y) {
        int result=x^y;
        int count=0;
        while(result>0)
        {
            count+=1;
            // remove the righmost bit of '1'
            result=result&(result-1);
        }
        return count;
    }
};