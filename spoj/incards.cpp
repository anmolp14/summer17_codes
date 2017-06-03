#include<bits/stdc++.h>
using namespace std;
long int  Djtr(vector < vector < pair <long int , long int> > > g , long int n )
{       long int w1=0;
	vector <long int> dist(n+1 , 0 );
	vector <int> mark( n+1 , 0 ),pushed(n+1,0),p(n+1);
	priority_queue < pair <long int,long int> > q;// <-weight,vertex_no.>
	q.push(make_pair(0,1));   pair <long int,long int> temp; pushed[1]=1;dist[1]=0;p[1]=1;
	while(!q.empty())
	{
		temp = q.top(); q.pop();
		w1+=dist[temp.second];// cout << " weight added :  " << dist[temp.second] << " for : " << temp.second << endl;
//		cout << "temp " << temp.first<< ' '<< temp.second << endl;cout << " neigh of temp :: ";
		if( mark[temp.second]==0   )
		{
			mark[temp.second]=1;
			for(long int i=0;i<g[temp.second].size();i++ )
			{      // cout << g[temp.second][i].second << ' ' ;
				if( mark[g[temp.second][i].second] == 0   )
				{if( pushed[g[temp.second][i].second]==1   )
					{ //cout << " IF KE ANDAR AAYA " << endl << dist[temp.second]  + g[temp.second][i].first << endl << endl ;
						
						if  ( dist[temp.second]  + g[temp.second][i].first  >  dist[g[temp.second][i].second]     )
						{
							p[g[temp.second][i].second] = temp.second;
							dist[g[temp.second][i].second]= dist[temp.second] + g[temp.second][i].first;
	//						cout << " total weight for " << g[temp.second][i].second << " updated to " << dist[g[temp.second][i].second] << endl;
						}
					}
					else{
						q.push(g[temp.second][i]);
						pushed[g[temp.second][i].second]=1;
						p[g[temp.second][i].second] = temp.second;
						dist[g[temp.second][i].second]= dist[temp.second] + g[temp.second][i].first;
	//				cout << " pushed "<< g[temp.second][i].first << ' ' <<  g[temp.second][i].second << ' '  ;
					}
				}
			}
		}
	//	cout << endl;
	}

	return -w1;
}
int main()
{

	int t; cin >> t;
	for(; t > 0 ; t-- )
	{

		long int n,m,e1,e2,weight; cin >> n >> m;
		vector < vector < pair <long int , long int> > > g1(n+1) , g2(n+1);
		for( long int i=0;i<m;i++  )
		{cin >> e1 >> e2 >> weight;

			g1[e1].push_back(make_pair(-weight,e2));
			g2[e2].push_back(make_pair(-weight,e1));
		}
		for(long int o=1; o<n+1;o++)
		{ //cout << o << " : ";
			for( int g=0;g<g1[o].size();g++)
			{// cout << g1[o][g].second << ' ' ;
			}
		//	cout << endl;
		}
		cout << Djtr( g1,n) + Djtr( g2,n ) << endl;
	}
	return 0;
}
