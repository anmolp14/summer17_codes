#include<bits/stdc++.h>
using namespace std;

int main()
{
int n; cin >> n;
vector <int> c(10,0);
vector <int> mark(10,0);
int D[n][6];
for( int i=0; i<n; i++)
{
for( int j=0;j<6;j++)
{
	cin >> D[i][j];
	if( mark[D[i][j]] != 1)
	{
	c[D[i][j]]++;
	mark[D[i][j]]=1;
	}
}
for(int h=0;h<10;h++)
mark[h]=0;
}
/*
 *for(int i=0;i<10;i++)
 *cout << c[i] << ' ';
 *cout << endl;*/
 int m=c[1],ind=1;

for(int l=2;l<10;l++)
	{
	if(c[l] < m)
	{
		m =c[l];
		ind = l;
	}

	}
int w = ind;
if(c[ind]==0)
{
	cout << ind-1;
	return 0;
}
for(int i=1;i<c[ind];i++)
	w = w * 10 + ind;
w = w*10;
 w = w + ind-1;


if( c[0] < c[ind] )
        { w=1;
                for(int i=0;i<c[0];i++)
                        w = w*10;
        }

cout << w;




	return 0;
}
