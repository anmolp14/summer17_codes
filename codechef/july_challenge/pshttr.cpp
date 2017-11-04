#include<bits/stdc++.h>
using namespace std;
// PREPROCESSING :store the paths for each pair
// QUERY :perform the required on the stored paths
int main()
{
	int t; cin >> t;
	for( ; t>0 ; t--)
	{
		int n; cin >> n;
		vector < vector <int> > g(n);
		vector < vector < long int> > w(n);
		int u,v;
		long int c;
		for( int i=0; i< n-1; i++)
		{
			cin >> u >> v >> c;u--;v--;
			g[u].push_back(v);
			g[v].push_back(u);
			w[u].push_back(c);
			w[v].push_back(c);
		}
		vector <int> parent (n) ; vector <int> visited(  n , 0 )  ;
		vector <int> level (n);
		vector < long int > weight(n);
		queue <int> q;
		q.push(0);
		parent[0] = 0;
		weight[0] = 0;
		level[0] = 0;
		visited[0] = 1;
		while( !q.empty())
		{
			int temp = q.front(); q.pop();
			for (int i=0; i< g[temp].size();i++)
			{
				if( visited[g[temp][i]] == 0 )
				{
					visited[g[temp][i]] = 1;
					level[g[temp][i]] = level[temp]+1;
					parent[g[temp][i]] = temp;
					weight[g[temp][i]] = w[temp][i];
					q.push(g[temp][i]);
				}
			}
		}
		//for (int i=0; i<n; i++ )
		//{ cout << "parent of " << i << " is " << parent[i] << " and weight is " << weight[i] << endl;   }
		//continue;
		int m; cin >> m;
		for( int i=0; i<m;i++ )
		{
			long int xo=0;
			cin >> u >> v >> c;v--;u--;
			int gr,sm , lgr , lsm ;
			lgr = max ( level[v] , level[u] );
			lsm = min ( level[v] , level[u] );
			gr = (level[v] == lgr ) ? v : u ;
			sm = ( gr == v ) ? u : v;
			for( int j=0; j< lgr - lsm  ; j++ )
			{
				if( weight[gr] <= c )
					xo = xo ^ weight[gr];
				gr = parent[gr];
			}
			while ( gr != sm )
			{
				if( weight[gr] <= c)
					xo = xo ^ weight[gr];
				if( weight[sm] <= c)
					xo = xo ^ weight[sm];
				gr = parent[gr];
				sm = parent[sm];
			}
			cout << xo << endl;
		}

	}
	return 0;
}
