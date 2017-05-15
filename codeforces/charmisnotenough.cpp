#include<bits/stdc++.h>
using namespace std;
int main()
{
int t; cin >> t;
for( int i=0;i<t;i++)
{
int n,m,c,waste=0; cin >> n >> m;
for( int j=0;j<n;j++)
{
cin >> c;
if( c < m)
	waste += m-c;



}
cout << waste;

}
	return 0;
}
