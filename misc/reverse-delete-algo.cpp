#include <bits/stdc++.h>
using namespace std;

struct edges
{
	int w;
	int x;
	int y;
	int xy;
	int yx;
	edges ( int ws,int xs, int ys , int xys , int yxs )
	{ w=ws;x=xs;y=ys;xy=xys;yx=yxs;       }
};

bool SortByWeight ( const edges& a , const edges& b )
{ return a.w > b.w ;   }

int connected (vector < vector <int> >& g , int n  )
{
	vector < int > vis ( n , 0 );
	queue < int > q ;
	q.push(0);vis[0]=1;
	while ( !q.empty() )
	{
		int temp  = q.front();q.pop();
		for( int i=0; i< g[temp].size() ; i++ )
		{
			if ( vis[g[temp][i]] == 0 && g[temp][i] != -1 )
			{
				q.push(g[temp][i]);
				vis[g[temp][i]] =1 ;
			}
		}
	}
	for( int i=0 ; i< n ; i++ )
	{
		if(vis[i] == 0 )
			return 0;
	}
	return 1;
}
int main()
{
	int n; cin >> n;

	vector < vector < int > > g(n) ;
	vector < vector < int > > w(n) ;
	vector < struct edges > e ;
	vector < pair < int , int > > f;
	string s;
	int x,y,w1;
	while ( cin >> x )
	{
		cin >> y ;
		cin >> w1 ;
		x--;y--;
		g[x].push_back(y);
		g[y].push_back(x);
		w[x].push_back(w1);
		w[y].push_back(w1);
		e.push_back( edges(w1 ,x ,y ,g[x].size() -1 , g[y].size() -1 ));
	}
	sort( e.begin() , e.end() , SortByWeight );
	for( int i=0; i < e.size() ; i++ )
	{
		g[e[i].x][e[i].xy] = -1;
		g[e[i].y][e[i].yx] = -1;
		if (!connected( g , n  )  )
		{
			f.push_back( make_pair(min( e[i].x , e[i].y) ,  max( e[i].x , e[i].y)));
			g[e[i].x][e[i].xy] = e[i].y;
			g[e[i].y][e[i].yx] = e[i].x;
		}

	}
	sort( f.begin() , f.end() );
	for( int i=0 ; i<f.size() ; i++ )
		cout << f[i].first+1  << ' ' << f[i].second+1 << endl;
	return 0;
}
