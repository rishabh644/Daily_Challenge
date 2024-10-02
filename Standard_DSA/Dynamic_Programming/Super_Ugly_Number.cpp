class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes)
    {

        if(n==1)
        return 1;

        int numPrimes=primes.size(); // Number of prime numbers
        vector<int>primeIndices(numPrimes,0); // Indices to track prime number  multiples

        int superUgly[n]; // Array to store super ugly numbers
        // memeset(superUgly,0,sizeof(superugly)); // Initialize the array

        superUgly[0]=1;

        for(int i=1;i<n;i++)
        {
            long minVal=INT_MAX; // Minimum value among the prime number multiples

            // Find the minimum value among the prime number multiples

            for(int j=0;j<numPrimes;j++)
            {
                minVal=min(minVal,(long)primes[j]*superUgly[primeIndices[j]]);
            }

            superUgly[i]=(int)minVal; // Store the minimum value as the next super
            //ugly


            // Increment the indices for prime number multiples that contribute
            // to the minum value

            for(int j=0;j<numPrimes;j++)
            {
                if(minVal==(long)primes[j]*superUgly[primeIndices[j]])
                {
                    primeIndices[j]++;
                }
            }

        }

        return superUgly[n-1]; // Return the nth super ugly number
    }
};