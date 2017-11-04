#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t; cin >> t;
	for( ; t>0 ; t-- )
	{
		char a;
		int sc=0;
		vector <char> s;
		cin >> a;
		int a1=0,a2;
		int coun = 0 ;
		while (    a != '\n'  )
		{ 
			coun++;

			if( a == ' ')
			{	sc++;
				if(!a1)
					a1 = coun;
				else
					a2 = coun; }
			s.push_back(a);
			scanf("%c", &a) ;
		}
		vector < char > f ;
		if( !sc)
		{
			f.push_back( ( s[0] >= 97 ) ? s[0] - 'a' + 'A'  : s[0] ) ;
			for( int i=1; i<coun; i++ )
			{
				f.push_back( ( s[i] < 97   ) ? s[i] - 'A' + 'a' : s[i] ) ;

			}
		}

		if( sc == 1 )
		{   f.push_back ( ( s[0] >= 97 ) ? s[0] - 'a' + 'A' : s[0] ) ; f.push_back('.') ; f.push_back( ' ' ) ;
			f.push_back(  ( s[a1] >= 97 ) ? s[a1] - 'a' + 'A'  : s[a1] ) ;
			for( int i=a1+1; i<coun; i++ )
			{
				f.push_back( ( s[i] < 97   ) ? s[i] - 'A' + 'a' : s[i] ) ;

			}



		}

		if ( sc == 2 )
		{
		f.push_back ( ( s[0] >= 97 ) ? s[0] - 'a' + 'A' : s[0] ) ; f.push_back('.') ; f.push_back( ' ' );
		f.push_back(  ( s[a1] >= 97 ) ? s[a1] - 'a' + 'A'  : s[a1] ) ;f.push_back('.') ; f.push_back( ' ' );
		f.push_back(  ( s[a2] >= 97 ) ? s[a2] - 'a' + 'A'  : s[a2] ) ;
	
		for( int i=a2+1; i<coun; i++ )
			{
				f.push_back( ( s[i] < 97   ) ? s[i] - 'A' + 'a' : s[i] ) ;

			}


		}
		
		for( int i=0; i<f.size();i++)
			cout << f[i] ;
		cout << endl;
		
	}


	return 0;
}
