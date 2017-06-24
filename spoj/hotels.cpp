#include<bits/stdc++.h>
using namespace std;

int main()
{

	int n; long int m,maxs=0,temp=0;
	cin >> n >> m;
	int h[n];
	for( int i=0 ;i<n;i++)
		cin >> h[i];
	int a=0,b=0;
	while( b < n )
	{
		temp += h[b];
		while ( temp > m )
		{ temp-=h[a]; a++;    }
		if( temp > maxs )
			maxs = temp;
		b++;
	}
	cout << maxs;
	return 0;
}
