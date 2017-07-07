#include<bits/stdc++.h>
using namespace std;
int merge( int * a , int low , int high   )
{ 
	int mid = (low + high )/2;
	int i=low,j= mid+1,k=0 ;
	int inv=0;
	int ar[high-low+1];
	while( i <=mid && j <= high   )
	{
		if( a[i] <= a[j] )
		{
			ar[k] = a[i];
			inv += j - mid -1;
			k++;
			i++;
		}
		else
		{
			ar[k] = a[j];
			k++;
			j++;
		}
	}
	while( i <= mid )
	{
		ar[k] = a[i];
		inv+= j - mid -1;
		k++;
		i++;
	}
	while ( j <= high)
	{
		ar[k] = a[j];
		k++;
		j++;
	}
	for( int i=0;i<high-low+1;i++)
		a[low+i] = ar[i];
	return inv;
}
int mergesort( int* a , int low , int high )
{ int i=0;
	if( low < high)
	{
		int mid = (low + high)/2;
		i+= mergesort( a , low , mid )+ mergesort( a , mid+1, high);
		i+= merge ( a , low ,high);
	}

	return i;
}
int main()
{	int n; cin >> n;
	while( n != 0 )
	{

	int a[n];
	for( int i=0; i<n;i++)
		cin >> a[i];
	cout << mergesort( a , 0 ,n-1 ) << endl;

cin >> n;
	}




	return 0;
}
