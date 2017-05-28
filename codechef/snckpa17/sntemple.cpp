#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t; cin >> t;
	for( int i=0;i<t;i++)
	{
		int n; cin >> n; long int h[n];long long int hsum=0;

		for( int j=0;j<n;j++)
		{	cin >> h[j];
			hsum+=h[j];

		}
		h[0]=1; h[n-1]=1;
		for( int f=0;f<n-1;f++ )
		{
			if(h[f+1] > h[f] +1 )
				h[f+1]= h[f]+1;


		}

		for( int f=n-1;f>0;f-- )
		{
			if(h[f-1] > h[f] +1 )
				h[f-1]= h[f]+1;


		}

		long int maxh = h[0] ;
		for( int g=0;g<n;g++)
		{
			if( h[g] > maxh )
				maxh = h[g];
		}

		cout << hsum - maxh * maxh << endl;

	}
	return 0;
}
