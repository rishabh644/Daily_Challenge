#include<bits/stdc++.h>

using namespace std;

// Function to find the maximum element in each sliding
// window of size k

vector<int> maxSlidingWindow(vector<int>&arr,int k)
{
    vector<int> ans;
    priority_queue<pair<int, int>> heap;

   // Initialize the heap with the first k elements

    for (int i = 0; i < k;i++)
        heap.push({arr[i], i});

   // The maximum element in the first window
    ans.push_back(heap.top().first);

    for (int i = k; i < arr.size();i++)
    {  

        // Add the current element to the heap
        heap.push({arr[i], i});

       // Remove elements that are outside the current
       // window

       while(heap.top().second<=(i-k))
           heap.pop();

      // The maximum element in the current window
       ans.push_back(heap.top().first);
    }

    return ans;
}
