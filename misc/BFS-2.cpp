#include<bits/stdc++.h>
using namespace std;


struct node
{
	int val;
	struct node * nex = NULL;
	struct node * pre = NULL;
};

struct adjlist 
{
	struct node * head = NULL ; 
};

struct graph
{
	int V;
	struct adjlist * vertices;
};

struct node * createnode(int val )
{ struct node * newnode = (struct node *) malloc ( sizeof(struct node ));
	(*newnode).val = val;
	return newnode;}

	vector < int > visited , dist;
void BFS( struct graph *G , int s)
{
	queue <int> q;
	q.push(s);
	visited[s] = 1; dist[s]=0;
	while( !q.empty() )
	{ int temp = q.front(); q.pop();
		struct node * neigh = (*G).vertices[temp].head;
		while ( neigh !=NULL)
		{
			if( visited[(*neigh).val] == 0 )
			{
				visited[(*neigh).val] =1;
				dist[(*neigh).val]= dist[temp]+1;
				q.push((*neigh).val);
			}
		neigh = (*neigh).nex;

		}


	}
}


int main()
{
	int n,m; cin >> n >> m;
	for ( int u=0; u<n; u++)
	{
		visited.push_back(0);
		dist.push_back(n+1);
	}
	struct graph G;
	G.V = n;
	int e1,e2;
	G.vertices = ( struct adjlist * ) malloc ( n * sizeof(struct adjlist ) );
	for( int i=0; i < m; i++)
	{ cin >> e1 >> e2;
		struct node *n1 = createnode(e2);
		struct node *n2 = createnode(e1);

		(*n1).nex = (G.vertices[e1]).head;
		(*n2).nex = (G.vertices[e2]).head;
	if((G.vertices[e1]).head != NULL )
		(G.vertices[e1]).head -> pre = n1;

		(G.vertices[e1]).head = n1 ;

	if((G.vertices[e2]).head != NULL )
		(G.vertices[e2]).head -> pre = n2;
		(G.vertices[e2]).head = n2 ;
	}
	int source; cin >> source;
	BFS( &G , source);
	cout << "node" << "  " << "distance" << endl;
	for( int j =0; j < n; j++ )
		cout << j << "      " << dist[j] << endl;
	return 0;
}
