class Solution {
public:
    double findMedianSortedArrays(vector<int>& A, vector<int>& B)
    {

        int na=int(A.size());
        int nb=int(B.size());
        int n=na+nb;
        if(n%2)
        {
            return solve(A,B,n/2,0,na-1,0,nb-1);
        }
        else
        {
            return (1.0*(solve(A,B,n/2-1,0,na-1,0,nb-1)+solve(A,B,n/2,0,na-1,0,nb-1)))/2;
        }

    }

    int solve(vector<int>&A,vector<int>&B,int k,int aStart,int aEnd,int bStart,int bEnd)
    {
         //If the segment of an array is empty, it means we have passed all
         // its element, just return the corresponding element in the other
         // array

         if(aEnd<aStart)
         {
            return B[k-aStart];
         }
         if(bEnd<bStart)
         {
            return A[k-bStart];
         }


          // Get the middle indexes and middle values of A and B.

          int aIndex=(aStart+aEnd)/2,bIndex=(bStart+bEnd)/2;
          int aValue=A[aIndex],bValue=B[bIndex];

          if(aIndex+bIndex<k)
          {
               if(aValue>bValue)
               {
                 return solve(A,B,k,aStart,aEnd,bIndex+1,bEnd);
               }
               else
               {
                return solve(A,B,k,aIndex+1,aEnd,bStart,bEnd);
               }
          }
          else
          {
            if(aValue>bValue)
            {
                return solve(A,B,k,aStart,aIndex-1,bStart,bEnd);
            }
            else
            {
                return solve(A,B,k,aStart,aEnd,bStart,bIndex-1);
            }

          }

          return -1;
    }

};
///////////////////
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
    {
        int X=nums1.size();
        int Y=nums2.size();

        if(X>Y)
        return findMedianSortedArrays(nums2,nums1);

        int l=0;
        int h=X;

        while(l<=h)
        {

           int px=(l+h)/2;

           int py=(X+Y+1)/2-px;

           int maxx=(px==0)?INT_MIN:nums1[px-1];
           int minx=(px==X)?INT_MAX:nums1[px];

           int maxy=(py==0)?INT_MIN:nums2[py-1];
           int miny=(py==Y)?INT_MAX:nums2[py];

           if(maxx<=miny && maxy<=minx)
           {
                if((X+Y)%2==0)
                {
                   return (max(maxx,maxy)+min(minx,miny))/2.0;
                }
                else
                {
                    return max(maxx,maxy);
                }

           }
           else if(maxx>miny)
           {
            h=px-1;
           }
           else
           {
            l=px+1;
           }

        }


        return -1;

    }
};