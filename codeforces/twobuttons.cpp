#include<bits/stdc++.h>
using namespace std;
int n,m;
vector <int> visited , dist;
void BFS( vector < vector <int> > g , int sr  )
{
	queue < int > q; q.push(sr); visited[sr]=1;dist[sr]=0;
	int temp;
	while( visited[ m ] == 0 )
	{//cout << "while ke andar " ; 
		temp = q.front();q.pop();// cout << "temp " << temp << endl;
		for( int i=0; i< g[temp].size(); i++)
		{
			if(  visited[g[temp][i] ] == 0 )
			{
				visited[g[temp][i] ] =1;
				dist[g[temp][i] ] = dist[temp] + 1; //cout << "dist of temp " << dist[temp] << endl;
				q.push(g[temp][i]);//cout << "pushed " << g[temp][i] << endl ;
			}

		}


	}


}
int main()
{
	cin >> n >> m;
	for(int h=0; h<2*m+1; h++)
	{ visited.push_back(0); dist.push_back(0);     }
	vector < vector <int> > g(2* m+1);
	for( int i=1 ; i< 2 *m ;i++)
	{	g[i+1].push_back(i);
		if(  i <=  m )
			g[i].push_back(2 * i);
	}

if( m <= n )
{ cout << n-m;return 0;    }
	BFS( g , n);
	cout << dist[m];
	return 0;
}
