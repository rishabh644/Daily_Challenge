
# n is the number of matrix
def print_expression(tp,myls,i,j):
    if i==j:
        return myls[i]
    #return '( '+ print_expression(tp,myls,i,tp[i][j])+' )'+'( '+print_expression(tp,myls,tp[i][j]+1,j)+' )'
    st=str()
    k=tp[i][j]

    if(k!=i):
        st+=' ( '
        st+=print_expression(tp,myls,i,k)
        st+=' ) '
    else:
        st+=print_expression(tp,myls,i,k)
    k=k+1
    if(k!=j):
        st+=' ( '
        st+=print_expression(tp,myls,k,j)
        st+=' ) '
    else:
        st+=print_expression(tp,myls,k,j)

    return st






def matirx_chain_multiplication(arr,n):
    dp=[[0 for _ in range(n+1)] for _ in range(n+1)]
    tp=[[0 for _ in range(n+1)] for _ in range(n+1)]

    myls=[ '0','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z']
    # n is the number of matrices
    # l is the chain length
    # for l length we need l-1 to i
    for l in range(2,n+1): #l=2 to n
        for i in range(1,n-l+2): #i=1 to n-l+1
            j=i+l-1
            dp[i][j]=float('inf')
            for k in range(i,j):
                c=dp[i][k]+dp[k+1][j]+arr[i-1]*arr[k]*arr[j]
                if(c<dp[i][j]):
                    dp[i][j]=c
                    tp[i][j]=k
    print('Minimum cost to multiply above chain of matrices is ',dp[1][n])

    print(print_expression(tp,myls,1,n))


def main():
    N=5
    arr=[40,20,30,10,30]
    matirx_chain_multiplication(arr,4)

main()