#include <iostream>
#include <vector>
using namespace std;
int ans;
vector<bool> p(2000, true);
vector<int> pi(2000);
void mp()
{
 p[0] = p[1] = false;
 for(int i = 2; i <= 1500;i++)
  if(p[i])
   for(int j = i; j <= 1500; j += i)
    p[i]=false;
}

void rec(int x)
{
 int i=1;
 while(i*i<=x)
 {
  int y=int(upper_bound(pi.begin(),pi.end(),i)-pi.begin());
  if(y==i)
  {
   if(x%i==0) ans++,x/=i;
  }
  else
  i++;
 }
}
                        
int main()
{
 freopen("input.txt","r",stdin);
 freopen("output.txt","w",stdout);
 int n;
 cin>>n;
 mp();

 for(long long i=0;i<=n;i++)
 {
  if(p[i]) pi.push_back(i);  
 }
 int pos=int(upper_bound(pi.begin(),pi.end(),n)-pi.begin());
 if(pos==n){cout<<n; return 0;}
 rec(n);
 cout<<ans;
 return 0;
}

