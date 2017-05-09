#include<bits/stdc++.h>
using namespace std;
void printrev(int n)
{
  int a;
  cin >> a;
  if(n>1)
  printrev(n-1);
cout << a << ' ';


}
int main()
{

int n;
cin >> n;
printrev(n);



return 0;}
