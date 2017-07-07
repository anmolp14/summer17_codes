#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n; cin >> n;
	float p[n+1],q[n+1],p1,q1;
	for( int i=1; i<=n ; i++)
	{ cin >> p1; p[i]=p1;  }
	for( int i=0; i < n+1; i++)
	{ cin >> q1; q[i]=q1; }
	float a[n+1][n+1];
	for( int i=1; i<=n; i++)
	{
		for( int j=i; j<=n; j++)
		{
			a[i][j]=0;
			for( int k=i; k<=j; k++)
			{
				a[i][j] += p[k];
				a[i][j] += q[k-1];
			}
			a[i][j]+=q[j];
		cout << a[i][j] << ' ';
		}
		cout << endl;
	}
	int root[n+1][n+1]; float  w[n+1][n+1];
	for( int i=0 ; i <=n; i++ )
	{	w[i][0] = 0;  }
	for( int i =1 ; i<n+1 ; i++ )
	{
		for( int j=1; j<=n-i+1 ; j++)
		{
			if(i==1 )
			{
				root[j][i] = j;
				w[j][i] = ( q[j-1] + q[j] ) * 2.0 + p[j];
			}
			else
			{
				int r; float mi = -1.0;
				for(int k=j; k<j+i; k++)
				{
					if( mi == -1.0 ||  mi > w[j][k-j] + w[k+1][j+i-k-1] +  a[j][j+i-1])
					{
						mi =   w[j][k-j] + w[k+1][j+i-k-1] + a[j][j+i-1] ;
						r=k;
					}
				}
				root[j][i] = r;
				w[j][i] = mi;
			}
		}
	}
	cout << w[1][n] << endl << root[1][n] << endl;
	for( int i =1 ; i<n+1 ; i++ )
	{
		for( int j=1; j<=n-i+1 ; j++)
		{ cout << w[i][j] << ' ' << ' ' ;}
		cout << endl;
	}
	for( int i =1 ; i<n+1 ; i++ )
	{
		for( int j=1; j<=n-i+1 ; j++)
		{ cout << root[i][j] << ' ' << ' ' ;}
		cout << endl;
	}





	return 0;
}
