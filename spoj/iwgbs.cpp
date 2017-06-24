#include<bits/stdc++.h>
using namespace std;

int main()
{
int n; cin >> n;
unsigned long long int a[n];
a[0]=2; a[1]=3;
for( int i=2;i<n;i++)
	a[i] = a[i-1] + a[i-2];
cout << a[n-1];





	return 0;
}

