#include <iostream>
#include <algorithm>
#include <string>
#include <cstdio>
#include <cstdlib>

using namespace std;

int n, k, ans, used[15][15];

void clear (int x, int y, int m)
{
 for(int z = 1; z <= n; z++)
  if(used[z][y] == m)
   used[z][y] = 0;

 if(used[x + 1][y + 2] == m) used[x+1][y+2] = 0;
 if(used[x + 2][y + 1] == m) used[x+2][y+1] = 0;

 if(y - 2 >= 1 && used[x + 1][y - 2] == m)
  used[x + 1][y - 2] = 0;
 if(y - 1 >= 1 && used[x + 2][y - 1] == m)
  used[x + 2][y - 1] = 0;

 for (int i = x, j = y; i <= n, j <= n; i++, j++)
  if(used[i][j] == m)
   used[i][j] = 0;

 for (int i = x, j = y; i <= n, j > 0; i++, j--)
  if(used[i][j] == m)
   used[i][j] = 0;
}

void fill (int x, int y, int m)
{
 for(int z = 1; z <= n; z++)
  if(used[z][y] == 0)
   used[z][y] = m;

 if(!used[x + 1][y + 2]) used[x + 1][y + 2] = m;
 if(!used[x + 2][y + 1]) used[x + 2][y + 1] = m;

 if(y - 2 >= 1)
  if(!used[x + 1][y - 2]) used[x + 1][y - 2] = m;
 if(y - 1 >= 1)
  if(!used[x + 2][y - 1]) used[x + 2][y - 1] = m;

 for (int i = x, j = y; i <= n, j <= n; i++, j++)
  if (!used[i][j])
   used[i][j] = m;

 for (int i = x, j = y; i <= n, j > 0; i++, j--)
  if (!used[i][j])
   used[i][j] = m;
}

void rec(int x, int y, int m)
{
 if(!m)
 {
  ans++;
  return;
 }
 fill (x, y, m);

 for(int i = x + 1; i <= n; i++)
  for(int j = 1; j <= n; j++)
   if(used[i][j] == 0)
    rec(i, j, m - 1);

 clear (x, y, m);
}

int main()
{
 freopen("input.txt","r",stdin);
 freopen("output.txt","w",stdout);
 cin >> n >> k;

 for(int i = 1; i <= n; i++)
  for(int j = 1; j <= n; j++)
   rec(i, j, k - 1);

 cerr << ans;
 return 0;
}

