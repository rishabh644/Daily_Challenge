class Solution:
    def frequencySort(self, s: str) -> str:

        dr={}
        n=len(s)
        ls=[]

        for i in range(len(s)):
            dr[s[i]]=dr.get(s[i],0)+1

        for key in dr.keys():
            ls.append((key,dr[key]))

        print(ls)
        ls=sorted(ls,key=lambda x:x[1],reverse=True)
        print(ls)
        st=str()
        for i in range(len(ls)):
              for k in range(ls[i][1]):
                  st+=ls[i][0]
        return st


def main():
    s1='tree'
    s2='cccaaa'
    obj=Solution()
    print(obj.frequencySort(s1))
main()