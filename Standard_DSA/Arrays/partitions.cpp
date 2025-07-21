#include <bits/stdc++.h>
#include<iostream>
using namespace std;

bool check(vector<int>& vec, int x) {
    if (vec.size() == 1)
        return true;

    // Sort the vector to make it easier to check differences
    sort(vec.begin(), vec.end());

    for (int i = 1; i < vec.size(); i++) {
        if (abs(vec[i] - vec[i - 1]) < x)
            return false;
    }
    return true;
}

bool isValid(vector<int>& arr, int ind, int x, int k) {
    int n = arr.size();
    if (k == 1) {
        // Check if the remaining elements from index `ind` form a good subarray
        vector<int> vec(arr.begin() + ind, arr.end());
        return check(vec, x);
    } else {
        vector<int> vec;
        for (int i = ind; i <= n - k; i++) {
            vec.push_back(arr[i]);
            // Check if the current partition is valid
            if (check(vec, x)) {
                // Recursively check if the rest can be partitioned into (k-1) good subarrays
                if (isValid(arr, i + 1, x, k - 1))
                    return true;
            } else {
                // If the current partition is no longer valid, break
                break;
            }
        }
    }
    return false;
}

int goodPartition(vector<int>& arr, int k) {
    int mx = *max_element(arr.begin(), arr.end());
    int mn = *min_element(arr.begin(), arr.end());

    int lw = 0;
    int hg = mx - mn;
    int ans = -1;

    while (lw <= hg) {
        int mid = (lw + hg) / 2;

        if (isValid(arr, 0, mid, k)) {
            ans = mid;  // mid is a valid value of x
            lw = mid + 1;  // Try for a larger value of x
        } else {
            hg = mid - 1;  // Try for a smaller value of x
        }
    }

    return ans;
}

int main() {
    vector<int> arr = {4,8,2,6,10,8};
    int k = 2;
    cout << goodPartition(arr, k) << endl;  // Output: Maximum value of x
    return 0;
}
