#include<bits/stdc++.h>
using namespace std;

long int extractmin( vector<long int> *heap )
{

long int a=(*heap)[0];
 int i=0,flag =0;
 while((*heap)[i] != a) 
	i++;
swap((*heap)[i] , (*heap)[(*heap).size() -1]);
(*heap).pop_back();
while( i!=0 && (*heap)[i] < (*heap)[(i-1)/2] )
 {swap((*heap)[i] , (*heap)[(i-1)/2]);
 i=(i-1)/2;
 flag=1;
 }

while( flag ==0 && (2*i+2) < (*heap).size() && ((*heap)[i] > min((*heap)[2*i+1] , (*heap)[2*i+2] )))
{
if((*heap)[2*i+1] ==  min((*heap)[2*i+1] , (*heap)[2*i+2] ))
{ swap((*heap)[2*i+1],(*heap)[i]); i=2*i+1;  }
else{ swap((*heap)[2*i+2],(*heap)[i] ); i=2*i+2;     }

}

if((2*i+2) == (*heap).size() && (*heap)[i] > (*heap)[2*i+1] && flag==0 )
	swap((*heap)[i] , (*heap)[2*i+1]);
return a;
}

void insertheap( vector<long int> *heap , long int a )
{
(*heap).push_back(a);

int i = (*heap).size() -1 ;
while( i!=0 && (*heap)[i] < (*heap)[(i-1)/2] )
{swap((*heap)[i] , (*heap)[(i-1)/2]);
i=(i-1)/2;
}

}

void heapify( vector<long int>* a , long int val )
{




}


int main()
{
long int n,k,temp;cin >> n >> k;vector <long int> a;
for(long int i=0;i<n;i++)
{cin >> temp; a.push_back(temp);}
heapify(&a,n);

while( a[0] < k )
{ long int mi1,mi2;
mi1 = extractmin( &a );
mi2 = extractmin( &a );
mi1 = mi1 + 2 * mi2 ;
insertheap( &a, mi1);
}
return 0;
}

