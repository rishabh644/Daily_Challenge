class Solution:
    def shortestPalindrome(self, s: str) -> str:
        n=len(s)

        for i in range(n,-1,-1):
            if s[:i]==s[i-1::-1]:
                return s[i:][::-1]+s

/////////////-----------------------///////////////////
class Solution {
public:

    bool isPalindrome(string s,int n)
    {
        int i=0;
        int j=n-1;

        while(i<=j)
        {
            if(s[i]!=s[j])
            return false;

            i+=1;
            j-=1;
        }

        return true;
    }

    string shortestPalindrome(string s) {

        int n=s.size();
        string t;
        for(int i=n;i>=1;i--)
        {
            if(isPalindrome(s,i))
            {
                t=s.substr(i);

                reverse(t.begin(),t.end());

               return t+s;

            }
        }
        return t;
    }
};