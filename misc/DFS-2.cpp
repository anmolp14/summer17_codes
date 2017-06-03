#include<bits/stdc++.h>
using namespace std;
struct node { 
	int val;
	struct node * nex=NULL;
	struct node * pre=NULL;
};

struct adjlist{

	struct node * head=NULL;

};

struct graph {

	int V;
	struct adjlist * ver;

};

vector <int> visited , dfn;
void DFS( struct graph  g , int sr  )
{
	stack <int> s; s.push(sr);
	int temp, df=0;
	while (!s.empty() )
	{ cout << "aaya " << endl;
		temp = s.top();s.pop();
		if( visited[temp] == 0  )
		{   cout << "if main aaya" << endl;
			visited[temp] =1; dfn[temp]=df;df++;
			struct node * tmp = g.ver[temp].head   ;
			while( tmp != NULL )
			{       cout << "second while main aaya" << endl;
				cout << "tmp -> val " << tmp -> val <<endl  ;
				if(visited[tmp -> val ] == 0)
				{s.push(tmp -> val);cout << "stack main push" << endl;}

				tmp = tmp -> nex;
			}



		}
	}
}

struct node * createnode(int val )
{ struct node * newnode = (struct node *) malloc ( sizeof(struct node ));
	(*newnode).val = val;
	return newnode;}





int main()
{
	int n,m; cin >> n >> m;
	int e1,e2;
	struct graph g; g.V = n;
	for ( int h=0;h<n;h++)
	{ visited.push_back(0 ); dfn.push_back(0);}
	g.ver = ( struct adjlist * ) malloc ( n *  sizeof( struct adjlist  ));
	for( int i=0;i<m;i++)
	{

		cin >> e1 >> e2;
		struct node * n1, * n2;

		n1 = createnode(e2);
		(*n1).nex = g.ver[e1].head;
		if( g.ver[e1].head != NULL )
			g.ver[e1].head -> pre = n1;
		g.ver[e1].head = n1;

		n2 = createnode(e1);
		(*n2).nex = g.ver[e2].head;
		if(  g.ver[e2].head != NULL )
			g.ver[e2].head -> pre = n2;
		g.ver[e2].head = n2;

	}
for( int f=0;f<n;f++)
{cout << f << "->"; 
struct node * tmp = g.ver[f].head;
while( tmp != NULL )
{
cout <<  tmp -> val << ' ';
tmp = tmp -> nex;
}
cout << endl;

}

	int s; cin >> s;
	DFS(g,s);
	for(int u=0;u<n;u++)
		cout << dfn[u] << ' ';
	return 0;
}
