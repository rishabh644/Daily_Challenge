def fxn(n):
    k=3
    i=0
    j=n
    for m in range(i,j,k-1):
        print('( ',i,' , ',m,' )','( ',m+1,',',j,')')





def main():
    n=int(input())
    fxn(n)

main()