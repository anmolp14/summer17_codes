#include <iostream>
#include <cmath>
#include<bits/stdc++.h>
using namespace std;

#define fori(k, a, b) for (k = a; k < b; k++)

int main()
{
	int t, n, sigma;
	double ratio;
	cin >> t;
	while (t--)
	{
		cin >> n >> sigma;
		if (n == 1)
		{
			if (sigma == 0)
			{
				cout << 0 << endl;
			}
			else
			{
				cout << -1 << endl;
			}
			continue;
		}
		ratio = (double)(n) / (double)(n-1);
		if (n % 2 != 0)
		{
			ratio = sqrt(ratio);
			for (int i = 0; i < n / 2; i++)
			{
				cout << fixed << setprecision(8) << (ratio * sigma) << " ";
			}
			cout << 0 << " ";
			for (int i = 0; i < n / 2; i++)
			{
				cout << fixed << setprecision(8) << -(ratio * sigma) << " ";
			}
		}
		else
		{
			for (int i = 0; i < n / 2; i++)
			{
				cout << sigma << " ";
			}
			for (int i = 0; i < n / 2; i++)
			{
				cout << -sigma << " ";
			}
		}
		cout << endl;
	}
}
