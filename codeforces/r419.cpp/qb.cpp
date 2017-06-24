#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,k,q;
	cin >> n >>k >>q;
	int l,h;
	vector < pair < int , int > > reco;
	for( int i=0; i < n ; i++)
	{ 
		cin >> l >> h;
		reco.push_back( make_pair( l , h ));
	}
	for( int i=0; i < q; i++)
	{
		int lw,hi,coun=0; cin >> lw >> hi;
		for( int j=lw; j<=hi;j++)
		{ int co=0;
			for( int p=0;p<n;p++)
			{
				if(j >= reco[p].first && j <= reco[p].second)
					co++;
			}
			if( co >= k)
				coun++;
		}
		cout << coun << endl;
	}
	return 0;
}
