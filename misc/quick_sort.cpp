#include<bits/stdc++.h>
using namespace std;
int n;

int partition(int * a , int low, int high )
{
	int p=a[low];int j=low+1 ;
	for(int i=low;i<=high ;i++)
	{
		if(a[i] < p)
		{
			swap(a[i],a[j]);
			j++;
		}
	}
	swap(a[j-1],a[low]);
	return j-1;
}
int coun=0;
void quick_sort( int * a, int low , int high)
{
	if( low < high)
	{
		int p = partition(a , low , high );
		quick_sort( a, low , p-1);
		quick_sort( a, p+1, high);
		coun++;
	}
}
int main()
{
	cin >> n;
	int a[n];
	for( int i=0;i<n;i++)
		cin >> a[i];
	quick_sort( a,0,n-1);
	for( int i=0;i<n;i++)
		cout << a[i] << ' ';
	return 0;
}
