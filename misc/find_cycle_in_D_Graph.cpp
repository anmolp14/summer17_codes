#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n; cin >> n;
	vector < vector <int> > g(n) ;
	int m; cin >> m;
	int e1,e2;
	for( int i=0; i<m ; i++ )
	{
		cin >> e1 >> e2;
		g[e1].push_back(e2);
	}
	vector < int > vis ( n , 0 );
	int cyc=0,i=0;
	while ( i < n  && !cyc )
	{
		if( vis[i] == 0 )
		{   cout << "DFS for " << i << endl;
			stack < int > s;
			s.push(i);
			vis[i] = 1;
			while ( !s.empty() && !cyc  )
			{
				int e = s.top(), flag=0;
				for( int j=0 ; j< g[e].size(); j++ )
				{
					if ( vis[g[e][j]] == 0 )
					{
						flag = 1;
						s.push(g[e][j]);
						vis[g[e][j]]=1;

					}
					else if ( vis[g[e][j]] == 1 )
					{
						cout << "cycle hain " << e << " se " << g[e][j] << endl;
						cyc = 1 ;
						break;
					}
				}
				if ( !flag )
				{ s.pop(); vis[e] = 2;  }
			}
			cout << "DFS for  " << i << " resulted in " << cyc << endl;
		}
		i++;
	}
	cout << cyc;
	return 0;
}
