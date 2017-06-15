#include<bits/stdc++.h>
using namespace std;
void merge (int * a , int low , int high)
{ 
	int b[high - low +1];
	int mid = (low + high)/2;
	int i = low, j = mid+1,k=0;
	while( i <= mid && j <= high)
	{
		if( a[i] < a[j] )
		{ 
			b[k] = a[i];
			i++;k++;
		}
		else
		{ 
			b[k]=a[j];
			j++;k++;
		}
	}
	while( i < mid+1)
	{   
		b[k] = a[i];
		i++; k++;
	}
	while( j < high+1)
	{
		b[k] = a[j];
		j++;k++;
	}
for( int i=low; i<=high; i++)
	a[i] = b[i-low];
}
void merge_sort( int * a, int low , int high )
{
	if(low < high)
	{
		int mid = (low + high)/2;
		merge_sort( a , low , mid );
		merge_sort( a , mid+1 , high);
		merge ( a , low , high);
	}
}

int main()
{
	int n; cin >> n;
	int a[n];
	for( int i=0; i<n;i++)
		cin >> a[i];
	merge_sort( a , 0 , n-1  );
for( int i=0; i < n ;i++)
	cout << a[i] << ' ';




	return 0;
}
