#include<bits/stdc++.h>
using namespace std;



void insh(long int a, vector<long int> *heap )
{
(*heap).push_back(a);

int i = (*heap).size() -1 ;
while( i!=0 && (*heap)[i] < (*heap)[(i-1)/2] )
{swap((*heap)[i] , (*heap)[(i-1)/2]);
i=(i-1)/2;
}
}




void delh( long int a, vector <long int>*  heap )
{ int i=0;
 while((*heap)[i] != a) 
	i++;
swap((*heap)[i] , (*heap)[(*heap).size() -1]);
(*heap).pop_back();
while( i!=0 && (*heap)[i] < (*heap)[(i-1)/2] )
 {swap((*heap)[i] , (*heap)[(i-1)/2]);
 i=(i-1)/2;
 }
return;
while( (2*i+2) < (*heap).size() && ((*heap)[i] > min((*heap)[2*i+1] , (*heap)[2*i+2] )))
{
if((*heap)[2*i+1] ==  min((*heap)[2*i+1] , (*heap)[2*i+2] ))
{ swap((*heap)[2*i+1],(*heap)[i]); i=2*i+1;  }
else{ swap((*heap)[2*i+2],(*heap)[i] ); i=2*i+2;     }

}

if((2*i+2) == (*heap).size() && (*heap)[i] > (*heap)[2*i+1]  )
	swap((*heap)[i] , (*heap)[2*i+1]);


}



int main()
{
int q;
cin >> q;
vector<long int> heap ;
for(int i=0;i<q;i++)
{
long int a; cin >> a;

if( a == 1)//insert
{cin >> a; insh(a,&heap);}

else if(a==2)//delete
{cin >> a; delh(a,&heap);}

else
{cout << heap[0] << endl;}

}
return 0;
}
