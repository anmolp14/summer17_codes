#include<bits/stdc++.h>
using namespace std;

int main()
{
int n,q,la=0;
cin >> n >> q;\
vector < vector<long int> >  seqs (n);
for(int i=0;i<q;i++)
{
   int a,x,y;
   cin >> a >> x >> y;
   if( a == 2 )
   {
       la =  seqs[(x ^ la) % n ][y % ( seqs[(x ^ la) % n ].size()  )  ];
       cout << la << endl;
    }
   else{
    	 seqs[(x ^ la) % n ].push_back(y);
    	
   
   }



}

return  0;
}
