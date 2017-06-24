#include<bits/stdc++.h>
using namespace std;

int main()
{
	string s; cin >> s;
	while( s[0] != '0' )
	{
		unsigned long long int n[s.length()+1];
		n[0]=1;
		for( unsigned long long int i=1; i<=s.length(); i++)
		{
			if(s[i-1] == '0')
			{
				if( i>=2 && (s[i-2] == '1' || s[i-2] == '2' ))
					n[i] = n[i-2];
				else
					n[i] = 0;
			}
			else
			{
				n[i]=n[i-1];
				if( i>=2 && (s[i-2] == '1' || (s[i-2] == '2' && s[i-1] - '0' <= 6 )))
					n[i] += n[i-2];
			}
		}
		printf( "%llu\n",  n[s.length()] );
		cin >> s;
	}
	return 0;
}
