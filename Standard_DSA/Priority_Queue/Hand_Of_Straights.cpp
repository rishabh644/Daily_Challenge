#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {

        if(hand.size()%groupSize!=0)
        {
            return false;
        }


        map<int,int>c;

        for(int i:hand) c[i]++;

        for(auto it:c)
        {
               if(c[it.first]>0)
               {
                   cout << " it.first " << it.first <<" c[it.first] "<<c[it.first]<<endl;
                   for (int i = groupSize - 1; i >= 0; --i)
                   {
                       cout << " it.first+i " << it.first + i << " " << c[it.first + i] << endl;
                       cout << " c[it.first + i] -= c[it.first] " << (c[it.first + i] - c[it.first])<< endl;
                       if ( (c[it.first + i] - c[it.first])< 0){
                           return false;}
                       else{
                           c[it.first + i] = c[it.first + i] - c[it.first];}
                           cout << " it.first+i " << it.first + i << " " << c[it.first + i] << endl;
                    }

               }
        }

        return true;

    }
};

int main()
{
    Solution obj;

    vector<int> hand = {1, 2, 3, 6, 2, 3, 4, 7, 8};

    int groupsize = 3;

    cout<<obj.isNStraightHand(hand, groupsize)<<endl;

    return 0;
}