#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin >> t;
	for(int i=0;i<t;i++)
	{
		int n,m;
		cin >> n >> m;
		int sum=0, min , temp;
		for(int j=0;j<n;j++)
		{ 
			for(int k=0;k<m;k++  )
			{ 
				if(k==0)
					cin >> min;	  
				else{ cin >> temp;
					if( temp < min  )
						min = temp;
			         	}		
			}


				sum += min;

		}





cout << sum << endl;

	}




	return 0;
}

