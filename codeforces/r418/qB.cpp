#include<bits/stdc++.h>
using namespace std;

int main()
{

	int n; cin >> n;
	int a[n],b[n],p[n],an[2],bn[2],abi=0,abx[2],arra[n],arrb[n];
	for( int i=0 ;i <n ;i++)
	{arra[i] = 0;arrb[i]=0;}
	for( int i=0; i<n;i++)
		cin >> a[i];
	for(int i=0; i< n;i++)
	{
		cin >> b[i];
		if( a[i] != b[i])
		{
			an[abi] = a[i];
			bn[abi] = b[i];
			abx[abi] = i;
			abi++;

		}
		arra[a[i]-1]++; arrb[b[i]-1]++;
	}
	int tmp=0;
	if( abi == 1 )
	{  
		while( arra[tmp] != 0)
		{
			 tmp++;
		}
		a[abx[0]] = tmp+1;
	}
	else
	{
tmp=0;

		while( arra[tmp] != 0   )
		{
			 tmp++;
		}
		tmp++;
		if(b[abx[0]] == tmp)
		{		a[abx[0]] = tmp; a[abx[1]] = a[abx[1]];}
		else
		{a[abx[1]]=tmp; a[abx[0]] = a [abx[0]];}

	}
for( int i=0;i<n;i++)
	cout << a[i] << ' ';
	return 0;
}
