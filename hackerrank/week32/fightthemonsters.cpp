#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;cin >> n;
	long int t, hit, health[n];
	cin >> hit >> t;
	for( int i=0;i<n;i++)
		cin >> health[i];
	sort(health, health+n);
	int coun = 0;
	while( t >= 0 &&  t >= ( health[coun]/hit + ((health[coun] % hit != 0) ? 1 : 0  )))
	{
		t = t - health[coun]/hit -( (health[coun] % hit != 0)  ? 1 : 0 )  ;
		coun++;
	}
	cout << coun;







	return 0;
}
