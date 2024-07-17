class Solution {
private:
    bool my_lexicalOrder(int i,int n,vector<int>&ans)
    {

        if(i<=n)
        ans.push_back(i);
        else
        return false;
        i=i*10;
        for(int j=0;j<=9;j++)
        {
            if(!my_lexicalOrder(i+j,n,ans))
            break;
        }

        return true;
    }

public:

    vector<int> lexicalOrder(int n) {

     vector<int>ans;

     for(int i=1;i<=9;i++)
     {
        if(!my_lexicalOrder(i,n,ans))
        break;
     }

     return ans;

    }
};