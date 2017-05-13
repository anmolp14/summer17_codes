#include<bits/stdc++.h>
using namespace std;
double sqrT(int n)
{
  /*We are using n itself as initial approximation
   This can definitely be improved */
  double x = n;
  double y = 1;
  double e = 0.0000001; /* e decides the accuracy level*/
  while(x - y > e)
  {
    x = (x + y)/2;
    y = n/x;
  }
  return x;
}
int main()

{
int n,h,num; cin >> n >> h; double hd;num = 1;
for( int i=0 ; i < n-1 ;i++)
{
hd = (sqrT(num) * 1.0) / (sqrT(n)*1.0) * h  ;
printf("%lf ",hd);
num++;
}



	return 0;
}
