
#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,a,b,p,c,m=0; cin >> n >> a >> b ;
	for( int i=0; i<n ;i++ )
	{
		cin >> p;
		if ( p == 1 )
		{
			if ( a > 0 )
				a--;
			else if ( b > 0 )
			{
				b--;
				m++;
			}
			else if ( m > 0 )
			{
				m--;
			}
			else
				c++;

		}
		else
		{
			if( b> 0 )
			{
				b--;
			}
			else
			{
				c++;
				c++;
			}

		}


	}
	cout << c << endl;







	return 0;
}
