#include<bits/stdc++.h>
using namespace std;

int chef( string s  )//returns 1 if valid
{ 
for(int i=0;i<s.length()-1;i++)
{
 if(s[i]=='E' && s[i+1] == 'C' ||  s[i] == 'S' && (s[i+1] == 'C' || s[i+1] == 'E')  )
     return 0;
 		 
}
return 1;

}


int main()
{
int t;
cin >> t;
for( int i=0;i<t;i++)
{
string s;
cin >> s;
if(chef(s))
	cout << "yes" << endl;  
else
	cout << "no" << endl;


}




return 0;
}
