#include<bits/stdc++.h>
using namespace std;
vector < int > visited , dist;
void BFS( vector < vector <int> >* G , int s)
{
	queue <int> q;
	int temp;
	q.push(s);
	dist[s]=0; visited[s] = 1;
	while( !q.empty())
	{temp = q.front();
		q.pop();
		for(int i=0; i < (*G)[temp].size(); i++)
		{
			if( visited[(*G)[temp][i]] == 0)
			{
				visited[(*G)[temp][i]] = 1;
				dist[(*G)[temp][i]] = dist[temp] + 1;
				q.push( (*G)[temp][i] );
			}
		}
	}
}

int main()
{
	int n;cin >> n;
	vector < vector <int> > G(n);

	for( int j=0;j<n;j++)
	{
		visited.push_back(0);
		dist.push_back(n+1);
	}

	int m,e1,e2; cin >> m;

	for( int i=0;i<m;i++)
	{
		cin >> e1 >> e2;
		G[e1].push_back(e2);
		G[e2].push_back(e1);
	}

	int root; cin >> root;
	BFS( &G ,root);

	for( int l=0;l<n;l++)
		cout << "distance of " << l << ' ' << dist[l] << endl ;
	return 0;
}
