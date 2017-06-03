#include<bits/stdc++.h>
using namespace std;

int main()
{
	string s; cin >>s;int coun=0;
	for ( int i = s.length()-1 ; i >= 0 ; i-- )
	{
		if( s[i] == '1')
		{  
			coun++;
			for( int j=0; j <= i; j++)
			{
				if( s[j]=='1')
					s[j]='0';
				else {s[j]='1';}
			}
		}
	}
	cout << coun;
	return 0;
}
