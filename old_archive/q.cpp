#include <iostream>
using namespace std;
int main()
{
 int a[111][111],n,m;
 int x,y;
 cin>>n>>m;
 for(int i=1;i<=m;i++)
 {
  cin>>x>>y;
  a[x][y]=1;
  a[y][x]=1;
 }
 for(int j=1;j<=n;j++)
 {
  for(int i=1;i<=n;i++)
  {
   cout<<a[i][j]<<" ";
  }
  cout<<endl;
 }
 return 0;
}