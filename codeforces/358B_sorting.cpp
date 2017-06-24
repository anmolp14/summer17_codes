#include<bits/stdc++.h>
using namespace std;

int main()
{
int n; cin >> n;
long int a[n];
for( int i=0; i< n ;i++)
	cin >> a[i];
sort( a , a+n);
long int xf = n-1,hr=n,hf=1;
for( int i= n-1; i>=0  ; i--)
{
if( a[i] < hr )
{ hr=a[i]-1; xf = i;
	hf=0;
}
else
	hr--;

}
if( hf )
	{ cout << n+1 ;return 0;  }
cout << n-xf+a[xf];
	return 0;
}
