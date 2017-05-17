#include <bits/stdc++.h>

using namespace std;
int n;
vector <int> visited,dist;
void BFS( int * r , int s, int t )
{int temp;
    queue <int> q; q.push(s); dist[s] = 0; visited[s] =1;
    while(  !q.empty() && visited[t]==0 )
    {
        temp = q.front(); q.pop();
        for(int i=temp-r[temp]; i <=temp+r[temp] ; i++)
        {  int tr = (i%n) + ((i%n<0) ? n:0);
            if(visited[tr]  == 0)
            {
                visited[tr] =1;
                dist[tr] = dist[temp] + 1;
                q.push(tr);
            }
        }
    }
}
int main() {

    int s,t,r_0,g,seed,p;
    cin >> n >> s >> t >> r_0 >> g >> seed >> p;
    int r[n];r[0] = r_0;
    for( int i=1;i<n;i++)
    { r[i] = (r[i-1] * g + seed) % p ;
        if(r[i] < 0) r[i] +=p;}
   visited.assign(n,0); dist.assign(n,-1);

    BFS(r, s,t);

    cout << dist[t];

    return 0;
}
