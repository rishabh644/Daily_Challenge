class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings)
    {
      // Sort the unique positions of all the edges
      set<int>edgeSet;

      for(auto building:buildings)
      {
         int left=building[0];
         int right=building[1];
         edgeSet.insert(left);
         edgeSet.insert(right);
      }

      vector<int>edges(edgeSet.begin(),edgeSet.end());

      // Use hash table 'edgeIndexMap' to record every {position:index} pairs in edges

      map<int,int>edgeIndexMap;

      for(int i=0;i<edges.size();++i)
      {
        edgeIndexMap[edges[i]]=i;
      }

      // Use 'heights' to record maximum height at each index

      vector<int>heights(edges.size());

      //Iterate over all the buildings
      for(auto building:buildings)
      {
         // Find the indexes of the left and right edges
         // and update the max_height within the range[left_idx,right_idx]

         int left=building[0],right=building[1],height=building[2];
         int leftIndex=edgeIndexMap[left];
         int rightIndex=edgeIndexMap[right];

         for(int idx=leftIndex;idx<rightIndex;++idx)
         {
            heights[idx]=max(heights[idx],height);
         }

      }

      vector<vector<int>>answer;

      //Iterate over 'heights'.

      for(int i=0;i<heights.size();++i)
      {
         // Add all the positions where the height changes to answer

         int currHeight=heights[i];
         int currPos=edges[i];

         if(i==0 || currHeight!=heights[i-1])
         {
            answer.push_back({currPos,currHeight});
         }

      }

      return answer;

    }
};
//////////////////////////////////////////////////////////////////////////////////-----------------------------------------------------------------////////////////////////////////////////////////////////
class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings)
    {
       // Collect and sort the unique positions of all the edges.
       set<int>edgeSet;

       for(auto building:buildings)
       {
           edgeSet.insert(building[0]);
           edgeSet.insert(building[1]);
       }

       vector<int>positions(edgeSet.begin(),edgeSet.end());

       vector<vector<int>>answer;

       //For each position, draw an imaginary vertical line.

       for(auto position:positions)
       {
          int maxHeight=0;
          // Check if any buildings intersect with the line at position.
          for(auto building:buildings)
          {
            int left=building[0],right=building[1],height=building[2];

            //Update 'maxHeight' if necessary
            if(position>=left and position<right)
            {
                maxHeight=max(maxHeight,height);
            }

          }

          // Add all the positions where the height changes to 'answer'

          if(answer.empty() || answer[answer.size()-1][1]!=maxHeight )
          {
            answer.push_back({position,maxHeight});
          }


       }

       return answer;
    }
};
////////////////////////////////////////////////////////////////////////////////////////------------------------------------------------------------------------------------////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings)
    {
      // Iterate over all buildings, for each building i,
      // add (position,i) to edges

      vector<vector<int>>edges;

      for(int i=0;i<buildings.size();++i)
      {
         edges.push_back({buildings[i][0],buildings[i][2]});
         edges.push_back({buildings[i][1],-buildings[i][2]});
      }

      // Sort edges by non-decreasing order
      sort(edges.begin(),edges.end());

      // Initialize two empty priority queues 'live' and 'past'
      // an empty list 'answer' to store the skyline key points.
      priority_queue<int>live;
      priority_queue<int>past;

      vector<vector<int>>answer;

      int idx=0;

      while(idx<edges.size())
      {


       // Since we might have multiple edges at same x,
       // Let the 'currX' be the current position

       int currX=edges[idx][0];

       // While we are handling the edges at 'currX'
       while(idx<edges.size() && edges[idx][0]==currX)
       {
         // The height of the current building
         int height=edges[idx][1];

         // If this is a left edge,add height to live
         // Otherwise add height to past

         if(height>0)
         {
            live.push(height);
         }
         else
         {
            past.push(-1*height);
         }

         idx+=1;
       }

       // If the tallest live building has been passed,
       // We remove it from 'live'.

       while(!past.empty() && live.top()==past.top())
       {
        live.pop();
        past.pop();
       }

       // Get the maximum height from 'live'

       int currHeight=live.empty()?0:live.top();

       // If the height changes at 'currX', we add this
       // skyline key point [currX,max_height] to 'answer'.

       if(answer.empty() || answer.back()[1]!=currHeight)
       answer.push_back({currX,currHeight});


      }


      // Return 'answer' as the skyline
      return answer;
    }
};