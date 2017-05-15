#include<bits/stdc++.h>
using namespace std;
void duplicate( vector <bool> * s)
{ int n = (*s).size();
 for( int i=0; i< n; i++)
	(*s).push_back(!(*s)[i]);

}

int main()
{
vector < bool > s;
s.push_back(!true);
while( s.size() < 1000 )
{
duplicate(&s);
}

int q,q1; cin >> q;
for(int j=0;j<q;j++)
{cin >> q1;
if(s[q1])
	cout << 1;
else
	cout << 0;
cout << endl;
}





	return 0;
}
