    int minAreaRect(vector<vector<int>>& points)
    {
        unordered_set<string>pointSet;
        for(const auto& point:points)
        {
            pointSet.insert(to_string(point[0])+","+to_string(point[1]));
        }

        int minArea=INT_MAX;

        for(int i=0;i<points.size();++i)
        {
            for(int j=i+1;j<points.size();++j)
            {

             // Consider points[i] and points[j] as potential diagonals

             auto& p1=points[i];
             auto& p2=points[j];

             // check if they can form a valid diagonal of a rectangle
             if(p1[0]!=p2[0] && p1[1]!=p2[1])
             {
                // check if the opposite corner exists
    string opposite1=to_string(p1[0])+","+to_string(p2[1]);
    string opposite2=to_string(p2[0])+","+to_string(p1[1]);

             if(pointSet.count(opposite1) && pointSet.count(opposite2))
             {
                int area=abs(p1[0]-p2[0])*abs(p1[1]-p2[1]);
                minArea=min(minArea,area);
             }


             }

            }
        }


        return minArea==INT_MAX?0:minArea;

    }