#include<bits/stdc++.h>
using namespace std;
int main()
{
int t;
cin >> t;
for(int i=0;i<t;i++)
{
int min ,n,a;
cin >> n >> min ;

for(int j=1;j<n;j++)
{ cin >> a;
if(a > min)
  min = a;


}

cout << n-min << endl;



}

return 0;
}
