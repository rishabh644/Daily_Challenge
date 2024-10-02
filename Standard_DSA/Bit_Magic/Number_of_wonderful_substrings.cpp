class Solution {
public:
    long long wonderfulSubstrings(string word)
    {
        int N=word.size();

        // Create the freq map
        //key=bitmask,value=frequency of bitmask key

        unordered_map<int,int>freq;

        // The empty prefix can be the smaller prefix, which is handled like this

        freq[0]=1;

        int mask=0;

        long long res=0L;

        for(int i=0;i<N;i++)
        {

            char c=word[i];
            int bit=c-'a';

            // Flip the parity of the c-th bit in the running prefix mask
            mask^=(1<<bit);

            //Count smaller prefixes that create substrings with no odd occuring letters
            res+=freq[mask];

            //Increment value associated with mask by 1
            freq[mask]++;

            // Loop through every possible letter that can appear an odd number of time in a substring

            for(int odd_c=0;odd_c<10;odd_c++)
            {
                res+=freq[mask^(1<<odd_c)];
            }

        }

        return res;



    }
};