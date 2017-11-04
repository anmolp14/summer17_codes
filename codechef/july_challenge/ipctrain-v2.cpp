#include<bits/stdc++.h>
using namespace std;

 int main()
{
	 int t; cin >> t;
	for( ; t>0;t--)
	{
		unsigned long int n,d; scanf( "%ld%ld",  &n , &d );
		vector <  unsigned long int > t(n),day(n) ;
		vector < pair < unsigned long int ,  unsigned long int > > sad(n) ;// sad , no; sort by sad decsending
		for( unsigned long int i=0 ; i<n ;i++)
		{
			sad[i].second = i;
			scanf("%ld%ld%ld" , &day[i] , &t[i] , &sad[i].first ) ;
			day[i]--;
		}
		sort ( sad.rbegin() , sad.rend() );
		unsigned long int runner;
		vector <unsigned long int > lec (d,0);
		unsigned long int cou=0;
		for ( unsigned long int i=0; i<n; i++ )
		{
		//	cout << "loop : " << i << endl;
			if( cou >= d )
				break;
			runner = day[sad[i].second];
		//	cout << "starting day to assign " << runner << endl;
			while (t[sad[i].second] > 0 && runner <= d-1 )
			{
				if( lec[runner] == 0 )
				{
					lec[runner] = 1;
		//			cout << "lec on day " << runner << " is taken by " << sad[i].second << endl;
					t[sad[i].second]--;
					cou++;
				}
		//		else
		//		cout << "lec on day " << runner << " NOT FREE" << endl;
				runner++;
			}
		}
		unsigned long  long  int sumi = 0;
		for( unsigned long int i=0; i<n ; i++ )
		{ sumi += sad[i].first * t[sad[i].second];  
	//	cout << sumi << endl;
		}
		printf("%llu\n" , sumi );
	}
	return 0;
}
