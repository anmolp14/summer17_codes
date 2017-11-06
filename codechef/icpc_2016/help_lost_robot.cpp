
#include<bits/stdc++.h>
#include<tr1/functional>

using namespace std;

int main()
{

int n; cin >> n;
for( int i=0;i<n;i++)
{
int x1,y1,x2,y2;
cin >> x1 >> y1 >> x2 >> y2;
//int ans = abs(x1-x2) + abs(y1-y2);
if( x1 != x2 && y1 != y2 )
	cout << "sad";
else{
	if( x1 == x2)
	{
		if( y1 > y2 )
			cout << "down";
		else
			cout << "up";
	}
	else
	{
		if(x1 > x2)
			cout << "left";
		else
			cout << "right";
	}
}

cout << endl;


}
	return 0;
}
