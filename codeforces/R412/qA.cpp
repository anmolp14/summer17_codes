#include<bits/stdc++.h>
using namespace std;

int main()
{ 
int n,a,b,unrated=0;
cin >> n;
for(int i=0;i<n;i++)
{
cin >> a ;
if(a > b && i!=0 )
	unrated =1;
cin >> b ;
if(a!=b)
{
	cout << "rated" << endl;
	return 0;
}




}

if(unrated)
	cout << "unrated" << endl;
else
	cout << "maybe" << endl;


return 0;
}
