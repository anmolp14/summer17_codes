#include<bits/stdc++.h>
using namespace std;
int ** dist;
struct S
{
	int x;
	int y;
	S(int x1,int y1): x(x1),y(y1){}
};

bool operator < (const S& a, const S& b)
{ return dist[a.x][a.y] > dist[b.x][b.y];  }

int main()
{
	int m,n; cin >> m >> n;
		while ( m || n )
	{
	dist = (int **) malloc ( n * sizeof(int *));
	for( int r=0;r<n;r++)
		dist[r] = (int *) malloc (m* sizeof(int));
	for( int r=0;r<n;r++)
	{
		for( int e=0;e<m;e++)
			dist[r][e]=100000;
	}


		char a[n][m]; int s1,s2,d1,d2;string s;
		for( int i=0;i<n;i++)
		{ cin >> s;
			for( int j=0;j<m;j++)
			{
				if(s[j] == 'D') {d1=i;d2=j; a[i][j]=-3; }
				else if(s[j] == 'S') {s1=i;s2=j; a[i][j]=-2;  }
				else if(s[j] == 'X') {a[i][j] = -1;}
				else{ a[i][j] = s[j]-'0';  }
			}
		}
		priority_queue<S> q;
		dist[s1][s2]=0;
		int pushed[n][m] ;
		for(int as=0;as<n;as++)
		{
		for( int ti=0;ti<m;ti++)
			pushed[as][ti]=0;
		
		}
		q.push(S(s1,s2));
		pushed[s1][s2] = 1;
		struct S tmp = S(0,0);
		while(!q.empty())
		{
			tmp = q.top();q.pop();
			if(tmp.x+1 < n && a[tmp.x+1][tmp.y] >= 0 && dist[tmp.x+1][tmp.y] > dist[tmp.x][tmp.y] + a[tmp.x+1][tmp.y] )
			{
				dist[tmp.x+1][tmp.y] = dist[tmp.x][tmp.y] + a[tmp.x+1][tmp.y];
				if( pushed[tmp.x+1][tmp.y] == 0 )
				{
					q.push(S(tmp.x+1,tmp.y) );
					pushed[tmp.x+1][tmp.y] = 1;
				}
			}
			if(tmp.x-1 >= 0 && a[tmp.x-1][tmp.y] >= 0 && dist[tmp.x-1][tmp.y] > dist[tmp.x][tmp.y] + a[tmp.x-1][tmp.y] )
			{
				dist[tmp.x-1][tmp.y] = dist[tmp.x][tmp.y] + a[tmp.x-1][tmp.y];
				if( pushed[tmp.x-1][tmp.y] == 0 )
				{
					q.push(S(tmp.x-1,tmp.y) );
					pushed[tmp.x-1][tmp.y] = 1;
				}
			}
			if(tmp.y+1 < m && a[tmp.x][tmp.y+1] >= 0 && dist[tmp.x][tmp.y+1] > dist[tmp.x][tmp.y] + a[tmp.x][tmp.y+1] )
			{
				dist[tmp.x][tmp.y+1] = dist[tmp.x][tmp.y] + a[tmp.x][tmp.y+1];
				if( pushed[tmp.x][tmp.y+1] == 0 )
				{
					q.push(S(tmp.x,tmp.y+1) );
					pushed[tmp.x][tmp.y+1] = 1;
				}
			}
			if(tmp.y-1 >= 0 && a[tmp.x][tmp.y-1] >= 0 && dist[tmp.x][tmp.y-1] > dist[tmp.x][tmp.y] + a[tmp.x][tmp.y-1] )
			{
				dist[tmp.x][tmp.y-1] = dist[tmp.x][tmp.y] + a[tmp.x][tmp.y-1];
				if( pushed[tmp.x][tmp.y-1] == 0 )
				{
					q.push(S(tmp.x,tmp.y-1) );
					pushed[tmp.x][tmp.y-1] = 1;
				}
			}
		}
		if ( d1+1 < n && dist[d1][d2] > dist[d1+1][d2]  )
			dist[d1][d2] = dist[d1+1][d2];
		if( d1-1 >=0 && dist[d1][d2] > dist[d1-1][d2])
			dist[d1][d2] = dist[d1-1][d2];
		if ( d2+1 < m && dist[d1][d2] > dist[d1][d2+1])
			dist[d1][d2] = dist[d1][d2+1];
		if ( d2-1 >=0 && dist[d1][d2] > dist[d1][d2-1])
			dist[d1][d2] = dist[d1][d2-1];
		cout << dist[d1][d2] << endl;
/*		for( int i=0;i<n;i++)
		{
		for( int j=0;j<m;j++)
			cout << dist[i][j] << ' ';
		cout << endl;
		}*/
		free(dist);
		cin >> m >> n;
	}
	return 0;
}
