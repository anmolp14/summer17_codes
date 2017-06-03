
#include<bits/stdc++.h>
using namespace std;

vector <int> dfn,visited;
void DFS( vector < vector <int> > * g , int sr   )
{
	stack <int> s; s.push(sr) ;
	int temp,df=0;
	while ( !s.empty())
	{
		temp = s.top(); s.pop();
		if( visited[temp] == 0 )
		{
			dfn[temp] = df;df++;
			visited[temp] =1;
			for( int i=0;i< (*g)[temp].size();i++ )
			{
				if( visited[(*g)[temp][i]] == 0 )
					s.push((*g)[temp][i]);

			}
		}

	}




}


int main()
{
	int n,m; cin >> n >> m;
	for(int j=0;j<n;j++)
	{dfn.push_back(0);visited.push_back(0);}
	vector < vector <int> > g(n);
	int e1,e2;
	for( int i=0;i<m;i++)
	{
		cin >> e1 >> e2;
		g[e1].push_back(e2);
		g[e2].push_back(e1);
	}
	int s; cin >> s;

	DFS( &g,s );
	for(int i=0;i<n;i++)
		cout << dfn[i] << ' ';



	return 0;
}
