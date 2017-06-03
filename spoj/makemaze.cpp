#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t; cin >> t;
	for(;t>0;t--)
	{int coun=0;pair <int,int> s1,s2;
		int n,m,vertex_no=0,v1,v2; cin >> n >> m;
		char a[n][m];int  v[n][m]; vector < vector <int> > g;
		for( int i=0;i<n;i++)
		{ 
			for( int j=0;j<m;j++)
			{
				cin >> a[i][j];
				if(a[i][j] == '.')
				{
					g.push_back( vector <int>() );
					v[i][j] = vertex_no; vertex_no++;
					if( i-1 >= 0 && a[i-1][j] == '.'  )
					{
						g[vertex_no-1].push_back(v[i-1][j]);
						g[v[i-1][j]].push_back(vertex_no-1);
					}
					if (j-1 >=0 && a[i][j-1] == '.')
					{
						g[vertex_no-1].push_back(v[i][j-1]);
						g[v[i][j-1]].push_back(vertex_no-1);
					}
					if( i==0 || j==0 || j==m-1 || i==n-1 )
					{
						coun++;
						if(coun == 1  )
						{
							s1.first = i;s1.second=j;
							v1 = vertex_no-1;
						}
						if(coun == 2)
						{
							s2.first = i; s2.second = j;
							v2 = vertex_no-1;
						}
					}
				}
			}
		}
		if( coun != 2 )
		{cout << "invalid" << endl; 
			continue;  }
		//--------------------------------------------------------------------------------------------------------------
		//--------------------------------------------------------------------------------------------------------------
		vector <int> visited( g.size() , 0 ) ;
		queue <int> q;
		q.push(v1);visited[v1]=1;int temp;
		while( !q.empty())
		{
			temp = q.front();q.pop();
			for( int d=0;d<g[temp].size();d++)
			{
				if( visited[g[temp][d]] == 0 )
				{
					q.push(g[temp][d]);
					visited[g[temp][d]] = 1;
				}
			}
			//--------------------------------------------------------------------------------------------------------------
			//--------------------------------------------------------------------------------------------------------------
		}
		if( visited[v2] == 0)
			cout << "invalid"<<endl;
		else{ cout << "valid"<< endl ;  }
	}
	return 0;
}
