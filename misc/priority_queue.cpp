#include<bits/stdc++.h>
using namespace std;
struct triplet { 
int x;
int y;
int w;

triplet(int x1,int y1, int w1): x(x1), y(y1) ,w(w1){}

};
bool operator<( const triplet& a, const triplet& b )
{
return a.w > b.w;
}
int main()
{
priority_queue <triplet> q;

q.push(triplet(1,1,1));
q.push(triplet(2,3,2));
q.push(triplet(1,5,9));
q.push(triplet(1,4,5));
q.push(triplet(4,1,6));
q.push(triplet(1,0,5));
q.push(triplet(1,1,0));

cout << q.top().w << ' ';q.pop();
cout << q.top().w << ' ';q.pop();;
cout << q.top().w << ' ';q.pop();
cout << q.top().w << ' ';q.pop();
cout << q.top().w << ' ';q.pop();
cout << q.top().w << ' ';q.pop();
cout << q.top().w << ' ';q.pop();
if( triplet(1,1,4) < triplet (1,1,3)  )
	cout << " mordified" ;
	return 0;
}
