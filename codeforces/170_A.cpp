#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,m,t,a,c=0; cin >> n >> m;
	vector < vector <int> > g(m+n);
	for( int i=0;i<n;i++)
	{
		cin >> t;

		for( int j=0;j<t;j++)
		{     c++;
			cin >> a;
			g[i].push_back(n+a-1);
			g[n+a-1].push_back(i);
		}
	}

	int coun=0;
	int visited[n+m] = {0} ;
	for( int i=0;i<n;i++)
	{
		if( visited[i] == 0 )
		{
			coun++;
			stack<int> s;s.push(i);int temp;
			while( !s.empty())
			{temp = s.top();s.pop();
				if(visited[temp] == 0)
				{
					visited[temp] =1;
					for( int j=0;j<g[temp].size();j++)
					{ 
						if(visited[g[temp][j]] == 0)
							s.push(g[temp][j]);
					}


				}

			}
		}
	}

if(c != 0 ) coun--;
cout << coun;


	return 0;
}
