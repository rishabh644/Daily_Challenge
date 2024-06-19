import sys

#Function to recursively calculate the minimum number of multiplications

def matrix_chain_order_recursive(arr,i,j):
    #If there's only one matrix, no multiplications are needed
    if i==j:
        return 0

#Initialize minimum count to a large value

    min_count=sys.maxsize

    for k in range(i,j):
        count=(matrix_chain_order_recursive(arr,i,k)+
           matrix_chain_order_recursive(arr,k+1,j)+
           arr[i-1]*arr[k]*arr[j])
        if count<min_count:
            min_count=count

    return min_count


arr=[1,2,3,4]
n=len(arr)

print('Minimum number of multiplications is',matrix_chain_order_recursive(arr,1,n-1))
