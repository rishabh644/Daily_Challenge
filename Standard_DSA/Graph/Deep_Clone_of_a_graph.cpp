Node* dfs(Node* node,unordered_map<int,Node*>&ump)
{
    Node* nd;
    int vl=node->val;
    nd=new Node(vl);
    ump[vl]=nd;
    for(auto adjnd:node->neighbors)
    {
        int adjk=adjnd->val;
        if(ump.find(adjk)==ump.end())
        {
            nd->neighbors.push_back(dfs(adjnd,ump));
        }
        else
        {
            nd->neighbors.push_back(ump[adjk]);
        }
    }
    return nd;

}

class Solution
{
public:
    Node* cloneGraph(Node* node)
    {
          if(node==NULL)
          return node;

          Node* nd;

          int vl=node->val;

          nd=new Node(vl);

          unordered_map<int,Node*>ump;

          ump[vl]=nd;

          for(auto adjnd:node->neighbors)
          {
             int adjk=adjnd->val;
             if(ump.find(adjk)==ump.end())
             {
                nd->neighbors.push_back(dfs(adjnd,ump));
             }
             else
             {
                nd->neighbors.push_back(ump[adjk]);
             }
          }

          return nd;
    }

};


/////////////////////////////---------------------///////////////////////
class Solution
{
public:
    Node* cloneGraph(Node* node)
    {
         if(node==nullptr)
         return node;

         unordered_map<Node*,Node*>visited;

         queue<Node*>qu;

         qu.push(node);

         visited[node]=new Node(node->val,{});

         //Start BFS traversal

         while(!qu.empty())
         {
            Node* n=qu.front();
            qu.pop();

            for(Node* neighbor:n->neighbors)
            {
                 if(visited.find(neighbor)==visited.end())
                 {
                    visited[neighbor]=new Node(neighbor->val,{});
                    qu.push(neighbor);
                 }
                // Add the clone of the neighbor to the neighbors the clone
                visited[n]->neighbors.push_back(visited[neighbor]);

            }

         }


        // Return the clone of the node from visited

        return visited[node];


    }

};