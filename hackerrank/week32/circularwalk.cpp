#include <bits/stdc++.h>

using namespace std;
vector <long int> visited,dist;
void BFS( vector< vector<long int> >* G , long int s, long int t )
{long int temp;
    queue <long int> q; q.push(s); dist[s] = 0; visited[s] =1;
    while(  !q.empty() )
    {
        temp = q.front(); q.pop();
        for(long int i=0; i < (*G)[temp].size(); i++)
        {
            if(visited[(*G)[temp][i]] == 0)
            {
                visited[(*G)[temp][i]] =1; 
                dist[(*G)[temp][i]] = dist[temp] + 1;
                q.push((*G)[temp][i]);
            }
        }
    }
}
int main() {

    long int n,s,t,r_0,g,seed,p;
    cin >> n >> s >> t >> r_0 >> g >> seed >> p;
    long int r[n];r[0] = r_0;
    for( long int i=1;i<n;i++)
    { r[i] = ((r[i-1] * g)%p + seed%p) % p ;
        if(r[i] < 0) r[i] +=p;}
    vector <vector< long int> > G(n);

    for( long int i=0;i<n;i++)
    {
        if( r[i] * 2 + 1 > n)
        {
            for( long int y=0;y<n;y++)
                G[i].push_back(y);
            continue;
        }
        long int jl = (i-r[i]);
        long int jb = (i+r[i]);
        long int j;
        for( j=jl; j<=jb; j++)
        { if(j!=i)
            G[i].push_back( (j%n) + ((j%n<0) ? n:0) );}

    }

   for(long int i=0;i<n ;i++)
    { visited.push_back(0); dist.push_back(-1);}

    BFS(&G, s,t);

    cout << dist[t];

    return 0;
}
