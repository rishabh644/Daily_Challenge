#include<iostream>
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

ll power(ll a,ll b,ll m)
{

    ll ans = 1;
    ll prod = a%m;

    while(b)
    {

      if(b&1)
      {
          ans = (ans * prod) % m;
      }

      prod = (prod *prod) % m;

      b >>= 1;
   }

   return ans;
}

vector<ll> Compute_rolling_hash(string text,ll window,ll base,ll prime)
{
    ll n = text.size();


    vector<ll> rolling_hash;

    rolling_hash.reserve(n - window + 1);

    ll h = power(base, window - 1, prime);

    ll current_hash = 0;  // or hash with zero shift according to clrs

    base = base % prime;

    for (ll i = 0; i <window;i++)
    {
        current_hash = ((base* current_hash)%prime + text[i]) % prime;
    }

    rolling_hash.push_back(current_hash);

    for (ll i = window; i < n;i++)
    {
        current_hash = ( current_hash + prime - ((text[i - window])%prime * h)%prime ) % prime;
        current_hash = ((current_hash * base)%prime  + text[i])%prime;
        rolling_hash.push_back(current_hash);
    }

    return rolling_hash;
}


void rabin_karp_match(string& text,string& patt,int base,int prime)
{
    ll m = patt.size();
    vector<ll> rolling_hash = Compute_rolling_hash(text, m, base, prime);

    ll hash_of_patt = 0;
    ll i, k;
    base = base % prime;
    for ( i = 0; i < patt.size();i++)
    {
        hash_of_patt = ((base * hash_of_patt)%prime + patt[i]) % prime;
        //cout << hash_of_patt << endl;
    }
    //cout << hash_of_patt << endl;
    for(int i = 0; i < rolling_hash.size();i++)
    {
        //cout << i << " " << rolling_hash[i] << endl;
        if (rolling_hash[i] == hash_of_patt)
        {
            bool match = true;

            for (int j = 0; j < m; j++)
            {
                if (text[i + j] != patt[j])
                {
                    match = false;
                    break;
                }
            }
            if (match)
                cout << patt << " occurs with shift " << i << endl;
           }
    }
}


int main(){

    string text = "My name is Rishabh Rishabh Rishabh Rishabh Rishabh";
    string patt = "Rishabh";

    int base = 256;
    int prime =1000000007 ;

    rabin_karp_match(text, patt, base, prime);
}