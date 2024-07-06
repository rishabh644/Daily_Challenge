#include<iostream>
#include<vector>
#include<string>

using namespace std;


// Funtion to calculate the Z-array

vector<int> calculateZArray(const string& s){

    int n = s.length();

    vector<int> Z(n);

    int L = 0, R = 0, K;

    for (int i = 1; i < n;i++)
    {
        if(i>R){

            L = R = i;
            while(R<n && s[R]==s[R-L])
            {
                R++;
            }

            Z[i] = R - L;
            R--;
               }
        else {

            K = i - L;

            if(Z[K]<R-i+1){

                Z[i] = Z[K];
            }
            else{

                L = i;
                while(R<n && s[R]==s[R-L]){
                    R++;
                 }

                 Z[i] = R - L;
                 R--;
              }



             }

    }

    return Z;
}

void searchPattern(const string& text,const string& pattern){

    string concat = pattern + "$" + text;
    int l = concat.length();

    // Calculate Z-array for the concatenated string

    vector<int> Z = calculateZArray(concat);

    for (int i = 0; i < l;++i){

      if(Z[i]==pattern.length())
      {
          cout << "Pattern found at index " << i - pattern.length() - 1 << endl;
      }

      }
}

int main()
{
    string text = "GEEKS FOR GEEKS";
    string pattern = "GEEK";

    searchPattern(text, pattern);

    return 0;

}