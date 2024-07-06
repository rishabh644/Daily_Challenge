#include<iostream>
#include<bits/stdc++.h>

using namespace std;

vector<int> Compute_LPS(string& P)
{
    int m = P.size();
    vector<int> lps(m, 0);

    lps[0] = 0;

    int k = 0; // lps of prev char

    for (int q = 2; q <= m;q++)
    {
           while(k>0 && P[k]!=P[q-1])
           {
               k = lps[k - 1];
           }
           if(P[k]==P[q-1])
           {
               k = k + 1;
           }
           lps[q - 1] = k;
    }

    return lps;
}

void kmp_matcher(string T,string P)
{
    int n = T.size(); // text_length
    int m = P.size();

    vector<int> lps = Compute_LPS(P);

    int q = 0; // q denotes number of character matched

    for (int i = 1; i <= n;i++)
    {
             while(q > 0 && P[q] != T[i - 1])
             {

                 q = lps[q - 1];
             }

             if(P[q] == T[i - 1])
             {
                 q = q + 1;
             }

             if(q==m)
             {
                cout << "Pattern occurs with shift " << i - m << endl;
                q = lps[q - 1];
             }

    }
}


int main(){

    string T = "My name is Rishabh Rishabh Rishabh Rishabh Rishabh";
    cout << T.size() << endl;
    string P = "Rishabh";

    kmp_matcher(T, P);

    return 0;
}