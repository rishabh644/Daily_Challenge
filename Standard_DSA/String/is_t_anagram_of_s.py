class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s)!=len(t):
            return False
        ls=[0]*26
        for i in range(len(s)):
            ls[ord(s[i])-ord('a')]+=1
            ls[ord(t[i])-ord('a')]-=1
        for i in range(26):
            if(ls[i]!=0):
                return False
        return True
def main():
    obj=Solution()
    s="anagram"
    t="nagaram"
    print(obj.isAnagram(s,t))

main()