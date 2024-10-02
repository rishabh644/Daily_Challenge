class Solution {
public:
    int majorityElement(vector<int>& nums)
    {

       int count=0;
       int candidate;

       for(int& num:nums)
       {
             if(count==0)
             {
                candidate=num;
             }
             count+=(num==candidate)?1:-1;
       }

       return candidate;

    }
};
/////////////////////////
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums)
    {
        int count1=0;
        int count2=0;

        int candidate1;
        int candidate2;


        for(int n:nums)
        {
            if(count1!=0 && candidate1==n)
            count1++;
            else if(count2!=0 && candidate2==n)
            count2++;
            else if(count1==0)
            {
                candidate1=n;
                count1++;
            }
            else if(count2==0)
            {
                candidate2=n;
                count2++;
            }
            else{
                count1--;
                count2--;
            }

        }

      int ckc1=0;
      int ckc2=0;

      for(int n:nums)
      {
        if(count1!=0 && n==candidate1)
        ckc1++;
        if(count2!=0 && n==candidate2)
        ckc2++;
      }

      int n=nums.size();

      vector<int>ans;

      if(ckc1>(n/3))
      ans.push_back(candidate1);
      if(ckc2>(n/3))
      ans.push_back(candidate2);

      return ans;
    }
};