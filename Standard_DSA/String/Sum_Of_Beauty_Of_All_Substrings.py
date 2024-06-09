class Solution:
    def beautySum(self, s: str) -> int:
        n=len(s)
        sum=0
        for i in range(n):
            st=str()
            for j in range(i,n):
                st+=s[j]
                sum+=self.beautysumsubstring(st)
        return sum
    def beautysumsubstring(self,st:str)->int:
        dr={}
        for i in range(len(st)):
            dr[st[i]]=dr.get(st[i],0)+1
        ls=list(dr.values())
        return max(ls)-min(ls)
