#include<bits/stdc++.h>
using namespace std;

int main()
{
	int maxw,n; cin >> maxw >> n;
	int w[n],v[n];
	int m[maxw+1][n+1];
	for( int i=0; i<n;i++)
		cin >> w[i] >> v[i];
	for(int i=0; i<maxw+1;i++)
		m[i][0]=0;
	for( int i=0;i<n+1;i++)
		m[0][i]=0;
	for( int i=1;i<=maxw;i++)
	{
		for( int j=1; j<=n; j++)
		{
			m[i][j] = m[i][j-1];
			if( i-w[j-1] >= 0 && m[i-w[j-1]][j-1] + v[j-1] > m[i][j] )
				m[i][j] = m[i-w[j-1]][j-1] + v[j-1];
		}
	}
	cout << m[maxw][n];
	return 0;
}
