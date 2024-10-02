class Solution {
public:
    int findCelebrity(int n)
    {

         for(int i=0;i<n;i++)
         {
            int no_p_i=0;
            int no_p_i_j=0;

            for(int j=0;j<n;j++)
            {
                if(j!=i)
                {
                    if(knows(j,i))
                    {
                        no_p_i+=1;
                    }
                    if(knows(i,j))
                    {
                        no_p_i_j+=1;
                    }

                }

            }

            if(no_p_i==n-1 && no_p_i_j==0)
            {
                return i;
            }

         }

         return -1;

    }
};
///////////////////////////////
public class Solution extends Relation {

    private int numberOfPeople;

    public int findCelebrity(int n) {
        numberOfPeople = n;
        for (int i = 0; i < n; i++) {
            if (isCelebrity(i)) {
                return i;
            }
        }
        return -1;
    }

    private boolean isCelebrity(int i) {
        for (int j = 0; j < numberOfPeople; j++) {
            if (i == j) continue; // Don't ask if they know themselves.
            if (knows(i, j) || !knows(j, i)) {
                return false;
            }
        }
        return true;
    }
}
//////////////////////