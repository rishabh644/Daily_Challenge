class Solution:
    def romanToInt(self, s: str) -> int:
        dr={}
        dr['I']=1
        dr['V']=5
        dr['X']=10
        dr['L']=50
        dr['C']=100
        dr['D']=500
        dr['M']=1000

        n=0

        i=0
        n=len(s)
        ans=0
        while i<(n-1):
            if dr[s[i]]>=dr[s[i+1]]:
                ans+=dr[s[i]]
            else:
                ans-=dr[s[i]]
            i+=1
        ans+=dr[s[i]]
        return ans

def main():
    obj=Solution()
    s="LVIII"
    print(obj.romanToInt(s))

main()