#include<iostream>
#include<bits/stdc++.h>

using namespace std;


void min_heapify(vector<int>&arr,int i,int n)
{
    int smallest = i;

    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if(left<n && arr[left]<arr[smallest])
    {
        smallest = left;
    }

    if(right<n && arr[right]<arr[smallest])
    {
        smallest = right;
    }

    if(smallest!=i)
    {
        swap(arr[i], arr[smallest]);
        min_heapify(arr, smallest, n);
    }
}



void construct_min_heap(vector<int>&arr,int n)
{
    int start_index= (n / 2) - 1;
    int i;
    for (int i = start_index; i >= 0;i--)
    {
        min_heapify(arr, i, n);
    }
}


void decrease_key(vector<int>&arr,int ind,int key)
{

    int parent = (ind - 1) / 2;
    int t;

    if(key<arr[parent])
    {
        t = arr[parent];
        arr[parent] = key;
        arr[ind] = t;
        decrease_key(arr, parent, key);
    }
}

void insert_min_heap(vector<int>&arr,int value)
{
    arr.push_back(INT_MIN);
    decrease_key(arr, arr.size() - 1, value);
}

void print_min_heap(vector<int>&arr,int n)
{
    for (int i = 0; i < n;i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main()
{
    int len;
    int value;
    cout << "Enter length of vector " << endl;
    cin >> len;
    vector<int> arr(len, 0);

    cout << "Enter elements of vector" << endl;

    for (int i = 0; i < len;i++)
    {

        cin >> arr[i];
    }

    construct_min_heap(arr, len);

    cout << "See the min heap" << endl;

    print_min_heap(arr, len);

    cout << "Input the value to insert into min heap" << endl;
    cin >> value;

    insert_min_heap(arr, value);

    cout << "See the min heap" << endl;

    print_min_heap(arr, len);

    return 0;
}