def gcd(a,b):
    if(b>a):
        return gcd(b,a)
    if(a%b==0):
        return b
    return gcd(b,a%b)

def main():
    t=int(input())

    while(t>0):
        t-=1
        n=int(input())
        Is=input()
        ls=list(map(int,Is.split()))
        prev=1
        i=0
        count=0
        while(i<=(n-2)):
            cur=gcd(ls[i],ls[i+1])
            print(ls[i]," ",ls[i+1]," ",cur)
            if(prev>cur):
                count+=1
                if(count>1):
                  print("No")
                  break
                ls[i+1]=ls[i]
                continue
            prev=cur
            i+=1
        if(i==n-1):
            print("YES")

main()