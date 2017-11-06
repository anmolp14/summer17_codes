
#include<bits/stdc++.h>
#include<tr1/functional>
using namespace std;

int main()
{
int t; cin >> t;
for(;t>0;t--)
{

int n,m=0; cin >> n;
long int a;int flag=0;
for(int i=0;i<n;i++)
{
cin >> a;
if(abs(a)>1)
{
	m++;
	if(m>1)
	{cout << "no" << endl; break;}
}
if( a == -1)
	flag =1;
}
}
	return 0;
}
