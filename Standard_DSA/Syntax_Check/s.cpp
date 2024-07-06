#include<iostream>
#include<bits/stdc++.h>

using namespace std;


int main(){

    string st = "4/5, 5/60";
    int a, b, c, d;

    int i = 0,j;
    int n = st.size();

    while(i<n)
    {
      if(st[i]=='/')
      {
          a = stoi(st.substr(0, i));
          break;
      }
      i++;
    }
    i += 1;
    j = i;
    while(i<n)
    {
      if(st[i]==',')
      {
          b = stoi(st.substr(j,i-j));
          break;
      }
      i++;
    }

    i += 2;
    j = i;

     while(i<n)
    {
      if(st[i]=='/')
      {
          c = stoi(st.substr(j,i-j));
          break;
      }
      i++;
    }
    i += 1;
    j = i;

    d = stoi(st.substr(j, n - j));

    cout << a << " " << b << " " << c << " " << d << endl;
}