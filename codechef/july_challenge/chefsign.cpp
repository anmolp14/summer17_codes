#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t; cin >> t;
	for( ; t>0;t--)
	{
		string s; cin >> s;
		int cmin=0,cmax=0,ans=0,inc=-1;
		for( int i=0; i<s.length() ; i++ )
		{
			if( s[i] == '<' ) // inc = 1
			{
				if( inc == 1 )
					cmax++;
				else{ cmin =0; cmax = 1;  }
		inc =1 ;
			}
			if( s[i] == '>' ) // inc = 0
			{
				if( inc == 0 )
					cmin--;
				else{ cmax =0; cmin = -1; }
			inc =0;
			}
			ans = ( cmax - cmin + 1 ) > ans ? ( cmax - cmin +1 ) : ans;
		}
		cout << ans << endl;
	}
	return 0;
}
