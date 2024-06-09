class Solution:
    def mylongestCommonPrefix(self,st1:str,st2:str):
        i=0
        while i<min(len(st1),len(st2)) and st1[i]==st2[i]:
            i+=1
        return st1[0:i]
    def longestCommonPrefix(self, strs: list[str]) -> str:
        lcp=strs[0]
        i=1
        sllen=len(strs)
        while(i<sllen):
            lcp=self.mylongestCommonPrefix(lcp,strs[i])
            i+=1
        return lcp

def main():
    obj=Solution()
    ls=input().split()
    print('Longest Common Prefix is ',obj.longestCommonPrefix(ls))

main()