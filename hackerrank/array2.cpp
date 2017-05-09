#include<bits/stdc++.h>
using namespace std;
int a[6][6];
int maxs=0;
void hourglass(int i , int j )
{
int sum = a[i][j]+ a[i][j+1]+ a[i][j+2]+ a[i+1][j+1]+ a[i+2][j]+ a[i+2][j+1] +a[i+2][j+2];
if(maxs < sum || (i==0 && j==0) )
maxs = sum;


}
int main()
{
for(int i=0;i<6;i++)
{

for (int j=0;j<6;j++)
{
  cin >> a[i][j];
}

}



for(int i=0;i<4;i++)
{

for (int j=0;j<4;j++)
{
    hourglass( i,j );

}

}

cout << maxs;

return 0;
}
