#include<bits/stdc++.h>
using namespace std;

vector <int> cat ,visited;

int no_rest( vector < vector <int> > * tree , int m , int root)
{visited[root-1] =1;
if((*tree)[root-1].size() == 1 && m>=0 )
	return 1;
int new_m = (cat[root-1]==1)? m-1 : m ;
int no_res = 0;
for(int i=0;i< (*tree)[root-1].size();i++)
{ if(visited[(*tree)[root-1][i]] == 0)
	no_res += no_rest( tree, new_m, (*tree)[root-1][i] );
}
return no_res;
}

int main()
{
int n,m,c; cin >> n >> m;
vector < vector < int> > tree(n);
for(int i=0;i<n;i++)
{	cin >> c;cat.push_back(c); visited.push_back(0);}
int n1,n2;
for( int j=0;j<n-1;j++)
{ cin >> n1 >> n2;
tree[n2-1].push_back(n1-1);
tree[n1-1].push_back(n2-1);
}


cout << no_rest( &tree , m, 1);








	return 0;
}
