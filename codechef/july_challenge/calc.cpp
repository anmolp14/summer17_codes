#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t; cin >> t;
	for( ; t>0 ;t--)
	{
		long int n,b; cin >> n >> b;
		if( n <= b )
			cout << 0 << endl;
		else
		{
			long long int a1 = ceil (n / ( 2.0 * b )) , a2 = floor (n / ( 2.0 * b )) ;
			cout << max ( a1 * ( n - a1 * b ) ,a2 * ( n - a2 * b ) ) << endl; 
		}
	}
	return 0;
}
