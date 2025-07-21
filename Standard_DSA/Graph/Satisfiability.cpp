class UnionFind
{
    private:
    vector<int>arr;
    vector<int>size;
    public:
    UnionFind()
    {      arr.resize(26);
           size.resize(26);
           for(int i=0;i<26;i++)
           {
            arr[i]=i;
            size[i]=1;
           }
    }
    int find(int nd)
    {
        int pr=arr[nd];

        if(pr==nd)
        {
            return pr;
        }

        return arr[nd]=find(pr);

    }

    void addtwo(char X,char Y)
    {   int x=X-'a';
        int y=Y-'a';
        int px=find(x);
        int py=find(y);

        if(px==py)
        return;

        if(size[px]<size[py])
        {
           arr[px]=py;
           size[py]+=size[px];
        }
        else
        {
           arr[py]=px;
           size[px]+=size[py];
        }
    }


};

class Solution {
public:
    bool equationsPossible(vector<string>& equations)
    {


       vector<string>neqls;
       UnionFind obj;

       for(auto eq:equations)
       {
          if(eq[1]=='=')
          {

            obj.addtwo(eq[0],eq[3]);
          }
          else
          {
            neqls.push_back(eq);
          }

       }

       for(auto eq:neqls)
       {

           char u=eq[0];
           char v=eq[3];

           if(obj.find(u-'a')==obj.find(v-'a'))
           return false;

       }

       return true;


    }
};
///////////////////////////////////////////////////////////////////////////////////-----------------------------------------------/////////////////////////////////////////////////////