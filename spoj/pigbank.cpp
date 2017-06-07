#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t; cin >> t;
	for( ; t>0;t--)
	{
		int pi,pf; cin >> pi >> pf;pf = pf - pi;
		int noc; cin >> noc;
		int v[noc+1 ],w[noc+1 ];
		for( int i=0; i <noc; i++)
			cin >> v[i+1] >> w[i+1];
		int val[pf+1];int flag;val[0]=0;
		for( int i=1;i <= pf;i++)
		{
			flag=0;
			for (int j=1;j<=noc;j++)
			{
				if(i-w[j] >= 0 && val[i-w[j]] >= 0)
				{
					if(flag == 0)
					{
						val[i] = val[i-w[j]] + v[j];
						flag = 1;
					}
					else
					{
						if(val[i-w[j]] + v[j] < val[i]  )
							val[i] = val[i-w[j]] + v[j];
					}
				}
			}
			if(flag == 0)
				val[i]=-1;
		//	cout <<  i << " : " << val[i] << endl;
		}
		//cout << endl;
if(val[pf] != -1)
cout << "The minimum amount of money in the piggy-bank is "<< val[pf] << '.'<< endl;
else{cout << "This is impossible." << endl;  }
	}
	return 0;
}
