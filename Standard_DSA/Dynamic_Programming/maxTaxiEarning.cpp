
long long maxTaxiEarnings(int n,vector<vector<int>>rides)
{

    sort(A.begin(), A.end());

    vector<long long> dp(n + 1, 0);

    int j = 0;

    for (int i = 1; i <= n;++i){

        dp[i] = max(dp[i], dp[i - 1]);

        while(j<A.size() && A[j][0]==i) {

            dp[A[j][1]] = max(dp[A[j][1]], dp[i] + A[j][1] - A[j][0] + A[j][2]);
            ++j;
              }


                               }
}
////////////////------------------//////////////////
#define pii pair<int,int>
long long maxTaxiEarning(int n,vector<vector<int>>rides)
{

    vector<vector<pii>> ridesstartAt(n);

    for(auto& ride:rides)
    {

        int s = ride[0];
        int e = ride[1];
        int t = ride[2];

        ridestart[s].push_back({e, e - s + t});
    }

    vector<long long> dp(n + 1);

    for (int i = n - 1; i >= 1;--i)
    {
         for(auto& [e,d]:ridestartAt[i])
         {

             dp[i] = max(dp[i], dp[e] + d);
         }

         dp[i] = max(dp[i], dp[i + 1]);
    }

    return dp[1];
}
