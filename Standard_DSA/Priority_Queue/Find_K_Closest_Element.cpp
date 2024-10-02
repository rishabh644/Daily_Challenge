class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x)
    {

        priority_queue<pair<int,int>>pq;

        vector<int>ans;

        pair<int,int>pr;

        int diff,vl;

        for(int i=0;i<arr.size();i++)
        {
            diff=abs(arr[i]-x);
            vl=arr[i];
            pr={diff,vl};

            pq.push(pr);

            if(pq.size()>k)
            pq.pop();

        }

        while(!pq.empty())
        {
            pr=pq.top();
            pq.pop();
            vl=pr.second;
            ans.push_back(vl);
        }

       sort(ans.begin(),ans.end());

        return ans;

    }
};
Time Complexity is O(nlogk)

--------------------------------------------------------------
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x)
    {
          // Initialize binary search bounds

          int l=0;
          int h=arr.size()-1;

          int start=h;

          while(l<=h)
          {

             int mid=(l+h)/2;

             if(arr[mid]>=x)
             {
                start=mid;
                h=mid-1;
             }
             else
             {
                l=mid+1;
             }

          }

          if(start!=0)
          {
            if(abs(arr[start-1]-x)<=abs(arr[start]-x))
            start=start-1;
          }
          int left=start;
          int right=start+1;

          while(right-left-1<k)
          {
             if(left==-1)
             {right+=1;
               continue;
             }

             if(right==arr.size() || abs(arr[left]-x)<=abs(arr[right]-x))
             {
                left=left-1;
             }
             else
             {
                right=right+1;
             }

          }

          vector<int>ans;

          for(int i=left+1;i<right;i++)
          {
            ans.push_back(arr[i]);
          }

          return ans;
    }
};
O(log(n) +k)
//////////////////////////////////////////////////////////////////////////


class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x)
    {

         // Initialize binary search bounds
         int l=0;
         int h=arr.size()-k;


         while(l<h)
         {

            int mid=(l+h)/2;

            if(x-arr[mid]>arr[mid+k]-x)
            {
                l=mid+1;
            }
            else
            {
                h=mid;
            }

         }

          vector<int>ans;

          for(int i=l;i<l+k;i++)
          {
            ans.push_back(arr[i]);
          }

         return ans;

    }
};
log(n)+k