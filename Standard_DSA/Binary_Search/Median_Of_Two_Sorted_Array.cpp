class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        if(nums1.size()==0)
        {
            if(nums2.size()%2==0)
            {
                return (nums2[nums2.size()/2]+nums2[nums2.size()/2-1])/2.0;
            }
            else
            {
                return nums2[nums2.size()/2];
            }
        }
        if(nums2.size()==0)
        {
            if(nums1.size()%2==0)
            {
                return (nums1[nums1.size()/2]+nums1[nums1.size()/2-1])/2.0;
            }
            else
            {
                return nums1[nums1.size()/2];
            }
        }

        if(nums1.size()>nums2.size())
        {
            nums1.swap(nums2);
        }

        int x=nums1.size();
        int y=nums2.size();

        int low=0;
        int high=x;
        int maxleft;
        int partitionx;
        int partitiony;
        int maxleftx;
        int minrightx;
        int maxlefty;
        int minrighty;
        while(low<=high)
        {
               partitionx=(low+high)/2;
               partitiony=(x+y+1)/2 -partitionx;


            if(partitionx==0)
             maxleftx=INT_MIN;
            else
             maxleftx=nums1[partitionx-1];

             if(partitionx==x)
             minrightx=INT_MAX;
             else
             minrightx=nums1[partitionx];

             if(partitiony==0)
             maxlefty=INT_MIN;
             else
             maxlefty=nums2[partitiony-1];

             if(partitiony==y)
             minrighty=INT_MAX;
             else
             minrighty=nums2[partitiony];

             if(maxleftx<=minrighty && maxlefty<=minrightx)
             {

             if((x+y)%2==0)
             {
                 return (max(maxleftx,maxlefty)+min(minrightx,minrighty))/2.0;
             }
             else
             {
                     return max(maxleftx,maxlefty);
             }

             }
             else if(maxleftx<minrighty)
             {
                 low=partitionx+1;
             }
             else
             {
                 high=partitionx-1;
             }


        }



           return -1;




    }
};
//////////////////////////////////
// Median of two sorted array in O(m+n)
