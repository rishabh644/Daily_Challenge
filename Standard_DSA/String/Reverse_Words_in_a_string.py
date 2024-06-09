class Solution:
    def reverseWords(self, s: str) -> str:
        ls=[]
        i=0
        ts=str()
        while i<len(s):
            if(s[i]!=' '):
                ts+=s[i]
            elif(len(ts)!=0):
                ls.append(ts)
                ts=str()
            i+=1
        if(len(ts)!=0):
            ls.append(ts)
        ls.reverse()

        ans=' '.join(ls)
        return ans

obj=Solution()
s="the sky is blue"
print(obj.reverseWords(s))