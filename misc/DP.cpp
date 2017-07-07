#include<bits/stdc++.h>
using namespace std;

int main ()
{
	int m,n,x; cin >> m >> n >> x;
	if( x == m*n)
	{
		cout << 0; return 0;
	}
	int a[m][n],r,c;
	for( int i=0 ; i<m;i++)
	{
		for( int j=0;j<n;j++) 
			a[i][j]=0;        
	}
	for( int i=0;i<x;i++)
	{
		cin >> r >> c; a[r][c]=1;
	}

/*	for( int i=0 ; i<m ; i++ )
	{
		for( int j=0;j<n ; j++)
			cout << a[i][j] << ' ';
		cout << endl;
	}
*/

	int sol[m][n],maxr=-1;
	pair < int , int > maxc ;
	for( int i=0; i< m; i++ )
	{
		for( int j=0; j<n ;j++ )
		{
			if( j==0  || i==0 )
				sol[i][j] = (a[i][j] == 0 ? 1 : 0)    ;
			else{ 
				if( a[i][j] == 1 )
					sol[i][j] = 0;
				else
					sol[i][j] = min(  min(sol[i][j-1] , sol[i-1][j]) , sol[i-1][j-1]  ) + 1 ;
			}
			if(  sol[i][j] > maxr )
			{  maxr = sol[i][j]; maxc = make_pair( i , j );      }

			//cout << sol[i][j] << ' ';
		}
		//cout << endl;
	}
	cout << maxc.first - maxr + 1 << ' ' << maxc.second - maxr + 1 << ' ' << maxc.first << ' ' << maxc.second ; 

	return 0;
}
