#include<bits/stdc++.h>
using namespace std;
int main()
{
int n,d;
cin >> n >>d;
int a[n],b[n];
for(int i=0;i<n;i++)
	cin >> a[i];
for(int j=0;j<n;j++)
	b[(j-d + n  ) % n ] = a[j];

for(int i=0;i<n;i++)
cout << b[i] << ' ' ;

	return 0;
}