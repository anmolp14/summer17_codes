#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,k; cin >> n >> k;
	int a[n],b[k],zer,ch[n-k],j=0 ;
	for(int i=0; i<n; i++ )
	{cin >> a[i]; if(a[i]==0) zer=i;
		if(a[i]!=0)
		{
			 ch[j] = a[i]  ; j++; 
		}
	}

	for( int i=0; i<k ;i++)
		cin >> b[i];


	if ( k > 1 )
	{cout << "Yes"  ;return 0;}
	
	int flag =0;
	
	for( int i=0; i<n-k-1; i++)
	{  
		if(ch[i]>=ch[i+1])
			flag=1;
	}
	if( flag == 1  )
	{cout << "Yes";return 0;}
	else{
		if( zer > 0 && zer < n-1 )
		{ if( a[zer-1] < b[0] && a[zer+1] > b[0] )
			{cout << "No";return 0;}
			else
			{cout << "Yes";return 0;}
		}
		else{
			if( zer == 0 && a[1] > b[0]  )
			{cout << "No" ;return 0;}
			else if (zer == n-1 && a[n-2] < b[0] )
			{cout << "No";return 0;}
			else
				cout << "Yes";
		}

	}



	return 0;
}
