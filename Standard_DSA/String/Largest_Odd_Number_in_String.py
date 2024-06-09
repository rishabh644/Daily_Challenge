class Solution:
    def largestOddNumber(self, num: str) -> str:
        j=len(num)-1

        while j>=0:
            dgt=int(num[j])
            if dgt%2==1:
                return num[0:(j+1)]
            j-=1
        return ""

def main():
    obj=Solution()
    print(obj.largestOddNumber("11537852"))
main()