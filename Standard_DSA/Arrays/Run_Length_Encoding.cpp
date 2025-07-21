class Solution {
public:
    int compress(vector<char>& chars)
    {

       int i=0;
       int j=0;

       while(j<chars.size())
       {

          int groupLength=1;

          while(j+groupLength<chars.size() && chars[j+groupLength]==chars[j])
          {
            groupLength++;
          }

          chars[i++]=chars[j];

          if(groupLength>1)
          {
             for(char c:to_string(groupLength))
             {
                chars[i++]=c;
             }

          }

          j+=groupLength;

       }

       return i;
    }
};