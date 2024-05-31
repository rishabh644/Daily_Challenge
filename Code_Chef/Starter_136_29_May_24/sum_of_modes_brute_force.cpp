#include <bits/stdc++.h>
using namespace std;

int number_of_modes(string& s,int n)
{
    int ans=0;
    int con=0;
    int cz=0;



    for(int i=0;i<n;i++)
    {   con=0;
        cz=0;
        for(int j=i;j<n;j++)
        {
            if(s[j]=='1')
            con++;
            else
            cz++;

            if(con==cz)
            ans+=2;
            else
            ans+=1;

            //cout << " i " << i << " j " << j << " con " << con << "  cz " << cz << "  ans " << ans << endl;
        }
    }

    return ans;

}

int main() {
	// your code goes here

	int t;
	int n;
	string s;
	cin>>t;

	while(t--)
	{
	    cin>>n;
	    cin>>s;

	    cout<<number_of_modes(s,n)<<endl;


	}

}
