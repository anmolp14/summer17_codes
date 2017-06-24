#include<bits/stdc++.h>
using namespace std;
int main()
{
int hour; cin >> hour;
char a; cin >> a;
int minu; cin >> minu;
int tmp;
tmp = hour %10;
tmp = tmp*10;
tmp += hour/10;
//cout << tmp << endl << minu << endl;
if( minu <= tmp && tmp < 60  )
{ cout << tmp - minu; return 0;   }
int tim = 60 - minu;
hour++ ; hour = hour % 24;
tmp = hour %10;
tmp = tmp*10;
tmp += hour/10;

while( tmp >= 60)
{
hour++;hour = hour % 24;
tmp = hour %10;
tmp = tmp*10;
tmp += hour/10;
tim +=60;
//cout << tmp  << endl;
}
cout << tim + tmp ;
return 0;
}
