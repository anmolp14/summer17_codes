#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t; cin >> t;
	for(;t>0;t--)
	{
		int n,m; cin >> n >> m;
		queue <pair <int,int> > q;
		int a[n][m],dist[n][m];
		string s;
		for( int i=0;i<n;i++)
		{ cin >> s;
			for( int j=0;j<m;j++)
			{
				if(s[j] == '1' )
				{q.push(make_pair(i,j)  );
					dist[i][j]=0;}
				else{ dist[i][j]=-1;   }
			}

		}
		pair < int,int > tmp;
		while ( !q.empty()  )
		{
			tmp = q.front();q.pop();
			if(   tmp.first-1 >= 0 && dist[tmp.first-1][tmp.second] == -1   )
			{
				dist[tmp.first-1][tmp.second] = dist[tmp.first][tmp.second] + 1 ; 
				q.push(make_pair(tmp.first-1,tmp.second)  );
			}
			if(tmp.first+1 < n && tmp.second < m && dist[tmp.first+1][tmp.second] == -1)
			{
				dist[tmp.first+1][tmp.second] = dist[tmp.first][tmp.second] + 1 ; 
				q.push(make_pair(tmp.first+1,tmp.second )  );
			}
			if(tmp.second+1 < m && dist[tmp.first][tmp.second+1] == -1)
			{
				dist[tmp.first][tmp.second+1] = dist[tmp.first][tmp.second] + 1 ; 
				q.push(make_pair(tmp.first,tmp.second+1 )  );
			}
			if(tmp.second-1 >= 0 && dist[tmp.first][tmp.second-1] == -1)
			{
				dist[tmp.first][tmp.second-1] = dist[tmp.first][tmp.second] + 1 ; 
				q.push(make_pair(tmp.first,tmp.second-1 )  );
			}
		}
for(int s=0;s<n;s++) 
{
for(int y=0;y<m;y++)
{
cout << dist[s][y] << ' ';

}
cout << endl;
}
	}
	return 0;
}
