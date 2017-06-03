#include<bits/stdc++.h>
using namespace std;

int n,m;
vector <int> visited;
void DFS(vector <vector <int> > g  )
{
	stack <int> s;s.push(1);
	int temp;
	while( !s.empty())
	{
		temp = s.top(); s.pop();
		visited[temp] = 1;
		for( int i=0;i<g[temp].size();i++)
		{
			if( visited[g[temp][i]]== 0)
			{ s.push(g[temp][i]);   }


		}

	}



}
int main()
{
	cin >> n >> m;
	if( m != n-1) { cout << "NO" ; return 0;}
	vector < vector<int> > g(n+1);

	int e1,e2;
	for( int i=0;i<m;i++)
	{visited.push_back(0);
		cin >> e1 >> e2;

		g[e1].push_back(e2);
		g[e2].push_back(e1);
	}
	visited.push_back(0);
	DFS(g);
	for( int j=0;j<n;j++)
	{ if(visited[j+1] == 0  ) {cout << "NO";return 0 ;  }   }
	cout << "YES";
	return 0;
}
