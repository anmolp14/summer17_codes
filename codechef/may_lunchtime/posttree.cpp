#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n; cin >> n;
	int parent[n+1];
	parent[1] = 0;
	for( int i=2; i<n+1; i++)
		cin >> parent[i];
	long int a[n+1];
	long long int cost[n+1]={0};
	for( int j=1; j<n+1; j++)
		cin >> a[j];
	for( int f=1; f<=n; f++)
	{
		long int amin = a[f];
		int temp = f;
		while( temp != 0 )
		{
			if( amin > a[temp] )
				amin = a[temp];
			cost[f]+=amin;
			temp = parent[temp];
		}


	}
for( int h=1; h<n+1; h++)
	cout << cost[h] << ' ';


	return 0;
}
