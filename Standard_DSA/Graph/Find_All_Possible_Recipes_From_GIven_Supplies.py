class Solution:
    def findAllRecipes(self, recipes: List[str], ingredients: List[List[str]], supplies: List[str]) -> List[str]:
        graph=defaultdict(list)
        in_degree=defaultdict(int)

        for i,recipe in enumerate(recipes):
            in_degree[recipe]=len(ingredients[i])
            for ingredient in ingredients[i]:
                graph[ingredient].append(recipe)

        queue=deque(supplies)
        result=[]

        # Process the queue

        while queue:
            current=queue.popleft()
            # If current is a recipe, add it to the result list
            #print(current)
            if current in in_degree:
                result.append(current)

            for neighbor in graph[current]:
                in_degree[neighbor]-=1

                if in_degree[neighbor]==0:
                    queue.append(neighbor)
        return result

//////////////////////////////////////////
class Solution {
public:
    vector<string> findAllRecipes(vector<string>& r, vector<vector<string>>& is, vector<string>& ss)
     {

        unordered_map<string,vector<string>>adjl;
        unordered_map<string,int>indegree;

        int n=r.size();

        for(int i=0;i<n;i++)
        {
            indegree[r[i]]=is[i].size();

            for(auto in:is[i])
            {
                adjl[in].push_back(r[i]);
            }
        }

        queue<string>qu(ss.begin(),ss.end());
        vector<string>result;

        while(!qu.empty())
        {
            string ci=qu.front();
            qu.pop();
            for(auto adji:adjl[ci])
            {
                indegree[adji]-=1;

                if(indegree[adji]==0)
                {
                    result.push_back(adji);
                    qu.push(adji);
                }
            }


        }

        return result;

     }
};