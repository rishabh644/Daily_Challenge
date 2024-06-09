class Solution:
    def maxDepth(self, s: str) -> int:
        ans=0
        cnt=0

        for c in s:
            if c=='(':
                cnt+=1
                ans=max(ans,cnt)
            if c==')':
                cnt-=1

        return ans

def main():
    obj=Solution()
    st="(1+(2*3)+((8)/4))+1"
    print(obj.maxDepth(st))

main()
