#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int rectanglesInCircle(int r) {
        // code here



         int i,j;
         int count=0;

         int maxd=2*r*2*r;


         // Need to find i and j with i>=1 and j>=1 such that i^2+j^2 <=maxd

         for(int i=1;i<2*r;i++)
         {
             for(int j=1;j<2*r;j++)
             {
                 if( (i*i +j*j)<=maxd )
                 {
                     count+=1;
                 }
             }
         }


         return count;





}