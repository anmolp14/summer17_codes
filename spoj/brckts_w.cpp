#include<bits/stdc++.h>
using namespace std;


void build( int *a, int v, int tl, int tr, pair<int,int> *t)
{
	if(tl == tr)
	{  if(a[tl] == 1 )
		{	t[v].first= 1;
			t[v].second= 0;
		}
		else
		{
			t[v].first= 0;
			t[v].second= 1;

		}
	}
	else
	{
		int tm = (tl+tr)/2;
		build(a,2*v,tl,tm,t);
		build(a,2*v+1,tm+1,tr,t);
		t[v].first =t[2*v+1].first;
		t[v].second=t[2*v].second;
		if( t[2*v].first > t[2*v+1].second)
			t[v].first+= t[2*v].first - t[2*v+1].second;
		else
			t[v].second+= -t[2*v].first + t[2*v+1].second;

	}
}

void update(int v, int tl, int tr, int index, pair<int,int> *t )
{
if( tl == tr )
{
 t[v].first = (t[v].first+1)%2;
t[v].second = (t[v].second+1)%2;

}
else{
int tm = (tl + tr)/2;
if(index > tm)
	update(2*v+1,tm+1,tr,index,t) ;
else
	update(2*v,tl,tm,index,t);

		t[v].first =t[2*v+1].first;
		t[v].second=t[2*v].second;
		if( t[2*v].first > t[2*v+1].second)
			t[v].first+= t[2*v].first - t[2*v+1].second;
		else
			t[v].second+= -t[2*v].first + t[2*v+1].second;
}




}


int main()
{
	for(int i=0;i<10;i++ )
	{
		int n; cin >> n;
		int a[n];char c;
		for(int j=0;j<n;j++)
		{ cin >> c;
			if(c==')')
				a[j]= -1;
			else
				a[j] = 1;
		}
		pair<int , int> t[4*n];// first : extra opening ------- second : extra closing
		build( a , 1 ,0 ,n-1,t);
	int q;
	cin >> q;
	int d;
	cout << "Test "<< i+1 <<":" << endl;
	for(int f=0;f<q;f++)
	{
		cin >> d;
		if(!d)
		 {  if( t[1].first==0 && t[1].second == 0 )
		 	cout << "YES"<< endl;
		    else
		 	cout << "NO" << endl;
		 }
		else
		{
		   update(1,0,n-1,d-1,t);
		}
	}
	}
	return 0;
}
