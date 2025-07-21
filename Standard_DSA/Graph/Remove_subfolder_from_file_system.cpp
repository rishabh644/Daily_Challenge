class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder)
    {



        unordered_map<string,int>idc;

        for(string st:folder)
        {

            for(string st1:folder)
            {

               string temp="";

               for(int i=0;i<st1.size();i++)
               {

                   temp=temp+st1[i];

                   if(st==temp)
                   {

                       if( (i==st1.size()-1) || (st1[i+1]=='/') )
                       {

                        idc[st1]+=1;

                       }

                   }

               }

            }

        }

        vector<string>ans;

        for(string st:folder)
        {
           if(idc[st]==1)
           ans.push_back(st);
        }

        return ans;

    }
};
////////////////////////////////////////////////////////////////////////////////////-------------------------------------------------------------------//////////////////////////////////////////////////////////////
class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder)
    {

       // Sort the folders alphabetically
       sort(folder.begin(),folder.end());

       // Initialize the result vector and add the first folder

       vector<string>result;
       result.push_back(folder[0]);

       // Iterate through each folder and check if it's a subfolder  of the
       // last added folder in the result

       for(int i=1;i<folder.size();i++)
       {

           string lastFolder=result.back();
           lastFolder+='/';


           //Check if the current folder starts with last added folder
           // path

           if(folder[i].compare(0,lastFolder.size(),lastFolder)!=0)
           {
              result.push_back(folder[i]);
           }

       }

       // Return the result containing only non-sub-folders
       return result;
    }
};
/////////////////////
class Solution {
private:
  struct TrieNode
  {

    bool isEndOfFolder;
    unordered_map<string,TrieNode*>children;
    TrieNode():isEndOfFolder(false){}

  };

  TrieNode* root;

  //Recursively delete all TrieNodes to prevent memory leaks

  void deleteTrie(TrieNode* node)
  {
      if(node==nullptr)
      return;
      for(auto& pair:node->children)
      {
          deleteTrie(pair.second);
      }
      delete node;
  }

public:
    // Constructor initializes the root of the Trie
    Solution():root(new TrieNode()){}

    //Clean up memory
    // A destructor to recursively delete all TrieNodes and prevent memory
    // leaks
    ~Solution(){deleteTrie(root);}

    vector<string> removeSubfolders(vector<string>& folder)
    {

       // Build Trie from folder paths
       for(string& path:folder)
       {

           TrieNode* currentNode=root;
           istringstream iss(path);
           string folderName;

           while(getline(iss,folderName,'/'))
           {

              //skip empty folder names
              if(folderName.empty())
              continue;

              // Create new node if it doesn't exist
              if(currentNode->children.find(folderName)==currentNode->children.end())
              {
                  currentNode->children[folderName]=new TrieNode();
              }

              currentNode=currentNode->children[folderName];
           }
           // Mark the end of fodler path
           currentNode->isEndOfFolder=true;
       }
       // Check each path for subfolders
       vector<string>result;
       for(string& path:folder)
       {

          TrieNode* currentNode=root;
          istringstream iss(path);
          string folderName;
          bool isSubFolder=false;

          while(getline(iss,folderName,'/'))
          {

             // Skip empty folder names
             if(folderName.empty())
             continue;

             TrieNode* nextNode=currentNode->children[folderName];
             // Check if the current folder path is a subfolder of an
             // existing folder

             if(nextNode->isEndOfFolder && iss.rdbuf()->in_avail()!=0)
             {
                isSubFolder=true;
                break;
             }

             currentNode=nextNode;
          }
          if(!isSubFolder)
          result.push_back(path);
       }

       return result;
    }
};