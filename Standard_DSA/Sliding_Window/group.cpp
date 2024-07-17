#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int numberOfAlternatingGroups(vector<int>& colors, int k) {

        int count=k-1;
        int i=0;
        while(count>0)
        {
            colors.push_back(colors[i]);
            count-=1;
            i+=1;
        }




        int n=colors.size();
        cout << "New n " << n << endl;
        int ans=0;
        vector<int>check(n,1);

        int j=1;

        while(j<n)
        {

            if(colors[j]!=colors[j-1])
            {
                check[j]=check[j-1]+1;
            }

            if(check[j]==k)
            ans+=1;

            cout << j << " " << check[j] << endl;

            j+=1;

        }

        return ans;

    }

int main(){

    vector<int> colors = {0, 1, 0, 1, 0 };

    int k = 3;

    cout<<numberOfAlternatingGroups(colors, k)<<endl;

    return 0;
}