#include<bits/stdc++.h>
using namespace std;
struct S
{
  int x;
  int y;
  int w;
  S(int x1,int y1,int w1 ) : x(x1),y(y1),w(w1)  {}
};

bool operator < ( const S& a, const S& b )
{ return a.w > b.w;    }

int main()
{
  int t; cin >> t;
  for( ;t>0;t--)
  {
    int m,n; cin >> m >> n;int a[n][m];
    for(int i=0;i<m;i++)
    {
      for(int j=0;j<n;j++)
	cin >> a[j][i];
    }
    int hx,hy;cin >> hy >> hx;hy--;hx--;
    int T; cin >> T;
    priority_queue <S> q;
    int dist[n][m];
    for(int z=0;z<n;z++)
    { for(int c=0;c<m;c++)
      dist[z][c] = 100001; }
    dist[0][0]=a[0][0];
    q.push(S(0,0,a[0][0]));
    struct S tmp = S(0,0,0 ) ;
    while(!q.empty())
    {
      tmp = q.top(); q.pop();
      if(tmp.w > dist[tmp.x][tmp.y] ) continue;

      if( tmp.x+1 < n && dist[tmp.x+1][tmp.y] > dist[tmp.x][tmp.y] + a[tmp.x+1][tmp.y] )
      {q.push(S( tmp.x+1 , tmp.y , dist[tmp.x][tmp.y] + a[tmp.x+1][tmp.y] ));
	dist[tmp.x+1][tmp.y] = dist[tmp.x][tmp.y] + a[tmp.x+1][tmp.y];
      }

      if( tmp.x-1 >= 0 && dist[tmp.x-1][tmp.y] > dist[tmp.x][tmp.y] + a[tmp.x-1][tmp.y] )
      {
	q.push(S( tmp.x-1 , tmp.y , dist[tmp.x][tmp.y] + a[tmp.x-1][tmp.y] ) );
	dist[tmp.x-1][tmp.y] = dist[tmp.x][tmp.y] + a[tmp.x-1][tmp.y];
      }
      if( tmp.y+1 < m && dist[tmp.x][tmp.y+1] > dist[tmp.x][tmp.y] + a[tmp.x][tmp.y+1] )
      {
	q.push(S( tmp.x , tmp.y+1 , dist[tmp.x][tmp.y] + a[tmp.x][tmp.y+1] ) );
	dist[tmp.x][tmp.y+1] = dist[tmp.x][tmp.y] + a[tmp.x][tmp.y+1];
      }
      if( tmp.y-1 >= 0 && dist[tmp.x][tmp.y-1] > dist[tmp.x][tmp.y] + a[tmp.x][tmp.y-1] )
      {
	q.push(S( tmp.x , tmp.y-1 , dist[tmp.x][tmp.y] + a[tmp.x][tmp.y-1] ) );
	dist[tmp.x][tmp.y-1] = dist[tmp.x][tmp.y] + a[tmp.x][tmp.y-1];
      }
    }
 /*   for( int i=0;i<n;i++)
    {
      for( int j=0;j<m;j++)
	cout << dist[i][j] << ' ';
      cout << endl;
    }*/

    if(dist[hx][hy] > T)
      cout << "NO" << endl;
    else{ cout << "YES" << endl << T-dist[hx][hy] << endl ;  }
  }
  return 0;
}
