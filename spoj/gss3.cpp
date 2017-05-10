#include<bits/stdc++.h>
using namespace std;
void build ( int*a, int v , int tl, int tr ,long long int*t )
{     if(tl == tr)
	     t[v] = a[tl];
	else{
	int tm = (tl + tr) / 2;
	build(a,2*v,tl,tm,t);
	build(a,2*v+1,tm+1,tr,t);
	t[v] = t[v*2] + t[v*2+1];
	}

}

long long int prsum ( int v , int tl , int tr , int l , int r,long long int * t )
{ 
	if( l > r)
		return 0 ;
	if( tl == l && tr == r )
		return  t[v]  ; 
	else{
		int tm = (tl + tr)/2;
return  prsum(2*v ,tl,tm,l,min(tm,r ),t  ) + prsum(2*v + 1 ,tm+1,tr, max(tm+1,l ),r,t ) ;
	}


}
void update ( int v , int tl ,int tr , int val , int inx, long long int *t)
{
if(tl == tr)
t[v] = val;
else{
int tm = (tl + tr) /2 ;
if(inx <= tm  )
	update( 2*v, tl , tm ,val ,inx ,t);
else
	update( 2*v+1, tm+1, tr , val ,inx , t);
t[v] = t[2*v] + t[v*2+1];


}




}
int main () 

{
	int n;
	cin >> n;
	int  a[n];
	for (int i=0;i<n;i++)
		cin >> a[i];
	int m;
	cin >> m;
	long long int t[4*n];
	build(a,1,0,n-1,t);
	for(int j=0;j<m;j++)
	{
	   int a; cin >> a;
	   if( a ) //print max
	   {    int l,r,sum; cin >> l >> r;
		  sum =  prsum( 1 , 0 , n-1 , l-1 , r-1,t );  cout << sum << endl;   }
	    else { int val,inx; cin >> inx >> val;
	    update(1,0,n-1,val,inx-1,t);
	    
	    
	    }//update
	
	
	}
	
	return 0;
}
