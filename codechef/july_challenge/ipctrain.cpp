#include<bits/stdc++.h>
using namespace std;

int main()
{
	 unsigned long long int t; cin >> t;
	for( ; t>0;t--)
	{
		 unsigned long long int n,d; cin >> n >> d;
		vector <  unsigned long long int > t(n),sad(n) ;
		vector < pair < unsigned long long int ,  unsigned long long int > > day(n) ;// day , no; sort by day ascending
		for( unsigned long long int i=0 ; i<n ;i++)
		{
			day[i].second = i;
			cin >> day[i].first >> t[i] >> sad[i] ;
			day[i].first--;
		}
		sort ( day.begin() , day.end() );
		priority_queue < pair < unsigned long long int ,  unsigned long long int > > q ;
		unsigned long long int z=0;
		for( unsigned long long int i=0; i<d ;i++ )
		{
			while ( day[z].first == i )
			{
				q.push( make_pair(sad[day[z].second],day[z].second ));
				z++;
			}
			while( !q.empty() && t[q.top().second] == 0 )
			{ q.pop();    }
			if( !q.empty() )
			{
				t[q.top().second]--;
			//	cout << "lecture on day " << i+1 << " is taken  by " << q.top().second+1 << endl;}
		//	else{ //cout << "no lecture held on day " << i+1 << endl;
			}
		}
		unsigned  long long  int sumi = 0;
		for( unsigned long long int i=0; i<n ; i++ )
		 sumi += sad[i] * t[i];  
		cout << sumi << endl;
	}
	return 0;
}
