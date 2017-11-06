
#include<bits/stdc++.h>
using namespace std;

int main()
{
int t; cin >> t;
for(;t>0;t--)
{
int n,a; cin >> n;
vector <int> c(101,0);
for( int i=0;i<n;i++)
{
cin >> a; c[a]++;
}
//for( int i=1; i<101;i++)
//cout << c[i] << ' ' ;
a = c[1];
int j=1;
while( a != 1  )
{
j++;
a = c[j];
}
cout << j << endl;


}
	return 0;
}
