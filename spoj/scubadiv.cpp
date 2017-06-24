#include<bits/stdc++.h>
using namespace std;
const long int INF=1000000;
int main()
{
	int t; cin >> t;
	for(;t>0;t--)
	{
		int ox,ni,n; cin >> ox >>ni >> n;
		int vo[n],vn[n],w[n];
		for( int i=0; i< n;i++)
			cin >> vo[i] >> vn[i] >> w[i];
		int mw[ox+1][ni+1][n+1];
		for(int i=0;i<ox+1;i++)
		{
			for(int j=0;j<ni+1;j++)
				mw[i][j][0] = INF;
		}
		for( int i=0;i<n+1;i++)
			mw[0][0][i]=0;

		for( int t=1;t<n+1;t++)
		{
			for( int i=0;i < ni+1;i++)
			{
				for( int j=0; j<ox+1; j++)
				{
					mw[j][i][t] = min(mw[j][i][t-1] , mw[max(j-vo[t-1],0)][max(i-vn[t-1],0)][t-1] + w[t-1] );
				}
			}
		}
	cout << mw[ox][ni][n]<< endl ;

	}
	return 0;
}
