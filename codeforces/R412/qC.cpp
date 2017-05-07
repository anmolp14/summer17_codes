#include<bits/stdc++.h>
using namespace std;

int main()
{
int t;
cin >> t;
for(int i=0;i<t;i++)
{
int x,y,p,q;
cin >> x >> y >> p >> q ;
if(p == q )
{  
   if(y == x)
	   cout << 0 << endl;
   else
	cout << -1 << endl;
continue;
}
if( x==p && x==0  )
{cout <<  0 << endl;
	continue;}
if ( p==0 && x!=0)
{
  cout << -1 << endl;
  continue;
}

int qf=q;
int pf=p;

while( x > pf || y > qf || ( pf-x > qf-y ) )
{
  pf+=p;
  qf+=q;
}

cout << qf-y << endl;
}




	return 0;
}
