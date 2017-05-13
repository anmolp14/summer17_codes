
#include<bits/stdc++.h>
using namespace std;

int main()
{
long int  o , s1 ,s2;
cin >> o >> s1 >> s2;
int n,flag,coun=0;long int a; cin >> n;
if ( o < s1 ) flag = 1;
else if ( o > s2 ) flag= 2;
else flag = 3;
for( int i=0 ; i< n ; i++)
{ cin>> a;
if( a < s1 && flag ==1)
	coun++;
if( a > s2 && flag==2)
	coun++;
if( a > s1 && a < s2 && flag ==3)
	coun++;
}
cout << coun;



	return 0;
}
