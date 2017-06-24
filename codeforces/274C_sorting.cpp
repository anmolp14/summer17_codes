#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;cin >> n;
	vector < pair < long int , long int > > a(n);
	for( int i=0 ; i< n ;i++ )
		cin >> a[i].first >> a[i].second ;
	sort ( a.begin() , a.end() );
	int ed = min (a[0].first , a[0].second );
	for( int i=1 ; i< n ; i++)
	{
	    if (ed <= a[i].second)
		    ed = a[i].second;
	    else
		    ed = a[i].first;
	
	}
	cout << ed;
return 0;
}
