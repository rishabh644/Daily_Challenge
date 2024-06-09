vector<int> Solution::solve(vector<int> &A, vector<int> &B, int C) {

    sort(A.begin(),A.end(),greater<int>());
    sort(B.begin(),B.end(),greater<int>());


    vector<int>ans;

    int n=A.size();

    priority_queue< pair< int,pair<int,int> > >pq;

    pq.push({A[0]+B[0],{0,0}});

    set<pair<int,int>>ust;

    pair< int,pair<int,int> >pr;

    ust.insert({0,0});

    int sum=0;
    int i,j;



    while(!pq.empty())
    {
        pr=pq.top();
        pq.pop();
        sum=pr.first;

        ans.push_back(sum);

        if(ans.size()==C)
        return ans;

        i=pr.second.first;
        j=pr.second.second;

        if((i+1)<n)
        {
            if(ust.find({i+1,j})==ust.end())
            pq.push({A[i+1]+B[j],{i+1,j}});
            ust.insert({i+1,j});
        }
        if((j+1)<n)
        {
            if(ust.find({i,j+1})==ust.end())
            pq.push({A[i]+B[j+1],{i,j+1}});
            ust.insert({i,j+1});
        }

    }



 return ans;

}