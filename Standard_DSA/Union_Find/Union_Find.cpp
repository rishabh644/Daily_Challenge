#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int find(int A[],int X)
{
       //add code here
       if(X==A[X])
       return X;

       int px=find(A,A[X]);

       A[X]=px; // path compression

       return px;
}
void unionSet(int A[],int Rank[],int x,int y)
{
	//add code here.

	int px=find(A,x);
	int py=find(A,y);

	if(Rank[px]<Rank[py])
    {
        A[px] = py;
    }
    else if(Rank[px]>Rank[py])
    {
        A[py] = px;
    }
    else
    {
        A[px] = py;
        Rank[py] += 1;
    }

}

bool check(int A[],int x,int y)
{
    int px = find(A, x);
    int py = find(A, y);

    if(px==py)
        return true;
    else
        return false;
}

int main()
{

    int n;
    cout << "Enter n" << endl;
    cin >> n;

    int A[n+1];
    int Rank[n + 1];

    int i;

    for (i = 1; i <= n;i++)
    {
        A[i] = i;
        Rank[i] = 0;
    }

    int x, y;

    int nf;
    cout << "Enter no of union" << endl;
    cin >> nf;

    i = 1;

    cout << "Enter x and y" << endl;

    while(i<=nf)
    {
        cin >> x >> y;

        unionSet(A,Rank,x, y);
        i += 1;
    }

    int ck;
    i = 1;
    cout << "Now check" << endl;
    cout << "Enter number of check " << endl;
    cin >> ck;
    cout << "Enter x and y" << endl;
    while(i<=ck)
    {
        cin >> x >> y;
        if(check(A,x,y))
            cout << "True" << endl;
        else
            cout << "False" << endl;

        i += 1;
    }

    return 0;
}