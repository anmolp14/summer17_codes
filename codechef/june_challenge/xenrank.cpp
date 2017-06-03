#include<bits/stdc++.h>
using namespace std;

int main()
{
int t; cin >> t;
for( ;t>0;t--)
{
unsigned long int u,v; cin >> u >> v;v=v+u;
unsigned long long int k =  v*(v+1)/2 + u + 1;
cout << k << endl;


}
	return 0;
}

