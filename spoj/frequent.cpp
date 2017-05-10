#include<bits/stdc++.h>
using namespace std;
struct  node { int val;
	int vfreq;
	int suffix;
	int sfreq;
	int prefix;
	int pfreq;};

void build( int* a, int v , int tl , int tr, node *t)
{   
      if( tl == tr)
	{ t[v].val =a[tl] ;
          t[v].vfreq = 1;
	  t[v].suffix= a[tl];
	  t[v].sfreq=1;
	  t[v].prefix=a[tl];
	  t[v].pfreq=1;
	}
      else
      { int tm = (tl + tr) /2 ;
        build( a , 2*v , tl ,tm,t );
	build( a,2*v+1 , tm+1 ,tr , t);
if( t[2*v].val == t[2*v+1].val )
{ t[v].val = t[2*v].val;
t[v].vfreq= t[2*v].vfreq + t[2*v+1].vfreq;}
      else{
        if( t[2*v].vfreq >= t[2*v+1].vfreq )
	   { t[v].val = t[2*v].val;
	     t[v].vfreq = t[2*v].vfreq;
	   }
	else{
		  t[v].val = t[2*v+1].val;
		  t[v].vfreq = t[2*v+1].vfreq;
	}
	if( t[2*v].suffix == t[2*v+1].prefix && (t[2*v].sfreq+t[2*v+1].pfreq > t[v].vfreq ) )
	{
	    t[v].vfreq = t[2*v].sfreq+t[2*v+1].pfreq;
	    t[v].val = t[2*v].suffix;
	}

      }




t[v].prefix = t[2*v].prefix;
t[v].pfreq = t[2*v].pfreq; 

if(t[2*v].prefix == t[2*v+1].prefix )
t[v].pfreq += t[2*v+1].pfreq;

t[v].suffix = t[2*v+1].suffix;
t[v].sfreq = t[2*v+1].sfreq;

if(t[2*v].suffix == t[2*v+1].suffix )
t[v].sfreq += t[2*v].sfreq;

	}
}







int main()
{ int n,q;
	cin >> n >>q;
	int a[n];
	for (int i=0;i<n;i++)
		cin >> a[i];
node t[4*n];
build(a,1,0,n-1,t);

	for(int j=0;j<q;j++)
	{   int l,r; cin >> l >> r;
		  
	}



	return 0;
}
