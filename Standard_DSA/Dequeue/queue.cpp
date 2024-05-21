#include<iostream>
#include<bits/stdc++.h>

using namespace std;

// Maintain a Deque
// The deque stores indices of array elements.
// The elements in the dequeue ar kept in decreasing order based on thier values.
// The front of the deque always contains the index of the maximum element for the current window.

// Processing Each Element
// For each element in the array, We do the following:
// Remove indices from the back of the deque as the current element is greater than the elements
// at those indices.This ensures that the deuque contains
//indices off elements in decreasing order.
// Add the current elements index to the back of the deque.
//Remove the front element of the deque if it is out of the cuuent window's range.
// the element at the front of the deque is the maximum element for the current window

vector<int> maxSlidingWindow(vector<int>&arr,int k)
{
    vector<int> result;
    deque<int> dq;

    int i, j;
    int n = arr.size();

    for (i = 0; i <k;i++)
    {
       while(!dq.empty() && arr[dq.back()]<arr[i])
       {
           dq.pop_back();
       }
       dq.push_back(i);


    }

    result.push_back(arr[dq.front()]);

    for (i = k; i < n;i++)
    {

      while(!dq.empty() && arr[dq.back()]<arr[i])
       {

           dq.pop_back();
       }

       dq.push_back(i);

       while(!dq.empty() && dq.front()<=(i-k))
       {

           dq.pop_front();
       }

       result.push_back(arr[dq.front()]);
    }

    return result;
}



int main()
{



}
