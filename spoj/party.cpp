#include<bits/stdc++.h>
using namespace std;

int main()
{
int W ,n; cin >> W >> n;
while( W || n )
{
int w[n+1],v[n+1],val[W+1][n+1],s[W+1][n+1];
for( int i=0;i<n;i++)
	cin >> w[i+1] >> v[i+1];
for( int i=0;i<W+1;i++)
{val[i][0]=0;s[i][0]=0;}
for( int i=0; i<n+1; i++)
{val[0][i]=0;s[0][i]=0;}
for( int i=1; i<=W ;i++)
{
for( int j=1; j<=n; j++)
   {
      val[i][j]=val[i][j-1];s[i][j]=s[i][j-1];
      if( i-w[j]>=0 && val[i-w[j]][j-1] + v[j] > val[i][j] )
      { val[i][j] = val[i-w[j]][j-1] + v[j]; s[i][j] = s[i-w[j]][j-1] + w[j];}
   }
}
cout << s[W][n] <<  ' '<< val[W][n] << endl;
cin >> W >> n;
}
return 0;
}
