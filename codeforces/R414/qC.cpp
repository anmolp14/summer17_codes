#include<bits/stdc++.h>
using namespace std;

int main()
{
	string s1,s2;int i=0,flag=0,pass=0;
	cin >> s1 >> s2;
	int n1=0, n2 = s1.length()-1;
	sort(s1.begin(), s1.end());
	sort(s2.begin(), s2.end());
	while(i < s1.length())
	{

		if(flag==0)
		{

			if ( s1[n1] < s2[n2] || pass == 2 )
			{cout << s1[n1];
				i++;
				n1++;
				if(pass == 2)
					pass=0;
			}


			else
			{pass++;
			}

			flag=1;
		}



		else{

			if(s2[n2] > s1[n1] || pass == 2 )
			{
				cout << s2[n2];
				i++;
				if(pass ==2)
					pass=0;
				n2--;
			}

			else{pass++;}
			flag=0;


		}


	}

	return 0;
}
