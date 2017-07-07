#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n; cin >> n;
	vector < vector <int> > g(n) ;
	vector < vector <int> > gh(n) ;
	int m; cin >> m;
	int e1,e2;
	for( int i=0; i<m ; i++ )
	{
		cin >> e1 >> e2;e1--;e2--;
		g[e1].push_back(e2);
		gh[e2].push_back(e1);
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
	if( cyc )
	{ cout << "Sandro fails."; return 0;   }
	vector < int > bw ( n , 0 ) , f , dist(n) ;
	queue <int> q;
	for( int i=0 ; i<n; i++ )
	 {   if( gh[i].size() == 0 )
		 {
			 q.push(i);
			 f.push_back(i);
			 bw[i] = 1;
			 dist[i]=0;
		 }
	 }
	sort ( f.begin(),f.end() );
	while ( !q.empty())
	{
		int w = q.front();q.pop();
		for( int i=0; i< g[w].size() ; i++ )
		{
			int flag=0;
			for( int j=0; j< gh[g[w][i]].size(); j++)
				{
					if( bw[gh[g[w][i]][j]] == 0 )
						flag =1;
				}
			if( !flag && !bw[g[w][i]] )
			{
				q.push(g[w][i]);
				bw[g[w][i]] = 1;
				f.push_back( g[w][i] );
				dist[g[w][i]] = dist[w] + 1;
			}
		}
	}
vector < pair <int ,int > > fin;
for( int i=0; i<n; i++ )
{
fin.push_back( make_pair(dist[i] , i ));
}
sort(fin.begin(), fin.end() );
for( int i=0; i<n ;i++)
	cout << fin[i].second << ' ' ;

	return 0;
}
