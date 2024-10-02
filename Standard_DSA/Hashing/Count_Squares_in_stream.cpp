class DetectSquares {

private:
  unordered_map<string,int>ump;
  vector<vector<int>>points;
public:
    DetectSquares() {

    }

    void add(vector<int> point) {
        string pt=to_string(point[0])+","+to_string(point[1]);
        ump[pt]+=1;
        points.push_back({point[0],point[1]});
    }

    int count(vector<int> point) {
        int p1x=point[0];
        int p1y=point[1];
        int ans=0;
        for(int i=0;i<points.size();i++)
        {
           int p2x=points[i][0];
           int p2y=points[i][1];
           if(p1x!=p2x && p1y!=p2y)
           {
              string p3=to_string(p1x)+","+to_string(p2y);
              string p4=to_string(p2x)+","+to_string(p1y);
              if( (ump[p3]!=0 && ump[p4]!=0) && abs(p2x-p1x)==abs(p1y-p2y) )
              {
                ans=ans+ump[p3]*ump[p4];
              }
           }
        }
        return ans;
    }
};
///////////
