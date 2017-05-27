#include<bits/stdc++.h>
using namespace std;

int main()
{int t;cin >> t;
	for( int i=0;i<t;i++)
	{ int notpossible=0;
		long int n,k,x1,y1,x2,y2; int m; cin >> n >> k >> m;
		vector < pair <long int , long int>  > srow,scol;
		for( int j=0;j<m;j++)
		{
			cin >> x1 >> y1 >> x2 >> y2;
			if ( ( x1 >= (n-k)/2 && x1 <= (n+k)/2 -1  )   ||  ( x2 >= (n-k)/2 && x2 <= (n+k)/2 -1 )   )
				srow.push_back(make_pair(x1,x2));
			else if (  ( y1 >= (n-k)/2 && y1 <= (n+k)/2 -1  )   ||  ( y2 >= (n-k)/2 && y2 <= (n+k)/2 -1 )  )
				scol.push_back(make_pair(y1,y2));
		}
		sort( srow.begin(), srow.end() );
		sort( scol.begin(), scol.end() );
		int rcount=0,ccount=0;

		long int rmin_start_snake = (n-k)/2,rtrav=0,rmax_end_point=-1;
		while( rtrav< srow.size() && rmin_start_snake <= (n+k)/2 -1  )
		{
			while( rtrav< srow.size() && srow[rtrav].first <= rmin_start_snake )
			{
				if( srow[rtrav].second > rmax_end_point )
					rmax_end_point = srow[rtrav].second ;
				rtrav++;
			}
			rcount++;
			rmin_start_snake = rmax_end_point + 1;
			if(rmax_end_point == -1)
			{notpossible = 1;break;}
			while(  rtrav< srow.size() && srow[rtrav].second < rmin_start_snake )
				rtrav++;
			rmax_end_point = -1;
		}
		if( rmin_start_snake <= (n+k)/2 + 1 )
			notpossible = 1;


		long int cmin_start_snake = (n-k)/2,ctrav=0,cmax_end_point=-1;
		while( ctrav< scol.size() && cmin_start_snake <= (n+k)/2 -1  )
		{
			while(  ctrav< scol.size() && scol[ctrav].first <= cmin_start_snake )
			{
				if( scol[ctrav].second > cmax_end_point )
					cmax_end_point = scol[ctrav].second ;
				ctrav++;
			}
			ccount++;
			cmin_start_snake = cmax_end_point + 1;

			if(cmax_end_point == -1)
			{notpossible = 1;break;}
			while( ctrav< scol.size() && scol[ctrav].second < cmin_start_snake )
				ctrav++;
			cmax_end_point = -1;
		}

		if( cmin_start_snake <= (n+k)/2 + 1 )
			notpossible = 1;
		if( notpossible )
			cout << -1;
		else{cout << ccount+rcount ;  }
		cout << endl;
	}
	return 0;
}


