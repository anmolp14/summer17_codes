#include<bits/stdc++.h>
using namespace std;
int nozero( vector <  vector <int > > &g , int si ,int ei , int sj , int ej  )
{int c=0;
	for ( int i= si ; i <= ei ; i++ )
	{
		for ( int j=sj ; j<= ej ; j++ )
		{
			if ( g[i][j] == 0 )
				c++;

		}


	}
	return c;

}
int main()
{
	int n,m; cin >> n >> m;int minx=-1,maxx=-1,miny=-1,maxy=-1;char c;
	vector <vector <int> > g ( n , vector <int> (m) );
	for ( int i=0 ;i <n ; i++ )
	{
		for( int j=0; j<m ;j++ )
		{  
			cin >> c; g[i][j] = ( c == 'W' ) ? 0 : 1 ;
			if ( g[i][j] == 1 )
			{

				if ( minx == -1 || minx > i  )
					minx = i;
				if ( miny == -1 || j < miny  )
					miny = j;
				if ( maxx == -1 || maxx < i   )
					maxx = i;
				if ( maxy == -1 || maxy < j  )
					maxy = j;



			}



		}

	}

	if ( maxx == -1 )
	{  cout << 1 ; return 0;    }

	int lx = maxx - minx , ly = maxy - miny , lmax = max( lx , ly ) , lmin = min ( lx , ly ) , dif = lmax - lmin ;

	int	ans = nozero( g , minx , maxx , miny , maxy );
	if ( dif )
	{
		if ( lx  > ly )
		{     
			int flag=0;
			if ( maxy + dif < m || miny - dif >= 0 )
				flag =1;
			if( !flag )
			{  cout << -1 ; return 0;    }
			ans+= dif * (lx+1) ;
		}
		else
		{

			int flag=0;
			if ( maxx + dif < n || minx - dif >= 0 )
				flag =1;
			if( !flag )
			{  cout << -1 ; return 0;    }
			ans+= dif * ( ly + 1) ;
		}

	}
	cout << ans;



	return 0;
}
