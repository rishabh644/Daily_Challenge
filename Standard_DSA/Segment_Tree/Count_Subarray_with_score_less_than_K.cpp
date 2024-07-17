#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class SegmentTree{
  private:
  vector<int>tree;
  vector<int>nums;
  int n;
  public:
  SegmentTree(vector<int>&nums)
  {
    n=nums.size();
    tree.resize(4*n);
    this->nums=nums;

    build(0,0,n-1);

  }

  void build(int i,int start,int end)
  {
     if(start==end)
     {
        tree[i]=nums[start];
        return;
     }

     int mid=(start+end)/2;

     build(2*i+1,start,mid);
     build(2*i+2,mid+1,end);

     tree[i]=tree[2*i+1]+tree[2*i+2];

  }

  int getsum(int st,int se)
  {

    return ingetsum(0,0,n-1,st,se);

  }

  int ingetsum(int i,int ts,int te,int qs,int qe)
  {

       if(qs>te || qe<ts)
       return 0;

       if(qs<=ts && te<=qe)
       return tree[i];

       int mid=(ts+te)/2;

       return ingetsum(2*i+1,ts,mid,qs,qe)+ingetsum(2*i+2,mid+1,te,qs,qe);

  }

  long long get(int i,long long k)
  {
    int l=i;
    int r=n-1;

    if(nums[i]>=k)
    return 0;

    int rightmost=i;

    long long count=0;
    long long prod;

    while(l<=r)
    {
        int mid=(l+r)/2;

        long long sum=getsum(i,mid);

        int length=(mid-i+1);

        long long prod=sum*length;

        if(prod<k)
        {
            rightmost=mid;
            l=mid+1;
        }
        else
        {
            r=mid-1;
        }

    }

    count=rightmost-i+1;

    return count;

  }

};

class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {

           long long count=0;
           long long cc;
           SegmentTree obj(nums);

           for(int i=0;i<nums.size();i++)
           {
              cc=obj.get(i,k);
              cout << i << " " << cc<<endl;
              count += cc;
           }

        return count;

    }
};

int main(){

    vector<int> nums = {9, 5, 3, 8, 4, 7, 2, 7, 4, 5, 4, 9, 1, 4, 8, 10, 8, 10, 4, 7};
    int k = 4;

    Solution obj;

    cout << obj.countSubarrays(nums, k);
}

///////////////------------//////////
#define ll long long
class SegmentTree{
  private:
  vector<ll>tree;
  vector<int>nums;
  int n;
  public:
  SegmentTree(vector<int>&nums)
  {
    n=nums.size();
    tree.resize(4*n);
    this->nums=nums;

    build(0,0,n-1);

  }

  void build(int i,int start,int end)
  {
     if(start==end)
     {
        tree[i]=nums[start];
        return;
     }

     int mid=(start+end)/2;

     build(2*i+1,start,mid);
     build(2*i+2,mid+1,end);

     tree[i]=tree[2*i+1]+tree[2*i+2];

  }

  ll getsum(int st,int se)
  {

    return ingetsum(0,0,n-1,st,se);

  }

  ll ingetsum(int i,int ts,int te,int qs,int qe)
  {

       if(qs>te || qe<ts)
       return 0;

       if(qs<=ts && te<=qe)
       return tree[i];

       int mid=(ts+te)/2;

       return ingetsum(2*i+1,ts,mid,qs,qe)+ingetsum(2*i+2,mid+1,te,qs,qe);

  }

  ll get(int i,ll k)
  {
    int l=i;
    int r=n-1;

    if(nums[i]>=k)
    return 0;

    int rightmost=i;

    long long count=0;
    long long prod;

    while(l<=r)
    {
        int mid=(l+r)/2;

        long long sum=getsum(i,mid);

        int length=(mid-i+1);

        long long prod=sum*length;

        if(prod<k)
        {
            rightmost=mid;
            l=mid+1;
        }
        else
        {
            r=mid-1;
        }

    }

    count=rightmost-i+1;

    return count;

  }

};

class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {

           long long count=0;

           SegmentTree obj(nums);

           for(int i=0;i<nums.size();i++)
           {
              count+=obj.get(i,k);

           }

        return count;

    }
};