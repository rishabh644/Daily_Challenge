def counting_sort(ls):
    fq=[0]*61
    nls=[0]*len(ls)
    for v in ls:
        fq[v]+=1
    for k in range(59,0,-1):
        fq[k]=fq[k]+fq[k+1]
    for vl in ls:
        print(vl,' ',len(ls)-fq[vl])
        nls[len(ls)-fq[vl]]=vl
        fq[vl]-=1
    return nls

def main():
    t=int(input())
    while(t>0):
        n=int(input())

        ls=list(map(int,input().split()))

        nls=counting_sort(ls)

        print(nls)

        t-=1


main()
