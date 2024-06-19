#include<vector>
#include<queue>

using namespace std;

int helpaterp(vector<vector<int>>&hospital) {

    int m = hospital.size();
    int n = hospital[0].size();

    // Define movement directions (up, down, left, right)

    vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    // Initialize visited and time_taken matrices

    vector<vector<int>> visited(m, vector<int>(n, 0));
    vector<vector<int>> time_taken(m, vector<int>(n, 0));

    // Initialize the queue for BFS

    queue<pair<int, int>> q;

    // Push all initially infected cells into the queue

    for (int i = 0; i < m;++i) {

        for (int j = 0; j < n;++j){

                if(hospital[i][j]==2){
                    visited[i][j] = 1;
                    q.push({i, j});
                                 }


                                  }

                                }

                                int max_time = 0;
    // Perform BFS

    while(!q.empty()) {

        auto curr = q.front();
        q.pop();

        int x = curr.first;
        int y = curr.second;

        for(auto dir:directions)
        {
            int new_x = x + dir.first;
            int new_y = y + dir.second;

            // Check if the new position is within bounds and unvisited
            if(new_x>=0 && new_x<m && new_y>=0 && new_y<n && hospital[new_x][new_y]==1 && !visited[new_x][new_y])
            {
                visited[new_x][new_y] = 1;
                time_taken[new_x][new_y] = time_taken[x][y] + 1;
                q.push({new_x, new_y});
                max_time = max(max_time, time_taken[new_x][new_y]);
            }



        }

                      }

        // Check if there are any cells that remain uninfected

                      for (int i = 0; i < m;++i)
                      {
                          for (int j = 0; j < n;++j)
                          {
                              if(hospital[i][j]==1 && time_taken[i][j]==0){
                                  return -1;
                             }

                          }
                      }

                      return max_time;
}
