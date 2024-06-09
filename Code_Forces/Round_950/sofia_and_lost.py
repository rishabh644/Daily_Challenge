def main():
    t=int(input())
    while t>0:
        t-=1
        n=int(input())
        input_string=input()
        lsa=list(map(int,input_string.split()))
        input_string=input()
        lsb=list(map(int,input_string.split()))
        m=int(input())
        input_string=input()
        dm=list(map(int,input_string.split()))
        dir={}
        for key in dm:
            dir[key]=dir.get(key,0)+1
        i=0
        while(i<len(lsa)):
            if lsa[i]!=lsb[i]:
                if(dir.get(lsb[i]) is not None and dir[lsb[i]]>0):
                    dir[lsb[i]]-=1
                else:
                       #print(lsa[i]," ",lsb[i])
                       print("No")
                       break
            i+=1
        if(i==len(lsa)):
            print("YES")
main()
