class Solution:
    def myAtoi(self,s:str)->int:
        ans=0
        i=0
        n=len(s)
        sgn=1

        # Skip leading whitespaces
        while i<n and s[i]==' ':
            i+=1

        # Handle Sign

        if i<n and (s[i]=='-' or s[i]=='+'):
            if s[i]=='-':
                sgn=-1
            i+=1

        #Convert digits
        while i<n and s[i].isdigit():
            digit=ord(s[i])-ord('0')

            # Check for overflow

            if ans>(2**31-1-digit)//10:
                return 2**31-1 if sgn==1 else -2**31

            ans=ans*10+digit
            i+=1

        return sgn*ans

#Example Usage:

sol=Solution()
print(sol.myAtoi("42"))
print(sol.myAtoi("   -42"))
print(sol.myAtoi("4193 with words"))
print(sol.myAtoi("words and 987"))
print(sol.myAtoi("-91283472332"))