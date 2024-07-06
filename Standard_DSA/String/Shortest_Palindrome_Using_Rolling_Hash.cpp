typedef long long ll;
class Solution {
public:

    ll power(ll a,ll b,ll prime)
    {

       ll ans=1;
       ll prod=a;

       while(b)
       {
          if(b&1)
          {
             ans=(ans*prod)%prime;
          }

          prod=(prod*prod)%prime;

          b>>=1;
       }

       return ans;
    }

    string shortestPalindrome(string s) {

     ll forward_hash=0;
     ll backward_hash=0;


     ll base=256;
     ll prime=1000000007;

     ll n=s.size();

     ll ans=0;

     for(ll i=0;i<n;i++)
     {
        forward_hash=( (base*forward_hash)%prime + s[i] )%prime;

        backward_hash=( backward_hash+(s[i]*power(base,i,prime))%prime)%prime;

        if(forward_hash==backward_hash)
        {
            ans=i;
        }
     }
     string t;
     if(ans!=s.size()){
     t=s.substr(ans+1);
     }
     reverse(t.begin(),t.end());

     return t+s;

    }
};