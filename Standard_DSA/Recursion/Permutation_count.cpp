#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int permutation(string& s,int i)
{
   if(i==s.size()-1)
   {
       return 1;
   }
   int count = 0;
   for (int j = i; j < s.size();j++)
   {
       swap(s[i], s[j]);
       count = count + permutation(s, i + 1);
       swap(s[i], s[j]);
   }

   return count;
}


int main()
{

    string pr = "RISHAB";

    int count = permutation(pr,0);

    cout << "No. of permutation of " << pr << " is " << count<<endl;

    return 0;
}