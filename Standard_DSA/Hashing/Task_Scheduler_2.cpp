class Solution {
public:
    long long taskSchedulerII(vector<int>& tasks, int space)
    {
        long long  day=0;

        unordered_map<int,long long>last;

        for(int a:tasks)
        {
            if(last.count(a))
            {
                last[a]=day=max(day,last[a]+space)+1;
            }
            else
            {
                last[a]=++day;
            }

        }


        return day;


    }
};