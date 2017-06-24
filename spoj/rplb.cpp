#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t; cin >> t;
	for( int e=0 ; e<t ;e++)
	{
		int n,B;cin >> n >> B;
		int bry[n+1]; 
		for( int i=1; i<n+1; i++)
			cin >> bry[i];
		int mx[B+1][n+1];
		for( int i=0; i<B+1; i++)
			mx[i][0] = 0;
		for( int i=0;i<B+1;i++)
		{
			for(int j=1;j<n+1;j++)
			{
				mx[i][j] = mx[i][j-1];
				if( bry[j] <= i  && mx[i][j] < bry[j] + mx[i-bry[j]][max(j-2,0)] )
					mx[i][j] = bry[j] + mx[i-bry[j]][max(j-2,0)];
			}
		}
	/*for( int i=0;i<n+1;i++)
	{
		for( int  j=0 ; j<B+1; j++)
			cout << mx[i][j] << ' ';
		cout << endl;
	}*/
		cout<<"Scenario #" << e+1 <<  ": ";
cout  << mx[B][n] << endl ;

	}
	return 0;
}
